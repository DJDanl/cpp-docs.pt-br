---
title: Suporte para Open Folder para sistemas de build do C++ no Visual Studio
ms.date: 03/21/2019
helpviewer_keywords:
- Open Folder Projects in Visual Studio
ms.assetid: abd1985e-3717-4338-9e80-869db5435175
ms.openlocfilehash: 8856a5b1782c75c5a59dfdc93a8203627059ea12
ms.sourcegitcommit: fde637f823494532314790602c2819f889706ff6
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 06/13/2019
ms.locfileid: "67042727"
---
# <a name="open-folder-projects-for-c"></a>Projetos Open Folder para C++

No Visual Studio 2017 e posteriores, o recurso "Abrir Pasta" permite que você abra uma pasta de arquivos de origem e comece a codificar imediatamente, com suporte para IntelliSense, navegação, refatoração, depuração e assim por diante. Nenhum arquivo .sln ou .vcxproj é carregado; se necessário, especifique tarefas personalizadas, além de compilar e iniciar parâmetros por meio de arquivos .json simples. Para obter informações gerais sobre Open Folder, confira [Desenvolver código no Visual Studio sem projetos nem soluções](/visualstudio/ide/develop-code-in-visual-studio-without-projects-or-solutions).

CMake está integrado no IDE do Visual Studio como um componente do C++ carga de trabalho da área de trabalho. Para saber mais, confira [Projetos CMake no Visual Studio](cmake-projects-in-visual-studio.md). Para qualquer outro sistema de build, você pode usar o recurso Open Folder. O Open Folder efetivamente separa o editor de códigos, o depurador e os analisadores do sistema de build e o conjunto de ferramentas do compilador. Você pode usar o editor de código C++ com seus recursos avançados do IntelliSense, analisadores de código e depurador do Visual Studio com praticamente qualquer sistema de build, incluindo CMake, Ninja, QMake (para projetos Qt), gyp, SCons, Gradle, Buck, make, entre outros. Ele funciona inclusive até mesmo com um único arquivo ou um conjunto flexível de arquivos sem nenhum sistema de build.

Para usar o recurso Abrir Pasta, no menu principal, selecione **Arquivo | Abrir | Pasta** ou pressione **Ctrl+Shift+Alt+O**. Imediatamente, o Gerenciador de Soluções exibe todos os arquivos da pasta. Você pode clicar em qualquer arquivo para começar a editá-lo. Em segundo plano, o Visual Studio inicia a indexação dos arquivos para habilitar os recursos de IntelliSense, navegação e refatoração. À medida que você edita, cria, move ou exclui arquivos, o Visual Studio rastreia as alterações automaticamente e atualiza continuamente seu índice do IntelliSense. 

## <a name="qmake-projects-that-target-the-qt-framework"></a>Projetos QMake direcionados à estrutura Qt

Você pode usar o CMake para compilar projetos Qt, ou você pode usar o [extensão do Visual Studio Qt](https://download.qt.io/development_releases/vsaddin/) para Visual Studio 2015 ou Visual Studio 2017.

## <a name="gyp-cons-scons-buck-etc"></a>gyp, Cons, SCons, Buck, etc.

Use qualquer sistema de build no Visual Studio e ainda aproveite as vantagens do IDE e do depurador C++. Quando você abre a pasta raiz do projeto, o editor de código C++ usa a heurística para indexar os arquivos de origem para o IntelliSense e a navegação. Forneça dicas sobre a estrutura do código editando o arquivo CppProperties.json. De maneira semelhante, configure e invoque o programa de build editando o arquivo launch.vs.json.

## <a name="configuring-open-folder-projects"></a>Configurando projetos Abrir Pasta

Personalize um projeto Abrir Pasta por meio de três arquivos JSON:

| | |
|-|-|
|CppProperties.json|Especifica informações de configuração personalizada para navegação. Crie esse arquivo, se necessário, na pasta raiz do projeto. (Não usado em projetos do CMake.)|
|tasks.vs.json|Especifica opções do compilador e comandos de build personalizados. Acessados por meio do item de menu de contexto do **Gerenciador de Soluções**, **Configurar tarefas**.|
|launch.vs.json|Especifica argumentos de linha de comando para o depurador. Acessados por meio do item de menu de contexto do **Gerenciador de Soluções**, **Configurações de depuração e de inicialização**.|

### <a name="configure-intellisense-and-browsing-hints-with-cpppropertiesjson"></a>Configurar o IntelliSense e dicas de navegação com CppProperties.json

O comportamento do IntelliSense e da navegação depende parcialmente da configuração de build ativa, que define caminhos #include, opções do compilador e outros parâmetros. Por padrão, o Visual Studio fornece configurações de Depuração e Versão. Projetos CMake usam os arquivos CMakeSettings.json e um arquivo CMakeLists.txt para essa finalidade. Para outros tipos de projetos Open Folder, talvez seja necessário criar uma configuração personalizada para que as funcionalidades do IntelliSense e de navegação compreendam o código por completo. Para definir uma nova configuração, crie um arquivo chamado CppProperties.json na pasta raiz. Veja um exemplo:

```json
{
  "configurations": [
    {
      "name": "Windows x64",
      "includePath": [ "include" ],
      "defines": [ "_DEBUG" ],
      "compilerSwitches": "/std:c++17",
      "intelliSenseMode": "windows-msvc-x64",
      "forcedInclude": [ "pch.h" ],
      "undefines": []
    }
  ]
}
```
Para obter mais informações, confira [Referência de esquema CppProperties](cppproperties-schema-reference.md).

### <a name="define-build-tasks-with-tasksvsjson"></a>Definir tarefas de build com tasks.vs.json

Você pode automatizar os scripts de compilação, ou quaisquer outras operações externas nos arquivos existentes em seu workspace atual, executando-os como tarefas diretamente no IDE. Você pode configurar uma nova tarefa clicando com o botão direito em um arquivo ou pasta e selecionando **Configurar Tarefas**.

![Configurar Tarefas do recurso Abrir Pasta](media/open-folder-config-tasks.png)

Isso cria (ou abre) o **Tasks** arquivo na pasta. VS, o que o Visual Studio cria na pasta raiz do projeto. Defina qualquer tarefa arbitrária nesse arquivo e, em seguida, invoque-a no menu de contexto do **Gerenciador de Soluções**. O exemplo a seguir mostra um arquivo tasks.vs.json que define uma única tarefa. `taskName` define o nome exibido no menu de contexto. `appliesTo` define em quais arquivos o comando pode ser executado. A propriedade `command` se refere à variável de ambiente COMSPEC, que identifica o caminho para o console (cmd.exe no Windows). Referencie também variáveis de ambiente declaradas em CppProperties.json ou CMakeSettings.json. A propriedade `args` especifica a linha de comando a ser invocada. A macro `${file}` recupera o arquivo selecionado no **Gerenciador de Soluções**. O exemplo a seguir exibirá o nome do arquivo .cpp atualmente selecionado.

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

Para obter mais informações, confira [Referência de esquema de Tasks.vs.json](tasks-vs-json-schema-reference-cpp.md).

### <a name="configure-debugging-parameters-with-launchvsjson"></a>Configurar parâmetros de depuração com launch.vs.json

Para personalizar os argumentos de linha de comando do programa, clique com o botão direito do mouse no executável no **Gerenciador de Soluções** e selecione **Configurações de Depuração e de Inicialização**. Isso abrirá uma existente **Launch** arquivo, ou se não houver nenhum, ele criará um novo arquivo pré-preenchida com as informações sobre o programa que você selecionou.

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
