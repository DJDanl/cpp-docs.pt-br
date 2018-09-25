---
title: IDE e ferramentas para desenvolvimento do Visual C++ | Microsoft Docs
ms.custom: ''
ms.date: 06/02/2018
ms.technology:
- cpp-ide
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- Visual C++, development tools
ms.assetid: 56eabafb-1956-4f0f-bec5-29b887763559
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: d4e7742afd3fecc4dd115624da0c1650dc662004
ms.sourcegitcommit: 799f9b976623a375203ad8b2ad5147bd6a2212f0
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/19/2018
ms.locfileid: "46412516"
---
# <a name="ide-and-tools-for-visual-c-development"></a>IDE e ferramentas para desenvolvimento do Visual C++

Como parte do IDE (Ambiente de Desenvolvimento Integrado) do Visual Studio, o MSVC (Microsoft Visual C++) compartilha muitas janelas e ferramentas com outras linguagens. Muitas delas, incluindo o **Gerenciador de Soluções**, o editor de códigos e o depurador, estão documentadas no [IDE do Visual Studio](/visualstudio/ide/visual-studio-ide). Geralmente, uma ferramenta ou uma janela compartilhada tem um conjunto de funcionalidades ligeiramente diferente para o C++ comparado às linguagens .NET ou JavaScript. Algumas janelas ou ferramentas só estão disponíveis no Visual Studio Pro ou no Visual Studio Enterprise.

Além das ferramentas compartilhadas no IDE do Visual Studio, o MSVC tem várias ferramentas especificamente para o desenvolvimento de código nativo. Essas ferramentas também são listadas neste artigo. Para obter uma lista de quais ferramentas estão disponíveis em cada edição do Visual Studio, confira [Ferramentas e funcionalidades do Visual C++ em edições do Visual Studio](../ide/visual-cpp-tools-and-features-in-visual-studio-editions.md).

## <a name="creating-a-solution-and-projects"></a>Criando uma solução e projetos

Um *projeto* é basicamente um conjunto de arquivos de código-fonte e recursos, como imagens ou arquivos de dados que são compilados em um arquivo executável.

O Visual Studio 2015 dá suporte para projetos do MSBuild. Você pode baixar extensões do Visual Studio para outros sistemas de build, como Qt ou CMake.

O Visual Studio 2017 dá suporte a qualquer sistema de build ou ferramenta de build personalizada que você deseje usar, com suporte total para IntelliSense, navegação e depuração:

