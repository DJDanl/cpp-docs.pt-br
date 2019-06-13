---
title: Conectar-se ao computador Linux remoto no Visual Studio
description: Como se conectar a um computador Linux remoto de dentro de um projeto do Visual Studio C++.
ms.date: 06/07/2019
ms.assetid: 5eeaa683-4e63-4c46-99ef-2d5f294040d4
ms.openlocfilehash: 6348681ecc8e6f7863b2119810db24879526a1c6
ms.sourcegitcommit: 8adabe177d557c74566c13145196c11cef5d10d4
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 06/10/2019
ms.locfileid: "66821604"
---
# <a name="connect-to-your-remote-linux-computer"></a>Conectar-se ao computador Linux remoto

::: moniker range="vs-2015"

O suporte ao Linux está disponível no Visual Studio 2017 e posterior.

::: moniker-end

::: moniker range="vs-2019"

Quando você tiver como destino o WSL (Subsistema do Windows para Linux), o Visual Studio interagirá com a distribuição do Linux diretamente por meio do sistema de arquivos; nenhuma conexão remota é necessária.

::: moniker-end

Ao compilar um projeto do C++ Linux para um sistema Linux remoto (VM ou computador físico), o código do Linux é copiado para o computador Linux remoto e, em seguida, compilado com base nas configurações do Visual Studio. Para configurar essa conexão remota:

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