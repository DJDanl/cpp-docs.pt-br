---
title: Configurar as sessões de depuração do CMake no Visual Studio
description: Descreve como usar o Visual Studio para configurar as configurações do depurador CMake.
ms.date: 04/02/2020
helpviewer_keywords:
- CMake debugging
ms.openlocfilehash: 8364e5b3dd3316a4ed7e754a104a14373040aa6e
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81328831"
---
# <a name="configure-cmake-debugging-sessions"></a>Configurar sessões de depuração do CMake

::: moniker range="vs-2015"

O suporte nativo do CMake está disponível no Visual Studio 2017 e posteriormente. Para ver a documentação dessas versões, defina o controle do seletor Visual Studio **Version** para este artigo para visual studio 2017 ou Visual Studio 2019. É encontrado no topo da tabela de conteúdo nesta página.

::: moniker-end

::: moniker range=">=vs-2017"

Todos os destinos executáveis do CMake são mostrados na lista suspensa **Item de Inicialização** na barra de ferramentas **Geral**. Selecione um para iniciar uma sessão de depuração e inicie o depurador.

![CMake item de inicialização dropdown](media/cmake-startup-item-dropdown.png "CMake item de inicialização dropdown")

Você também pode iniciar uma sessão de depuração do Solution Explorer. Primeiro, mude para **CMake Targets Exibir** na janela **Solution Explorer.**

![Botão de exibição de destinos do CMake](media/cmake-targets-view.png  "CFazer metas Exibir item do menu")

Em seguida, clique com o botão direito do mouse em um executável e selecione **Debug**. Este comando inicia automaticamente a depuração do destino selecionado com base na sua configuração ativa.

## <a name="customize-debugger-settings"></a>Personalizar configurações do depurador

Você pode personalizar as configurações do depurador para qualquer destino CMake executável em seu projeto. Eles são encontrados em um arquivo de configuração chamado *launch.vs.json*, localizado em uma *`.vs`* pasta na raiz do projeto. Um arquivo de configuração de lançamento é útil na maioria dos cenários de depuração, porque você pode configurar e salvar os detalhes de configuração de depuração. Há três pontos de entrada neste arquivo:

- **Menu de depuração:** Selecione **Depurar > Debug e Configurações de lançamento para ${activeDebugTarget}** no menu principal para personalizar a configuração de depuração específica do seu destino de depuração ativa. Se você não tiver um destino de depuração selecionado, esta opção será acinzentada.

![Ponto de entrada do menu de depuração](media/cmake-debug-menu.png "Ponto de entrada do menu de depuração")

- **Exibição de metas:** Navegue **até o Targets View** in Solution Explorer. Em seguida, clique com o botão direito do mouse em um destino de depuração e selecione **Adicionar configuração de depuração** para personalizar a configuração de depuração específica para o destino selecionado.

![Alvos ver ponto de entrada](media/cmake-targets-add-debug-configuration.png "Alvos ver ponto de entrada")

- **Root CMakeLists.txt:** Clique com o botão direito do mouse em uma *raiz CMakeLists.txt* e selecione **Adicionar configuração de depuração** para abrir a caixa de diálogo **Selecionar um depurador.** A caixa de diálogo permite adicionar *qualquer* tipo de configuração de depuração, `projectTarget` mas você deve especificar manualmente o destino CMake para invocar através da propriedade.

![Selecione uma caixa de diálogo de depurador](media/cmake-select-a-debugger.png "Selecione uma caixa de diálogo de depurador")

Você pode editar o arquivo *launch.vs.json* para criar configurações de depuração para qualquer número de alvos CMake. Quando você salva o arquivo, o Visual Studio cria uma entrada para cada nova configuração no **item** de inicialização.

## <a name="reference-keys-in-cmakesettingsjson"></a>Chaves de referência em CMakeSettings.json

Para referenciar qualquer tecla em um arquivo *CMakeSettings.json,* `cmake.` prepare-a em *launch.vs.json*. O exemplo a seguir mostra um arquivo simple *launch.vs.json* que puxa o valor da `remoteCopySources` chave no arquivo *CMakeSettings.json* para a configuração atualmente selecionada:

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

