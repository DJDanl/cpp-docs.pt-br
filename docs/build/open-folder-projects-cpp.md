---
title: Suporte para Open Folder para sistemas de build do C++ no Visual Studio
ms.date: 08/20/2019
helpviewer_keywords:
- Open Folder Projects in Visual Studio
ms.assetid: abd1985e-3717-4338-9e80-869db5435175
ms.openlocfilehash: 78b1c00b07423e9d02f585c707156a1c843bea6f
ms.sourcegitcommit: ace42fa67e704d56d03c03745b0b17d2a5afeba4
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/22/2019
ms.locfileid: "69975987"
---
# <a name="open-folder-support-for-c-build-systems-in-visual-studio"></a>Suporte para Open Folder para sistemas de build do C++ no Visual Studio

::: moniker range="vs-2015"

O recurso abrir pasta está disponível no Visual Studio 2017 e posterior.

::: moniker-end

::: moniker range=">=vs-2017"

No Visual Studio 2017 e posteriores, o recurso "Abrir Pasta" permite que você abra uma pasta de arquivos de origem e comece a codificar imediatamente, com suporte para IntelliSense, navegação, refatoração, depuração e assim por diante. À medida que você edita, cria, move ou exclui arquivos, o Visual Studio rastreia as alterações automaticamente e atualiza continuamente seu índice do IntelliSense. Nenhum arquivo .sln ou .vcxproj é carregado; se necessário, especifique tarefas personalizadas, além de compilar e iniciar parâmetros por meio de arquivos .json simples. Esse recurso permite que você integre qualquer sistema de compilação de terceiros ao Visual Studio. Para obter informações gerais sobre Open Folder, confira [Desenvolver código no Visual Studio sem projetos nem soluções](/visualstudio/ide/develop-code-in-visual-studio-without-projects-or-solutions).

## <a name="cmake-and-qt"></a>CMake e QT

