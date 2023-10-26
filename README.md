# Projeto de Sincronização de Trens no Qt Creator

Este é um projeto de exemplo que demonstra a sincronização de trens em uma rede ferroviária no Qt Creator. O projeto utiliza threads, mutexes e semáforos para garantir que os trens não colidam e sigam trajetos independentes. Cada trem é representado por uma thread separada, e as regiões críticas são protegidas por mutexes e semáforos.

## Requisitos

Certifique-se de ter os seguintes requisitos instalados antes de executar o projeto:

- [Qt Creator](https://www.qt.io/download) - A IDE usada para desenvolver o projeto.

## Executando o Projeto

1. Abra o projeto no Qt Creator.
2. Compile e execute o projeto.
3. A interface do aplicativo será exibida, mostrando trens em trilhos.

## Funcionalidades
![Captura de tela de 2023-10-21 20-11-07](https://github.com/mariamandafm/Avaliacao-SO-Trem/assets/67834977/fddae662-8a2c-472f-bd05-8ff6eda43812)

- Os trens já começam andando.
- Use os controles deslizantes para ajustar a velocidade dos trens.
- A velocidade varia de 0 a 200.

## Como Funciona

Cada trem é representado por uma thread na classe `Trem`. Os trens movem-se ao longo dos trilhos, e os mutexes (`<QMutex>`) são usados para garantir que eles não colidam nas regiões críticas.
