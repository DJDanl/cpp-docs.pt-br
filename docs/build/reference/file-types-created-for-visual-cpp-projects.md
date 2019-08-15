---
title: Tipos de arquivo criados para projetos C++ do Visual Studio
ms.date: 04/08/2019
helpviewer_keywords:
- header files [C++], Visual Studio projects
- ActiveX controls [C++], Help files
- def files
- project items [C++], files
- Visual Studio C++ projects, files and directories
- resource files, created by wizard
- files [C++], extensions
- Help files, for ActiveX controls
- Web projects [C++], adding items
- .def files
- licensing ActiveX controls
ms.assetid: 2b0ee2e0-ae81-4185-9bb9-11da3c99a283
ms.openlocfilehash: 078c83a9c95c1b143af2037240d5cc0a16211827
ms.sourcegitcommit: fcb48824f9ca24b1f8bd37d647a4d592de1cc925
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/15/2019
ms.locfileid: "69492877"
---
# <a name="file-types-created-for-visual-studio-c-projects"></a>Tipos de arquivo criados para projetos C++ do Visual Studio

Muitos tipos de arquivos são associados a projetos do Visual Studio para aplicativos de área de trabalho clássica. Os arquivos reais incluídos no projeto dependem do tipo de projeto e das opções selecionadas ao usar um assistente.

- [Arquivos de projeto e solução](project-and-solution-files.md)

- [Projetos CLR](files-created-for-clr-projects.md)

- [Programa ATL ou origem de controle e arquivos de cabeçalho](atl-program-or-control-source-and-header-files.md)

- [Programa MFC ou origem de controle e arquivos de cabeçalho](mfc-program-or-control-source-and-header-files.md)

- [Arquivos de cabeçalho pré-compilado](../creating-precompiled-header-files.md)

- [Arquivos de recurso](resource-files-cpp.md)

- [Arquivos de ajuda (WinHelp)](help-files-winhelp.md)

- [Arquivos de dica](hint-files.md)

Quando você cria um projeto do Visual Studio, você pode criá-lo em uma nova solução ou pode adicionar um projeto a uma solução existente. Geralmente, os aplicativos não triviais são desenvolvidos com vários projetos em uma solução.

Os projetos costumam produzir um EXE ou uma DLL. Os projetos podem ser dependentes uns dos outros; durante o processo de compilação, o ambiente do Visual Studio verifica dependências dentro e entre projetos. Cada projeto geralmente tem código-fonte principal. Dependendo do tipo de projeto, ele pode ter muitos outros arquivos contendo vários aspectos do projeto. O conteúdo desses arquivos é indicado pela extensão de arquivo. O ambiente de desenvolvimento do Visual Studio usa as extensões de arquivo para determinar como manipular o conteúdo do arquivo durante um build.

A tabela a seguir mostra os arquivos comuns em um projeto do Visual Studio e os identifica com sua extensão de arquivo.

