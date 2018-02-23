---
title: IDE e ferramentas de desenvolvimento do Visual C++ | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-ide
ms.tgt_pltfrm: 
ms.topic: article
dev_langs:
- C++
helpviewer_keywords:
- Visual C++, development tools
ms.assetid: 56eabafb-1956-4f0f-bec5-29b887763559
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 4b6ff3f709e5db16f06569ab3406cfef44cabf11
ms.sourcegitcommit: a5a69d2dc3513261e9e28320e4e067aaf40d2ef2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/21/2018
---
# <a name="ide-and-tools-for-visual-c-development"></a>IDE e ferramentas de desenvolvimento do Visual C++

Como parte do Visual Studio Integrated Development Environment (IDE), Microsoft Visual C++ (MSVC) compartilha muitas janelas e ferramentas em comum com outras linguagens. Muitos deles, incluindo **Solution Explorer**, o editor de código e o depurador estão documentados em [IDE do Visual Studio](/visualstudio/ide/visual-studio-ide). Geralmente, uma ferramenta compartilhada ou a janela tem um conjunto de recursos ligeiramente diferente para C++ que para as linguagens .NET ou Javascript. Alguns windows ou ferramentas só estão disponíveis no Visual Studio Pro ou o Visual Studio Enterprise.

Além das ferramentas compartilhadas no IDE do Visual Studio, MSVC tem várias ferramentas especificamente para desenvolvimento de código nativo. Essas ferramentas também são listadas neste artigo. Para obter uma lista dos quais ferramentas estão disponíveis em cada edição do Visual Studio, consulte [recursos em edições do Visual Studio e ferramentas do Visual C++](../ide/visual-cpp-tools-and-features-in-visual-studio-editions.md).

## <a name="creating-a-solution-and-projects"></a>Criando uma solução e projetos

Um *projeto* é basicamente um conjunto de arquivos de código fonte e recursos, como imagens ou arquivos de dados que são criados em um arquivo executável. 2017 do Visual Studio pode dar suporte a qualquer sistema de compilação ou ferramentas de compilação personalizado que você deseja usar, com suporte total para Intellisense, pesquisa e a depuração:

