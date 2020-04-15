---
title: Referência do ConnectionManager
ms.date: 01/17/2020
f1_keywords:
- ConnectionManager
helpviewer_keywords:
- ConnectionManager program
ms.openlocfilehash: 1c6236cedba88714e9918dd2c096b5e78d2f08ce
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "77258027"
---
# <a name="connectionmanager-reference"></a>Referência do ConnectionManager

::: moniker range="<=vs-2017"

O ConnectionManager.exe está disponível no Visual Studio 2019 versão 16.5 e posterior.

::: moniker-end

::: moniker range="vs-2019"

ConnectionManager.exe é um utilitário de linha de comando para gerenciar conexões de desenvolvimento remoto fora do Visual Studio. É útil para tarefas como o provisionamento de uma nova máquina de desenvolvimento. Ou, use-o para configurar o Visual Studio para integração contínua.Você pode usá-lo em uma janela Prompt de comando do desenvolvedor. Para obter mais informações sobre o Prompt de comando do desenvolvedor, consulte [Use o conjunto de ferramentas Microsoft C++ da linha de comando](../build/building-on-the-command-line.md).

O ConnectionManager.exe está disponível no Visual Studio 2019 versão 16.5 e posterior. Faz parte do desenvolvimento do Linux com carga de trabalho **C++** no Visual Studio Installer. Ele também é instalado automaticamente quando você escolhe o componente **Gerenciador de conexões** no instalador. Ele está instalado em *%VCIDEInstallDir%\\Linux\\bin\\ConnectionManagerExe\\ConnectionManager.exe*.

A funcionalidade do ConnectionManager.exe também está disponível no Visual Studio. Para gerenciar conexões de desenvolvimento remoto no IDE, na barra de menus, escolha **Opções de** > **ferramentas** para abrir a caixa de diálogo Opções. Na caixa de diálogo Opções, selecione **Cross Platform** > **Connection Manager**.

## <a name="syntax"></a>Sintaxe

> Opções de *comando* \[ *arguments* **ConnectionManager.exe** ] \[ *options*]

### <a name="commands-and-arguments"></a>Comandos e argumentos

- **adicionar** *\@host de* \[usuário \[ **--porta de porta** *port*de porta **] --senha de** *senha*] \[ **--privatekey** *privatekey_file*]

  Autentica e adiciona uma nova conexão. Por padrão, ele usa a porta 22 e autenticação de senha. (Você será solicitado a digitar uma senha.) Use a **senha** e a **chave privada para** especificar uma senha para uma chave privada.

- **remover** \[ *connection_id* \| host \[do *usuário\@* **--porta de porta]]** *port*

  Remove uma conexão. Se nenhum argumento for especificado, você será solicitado a especificar qual conexão remover.

- **remover-tudo**

  Remove todas as conexões armazenadas.

- **list**

  Exibe informações e IDs de todas as conexões armazenadas.

- **Ajuda**

  Exibe uma tela de ajuda.

- **versão**

  Exibe informações da versão.

### <a name="options"></a>Opções

- **-q**, **--tranquilo**

  Impede a `stdout` saída `stderr`para ou .

- **--sem-prompt**

  Falhe em vez de prompt, quando apropriado.

- **--sem verificação**

  Adicione ou modifique uma conexão sem autenticação.

- **--arquivo** *nome de arquivo*

  Leia as informações de conexão do nome do *arquivo*fornecido .

- **--sem telemetria**

  Desabilite o envio de dados de uso de volta para a Microsoft. Os dados de uso são coletados e enviados de volta para a Microsoft, a menos que o sinalizador **--sem telemetria** seja passado.  

- **-n**, **--dry-run**

  Faz uma corrida seca do comando.

- **-p**

  O mesmo **que --senha.**

- **-I**

  O mesmo **que --privatekey**.

## <a name="examples"></a>Exemplos

Este comando adiciona uma conexão para um usuário chamado "usuário" no host local. A conexão usa um arquivo-chave para autenticação, encontrado em *%USERPROFILE%\.ssh\id_rsa*.

```cmd
ConnectionManager.exe add user@127.0.0.1 --privatekey "%USERPROFILE%\.ssh\id_rsa"
```

Este comando remove a conexão que tem ID 1975957870 da lista de conexões.

```cmd
ConnectionManager.exe remove 1975957870
```

## <a name="see-also"></a>Confira também

[Conectar-se a seu sistema Linux de destino no Visual Studio](connect-to-your-remote-linux-computer.md)

::: moniker-end
