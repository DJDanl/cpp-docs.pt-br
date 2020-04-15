---
title: Suporte para Open Folder para sistemas de build do C++ no Visual Studio
ms.date: 12/02/2019
helpviewer_keywords:
- Open Folder Projects in Visual Studio
ms.assetid: abd1985e-3717-4338-9e80-869db5435175
ms.openlocfilehash: 9264aa4bf77de406bdde9042ef9ec4251763f721
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81320957"
---
# <a name="open-folder-support-for-c-build-systems-in-visual-studio"></a>Suporte para Open Folder para sistemas de build do C++ no Visual Studio

::: moniker range="vs-2015"

O recurso Open Folder está disponível no Visual Studio 2017 e posteriormente.

::: moniker-end

::: moniker range=">=vs-2017"

No Visual Studio 2017 e posteriores, o recurso "Abrir Pasta" permite que você abra uma pasta de arquivos de origem e comece a codificar imediatamente, com suporte para IntelliSense, navegação, refatoração, depuração e assim por diante. À medida que você edita, cria, move ou exclui arquivos, o Visual Studio rastreia as alterações automaticamente e atualiza continuamente seu índice do IntelliSense. Nenhum arquivo .sln ou .vcxproj é carregado; se necessário, especifique tarefas personalizadas, além de compilar e iniciar parâmetros por meio de arquivos .json simples. Esse recurso permite que você integre qualquer sistema de compilação de terceiros no Visual Studio. Para obter informações gerais sobre Open Folder, confira [Desenvolver código no Visual Studio sem projetos nem soluções](/visualstudio/ide/develop-code-in-visual-studio-without-projects-or-solutions).

## <a name="cmake-and-qt"></a>CMake e Qt

