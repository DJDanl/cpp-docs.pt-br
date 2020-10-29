---
title: Referência do ConnectionManager
description: Como gerenciar suas conexões SSH remotas de uma ferramenta de linha de comando.
ms.date: 10/7/2020
f1_keywords:
- ConnectionManager
helpviewer_keywords:
- ConnectionManager program
ms.openlocfilehash: 065a2cf6d6a2fe7d7e418299255c5bbf1f2bf753
ms.sourcegitcommit: 9c2b3df9b837879cd17932ae9f61cdd142078260
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/29/2020
ms.locfileid: "92921614"
---
# <a name="connectionmanager-reference"></a>Referência do ConnectionManager

::: moniker range="<=msvc-150"

ConnectionManager.exe está disponível no Visual Studio 2019 versão 16,5 e posterior.

::: moniker-end

::: moniker range="msvc-160"

ConnectionManager.exe é um utilitário de linha de comando para gerenciar conexões de desenvolvimento remoto fora do Visual Studio. Ele é útil para tarefas como o provisionamento de uma nova máquina de desenvolvimento. Ou use-o para configurar o Visual Studio para integração contínua. Você pode usá-lo em uma janela de Prompt de Comando do Desenvolvedor. Para obter mais informações sobre o Prompt de Comando do Desenvolvedor, consulte [usar o conjunto de ferramentas do Microsoft C++ na linha de comando](../build/building-on-the-command-line.md).

ConnectionManager.exe está disponível no Visual Studio 2019 versão 16,5 e posterior. Faz parte do desenvolvimento do **Linux com** carga de trabalho do C++ no instalador do Visual Studio. Ele também é instalado automaticamente quando você escolhe o componente do **Gerenciador de conexões** no instalador. Ele está instalado em *% VCIDEInstallDir% \\ Linux \\ bin \\ ConnectionManagerExe \\ConnectionManager.exe* .

A funcionalidade do ConnectionManager.exe também está disponível no Visual Studio. Para gerenciar conexões de desenvolvimento remoto no IDE, na barra de menus, escolha **ferramentas**  >  **Opções** para abrir a caixa de diálogo opções. Na caixa de diálogo opções, selecione Gerenciador de conexões **entre plataformas**  >  **Connection Manager** .

## <a name="syntax"></a>Syntax

> **`ConnectionManager.exe`***comando* \[ *arguments* ] \[ *Opções* ]

### <a name="commands-and-arguments"></a>Comandos e argumentos

- **`add`***\@ host* \[ do usuário **`--port`** *porta* ] \[ **`--password`** *password* senha \[ ] **`--privatekey`** *privatekey_file* ]

  Autentica e adiciona uma nova conexão. Por padrão, ele usa a porta 22 e a autenticação de senha. (Você será solicitado a inserir uma senha.) Use **-`-password`** e **`--privatekey`** para especificar uma senha para uma chave privada.

- **`remove`**\[ *CONNECTION_ID* \| porta de *\@ host do usuário* \[ **`--port`** *port* ]]

  Remove uma conexão. Se nenhum argumento for especificado, você será solicitado a especificar qual conexão será removida.
  
- **`modify`**\[ *padrão* \| *CONNECTION_ID* \| porta do *\@ host do usuário* \[ **`--port`** *port* ]] \[ **`--property`** *chave = valor* ]

  Define ou modifica uma propriedade em uma conexão. \
  Se o *valor* estiver vazio, a *chave* de propriedade será excluída. \
  Se a autenticação falhar, nenhuma alteração será feita. \
  Se nenhuma conexão for especificada (o que significa por *padrão* , acima), a conexão remota padrão do usuário será usada.

- **`remove-all`**

  Remove todas as conexões armazenadas.
  
- **`clean`**

  Exclui o cache de cabeçalho para conexões que não existem mais. 

- **`list`** \[**`--properties`** ]

  Exibe informações, IDs e propriedades de todas as conexões armazenadas. 

- **`help`**

  Exibe uma tela de ajuda.

- **`version`**

  Exibe informações de versão.

### <a name="options"></a>Opções

- **`-q`** , **`--quiet`**

  Impede a saída para `stdout` ou `stderr` .

- **`--no-prompt`**

  Falha em vez de prompt, quando apropriado.

- **`--no-verify`**

  Adicionar ou modificar uma conexão sem autenticação.

- **`--file`***nome do arquivo*

  Ler informações de conexão do *nome de arquivo* fornecido.

- **`--no-telemetry`**

  Desabilitar o envio de dados de uso de volta à Microsoft. Os dados de uso são coletados e enviados de volta à Microsoft, a menos que o **`--no-telemetry`** sinalizador seja passado.  

- **`-n`** , **`--dry-run`**

  Executa uma simulação do comando.
 
- **`--p`**

  O mesmo que **`--password`** .

- **`-i`**

  O mesmo que **`--privatekey`** .

## <a name="examples"></a>Exemplos

Esse comando adiciona uma conexão para um usuário chamado "user" no localhost. A conexão usa um arquivo de chave para autenticação, encontrado em *% USERPROFILE% \. ssh \ id_rsa* .

```cmd
ConnectionManager.exe add user@127.0.0.1 --privatekey "%USERPROFILE%\.ssh\id_rsa"
```

Esse comando Remove a conexão com a ID 1975957870 da lista de conexões.

```cmd
ConnectionManager.exe remove 1975957870
```

Esse comando substitui a escolha do Shell para a conexão com a ID de conexão 21212121. Os shells com suporte são: **`sh, csh, bash, tcsh, ksh, zsh, dash`** . Se o Shell encontrado no sistema Linux não tiver suporte, voltaremos a usar explicitamente **`sh`** para todos os comandos.

```cmd
ConnectionManager.exe modify 21212121 --property shell=csh
```

## <a name="see-also"></a>Veja também

[Conectar-se a seu sistema Linux de destino no Visual Studio](connect-to-your-remote-linux-computer.md)

::: moniker-end