|Extensão de arquivo|Tipo|Conteúdo|
|--------------------|----------|--------------|
|.asmx|Origem|Arquivo de implantação.|
|.asp|Origem|Arquivo Active Server Page.|
|.atp|Projeto|Arquivo de projeto de modelo do aplicativo.|
|.bmp, .dib, .gif, .jpg, .jpe, .png|Recurso|Arquivos de imagem gerais.|
|.bsc|Compilando|O arquivo de código do navegador.|
|.cpp, .c|Origem|Arquivos de código-fonte principal do aplicativo.|
|.cur|Recurso|Arquivo gráfico de bitmap do cursor.|
|.dbp|Projeto|Arquivo de projeto de banco de dados.|
|.disco|Origem|O arquivo de documento da descoberta dinâmica. Manipula a descoberta de serviço Web XML.|
|.exe, .dll|Projeto|Arquivos de biblioteca executável ou de vínculo dinâmico.|
|.h|Origem|Um arquivo de cabeçalho (inclusão).|
|.htm, .html, .xsp, .asp, .htc, .hta, .xml|Recurso|Arquivos da Web comuns.|
|.HxC|Projeto|Arquivo de projeto da Ajuda.|
|.ico|Recurso|Arquivo gráfico de bitmap do ícone.|
|.idb|Compilando|O arquivo de estado, que contém informações de dependência entre os arquivos de origem e as definições de classe. Ele pode ser usado pelo compilador durante a compilação incremental. Use a opção do compilador [/Fd](fd-program-database-file-name.md) para especificar o nome do arquivo .idb.|
|.idl|Compilando|Um arquivo de linguagem IDL. Para obter mais informações, confira [Arquivo IDL](/windows/win32/Rpc/the-interface-definition-language-idl-file) no SDK do Windows.|
|.ilk|Vinculação|Arquivo de vínculo incremental. Para obter mais informações, consulte [/incremental](incremental-link-incrementally.md).|
|.map|Vinculação|Um arquivo de texto que contém informações do vinculador. Use a opção do compilador [/Fm](fm-name-mapfile.md) para nomear o arquivo de mapa. Para obter mais informações, consulte [/MAP](map-generate-mapfile.md).|
|.mfcribbon-ms|Recurso|Um arquivo de recurso que contém o código XML que define os botões, controles e atributos do MFC na faixa de faixas. Para obter mais informações, consulte [Fitas](../../mfc/ribbon-designer-mfc.md).|
|.obj, .o||Arquivos-objeto, compilados mas não vinculados.|
|.pch|Depurar|Arquivo de cabeçalho pré-compilado.|
|.rc, .rc2|Recurso|[Arquivos de script de recurso](../../windows/working-with-resource-files.md) para gerar recursos.|
|.sbr|Compilando|Arquivo intermediário do navegador de origem. O arquivo de entrada para [BSCMAKE](bscmake-options.md).|
|.sln|Solução|O arquivo de [solução](/visualstudio/ide/solutions-and-projects-in-visual-studio).|
|.suo|Solução|O arquivo de opções da solução.|
|.txt|Recurso|Um arquivo de texto, geralmente, o arquivo "Leiame".|
|.vap|Projeto|Um arquivo de projeto do Visual Studio Analyzer.|
|.vbg|Solução|Um arquivo de grupo de projetos compatível.|
|.vbp, .vip, .vbproj|Projeto|O arquivo de projeto do Visual Basic.|
|.vcxitems|Projeto|Projeto Itens Compartilhados para compartilhar arquivos de código entre vários projetos do C++. Para obter mais informações, consulte [Project and Solution files](project-and-solution-files.md).|
|.vcxproj|Projeto|O arquivo de projeto do Visual Studio. Para obter mais informações, consulte [Project and Solution files](project-and-solution-files.md).|
|.vcxproj.filters|Projeto|Usado quando você usa Gerenciador de Soluções para adicionar um arquivo a um projeto. O arquivo de filtros define o local no modo de exibição de árvore de Gerenciador de Soluções para adicionar o arquivo, com base em sua extensão de nome de arquivo.|
|.vdproj|Projeto|O arquivo de projeto de implantação do Visual Studio.|
|.vmx|Projeto|O arquivo de projeto de macro.|
|.vup|Projeto|O arquivo de projeto de utilitário.|

Para obter informações sobre outros arquivos associados ao Visual Studio, confira [Tipos de arquivo e extensões de arquivo no Visual Studio .NET](/visualstudio/ide/reference/project-and-solution-file-types).

Os arquivos de projeto são organizados em pastas no Gerenciador de Soluções. O Visual Studio cria uma pasta para arquivos de origem, arquivos de cabeçalho e arquivos de recurso, mas você pode reorganizar essas pastas ou criar novas. Use pastas para organizar os clusters lógicos de arquivos explicitamente na hierarquia de um projeto. Por exemplo, você pode criar pastas para conter todos os arquivos de origem da interface do usuário. Ou, pastas para especificações, documentação ou conjuntos de testes. Todos os nomes de pasta de arquivos devem ser exclusivos.

Quando você adiciona um item a um projeto, você adiciona o item a todas as configurações para esse projeto. O item é adicionado independentemente de ser compilável ou não. Por exemplo, se você tem um projeto chamado MyProject, a adição de um item o adiciona às configurações de projeto Depuração e Versão.

## <a name="see-also"></a>Consulte também

[Criando e gerenciando projetos C++ do Visual Studio](../creating-and-managing-visual-cpp-projects.md)<br>
[Tipos de C++ projeto do Visual Studio](visual-cpp-project-types.md)<br>