---
title: Configurar as sessões de depuração do CMake no Visual Studio
description: Descreve como usar o Visual Studio para definir as configurações do depurador CMake.
ms.date: 04/02/2020
helpviewer_keywords:
- CMake debugging
ms.openlocfilehash: f860d1ae78d401a9e5079e79684a053220deaa6c
ms.sourcegitcommit: 3f91111c0350c0237fddb82766c290307f20e659
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/19/2020
ms.locfileid: "83630529"
---
# <a name="configure-cmake-debugging-sessions"></a>Configurar sessões de depuração do CMake

::: moniker range="vs-2015"

O suporte nativo a CMake está disponível no Visual Studio 2017 e posterior. Para ver a documentação dessas versões, defina o controle do seletor de **versão** do Visual Studio para este artigo como visual Studio 2017 ou visual Studio 2019. Ele é encontrado na parte superior do Sumário nesta página.

::: moniker-end

::: moniker range=">=vs-2017"

Todos os destinos executáveis do CMake são mostrados na lista suspensa **Item de Inicialização** na barra de ferramentas **Geral**. Selecione um para iniciar uma sessão de depuração e inicie o depurador.

![Menu suspenso de item de inicialização CMake](media/cmake-startup-item-dropdown.png "Menu suspenso de item de inicialização CMake")

Você também pode iniciar uma sessão de depuração de Gerenciador de Soluções. Primeiro, alterne para o **modo de exibição de destinos CMake** na janela **Gerenciador de soluções** .

![Botão de exibição de destinos do CMake](media/cmake-targets-view.png  "Item de menu de exibição de destinos CMake")

Em seguida, clique com o botão direito do mouse em um executável e selecione **depurar**. Esse comando inicia automaticamente a depuração do destino selecionado com base em sua configuração ativa.

## <a name="customize-debugger-settings"></a>Personalizar configurações do depurador

Você pode personalizar as configurações do depurador para qualquer destino de CMake executável em seu projeto. Eles são encontrados em um arquivo de configuração chamado *Launch. vs. JSON*, localizado em uma *`.vs`* pasta na raiz do projeto. Um arquivo de configuração de inicialização é útil na maioria dos cenários de depuração, pois você pode configurar e salvar os detalhes da configuração de depuração. Há três pontos de entrada para este arquivo:

- **Menu Depurar:** Selecione **depurar > depurar e iniciar configurações para $ {activeDebugTarget}** no menu principal para personalizar a configuração de depuração específica para seu destino de depuração ativa. Se você não tiver um destino de depuração selecionado, essa opção estará esmaecida.

![Ponto de entrada do menu de depuração](media/cmake-debug-menu.png "Ponto de entrada do menu de depuração")

- **Exibição de destinos:** Navegue até o **modo de exibição destinos** em Gerenciador de soluções. Em seguida, clique com o botão direito do mouse em um destino de depuração e selecione **Adicionar configuração de depuração** para personalizar a configuração de depuração específica para o destino selecionado.

![Ponto de entrada de exibição de destinos](media/cmake-targets-add-debug-configuration.png "Ponto de entrada de exibição de destinos")

- **CMakeLists. txt raiz:** Clique com o botão direito do mouse em uma raiz *CMakeLists. txt* e selecione **Adicionar configuração de depuração** para abrir a caixa de diálogo **selecionar um depurador** . A caixa de diálogo permite que você adicione *qualquer* tipo de configuração de depuração, mas você deve especificar manualmente o destino CMake para invocar por meio da `projectTarget` propriedade.

![Caixa de diálogo Selecionar um depurador](media/cmake-select-a-debugger.png "Caixa de diálogo Selecionar um depurador")

Você pode editar o arquivo *Launch. vs. JSON* para criar configurações de depuração para qualquer número de destinos CMake. Quando você salva o arquivo, o Visual Studio cria uma entrada para cada nova configuração no menu suspenso **item de inicialização** .

## <a name="reference-keys-in-cmakesettingsjson"></a>Chaves de referência em CMakeSettings. JSON

Para fazer referência a qualquer chave em um arquivo *CMakeSettings. JSON* , preceda `cmake.` -a na *inicialização. vs. JSON*. O exemplo a seguir mostra um arquivo de *inicialização simples. vs. JSON* que efetua pull do valor da `remoteCopySources` chave no arquivo *CMakeSettings. JSON* para a configuração selecionada no momento:

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

As **variáveis de ambiente** definidas em *CMakeSettings. JSON* também podem ser usadas em Launch. vs. JSON usando a sintaxe `${env.VARIABLE_NAME}` . No Visual Studio 2019 versão 16,4 e posteriores, os destinos de depuração são iniciados automaticamente usando o ambiente que você especificar em *CMakeSettings. JSON*. Você pode remover uma variável de ambiente definindo-a como **NULL**.

