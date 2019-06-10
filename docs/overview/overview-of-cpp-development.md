---
title: Visão geral do desenvolvimento em C++ no Visual Studio
description: O IDE do Visual Studio é compatível com o desenvolvimento de C++ no Windows, Linux, Android e iOS com um editor de código, um depurador, estruturas de teste, analisadores estáticos e outras ferramentas de programação.
ms.date: 03/08/2019
helpviewer_keywords:
- Visual C++, development tools
author: corob-msft
ms.author: corob
ms.openlocfilehash: 54ed590122f1eb914ff039378914a1fd4adc5f10
ms.sourcegitcommit: bde3279f70432f819018df74923a8bb895636f81
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/23/2019
ms.locfileid: "66182896"
---
# <a name="overview-of-c-development-in-visual-studio"></a>Visão geral do desenvolvimento em C++ no Visual Studio

Como parte do IDE (Ambiente de Desenvolvimento Integrado) do Visual Studio, o MSVC (Microsoft C++) compartilha muitas janelas e ferramentas com outras linguagens. Muitas delas, incluindo o **Gerenciador de Soluções**, o editor de códigos e o depurador, estão documentadas no [IDE do Visual Studio](/visualstudio/get-started/visual-studio-ide). Geralmente, uma ferramenta ou uma janela compartilhada tem um conjunto de recursos ligeiramente diferente para o C++ comparado a outra linguagens. Algumas janelas ou ferramentas só estão disponíveis no Visual Studio Professional ou nas edições do Visual Studio Enterprise.

Além das ferramentas compartilhadas no IDE do Visual Studio, o MSVC tem várias ferramentas especificamente para o desenvolvimento de código nativo. Essas ferramentas também são listadas neste artigo. Para obter uma lista de quais ferramentas estão disponíveis em cada edição do Visual Studio, confira [Ferramentas e recursos do C++ em edições do Visual Studio](visual-cpp-tools-and-features-in-visual-studio-editions.md).

## <a name="create-projects"></a>Criar projetos

Um *projeto* é basicamente um conjunto de arquivos de código-fonte e recursos, como imagens ou arquivos de dados que são compilados em um programa ou biblioteca executável.

O Visual Studio dá suporte a qualquer sistema de projeto ou ferramenta de build personalizada que você deseje usar, com suporte total para IntelliSense, navegação e depuração:

- O **MSBuild** é o sistema de projeto nativo para o Visual Studio. Ao selecionar **Arquivo** > **Novo** > **Projeto** no menu principal, serão exibidos vários tipos de *modelos de projeto* do MSBuild para você começar a desenvolver diferentes tipos de aplicativos em C++ rapidamente.

   ::: moniker range="vs-2019"

   ![Novos Modelos de Projeto](../build/media/mathclient-project-name-2019.png "Caixa de diálogo \"Novo projeto\" do Visual Studio 2019")

   ::: moniker-end

   ::: moniker range="<=vs-2017"

   ![Modelos de projeto](media/vs2017-new-project.png "Caixa de diálogo \"Novo projeto\" do Visual Studio 2017")

   ::: moniker-end

   Em geral, você deve usar esses modelos para novos projetos, a menos que esteja usando projetos CMake ou outro sistema de projeto. Para saber mais, confira [Criar e gerenciar projetos baseados no MSBuild](../build/creating-and-managing-visual-cpp-projects.md).

- O **CMake** é um sistema de build multiplataforma integrado ao IDE do Visual Studio durante a instalação da carga de trabalho Desenvolvimento para desktop com C++. É possível usar o modelo de projeto CMake para novos projetos ou simplesmente abrir uma pasta com um arquivo CMakeLists.txt. Para saber mais, confira [Projetos CMake no Visual Studio](../build/cmake-projects-in-visual-studio.md).

- Há suporte para qualquer outro sistema de build do C++, incluindo uma coleção flexível de arquivos, por meio do recurso **Abrir Pasta**. Crie arquivos JSON simples para invocar o programa de build e configurar sessões de depuração. Para saber mais, veja [Projetos Open Folder para C++](../build/open-folder-projects-cpp.md).

