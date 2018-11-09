---
title: Conectar-se ao computador Linux remoto no Visual Studio
description: Como se conectar a um computador Linux remoto de dentro de um projeto do Visual Studio C++.
ms.date: 07/20/2018
ms.assetid: 5eeaa683-4e63-4c46-99ef-2d5f294040d4
ms.openlocfilehash: ce6a3c02846586dbc46b0c9bc0db0d579878c814
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50575234"
---
# <a name="connect-to-your-remote-linux-computer"></a>Conectar-se ao computador Linux remoto

Ao compilar um projeto Linux em C++ no Visual Studio, o código do Linux é copiado para o seu computador Linux remoto e então compilado com base nas configurações do Visual Studio. Para configurar essa conexão remota:

1. Compile o projeto pela primeira vez ou crie manualmente uma nova entrada selecionando **Ferramentas > Opções** e, em seguida, abra o nó **Plataforma Cruzada > Gerenciador de Conexão** clique no botão **Adicionar**.

   ![Gerenciador de Conexões](media/settings_connectionmanager.png)

   Em qualquer cenário, a janela **Conectar-se ao sistema remoto** será exibida.

   ![Conectar-se ao Site Remoto](media/connect.png)

1. Insira as seguintes informações:

   | Entrada | Descrição
   | ----- | ---
   | **Nome do host**           | Nome ou endereço IP do dispositivo de destino
   | **Porta**                | Porta na qual o serviço SSH está em execução, normalmente 22
   | **Nome de usuário**           | Usuário como o qual será autenticado
   | **Tipo de autenticação** | Há suporte tanto para senha quanto para chave privada
   | **Senha**            | A senha do nome de usuário inserido
   | **Arquivo de chave privada**    | Arquivo de chave privada criado para conexão ssh
   | **Frase secreta**          | Frase secreta usada com a chave privada selecionada acima

1. Clique no botão **conectar** para tentar uma conexão com o computador remoto.  Se a conexão falhar, as caixas de entrada que precisarem ser alteradas serão destacadas em vermelho.

   ![Erro do Gerenciador de Conexões](media/settings_connectionmanagererror.png)