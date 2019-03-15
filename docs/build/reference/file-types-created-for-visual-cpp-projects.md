---
title: Tipos de arquivo criados para projetos do Visual C++
ms.date: 11/04/2016
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
ms.openlocfilehash: c05dd9da5dd17b0e06ace750d34f2c5abcf94380
ms.sourcegitcommit: 8105b7003b89b73b4359644ff4281e1595352dda
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/14/2019
ms.locfileid: "57824557"
---
# <a name="file-types-created-for-visual-studio-c-projects"></a>Tipos de arquivo criados para projetos do Visual Studio C++

Este tópico descreve todos os tipos de arquivos que estão associados a projetos do Visual Studio para aplicativos da área de trabalho clássicos. Os arquivos reais incluídos no projeto dependem do tipo de projeto e das opções selecionadas ao usar um assistente.

- [Arquivos de projeto e solução]()

- [Projetos CLR](files-created-for-clr-projects.md)

- [Programa ATL ou origem de controle e arquivos de cabeçalho](atl-program-or-control-source-and-header-files.md)

- [Programa MFC ou origem de controle e arquivos de cabeçalho](mfc-program-or-control-source-and-header-files.md)

- [Arquivos de cabeçalho pré-compilado](../creating-precompiled-header-files.md)

- [Arquivos de recurso](resource-files-cpp.md)

- [Arquivos de ajuda (WinHelp)](help-files-winhelp.md)

- [Arquivos de dica](hint-files.md)

Quando você cria um projeto do Visual Studio, você pode estar criando uma nova solução, ou você pode adicionar um projeto a uma solução. Geralmente, os aplicativos não triviais são desenvolvidos com vários projetos em uma solução.

Os projetos costumam produzir um EXE ou uma DLL. Projetos podem ser dependentes entre si; durante o processo de compilação, o ambiente do Visual Studio verifica dependências dentro e entre projetos. Cada projeto tem o código-fonte principal e, dependendo do tipo de projeto, pode ter muitos outros arquivos que contém vários aspectos do projeto. O conteúdo desses arquivos é indicado pela extensão de arquivo. O ambiente de desenvolvimento do Visual Studio usa as extensões de arquivo para determinar como manipular o conteúdo do arquivo durante um build.

A tabela a seguir mostra os arquivos comuns em um projeto do Visual Studio e identifica-los com sua extensão de arquivo.

|Extensão de arquivo|Tipo|Conteúdo|
|--------------------|----------|--------------|
|.asmx|Origem|Arquivo de implantação.|
|.asp|Origem|Arquivo Active Server Page.|
|.atp|Projeto|Arquivo de projeto de modelo do aplicativo.|
|.bmp, .dib, .gif, .jpg, .jpe, .png|Recurso|Arquivos de imagem gerais.|
|.bsc|Compilando|O arquivo de código do navegador.|
|.cpp; .c|Origem|Arquivos de código-fonte principal do aplicativo.|
|.cur|Recurso|Arquivo gráfico de bitmap do cursor.|
|.dbp|Projeto|Arquivo de projeto de banco de dados.|
|.disco|Origem|O arquivo de documento da descoberta dinâmica. Manipula a descoberta de serviço Web XML.|
|.exe, .dll|Projeto|Arquivos de biblioteca executável ou de vínculo dinâmico.|
|.h|Origem|Um arquivo de cabeçalho (inclusão).|
|.htm, .html, .xsp, .asp, .htc, .hta, .xml|Recurso|Arquivos da Web comuns.|
|.HxC|Projeto|Arquivo de projeto da Ajuda.|
|.ico|Recurso|Arquivo gráfico de bitmap do ícone.|
|.idb|Compilando|O arquivo de estado, que contém informações de dependência entre os arquivos de origem e as definições de classe, que podem ser usadas pelo compilador durante a recompilação mínima e a compilação incremental. Use a opção do compilador [/Fd](fd-program-database-file-name.md) para especificar o nome do arquivo .idb. Confira [/Gm (Habilitar Recompilação Mínima)](gm-enable-minimal-rebuild.md) para obter mais informações.|
|.idl|Compilando|Um arquivo de linguagem IDL. Confira [Arquivo IDL](/windows/desktop/Rpc/the-interface-definition-language-idl-file) no SDK do Windows para obter mais informações.|
|.ilk|Vinculação|Arquivo de vínculo incremental. Confira [/INCREMENTAL](incremental-link-incrementally.md) para obter mais informações.|
|.map|Vinculação|Um arquivo de texto que contém informações do vinculador. Use a opção do compilador [/Fm](fm-name-mapfile.md) para nomear o arquivo de mapa. Confira [/MAP](map-generate-mapfile.md) para obter mais informações.|
|.mfcribbon-ms|Recurso|Um arquivo de recurso que contém o código XML que define os botões, os controles e os atributos da faixa de opções. Para obter mais informações, confira [Designer da Faixa de Opções (MFC)](../../mfc/ribbon-designer-mfc.md).|
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
|.vcxitems|Projeto|Projeto Itens Compartilhados para compartilhar arquivos de código entre vários projetos do C++. Confira [Arquivos de projeto e Makefiles]() para obter mais informações.|
|.vcxproj|Projeto|O arquivo de projeto do Visual Studio. Confira [Arquivos de projeto e Makefiles]() para obter mais informações.|
|.vcxproj.filters|Projeto|Quando o Gerenciador de Soluções é usado para adicionar um arquivo a um projeto, o arquivo de filtros define em que o local no modo de exibição de árvore do Gerenciador de Soluções o arquivo é adicionado, com base em sua extensão de nome de arquivo.|
|.vdproj|Projeto|O arquivo de projeto de implantação do Visual Studio.|
|.vmx|Projeto|O arquivo de projeto de macro.|
|.vup|Projeto|O arquivo de projeto de utilitário.|

Para obter informações sobre outros arquivos associados ao Visual Studio, confira [Tipos de arquivo e extensões de arquivo no Visual Studio .NET](/visualstudio/ide/reference/project-and-solution-file-types).

Os arquivos de projeto são organizados em pastas no Gerenciador de Soluções. O Visual Studio cria uma pasta para os arquivos de origem, arquivos de cabeçalho e arquivos de recurso, mas você pode reorganizar essas pastas ou criar novos. Use pastas para organizar os clusters lógicos de arquivos explicitamente na hierarquia de um projeto. Por exemplo, crie pastas para conter todos os arquivos de origem da interface do usuário, especificações, documentação ou conjuntos de testes. Todos os nomes de pasta de arquivos devem ser exclusivos.

Quando você adiciona um item a um projeto, você adiciona o item a todas as configurações desse projeto, independentemente de o item ser compilável ou não. Por exemplo, se você tem um projeto chamado MyProject, a adição de um item o adiciona às configurações de projeto Depuração e Versão.

## <a name="see-also"></a>Consulte também

[Criando e gerenciando projetos do Visual Studio C++](../creating-and-managing-visual-cpp-projects.md)<br>
[Tipos de projeto C++ do Visual Studio](visual-cpp-project-types.md)<br>