## <a name="add-to-source-control"></a>Adicionar ao controle do código-fonte

O controle do código-fonte permite coordenar o trabalho entre diversos desenvolvedores, isolar o trabalho em andamento do código de produção e fazer backup do código-fonte. O Visual Studio é compatível com o Git e o [TFVC \(Controle de Versão do Team Foundation\)](/azure/devops/repos/tfvc/) por meio da janela **Team Explorer**. 

::: moniker range="vs-2019"

![Team Explorer](media/vs2019-team-explorer.png "Team Explorer do Visual Studio 2017")

::: moniker-end

::: moniker range="<=vs-2017"

![Team Explorer](media/vs2017-team-explorer.png "Team Explorer do Visual Studio 2017")

::: moniker-end

Para saber mais sobre a integração do Git com repositórios no Azure, confira [Compartilhar código com o Visual Studio 2017 e o Git do Azure Repos](/azure/devops/repos/git/share-your-code-in-git-vs-2017). Para saber mais sobre a integração do Git com o GitHub, confira [Extensão do GitHub para Visual Studio](https://visualstudio.github.com/).

## <a name="obtain-libraries"></a>Obter bibliotecas

Use o gerenciador de pacotes [vcpkg](../build/vcpkg.md) para obter e instalar bibliotecas de terceiros. No momento, mais de 900 bibliotecas open-source estão disponíveis no catálogo.

## <a name="create-user-interfaces-with-designers"></a>Criar interfaces do usuário com designers

Se o programa tiver uma interface do usuário, você poderá usar um designer para populá-lo rapidamente com controles como botões, caixas de listagem e assim por diante. Ao arrastar um controle da janela de ferramentas e soltá-lo na superfície de design, o Visual Studio gerará os recursos e o código necessários para fazer tudo funcionar. Em seguida, você escreverá o código para personalizar a aparência e o comportamento.

![Designer e Caixa de Ferramentas](media/vs2017-toolbox-designer.png "Designer e Caixa de Ferramentas do Visual Studio 2017")

Para obter mais informações sobre como criar uma interface do usuário para um aplicativo da Plataforma Universal do Windows, confira [Design e interface do usuário](https://developer.microsoft.com/windows/design).

Para obter mais informações sobre como criar uma interface do usuário para um aplicativo MFC, confira [Aplicativos da área de trabalho do MFC](../mfc/mfc-desktop-applications.md). Para obter informações sobre programas Windows Win32, confira [Aplicativos da área de trabalho do Windows](../windows/windows-desktop-applications-cpp.md).

## <a name="write-code"></a>Escrever código

Depois que você cria um projeto, todos os arquivos de projeto são exibidos na janela **Gerenciador de Soluções**. Uma *solução* é um contêiner lógico para um ou mais projetos relacionados. Quando você clica em um arquivo .h ou .cpp no **Gerenciador de Soluções**, o arquivo é aberto no editor de códigos.

![Gerenciador de Soluções e editor de código](media/vs2017-solution-explorer-code-editor.png "Gerenciador de Soluções e editor de código do Visual Studio 2017")

O editor de códigos é um processador de texto especializado para código-fonte C++. Ele codifica por cores os nomes de palavras-chave, de métodos e de variáveis da linguagem e outros elementos do código para tornar o código mais legível e mais fácil de ser entendido. Ele também fornece ferramentas para refatoração de código, navegação entre diferentes arquivos e noções básicas sobre como o código é estruturado. Para saber mais, confira [Escrever e refatorar código](../ide/writing-and-refactoring-code-cpp.md).

## <a name="add-and-edit-resources"></a>Adicionar e editar recursos

O termo *recurso* inclui itens como caixas de diálogo, ícones, imagens, cadeias de caracteres localizáveis, telas iniciais, cadeias de conexão de banco de dados ou dados arbitrários que você deseja incluir no arquivo executável.

Para obter mais informações sobre como adicionar e editar recursos em projetos do C++ da área de trabalho nativos, confira [Trabalhando com arquivos de recurso](../windows/working-with-resource-files.md).

## <a name="build-compile-and-link"></a>Build (compilar e vincular)

Escolha **Build** > **Compilar Solução** na barra de menus ou insira a combinação de teclas Ctrl+Shift+B para compilar e vincular um projeto. Os avisos e os erros de build são relatados na Lista de Erros (Ctrl+\\, E). A janela de **Saída** (Alt+2) mostra informações sobre o processo de build.

![Lista de Erros e Janela de Saída](media/vs2017-output-error-list.png "Janela de Saída e Lista de Erros do Visual Studio 2017")

Para saber mais sobre como configurar builds, confira [Como trabalhar com Propriedades de Projeto](../build/working-with-project-properties.md) e [Projetos e sistemas de build](../build/projects-and-build-systems-cpp.md).

Use também o compilador (cl.exe) e muitas outras ferramentas autônomas relacionadas a build, como NMAKE e LIB, diretamente na linha de comando. Para obter mais informações, confira [Compilar o código C/C++ na linha de comando](../build/building-on-the-command-line.md) e [Referência de build do C/C++](../build/reference/c-cpp-building-reference.md).

## <a name="debug"></a>Depurar

É possível iniciar a depuração pressionando **F5**. A execução pausa em qualquer ponto de interrupção que você tiver definido. Também é possível executar o código em etapas, exibir os valores de variáveis ou de registros especificados e, em alguns casos, até mesmo fazer alterações no código e continuar a depuração sem a recompilação. A ilustração a seguir mostra uma sessão de depuração em que a execução é pausada no ponto de interrupção. Os valores dos membros da estrutura de dados são visíveis na **janela Inspeção**.

![Sessão de depuração](media/vs2017-debug-watch.png "Sessão de depuração do Visual Studio 2017")

Para obter mais informações, consulte [Depuração no Visual Studio](/visualstudio/debugger/debugging-in-visual-studio).

## <a name="test"></a>Teste

O Visual Studio inclui o Microsoft Unit Test Framework para C++, além de suporte para Boost.Test, Google Test e CTest. Execute os testes na janela do **Gerenciador de Testes**:

![Gerenciador de Testes](media/cpp-test-explorer-passed.png "Gerenciador de Testes do Visual Studio 2017")

Para saber mais, confira [Verificar código usando testes de unidade](/visualstudio/test/unit-test-your-code) e [Gravar testes de unidade para C/C++ no Visual Studio](/visualstudio/test/writing-unit-tests-for-c-cpp).

## <a name="analyze"></a>Analisar

O Visual Studio inclui ferramentas de análise de código estático que podem detectar possíveis problemas no código-fonte. Essas ferramentas incluem uma implementação dos verificadores de regras das [Diretrizes Principais do C++](https://github.com/isocpp/CppCoreGuidelines/blob/master/CppCoreGuidelines.md). Para obter mais informações, confira [Visão geral da análise de código do C/C++](/visualstudio/code-quality/code-analysis-for-c-cpp-overview).

## <a name="deploy-completed-applications"></a>Implantar aplicativos concluídos

É possível implantar os aplicativos tradicionais de área de trabalho e os aplicativos da UWP para os clientes por meio da Microsoft Store. A implantação do CRT é manipulada automaticamente em segundo plano. Para obter mais informações, confira [Publicar aplicativos e jogos do Windows](/windows/uwp/publish/).

Também é possível implantar uma área de trabalho nativa do C++ em outro computador. Para saber mais, confira [Implantar aplicativos da área de trabalho](../windows/deploying-native-desktop-applications-visual-cpp.md).

Para obter mais informações sobre como implantar um programa do C++/CLI, confira [Guia de Implantação para Desenvolvedores](/dotnet/framework/deployment/deployment-guide-for-developers).

## <a name="next-steps"></a>Próximas etapas

Explore ainda mais o Visual Studio seguindo um dos seguintes artigos introdutórios:

> [!div class="nextstepaction"]
> [Saiba como usar o editor de códigos](/visualstudio/get-started/tutorial-editor)

> [!div class="nextstepaction"]
> [Saiba mais sobre projetos e soluções](/visualstudio/get-started/tutorial-projects-solutions)