O CMake é integrado no Visual Studio IDE como um componente da carga de trabalho de desktop C++. O fluxo de trabalho do CMake não é idêntico ao fluxo de trabalho descrito neste artigo. Se você estiver usando o CMake, consulte [projetos CMake no Visual Studio](cmake-projects-in-visual-studio.md). Você também pode usar o CMake para construir projetos Qt, ou pode usar o [Qt Visual Studio Extension](https://download.qt.io/development_releases/vsaddin/) para o Visual Studio 2015 ou o Visual Studio 2017.

## <a name="other-build-systems"></a>Outros sistemas de construção

Para usar o Visual Studio IDE com um sistema de compilação ou conjunto de ferramentas de compilação que não é suportado diretamente a partir do menu principal selecione **Arquivo | Aberto | Pasta** ou **pressione Ctrl + Shift + Alt + O**. Navegue até a pasta que contém seus arquivos de código-fonte. Para construir o projeto, configurar o IntelliSense e definir parâmetros de depuração, você adiciona três arquivos JSON:

| | |
|-|-|
|CppProperties.json|Especifica informações de configuração personalizada para navegação. Crie esse arquivo, se necessário, na pasta raiz do projeto. (Não usado em projetos do CMake.)|
|tasks.vs.json|Especifique comandos de compilação personalizados. Acessados por meio do item de menu de contexto do **Gerenciador de Soluções**, **Configurar tarefas**.|
|launch.vs.json|Especifica argumentos de linha de comando para o depurador. Acessados por meio do item de menu de contexto do **Gerenciador de Soluções**, **Configurações de depuração e de inicialização**.|

## <a name="configure-code-navigation-with-cpppropertiesjson"></a>Configure a navegação de código com CppProperties.json

Para o IntelliSense e o comportamento de navegação, como **Ir para Definição** para funcionar corretamente, o Visual Studio precisa saber qual compilador você está usando, onde estão os cabeçalhos do sistema e onde quaisquer arquivos adicionais incluem se eles não estiverem diretamente na pasta que você abriu (a pasta do espaço de trabalho). Para especificar uma configuração, você pode escolher **Gerenciar configurações** a partir da parte de entrada na barra de ferramentas principal:

![Gerenciar configurações de saque](media/manage-configurations-dropdown.png)

O Visual Studio oferece as seguintes configurações padrão:

![Configurações padrão](media/default-configurations.png)

Se, por exemplo, você escolher **x64-Debug,** o Visual Studio criará um arquivo chamado *CppProperties.json* em sua pasta de projeto raiz:

```json
{
  "configurations": [
    {
      "inheritEnvironments": [
        "msvc_x64"
      ],
      "name": "x64-Debug",
      "includePath": [
        "${env.INCLUDE}",
        "${workspaceRoot}\\**"
      ],
      "defines": [
        "WIN32",
        "_DEBUG",
        "UNICODE",
        "_UNICODE"
      ],
      "intelliSenseMode": "windows-msvc-x64"
    }
  ]
}
```

Esta configuração herda as variáveis de ambiente do Visual Studio [x64 Developer Command Prompt](building-on-the-command-line.md). Uma dessas variáveis `INCLUDE` é e você pode se `${env.INCLUDE}` referir a ela aqui usando a macro. A `includePath` propriedade diz ao Visual Studio onde procurar todas as fontes que precisa para o IntelliSense. Neste caso, diz "olhe em todos os diretórios especificados pela variável ambiente INCLUDE, e também todos os diretórios na árvore atual da pasta de trabalho". A `name` propriedade é o nome que aparecerá no dropdown, e pode ser o que você quiser. A `defines` propriedade fornece dicas ao IntelliSense quando encontra blocos de compilação condicional. A `intelliSenseMode` propriedade fornece algumas dicas adicionais com base no tipo de compilador. Várias opções estão disponíveis para MSVC, GCC e Clang.

> [!NOTE]
> Se o Visual Studio parece estar ignorando as configurações em *CppProperties.json,* tente `!/CppProperties.json`adicionar uma exceção ao seu arquivo *.gitignore* assim: .

## <a name="default-configuration-for-mingw-w64"></a>Configuração padrão para MinGW-w64

Se você adicionar a configuração MinGW-W64, o JSON será este:

```json
{
  {
      "inheritEnvironments": [
        "mingw_64"
      ],
      "name": "Mingw64",
      "includePath": [
        "${env.INCLUDE}",
        "${workspaceRoot}\\**"
      ],
      "intelliSenseMode": "linux-gcc-x64",
      "environments": [
        {
          "MINGW64_ROOT": "C:\\msys64\\mingw64",
          "BIN_ROOT": "${env.MINGW64_ROOT}\\bin",
          "FLAVOR": "x86_64-w64-mingw32",
          "TOOLSET_VERSION": "9.1.0",
          "PATH": "${env.BIN_ROOT};${env.MINGW64_ROOT}\\..\\usr\\local\\bin;${env.MINGW64_ROOT}\\..\\usr\\bin;${env.MINGW64_ROOT}\\..\\bin;${env.PATH}",
          "INCLUDE": "${env.MINGW64_ROOT}\\include\\c++\\${env.TOOLSET_VERSION};${env.MINGW64_ROOT}\\include\\c++\\${env.TOOLSET_VERSION}\\tr1;${env.MINGW64_ROOT}\\include\\c++\\${env.TOOLSET_VERSION}\\${env.FLAVOR}",
          "environment": "mingw_64"
        }
      ]
    }
}
```

Anote `environments` o bloco. Ele define propriedades que se comportam como variáveis de ambiente e estão disponíveis não apenas no arquivo *CppProperties.json,* mas também na outra tarefa de arquivos de *configuração.vs.json* e *launch.vs.json*. A `Mingw64` configuração `mingw_w64` herda o `INCLUDE` ambiente e usa `includePath`sua propriedade para especificar o valor para . Você pode adicionar outros caminhos a esta propriedade de matriz, conforme necessário.

A `intelliSenseMode` propriedade é definida como um valor apropriado para GCC. Para obter mais informações sobre todas essas propriedades, consulte [referência do esquema CppProperties](cppproperties-schema-reference.md).

Quando tudo estiver funcionando corretamente, você verá o IntelliSense a partir dos cabeçalhos GCC quando você passar o tempo sobre um tipo:

![GCC IntelliSense](media/gcc-intellisense.png)

## <a name="enable-intellisense-diagnostics"></a>Habilite os diagnósticos do IntelliSense

Se você não estiver vendo o IntelliSense que você espera, você pode solucionar problemas indo para O**Editor** > de texto**de opções** >  **de ferramentas** > **C/C++** > **avançado** e configurando Ativar **o registro** para **true**. Para começar, tente definir **o nível de registro** para 5 e os **filtros de registro** para 8.

![Registro de diagnóstico](media/diagnostic-logging.png)

A saída é canalizada para a **janela de saída** e é visível quando você escolhe * Mostrar saída*de: Log Visual C++*. A saída contém, entre outras coisas, a lista de caminhos reais que o IntelliSense está tentando usar. Se os caminhos não corresponderem aos do *CppProperties.json,* tente fechar a pasta e excluir a subpasta *.vs* que contém dados de navegação em cache.

### <a name="define-build-tasks-with-tasksvsjson"></a>Definir tarefas de build com tasks.vs.json

Você pode automatizar os scripts de compilação, ou quaisquer outras operações externas nos arquivos existentes em seu workspace atual, executando-os como tarefas diretamente no IDE. Você pode configurar uma nova tarefa clicando com o botão direito em um arquivo ou pasta e selecionando **Configurar Tarefas**.

![Configurar Tarefas do recurso Abrir Pasta](media/configure-tasks.png)

Isso cria (ou abre) o arquivo *tasks.vs.json* na pasta .vs que o Visual Studio cria em sua pasta de projeto raiz. Defina qualquer tarefa arbitrária nesse arquivo e, em seguida, invoque-a no menu de contexto do **Gerenciador de Soluções**. Para continuar o exemplo do GCC, o trecho a seguir mostra um arquivo *de tarefas completas.vs.json* com uma tarefa única que invoca *g++.exe* para construir um projeto. Suponha que o projeto contenha um único arquivo chamado *hello.cpp*.

```json
{
  "version": "0.2.1",
  "tasks": [
    {
      "taskLabel": "build hello",
      "appliesTo": "/",
      "type": "default",
      "command": "g++",
      "args": [
        "-g",
        "-o",
        "hello",
        "hello.cpp"
      ]
    }
  ]
}

```

O arquivo JSON é colocado na subpasta *.vs.* Para ver essa pasta, clique no botão **Mostrar todos os arquivos** na parte superior do Solution **Explorer**. Você pode executar esta tarefa clicando com o botão direito do mouse no nó raiz no **Solution Explorer** e escolhendo **build hello**. Quando a tarefa for concluída, você deve ver um novo arquivo, *hello.exe* no **Solution Explorer**.

Você pode definir muitos tipos de tarefas. O exemplo a seguir mostra um *arquivo tasks.vs.json* que define uma única tarefa. `taskLabel` define o nome exibido no menu de contexto. `appliesTo` define em quais arquivos o comando pode ser executado. A `command` propriedade refere-se à variável ambiente COMSPEC, que identifica o caminho para o console (*cmd.exe* no Windows). Referencie também variáveis de ambiente declaradas em CppProperties.json ou CMakeSettings.json. A propriedade `args` especifica a linha de comando a ser invocada. A macro `${file}` recupera o arquivo selecionado no **Gerenciador de Soluções**. O exemplo a seguir exibirá o nome do arquivo .cpp atualmente selecionado.

```json
{
  "version": "0.2.1",
  "tasks": [
    {
      "taskLabel": "Echo filename",
      "appliesTo": "*.cpp",
      "type": "command",
      "command": "${env.COMSPEC}",
      "args": ["echo ${file}"]
    }
  ]
}
```

Depois de salvar *tasks.vs.json,* você pode clicar com o botão direito do mouse em qualquer arquivo *.cpp* na pasta, escolher **o nome** do arquivo Echo no menu de contexto e ver o nome do arquivo exibido na janela Saída.

Para obter mais informações, confira [Referência de esquema de Tasks.vs.json](tasks-vs-json-schema-reference-cpp.md).

### <a name="configure-debugging-parameters-with-launchvsjson"></a>Configurar parâmetros de depuração com launch.vs.json

Para personalizar os argumentos da linha de comando do programa e as instruções de depuração, clique com o botão direito do mouse no executável no **Solution Explorer** e selecione **Debug e Launch Settings**. Isso abrirá um arquivo *launch.vs.json* existente, ou se nenhum existir, criará um novo arquivo com um conjunto de configurações mínimas de lançamento. Primeiro você tem a escolha de que tipo de sessão de depuração você deseja configurar. Para depurar um projeto MinGw-w64, escolhemos **o lançamento de C/C++ para MinGW/Cygwin (gdb)**. Isso cria uma configuração de lançamento para usar *gdb.exe* com alguns palpites educados sobre valores padrão. Um desses valores `MINGW_PREFIX`padrão é . Você pode substituir o caminho literal (como mostrado `MINGW_PREFIX` abaixo) ou você pode definir uma propriedade em *CppProperties.json*:

```json
{
  "version": "0.2.1",
  "defaults": {},
  "configurations": [
    {
      "type": "cppdbg",
      "name": "hello.exe",
      "project": "hello.exe",
      "cwd": "${workspaceRoot}",
      "program": "${debugInfo.target}",
      "MIMode": "gdb",
      "miDebuggerPath": "c:\\msys64\\usr\\bin\\gdb.exe",
      "externalConsole": true
    }
  ]
}

```

Para iniciar a depuração, escolha o executável na parada de depuração e clique na seta verde:

![Depurador de lançamento](media/launch-debugger-gdb.png)

Você deve ver a caixa de diálogo **Inicializar depurador** e, em seguida, uma janela externa do console que está executando o seu programa.

Para obter mais informações, consulte [a referência do esquema launch.vs.json](launch-vs-schema-reference-cpp.md).

## <a name="launching-other-executables"></a>Lançamento de outros executáveis

Você pode definir as configurações de lançamento para qualquer executável em seu computador. O exemplo a seguir inicia *o 7za* e especifica `args` argumentos adicionais, adicionando-os à matriz JSON:

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

::: moniker-end
