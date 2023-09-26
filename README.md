-Davi Almeida Desenzi
-Arthur Bessa
-Miguel Milok
-João Rodrigues
-Marcio Gastaldi

# CP4-Edge

Este código é um exemplo de um programa para um dispositivo que coleta dados de um sensor DHT22 (ou AM2302), um sensor de luminosidade e os envia para o serviço TagoIO usando um módulo WiFi. Aqui está uma análise do código:

Inclusão de Bibliotecas e Declaração de Variáveis Globais:
O código inclui as bibliotecas DHT.h, HTTPClient.h, WiFi.h para uso das funcionalidades necessárias.
Declaração de variáveis globais, como o endereço do servidor TagoIO, informações de autenticação, SSID e senha da rede WiFi, além de outras variáveis relacionadas aos sensores e à comunicação.
Configuração WiFi:
A função init_wifi() é responsável por iniciar a conexão WiFi com as credenciais fornecidas. Ele aguarda até que a conexão seja estabelecida.
Configuração do Sensor DHT:
Configuração do sensor DHT22 (ou AM2302) na função setup() usando a biblioteca DHT. O pino de dados é definido como DHTPIN e o tipo de sensor é definido como DHT22.
Loop Principal:
O loop principal realiza as seguintes ações em sequência:
Leitura da umidade (humidity) e temperatura (temperature) do sensor DHT.
Leitura do valor de luminosidade do sensor (valor analógico do pino A5).
Envio dos dados para o servidor TagoIO através de três funções distintas: send_temperature(), send_humidity(), send_light().
Espera de 5 segundos antes de repetir o processo.
Funções de Envio de Dados:
Cada função de envio de dados (send_temperature(), send_humidity(), send_light()) cria uma estrutura JSON com os dados coletados e os envia para o servidor TagoIO usando uma solicitação HTTP POST.
Observações:
O código possui algumas peculiaridades, como o incremento das variáveis dhtHumidity, dhtTemperature, e sensor em vez de obter valores reais dos sensores. Isso pode ser um erro ou uma simplificação para fins de depuração.
Certifique-se de que o endereço do servidor TagoIO, o token de autenticação e as credenciais WiFi estejam corretos.
É importante entender que esse código depende de uma conexão WiFi ativa e de um servidor TagoIO configurado corretamente para funcionar.

Certifique-se de revisar as configurações específicas do TagoIO, como os nomes das variáveis e unidades esperadas pelo seu aplicativo TagoIO, para garantir que os dados sejam enviados corretamente. Também é importante corrigir os valores dos sensores para obter leituras reais em vez de incrementos fixos.
