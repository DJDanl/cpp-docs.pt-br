---
title: Visão geral do desenvolvimento em C++ no Visual Studio
description: O IDE do Visual Studio é compatível com o desenvolvimento de C++ no Windows, Linux, Android e iOS com um editor de código, um depurador, estruturas de teste, analisadores estáticos e outras ferramentas de programação.
ms.date: 12/02/2019
helpviewer_keywords:
- Visual C++, development tools
author: corob-msft
ms.author: corob
ms.openlocfilehash: 4e04e189b44fe61759a9422139d856ab8a09f201
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "77415704"
---
# <a name="overview-of-c-development-in-visual-studio"></a>Visão geral do desenvolvimento em C++ no Visual Studio

Como parte do IDE (Ambiente de Desenvolvimento Integrado) do Visual Studio, o MSVC (Microsoft C++) compartilha muitas janelas e ferramentas com outras linguagens. Muitas delas, incluindo o **Gerenciador de Soluções**, o editor de códigos e o depurador, estão documentadas no [IDE do Visual Studio](/visualstudio/get-started/visual-studio-ide). Geralmente, uma ferramenta ou uma janela compartilhada tem um conjunto de recursos ligeiramente diferente para o C++ comparado a outra linguagens. Algumas janelas ou ferramentas só estão disponíveis no Visual Studio Professional ou nas edições do Visual Studio Enterprise.

Além das ferramentas compartilhadas no IDE do Visual Studio, o MSVC tem várias ferramentas especificamente para o desenvolvimento de código nativo. Essas ferramentas também são listadas neste artigo. Para obter uma lista de quais ferramentas estão disponíveis em cada edição do Visual Studio, confira [Ferramentas e recursos do C++ em edições do Visual Studio](visual-cpp-tools-and-features-in-visual-studio-editions.md).

## <a name="create-projects"></a>Criar projetos

Um *projeto* é basicamente um conjunto de arquivos de código-fonte e recursos, como imagens ou arquivos de dados que são compilados em um programa ou biblioteca executável.

O Visual Studio dá suporte a qualquer sistema de projeto ou ferramenta de build personalizada que você deseje usar, com suporte total para IntelliSense, navegação e depuração:

- O **MSBuild** é o sistema de projeto nativo para o Visual Studio. Quando você seleciona O**Novo** > **Projeto** de **Arquivo** > no menu principal, você vê muitos tipos de *modelos* de projeto MSBuild que fazem você começar a desenvolver rapidamente diferentes tipos de aplicativos C++.

   ::: moniker range="vs-2019"

   ![Novos modelos de projeto](../build/media/mathclient-project-name-2019.png "Visual Studio 2019 Novo Projeto Diálogo")

   ::: moniker-end

   ::: moniker range="<=vs-2017"

   ![Modelos de projeto](media/vs2017-new-project.png "Visual Studio 2017 Novo Projeto Diálogo")

   ::: moniker-end

   Em geral, você deve usar esses modelos para novos projetos, a menos que esteja usando projetos CMake ou outro sistema de projeto. Para saber mais, confira [Criar e gerenciar projetos baseados no MSBuild](../build/creating-and-managing-visual-cpp-projects.md).

- **CMake** é um sistema de compilação multiplataforma que é integrado ao Visual Studio IDE quando você instala o desenvolvimento de Desktop com carga de trabalho C++. É possível usar o modelo de projeto CMake para novos projetos ou simplesmente abrir uma pasta com um arquivo CMakeLists.txt. Para saber mais, confira [Projetos CMake no Visual Studio](../build/cmake-projects-in-visual-studio.md).

- Qualquer outro sistema de compilação C++, incluindo uma coleção solta de arquivos, é suportado através do recurso **Open Folder.** Crie arquivos JSON simples para invocar o programa de build e configurar sessões de depuração. Para saber mais, veja [Projetos Open Folder para C++](../build/open-folder-projects-cpp.md).

## <a name="add-to-source-control"></a>Adicionar ao controle do código-fonte

