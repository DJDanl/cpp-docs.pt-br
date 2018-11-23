---
title: IDE e ferramentas para desenvolvimento do Visual C++
description: O IDE do Visual Studio é compatível com o desenvolvimento de C++ no Windows, Linux, Android e iOS com um editor de código, um depurador, estruturas de teste, analisadores estáticos e outras ferramentas de programação.
ms.date: 11/18/2018
helpviewer_keywords:
- Visual C++, development tools
ms.assetid: 56eabafb-1956-4f0f-bec5-29b887763559
ms.openlocfilehash: a5dd7f681d05d36215c4086165165122a05be23c
ms.sourcegitcommit: b032daf81cb5fdb1f5a988277ee30201441c4945
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 11/15/2018
ms.locfileid: "51693952"
---
# <a name="ide-and-compiler-tools-for-visual-c-development"></a>IDE e Ferramentas de Compilador para Desenvolvimento do Visual C++

Como parte do IDE (Ambiente de Desenvolvimento Integrado) do Visual Studio, o MSVC (Microsoft Visual C++) compartilha muitas janelas e ferramentas com outras linguagens. Muitas delas, incluindo o **Gerenciador de Soluções**, o editor de códigos e o depurador, estão documentadas no [IDE do Visual Studio](/visualstudio/ide/visual-studio-ide). Geralmente, uma ferramenta ou uma janela compartilhada tem um conjunto de recursos ligeiramente diferente para o C++ comparado às linguagens .NET ou JavaScript. Algumas janelas ou ferramentas só estão disponíveis no Visual Studio Professional ou nas edições do Visual Studio Enterprise.

Além das ferramentas compartilhadas no IDE do Visual Studio, o MSVC tem várias ferramentas especificamente para o desenvolvimento de código nativo. Essas ferramentas também são listadas neste artigo. Para obter uma lista de quais ferramentas estão disponíveis em cada edição do Visual Studio, confira [Ferramentas e funcionalidades do Visual C++ em edições do Visual Studio](visual-cpp-tools-and-features-in-visual-studio-editions.md).

## <a name="create-projects"></a>Criar projetos

Um *projeto* é basicamente um conjunto de arquivos de código-fonte e recursos, como imagens ou arquivos de dados que são compilados em um arquivo executável.

O Visual Studio 2015 dá suporte para projetos do MSBuild. Você pode baixar extensões do Visual Studio para outros sistemas de build, como Qt ou CMake.

O Visual Studio 2017 dá suporte a qualquer sistema de build ou ferramenta de build personalizada que você deseje usar, com suporte total para IntelliSense, navegação e depuração:

- O **MSBuild** é o sistema de build nativo para o Visual Studio. Ao selecionar **Arquivo** > **Novo** > **Projeto** no menu principal, serão exibidos vários tipos de *modelos de projeto* do MSBuild para você começar a desenvolver diferentes tipos de aplicativos em C++ rapidamente.

   ![Modelos de projeto](media/vs2017-new-project.png "Caixa de diálogo \"Novo projeto\" do Visual Studio 2017")

   Em geral, é necessário usar esses modelos para novos projetos, a menos que você tenha um motivo específico para usar o CMake ou outros sistemas de projeto. Alguns projetos têm um *assistente* que orienta você passo a passo ao longo do projeto de criação de um novo projeto. Para saber mais, confira [Criar e gerenciar projetos baseados no MSBuild](creating-and-managing-visual-cpp-projects.md).

- O **CMake** é um sistema de build multiplataforma integrado ao IDE do Visual Studio durante a instalação da carga de trabalho Desenvolvimento para desktop com C++. Para saber mais, veja [Projetos CMake no Visual C++](cmake-tools-for-visual-cpp.md).
- Há suporte para qualquer outro sistema de build do C++, incluindo uma coleção flexível de arquivos, por meio do recurso **Abrir Pasta**. Crie arquivos JSON simples para invocar o programa de build e configurar sessões de depuração. Para saber mais, veja [Projetos Abrir Pasta no Visual C++](non-msbuild-projects.md).

## <a name="add-to-source-control"></a>Adicionar ao controle do código-fonte

O controle do código-fonte permite coordenar o trabalho entre diversos desenvolvedores, isolar o trabalho em andamento do código de produção e fazer backup do código-fonte. O Visual Studio é compatível com o Git e o [TFVC \(Controle de Versão do Team Foundation\)](/azure/devops/repos/tfvc/) por meio da janela **Team Explorer**.

![Team Explorer](media/vs2017-team-explorer.png "Team Explorer do Visual Studio 2017")

