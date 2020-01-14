---
title: Configurar as sessões de depuração do CMake no Visual Studio
description: Descreve como usar o Visual Studio para definir as configurações do depurador CMake
ms.date: 01/13/2020
helpviewer_keywords:
- CMake debugging
ms.openlocfilehash: ff1de8241c2489e675f82f469f1cf697a72f5034
ms.sourcegitcommit: 275b71219d2a8bd5d78f87e21dd909e9968c2f44
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 01/14/2020
ms.locfileid: "75946808"
---
# <a name="configure-cmake-debugging-sessions"></a>Configurar sessões de depuração do CMake

::: moniker range="vs-2015"

O suporte nativo a CMake está disponível no Visual Studio 2017 e posterior.

::: moniker-end

::: moniker range=">=vs-2017"

Todos os destinos executáveis do CMake são mostrados na lista suspensa **Item de Inicialização** na barra de ferramentas **Geral**. Para iniciar uma sessão de depuração, basta selecionar um e iniciar o depurador.

![Menu suspenso de item de inicialização CMake](media/cmake-startup-item-dropdown.png "Menu suspenso de item de inicialização CMake")

Você também pode iniciar uma sessão de depuração de Gerenciador de Soluções. Primeiro, alterne para o **modo de exibição de destinos CMake** na janela **Gerenciador de soluções** .

![Botão de exibição de destinos CMake](media/cmake-targets-view.png  "Item de menu de exibição de destinos CMake")

Em seguida, clique com o botão direito do mouse em qualquer executável e selecione **depurar** ou **depurar e iniciar as configurações**. **Debug** inicia automaticamente a depuração do destino selecionado, com base em sua configuração ativa. **Configurações de depuração e inicialização** abre o arquivo *Launch. vs. JSON* e adiciona uma nova configuração de depuração para o destino selecionado.

## <a name="customize-debugger-settings"></a>Personalizar configurações do depurador

Você pode personalizar as configurações do depurador para qualquer destino de CMake executável em seu projeto em um arquivo chamado *Launch. vs. JSON*. Há três pontos de entrada para este arquivo:

- Selecione **depurar > depurar e iniciar configurações para $ {activeDebugTarget}** no menu principal para editar a configuração de depuração específica para seu destino de depuração ativa. Se você não tiver um destino ativo selecionado, essa opção ficará esmaecida.

- Navegue até o **modo de exibição destinos** em Gerenciador de soluções. Em seguida, clique com o botão direito do mouse em um destino de depuração e selecione **depurar e iniciar configurações** para editar a configuração de depuração específica para o destino selecionado.

- Clique com o botão direito do mouse em uma raiz CMakeLists. txt e selecione **depurar e iniciar configurações** para abrir a caixa de diálogo **selecionar um depurador** . A caixa de diálogo permite que você adicione qualquer configuração de depuração, mas você deve especificar manualmente o destino CMake para invocar por meio da propriedade `projectTarget`.

Para fazer referência a qualquer chave em um arquivo *CMakeSettings. JSON* , preceda-a com `cmake.` em *Launch. vs. JSON*. O exemplo a seguir mostra um arquivo de *inicialização simples. vs. JSON* que efetua pull do valor da chave de `remoteCopySources` no arquivo *CMakeSettings. JSON* para a configuração selecionada no momento:

```json
{
  "version": "0.2.1",
  "defaults": {},
  "configurations": [
    {
      "type": "default",
      "project": "CMakeLists.txt",
      "projectTarget": "CMakeHelloWorld.exe (Debug\\CMakeHelloWorld.exe)",
      "name": "CMakeHelloWorld.exe (Debug\\CMakeHelloWorld.exe)",
      "args": ["${cmake.remoteCopySources}"]
    }
  ]
}
```

Quando você salva o arquivo *Launch. vs. JSON* , o Visual Studio cria uma entrada para o novo nome na lista suspensa **item de inicialização** . Você pode editar o arquivo *Launch. vs. JSON* para criar várias configurações de depuração, para qualquer número de destinos CMake.

## <a name="launchvsjson-reference"></a>Inicializar. vs. referência JSON