- MSBuild é o sistema de compilação nativa para o Visual Studio e geralmente é a melhor escolha para aplicativos do Windows UWP (plataforma Universal) ou aplicativos herdados da área de trabalho Windows que usam MFC ou do ATL Para obter mais informações sobre projetos do C++ com base em MSBuild, consulte [criando e gerenciando projetos com base em MSBuild](creating-and-managing-visual-cpp-projects.md).
- CMake é uma plataforma cruzada criar sistema que é integrado ao IDE do Visual Studio quando você instala o desenvolvimento de área de trabalho com a carga de trabalho do C++. Para saber mais, veja [Projetos CMake no Visual C++](cmake-tools-for-visual-cpp.md).
- Qualquer outro C++ compilação sistema, incluindo um conjunto flexível de arquivos, há suporte para o recurso de abrir a pasta. Criar arquivos JSON simples para chamar o programa de compilação e configurar sessões de depuração. Para obter mais informações, consulte [trazer seu código C++ para Visual Studio](https://blogs.msdn.microsoft.com/vcblog/2017/04/14/bring-your-cpp-code-to-visual-studio/).

### <a name="project-templates-msbuild"></a>Modelos de projeto (MSBuild)

O Visual Studio contém vários modelos para projetos de MSBuild; Esses modelos contêm o código de inicialização e as configurações necessárias para uma variedade de tipos básicos do programa. Normalmente você começar escolhendo **arquivo** > **novo projeto** para criar um projeto de um modelo de projeto, em seguida, adicionar novos arquivos de código de origem para o projeto ou iniciar a codificação de arquivos fornecido. Para obter informações específicas para projetos C++ e assistentes de projeto, consulte [criando e gerenciando projetos do Visual C++](../ide/creating-and-managing-visual-cpp-projects.md).

### <a name="application-wizards-msbuild"></a>Assistentes de aplicativo (MSBuild)

O Visual Studio fornece assistentes para alguns tipos de projeto do MSBuild, quando você escolhe **arquivo** > **novo projeto**. Um assistente conduzirá você pelo processo de criação de um novo projeto. Isso é útil para tipos de projeto que têm muitas opções e configurações. Para obter mais informações, consulte [criar área de trabalho projetos por usando assistentes de aplicativo](../ide/creating-desktop-projects-by-using-application-wizards.md).

## <a name="creating-user-interfaces-with-designers-msbuild"></a>Criando interfaces de usuário com designers (MSBuild)

Se seu programa tem uma interface de usuário, uma das primeiras tarefas é preenchê-lo com os controles como botões, caixas de listagem e assim por diante. O Visual Studio inclui uma superfície de design visual e uma caixa de ferramentas para cada tipo de aplicativo em C++. Não importa qual tipo de aplicativo que você está criando, a ideia básica é o mesmo: você arrasta um controle da janela da caixa de ferramentas e solte-o na superfície de design no local desejado. Em segundo plano, o Visual Studio gera os recursos e o código necessário para que tudo funcione. Em seguida, você escreve o código para preencher os controles com dados ou personalize sua aparência e comportamento.

Para obter mais informações sobre como criar uma interface do usuário para um aplicativo de plataforma Universal do Windows, consulte [Design e a interface do usuário](https://developer.microsoft.com/en-us/windows/design).

Para obter mais informações sobre como criar uma interface do usuário para um aplicativo MFC, consulte [aplicativos de Desktop do MFC](../mfc/mfc-desktop-applications.md). Para obter informações sobre programas do Windows Win32, consulte [aplicativos de área de trabalho do Windows](../windows/windows-desktop-applications-cpp.md).

## <a name="writing-and-editing-code"></a>Gravando e editando código

### <a name="semantic-colorization"></a>Colorização semântica

Depois de criar um projeto, todos os arquivos de projeto são exibidos no **Solution Explorer** janela. Quando você clicar em um arquivo. h ou. cpp no **Solution Explorer**, o arquivo é aberto no editor de códigos. O editor de códigos é um processador de textos especializado para código-fonte C++. Ele insere palavras-chave, nomes de método e a variável e outros elementos do seu código para tornar o código mais legível e mais fácil de entender.

### <a name="intellisense"></a>Intellisense

O editor de código também oferece suporte a vários recursos que juntas são conhecidos como Intellisense. Você pode passe o mouse sobre um método e ver alguns documentação básica para ele. Depois de digitar um nome de variável de classe e um. ou ->, é exibida uma lista de membros de instância dessa classe. Se você digitar um nome de classe e, em seguida, um::, será exibida uma lista de membros estáticos. Quando você começa a digitar um nome de classe ou método, o editor de código oferece sugestões para completar a instrução. Para obter mais informações, veja [Usando o IntelliSense](/visualstudio/ide/using-intellisense).

### <a name="code-snippets"></a>Trechos de código

Você pode usar trechos de código do Intellisense para gerar mais usados ou construções de código complicado com um pressionamento de tecla de atalho. Para obter mais informações, consulte [Trechos de Código](/visualstudio/ide/code-snippets).

## <a name="navigating-code"></a>Navegação de código

O **exibição** menu fornece acesso a várias janelas e ferramentas para navegar nos arquivos de código. Para obter informações detalhadas sobre essas janelas, consulte [exibindo a estrutura do código](/visualstudio/ide/viewing-the-structure-of-code).

### <a name="solution-explorer"></a>Gerenciador de Soluções

Em todas as edições do Visual Studio, use o **Solution Explorer** painel para navegar entre os arquivos em um projeto. Expanda um ícone de arquivo. h ou. cpp para exibir as classes no arquivo. Expanda uma classe para ver seus membros. Clique duas vezes em um membro para navegar até sua definição ou a implementação no arquivo.

### <a name="class-view-and-code-definition-window"></a>Exibição de classe e janela de definição de código

Use o **exibição de classe** painel para ver as classes e namespaces em todos os arquivos, incluindo classes parciais. Você pode expandir cada namespace ou classe para ver seus membros e clique duas vezes no membro para navegar até o local no arquivo de origem. Se você abrir o **janela de definição de código**, você pode exibir a definição ou a implementação do tipo quando você escolhe na **exibição de classe**.

### <a name="object-browser"></a>Pesquisador de Objetos

Use **Pesquisador de objetos** para explorar as informações de tipo em componentes do Windows Runtime (arquivos. winmd), assemblies .NET e COM bibliotecas de tipos. Ele não é usado com DLLs Win32.

### <a name="go-to-definitiondeclaration"></a>Ir para declaração/definição

Pressione F12 qualquer variável de nome ou membro de API para ir para sua definição. Se a definição em um arquivo. winmd (para um UWP ou Windows 8. x Store app), em seguida, você verá as informações de tipo no Pesquisador de objetos. Você também pode escolher **ir para definição** ou **ir para declaração** clicando duas vezes no nome da variável ou tipo e escolher a opção no menu de contexto.

### <a name="find-all-references"></a>Localizar Todas as Referências

Em um arquivo de código fonte, clique com o cursor do mouse sobre o nome de um tipo ou método ou variável e escolha **localizar todas as referências** para retornar uma lista de todos os locais do arquivo, projeto ou solução em que o tipo é usado. **Localizar todas as referências** é inteligente e retorna apenas as instâncias da mesma variável idêntico, mesmo que outras variáveis em escopo diferente com o mesmo nome.

## <a name="add-and-edit-resources--msbuild"></a>Adicionar e editar recursos (MSBuild)

O termo *recurso* no contexto de um Visual Studio desktop projeto inclui coisas como caixas de diálogo, ícones, cadeias de caracteres localizáveis, telas, cadeias de conexão de banco de dados ou todos os dados arbitrários que você deseja incluir do arquivo executável.

Para obter mais informações sobre como adicionar e editar recursos em projetos em C++ nativo da área de trabalho, consulte [trabalhando com arquivos de recurso](../windows/working-with-resource-files.md).

## <a name="build-compile-and-link"></a>Build (compilação e link)

Escolha **criar** > **compilar solução** no menu barra ou insira a combinação de teclas Ctrl + Shift + B para compilar e vincular a um projeto. Para criar o código executável, o Visual Studio usa [MSBuild](/visualstudio/msbuild/msbuild1) ou CMake ou qualquer ambiente de compilação é configurado por meio de **Abrir pasta**. Para projetos de MSBuild, você defina opções de compilação gerais em **ferramentas** > **opções** > **projetos e soluções** e você pode definir propriedades para projetos específicos em **projeto** > **propriedades**. Avisos e erros de compilação são relatados na lista de erros (Ctrl +\\, E). Projetos de MSBuild não são configurados com os arquivos JSON que você criar no Gerenciador de soluções. Tudo o que criar sistema usado, o **saída** janela (Alt + 2) mostra informações sobre o processo de compilação. Para obter mais informações sobre as configurações do MSBuild, consulte [trabalhando com propriedades de projeto](../ide/working-with-project-properties.md) e [Construindo projetos do C++ no Visual Studio](../ide/building-cpp-projects-in-visual-studio.md).

Você também pode usar o compilador (cl.exe) e muitas outras ferramentas de autônomo relacionados a compilação como NMAKE e LIB diretamente da linha de comando. Para obter mais informações, consulte [código C/C++ compilar na linha de comando](../build/building-on-the-command-line.md) e [referência de build do C/C++](../build/reference/c-cpp-building-reference.md).

## <a name="test"></a>Teste

O Visual Studio inclui uma estrutura de teste de unidade para C++ nativo e C + + CLI. Para obter mais informações, consulte [verificando o código usando testes de unidade](/visualstudio/test/unit-test-your-code) e [testes de unidade de gravação para C/C++ com o Microsoft Unit Testing Framework para C++](/visualstudio/test/writing-unit-tests-for-c-cpp-with-the-microsoft-unit-testing-framework-for-cpp)

## <a name="debug"></a>Depuração

Você pode depurar seu programa pressionando **F5** quando a configuração de projeto está definida para depuração. Enquanto a depuração, você pode definir pontos de interrupção, pressionando **F9**, percorrer código pressionando **F10**, exiba os valores de variáveis especificadas ou registros e até mesmo em alguns casos, fazer alterações no código e continuar depuração sem recompilação. Para obter mais informações, consulte [Depuração no Visual Studio](/visualstudio/debugger/debugging-in-visual-studio).

## <a name="deploy-completed-applications"></a>Implantar aplicativos concluídos

Implantar um aplicativo UWP aos clientes por meio da Microsoft Store por meio de **projeto** > **repositório** opção de menu. Implantação do CRT é tratada automaticamente em segundo plano. Para obter mais informações, consulte [vender aplicativos](http://go.microsoft.com/fwlink/p/?LinkId=262280).

Quando você implanta um aplicativo de área de trabalho C++ nativo para outro computador, você deve instalar o aplicativo em si e quaisquer arquivos de biblioteca que o aplicativo depende. Para implantar o tempo de execução C++ Universal (UCRT) com um aplicativo de três maneiras: implantação central, a implantação local ou a vinculação estática. Para obter mais informações, consulte [implantação de aplicativos de área de trabalho](../ide/deploying-native-desktop-applications-visual-cpp.md).

Para obter mais informações sobre como implantar um C + + programa da CLI, consulte [guia de implantação para desenvolvedores](/dotnet/framework/deployment/deployment-guide-for-developers),

## <a name="related-articles"></a>Artigos relacionados

|||
|-|-|
|[Ferramentas e recursos do Visual C++ em edições do Visual Studio](../ide/visual-cpp-tools-and-features-in-visual-studio-editions.md)|Mostra quais recursos estão disponíveis em várias edições do Visual Studio.|
|[Criando e gerenciando projetos com base em MSBuild](../ide/creating-and-managing-visual-cpp-projects.md)|Fornece uma visão geral de projetos com base em MSBuild C++ no Visual Studio e links para outros artigos que explicam como criar e gerenciá-los.|
|[Projetos Visual C++ CMake](cmake-tools-for-visual-cpp.md).|Descreve como criar CMake ou outros projetos não MSBuild no Visual C++.|
|[Compilando programas do C/C++](../build/building-c-cpp-programs.md)|Descreve como criar projetos C++.|
|[Implantando aplicativos de área de trabalho](../ide/deploying-native-desktop-applications-visual-cpp.md)|Fornece uma visão geral de implantação para aplicativos em C++ e links para outros artigos que descrevem a implantação em detalhes.|
|[Guia de atualização e portabilidade do Visual C++](../porting/visual-cpp-porting-and-upgrading-guide.md)|Informações detalhadas sobre como atualizar aplicativos C++ que foram criados em versões anteriores do Visual Studio e também como migrar aplicativos que foram criados usando ferramentas que não sejam o Visual Studio.|
|[Visual C++](../visual-cpp-in-visual-studio.md)|Descreve os principais recursos do Visual C++ no Visual Studio e links para o restante da documentação do Visual C++.|