## <a name="launchvsjson-reference"></a>Inicializar. vs. referência JSON

Há muitas propriedades *Launch. vs. JSON* para dar suporte a todos os seus cenários de depuração. As propriedades a seguir são comuns a todas as configurações de depuração, remota e local:

- `projectTarget`: Especifica o destino CMake a invocar ao compilar o projeto. O Visual Studio preenche automaticamente essa propriedade se você inserir *Launch. vs. JSON* no **menu Depurar** ou no **modo de exibição destinos**. Esse valor deve corresponder ao nome de um destino de depuração existente listado na lista suspensa **item de inicialização** .

- `env`: Variáveis de ambiente adicionais a serem adicionadas usando a sintaxe:

  ```json
  "env": {
        "DEBUG_LOGGING_LEVEL": "trace;info",
        "ENABLE_TRACING": "true"
      }
  ```

- `args`: Argumentos de linha de comando passados para o programa a ser depurado.

## <a name="launchvsjson-reference-for-remote-projects-and-wsl"></a>Inicialização. vs. JSON referência para projetos e WSL remotos

No Visual Studio 2019 versão 16,6, adicionamos uma nova configuração de depuração do `type: cppgdb` para simplificar a depuração em sistemas remotos e WSL. As configurações de depuração antigas do `type: cppdbg` ainda têm suporte.

### <a name="configuration-type-cppgdb"></a>Tipo de configuração`cppgdb`

