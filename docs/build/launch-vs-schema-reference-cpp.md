---
title: Iniciar. referência de esquema do vs.C++JSON ()
ms.date: 08/20/2019
helpviewer_keywords:
- launch.vs.json file [C++]
ms.openlocfilehash: 362a329289107f74cca2f20af62c8a28b4192575
ms.sourcegitcommit: ace42fa67e704d56d03c03745b0b17d2a5afeba4
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/22/2019
ms.locfileid: "69978451"
---
# <a name="launchvsjson-schema-reference-c"></a>Iniciar. referência de esquema do vs.C++JSON ()

Use o arquivo *Launch. vs. JSON* para configurar parâmetros de depuração. Para criar o arquivo. Clique com o botão direito do mouse em um arquivo executável em **Gerenciador de soluções** e escolha **depurar e iniciar configurações**. Escolha a opção que mais se aproximará do seu projeto e, em seguida, use as propriedades a seguir para modificar a configuração conforme necessário:

## <a name="default-properties"></a>Propriedades padrão

||||
|-|-|-|
|**Property**|**Tipo**|**Descrição**|
|`name`|cadeia de caracteres|Especifica o nome da entrada no menu suspenso de destino de depuração.|
|`type`|cadeia de caracteres|Especifica se o projeto é uma DLL ou. exe (o padrão é. exe)|
|`project`|cadeia de caracteres|Especifica o caminho relativo para o arquivo de projeto.|
|`projectTarget`|cadeia de caracteres|Especifica o destino opcional invocado durante `project`a compilação. Isso `projectTarget` já deve existir e corresponder ao nome na lista suspensa de **destino de depuração** .|
|`debugType`|cadeia de caracteres|Especifica o modo de depuração de acordo com o tipo de código (nativo, gerenciado ou misto). Isso será detectado automaticamente, a menos que esse parâmetro esteja definido. Valores permitidos: "nativo", "gerenciado", "misto".|
|`inheritEnvironments`|array|Especifica um conjunto de variáveis de ambiente herdadas de várias fontes. Você pode definir algumas variáveis em arquivos como CMakeSettings. JSON ou CppProperties. JSON e torná-los disponíveis para o contexto de depuração|
|`args`|array|Especifica os argumentos de linha de comando passados para o programa iniciado.|
|`currentDir`|cadeia de caracteres|Especifica o caminho completo do diretório para o destino da compilação. Isso será detectado automaticamente, a menos que esse parâmetro esteja definido.|
|`noDebug`|boolean|Especifica se o programa iniciado deve ser depurado. O valor padrão para esse parâmetro é `false` se não for especificado.|
|`stopOnEntry`|boolean|Especifica se deve-se interromper um pouco quando o processo é iniciado e o depurador é anexado. O valor padrão para esse parâmetro é `false`.|
|`remoteMachine`|cadeia de caracteres|Especifica o nome do computador remoto onde o programa é iniciado.|
|`env`|array| Especifica uma lista de valores-chave de variáveis de ambiente personalizadas. env: {"myEnv": "myVal"}.|
|`portName`|cadeia de caracteres|Especifica o nome da porta ao anexar a um processo em execução.|
|`buildConfigurations`|array| Um par chave-valor que especifica o nome do modo de compilação para aplicar as configurações. Por exemplo, `Debug` ou `Release` e as configurações a serem usadas de acordo com o modo de compilação selecionado.

## <a name="c-linux-properties"></a>C++Propriedades do Linux

