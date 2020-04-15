---
title: launch.vs.json schema reference (C++)
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
# <a name="launchvsjson-schema-reference-c"></a>launch.vs.json schema reference (C++)

Use o arquivo *launch.vs.json* para configurar parâmetros de depuração. Para criar o arquivo. clique com o botão direito do mouse em um arquivo executável no **Solution Explorer** e escolha **Depurar e Iniciar Configurações**. Escolha a opção que mais combina com o seu projeto e, em seguida, use as seguintes propriedades para modificar a configuração conforme necessário. Para obter mais informações sobre a depuração de projetos CMake, consulte [Configurar sessões de depuração CMake](/cpp/build/configure-cmake-debugging-sessions).

## <a name="default-properties"></a>Propriedades padrão

||||
|-|-|-|
|**Propriedade**|**Tipo**|**Descrição**|
|`name`|string|Especifica o nome da entrada na parada de destino Debug.|
|`type`|string|Especifica se o projeto é um dll ou .exe (Padrão para .exe)|
|`project`|string|Especifica o caminho relativo ao arquivo do projeto.|
|`projectTarget`|string|Especifica o alvo opcional invocado na construção `project`. Isso `projectTarget` já deve existir e corresponder ao nome no dropdown **Debug Target.**|
|`debugType`|string|Especifica o modo de depuração de acordo com o tipo de código (nativo, gerenciado ou misto). Isso será detectado automaticamente a menos que este parâmetro esteja definido. Valores permitidos: "nativo", "gerenciado", "misto".|
|`inheritEnvironments`|matriz|Especifica um conjunto de variáveis de ambiente herdadas de múltiplas fontes. Você pode definir algumas variáveis em arquivos como *CMakeSettings.json* ou *CppProperties.json* e disponibilizá-las para depurar contexto.  **Visual Studio 16.4:**: Especifique variáveis de `env.VARIABLE_NAME` ambiente por alvo usando a sintaxe. Para desdefinir uma variável, defina-a como "nula".|
|`args`|matriz|Especifica os argumentos de linha de comando passados para o programa iniciado.|
|`currentDir`|string|Especifica o caminho completo do diretório para o Alvo de Compilação. Isso será detectado automaticamente a menos que este parâmetro esteja definido.|
|`noDebug`|booleano|Especifica se deve depurar o programa lançado. O valor padrão deste `false` parâmetro é, se não especificado.|
|`stopOnEntry`|booleano|Especifica se deve quebrar um logo que o processo é iniciado e o depurador é anexado. O valor padrão para `false`este parâmetro é .|
|`remoteMachine`|string|Especifica o nome da máquina remota onde o programa é lançado.|
|`env`|matriz| Especifica uma lista de valor-chave de variáveis de ambiente personalizadas. env:{"myEnv":"myVal"}.|
|`portName`|string|Especifica o nome da porta ao anexar a um processo em execução.|
|`buildConfigurations`|matriz| Um par de valor-chave que especifica o nome do modo de compilação para aplicar as configurações. Por `Debug` exemplo, `Release` ou e as configurações a serem usados de acordo com o modo de compilação selecionado.

## <a name="c-linux-properties"></a>Propriedades C++ Linux

