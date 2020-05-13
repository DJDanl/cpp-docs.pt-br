---
title: inicialização. vs. referência de esquema JSON (C++)
ms.date: 08/20/2019
helpviewer_keywords:
- launch.vs.json file [C++]
ms.openlocfilehash: ff4713642ab95a9bbc31f1a06236de459e53f9c3
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81323048"
---
# <a name="launchvsjson-schema-reference-c"></a>inicialização. vs. referência de esquema JSON (C++)

Use o arquivo *Launch. vs. JSON* para configurar parâmetros de depuração. Para criar o arquivo. Clique com o botão direito do mouse em um arquivo executável em **Gerenciador de soluções** e escolha **depurar e iniciar configurações**. Escolha a opção que mais se aproximará do seu projeto e, em seguida, use as propriedades a seguir para modificar a configuração conforme necessário. Para obter mais informações sobre como depurar projetos do CMake, consulte [Configurar sessões de depuração do cmake](/cpp/build/configure-cmake-debugging-sessions).

## <a name="default-properties"></a>Propriedades padrão

||||
|-|-|-|
|**Propriedade**|**Tipo**|**Descrição**|
|`name`|string|Especifica o nome da entrada no menu suspenso de destino de depuração.|
|`type`|string|Especifica se o projeto é uma DLL ou. exe (o padrão é. exe)|
|`project`|string|Especifica o caminho relativo para o arquivo de projeto.|
|`projectTarget`|string|Especifica o destino opcional invocado durante `project`a compilação. Isso `projectTarget` já deve existir e corresponder ao nome na lista suspensa de **destino de depuração** .|
|`debugType`|string|Especifica o modo de depuração de acordo com o tipo de código (nativo, gerenciado ou misto). Isso será detectado automaticamente, a menos que esse parâmetro esteja definido. Valores permitidos: "nativo", "gerenciado", "misto".|
|`inheritEnvironments`|matriz|Especifica um conjunto de variáveis de ambiente herdadas de várias fontes. Você pode definir algumas variáveis em arquivos como *CMakeSettings. JSON* ou *CppProperties. JSON* e torná-los disponíveis para o contexto de depuração.  **Visual Studio 16,4:**: especificar variáveis de ambiente por destino usando a `env.VARIABLE_NAME` sintaxe. Para remover a definição de uma variável, defina-a como "NULL".|
|`args`|matriz|Especifica os argumentos de linha de comando passados para o programa iniciado.|
|`currentDir`|string|Especifica o caminho completo do diretório para o destino da compilação. Isso será detectado automaticamente, a menos que esse parâmetro esteja definido.|
|`noDebug`|booleano|Especifica se o programa iniciado deve ser depurado. O valor padrão para esse parâmetro é `false` se não for especificado.|
|`stopOnEntry`|booleano|Especifica se deve-se interromper um pouco quando o processo é iniciado e o depurador é anexado. O valor padrão para esse parâmetro é `false`.|
|`remoteMachine`|string|Especifica o nome do computador remoto onde o programa é iniciado.|
|`env`|matriz| Especifica uma lista de valores-chave de variáveis de ambiente personalizadas. env: {"myEnv": "myVal"}.|
|`portName`|string|Especifica o nome da porta ao anexar a um processo em execução.|
|`buildConfigurations`|matriz| Um par chave-valor que especifica o nome do modo de compilação para aplicar as configurações. Por exemplo, `Debug` ou `Release` e as configurações a serem usadas de acordo com o modo de compilação selecionado.

## <a name="c-linux-properties"></a>Propriedades do C++ Linux

