#include <WiFi.h>
#include <WebServer.h>

const char* ssid = "Familia Gouveia";
const char* password = "GRGH9TM0NHQ";

WebServer server(80);

const int ledPin = 2; // Pino do LED embutido, que controla o motor

bool motorStatus = false; // Estado inicial do motor
unsigned long startTime = 0; // Tempo de início do motor

// HTML & JavaScript para a página web
const char* htmlPage =
  "<!DOCTYPE html>"
  "<html lang=\"en\">"
  "<head>"
  "    <meta charset=\"UTF-8\">"
  "    <meta name=\"viewport\" content=\"width=device-width, initial-scale=1.0\">"
  "    <title>Controle do Motor</title>"
  "    <style>"
  "        body {"
  "            font-family: Arial, sans-serif;"
  "            background-color: #f0f0f0;"
  "            margin: 0;"
  "            padding: 0;"
  "            display: flex;"
  "            justify-content: center;"
  "            align-items: center;"
  "            height: 100vh;"
  "        }"
  "        .container {"
  "            background-color: #fff;"
  "            border-radius: 15px;"
  "            box-shadow: 0 0 10px rgba(0, 0, 0, 0.1);"
  "            padding: 20px;"
  "            text-align: center;"
  "        }"
  "        h1 {"
  "            color: #333;"
  "        }"
  "        .status {"
  "            margin: 20px 0;"
  "            padding: 10px;"
  "            font-size: 24px;"
  "            border-radius: 5px;"
  "        }"
  "        .button {"
  "            padding: 15px 25px;"
  "            font-size: 24px;"
  "            cursor: pointer;"
  "            outline: none;"
  "            color: #fff;"
  "            background-color: #04AA6D;"
  "            border: none;"
  "            border-radius: 15px;"
  "            box-shadow: 0 9px #999;"
  "        }"
  "        .button:hover {background-color: #3e8e41}"
  "        .button:active {"
  "            background-color: #3e8e41;"
  "            box-shadow: 0 5px #666;"
  "            transform: translateY(4px);"
  "        }"
  "        .online { color: green; }"
  "        .offline { color: red; }"
  "    </style>"
  "</head>"
  "<body>"
  "<div class=\"container\">"
  "    <h1>Controle do Motor</h1>"
  "    <div class=\"status\" id=\"motorStatus\">MOTOR 1: OFFLINE</div>"
  "    <div class=\"status\" id=\"uptimeStatus\">Tempo Online: 0 segundos</div>"
  "    <button class=\"button\" onclick=\"toggleMotor()\">Ligar Motor</button>"
  "</div>"
  "<script>"
  "    function updateStatus(online) {"
  "        document.getElementById('motorStatus').innerHTML = online ? \"MOTOR 1: ONLINE\" : \"MOTOR 1: OFFLINE\";"
  "        document.getElementById('motorStatus').className = online ? \"status online\" : \"status offline\";"
  "        if (online) {"
  "            startTime = Date.now();"
  "            setInterval(updateUptime, 1000);"
  "        } else {"
  "            startTime = 0;" // Zera o startTime quando o motor é desligado
  "        }"
  "    }"
  "    function updateUptime() {"
  "        if (startTime) {"
  "            const currentTime = Date.now();"
  "            const elapsedTime = Math.floor((currentTime - startTime) / 1000);"
  "            document.getElementById('uptimeStatus').innerHTML = \"Tempo Online: \" + elapsedTime + \" segundos\";"
  "        }"
  "    }"
  "    function toggleMotor() {"
  "        fetch('/toggle_motor', { method: 'POST' })"
  "            .then(response => response.json())"
  "            .then(data => {"
  "                updateStatus(data.online);"
  "                document.querySelector('.button').innerText = data.online ? \"Desligar Motor\" : \"Ligar Motor\";"
  "            })"
  "            .catch(error => console.error('Erro:', error));"
  "    }"
  "    updateStatus(false);"
  "</script>"
  "</body>"
  "</html>";

void setup() {
  Serial.begin(115200);
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, LOW);

  WiFi.begin(ssid, password);
  Serial.println("Conectando à rede Wi-Fi...");
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("\nConectado com sucesso à rede Wi-Fi!");
  Serial.print("Endereço IP: ");
  Serial.println(WiFi.localIP());

  server.on("/", HTTP_GET, []() {
    server.send(200, "text/html", htmlPage);
  });

  server.on("/toggle_motor", HTTP_POST, []() {
    motorStatus = !motorStatus;
    digitalWrite(ledPin, motorStatus ? HIGH : LOW);
    server.send(200, "application/json", "{\"online\":" + String(motorStatus ? "true" : "false") + "}");
  });

  server.begin();
}

void loop() {
  server.handleClient();
}