||||
|-|-|-|
|**Property**|**Tipo**|**Descrição**|
|`program`|cadeia de caracteres|Caminho completo para o executável do programa no computador remoto. Ao usar CMake, a macro `${debugInfo.fullTargetPath}` pode ser usada como o valor desse campo.|
|`processId`|inteiro|ID de processo opcional para anexar o depurador.|
|`sourceFileMap`|objeto|Mapeamentos de arquivo de origem opcionais passados para o mecanismo de depuração. Formato: `{ "\<Compiler source location>": "\<Editor source location>" }` ou `{ "\<Compiler source location>": { "editorPath": "\<Editor source location>", "useForBreakpoints": true } }`. Exemplo: `{ "/home/user/foo": "C:\\foo" }` ou `{ "/home/user/foo": { "editorPath": "c:\\foo", "useForBreakpoints": true } }`. Consulte [Opções de mapa do arquivo de origem](#source_file_map_options).|
|`additionalProperties`|cadeia de caracteres|Um dos sourceFileMapOptions. (Veja abaixo.)|
|`MIMode`|cadeia de caracteres|Indica o tipo de depurador de console habilitado para MI ao qual o MIDebugEngine se conectará. Os valores permitidos são "gdb", "lldb".|
|`args`|array|Argumentos de linha de comando passados para o programa.|
|`environment`|array|Variáveis de ambiente a serem adicionadas ao ambiente para o programa. Exemplo: [{"Name": "squid", "value": "ponto"}].|
|`targetArchitecture`|cadeia de caracteres|A arquitetura do depurado. Isso será detectado automaticamente, a menos que esse parâmetro esteja definido. Os valores permitidos são x86, ARM, arm64, MIPS, x64, AMD64, x86_64.|
|`visualizerFile`|cadeia de caracteres|arquivo. natvis a ser usado ao depurar esse processo. Essa opção não é compatível com a impressão bonita do GDB. Consulte "exibir somente" se estiver usando essa configuração.|
|`showDisplayString`|boolean|Quando um visualisadorfile é especificado, o DisplayString habilitará a cadeia de caracteres de exibição. Ativar essa opção pode causar um desempenho mais lento durante a depuração.|
|`remoteMachineName`|cadeia de caracteres|O computador Linux remoto que hospeda o gdb e o programa a ser depurado. Use o Gerenciador de Conexões para a adição de novos computadores Linux. Ao usar CMake, a macro `${debugInfo.remoteMachineName}` pode ser usada como o valor desse campo.|
|`cwd`|cadeia de caracteres|O diretório de trabalho do destino no computador remoto. Ao usar CMake, a macro `${debugInfo.defaultWorkingDirectory}` pode ser usada como o valor desse campo. O valor padrão é a raiz do espaço de trabalho remoto, a menos que seja substituído no arquivo *CMakeLists. txt* .|
|`miDebuggerPath`|cadeia de caracteres|O caminho para o depurador habilitado para MI (como o gdb). Quando não for especificado, ele pesquisará o caminho primeiro para o depurador.|
|`miDebuggerServerAddress`|cadeia de caracteres|Endereço de rede do servidor do depurador habilitado para MI ao qual se conectar. Exemplo: localhost: 1234.|
|`setupCommands`|array|Um ou mais comandos GDB/LLDB para executar a fim de configurar o depurador subjacente. Exemplo: `"setupCommands": [ { "text": "-enable-pretty-printing", "description": "Enable GDB pretty printing", "ignoreFailures": true }]`. Consulte [iniciar comandos de instalação](#launch_setup_commands).|
|`customLaunchSetupCommands`|array|Se fornecido, isso substituirá os comandos padrão usados para iniciar um destino com alguns outros comandos. Por exemplo, isso pode ser "-Target-Attach" para anexar a um processo de destino. Uma lista de comandos vazia substitui os comandos de inicialização por nada, o que pode ser útil se o depurador estiver sendo fornecido com opções de inicialização como opções de linha de comando. Exemplo: `"customLaunchSetupCommands": [ { "text": "target-run", "description": "run target", "ignoreFailures": false }]`.|
|`launchCompleteCommand`|cadeia de caracteres|O comando a ser executado depois que o depurador está totalmente configurado, para fazer com que o processo de destino seja executado. Os valores permitidos são "exec-Run", "exec-Continue", "None". O valor padrão é "exec-Run".|
|`debugServerPath`|cadeia de caracteres|Caminho completo opcional para o servidor de depuração a ser iniciado. O padrão é NULL.|
|`debugServerArgs`|cadeia de caracteres|Argumentos de servidor de depuração opcionais. O padrão é NULL.|
|`filterStderr`|boolean|Pesquisar o fluxo stderr para o padrão iniciado pelo servidor e o stderr do log para depurar a saída. Assume o padrão de `false`.|
|`coreDumpPath`|cadeia de caracteres|Caminho completo opcional para um arquivo de despejo de núcleo para o programa especificado. O padrão é NULL.|
externalConsole|boolean|Se for true, um console será iniciado para o depurado. Se `false`, nenhum console será iniciado. Assume o padrão de `false`. OBSERVAÇÃO: Essa opção é ignorada em alguns casos por motivos técnicos.|
|`pipeTransport`|cadeia de caracteres|Quando presente, isso informa ao depurador para se conectar a um computador remoto usando outro executável como um pipe que retransmitirá a entrada/saída padrão entre o Visual Studio e o depurador habilitado para MI (como o gdb). Valores permitidos: uma ou mais [Opções de transporte de pipe](#pipe_transport_options).|


## <a name="launch_setup_commands"></a>Iniciar comandos de instalação

Usado com a `setupCommands` Propriedade:

||||
|-|-|-|
|`text`|cadeia de caracteres|O comando do depurador a ser executado.|
|`description`|cadeia de caracteres|Descrição opcional para o comando.|
|`ignoreFailures`|boolean|Se for true, as falhas do comando deverão ser ignoradas. Assume o padrão de `false`.|

## <a name = "pipe_transport_options"></a>Opções de transporte de pipe

Usado com a `pipeTransport` Propriedade:

||||
|-|-|-|
|`pipeCwd`|cadeia de caracteres|O caminho totalmente qualificado para o diretório de trabalho para o programa de pipe.|
|`pipeProgram`|cadeia de caracteres|O comando de pipe totalmente qualificado a ser executado.|
|`pipeArgs`|array|Argumentos de linha de comando passados para o programa de pipe para configurar a conexão.|
|`debuggerPath`|cadeia de caracteres|O caminho completo para o depurador no computador de destino, por exemplo,,/usr/bin/gdb.|
|`pipeEnv`|objeto|Variáveis de ambiente passadas para o programa de pipe.|
|`quoteArgs`|boolean|Se argumentos individuais contiverem caracteres (como espaços ou tabulações), eles deverão ser colocados entre aspas? Se `false`, o comando do depurador não será mais colocado entre aspas automaticamente. O padrão é `true`.|

## <a name="source_file_map_options"></a>Opções de mapa do arquivo de origem

Use com a `sourceFileMap` Propriedade:

||||
|-|-|-|
|`editorPath`|cadeia de caracteres|O local do código-fonte do editor a ser localizado.|
|`useForBreakpoints`|boolean|Ao definir pontos de interrupção, esse mapeamento de origem deve ser usado. Se `false`, somente o nome do arquivo e o número da linha serão usados para definir pontos de interrupção. Se `true`, os pontos de interrupção serão definidos com o caminho completo para o arquivo e o número de linha somente quando esse mapeamento de origem for usado. Caso contrário, apenas o nome do arquivo e o número da linha serão usados ao definir pontos de interrupção. O padrão é `true`.|
