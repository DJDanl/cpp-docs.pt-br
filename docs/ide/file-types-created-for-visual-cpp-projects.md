---
title: Criado para projetos do Visual C++ de tipos de arquivo | Microsoft Docs
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
- header files [C++], Visual C++ projects
- ActiveX controls [C++], Help files
- def files
- project items [C++], files
- Visual C++ projects, files and directories
- resource files, created by wizard
- files [C++], extensions
- Help files, for ActiveX controls
- Web projects [C++], adding items
- .def files
- licensing ActiveX controls
ms.assetid: 2b0ee2e0-ae81-4185-9bb9-11da3c99a283
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 90d7b1523c8a61405224fc21701b5203e2cfb006
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="file-types-created-for-visual-c-projects"></a>Tipos de arquivo criados para projetos do Visual C++
Este tópico descreve todos os tipos de arquivos que estão associados com projetos do Visual C++ para aplicativos de área de trabalho clássicos. Os arquivos reais incluídos em seu projeto dependem do tipo de projeto e as opções selecionadas ao usar um assistente.  
  
-   [Arquivos de projeto e solução](../ide/project-and-solution-files.md)  
  
-   [Projetos CLR](../ide/files-created-for-clr-projects.md)  
  
-   [Programa ATL ou origem de controle e arquivos de cabeçalho](../ide/atl-program-or-control-source-and-header-files.md)  
  
-   [Programa MFC ou origem de controle e arquivos de cabeçalho](../ide/mfc-program-or-control-source-and-header-files.md)  
  
-   [Arquivos de cabeçalho pré-compilado](../ide/precompiled-header-files.md)  
  
-   [Arquivos de recurso](../ide/resource-files-cpp.md)  
  
-   [Arquivos de ajuda (WinHelp)](../ide/help-files-winhelp.md)  
  
-   [Arquivos de dica](../ide/hint-files.md)  
  
 Quando você [criar um projeto do Visual C++](../ide/creating-desktop-projects-by-using-application-wizards.md), você pode criar uma nova solução, ou você pode adicionar um projeto a uma solução. Aplicativos não trivial geralmente são desenvolvidos com vários projetos em uma solução.  
  
 Os projetos geralmente produzem um executável ou uma DLL. Projetos podem ser dependentes entre si; durante o processo de compilação, o ambiente do Visual C++ verifica as dependências dentro e entre projetos. Cada projeto tem o código-fonte principal e, dependendo do tipo de projeto, ele pode ter muitos outros arquivos que contém vários aspectos do projeto. O conteúdo desses arquivos é indicado pela extensão de arquivo. O ambiente de desenvolvimento do Visual Studio usa as extensões de arquivo para determinar como tratar o conteúdo do arquivo durante uma compilação.  
  
 A tabela a seguir mostra os arquivos comuns em um projeto do Visual C++ e identifica-las com sua extensão de arquivo.  
  