O controle do código-fonte permite coordenar o trabalho entre diversos desenvolvedores, isolar o trabalho em andamento do código de produção e fazer backup do código-fonte. O Visual Studio é compatível com o Git e o [TFVC \(Controle de Versão do Team Foundation\)](/azure/devops/repos/tfvc/) por meio da janela **Team Explorer**.

::: moniker range="vs-2019"

![Explorador de Equipe](media/vs2019-team-explorer.png "Visual Studio 2017 Team Explorer")

::: moniker-end

::: moniker range="<=vs-2017"

![Explorador de Equipe](media/vs2017-team-explorer.png "Visual Studio 2017 Team Explorer")

::: moniker-end

Para saber mais sobre a integração do Git com repositórios no Azure, confira [Compartilhar código com o Visual Studio 2017 e o Git do Azure Repos](/azure/devops/repos/git/share-your-code-in-git-vs-2017). Para saber mais sobre a integração do Git com o GitHub, confira [Extensão do GitHub para Visual Studio](https://visualstudio.github.com/).

## <a name="obtain-libraries"></a>Obter bibliotecas

Use o gerenciador de pacotes [vcpkg](../build/vcpkg.md) para obter e instalar bibliotecas de terceiros. No momento, mais de 900 bibliotecas open-source estão disponíveis no catálogo.

## <a name="create-user-interfaces-with-designers"></a>Criar interfaces do usuário com designers

Se o programa tiver uma interface do usuário, você poderá usar um designer para populá-lo rapidamente com controles como botões, caixas de listagem e assim por diante. Ao arrastar um controle da janela de ferramentas e soltá-lo na superfície de design, o Visual Studio gerará os recursos e o código necessários para fazer tudo funcionar. Em seguida, você escreverá o código para personalizar a aparência e o comportamento.

![Designer e Caixa de Ferramentas](media/vs2017-toolbox-designer.png "Visual Studio 2017 Toolbox e designer")

Para obter mais informações sobre como projetar uma interface de usuário para um aplicativo universal da Plataforma Windows, consulte [Design e Interface do Usuário](https://developer.microsoft.com/windows/design).

Para obter mais informações sobre como criar uma interface do usuário para um aplicativo MFC, confira [Aplicativos da área de trabalho do MFC](../mfc/mfc-desktop-applications.md). Para obter informações sobre programas Windows Win32, confira [Aplicativos da área de trabalho do Windows](../windows/windows-desktop-applications-cpp.md).

## <a name="write-code"></a>Escrever código

Depois que você cria um projeto, todos os arquivos de projeto são exibidos na janela **Gerenciador de Soluções**. (Uma *solução* é um recipiente lógico para um ou mais projetos relacionados.) Quando você clica em um arquivo .h ou .cpp no **Solution Explorer,** o arquivo é aberto no editor de código.

![Explorador de soluções e editor de código](media/vs2017-solution-explorer-code-editor.png "Visual Studio 2017 Solution Explorer e editor de código")

O editor de códigos é um processador de texto especializado para código-fonte C++. Ele codifica por cores os nomes de palavras-chave, de métodos e de variáveis da linguagem e outros elementos do código para tornar o código mais legível e mais fácil de ser entendido. Ele também fornece ferramentas para refatoração de código, navegação entre diferentes arquivos e noções básicas sobre como o código é estruturado. Para saber mais, confira [Escrever e refatorar código](../ide/writing-and-refactoring-code-cpp.md).

## <a name="add-and-edit-resources"></a>Adicionar e editar recursos

Um programa do Windows ou DLL geralmente inclui alguns *recursos,* como diálogos, ícones, imagens, strings localizáveis, telas de respingo, strings de conexão de banco de dados ou quaisquer dados arbitrários. O Visual Studio inclui ferramentas para adicionar e editar recursos. Para obter mais informações, consulte [Trabalhando com arquivos de recursos](../windows/working-with-resource-files.md).

## <a name="build-compile-and-link"></a>Build (compilar e vincular)

Escolha **Criar** > **solução de construção** na barra de menu ou digite a combinação de teclas **Ctrl+Shift+B** para compilar e vincular um projeto. Erros de compilação e avisos são relatados na Lista de Erros (**Ctrl+\\, E**). A **janela de saída** **(Alt+2**) mostra informações sobre o processo de compilação.

![Janela de saída e lista de erros](media/vs2017-output-error-list.png "Janela de saída do Visual Studio 2017 e lista de erros")

Para saber mais sobre como configurar builds, confira [Como trabalhar com Propriedades de Projeto](../build/working-with-project-properties.md) e [Projetos e sistemas de build](../build/projects-and-build-systems-cpp.md).

Use também o compilador (cl.exe) e muitas outras ferramentas autônomas relacionadas a build, como NMAKE e LIB, diretamente na linha de comando. Para obter mais informações, confira [Compilar o código C/C++ na linha de comando](../build/building-on-the-command-line.md) e [Referência de build do C/C++](../build/reference/c-cpp-building-reference.md).

## <a name="debug"></a>Depurar

É possível iniciar a depuração pressionando **F5**. A execução faz pausas em qualquer ponto de interrupção que você tenha definido (pressionando **F9**). Você também pode passar pelo código uma linha de cada vez **(F10),** visualizar os valores das variáveis ou registros, e mesmo em alguns casos fazer alterações no código e continuar depurando sem recompilação. A ilustração a seguir mostra uma sessão de depuração em que a execução é pausada no ponto de interrupção. Os valores dos membros da estrutura de dados são visíveis na **janela Inspeção**.

![Sessão de depuração](media/vs2017-debug-watch.png "Sessão de depuração do Visual Studio 2017")

Para obter mais informações, consulte [Depuração no Visual Studio](/visualstudio/debugger/debugging-in-visual-studio).

## <a name="test"></a>Teste

O Visual Studio inclui o Microsoft Unit Test Framework para C++, além de suporte para Boost.Test, Google Test e CTest. Execute os testes na janela do **Gerenciador de Testes**:

![Gerenciador de Testes](media/cpp-test-explorer-passed.png "Visual Studio 2017 Test Explorer")

Para saber mais, confira [Verificar código usando testes de unidade](/visualstudio/test/unit-test-your-code) e [Gravar testes de unidade para C/C++ no Visual Studio](/visualstudio/test/writing-unit-tests-for-c-cpp).

## <a name="analyze"></a>Analisar

O Visual Studio inclui ferramentas de análise de código estático que podem detectar possíveis problemas no código-fonte. Essas ferramentas incluem uma implementação dos verificadores de regras das [Diretrizes Principais do C++](https://github.com/isocpp/CppCoreGuidelines/blob/master/CppCoreGuidelines.md). Para obter mais informações, confira [Visão geral da análise de código do C/C++](/cpp/code-quality/code-analysis-for-c-cpp-overview).

## <a name="deploy-completed-applications"></a>Implantar aplicativos concluídos

É possível implantar os aplicativos tradicionais de área de trabalho e os aplicativos da UWP para os clientes por meio da Microsoft Store. A implantação do CRT é manipulada automaticamente em segundo plano. Para obter mais informações, confira [Publicar aplicativos e jogos do Windows](/windows/uwp/publish/).

Você também pode implantar uma área de trabalho C++ nativa em outro computador. Para obter mais informações, confira [Implantando aplicativos da área de trabalho](../windows/deploying-native-desktop-applications-visual-cpp.md).

Para obter mais informações sobre como implantar um programa do C++/CLI, confira [Guia de Implantação para Desenvolvedores](/dotnet/framework/deployment/deployment-guide-for-developers).

## <a name="next-steps"></a>Próximas etapas

Explore ainda mais o Visual Studio seguindo um dos seguintes artigos introdutórios:

> [!div class="nextstepaction"]
> [Saiba como usar o editor de códigos](/visualstudio/get-started/tutorial-editor)

> [!div class="nextstepaction"]
> [Saiba mais sobre projetos e soluções](/visualstudio/get-started/tutorial-projects-solutions)