||||
|-|-|-|
|**Propriedade**|**Tipo**|**Descrição**|
|`program`|string|Caminho completo para o executável do programa no computador remoto. Ao usar CMake, a macro `${debugInfo.fullTargetPath}` pode ser usada como o valor desse campo.|
|`processId`|inteiro|ID de processo opcional para anexar o depurador.|
|`sourceFileMap`|objeto|Mapeamentos de arquivo de origem opcionais passados para o mecanismo de depuração. Formato: `{ "\<Compiler source location>": "\<Editor source location>" }` ou `{ "\<Compiler source location>": { "editorPath": "\<Editor source location>", "useForBreakpoints": true } }`. Exemplo: `{ "/home/user/foo": "C:\\foo" }` ou `{ "/home/user/foo": { "editorPath": "c:\\foo", "useForBreakpoints": true } }`. Consulte [Opções de mapa do arquivo de origem](#source_file_map_options).|
|`additionalProperties`|string|Um dos sourceFileMapOptions. (Veja abaixo.)|
|`MIMode`|string|Indica o tipo de depurador de console habilitado para MI ao qual o MIDebugEngine se conectará. Os valores permitidos são "gdb", "lldb".|
|`args`|matriz|Argumentos de linha de comando passados para o programa.|
|`environment`|matriz|Variáveis de ambiente a serem adicionadas ao ambiente para o programa. Exemplo: [{"Name": "squid", "value": "ponto"}].|
|`targetArchitecture`|string|A arquitetura do depurado. Isso será detectado automaticamente, a menos que esse parâmetro esteja definido. Os valores permitidos são x86, ARM, arm64, MIPS, x64, AMD64, x86_64.|
|`visualizerFile`|string|arquivo. natvis a ser usado ao depurar esse processo. Essa opção não é compatível com a impressão bonita do GDB. Consulte "exibir somente" se estiver usando essa configuração.|
|`showDisplayString`|booleano|Quando um visualisadorfile é especificado, o DisplayString habilitará a cadeia de caracteres de exibição. Ativar essa opção pode causar um desempenho mais lento durante a depuração.|
|`remoteMachineName`|string|O computador Linux remoto que hospeda o gdb e o programa a ser depurado. Use o Gerenciador de Conexões para a adição de novos computadores Linux. Ao usar CMake, a macro `${debugInfo.remoteMachineName}` pode ser usada como o valor desse campo.|
|`cwd`|string|O diretório de trabalho do destino no computador remoto. Ao usar CMake, a macro `${debugInfo.defaultWorkingDirectory}` pode ser usada como o valor desse campo. O valor padrão é a raiz do espaço de trabalho remoto, a menos que seja substituído no arquivo *CMakeLists. txt* .|
|`miDebuggerPath`|string|O caminho para o depurador habilitado para MI (como o gdb). Quando não for especificado, ele pesquisará o caminho primeiro para o depurador.|
|`miDebuggerServerAddress`|string|Endereço de rede do servidor do depurador habilitado para MI ao qual se conectar. Exemplo: localhost: 1234.|
|`setupCommands`|matriz|Um ou mais comandos GDB/LLDB para executar a fim de configurar o depurador subjacente. Exemplo: `"setupCommands": [ { "text": "-enable-pretty-printing", "description": "Enable GDB pretty printing", "ignoreFailures": true }]`. Consulte [iniciar comandos de instalação](#launch_setup_commands).|
|`customLaunchSetupCommands`|matriz|Se fornecido, isso substituirá os comandos padrão usados para iniciar um destino com alguns outros comandos. Por exemplo, isso pode ser "-Target-Attach" para anexar a um processo de destino. Uma lista de comandos vazia substitui os comandos de inicialização por nada, o que pode ser útil se o depurador estiver sendo fornecido com opções de inicialização como opções de linha de comando. Exemplo: `"customLaunchSetupCommands": [ { "text": "target-run", "description": "run target", "ignoreFailures": false }]`.|
|`launchCompleteCommand`|string|O comando a ser executado depois que o depurador está totalmente configurado, para fazer com que o processo de destino seja executado. Os valores permitidos são "exec-Run", "exec-Continue", "None". O valor padrão é "exec-Run".|
|`debugServerPath`|string|Caminho completo opcional para o servidor de depuração a ser iniciado. O padrão é NULL.|
|`debugServerArgs`|string|Argumentos de servidor de depuração opcionais. O padrão é NULL.|
|`filterStderr`|booleano|Pesquisar o fluxo stderr para o padrão iniciado pelo servidor e o stderr do log para depurar a saída. O padrão é `false`.|
|`coreDumpPath`|string|Caminho completo opcional para um arquivo de despejo de núcleo para o programa especificado. O padrão é NULL.|
externalConsole|booleano|Se for true, um console será iniciado para o depurado. Se `false`, nenhum console será iniciado. O padrão é `false`. Observação: essa opção é ignorada em alguns casos por motivos técnicos.|
|`pipeTransport`|string|Quando presente, isso informa ao depurador para se conectar a um computador remoto usando outro executável como um pipe que retransmitirá a entrada/saída padrão entre o Visual Studio e o depurador habilitado para MI (como o gdb). Valores permitidos: uma ou mais [Opções de transporte de pipe](#pipe_transport_options).|

## <a name="launch-setup-commands"></a><a name="launch_setup_commands"></a>Iniciar comandos de instalação

Usado com a `setupCommands` Propriedade:

||||
|-|-|-|
|`text`|string|O comando do depurador a ser executado.|
|`description`|string|Descrição opcional para o comando.|
|`ignoreFailures`|booleano|Se for true, as falhas do comando deverão ser ignoradas. O padrão é `false`.|

## <a name="pipe-transport-options"></a><a name = "pipe_transport_options"></a>Opções de transporte de pipe

Usado com a `pipeTransport` Propriedade:

||||
|-|-|-|
|`pipeCwd`|string|O caminho totalmente qualificado para o diretório de trabalho para o programa de pipe.|
|`pipeProgram`|string|O comando de pipe totalmente qualificado a ser executado.|
|`pipeArgs`|matriz|Argumentos de linha de comando passados para o programa de pipe para configurar a conexão.|
|`debuggerPath`|string|O caminho completo para o depurador no computador de destino, por exemplo,,/usr/bin/gdb.|
|`pipeEnv`|objeto|Variáveis de ambiente passadas para o programa de pipe.|
|`quoteArgs`|booleano|Se argumentos individuais contiverem caracteres (como espaços ou tabulações), eles deverão ser colocados entre aspas? Se `false`, o comando do depurador não será mais colocado entre aspas automaticamente. O padrão é `true`.|

## <a name="source-file-map-options"></a><a name="source_file_map_options"></a>Opções de mapa do arquivo de origem

Use com a `sourceFileMap` Propriedade:

||||
|-|-|-|
|`editorPath`|string|O local do código-fonte do editor a ser localizado.|
|`useForBreakpoints`|booleano|Ao definir pontos de interrupção, esse mapeamento de origem deve ser usado. Se `false`, somente o nome do arquivo e o número da linha serão usados para definir pontos de interrupção. Se `true`, os pontos de interrupção serão definidos com o caminho completo para o arquivo e o número de linha somente quando esse mapeamento de origem for usado. Caso contrário, apenas o nome do arquivo e o número da linha serão usados ao definir pontos de interrupção. O padrão é `true`.|