|Extensão de arquivo|Tipo|Conteúdo|  
|--------------------|----------|--------------|  
|. asmx|Origem|Arquivo de implantação.|  
|. ASP|Origem|Arquivo de Active Server Page.|  
|.ATP|Projeto|Arquivo de projeto de modelo de aplicativo.|  
|. bmp,. dib,. gif,. jpg,. jpe,. PNG|Recurso|Arquivos de imagem geral.|  
|. bsc|Compilando|O arquivo de código do navegador.|  
|. cpp; o. c|Origem|Arquivos de código fonte principal de seu aplicativo.|  
|cur|Recurso|Arquivo de gráfico de bitmap de cursor.|  
|dbp|Projeto|Arquivo de projeto de banco de dados.|  
|. disco|Origem|O arquivo de documento de descoberta dinâmica. Lida com a descoberta de serviço da Web em XML.|  
|.exe,. dll|Projeto|Arquivos de biblioteca executável ou de vínculo dinâmico.|  
|.h|Origem|Um cabeçalho (incluir) arquivos.|  
|. htm,. HTML, .xsp,. asp,. htc,. HTA,. XML|Recurso|Arquivos comuns de Web.|  
|. HxC|Projeto|Arquivo de projeto de Ajuda.|  
|.ico|Recurso|Arquivo de gráfico de bitmap de ícone.|  
|.IDB|Compilando|O arquivo de estado, que contém informações de dependência entre os arquivos de origem e definições de classe, que podem ser usadas pelo compilador durante a recompilação mínima e a compilação incremental. Use o [/Fd](../build/reference/fd-program-database-file-name.md) opção de compilador para especificar o nome do arquivo .idb. Consulte [/GM (habilitar mínimo recriar) de manual](../build/reference/gm-enable-minimal-rebuild.md) para obter mais informações.|  
|. idl|Compilando|Um arquivo de linguagem de definição de interface. Consulte [arquivo IDL (Interface Definition)](http://msdn.microsoft.com/library/windows/desktop/aa378712) no SDK do Windows para obter mais informações.|  
|. ilk|Vinculação|Arquivo de vínculo incremental. Consulte [/incremental](../build/reference/incremental-link-incrementally.md) para obter mais informações.|  
|. map|Vinculação|Um arquivo de texto que contém informações de vinculador. Use o [/Fm](../build/reference/fm-name-mapfile.md) opção de compilador para nomear o arquivo de mapa. Consulte [/MAPEAR](../build/reference/map-generate-mapfile.md) para obter mais informações.|  
|.mfcribbon ms|Recurso|Um arquivo de recurso que contém o código XML que define os atributos, botões e controles da faixa de opções. Para obter mais informações, consulte [Designer da faixa de opções (MFC)](../mfc/ribbon-designer-mfc.md).|  
|. obj, .o||Arquivos de objeto compilado, mas não vinculada.|  
|. pch|Depurar|Arquivo de cabeçalho pré-compilado.|  
|RC,. RC2|Recurso|[Arquivos de script de recurso](../windows/working-with-resource-files.md) para gerar recursos.|  
|. SBR|Compilando|Arquivo intermediário do navegador de fonte. O arquivo de entrada para [BSCMAKE](../build/reference/bscmake-options.md).|  
|.sln|Solução|O [solução](http://msdn.microsoft.com/en-us/a45c299d-69f5-4b67-879d-1383417df0a7) arquivo.|  
|.suo|Solução|O arquivo de opções de solução.|  
|. txt|Recurso|Um arquivo de texto, geralmente o arquivo "Leiame".|  
|.VAP|Projeto|Um arquivo de projeto do Visual Studio Analyzer.|  
|vbg|Solução|Um arquivo de grupo de projeto compatível.|  
|. vbp, .vip,. vbproj|Projeto|O arquivo de projeto do Visual Basic.|  
|.vcxitems|Projeto|Itens de projeto para o compartilhamento de arquivos de código entre vários projetos do C++ compartilhado. Consulte [arquivos de projeto e Makefiles](../ide/project-and-solution-files.md) para obter mais informações.|
|. vcxproj|Projeto|O arquivo de projeto do Visual C++. Consulte [arquivos de projeto e Makefiles](../ide/project-and-solution-files.md) para obter mais informações.|  
|. vcxproj.filters|Projeto|Quando o Gerenciador de soluções é usado para adicionar um arquivo a um projeto, o arquivo de filtros define onde na exibição de árvore do Gerenciador de soluções de arquivo é adicionado, com base em sua extensão de nome de arquivo.|  
|. vdproj|Projeto|O arquivo de projeto de implantação do Visual Studio.|  
|. vmx|Projeto|O arquivo de projeto de macro.|  
|.VUP|Projeto|O arquivo de projeto do utilitário.|  
  
 Para obter informações sobre outros arquivos associados com o Visual Studio, consulte [tipos de arquivo e extensões de arquivo no Visual Studio .NET](/visualstudio/ide/reference/project-and-solution-file-types).  
  
 Arquivos de projeto são organizados em pastas no Gerenciador de soluções. Visual C++ cria uma pasta para arquivos de origem, arquivos de cabeçalho e arquivos de recurso, mas você pode reorganizar essas pastas ou criar novos. Você pode usar pastas para organizar os clusters explicitamente lógicos dos arquivos dentro da hierarquia de um projeto. Por exemplo, você pode criar pastas para conter todos os seus arquivos de origem da interface de usuário, ou especificações, documentação ou conjuntos de testes. Todos os nomes de pasta de arquivo devem ser exclusivos.  
  
 Quando você adiciona um item a um projeto, você adicionar o item a todas as configurações para o projeto, independentemente de estarem ou não o item é compilável. Por exemplo, se você tiver um projeto chamado MyProject, adicionar um item adiciona a ambas as configurações de projeto Debug e Release.  
  
## <a name="see-also"></a>Consulte também  
 [Criando e gerenciando projetos do Visual C++](../ide/creating-and-managing-visual-cpp-projects.md)   
 [Tipos de projeto do Visual C++](../ide/visual-cpp-project-types.md)   
 [Suporte do assistente para outros idiomas](../ide/wizard-support-for-other-languages.md)