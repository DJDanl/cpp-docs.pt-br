---
title: "Tipos de arquivo criados para projetos do Visual C++ | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "arquivos de cabeçalho C++, projetos do Visual C++"
  - "Controles ActiveX [C++], arquivos de ajuda"
  - "arquivos def"
  - "itens de projeto [C++], arquivos"
  - "Projetos C++ Visual, arquivos e diretórios"
  - "arquivos de recursos, criados pelo Assistente"
  - "arquivos [C++], extensões"
  - "Arquivos de ajuda para controles ActiveX"
  - "Projetos da Web [C++], adicionando itens"
  - "Arquivos .def"
  - "licenciando controles ActiveX"
ms.assetid: 2b0ee2e0-ae81-4185-9bb9-11da3c99a283
caps.latest.revision: 20
caps.handback.revision: 20
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Tipos de arquivo criados para projetos do Visual C++
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Este tópico descreve todos os tipos de arquivos que estão associados a projetos do Visual C\+\+ para aplicativos de área de trabalho clássicos. Os arquivos reais incluídos em seu projeto dependem do tipo de projeto e as opções selecionadas ao usar um assistente.  
  
-   [Arquivos de projeto e solução](../ide/project-and-solution-files.md)  
  
-   [Projetos CLR](../ide/files-created-for-clr-projects.md)  
  
-   [Programa ATL ou origem de controle e arquivos de cabeçalho](../ide/atl-program-or-control-source-and-header-files.md)  
  
-   [Programa MFC ou origem de controle e arquivos de cabeçalho](../ide/mfc-program-or-control-source-and-header-files.md)  
  
-   [Arquivos de cabeçalho pré\-compilado](../ide/precompiled-header-files.md)  
  
-   [Arquivos de recursos](../ide/resource-files-cpp.md)  
  
-   [Arquivos de ajuda \(WinHelp\)](../Topic/Help%20Files%20\(WinHelp\).md)  
  
-   [Arquivos de dica](../ide/hint-files.md)  
  
 Quando você [criar um projeto do Visual C\+\+](../ide/creating-desktop-projects-by-using-application-wizards.md), você pode criar uma nova solução, ou você pode adicionar um projeto a uma solução. Aplicativos não\-trivial geralmente são desenvolvidos com vários projetos em uma solução.  
  
 Os projetos geralmente produzem um executável ou uma DLL. Projetos podem ser dependentes entre si; durante o processo de compilação, o ambiente do Visual C\+\+ verifica as dependências dentro e entre projetos. Cada projeto tem código\-fonte principal e, dependendo do tipo de projeto, ele pode ter muitos outros arquivos que contém vários aspectos do projeto. O conteúdo desses arquivos é indicado pela extensão de arquivo. O ambiente de desenvolvimento do Visual Studio usa as extensões de arquivo para determinar como tratar o conteúdo do arquivo durante a compilação.  
  
 A tabela a seguir mostra os arquivos comuns em um projeto do Visual C\+\+ e identifica\-os com a extensão de arquivo.  
  