- `name`: Um nome amigável para identificar a configuração no menu suspenso do **item de inicialização** .
- `project`: Especifica o caminho relativo para o arquivo de projeto. Normalmente, você não precisa alterar esse caminho ao depurar um projeto CMake.
- `projectTarget`: Especifica o destino CMake a invocar ao compilar o projeto. O Visual Studio preenche automaticamente essa propriedade se você inserir *Launch. vs. JSON* no **menu Depurar** ou no **modo de exibição destinos**. Esse valor de destino deve corresponder ao nome de um destino de depuração existente listado na lista suspensa **item de inicialização** .
- `debuggerConfiguration`: Indica qual conjunto de valores padrão de depuração usar. No Visual Studio 2019 versão 16,6, a única opção válida é `gdb` . O Visual Studio 2019 versão 16,7 ou posterior também dá suporte a `gdbserver` .
- `args`: Argumentos de linha de comando passados na inicialização para o programa que está sendo depurado.
- `env`: Variáveis de ambiente adicionais passadas para o programa que está sendo depurado. Por exemplo, `{"DISPLAY": "0.0"}`.
- `processID`: ID do processo do Linux para anexar. Usado somente ao anexar a um processo remoto. Para obter mais informações, consulte [solucionar problemas de anexação a processos usando o gdb](https://github.com/Microsoft/MIEngine/wiki/Troubleshoot-attaching-to-processes-using-GDB).

#### <a name="additional-options-for-the-gdb-configuration"></a>Opções adicionais para a `gdb` configuração

- `program`: O padrão é `"${debugInfo.fullTargetPath}"` . O caminho do UNIX para o aplicativo a ser depurado. Necessário somente se for diferente do executável de destino no local de compilação ou implantação.
- `remoteMachineName`: O padrão é `"${debugInfo.remoteMachineName}"` . Nome do sistema remoto que hospeda o programa a ser depurado. Necessário somente se for diferente do sistema de compilação. Deve ter uma entrada existente no [Gerenciador de conexões](../linux/connect-to-your-remote-linux-computer.md). Pressione **Ctrl + espaço** para exibir uma lista de todas as conexões remotas existentes.
- `cwd`: O padrão é `"${debugInfo.defaultWorkingDirectory}"` . O caminho do UNIX para o diretório no sistema remoto em que o `program` é executado. O diretório precisa existir.
- `gdbpath`: O padrão é `/usr/bin/gdb` . Caminho completo do UNIX para o `gdb` usado para depurar. Necessário somente se estiver usando uma versão personalizada do `gdb` .
- `preDebugCommand`: Um comando do Linux a ser executado imediatamente antes de chamar `gdb` . `gdb`não inicia até que o comando seja concluído. Você pode usar a opção para executar um script antes da execução de `gdb` .

#### <a name="additional-options-allowed-with-the-gdbserver-configuration-167-or-later"></a>Opções adicionais permitidas com a `gdbserver` configuração (16,7 ou posterior)

- `program`: O padrão é `"${debugInfo.fullTargetPath}"` . O caminho do UNIX para o aplicativo a ser depurado. Necessário somente se for diferente do executável de destino no local de compilação ou implantação.
- `remoteMachineName`: O padrão é `"${debugInfo.remoteMachineName}"` . Nome do sistema remoto que hospeda o programa a ser depurado. Necessário somente se for diferente do sistema de compilação. Deve ter uma entrada existente no [Gerenciador de conexões](../linux/connect-to-your-remote-linux-computer.md). Pressione **Ctrl + espaço** para exibir uma lista de todas as conexões remotas existentes.
- `cwd`: O padrão é `"${debugInfo.defaultWorkingDirectory}"` . Caminho completo do UNIX para o diretório no sistema remoto em que o `program` é executado. O diretório precisa existir.
- `gdbPath`: O padrão é `${debugInfo.vsInstalledGdb}` . Caminho completo do Windows para o `gdb` usado para depurar. O padrão é `gdb` instalado com o desenvolvimento do Linux com carga de trabalho C/C++.
- `gdbserverPath`: O padrão é `usr/bin/gdbserver` . Caminho completo do UNIX para o `gdbserver` usado para depurar.
- `preDebugCommand`: Um comando do Linux a ser executado imediatamente antes de iniciar `gdbserver` . `gdbserver`não inicia até que o comando seja concluído.

#### <a name="deployment-options"></a>Opções de implantação

Use as opções a seguir para separar o computador de compilação (definido em CMakeSettings. JSON) de seu computador de depuração remota.

- `remoteMachineName`: Computador de depuração remota. Necessário somente se for diferente do computador de compilação. Deve ter uma entrada existente no [Gerenciador de conexões](../linux/connect-to-your-remote-linux-computer.md). Pressione **Ctrl + espaço** para exibir uma lista de todas as conexões remotas existentes.
- `disableDeploy`: O padrão é `false` . Indica se a separação de compilação/depuração está desabilitada. Quando `false` , essa opção permite que a compilação e a depuração ocorram em dois computadores separados.
- `deployDirectory`: Caminho completo do UNIX para o diretório no `remoteMachineName` qual o executável é copiado.
- `deploy`: Uma matriz de configurações de implantação avançadas. Você só precisa definir essas configurações quando desejar um controle mais granular sobre o processo de implantação. Por padrão, somente os arquivos necessários para o processo de depuração são implantados no computador de depuração remota.
  - `sourceMachine`: O computador do qual o arquivo ou diretório é copiado. Pressione **Ctrl + espaço** para exibir uma lista de todas as conexões remotas armazenadas no Gerenciador de conexões. Ao compilar nativamente em WSL, essa opção é ignorada.
  - `targetMachine`: O computador no qual o arquivo ou diretório é copiado. Pressione **Ctrl + espaço** para exibir uma lista de todas as conexões remotas armazenadas no Gerenciador de conexões.
  - `sourcePath`: O local do arquivo ou diretório em `sourceMachine` .
  - `targetPath`: O local do arquivo ou diretório em `targetMachine` .
  - `deploymentType`: Uma descrição do tipo de implantação. `LocalRemote`e `RemoteRemote` têm suporte. `LocalRemote`significa copiar do sistema de arquivos local para o sistema remoto especificado por `remoteMachineName` na *inicialização. vs. JSON*. `RemoteRemote`significa copiar do sistema de Build remoto especificado em *CMakeSettings. JSON* para o sistema remoto diferente especificado em *Launch. vs. JSON*.
  - `executable`: Indica se o arquivo implantado é um executável.

### <a name="execute-custom-gdb-commands"></a>Executar `gdb` comandos personalizados

O Visual Studio dá suporte `gdb` à execução de comandos personalizados para interagir diretamente com o depurador subjacente. Para obter mais informações, consulte [executando `gdb` comandos lldb personalizados](https://github.com/microsoft/MIEngine/wiki/Executing-custom-gdb-lldb-commands).

### <a name="enable-logging"></a>Habilitar o registro em log

Habilite o log do MIEngine para ver quais comandos são enviados `gdb` , qual saída `gdb` retorna e quanto tempo cada comando leva. [Saiba mais](https://github.com/microsoft/MIEngine/wiki/Logging)

### <a name="configuration-type-cppdbg"></a>Tipo de configuração`cppdbg`

As opções a seguir podem ser usadas durante a depuração em um sistema remoto ou WSL usando o `cppdbg` tipo de configuração. No Visual Studio 2019 versão 16,6 ou posterior, o tipo de configuração `cppgdb` é recomendado.

- `name`: Um nome amigável para identificar a configuração no menu suspenso do **item de inicialização** .

- `project`: Especifica o caminho relativo para o arquivo de projeto. Normalmente, você não precisa alterar esse valor ao depurar um projeto CMake.

- `projectTarget`: Especifica o destino CMake a invocar ao compilar o projeto. O Visual Studio preenche automaticamente essa propriedade se você inserir *Launch. vs. JSON* no **menu Depurar** ou no **modo de exibição destinos**. Esse valor deve corresponder ao nome de um destino de depuração existente listado na lista suspensa **item de inicialização** .

- `args`: Argumentos de linha de comando passados na inicialização para o programa que está sendo depurado.

- `processID`: ID do processo do Linux para anexar. Usado somente ao anexar a um processo remoto. Para obter mais informações, consulte [solucionar problemas de anexação a processos usando o gdb](https://github.com/Microsoft/MIEngine/wiki/Troubleshoot-attaching-to-processes-using-GDB).

- `program`: O padrão é `"${debugInfo.fullTargetPath}"` . O caminho do UNIX para o aplicativo a ser depurado. Necessário somente se for diferente do executável de destino no local de compilação ou implantação.

- `remoteMachineName`: O padrão é `"${debugInfo.remoteMachineName}"` . Nome do sistema remoto que hospeda o programa a ser depurado. Necessário somente se for diferente do sistema de compilação. Deve ter uma entrada existente no [Gerenciador de conexões](../linux/connect-to-your-remote-linux-computer.md). Pressione **Ctrl + espaço** para exibir uma lista de todas as conexões remotas existentes.

- `cwd`: O padrão é `"${debugInfo.defaultWorkingDirectory}"` . Caminho completo do UNIX para o diretório no sistema remoto em que o `program` é executado. O diretório precisa existir.

- `environment`: Variáveis de ambiente adicionais passadas para o programa que está sendo depurado. Por exemplo,

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

- `pipeArgs`: Uma matriz de argumentos de linha de comando passada para o programa de pipe para configurar a conexão. O programa de pipe é usado para retransmitir entrada/saída padrão entre o Visual Studio e o `gdb` . A maior parte dessa matriz **não precisa ser personalizada durante a** depuração de projetos CMake. A exceção é o `${debuggerCommand}` , que é iniciado `gdb` no sistema remoto. Ele pode ser modificado para:

  - Exporte o valor da exibição da variável de ambiente no seu sistema Linux. No exemplo a seguir, esse valor é `:1` .

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

  - Execute um script antes da execução de `gdb` . Verifique se as permissões de execução estão definidas no seu script.

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

- `stopOnEntry`: Um booliano que especifica se deve ser interrompido assim que o processo é iniciado. O padrão é false.

- `visualizerFile`: Um [arquivo. natvis](/visualstudio/debugger/create-custom-views-of-native-objects) a ser usado ao depurar esse processo. Essa opção é incompatível com a `gdb` impressão de formatação. Defina também `showDisplayString` quando você definir essa propriedade.

- `showDisplayString`: Um booliano que habilita a cadeia de caracteres de exibição quando um `visualizerFile` é especificado. Definir essa opção como `true` pode causar um desempenho mais lento durante a depuração.

- `setupCommands`: Um ou mais `gdb` comandos a serem executados para configurar o depurador subjacente.

- `miDebuggerPath`: O caminho completo para `gdb` . Quando não especificado, o Visual Studio pesquisa o caminho primeiro para o depurador.

- Por fim, todas as opções de implantação definidas para o `cppgdb` tipo de configuração também podem ser usadas pelo `cppdbg` tipo de configuração.

### <a name="debug-using-gdbserver"></a>Depurar usando`gdbserver`

Você pode configurar a `cppdbg` configuração para depurar usando o `gdbserver` . Você pode encontrar mais detalhes e uma configuração de inicialização de exemplo no blog da equipe do Microsoft C++ post [Debugging Linux `gdbserver` CMake Projects with ](https://devblogs.microsoft.com/cppblog/debugging-linux-cmake-projects-with-gdbserver/).

::: moniker-end

::: moniker range=">=vs-2017"

## <a name="see-also"></a>Confira também

[Projetos do CMake no Visual Studio](cmake-projects-in-visual-studio.md)\
[Configurar um projeto CMake do Linux](../linux/cmake-linux-project.md)\
[Conectar-se ao computador Linux remoto](../linux/connect-to-your-remote-linux-computer.md)\
[Personalizar configurações de Build do CMake](customize-cmake-settings.md)\
[Configurar sessões de depuração CMake](configure-cmake-debugging-sessions.md)\
[Implante, execute e depure seu projeto do Linux](../linux/deploy-run-and-debug-your-linux-project.md)\
[Referência de configuração predefinida do CMake](cmake-predefined-configuration-reference.md)

::: moniker-end
