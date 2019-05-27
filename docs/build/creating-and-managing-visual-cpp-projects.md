---
title: Projetos do Visual Studio – C++
ms.date: 12/12/2018
helpviewer_keywords:
- ATL projects, creating
- Visual Studio C++ projects, creating
- projects [C++], creating
- Visual Studio C++ projects
- ATL projects
ms.assetid: 11003cd8-9046-4630-a189-a32bf3b88047
ms.openlocfilehash: 30d3b13ba4d392cdc5d1c7c611b61066503647a2
ms.sourcegitcommit: a10c9390413978d36b8096b684d5ed4cf1553bc8
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/17/2019
ms.locfileid: "65837064"
---
# <a name="visual-studio-projects---c"></a>Projetos do Visual Studio – C++

Um *projeto do Visual Studio* é um projeto baseado no sistema de build do MSBuild. O MSBuild é o sistema de build nativo para o Visual Studio e, geralmente, é o melhor sistema de build a ser usado para aplicativos UWP, bem como para aplicativos da Área de Trabalho que usam bibliotecas MFC ou ATL, componentes COM e outros programas específicos do Windows. O MSBuild está totalmente integrado ao Visual Studio, mas você também pode usá-lo na linha de comando. 

## <a name="create-a-project"></a>Criar um projeto

::: moniker range="vs-2019"

Crie projetos C++ escolhendo **Arquivo** > **Novo** > **Projeto** e, em seguida, definindo a **Linguagem** como C++. Na lista de resultados, você verá uma lista de modelos de projeto pela qual poderá filtrar, definindo a **Plataforma** ou o **Tipo de Projeto** e digitando palavras-chave na caixa de pesquisa. 

   ![Modelos de Projeto do Visual Studio 2019](../build/media/vs2019-choose-console-app.png "Caixa de diálogo Novo Projeto do Visual Studio 2019")

::: moniker-end

::: moniker range="vs-2017"

Crie projetos C++ escolhendo **Arquivo** > **Novo** > **Projeto** e, em seguida, escolhendo Visual C++ no painel esquerdo. No painel central, você verá uma lista de modelos de projeto:

   ![Modelos de projeto](../overview/media/vs2017-new-project.png "Caixa de diálogo \"Novo projeto\" do Visual Studio 2017")

::: moniker-end

Para obter mais informações sobre todos os modelos de projeto padrão incluídos no Visual Studio, confira [Modelos de projeto C++ no Visual Studio](reference/visual-cpp-project-types.md). Criar seus próprios modelos de projeto. Para obter mais informações, confira [Como: Criar modelos de projeto](/visualstudio/ide/how-to-create-project-templates).

Depois que você criar um projeto, ele será exibido na janela [Gerenciador de Soluções](/visualstudio/ide/solutions-and-projects-in-visual-studio):

   ![Gerenciador de Soluções](media/mathlibrary-solution-explorer-153.png)

Quando você cria um projeto, um arquivo de solução (.sln) também é criado. Adicione mais projetos à solução clicando com o botão direito do mouse nele no **Gerenciador de Soluções**. O arquivo de solução é usado para coordenar as dependências de build quando você tem vários projetos relacionados, mas não faz muito mais do que isso. Todas as opções do compilador são definidas no nível do projeto.

## <a name="add-items"></a>Adicionar itens

Adicione arquivos de código-fonte, ícones ou outros itens ao projeto clicando com o botão direito do mouse no projeto no **Gerenciador de Soluções** e escolhendo **Adicionar > Novo** ou **Adicionar > Existente**.

## <a name="add-third-party-libraries"></a>Adicionar bibliotecas de terceiros

Para adicionar bibliotecas de terceiros, use o gerenciador de pacotes do [vcpkg](vcpkg.md). Execute a etapa de integração do Visual Studio para configurar os caminhos para essa biblioteca quando você referenciá-la em qualquer projeto do Visual Studio. 

## <a name="set-compiler-options-and-other-build-properties"></a>Definir opções do compilador e outras propriedades de build

Para definir configurações de build para um projeto, clique com o botão direito do mouse no projeto no **Gerenciador de Soluções** e escolha **Propriedades**. Para obter mais informações, confira [Definir as propriedades de build e do compilador do C++ no Visual Studio](working-with-project-properties.md).

## <a name="compile-and-run"></a>Compilar e executar

Para compilar e executar o novo projeto, pressione **F5** ou clique na *lista suspensa de depuração* com a seta verde na barra de ferramentas principal. A *lista suspensa de configuração* é o local em que você escolhe se deseja executar um build de *Depuração* ou *Versão* (ou outra configuração personalizada).

Um novo projeto é compilado sem erros. Ao adicionar seu próprio código, ocasionalmente, você pode introduzir um erro ou disparar um aviso. Um erro impede a conclusão do build, ao contrário de um aviso. Todos os erros e avisos serão exibidos na Janela de Saída e na Lista de Erros quando você compilar o projeto. 

   ![Janela de Saída e Lista de Erros](../overview/media/vs2017-output-error-list.png)

Na Lista de Erros, pressione **F1** em um erro realçado para acessar o tópico da documentação.

## <a name="in-this-section"></a>Nesta seção

[Definição das propriedades de compilação do C++ no Visual Studio](working-with-project-properties.md)<br/>
Como usar as páginas de propriedades e as folhas de propriedades para especificar as configurações do projeto.

[Bibliotecas e componentes de referência em tempo de compilação](adding-references-in-visual-cpp-projects.md)<br/>
Como incluir bibliotecas, DLLs e componentes .NET e COM em um projeto.
 
[Organização de arquivos de saída do projeto](how-to-organize-project-output-files-for-builds.md)<br/>
Como personalizar a localização dos arquivos executáveis criados no processo de build.

[Etapas e eventos de build personalizados](understanding-custom-build-steps-and-build-events.md)<br/>
Como adicionar qualquer comando arbitrário para o processo de build em pontos específicos.

[Criar um projeto com base em código existente](how-to-create-a-cpp-project-from-existing-code.md)<br/>
Como criar um projeto do Visual Studio com base em uma coleção flexível de arquivos de origem.

## <a name="see-also"></a>Consulte também

[Sistemas de Compilação e Projetos](projects-and-build-systems-cpp.md)<br>