|Extensão de arquivo|Tipo|Conteúdo|  
|-------------------------|----------|--------------|  
|. asmx|Código\-fonte|Arquivo de implantação.|  
|. ASP|Código\-fonte|Arquivo do Active Server Page.|  
|.ATP|Projeto|Arquivo de projeto do modelo de aplicativo.|  
|. bmp,. dib,. gif,. jpg,. jpe,. PNG|Recurso|Arquivos de imagem geral.|  
|. bsc|Compilando|O arquivo de código do navegador.|  
|. cpp,. c|Código\-fonte|Arquivos de código fonte principal de seu aplicativo.|  
|cur|Recurso|Arquivo gráfico de bitmap de cursor.|  
|dbp|Projeto|Arquivo de projeto de banco de dados.|  
|. disco|Código\-fonte|O arquivo de documento de descoberta dinâmica. Lida com a descoberta de serviços Web XML.|  
|.exe,. dll|Projeto|Arquivos executáveis ou dynamic\-link library.|  
|. h|Código\-fonte|Um cabeçalho \(incluir\) arquivos.|  
|. htm,. HTML, .xsp,. asp,. htc,. HTA,. XML|Recurso|Arquivos comuns de Web.|  
|. HxC|Projeto|Arquivo de projeto de Ajuda.|  
|. ico|Recurso|Arquivo gráfico de bitmap de ícone.|  
|IDB|Compilando|O arquivo de estado, que contém informações de dependência entre arquivos de origem e definições de classe, que podem ser usadas pelo compilador durante a recompilação mínima e compilação incremental. Use o [\/Fd](../build/reference/fd-program-database-file-name.md) opção de compilador para especificar o nome do arquivo IDB. Consulte [\/Gm \(habilitar recompilação mínima\)](../build/reference/gm-enable-minimal-rebuild.md) para obter mais informações.|  
|. idl|Compilando|Um arquivo de linguagem de definição de interface. Consulte [arquivo de definição de Interface \(IDL\)](http://msdn.microsoft.com/library/windows/desktop/aa378712) no [!INCLUDE[winsdkshort](../atl/reference/includes/winsdkshort_md.md)] para obter mais informações.|  
|. ilk|Vinculação|Arquivo de link incremental. Consulte [\/incremental](../build/reference/incremental-link-incrementally.md) para obter mais informações.|  
|. map|Vinculação|Um arquivo de texto que contém informações do vinculador. Use o [\/Fm](../Topic/-Fm%20\(Name%20Mapfile\).md) opção de compilador para nomear o arquivo de mapa. Consulte [\/MAPEAR](../build/reference/map-generate-mapfile.md) para obter mais informações.|  
|.mfcribbon ms|Recurso|Um arquivo de recursos que contém o código XML que define os botões, controles e atributos na faixa de opções. Para obter mais informações, consulte [Designer da faixa de opções \(MFC\)](../mfc/ribbon-designer-mfc.md).|  
|. obj, .o||Arquivos de objeto compilados, mas não vinculado.|  
|. pch|Depurar|Arquivo de cabeçalho pré\-compilado.|  
|RC, .rc2|Recurso|[Arquivos de script de recurso](../mfc/working-with-resource-files.md) para gerar recursos.|  
|. SBR|Compilando|Arquivo intermediário do navegador de origem. O arquivo de entrada para [BSCMAKE](../Topic/BSCMAKE%20Options.md).|  
|. sln|Solução|O [solução](http://msdn.microsoft.com/pt-br/a45c299d-69f5-4b67-879d-1383417df0a7) arquivo.|  
|. suo|Solução|O arquivo de opções de solução.|  
|. txt|Recurso|Um arquivo de texto, geralmente o arquivo "readme".|  
|.VAP|Projeto|Um arquivo de projeto do Visual Studio Analyzer.|  
|vbg|Solução|Um arquivo de grupo de projeto compatível.|  
|. vbp, .vip,. vbproj|Projeto|O arquivo de projeto do Visual Basic.|  
|vcxproj|Projeto|O arquivo de projeto do Visual C\+\+. Consulte [arquivos de projeto e Makefiles](../ide/project-and-solution-files.md) para obter mais informações.|  
|. vcxproj.filters|Projeto|Quando o Gerenciador de soluções é usado para adicionar um arquivo a um projeto, o arquivo de filtros define onde no modo de exibição de árvore Solution Explorer o arquivo é adicionado, com base em sua extensão de nome de arquivo.|  
|. vdproj|Projeto|O arquivo de projeto de implantação do Visual Studio.|  
|VMX|Projeto|O arquivo de projeto de macro.|  
|.VUP|Projeto|O arquivo de projeto do utilitário.|  
  
 Para obter informações sobre outros arquivos associados com o Visual Studio, consulte [tipos de arquivo e extensões de arquivo no Visual Studio .NET](../Topic/Project%20and%20Solution%20File%20Types.md).  
  
 Arquivos de projeto são organizados em pastas no Solution Explorer. Visual C\+\+ cria uma pasta para arquivos de origem, arquivos de cabeçalho e arquivos de recurso, mas você pode reorganizar essas pastas ou criar novos. Você pode usar pastas para organizar clusters explicitamente lógicos dos arquivos dentro da hierarquia de um projeto. Por exemplo, você pode criar pastas para conter todos os seus arquivos de origem da interface de usuário, ou especificações, documentação ou conjuntos de testes. Todos os nomes de pasta de arquivo devem ser exclusivos.  
  
 Quando você adiciona um item a um projeto, você adicionar o item a todas as configurações para o projeto, independentemente se o item é compilável. Por exemplo, se você tiver um projeto chamado MyProject, adicionando um item adiciona a ambas as configurações de projeto Debug e Release.  
  
## Consulte também  
 [Criando e gerenciando projetos do Visual C\+\+](../ide/creating-and-managing-visual-cpp-projects.md)   
 [Tipos de projeto do Visual C\+\+](../ide/visual-cpp-project-types.md)   
 [Suporte do assistente para outros idiomas](../ide/wizard-support-for-other-languages.md)