||||
|-|-|-|
|**Propriedade**|**Tipo**|**Descrição**|
|`program`|string|Caminho completo para programar executável na máquina remota. Ao usar cMake, `${debugInfo.fullTargetPath}` a macro pode ser usada como o valor deste campo.|
|`processId`|inteiro|ID de processo opcional para anexar o depurador.|
|`sourceFileMap`|objeto|Mapeamentos opcionais de arquivos de origem passados para o mecanismo de depuração. Formato: `{ "\<Compiler source location>": "\<Editor source location>" }` `{ "\<Compiler source location>": { "editorPath": "\<Editor source location>", "useForBreakpoints": true } }`ou . Exemplo: `{ "/home/user/foo": "C:\\foo" }` ou `{ "/home/user/foo": { "editorPath": "c:\\foo", "useForBreakpoints": true } }`. Consulte [as opções do mapa do arquivo de origem](#source_file_map_options).|
|`additionalProperties`|string|Uma das opções de sourceFileMapOptions. (Veja abaixo.)|
|`MIMode`|string|Indica o tipo de depurador de console habilitado para MI ao que o MIDebugEngine se conectará. Os valores permitidos são "gdb", "lldb".|
|`args`|matriz|Argumentos de linha de comando passaram para o programa.|
|`environment`|matriz|Variáveis de ambiente para adicionar ao ambiente para o programa. Exemplo: [ { "nome": "lula", "valor": "molusco" } ].|
|`targetArchitecture`|string|A arquitetura da depuração. Isso será detectado automaticamente a menos que este parâmetro esteja definido. Os valores permitidos são x86, braço, braço64, mips, x64, amd64, x86_64.|
|`visualizerFile`|string|arquivo .natvis a ser usado ao depurar esse processo. Esta opção não é compatível com a impressão bonita GDB. Consulte "showDisplayString" se estiver usando essa configuração.|
|`showDisplayString`|booleano|Quando um visualizadorDe arquivo é especificado, showDisplayString ativará a seqüência de exibição. Ligar esta opção pode causar um desempenho mais lento durante a depuração.|
|`remoteMachineName`|string|A máquina Linux remota que hospeda o gdb e o programa para depurar. Use o Gerenciador de Conexões para a adição de novos computadores Linux. Ao usar cMake, `${debugInfo.remoteMachineName}` a macro pode ser usada como o valor deste campo.|
|`cwd`|string|O diretório de trabalho do alvo na máquina remota. Ao usar cMake, `${debugInfo.defaultWorkingDirectory}` a macro pode ser usada como o valor deste campo. O valor padrão é a raiz do espaço de trabalho remoto, a menos que seja substituído no arquivo *CMakeLists.txt.*|
|`miDebuggerPath`|string|O caminho para o depurador habilitado para MI (como gdb). Quando não especificado, ele procurará path primeiro para o depurador.|
|`miDebuggerServerAddress`|string|Endereço de rede do servidor dedepurador habilitado para MI para se conectar. Exemplo: localhost:1234.|
|`setupCommands`|matriz|Um ou mais comandos GDB/LLDB para executar para configurar o depurador subjacente. Exemplo: `"setupCommands": [ { "text": "-enable-pretty-printing", "description": "Enable GDB pretty printing", "ignoreFailures": true }]`. Consulte [os comandos de configuração de lançamento](#launch_setup_commands).|
|`customLaunchSetupCommands`|matriz|Se fornecido, isso substitui os comandos padrão usados para lançar um alvo por alguns outros comandos. Por exemplo, isso pode ser "-target-attach" para anexar a um processo de destino. Uma lista de comandos vazia substitui os comandos de lançamento por nada, o que pode ser útil se o depurador estiver sendo fornecido opções de lançamento como opções de linha de comando. Exemplo: `"customLaunchSetupCommands": [ { "text": "target-run", "description": "run target", "ignoreFailures": false }]`.|
|`launchCompleteCommand`|string|O comando a ser executado após o depurador é totalmente configurado, para fazer com que o processo de destino seja executado. Os valores permitidos são "exec-run", "exec-continue", "None". O valor padrão é "exec-run".|
|`debugServerPath`|string|Caminho completo opcional para depurar servidor para iniciar. Inadimplência a nulo.|
|`debugServerArgs`|string|Args de servidor de depuração opcional. Inadimplência a nulo.|
|`filterStderr`|booleano|Pesquise o fluxo stderr para padrão iniciado pelo servidor e registre stderr para depurar a saída. Usa `false` como padrão.|
|`coreDumpPath`|string|Caminho completo opcional para um arquivo de despejo principal para o programa especificado. Inadimplência a nulo.|
externalConsole|booleano|Se for verdade, um console é lançado para a depuração. Se `false`, nenhum console é lançado. Usa `false` como padrão. NOTA: Essa opção é ignorada em alguns casos por razões técnicas.|
|`pipeTransport`|string|Quando presente, isso diz ao depurador para se conectar a um computador remoto usando outro executável como um tubo que irá retransmitir entrada/saída padrão entre o Visual Studio e o depurador habilitado para MI (como gdb). Valores permitidos: uma ou mais [opções de transporte de tubulação](#pipe_transport_options).|

## <a name="launch-setup-commands"></a><a name="launch_setup_commands"></a>Comandos de configuração de lançamento

Usado com `setupCommands` a propriedade:

||||
|-|-|-|
|`text`|string|O comando dedepurador para executar.|
|`description`|string|Descrição opcional para o comando.|
|`ignoreFailures`|booleano|Se for verdade, falhas do comando devem ser ignoradas. Usa `false` como padrão.|

## <a name="pipe-transport-options"></a><a name = "pipe_transport_options"></a>Opções de transporte de tubos

Usado com `pipeTransport` a propriedade:

||||
|-|-|-|
|`pipeCwd`|string|O caminho totalmente qualificado para o diretório de trabalho para o programa de tubos.|
|`pipeProgram`|string|O comando de tubulação totalmente qualificado para executar.|
|`pipeArgs`|matriz|Argumentos de linha de comando passados para o programa de tubos para configurar a conexão.|
|`debuggerPath`|string|O caminho completo para o depurador na máquina de destino, por exemplo /usr/bin/gdb.|
|`pipeEnv`|objeto|Variáveis de ambiente passadas para o programa de tubos.|
|`quoteArgs`|booleano|Se os argumentos individuais contiverem caracteres (como espaços ou guias), ele deve ser citado? Se `false`, o comando depurador não será mais citado automaticamente. O padrão é `true`.|

## <a name="source-file-map-options"></a><a name="source_file_map_options"></a>Opções de mapa de arquivo de origem

Use com `sourceFileMap` a propriedade:

||||
|-|-|-|
|`editorPath`|string|A localização do código fonte para o editor localizar.|
|`useForBreakpoints`|booleano|Ao definir pontos de interrupção, este mapeamento de origem deve ser usado. Se `false`, apenas o nome de arquivo e o número da linha forusado para definir pontos de interrupção. Se `true`, pontos de interrupção serão definidos com o caminho completo para o arquivo e o número da linha somente quando este mapeamento de origem for usado. Caso contrário, apenas nome de arquivo e número de linha serão usados ao definir pontos de interrupção. O padrão é `true`.|
