---
title: Projetos Abrir Pasta no Visual C++ | Microsoft Docs
ms.custom: ''
ms.date: 06/01/2018
ms.technology:
- cpp-ide
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- Open Folder Projects in Visual C++
ms.assetid: abd1985e-3717-4338-9e80-869db5435175
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: aefcd05f4187e22adf5f21c4beffa74ca8be39b3
ms.sourcegitcommit: 799f9b976623a375203ad8b2ad5147bd6a2212f0
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/19/2018
ms.locfileid: "46420550"
---
# <a name="open-folder-projects-in-visual-c"></a>Projetos Abrir Pasta no Visual C++

No Visual Studio 2017 e posteriores, o recurso "Abrir Pasta" permite que você abra uma pasta de arquivos de origem e comece a codificar imediatamente, com suporte para IntelliSense, navegação, refatoração, depuração e assim por diante. Nenhum arquivo .sln ou .vcxproj é carregado; se necessário, especifique tarefas personalizadas, além de compilar e iniciar parâmetros por meio de arquivos .json simples.
Ativado pelo recurso Abrir Pasta, o Visual C++ agora pode dar suporte não apenas a coleções flexíveis de arquivos, mas também a praticamente qualquer sistema de build, incluindo CMake, Ninja, QMake (para projetos Qt), gyp, SCons, Gradle, Buck, make e muito mais.

Para usar o recurso Abrir Pasta, no menu principal, selecione *Arquivo | Abrir | Pasta* ou pressione *Ctrl+Shift+Alt+O*. Imediatamente, o Gerenciador de Soluções exibe todos os arquivos da pasta. Você pode clicar em qualquer arquivo para começar a editá-lo. Em segundo plano, o Visual Studio inicia a indexação dos arquivos para habilitar os recursos de IntelliSense, navegação e refatoração. À medida que você edita, cria, move ou exclui arquivos, o Visual Studio rastreia as alterações automaticamente e atualiza continuamente seu índice do IntelliSense.

## <a name="cmake-projects"></a>Projetos do CMake

O CMake é integrado ao IDE do Visual Studio como as Ferramentas CMake para Visual C++, um componente da carga de trabalho de área de trabalho do C++. Para saber mais, veja [Ferramentas do CMake no Visual C++](cmake-tools-for-visual-cpp.md).

## <a name="qmake-projects-that-target-the-qt-framework"></a>Projetos QMake direcionados à estrutura Qt