- O MSBuild é o sistema de build nativo do Visual Studio e, geralmente, é a melhor escolha para aplicativos UWP (Plataforma Universal do Windows) ou aplicativos herdados da área de trabalho do Windows que usam o MFC ou a ATL. Para obter mais informações sobre projetos do C++ baseados no MSBuild, confira [Criando e gerenciando projetos baseados no MSBuild](creating-and-managing-visual-cpp-projects.md).
- O CMake é um sistema de build multiplataforma integrado ao IDE do Visual Studio durante a instalação da carga de trabalho Desenvolvimento para desktop com C++. Para saber mais, veja [Projetos CMake no Visual C++](cmake-tools-for-visual-cpp.md).
- Há suporte para qualquer outro sistema de build do C++, incluindo uma coleção flexível de arquivos, por meio do recurso Abrir Pasta. Crie arquivos JSON simples para invocar o programa de build e configurar sessões de depuração. Para obter mais informações, confira [Trazer seu código C++ para o Visual Studio](https://blogs.msdn.microsoft.com/vcblog/2017/04/14/bring-your-cpp-code-to-visual-studio/).

### <a name="project-templates-msbuild"></a>Modelos de projeto (MSBuild)

O Visual Studio é fornecido com vários modelos para projetos baseados no MSBuild; esses modelos contêm um código inicial e as configurações necessárias para uma variedade de tipos de programa básicos. Normalmente, você começa escolhendo **Arquivo** > **Novo Projeto** para criar um projeto com base em um modelo de projeto e, em seguida, adiciona novos arquivos de código-fonte ao projeto ou inicia a codificação nos arquivos fornecidos. Para obter informações específicas a projetos do C++ e a assistentes de projeto, confira [Criando e gerenciando projetos do Visual C++](../ide/creating-and-managing-visual-cpp-projects.md).

### <a name="application-wizards-msbuild"></a>Assistentes de aplicativo (MSBuild)

O Visual Studio fornece assistentes para alguns tipos de projeto do MSBuild quando você escolhe **Arquivo** > **Novo Projeto**. Um assistente orientará você passo a passo pelo processo de criação de um projeto. Isso é útil para tipos de projeto que têm muitas opções e configurações. Para obter mais informações, confira [Criando projetos de área de trabalho usando assistentes de aplicativo](../ide/creating-desktop-projects-by-using-application-wizards.md).

## <a name="creating-user-interfaces-with-designers-msbuild"></a>Criando interfaces do usuário com designers (MSBuild)

Se o programa tem uma interface do usuário, uma das primeiras tarefas é populá-lo com controles como botões, caixas de listagem e assim por diante. O Visual Studio inclui uma área de design visual e uma caixa de ferramentas para cada tipo de aplicativo do C++. Não importa qual tipo de aplicativo você está criando. A ideia básica é a mesma: você arrasta um controle da janela da caixa de ferramentas e solta-o na área de design no local desejado. Em segundo plano, o Visual Studio gera os recursos e o código necessários para que tudo funcione. Em seguida, você escreve o código para popular os controles com os dados ou personalizar a aparência e o comportamento.

Para obter mais informações sobre como criar uma interface do usuário para um aplicativo da Plataforma Universal do Windows, confira [Design e interface do usuário](https://developer.microsoft.com/en-us/windows/design).

Para obter mais informações sobre como criar uma interface do usuário para um aplicativo MFC, confira [Aplicativos da área de trabalho do MFC](../mfc/mfc-desktop-applications.md). Para obter informações sobre programas Windows Win32, confira [Aplicativos da área de trabalho do Windows](../windows/windows-desktop-applications-cpp.md).

## <a name="writing-and-editing-code"></a>Escrevendo e editando o código

### <a name="semantic-colorization"></a>Colorização semântica

Depois que você cria um projeto, todos os arquivos de projeto são exibidos na janela **Gerenciador de Soluções**. Quando você clica em um arquivo .h ou .cpp no **Gerenciador de Soluções**, o arquivo é aberto no editor de códigos. O editor de códigos é um processador de texto especializado para código-fonte C++. Ele codifica por cores os nomes de palavras-chave, de métodos e de variáveis da linguagem e outros elementos do código para tornar o código mais legível e mais fácil de ser entendido.

### <a name="intellisense"></a>IntelliSense

O editor de códigos também dá suporte a várias funcionalidades que, juntas, são conhecidas como IntelliSense. Focalize um método e veja a documentação básica sobre ele. Depois que você digita um nome de variável de classe e um . ou ->, uma lista de membros de instância dessa classe é exibida. Se você digita um nome de classe e, em seguida, um ::, uma lista de membros estáticos é exibida. Quando você começa a digitar um nome de classe ou de método, o editor de códigos oferece sugestões para completar a instrução. Para obter mais informações, veja [Usando o IntelliSense](/visualstudio/ide/using-intellisense).

### <a name="code-snippets"></a>Snippets de código

Use os snippets de código do IntelliSense para gerar constructos de código geralmente usados ou complicados com um pressionamento de tecla de atalho. Para obter mais informações, consulte [Snippets de Código](/visualstudio/ide/code-snippets).

## <a name="navigating-code"></a>Navegando pelo código

O menu **Exibir** fornece acesso a várias janelas e ferramentas para navegar pelos arquivos de código. Para obter informações detalhadas sobre essas janelas, confira [Exibindo a estrutura do código](/visualstudio/ide/viewing-the-structure-of-code).

### <a name="solution-explorer"></a>Gerenciador de Soluções

Em todas as edições do Visual Studio, use o painel do **Gerenciador de Soluções** para navegar entre os arquivos de um projeto. Expanda um ícone de arquivo .h ou .cpp para exibir as classes do arquivo. Expanda uma classe para ver seus membros. Clique duas vezes em um membro para navegar para sua definição ou implementação no arquivo.

### <a name="class-view-and-code-definition-window"></a>Modo de Exibição de Classe e Janela de Definição de Código

Use o painel **Modo de Exibição de Classe** para ver namespaces e classes em todos os arquivos, incluindo classes parciais. Expanda cada namespace ou classe para ver seus membros e clique duas vezes no membro para navegar para o local no arquivo de origem. Se você abrir a **Janela de Definição de Código**, poderá exibir a definição ou a implementação do tipo ao escolhê-la em **Modo de Exibição de Classe**.

### <a name="object-browser"></a>Pesquisador de Objetos

Use o **Pesquisador de Objetos** para explorar as informações de tipo em componentes do Tempo de Execução do Windows (arquivos .winmd), assemblies .NET e bibliotecas de tipos COM. Ele não é usado com DLLs do Win32.

### <a name="go-to-definitiondeclaration"></a>Ir para definição/declaração

Pressione F12 em qualquer nome de API ou variável de membro para ir para sua definição. Se a definição estiver em um arquivo .winmd (para um aplicativo UWP ou da Windows 8.x Store), você verá as informações de tipo no Pesquisador de Objetos. Escolha também **Ir para definição** ou **Ir para declaração** clicando com o botão direito do mouse no nome da variável ou do tipo e escolhendo a opção no menu de contexto.

### <a name="find-all-references"></a>Localizar Todas as Referências

Em um arquivo de código-fonte, clique com o botão direito do mouse com o cursor no nome de um tipo, de um método ou de uma variável e escolha **Localizar todas as Referências** para retornar uma lista de todos os locais no arquivo, no projeto ou na solução em que o tipo é usado. A opção **Localizar Todas as Referências** é inteligente e retorna apenas as instâncias da mesma variável idêntica, mesmo que outras variáveis em um escopo diferente tenham o mesmo nome.

## <a name="add-and-edit-resources--msbuild"></a>Adicionar e editar recursos (MSBuild)

O termo *recurso* no contexto de um projeto de área de trabalho do Visual Studio inclui itens como caixas de diálogo, ícones, cadeias de caracteres localizáveis, telas iniciais, cadeias de conexão de banco de dados ou dados arbitrários que você deseja incluir no arquivo executável.

Para obter mais informações sobre como adicionar e editar recursos em projetos do C++ da área de trabalho nativos, confira [Trabalhando com arquivos de recurso](../windows/working-with-resource-files.md).

## <a name="build-compile-and-link"></a>Build (compilar e vincular)

Escolha **Build** > **Compilar Solução** na barra de menus ou insira a combinação de teclas Ctrl+Shift+B para compilar e vincular um projeto. Para criar um código executável, o Visual Studio usa o [MSBuild](/visualstudio/msbuild/msbuild1), o CMake ou qualquer ambiente de build configurado por meio do recurso **Abrir Pasta**. Para projetos do MSBuild, defina as opções gerais de build em **Ferramentas** > **Opções** > **Projetos e Soluções** e defina as propriedades para projetos específicos em **Projeto** > **Propriedades**. Os avisos e os erros de build são relatados na Lista de Erros (Ctrl+\\, E). Os projetos não MSBuild são configurados com os arquivos JSON criados no Gerenciador de Soluções. Seja qual for o sistema de build usado, a janela de **Saída** (Alt+2) mostra informações sobre o processo de build. Para obter mais informações sobre as configurações do MSBuild, confira [Trabalhando com propriedades do projeto](../ide/working-with-project-properties.md) e [Compilando projetos do C++ no Visual Studio](../ide/building-cpp-projects-in-visual-studio.md).

Use também o compilador (cl.exe) e muitas outras ferramentas autônomas relacionadas a build, como NMAKE e LIB, diretamente na linha de comando. Para obter mais informações, confira [Compilar o código C/C++ na linha de comando](../build/building-on-the-command-line.md) e [Referência de build do C/C++](../build/reference/c-cpp-building-reference.md).

## <a name="test"></a>Teste

O Visual Studio inclui uma estrutura de teste de unidade para o C++ nativo e o C++/CLI. Para obter mais informações, confira [Verificando o código usando testes de unidade](/visualstudio/test/unit-test-your-code) e [Escrevendo teste de unidade para o C/C++ com o Microsoft Unit Testing Framework para C++](/visualstudio/test/writing-unit-tests-for-c-cpp-with-the-microsoft-unit-testing-framework-for-cpp)

## <a name="analyze"></a>Analisar

O Visual Studio inclui ferramentas de análise estática de código para C++, incluindo uma implementação dos verificadores de regras [Diretrizes Principais do C++](https://github.com/isocpp/CppCoreGuidelines/blob/master/CppCoreGuidelines.md). Para obter mais informações, confira [Visão geral da análise de código do C/C++](/visualstudio/code-quality/code-analysis-for-c-cpp-overview).

## <a name="debug"></a>Depurar

Depure o programa pressionando **F5** quando a configuração de projeto estiver definida como Depuração. Durante a depuração, defina pontos de interrupção, pressionando **F9**, execute o código em etapas pressionando **F10**, exiba os valores de variáveis ou de registros especificados e, até mesmo em alguns casos, faça alterações no código e continue a depuração sem a recompilação. Para obter mais informações, consulte [Depuração no Visual Studio](/visualstudio/debugger/debugging-in-visual-studio).

## <a name="deploy-completed-applications"></a>Implantar aplicativos concluídos

Implante um aplicativo UWP nos clientes por meio da Microsoft Store na opção de menu **Projeto** > **Loja**. A implantação do CRT é manipulada automaticamente em segundo plano. Para obter mais informações, confira [Publicar aplicativos e jogos do Windows](/windows/uwp/publish/).

Ao implantar um aplicativo da área de trabalho do C++ nativo em outro computador, você precisa instalar o próprio aplicativo e os arquivos de biblioteca dos quais o aplicativo depende. Há três maneiras de implantar o UCRT (Tempo de Execução do C++ Universal) com um aplicativo: implantação central, implantação local ou vinculação estática. Para obter mais informações, confira [Implantando aplicativos da área de trabalho](../ide/deploying-native-desktop-applications-visual-cpp.md).

Para obter mais informações sobre como implantar um programa do C++/CLI, confira [Guia de Implantação para Desenvolvedores](/dotnet/framework/deployment/deployment-guide-for-developers).

## <a name="related-articles"></a>Artigos relacionados

|||
|-|-|
|[Ferramentas e recursos do Visual C++ em edições do Visual Studio](../ide/visual-cpp-tools-and-features-in-visual-studio-editions.md)|Mostra quais funcionalidades estão disponíveis nas várias edições do Visual Studio.|
|[Criando e gerenciando projetos baseados no MSBuild](../ide/creating-and-managing-visual-cpp-projects.md)|Fornece uma visão geral dos projetos baseados no MSBuild do C++ no Visual Studio e links para outros artigos que explicam como criá-los e gerenciá-los.|
|[Projetos do CMake no Visual C++](cmake-tools-for-visual-cpp.md).|Descreve como compilar projetos do CMake ou outros projetos não MSBuild no Visual C++.|
|[Compilando programas do C/C++](../build/building-c-cpp-programs.md)|Descreve como compilar projetos do C++.|
|[Implantando aplicativos da área de trabalho](../ide/deploying-native-desktop-applications-visual-cpp.md)|Fornece uma visão geral da implantação de aplicativos do C++ e links para outros artigos que descrevem a implantação em detalhes.|
|[Guia de atualização e portabilidade do Visual C++](../porting/visual-cpp-porting-and-upgrading-guide.md)|Informações detalhadas sobre como atualizar aplicativos do C++ criados em versões anteriores do Visual Studio e também como migrar aplicativos criados com ferramentas que não incluem o Visual Studio.|
|[Visual C++](../visual-cpp-in-visual-studio.md)|Descreve as principais funcionalidades do Visual C++ no Visual Studio e fornece links para o restante da documentação do Visual C++.|
