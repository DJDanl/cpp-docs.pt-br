---
title: Referência de ConnectionManager
ms.date: 01/17/2020
f1_keywords:
- ConnectionManager
helpviewer_keywords:
- ConnectionManager program
ms.openlocfilehash: 2b01bfbcd81984e7ddf32cd5ab0485fff17b3d2b
ms.sourcegitcommit: a930a9b47bd95599265d6ba83bb87e46ae748949
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 01/22/2020
ms.locfileid: "76520896"
---
# <a name="connectionmanager-reference"></a>Referência de ConnectionManager

::: moniker range="<=vs-2017"

O ConnectionManager. exe está disponível no Visual Studio 2019 versão 16,5 e posterior.

::: moniker-end

::: moniker range="vs-2019"

O ConnectionManager. exe é um utilitário de linha de comando para gerenciar conexões de desenvolvimento remoto fora do Visual Studio. Ele é útil para tarefas como o provisionamento de uma nova máquina de desenvolvimento. Ou use-o para configurar o Visual Studio para integração contínua. Você pode usá-lo em uma janela de Prompt de Comando do Desenvolvedor. Para obter mais informações sobre o Prompt de Comando do Desenvolvedor, consulte [usar o C++ conjunto de ferramentas da Microsoft na linha de comando](..\build\building-on-the-command-line.md).

O ConnectionManager. exe está disponível no Visual Studio 2019 versão 16,5 e posterior. Faz parte do desenvolvimento do **Linux com C++**  carga de trabalho no instalador do Visual Studio. Ele também é instalado automaticamente quando você escolhe o componente do **Gerenciador de conexões** no instalador. Ele está instalado em *% VCIDEInstallDir%\\ConnectionManagerExe do Linux\\\\\\ConnectionManager. exe*.

A funcionalidade do ConnectionManager. exe também está disponível no Visual Studio. Para gerenciar conexões de desenvolvimento remoto no IDE, na barra de menus, escolha **ferramentas** > **Opções** para abrir a caixa de diálogo opções. Na caixa de diálogo opções, selecione > **Gerenciador de conexões** **entre plataformas** .

## <a name="syntax"></a>Sintaxe

> *Comando* **ConnectionManager. exe** \[*argumentos*] \[*Opções*]

### <a name="commands-and-arguments"></a>Comandos e argumentos

- **Adicionar** *usuário\@host* \[ **--** *porta porta]* \[ **--** *senha*de senha] \[ **--PrivateKey** *privatekey_file*]

  Autentica e adiciona uma nova conexão. Por padrão, ele usa a porta 22 e a autenticação de senha. (Você será solicitado a inserir uma senha.) Use ambos **--password** e **--PrivateKey** para especificar uma senha para uma chave privada.

- **remover** \[*connection_id* \| *usuário\@host* \[ **--** *porta porta]]*

  Remove uma conexão. Se nenhum argumento for especificado, você será solicitado a especificar qual conexão será removida.

- **remover tudo**

  Remove todas as conexões armazenadas.

- **list**

  Exibe informações e IDs de todas as conexões armazenadas.

- **ajuda**

  Exibe uma tela de ajuda.

- **version**

  Exibe informações de versão.

### <a name="options"></a>Opções

- **-q**, **--Quiet**

  Impede a saída para `stdout` ou `stderr`.

- **--sem aviso**

  Falha em vez de prompt, quando apropriado.

- **--sem verificação**

  Adicionar ou modificar uma conexão sem autenticação.

- **--** *nome* do arquivo

  Ler informações de conexão do *nome de arquivo*fornecido.

- **--sem telemetria**

  Desabilitar o envio de dados de uso de volta à Microsoft. Os dados de uso são coletados e enviados de volta à Microsoft, a menos que o sinalizador **--no-telemetria** seja passado.  

- **-n**, **--execução seca**

  Executa uma simulação do comando.

- **-p**

  Mesmo que **--password**.

- **-i**

  O mesmo que **--PrivateKey**.

## <a name="examples"></a>Exemplos

Esse comando adiciona uma conexão para um usuário chamado "user" no localhost. A conexão usa um arquivo de chave para autenticação, encontrado em *% USERPROFILE%\.SSH \ id_rsa*.

```cmd
ConnectionManager.exe add user@127.0.0.1 --privatekey "%USERPROFILE%\.ssh\id_rsa"
```

Esse comando Remove a conexão com a ID 1975957870 da lista de conexões.

```cmd
ConnectionManager.exe remove 1975957870
```

## <a name="see-also"></a>Veja também

[Conectar-se ao seu sistema Linux de destino no Visual Studio](connect-to-your-remote-linux-computer.md)

::: moniker-end