**As variáveis de ambiente definidas** em *CMakeSettings.json* também podem ser usadas `${env.VARIABLE_NAME}`em launch.vs.json usando a sintaxe . No Visual Studio 2019 versão 16.4 e posterior, os alvos de depuração são automaticamente lançados usando o ambiente especificado em *CMakeSettings.json*. Você pode desdefinir uma variável de ambiente definindo-a **como nula**.

## <a name="launchvsjson-reference"></a>Referência launch.vs.json

Existem muitas propriedades *launch.vs.json* para suportar todos os seus cenários de depuração. As seguintes propriedades são comuns a todas as configurações de depuração, tanto remotas quanto locais:

- `projectTarget`: Especifica o alvo CMake para invocar ao construir o projeto. O Visual Studio preenche automaticamente essa propriedade se você inserir *launch.vs.json* no **Menu Debug** ou **Targets View**. Esse valor deve corresponder ao nome de um destino de depuração existente listado **na** lista de itens de inicialização.

- `env`: Variáveis adicionais de ambiente para adicionar usando a sintaxe:

  ```json
  "env": {
        "DEBUG_LOGGING_LEVEL": "trace;info",
        "ENABLE_TRACING": "true"
      }
  ```

- `args`: Argumentos de linha de comando passados para o programa para depurar.

## <a name="launchvsjson-reference-for-remote-projects-and-wsl"></a>Referência launch.vs.json para projetos remotos e WSL

No Visual Studio 2019 versão 16.6, adicionamos `type: cppgdb` uma nova configuração de depuração para simplificar a depuração em sistemas remotos e WSL. Configurações antigas de `type: cppdbg` depuração ainda são suportadas.

### <a name="configuration-type-cppgdb"></a>Tipo de configuração`cppgdb`