Para saber mais sobre a integração do Git com repositórios no Azure, confira [Compartilhar código com o Visual Studio 2017 e o Git do Azure Repos](/azure/devops/repos/git/share-your-code-in-git-vs-2017). Para saber mais sobre a integração do Git com o GitHub, confira [Extensão do GitHub para Visual Studio](https://visualstudio.github.com/).

## <a name="create-user-interfaces-with-designers"></a>Criar interfaces do usuário com designers

Se o programa tiver uma interface do usuário, você poderá usar um designer para populá-lo rapidamente com controles como botões, caixas de listagem e assim por diante. Ao arrastar um controle da janela de ferramentas e soltá-lo na superfície de design, o Visual Studio gerará os recursos e o código necessários para fazer tudo funcionar. Em seguida, você escreverá o código para personalizar a aparência e o comportamento.

![Designer e Caixa de Ferramentas](media/vs2017-toolbox-designer.png "Designer e Caixa de Ferramentas do Visual Studio 2017")

Para obter mais informações sobre como criar uma interface do usuário para um aplicativo da Plataforma Universal do Windows, confira [Design e interface do usuário](https://developer.microsoft.com/windows/design).

Para obter mais informações sobre como criar uma interface do usuário para um aplicativo MFC, confira [Aplicativos da área de trabalho do MFC](../mfc/mfc-desktop-applications.md). Para obter informações sobre programas Windows Win32, confira [Aplicativos da área de trabalho do Windows](../windows/windows-desktop-applications-cpp.md).

## <a name="write-code"></a>Escrever código

Depois que você cria um projeto, todos os arquivos de projeto são exibidos na janela **Gerenciador de Soluções**. Uma *solução* é um contêiner lógico para um ou mais projetos relacionados. Quando você clica em um arquivo .h ou .cpp no **Gerenciador de Soluções**, o arquivo é aberto no editor de códigos.

![Gerenciador de Soluções e editor de código](media/vs2017-solution-explorer-code-editor.png "Gerenciador de Soluções e editor de código do Visual Studio 2017")

O editor de códigos é um processador de texto especializado para código-fonte C++. Ele codifica por cores os nomes de palavras-chave, de métodos e de variáveis da linguagem e outros elementos do código para tornar o código mais legível e mais fácil de ser entendido.

Para saber mais, confira [Escrever e refatorar código](writing-and-refactoring-code-cpp.md).

## <a name="add-and-edit-resources"></a>Adicionar e editar recursos

O termo *recurso* inclui itens como caixas de diálogo, ícones, imagens, cadeias de caracteres localizáveis, telas iniciais, cadeias de conexão de banco de dados ou dados arbitrários que você deseja incluir no arquivo executável.

Para obter mais informações sobre como adicionar e editar recursos em projetos do C++ da área de trabalho nativos, confira [Trabalhando com arquivos de recurso](../windows/working-with-resource-files.md).

## <a name="build-compile-and-link"></a>Build (compilar e vincular)

Escolha **Build** > **Compilar Solução** na barra de menus ou insira a combinação de teclas Ctrl+Shift+B para compilar e vincular um projeto. Os avisos e os erros de build são relatados na Lista de Erros (Ctrl+\\, E). A janela de **Saída** (Alt+2) mostra informações sobre o processo de build.

![Janela de Saída e Lista de Erros](media/vs2017-output-error-list.png "Janela de Saída e Lista de Erros do Visual Studio 2017") Para saber mais sobre as configurações do MSBuild, confira [Trabalhar com propriedades do projeto](working-with-project-properties.md) e [Compilar projetos do C++ no Visual Studio](building-cpp-projects-in-visual-studio.md).

Use também o compilador (cl.exe) e muitas outras ferramentas autônomas relacionadas a build, como NMAKE e LIB, diretamente na linha de comando. Para obter mais informações, confira [Compilar o código C/C++ na linha de comando](../build/building-on-the-command-line.md) e [Referência de build do C/C++](../build/reference/c-cpp-building-reference.md).

## <a name="debug"></a>Depurar

É possível iniciar a depuração pressionando **F5**. A execução pausa em qualquer ponto de interrupção que você tiver definido. Também é possível executar o código em etapas, exibir os valores de variáveis ou de registros especificados e, em alguns casos, até mesmo fazer alterações no código e continuar a depuração sem a recompilação. A ilustração a seguir mostra uma sessão de depuração em que a execução é pausada no ponto de interrupção. Os valores dos membros da estrutura de dados são visíveis na **janela Inspeção**.

![Sessão de depuração](media/vs2017-debug-watch.png "Sessão de depuração do Visual Studio 2017")

Para obter mais informações, consulte [Depuração no Visual Studio](/visualstudio/debugger/debugging-in-visual-studio).

## <a name="test"></a>Teste

O Visual Studio inclui estruturas de teste de unidade para o C++ nativo e o C++/CLI. Boost.Test, Google Test e CTest também são compatíveis. Execute os testes na janela do **Gerenciador de Testes**:

![Gerenciador de Testes](media/cpp-test-explorer-passed.png "Gerenciador de Testes do Visual Studio 2017")

Para saber mais, confira [Verificar código usando testes de unidade](/visualstudio/test/unit-test-your-code) e [Gravar testes de unidade para C/C++ no Visual Studio](/visualstudio/test/writing-unit-tests-for-c-cpp).

## <a name="analyze"></a>Analisar

O Visual Studio inclui ferramentas de análise de código estático que podem detectar possíveis problemas no código-fonte. Essas ferramentas incluem uma implementação dos verificadores de regras das [Diretrizes Principais do C++](https://github.com/isocpp/CppCoreGuidelines/blob/master/CppCoreGuidelines.md). Para obter mais informações, confira [Visão geral da análise de código do C/C++](/visualstudio/code-quality/code-analysis-for-c-cpp-overview).

## <a name="deploy-completed-applications"></a>Implantar aplicativos concluídos

É possível implantar os aplicativos tradicionais de área de trabalho e os aplicativos da UWP para os clientes por meio da Microsoft Store. A implantação do CRT é manipulada automaticamente em segundo plano. Para obter mais informações, confira [Publicar aplicativos e jogos do Windows](/windows/uwp/publish/).

Também é possível implantar uma área de trabalho nativa do C++ em outro computador. Para saber mais, confira [Implantar aplicativos da área de trabalho](deploying-native-desktop-applications-visual-cpp.md).

Para obter mais informações sobre como implantar um programa do C++/CLI, confira [Guia de Implantação para Desenvolvedores](/dotnet/framework/deployment/deployment-guide-for-developers).

## <a name="in-this-section"></a>Nesta seção

|||
|-|-|
|[Escrevendo e refatorando código (C++)](writing-and-refactoring-code-cpp.md)| Como usar o editor de código C++ para gravar, refatorar e navegar pelo seu código.|
|[Ferramentas e recursos do Visual C++ em edições do Visual Studio](visual-cpp-tools-and-features-in-visual-studio-editions.md)|Mostra quais funcionalidades estão disponíveis nas várias edições do Visual Studio.|
|[Projetos Abrir Pasta C++ no Visual Studio](non-msbuild-projects.md).|Descreve como usar qualquer sistema de build C++ arbitrário no Visual Studio.|
|[Projetos do CMake no Visual C++](cmake-tools-for-visual-cpp.md).|Descreve como compilar projetos do CMake no Visual Studio.|
|[Criando e gerenciando projetos baseados no MSBuild](creating-and-managing-visual-cpp-projects.md)|Fornece uma visão geral dos projetos baseados no MSBuild do C++ no Visual Studio e links para outros artigos que explicam como criá-los e gerenciá-los.|
|[Implantando aplicativos da área de trabalho](deploying-native-desktop-applications-visual-cpp.md)|Fornece uma visão geral da implantação de aplicativos do C++ e links para outros artigos que descrevem a implantação em detalhes.|
|[Adicionando funcionalidade com assistentes de código (C++)](adding-functionality-with-code-wizards-cpp.md)| Adicione classes, arquivos ou elementos da interface do usuário a um projeto usando os assistentes para guiá-lo.|
|[Documentação XML (Visual C++)](xml-documentation-visual-cpp.md)| Crie documentação XML para suas APIs.|
|[Compilando projetos do C++ no Visual Studio](building-cpp-projects-in-visual-studio.md)|Como usar o ambiente de desenvolvimento integrado do Visual Studio para compilar projetos.|

## <a name="related-articles"></a>Artigos relacionados

|||
|-|-|
|[Compilando programas do C/C++](../build/building-c-cpp-programs.md)|Informações detalhadas sobre a compilação de projetos C++.|
|[Guia de atualização e portabilidade do Visual C++](../porting/visual-cpp-porting-and-upgrading-guide.md)|Informações detalhadas sobre como atualizar aplicativos do C++ criados em versões anteriores do Visual Studio e também como migrar aplicativos criados com ferramentas que não incluem o Visual Studio.|
|[Visual C++](../visual-cpp-in-visual-studio.md)|Descreve as principais funcionalidades do Visual C++ no Visual Studio e fornece links para o restante da documentação do Visual C++.|
