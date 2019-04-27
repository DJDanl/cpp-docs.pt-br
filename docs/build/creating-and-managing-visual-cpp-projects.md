---
title: Projetos do Visual Studio – C++
ms.date: 12/12/2018
f1_keywords:
- vcprojects
- creatingmanagingVC
helpviewer_keywords:
- ATL projects, creating
- Visual C++ projects, creating
- projects [C++], creating
- Visual C++ projects
- ATL projects
ms.assetid: 11003cd8-9046-4630-a189-a32bf3b88047
ms.openlocfilehash: b4772b9bd625a542a18039386fefe42840ab65b1
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62195685"
---
# <a name="visual-studio-projects---c"></a>Projetos do Visual Studio – C++

Um *projeto do Visual Studio* é um projeto com base no sistema de build do MSBuild. O MSBuild é o sistema de compilação nativa para Visual Studio e é geralmente que o melhor criar o sistema a ser usado para aplicativos UWP, bem como aplicativos da área de trabalho que usam bibliotecas MFC ou ATL, componentes COM e outros programas específicos do Windows. MSBuild está totalmente integrado ao Visual Studio, mas você também pode usá-lo na linha de comando. 

## <a name="create-a-project"></a>Criar um projeto

Você pode criar projetos do C++, escolhendo **arquivo &#124; novo &#124; Project**, em seguida, escolhendo o Visual C++ no painel esquerdo. No painel central, você verá uma lista de modelos de projeto: 

   ![Modelos de projeto](../overview/media/vs2017-new-project.png "Caixa de diálogo \"Novo projeto\" do Visual Studio 2017")

Para obter mais informações sobre todos os modelos de projeto padrão que estão incluídos no Visual Studio, consulte [modelos de projeto do C++ no Visual Studio](reference/visual-cpp-project-types.md). Você pode criar seus próprios modelos de projeto. Para obter mais informações, confira [Como: Criar modelos de projeto](/visualstudio/ide/how-to-create-project-templates).

Depois de criar um projeto, ele aparece na [Gerenciador de soluções](/visualstudio/ide/solutions-and-projects-in-visual-studio) janela:

   ![Gerenciador de Soluções](media/mathlibrary-solution-explorer-153.png)

Quando você cria um novo projeto, também é criado um arquivo de solução (. sln). Você pode adicionar mais projetos à solução clicando no **Gerenciador de soluções**. O arquivo de solução é usado para coordenar as dependências de compilação quando você tiver vários projetos relacionados, mas não faz muito mais do que isso. Todas as opções de compilador são definidas no nível do projeto.

## <a name="add-items"></a>Adicionar itens

Adicionar arquivos de código-fonte, ícones ou qualquer outro item ao seu projeto clicando com o projeto no **Gerenciador de soluções** e escolhendo **Adicionar > novo** ou **Add > existente**.

## <a name="add-third-party-libraries"></a>Adicionar bibliotecas de terceiros

Para adicionar as bibliotecas de terceiros, use o [vcpkg](vcpkg.md) Gerenciador de pacotes. Execute a etapa de integração do Visual Studio para configurar os caminhos para essa biblioteca quando você referenciá-lo de qualquer projeto do Visual Studio. 

## <a name="set-compiler-options-and-other-build-properties"></a>Definir opções do compilador e outras propriedades de compilação

Para definir configurações de compilação para um projeto, clique com botão direito no projeto no **Gerenciador de soluções** e escolha **propriedades**. Para obter mais informações, consulte [propriedades de compilador e de build definida C++ no Visual Studio](working-with-project-properties.md).

## <a name="compile-and-run"></a>Compilar e executar

Para compilar e executar o novo projeto, pressione **F5** ou clique no *lista suspensa de depuração* com a seta verde na barra de ferramentas principal. O *lista suspensa de configuração* é onde você escolhe se deseja executar uma *Debug* ou *versão* build (ou outra configuração personalizada).

Um novo projeto é compilado sem erros. Ao adicionar seu próprio código, você pode, ocasionalmente, introduzir um erro ou disparar um aviso. Um erro impede a compilação de conclusão; um aviso, não. Todos os erros e avisos aparecerá na janela de saída e na lista de erros quando compilar o projeto. 

   ![Lista de erros e janela de saída](../overview/media/vs2017-output-error-list.png)

Na lista de erros, você pode pressionar **F1** em um erro realçado para ir para o tópico de documentação.

## <a name="in-this-section"></a>Nesta seção

[Definição das propriedades de compilação do C++ no Visual Studio](working-with-project-properties.md)<br/>
Como usar páginas de propriedades e folhas de propriedades para especificar as configurações do projeto.

[Bibliotecas e componentes de referência em tempo de compilação](adding-references-in-visual-cpp-projects.md)<br/>
Como incluir componentes de bibliotecas, DLLs, COM e .NET em um projeto.
 
[Organização de arquivos de saída do projeto](how-to-organize-project-output-files-for-builds.md)<br/>
Como personalizar o local dos arquivos executáveis criados no processo de compilação.

[Etapas e eventos de build personalizados](understanding-custom-build-steps-and-build-events.md)<br/>
Como adicionar qualquer comando arbitrário para o processo de compilação em pontos específicos.

[Criar um projeto com base em código existente](how-to-create-a-cpp-project-from-existing-code.md)<br/>
Como criar um novo projeto do Visual Studio de um conjunto flexível de arquivos de origem.

## <a name="see-also"></a>Consulte também

[Sistemas de Compilação e Projetos](projects-and-build-systems-cpp.md)<br>
