---
title: Abrir projetos de pasta no Visual C++ | Microsoft Docs
ms.custom: 
ms.date: 08/02/2017
ms.reviewer: 
ms.suite: 
ms.technology: cpp-ide
ms.tgt_pltfrm: 
ms.topic: article
dev_langs: C++
helpviewer_keywords: Open Folder Projects in Visual C++
ms.assetid: abd1985e-3717-4338-9e80-869db5435175
author: mikeblome
ms.author: mblome
manager: ghogen
ms.openlocfilehash: da81f8731be97c69a73eddb96e9e56e49c59c91b
ms.sourcegitcommit: 1b480aa74886930b3bd0435d71cfcc3ccda36424
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 11/15/2017
---
# <a name="open-folder-projects-in-visual-c"></a>Abrir projetos de pasta no Visual C++
Visual Studio de 2017 apresenta o recurso "Abrir pasta", que permite que você abrir uma pasta de arquivos de origem e imediatamente para iniciar a codificação com suporte para IntelliSense, pesquisa, refatoração, depuração e assim por diante. Nenhum arquivo. sln ou. vcxproj é carregado; Se necessário, você pode especificar tarefas personalizadas, bem como criar e iniciar parâmetros por meio de arquivos. JSON simples. Abrir a pasta da plataforma, Visual C++ agora pode dar suporte não apenas flexível coleções de arquivos, mas também praticamente qualquer sistema de compilação, incluindo CMake, Ninja, QMake (para projetos Qt), gyp, SCons, Gradle, Buck, verifique e muito mais. 

Para usar a pasta aberta, no menu principal, selecione *arquivo | Abrir | Pasta* ou pressione *Ctrl + Shift + Alt + O*. Imediatamente, o Gerenciador de soluções exibe todos os arquivos na pasta. Você pode clicar em qualquer arquivo para começar a editá-lo. Em segundo plano, o Visual Studio inicia a indexação de arquivos para habilitar o IntelliSense, navegação e recursos de refatoração. Como editar, criar, mover ou excluir arquivos, o Visual Studio rastreia as alterações automaticamente e atualiza continuamente seu índice de IntelliSense. 
  
## <a name="cmake-projects"></a>Projetos CMake
CMake é integrado no IDE do Visual Studio como CMake Tools para Visual C++, um componente da carga de trabalho de área de trabalho do C++. Para obter mais informações, consulte [CMake ferramentas do Visual C++](cmake-tools-for-visual-cpp.md).
 