- `name`: Um nome amigável para identificar a configuração no **item** de inicialização.
- `project`: Especifica o caminho relativo ao arquivo do projeto. Normalmente, você não precisa mudar esse caminho ao depurar um projeto CMake.
- `projectTarget`: Especifica o alvo CMake para invocar ao construir o projeto. O Visual Studio preenche automaticamente essa propriedade se você inserir *launch.vs.json* no **Menu Debug** ou **Targets View**. Esse valor de destino deve corresponder ao nome de um destino de depuração existente listado **na** lista de itens de inicialização.
- `debuggerConfiguration`: Indica qual conjunto de valores padrão de depuração deve ser utilizado. No Visual Studio 2019 versão 16.6, `gdb`a única opção válida é . Versões `gdbserver`anteriores também suportam .
- `args`: Os argumentos da linha de comando passaram a inicialização para o programa que está sendo depurado.
- `env`: Variáveis adicionais de ambiente passadas para o programa que está sendo depurado. Por exemplo, `{"DISPLAY": "0.0"}`.
- `processID`: ID de processo Linux para anexar. Usado apenas quando conectado a um processo remoto. Para obter mais informações, consulte ['Solução de problemas' anexando-se a processos que usam OGDB](https://github.com/Microsoft/MIEngine/wiki/Troubleshoot-attaching-to-processes-using-GDB).

#### <a name="additional-options-for-the-gdb-configuration"></a>Opções adicionais para a configuração `gdb`

- `program`: Padrão `"${debugInfo.fullTargetPath}"`para . O caminho Unix para a aplicação para depurar. Apenas necessário se diferente do executável de destino no local de compilação ou implantação.
- `remoteMachineName`: Padrão `"${debugInfo.remoteMachineName}"`para . Nome do sistema remoto que hospeda o programa para depurar. Só é necessário se diferente do sistema de construção. Deve ter uma entrada existente no [Gerenciador de Conexões](../linux/connect-to-your-remote-linux-computer.md). Pressione **Ctrl+Space** para visualizar uma lista de todas as conexões remotas existentes.
- `cwd`: Padrão `"${debugInfo.defaultWorkingDirectory}"`para . O caminho Unix para o diretório `program` no sistema remoto onde é executado. O diretório precisa existir.
- `gdbpath`: Padrão `/usr/bin/gdb`para . Caminho Completo unix `gdb` para o usado para depurar. Só é necessário se `gdb`usar uma versão personalizada de .
- `preDebugCommand`: Um comando Linux para ser `gdb`executado imediatamente antes de invocar . `gdb`não começa até que o comando seja concluído. Você pode usar a opção de executar `gdb`um script antes da execução de .

#### <a name="deployment-options"></a>Opções de implantação

Use as seguintes opções para separar sua máquina de compilação (definida em CMakeSettings.json) da sua máquina de depuração remota.

- `remoteMachineName`: Máquina de depuração remota. Só é necessário se diferente da máquina de construção. Deve ter uma entrada existente no [Gerenciador de Conexões](../linux/connect-to-your-remote-linux-computer.md). Pressione **Ctrl+Space** para visualizar uma lista de todas as conexões remotas existentes.
- `disableDeploy`: Padrão `false`para . Indica se a separação de compilação/depuração está desativada. Quando `false`, esta opção permite que a compilação e a depuração ocorram em duas máquinas separadas.
- `deployDirectory`: Caminho completo do Unix `remoteMachineName` para o diretório em que o executável é copiado.
- `deploy`: Um conjunto de configurações avançadas de implantação. Você só precisa configurar essas configurações quando quiser um controle mais granular sobre o processo de implantação. Por padrão, apenas os arquivos necessários para o processo de depuração são implantados na máquina de depuração remota.
  - `sourceMachine`: A máquina a partir da qual o arquivo ou diretório é copiado. Pressione **Ctrl+Space** para visualizar uma lista de todas as conexões remotas armazenadas no Gerenciador de conexões. Ao construir nativamente no WSL, essa opção é ignorada.
  - `targetMachine`: A máquina para a qual o arquivo ou diretório é copiado. Pressione **Ctrl+Space** para visualizar uma lista de todas as conexões remotas armazenadas no Gerenciador de conexões.
  - `sourcePath`: O arquivo ou `sourceMachine`o local do diretório ligado .
  - `targetPath`: O arquivo ou `targetMachine`o local do diretório ligado .
  - `deploymentType`: Uma descrição do tipo de implantação. `LocalRemote`e `RemoteRemote` são apoiados. `LocalRemote`significa copiar do sistema de arquivos local para `remoteMachineName` o sistema remoto especificado por *em launch.vs.json*. `RemoteRemote`significa copiar do sistema de compilação remota especificado em *CMakeSettings.json* para o diferente sistema remoto especificado em *launch.vs.json*.
  - `executable`: Indica se o arquivo implantado é executável.

### <a name="execute-custom-gdb-commands"></a>Execute `gdb` comandos personalizados

O Visual Studio suporta `gdb` a execução de comandos personalizados para interagir diretamente com o depurador subjacente. Para obter mais informações, consulte [Executando comandos `gdb` lldb personalizados](https://github.com/microsoft/MIEngine/wiki/Executing-custom-gdb-lldb-commands).

### <a name="enable-logging"></a>Habilitar o registro em log

Habilite o registro do MIEngine `gdb`para `gdb` ver para quais comandos são enviados, quais retornos de saída e quanto tempo cada comando leva. [Saiba mais](https://github.com/microsoft/MIEngine/wiki/Logging)

### <a name="configuration-type-cppdbg"></a>Tipo de configuração`cppdbg`

As seguintes opções podem ser usadas ao depurar `cppdbg` em um sistema remoto ou WSL usando o tipo de configuração. No Visual Studio 2019 versão 16.6 `cppgdb` ou posterior, o tipo de configuração é recomendado.

- `name`: Um nome amigável para identificar a configuração no **item** de inicialização.

- `project`: Especifica o caminho relativo ao arquivo do projeto. Normalmente, você não precisa alterar esse valor ao depurar um projeto CMake.

- `projectTarget`: Especifica o alvo CMake para invocar ao construir o projeto. O Visual Studio preenche automaticamente essa propriedade se você inserir *launch.vs.json* no **Menu Debug** ou **Targets View**. Esse valor deve corresponder ao nome de um destino de depuração existente listado **na** lista de itens de inicialização.

- `args`: Os argumentos da linha de comando passaram a inicialização para o programa que está sendo depurado.

- `processID`: ID de processo Linux para anexar. Usado apenas quando conectado a um processo remoto. Para obter mais informações, consulte ['Solução de problemas' anexando-se a processos que usam OGDB](https://github.com/Microsoft/MIEngine/wiki/Troubleshoot-attaching-to-processes-using-GDB).

- `program`: Padrão `"${debugInfo.fullTargetPath}"`para . O caminho Unix para a aplicação para depurar. Apenas necessário se diferente do executável de destino no local de compilação ou implantação.

- `remoteMachineName`: Padrão `"${debugInfo.remoteMachineName}"`para . Nome do sistema remoto que hospeda o programa para depurar. Só é necessário se diferente do sistema de construção. Deve ter uma entrada existente no [Gerenciador de Conexões](../linux/connect-to-your-remote-linux-computer.md). Pressione **Ctrl+Space** para visualizar uma lista de todas as conexões remotas existentes.

- `cwd`: Padrão `"${debugInfo.defaultWorkingDirectory}"`para . Caminho Completo unix para o diretório `program` no sistema remoto onde é executado. O diretório precisa existir.

- `environment`: Variáveis adicionais de ambiente passadas para o programa que está sendo depurado. Por exemplo,

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

- `pipeArgs`: Uma matriz de argumentos de linha de comando passou para o programa de tubos para configurar a conexão. O programa pipe é usado para retransmitir `gdb`entrada/saída padrão entre o Visual Studio e . A maioria desta matriz **não precisa ser personalizada ao** depurar projetos CMake. A exceção `${debuggerCommand}`é a `gdb` , que é lançada no sistema remoto. Pode ser modificado para:

  - Exporte o valor da variável ambiente DISPLAY em seu sistema Linux. No exemplo a seguir, `:1`este valor é .

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

  - Execute um script antes `gdb`da execução de . Certifique-se de que as permissões de execução estão definidas no seu script.

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

- `stopOnEntry`: Um booleano que especifica se deve quebrar assim que o processo é iniciado. O padrão é false.

- `visualizerFile`: Um [arquivo .natvis](/visualstudio/debugger/create-custom-views-of-native-objects) para usar ao depurar este processo. Esta opção é `gdb` incompatível com impressão bonita. Também `showDisplayString` defina quando você definir esta propriedade.

- `showDisplayString`: Um booleano que habilita `visualizerFile` a seqüência de visualização quando a é especificada. Definir essa `true` opção pode causar um desempenho mais lento durante a depuração.

- `setupCommands`: Um `gdb` ou mais comandos para executar, para configurar o depurador subjacente.

- `miDebuggerPath`: O caminho `gdb`completo para . Quando não especificado, o Visual Studio pesquisa path primeiro para o depurador.

- Finalmente, todas as opções `cppgdb` de implantação definidas `cppdbg` para o tipo de configuração também podem ser usadas pelo tipo de configuração.

### <a name="debug-using-gdbserver"></a>Depuração usando`gdbserver`

Você pode configurar `cppdbg` a configuração `gdbserver`para depurar usando . Você pode encontrar mais detalhes e uma configuração de lançamento de exemplo no microsoft C++ Team Blog [post Depurando Projetos Linux `gdbserver`CMake com ](https://devblogs.microsoft.com/cppblog/debugging-linux-cmake-projects-with-gdbserver/).

::: moniker-end

::: moniker range=">=vs-2017"

## <a name="see-also"></a>Confira também

[Projetos CMake no Visual Studio](cmake-projects-in-visual-studio.md)\
[Configure um projeto Linux CMake](../linux/cmake-linux-project.md)\
[Conecte-se ao seu computador Linux remoto](../linux/connect-to-your-remote-linux-computer.md)\
[Personalizar configurações de compilação cMake](customize-cmake-settings.md)\
[Configurar sessões de depuração CMake](configure-cmake-debugging-sessions.md)\
[Implantar, executar e depurar seu projeto Linux](../linux/deploy-run-and-debug-your-linux-project.md)\
[Referência de configuração predefinida do CMake](cmake-predefined-configuration-reference.md)

::: moniker-end