Há muitas propriedades *Launch. vs. JSON* para dar suporte a todos os seus cenários de depuração. As propriedades a seguir são comuns a todas as configurações de depuração, remota e local:

- `projectTarget`: especifica o destino CMake a ser invocado durante a compilação do projeto. O Visual Studio preenche automaticamente essa propriedade se você inserir *Iniciar. vs. JSON* de **debug > depurar e iniciar configurações para $ {ActiveDebugTarget}** ou **exibição de destinos**.

- `program`: caminho completo para o executável do programa no sistema remoto. Você pode usar a macro `${debugInfo.fullTargetPath}` aqui.

- `args`: argumentos de linha de comando passados para o programa a ser depurado.

## <a name="launchvsjson-reference-for-remote-linux-projects"></a>Iniciar a referência do. vs. JSON para projetos remotos do Linux

As propriedades a seguir são específicas para **configurações de depuração remota**. Você também pode [enviar comandos diretamente para o gdb](https://github.com/microsoft/MIEngine/wiki/Executing-custom-gdb-lldb-commands) e [habilitar o registro em log do MIEngine](https://github.com/microsoft/MIEngine/wiki/Logging). Essas propriedades permitem ver quais comandos são enviados ao gdb, qual saída o gdb retorna e quanto tempo cada comando leva.

- `cwd`: diretório de trabalho atual para localizar dependências e outros arquivos no computador remoto. A macro `${debugInfo.defaultWorkingDirectory}` pode ser usada. O valor padrão é a raiz do espaço de trabalho remoto, a menos que seja substituído em *CMakeLists. txt*. Esta propriedade é usada somente para configurações remotas; `currentDir` é usado para definir o diretório atual do aplicativo de inicialização para um projeto local.

- `environment`: variáveis de ambiente adicionais para adicionar ao ambiente para o programa com essa sintaxe:

```json
  "environment": [
      {
        "name": "ENV1",
        "value": "envvalue1"
      },
      {
        "name": "ENV2",
        "value": "envvalue2"
      }
    ]
```

- `pipeArgs`: argumentos de linha de comando passados para o programa de pipe para configurar a conexão. O programa de pipe é usado para retransmitir entrada/saída padrão entre o Visual Studio e o gdb. O comando `${debuggerCommand}` inicia o gdb no sistema remoto e pode ser modificado para:

  - Exporte o valor da exibição da variável de ambiente no seu sistema Linux. No exemplo a seguir, esse valor é `:1`.

  ```json
  "pipeArgs": [
      "/s",
      "${debugInfo.remoteMachineId}",
      "/p",
      "${debugInfo.parentProcessId}",
      "/c",
      "export DISPLAY=:1;${debuggerCommand}",
      "--tty=${debugInfo.tty}"
    ],
  ```

  - Execute um script antes da execução do gdb. Verifique se as permissões de execução estão definidas no seu script.

    ```json
    "pipeArgs": [
        "/s",
        "${debugInfo.remoteMachineId}",
        "/p",
        "${debugInfo.parentProcessId}",
        "/c",
        "/path/to/script.sh;${debuggerCommand}",
        "--tty=${debugInfo.tty}"
      ],
    ```

- `stopOnEntry`: um booliano que especifica se deve ser interrompido assim que o processo é iniciado. O padrão é falso.

- `visualizerFile`: um [arquivo. natvis](/visualstudio/debugger/create-custom-views-of-native-objects) a ser usado ao depurar esse processo. Essa opção é incompatível com o gdb Pretty Printing. Defina também `showDisplayString` quando você definir essa propriedade.

- `showDisplayString`: um booliano que habilita a cadeia de caracteres de exibição quando um `visualizerFile` é especificado. Definir essa opção como `true` pode causar um desempenho mais lento durante a depuração.

- `setupCommands`: um ou mais comandos do gdb a serem executados, para configurar o depurador subjacente.

- `externalConsole`: um booliano que especifica se um console é iniciado para o depurado.

- `miDebuggerPath`: o caminho completo para o gdb. Quando não especificado, o Visual Studio pesquisa o caminho primeiro para o depurador.

::: moniker-end

::: moniker range="vs-2017"

- `remoteMachineName`: o sistema Linux remoto que hospeda o gdb e o programa a ser depurado.

::: moniker-end

::: moniker range="vs-2019"

As propriedades a seguir podem ser usadas para separar o **sistema de compilação remota** do seu **sistema de depuração remota**. Para obter mais informações, consulte [especificar máquinas diferentes para criação e depuração](../linux/deploy-run-and-debug-your-linux-project.md#cmake-projects).

- `remoteMachineName`: o sistema Linux remoto que hospeda o gdb e o programa a ser depurado. Essa entrada não precisa corresponder ao sistema Linux remoto usado para compilação especificada em *CMakeSettings. JSON*. Pressione **Ctrl + espaço** para exibir uma lista de todas as conexões remotas armazenadas no [Gerenciador de conexões](../linux/connect-to-your-remote-linux-computer.md).

- `disableDeploy`: indica se a separação de compilação/depuração está desabilitada. Quando habilitado, esse recurso permite que a compilação e a depuração ocorram em dois computadores separados.

- `deployDirectory`: o diretório no computador de depuração remota (especificado pelo `remoteMachineName`) para o qual o executável será copiado.

- `deploy`: uma matriz de configurações de implantação avançadas. Você só precisa definir essas configurações quando desejar um controle mais granular sobre o processo de implantação. Por padrão, somente os arquivos necessários para depurar o processo serão implantados no computador de depuração remoto.

  - `sourceMachine`: o computador do qual o arquivo ou diretório será copiado. Pressione **Ctrl + espaço** para exibir uma lista de todas as conexões remotas armazenadas no Gerenciador de conexões.

  - `targetMachine`: o computador no qual o arquivo ou diretório será copiado. Pressione **Ctrl + espaço** para exibir uma lista de todas as conexões remotas armazenadas no Gerenciador de conexões.

  - `sourcePath`: o local do arquivo ou diretório no `sourceMachine`.

  - `targetPath`: o local do arquivo ou diretório no `targetMachine`.

  - `deploymentType`: uma descrição do tipo de implantação. Há suporte para `LocalRemote` e `RemoteRemote`. `LocalRemote` significa copiar do sistema de arquivos local para o sistema remoto especificado por `remoteMachineName` na *inicialização. vs. JSON*. `RemoteRemote` significa copiar do sistema de Build remoto especificado em *CMakeSettings. JSON* para o sistema remoto diferente especificado em *Launch. vs. JSON*.

  - `executable`: indica se o arquivo implantado é um executável.

::: moniker-end

::: moniker range=">=vs-2017"

## <a name="attach-to-a-remote-process"></a>Anexar a um processo remoto

Você pode anexar a um processo em execução no seu sistema Linux definindo `processId` à ID do processo para anexar o depurador. Para obter mais informações, consulte [solucionar problemas de anexação a processos usando o gdb](https://github.com/Microsoft/MIEngine/wiki/Troubleshoot-attaching-to-processes-using-GDB).

::: moniker-end

::: moniker range="vs-2019"

## <a name="debug-on-linux-using-gdbserver"></a>Depurar no Linux usando o gdbserver

O Visual Studio 2019 versão 16,5 Preview 1 ou posterior dá suporte à depuração remota de projetos do CMake com gdbserver. Para obter mais informações, consulte [Debugging Linux CMake Projects with gdbserver](https://devblogs.microsoft.com/cppblog/debugging-linux-cmake-projects-with-gdbserver/).

::: moniker-end

::: moniker range=">=vs-2017"

## <a name="see-also"></a>Veja também

[Projetos do cmake no Visual Studio](cmake-projects-in-visual-studio.md)\
[Configurar um projeto CMake do Linux](../linux/cmake-linux-project.md)\
[Conecte-se ao seu computador Linux remoto](../linux/connect-to-your-remote-linux-computer.md)\
[Personalizar as configurações de compilação do CMake](customize-cmake-settings.md)\
[Configurar sessões de depuração CMake](configure-cmake-debugging-sessions.md)\
[Implante, execute e depure seu projeto do Linux](../linux/deploy-run-and-debug-your-linux-project.md)\
[Referência de configuração predefinida do CMake](cmake-predefined-configuration-reference.md)

::: moniker-end