## <a name="qmake-projects-that-target-the-qt-framework"></a>QMake projetos direcionados ao framework Qt
Você pode usar ferramentas CMake do Visual C++ para destino Qt para compilar projetos Qt, ou você pode usar a extensão do Visual Studio Qt. Observação: A partir de agosto de 2017, o [suporte Qt extensão do Visual Studio para Visual Studio de 2017](https://download.qt.io/development_releases/vsaddin/) está disponível como uma versão beta.

## <a name="gyp-cons-scons-buck-etc"></a>gyp, contras, SCons, Buck, etc
Você pode usar qualquer sistema de compilação no Visual C++ e ainda aproveitar as vantagens do IDE do Visual C++ e depurador. Quando você abre a pasta raiz do seu projeto, o Visual C++ usa heurística para indexar os arquivos de origem para o IntelliSense e pesquisa. Você pode fornecer dicas sobre a estrutura do seu código, editando o arquivo CppProperties.json. De maneira semelhante, você pode configurar seu programa de compilação editando o arquivo launch.vs.json. 

## <a name="configuring-open-folder-projects"></a>Configurando projetos Abrir pasta
Você pode personalizar um projeto de abrir a pasta por meio de três arquivos JSON:
|||
|-|-|
|CppProperties.json|Especifica informações de configuração personalizados para navegação. Crie esse arquivo, se necessário, na pasta do projeto raiz.|
|Launch.vs.JSON|Especifica argumentos de linha de comando. Acessados por meio de **Gerenciador de soluções** item de menu de contexto **depuração e iniciar configurações**.|
|Tasks.vs.JSON|Especifica opções de compilador e de comandos de compilação personalizada. Acessados por meio de **Solution Explorer** item de menu de contexto **configurar tarefas**.|

### <a name="configure-intellisense-with-cpppropertiesjson"></a>Configurar o IntelliSense com CppProperties.json
IntelliSense e pesquisa parcialmente o comportamento depende da configuração de compilação ativo, o que define #include caminhos, opções de compilador e outros parâmetros. Por padrão, o Visual Studio fornece configurações Debug e Release. Para alguns projetos, talvez seja necessário criar uma configuração personalizada para IntelliSense e navegação de recursos compreender totalmente o seu código. Para definir uma nova configuração, crie um arquivo chamado CppProperties.json na pasta raiz. Veja um exemplo:

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
Uma configuração pode ter qualquer uma das seguintes propriedades:

|||  
|-|-| 
|`name`|o nome de configuração que aparece na lista suspensa de configuração do C++|
|`includePath`|a lista de pastas deve ser especificado no caminho de inclusão (mapeado para /I para a maioria dos compiladores)|
|`defines`|a lista de macros que deve ser definida (mapeado para /D para a maioria dos compiladores)|
|`compilerSwitches`|uma ou mais opções adicionais que podem influenciar o comportamento do IntelliSense|
|`forcedInclude`|cabeçalho a ser incluído automaticamente em cada unidade de compilação (mapeia para /FI de MSVC ou - incluem para clang)|
|`undefines`|a lista de macros ser indefinidos maps (a/u para MSVC)|
|`intelliSenseMode`|o mecanismo IntelliSense a ser usado. Você pode especificar as variantes específicas de arquitetura para MSVC, gcc ou Clang:
- MSVC-x86 (padrão)
- MSVC x64
- MSVC arm
- Windows-clang-x86
- Windows-clang-x64
- Windows-clang-arm
- Linux-x64
- Linux-x86
- Linux-arm
- gccarm

Dá suporte a CppProperties.json expansão variável de ambiente para incluir caminhos e outros valores de propriedade. A sintaxe é `${env.FOODIR}` para expandir uma variável de ambiente `%FOODIR%`.

Você também tem acesso às seguintes macros internas dentro desse arquivo:
|||
|-|-|
|`${workspaceRoot}`| o caminho completo para a pasta de trabalho|
|`${projectRoot}`| o caminho completo para a pasta onde CppProperties.json é colocada|
|`${vsInstallDir}`| o caminho completo para a pasta onde a instância em execução de 2017 VS está instalada|

Por exemplo, se seu projeto tem uma pasta de inclusão e também inclui outros cabeçalhos comuns do SDK do Windows e Windows. h, convém atualizar o CppProperties.json inclui o arquivo de configuração com estas:

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

**Observação:** `%WindowsSdkDir%` e `%VCToolsInstallDir%` não estão definidas como variáveis de ambiente globais, então certifique-se de que você inicia o devenv.exe "desenvolvedor Prompt de comando para VS 2017" que define essas variáveis.

Para solucionar problemas de IntelliSense erros causados pela falta de incluem caminhos, abra o **lista de erros** e filtrar a saída para "IntelliSense" e o código de erro E1696 "não é possível abrir o arquivo de origem...". 

Você pode criar qualquer número de configurações em CppProperties.json. Cada um aparecerá na lista suspensa de configuração:

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
### <a name="define-tasks-with-tasksvsjson"></a>Definir tarefas de tasks.vs.json
Você pode automatizar a compilação de scripts ou outras operações externas nos arquivos que você tem em seu espaço de trabalho atual ao executá-los como tarefas diretamente no IDE. Você pode configurar uma nova tarefa, clicando duas vezes em um arquivo ou pasta e selecionando **configurar tarefas**. 

![Abrir pasta configurar tarefas](media/open-folder-config-tasks.png)

Isso cria (ou abrir) o `tasks.vs.json` arquivo na pasta do VS que o Visual Studio cria na pasta do projeto raiz. Você pode definir qualquer tarefa arbitrária neste arquivo e, em seguida, invoca o **Solution Explorer** menu de contexto. O exemplo a seguir mostra um arquivo de tasks.vs.json que define uma única tarefa. `taskName`Define o nome que aparece no menu de contexto. `appliesTo`define quais arquivos o comando pode ser executado em. O `command` propriedade se refere à variável de ambiente COMSPEC, que identifica o caminho para o console (cmd.exe no Windows). O `args` propriedade especifica a linha de comando a ser invocado. O `${file}` macro recupera o arquivo selecionado em **Gerenciador de soluções**. O exemplo a seguir exibirá o nome do arquivo. cpp selecionado no momento.

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
Depois de salvar tasks.vs.json, qualquer arquivo. cpp na pasta de atalho, escolha **Echo filename** no menu de contexto e consulte o nome do arquivo é exibido na janela de saída.

#### <a name="appliesto"></a>appliesTo
Você pode criar tarefas para um arquivo ou pasta, especificando seu nome no `appliesTo` campo, por exemplo `"appliesTo" : "hello.cpp"`. As máscaras de arquivo a seguir podem ser usadas como valores:
|||
|-|-|
|`"*"`| tarefa está disponível para todos os arquivos e pastas no espaço de trabalho|
|`"*/"`| tarefa está disponível para todas as pastas no espaço de trabalho|
|`"*.cpp"`| tarefa está disponível para todos os arquivos com a extensão cpp no espaço de trabalho|
|`"/*.cpp"`| tarefa está disponível para todos os arquivos com a extensão cpp na raiz do espaço de trabalho|
|`"src/*/"`| tarefa está disponível para todas as subpastas da pasta "src"|
|`"makefile"`| tarefa está disponível para todos os arquivos de makefile no espaço de trabalho|
|`"/makefile"`| tarefa está disponível somente para o makefile na raiz do espaço de trabalho|

#### <a name="output"></a>saída
Use o `output` propriedade para especificar o executável que será iniciado quando você pressiona **F5**. Por exemplo:

```json
      "output": "${workspaceRoot}\\bin\\hellomake.exe" 
```

#### <a name="macros-for-tasksvsjson"></a>Macros para tasks.vs.json

|||
|-|-|
|`${env.<VARIABLE>}`| Especifica qualquer variável de ambiente (por exemplo, ${env. CAMINHO} ${env.COMSPEC} e assim por diante) que está definido para o prompt de comando do desenvolvedor. Para obter mais informações, consulte [Prompt de comando do desenvolvedor para o Visual Studio](/dotnet/framework/tools/developer-command-prompt-for-vs).|
|`${workspaceRoot}`| o caminho completo para a pasta de trabalho (por exemplo, "C:\sources\hello")|
|`${file}`| o caminho completo do arquivo ou pasta selecionada para executar essa tarefa (por exemplo, "C:\sources\hello\src\hello.cpp")|
|`${relativeFile}`| o caminho relativo para o arquivo ou pasta (por exemplo, "src\hello.cpp")|
|`${fileBasename}`| o nome do arquivo sem o caminho ou a extensão (por exemplo, "Olá")|
|`${fileDirname}`| o caminho completo para o arquivo, exceto o nome do arquivo (por exemplo, "C:\sources\hello\src")|
|`${fileExtname}`| a extensão do arquivo selecionado (por exemplo, ". cpp")|

#### <a name="custom-macros"></a>Macros personalizadas
Para definir uma macro personalizada em tasks.vs.json, adicione um par de nome: valor antes dos blocos de tarefa. O exemplo a seguir define uma macro denominada `outDir` que é consumido no `args` propriedade:

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
Para personalizar os argumentos de linha de comando do programa, clique com botão direito no executável em **Solution Explorer** e selecione **depuração e iniciar configurações**. Isso abrirá um existente `launch.vs.json` arquivo, ou se não houver nenhum, ele criará um novo arquivo preenchida previamente com as informações sobre o programa que você selecionou. 

Para especificar argumentos adicionais, basta adicioná-las a `args` matriz JSON, conforme mostrado no exemplo a seguir:

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

Quando você salvar este arquivo, a nova configuração aparece na lista suspensa de destino de depuração e você pode selecioná-la para iniciar o depurador. Você pode criar como muitas configurações de depuração que, para qualquer número de executáveis. Se você pressionar **F5** agora, o depurador iniciará e nenhum ponto de interrupção que você já pode ter definido. Todas as janelas do depurador familiar e sua funcionalidade agora estão disponíveis.

## <a name="see-also"></a>Consulte também
[IDE e ferramentas para desenvolvimento no Visual C++](ide-and-tools-for-visual-cpp-development.md)