O CMake é integrado no IDE do Visual Studio como um componente da C++ carga de trabalho da área de trabalho. O fluxo de trabalho para CMake não é idêntico ao fluxo de trabalho descrito neste artigo. Se você estiver usando o CMake, consulte [projetos do cmake no Visual Studio](cmake-projects-in-visual-studio.md). Você também pode usar o CMake para criar projetos Qt ou pode usar a [extensão do Visual Studio Qt](https://download.qt.io/development_releases/vsaddin/) para o visual Studio 2015 ou o visual Studio 2017.

## <a name="other-build-systems"></a>Outros sistemas de compilação

Para usar o IDE do Visual Studio com um sistema de compilação ou conjunto de ferramentas de compilador que não tem suporte direto no menu principal, selecione **arquivo | Abrir | Pasta** ou pressione **Ctrl + Shift + Alt + O**. Navegue até a pasta que contém os arquivos de código-fonte. Para compilar o projeto, configurar o IntelliSense e definir parâmetros de depuração, você adiciona três arquivos JSON:

| | |
|-|-|
|CppProperties.json|Especifica informações de configuração personalizada para navegação. Crie esse arquivo, se necessário, na pasta raiz do projeto. (Não usado em projetos do CMake.)|
|tasks.vs.json|Especifique comandos de compilação personalizados. Acessados por meio do item de menu de contexto do **Gerenciador de Soluções**, **Configurar tarefas**.|
|launch.vs.json|Especifica argumentos de linha de comando para o depurador. Acessados por meio do item de menu de contexto do **Gerenciador de Soluções**, **Configurações de depuração e de inicialização**.|

## <a name="configure-code-navigation-with-cpppropertiesjson"></a>Configurar a navegação de código com CppProperties. JSON

Para o IntelliSense e o comportamento de navegação, como **ir para definição** para funcionar corretamente, o Visual Studio precisa saber qual compilador você está usando, onde os cabeçalhos do sistema são e onde os arquivos de inclusão adicionais estão localizados se não estiverem diretamente no pasta que você abriu (a pasta do espaço de trabalho). Para especificar uma configuração, você pode escolher **gerenciar configurações** na lista suspensa na barra de ferramentas principal:

![Gerenciar lista suspensa de configurações](media/manage-configurations-dropdown.png)

Atualmente, o Visual Studio oferece quatro configurações padrão, tudo para o C++ compilador da Microsoft:

![Configurações padrão](media/default-configurations.png)

Se, por exemplo, você escolher **x64-Debug**, o Visual Studio criará um arquivo chamado *CppProperties. JSON* na pasta do projeto raiz e o preencherá da seguinte forma:

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

Essa configuração "herda" as variáveis de ambiente do Prompt de Comando do Desenvolvedor do Visual Studio [x64](building-on-the-command-line.md). Uma dessas variáveis é `INCLUDE` e você pode consultá-la aqui usando a `${env.INCLUDE}` macro. A `includePath` propriedade informa ao Visual Studio onde procurar todas as fontes necessárias para o IntelliSense. Nesse caso, ele diz "examinar todos os diretórios especificados pela variável de ambiente INCLUDE e também todos os diretórios na árvore de pastas de trabalho atual". A `name` propriedade é o nome que aparecerá na lista suspensa e pode ser qualquer coisa que você desejar. A `defines` propriedade fornece dicas para o IntelliSense quando ele encontra blocos de compilação condicionais. A `intelliSenseMode` propriedade fornece algumas dicas adicionais com base no tipo de compilador. Várias opções estão disponíveis para MSVC, GCC e Clang.

## <a name="example-configuration-for-gcc"></a>Exemplo de configuração para GCC

Se você estiver usando um compilador diferente da Microsoft C++, precisará criar uma configuração e um ambiente personalizados no *CppProperties. JSON*. O exemplo a seguir mostra um arquivo *CppProperties. JSON* completo com uma única configuração personalizada para usar o gcc em uma instalação do MSYS2:

```json
{
  "configurations": [
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
          "TOOLSET_VERSION": "8.3.0",
          "PATH": "${env.MINGW64_ROOT}\\bin;${env.MINGW64_ROOT}\\..\\usr\\local\\bin;${env.MINGW64_ROOT}\\..\\usr\\bin;${env.MINGW64_ROOT}\\..\\bin;${env.PATH}",
          "INCLUDE": "${env.MINGW64_ROOT}\\include\\c++\\${env.TOOLSET_VERSION};${env.MINGW64_ROOT}\\include\\c++\\${env.TOOLSET_VERSION}\\tr1;${env.MINGW64_ROOT}\\include\\c++\\${env.TOOLSET_VERSION}\\${env.FLAVOR}",
          "environment": "mingw_64"
        }
      ]
   }
}
```

Observe o `environments` bloco. Ele define as propriedades que se comportam como variáveis de ambiente e estão disponíveis não apenas no arquivo *CppProperties. JSON* , mas também na tarefa outros arquivos de configuração *. vs. JSON* e *Launch. vs. JSON*. A `Mingw64` configuração herda o `mingw_w64` ambiente e usa sua `INCLUDE` propriedade para especificar o valor para `includePath`. Você pode adicionar outros caminhos a essa propriedade de matriz, conforme necessário. '

> [!WARNING]
> Atualmente, há um problema conhecido no qual o `INCLUDE` valor especificado em `environments` não é passado corretamente para a `includePath` propriedade. Você pode contornar o problema adicionando o literal completo incluir caminhos para a `includePath` matriz.

A `intelliSenseMode` propriedade é definida com um valor apropriado para gcc. Para obter mais informações sobre todas essas propriedades, consulte [CppProperties Schema Reference](cppproperties-schema-reference.md).

Quando tudo estiver funcionando corretamente, você verá o IntelliSense dos cabeçalhos GCC ao passar o mouse sobre um tipo:

![O GCC IntelliSense](media/gcc-intellisense.png)

## <a name="enable-intellisense-diagnostics"></a>Habilitar o diagnóstico do IntelliSense

Se você não estiver vendo o IntelliSense que espera, poderá solucionar problemas acessando **ferramentas** > **Opções** > **Editor** > de texto > **CC++/** **avançado** e configuração **habilitar registro em log** como **true**. Para começar, tente definir o **nível de log** para 5 e **registrar filtros em log** como 8.

![Diagnostic logging](media/diagnostic-logging.png)

A saída é canalizada para o **janela de saída** e fica visível quando você escolhe ** Mostrar saída de: C++ Log*do Visual. A saída contém, entre outras coisas, a lista de caminhos de inclusão reais que o IntelliSense está tentando usar. Se os caminhos não corresponderem àqueles em *CppProperties. JSON*, tente fechar a pasta e excluir a subpasta *. vs* que contém dados de navegação armazenados em cache.

### <a name="define-build-tasks-with-tasksvsjson"></a>Definir tarefas de build com tasks.vs.json

Você pode automatizar os scripts de compilação, ou quaisquer outras operações externas nos arquivos existentes em seu workspace atual, executando-os como tarefas diretamente no IDE. Você pode configurar uma nova tarefa clicando com o botão direito em um arquivo ou pasta e selecionando **Configurar Tarefas**.

![Configurar Tarefas do recurso Abrir Pasta](media/configure-tasks.png)

Isso cria (ou abre) o arquivo *Tasks. vs. JSON* na pasta. vs que o Visual Studio cria na pasta do projeto raiz. Defina qualquer tarefa arbitrária nesse arquivo e, em seguida, invoque-a no menu de contexto do **Gerenciador de Soluções**. Para continuar o exemplo de GCC, o trecho a seguir mostra um arquivo *Tasks. vs. JSON* completo com uma tarefa única que invoca o *g + +. exe* para compilar um projeto. Suponha que o projeto contenha um único arquivo chamado *Hello. cpp*.

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

O arquivo JSON é colocado na subpasta *. vs* , que você pode ver se clicar no botão **Mostrar todos os arquivos** na parte superior de **Gerenciador de soluções**. Você pode executar essa tarefa clicando com o botão direito do mouse no nó raiz em **Gerenciador de soluções** e escolhendo **criar Olá**. Quando a tarefa for concluída, você deverá ver um novo arquivo, *Olá. exe* em **Gerenciador de soluções**.

Você pode definir muitos tipos de tarefas. O exemplo a seguir mostra um *arquivo Tasks. vs. JSON* que define uma única tarefa. `taskLabel` define o nome exibido no menu de contexto. `appliesTo` define em quais arquivos o comando pode ser executado. A `command` Propriedade refere-se à variável de ambiente COMSPEC, que identifica o caminho para o console (*cmd. exe* no Windows). Referencie também variáveis de ambiente declaradas em CppProperties.json ou CMakeSettings.json. A propriedade `args` especifica a linha de comando a ser invocada. A macro `${file}` recupera o arquivo selecionado no **Gerenciador de Soluções**. O exemplo a seguir exibirá o nome do arquivo .cpp atualmente selecionado.

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

Depois de salvar *as tarefas. vs. JSON*, você pode clicar com o botão direito do mouse em qualquer arquivo *. cpp* na pasta, escolher **Echo filename** no menu de contexto e ver o nome do arquivo exibido na janela de saída.

Para obter mais informações, confira [Referência de esquema de Tasks.vs.json](tasks-vs-json-schema-reference-cpp.md).

### <a name="configure-debugging-parameters-with-launchvsjson"></a>Configurar parâmetros de depuração com launch.vs.json

Para personalizar os argumentos de linha de comando do programa e as instruções de depuração, clique com o botão direito do mouse no executável em **Gerenciador de soluções** e selecione **depurar e iniciar configurações**. Isso abrirá um arquivo de *inicialização existente. vs. JSON* ou, se não houver nenhum, ele criará um novo arquivo com um conjunto de configurações de inicialização mínima. Primeiro, você terá a opção de qual tipo de sessão de depuração deseja configurar. Para depurar um projeto MinGW-w64, escolhemos **C/C++ Launch for MinGGW/Cygwin (gdb)** . Isso cria uma configuração de inicialização para usar o *gdb. exe* com algumas palpites instruídos sobre valores padrão. Um desses valores padrão é `MINGW_PREFIX`. Você pode substituir o caminho literal (conforme mostrado abaixo) ou pode definir uma `MINGW_PREFIX` Propriedade em *CppProperties. JSON*:

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

Para iniciar a depuração, escolha o executável na lista suspensa depurar e clique na seta verde:

![Iniciar depurador](media/launch-debugger-gdb.png)

Você deve ver a caixa de diálogo inicializando o **depurador** e uma janela de console externa que está executando seu programa.

Para obter mais informações, consulte [Launch. vs. JSON Schema Reference](launch-vs-schema-reference-cpp.md).

## <a name="launching-other-executables"></a>Iniciando outros executáveis

Você pode definir configurações de inicialização para qualquer executável em seu computador. O exemplo a seguir inicia *7za* e especifica argumentos adicionais, adicionando-os à `args` matriz JSON:

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