Você pode usar as Ferramentas CMake para Visual C++ para direcionar ao Qt para criar projetos Qt ou usar a [Extensão Qt Visual Studio](https://download.qt.io/development_releases/vsaddin/) para Visual Studio 2015 ou Visual Studio 2017.

## <a name="gyp-cons-scons-buck-etc"></a>gyp, Cons, SCons, Buck, etc.

Use qualquer sistema de build no Visual C++ e ainda aproveite as vantagens do IDE e do depurador do Visual C++. Quando você abre a pasta raiz do projeto, o Visual C++ usa a heurística para indexar os arquivos de origem para o IntelliSense e a navegação. Forneça dicas sobre a estrutura do código editando o arquivo CppProperties.json. De maneira semelhante, configure o programa de build editando o arquivo launch.vs.json.

## <a name="configuring-open-folder-projects"></a>Configurando projetos Abrir Pasta

Personalize um projeto Abrir Pasta por meio de três arquivos JSON:
|||
|-|-|
|CppProperties.json|Especifica informações de configuração personalizada para navegação. Crie esse arquivo, se necessário, na pasta raiz do projeto.|
|launch.vs.json|Especifica argumentos de linha de comando. Acessados por meio do item de menu de contexto do **Gerenciador de Soluções**, **Configurações de depuração e de inicialização**.|
|tasks.vs.json|Especifica opções do compilador e comandos de build personalizados. Acessados por meio do item de menu de contexto do **Gerenciador de Soluções**, **Configurar tarefas**.|

### <a name="configure-intellisense-with-cpppropertiesjson"></a>Configurar o IntelliSense com CppProperties.json

O comportamento do IntelliSense e da navegação depende parcialmente da configuração de build ativa, que define caminhos #include, opções do compilador e outros parâmetros. Por padrão, o Visual Studio fornece configurações de Depuração e Versão. Para alguns projetos, talvez seja necessário criar uma configuração personalizada para que as funcionalidades do IntelliSense e de navegação compreendam o código por completo. Para definir uma nova configuração, crie um arquivo chamado CppProperties.json na pasta raiz. Veja um exemplo:

```json
{
  "configurations": [
    {
      "name": "Windows x64",
      "includePath": [ "include" ],
      "defines": [ "_DEBUG" ],
      "compilerSwitches": "/std:c++17",
      "intelliSenseMode": "msvc-x64",
      "forcedInclude": [ "pch.h" ],
      "undefines": []
    }
  ]
}
```
Uma configuração pode ter uma das seguintes propriedades:

|||
|-|-|
|`name`|o nome de configuração exibido na lista suspensa de configuração do C++|
|`includePath`|a lista de pastas que deve ser especificada no caminho de inclusão (mapeada para /I na maioria dos compiladores)|
|`defines`|a lista de macros que deve ser definida (mapeada para /D na maioria dos compiladores)|
|`compilerSwitches`|uma ou mais opções adicionais que podem influenciar o comportamento do IntelliSense|
|`forcedInclude`|o cabeçalho a ser incluído automaticamente em cada unidade de compilação (mapeado para /FI no MSVC ou -include no Clang)|
|`undefines`|a lista de macros a ter as definições excluídas (mapeada para /U no MSVC)|
|`intelliSenseMode`|o mecanismo IntelliSense a ser usado. Especifique as variantes específicas à arquitetura para o MSVC, o GCC ou o Clang:<br/><br/>- msvc-x86 (padrão)<br/>- msvc-x64<br/>- msvc-arm<br/>- windows-clang-x86<br/>- windows-clang-x64<br/>- windows-clang-arm<br/>- Linux-x64<br/>- Linux-x86<br/>- Linux-arm<br/>- gccarm|

#### <a name="environment-variables"></a>Variáveis de ambiente

CppProperties.json dá suporte à expansão de variáveis de ambiente do sistema para caminhos de inclusão e outros valores de propriedade. A sintaxe é `${env.FOODIR}` para expandir uma variável de ambiente `%FOODIR%`. Também há suporte para as seguintes variáveis definidas pelo sistema:

|Nome da variável|Descrição|
|-----------|-----------------|
|vsdev|O ambiente padrão do Visual Studio|
|msvc_x86|Compilar para x86 usando ferramentas x86|
|msvc_arm|Compilar para ARM usando ferramentas x86|
|msvc_arm64|Compilar para ARM64 usando ferramentas x86|
|msvc_x86_x64|Compilar para AMD64 usando ferramentas x86|
|msvc_x64_x64|Compilar para AMD64 usando ferramentas de 64 bits|
|msvc_arm_x64|Compilar para ARM usando ferramentas de 64 bits|
|msvc_arm64_x64|Compilar para ARM64 usando ferramentas de 64 bits|

Quando a carga de trabalho do Linux é instalada, os seguintes ambientes ficam disponíveis para o direcionamento remoto do Linux e do WSL:

|Nome da variável|Descrição|
|-----------|-----------------|
|linux_x86|Direcionar ao Linux x86 remotamente|
|linux_x64|Direcionar ao Linux x64 remotamente|
|linux_arm|Direcionar ao ARM Linux remotamente|

Defina variáveis de ambiente personalizadas em CppProperties.json globalmente ou por configuração. O exemplo a seguir mostra como as variáveis de ambiente padrão e personalizadas podem ser declaradas e usadas. A propriedade **environments** global declara uma variável chamada **INCLUDE** que pode ser usada por qualquer configuração:

```json
{
  // The "environments" property is an array of key value pairs of the form
  // { "EnvVar1": "Value1", "EnvVar2": "Value2" }
  "environments": [
    {
      "INCLUDE": "${workspaceRoot}\\src\\includes"
    }
  ],

  "configurations": [
    {
      "inheritEnvironments": [
        // Inherit the MSVC 32-bit environment and toolchain.
        "msvc_x86"
      ],
      "name": "x86",
      "includePath": [
        // Use the include path defined above.
        "${env.INCLUDE}"
      ],
      "defines": [ "WIN32", "_DEBUG", "UNICODE", "_UNICODE" ],
      "intelliSenseMode": "msvc-x86"
    },
    {
      "inheritEnvironments": [
        // Inherit the MSVC 64-bit environment and toolchain.
        "msvc_x64"
      ],
      "name": "x64",
      "includePath": [
        // Use the include path defined above.
        "${env.INCLUDE}"
      ],
      "defines": [ "WIN32", "_DEBUG", "UNICODE", "_UNICODE" ],
      "intelliSenseMode": "msvc-x64"
    }
  ]
}
```
Defina também uma propriedade **environments** dentro de uma configuração, de modo que ela só se aplique a essa configuração e substitua todas as variáveis globais com o mesmo nome. No seguinte exemplo, a configuração x64 define uma variável **INCLUDE** local que substitui o valor global:

```json
{
  "environments": [
    {
      "INCLUDE": "${workspaceRoot}\\src\\includes"
    }
  ],

  "configurations": [
    {
      "inheritEnvironments": [
        "msvc_x86"
      ],
      "name": "x86",
      "includePath": [
        // Use the include path defined in the global environments property.
        "${env.INCLUDE}"
      ],
      "defines": [ "WIN32", "_DEBUG", "UNICODE", "_UNICODE" ],
      "intelliSenseMode": "msvc-x86"
    },
    {
      "environments": [
        {
          // Append 64-bit specific include path to env.INCLUDE.
          "INCLUDE": "${env.INCLUDE};${workspaceRoot}\\src\\includes64"
        }
      ],

      "inheritEnvironments": [
        "msvc_x64"
      ],
      "name": "x64",
      "includePath": [
        // Use the include path defined in the local environments property.
        "${env.INCLUDE}"
      ],
      "defines": [ "WIN32", "_DEBUG", "UNICODE", "_UNICODE" ],
      "intelliSenseMode": "msvc-x64"
    }
  ]
}
```

Todas as variáveis de ambiente padrão e personalizadas também estão disponíveis em tasks.vs.json e launch.vs.json.

#### <a name="macros"></a>Macros

Você tem acesso às seguintes macros internas dentro de CppProperties.json:
|||
|-|-|
|`${workspaceRoot}`| o caminho completo para a pasta de espaço de trabalho|
|`${projectRoot}`| o caminho completo para a pasta na qual CppProperties.json foi colocado|
|`${vsInstallDir}`| o caminho completo para a pasta na qual a instância em execução do VS 2017 está instalada|

Por exemplo, se o projeto tem uma pasta de inclusão e também inclui windows.h e outros cabeçalhos comuns do SDK do Windows, recomendamos que você atualize o arquivo de configuração CppProperties.json com estas inclusões:

```json
{
  "configurations": [
    {
      "name": "Windows",
      "includePath": [
        // local include folder
        "${workspaceRoot}\\include",
        // Windows SDK and CRT headers
        "${env.WindowsSdkDir}include\\${env.WindowsSDKVersion}\\ucrt",
        "${env.NETFXSDKDir}\\include\\um",
        "${env.WindowsSdkDir}include\\${env.WindowsSDKVersion}\\um",
        "${env.WindowsSdkDir}include\\${env.WindowsSDKVersion}\\shared",
        "${env.VCToolsInstallDir}include"
      ]
    }
  ]
}
```

> [!Note]
> `%WindowsSdkDir%` e `%VCToolsInstallDir%` não são definidos como variáveis de ambiente globais; portanto, inicie devenv.exe em um "Prompt de Comando do Desenvolvedor para VS 2017" que define essas variáveis.

Para solucionar erros do IntelliSense causados por caminhos de inclusão ausentes, abra a **Lista de Erros** e filtre a saída para "somente IntelliSense" e o código de erro E1696 "não é possível abrir o arquivo de origem...".

É possível criar qualquer quantidade de configurações em CppProperties.json. Cada uma delas será exibida na lista suspensa de configurações:

```json
{
  "configurations": [
    {
      "name": "Windows",
      ...
    },
    {
      "name": "with EXTERNAL_CODECS",
      ...
    }
  ]
}
```
### <a name="define-tasks-with-tasksvsjson"></a>Definir tarefas com tasks.vs.json

Você pode automatizar os scripts de compilação, ou quaisquer outras operações externas nos arquivos existentes em seu espaço de trabalho atual, executando-os como tarefas diretamente no IDE. Você pode configurar uma nova tarefa clicando com o botão direito em um arquivo ou pasta e selecionando **Configurar Tarefas**.

![Configurar Tarefas do recurso Abrir Pasta](media/open-folder-config-tasks.png)

Isso cria (ou abre) o arquivo `tasks.vs.json` na pasta .vs criada pelo Visual Studio na pasta raiz do projeto. Defina qualquer tarefa arbitrária nesse arquivo e, em seguida, invoque-a no menu de contexto do **Gerenciador de Soluções**. O exemplo a seguir mostra um arquivo tasks.vs.json que define uma única tarefa. `taskName` define o nome exibido no menu de contexto. `appliesTo` define em quais arquivos o comando pode ser executado. A propriedade `command` se refere à variável de ambiente COMSPEC, que identifica o caminho para o console (cmd.exe no Windows). Referencie também variáveis de ambiente declaradas em CppProperties.json ou CMakeSettings.json. A propriedade `args` especifica a linha de comando a ser invocada. A macro `${file}` recupera o arquivo selecionado no **Gerenciador de Soluções**. O exemplo a seguir exibirá o nome do arquivo .cpp atualmente selecionado.

```json
{
  "version": "0.2.1",
  "tasks": [
    {
      "taskName": "Echo filename",
      "appliesTo": "*.cpp",
      "type": "command",
      "command": "${env.COMSPEC}",
      "args": ["echo ${file}"]
    }
  ]
}
```
Depois de salvar tasks.vs.json, clique com o botão direito do mouse em qualquer arquivo .cpp na pasta, escolha **Ecoar nome de arquivo** no menu de contexto e veja o nome de arquivo exibido na janela de Saída.

#### <a name="appliesto"></a>appliesTo

Você pode criar tarefas para qualquer arquivo ou pasta especificando seu nome no campo `appliesTo`, por exemplo `"appliesTo" : "hello.cpp"`. As máscaras de arquivo a seguir podem ser usadas como valores:
|||
|-|-|
|`"*"`| a tarefa está disponível para todos os arquivos e pastas no espaço de trabalho|
|`"*/"`| a tarefa está disponível para todas as pastas no espaço de trabalho|
|`"*.cpp"`| a tarefa está disponível para todos os arquivos com a extensão .cpp no espaço de trabalho|
|`"/*.cpp"`| a tarefa está disponível para todos os arquivos com a extensão .cpp na raiz do espaço de trabalho|
|`"src/*/"`| a tarefa está disponível para todas as subpastas da pasta "src"|
|`"makefile"`| a tarefa está disponível para todos os arquivos makefile no espaço de trabalho|
|`"/makefile"`| a tarefa está disponível apenas para o makefile na raiz do espaço de trabalho|

#### <a name="output"></a>saída

Use a propriedade `output` para especificar o executável que será iniciado quando você pressionar **F5**. Por exemplo:

```json
      "output": "${workspaceRoot}\\bin\\hellomake.exe"
```

#### <a name="macros-for-tasksvsjson"></a>Macros para tasks.vs.json

|||
|-|-|
|`${env.<VARIABLE>}`| especifica qualquer variável de ambiente (por exemplo, ${env.PATH}, ${env.COMSPEC} e assim por diante) que esteja definida para o Prompt de Comando do Desenvolvedor. Para saber mais, confira [Prompt de comando do desenvolvedor para Visual Studio](/dotnet/framework/tools/developer-command-prompt-for-vs).|
|`${workspaceRoot}`| o caminho completo para a pasta de espaço de trabalho (por exemplo, "C:\sources\hello")|
|`${file}`| o caminho completo do arquivo ou da pasta selecionado para execução dessa tarefa (por exemplo, "C:\sources\hello\src\hello.cpp")|
|`${relativeFile}`| o caminho relativo para o arquivo ou a pasta (por exemplo, "src\hello.cpp")|
|`${fileBasename}`| o nome do arquivo sem o caminho nem a extensão (por exemplo, "hello")|
|`${fileDirname}`| o caminho completo para o arquivo, exceto o nome de arquivo (por exemplo, "C:\sources\hello\src")|
|`${fileExtname}`| a extensão do arquivo selecionado (por exemplo, ".cpp")|

#### <a name="custom-macros"></a>Macros personalizadas

Para definir uma macro personalizada em tasks.vs.json, adicione um par nome:valor antes dos blocos de tarefa. O seguinte exemplo define uma macro chamada `outDir` que é consumida na propriedade `args`:

```json
{
"version": "0.2.1",
  "outDir": "${workspaceRoot}\\bin",
  "tasks": [
    {
      "taskName": "List outputs",
      "*",
      "type": "command",
      "command": "${env.COMSPEC}",
      "args": [
        "dir ${outDir}"
      ]
    }
  ]
```

### <a name="configure-debugging-parameters-with-launchvsjson"></a>Configurar parâmetros de depuração com launch.vs.json

Para personalizar os argumentos de linha de comando do programa, clique com o botão direito do mouse no executável no **Gerenciador de Soluções** e selecione **Configurações de Depuração e de Inicialização**. Isso abrirá um arquivo `launch.vs.json` existente ou, se não houver nenhum, ele criará um arquivo pré-populado com as informações sobre o programa selecionado.

Para especificar argumentos adicionais, basta adicioná-los na matriz JSON `args`, conforme mostrado no seguinte exemplo:

```json
{
  "version": "0.2.1",
  "defaults": {},
  "configurations": [
    {
      "type": "default",
      "project": "CPP\\7zip\\Bundles\\Alone\\O\\7za.exe",
      "name": "7za.exe list content of helloworld.zip",
      "args": [ "l", "d:\\sources\\helloworld.zip" ]
    }
  ]
}
```

Quando você salva esse arquivo, a nova configuração é exibida na lista suspensa Destino de Depuração e você pode selecioná-la para iniciar o depurador. Crie quantas configurações de depuração desejar para qualquer quantidade de executáveis. Se você pressionar **F5** agora, o depurador será iniciado e atingirá qualquer ponto de interrupção que você já possa ter definido. Todas as janelas do depurador conhecidas e sua funcionalidade agora estão disponíveis.

## <a name="see-also"></a>Consulte também

[IDE e ferramentas para desenvolvimento no Visual C++](ide-and-tools-for-visual-cpp-development.md)

