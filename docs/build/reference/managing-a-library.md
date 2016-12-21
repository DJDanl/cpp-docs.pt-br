---
title: "Gerenciando uma biblioteca | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
f1_keywords: 
  - "VC.Project.VCLibrarianTool.IgnoreAllDefaultLibraries"
  - "VC.Project.VCLibrarianTool.AdditionalDependencies"
  - "VC.Project.VCLibrarianTool.RemoveObjects"
  - "VC.Project.VCLibrarianTool.LibraryPaths"
  - "VC.Project.VCLibrarianTool.OutputFile"
  - "VC.Project.VCLibrarianTool.IgnoreDefaultLibraryNames"
  - "VC.Project.VCLibrarianTool.AdditionalLibraryDirectories"
  - "VC.Project.VCLibrarianTool.ListContentsFile"
  - "VC.Project.VCLibrarianTool.ListContents"
  - "VC.Project.VCLibrarianTool.SubSystemVersion"
  - "VC.Project.VCLibrarianTool.IgnoreDefaultLibraryName"
  - "VC.Project.VCLibrarianTool.SubSystem"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Opção /CONVERT (gerenciador de biblioteca)"
  - "Opção /LIBPATH (gerenciador de biblioteca)"
  - "Opção /LINK50COMPAT (gerenciador de biblioteca)"
  - "Opção /LIST (gerenciador de biblioteca)"
  - "Opção /OUT (gerenciador de biblioteca)"
  - "Opção /REMOVE (gerenciador de biblioteca)"
  - "Opção /SUBSYSTEM (gerenciador de biblioteca)"
  - "opção de gerenciador de biblioteca CONVERT"
  - "opção de gerenciador de biblioteca -CONVERT"
  - "LIB [C++], gerenciando bibliotecas COFF"
  - "opção de gerenciador de biblioteca LIBPATH"
  - "opção de gerenciador de biblioteca -LIBPATH"
  - "Opção LINK50COMPAT (gerenciador de biblioteca)"
  - "opção de gerenciador de biblioteca -LINK50COMPAT"
  - "opção de gerenciador de biblioteca LIST"
  - "opção de gerenciador de biblioteca -LIST"
  - "arquivos de objeto"
  - "arquivos de objeto, criando e modificando"
  - "opção de gerenciador de biblioteca OUT"
  - "opção de gerenciador de biblioteca -OUT"
  - "opção de gerenciador de biblioteca REMOVE"
  - "opção de gerenciador de biblioteca -REMOVE"
  - "opção de gerenciador de biblioteca SUBSYSTEM"
  - "opção de gerenciador de biblioteca -SUBSYSTEM"
ms.assetid: f56a8b85-fbdc-4c09-8d8e-00f0ffe1da53
caps.latest.revision: 7
caps.handback.revision: 7
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Gerenciando uma biblioteca
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

O modo padrão para o LIB é criar ou alterar uma biblioteca de objetos de COFF.  O LIB executado nesse modo quando você não especificar \/EXTRACT \(para copiar um objeto em um arquivo \/DEF\) ou \(para criar uma biblioteca de importação\).  
  
 Para criar uma biblioteca de objetos e\/ou bibliotecas, use a seguinte sintaxe:  
  
```  
LIB [options...] files...  
```  
  
 Este comando cria uma biblioteca de um ou mais *arquivos*  de entrada.  *Os arquivos* podem ser arquivos de objeto de COFF, arquivos de objeto de 32 bits de OMF, ou bibliotecas existentes de COFF.  O LIB cria uma biblioteca que contém todos os objetos nos arquivos especificados.  Se um arquivo de entrada seja um arquivo de objeto de 32 bits de OMF, o LIB convertê\-los em COFF antes de criar a biblioteca.  O LIB não pode aceitar um objeto de 32 bits de OMF que está em uma biblioteca criada pela versão de 16 bits de LIB.  Você deve usar o LIB de 16 bits para extrair o objeto; depois você pode usar o arquivo de objeto extraído como entrada para o LIB de 32 bits.  
  
 Por padrão, o LIB nomear o arquivo de saída usando o nome de base do primeiro objeto ou arquivo de biblioteca e a extensão .lib.  O arquivo de saída será colocado no diretório atual.  Se um arquivo já existir outro com o mesmo nome, o arquivo de saída substituir o arquivo existente.  Para preservar uma biblioteca existente, use a opção \/OUT especifique um nome para o arquivo de saída.  
  
 As opções a seguir se aplicam a criar e modificar uma biblioteca:  
  
 \/LIBPATH: `dir`  
 Substitui o caminho da biblioteca de ambiente.  Para obter detalhes, consulte a descrição da opção de [\/LIBPATH](../../build/reference/libpath-additional-libpath.md) de LINK.  
  
 \/LIST  
 Exibe informações sobre a biblioteca de saída para a saída padrão.  As saídas podem ser redirecionadas para um arquivo.  Você pode usar \/LIST para determinar o conteúdo de uma biblioteca existente sem modificá\-la.  
  
 \/NAME: *nome do arquivo*  
 Ao criar uma biblioteca de importação, especifique o nome da DLL da biblioteca de importação está sendo criada.  
  
 \/NODEFAULTLIB  
 Remove uma ou várias bibliotecas padrão da lista de bibliotecas que pesquisa ao resolver referências externas.  Consulte [\/NODEFAULTLIB](../../build/reference/nodefaultlib-ignore-libraries.md) para obter mais informações.  
  
 \/OUT: *nome do arquivo*  
 Substitui o nome do arquivo de saída padrão.  Por padrão, a biblioteca de saída é criada no diretório atual, com o nome base de primeiro biblioteca ou arquivo do objeto na linha de comando e na extensão .lib.  
  
 \/REMOVE: *objeto*  
 Omitir *o objeto* especificado da biblioteca de saída.  O LIB cria uma biblioteca de saída combinando todos os objetos \(se em arquivos ou em bibliotecas do objeto\), e excluindo todos os objetos especificados com \/REMOVE.  
  
 \/SUBSYSTEM: {CONSOLE &#124; EFI\_APPLICATION &#124; EFI\_BOOT\_SERVICE\_DRIVER &#124; EFI\_ROM &#124; EFI\_RUNTIME\_DRIVER &#124; NATIVO &#124; POSIX &#124; WINDOWS &#124; WINDOWSCE} \[, \[\#. \#\#\]\]  
 Informa ao sistema operacional como executar um programa criado vinculando à biblioteca de saída.  Para obter mais informações, consulte a descrição da opção de [\/SUBSYSTEM](../../build/reference/subsystem-specify-subsystem.md) de LINK.  
  
 As opções de LIB especificadas na linha de comando não diferenciam maiúsculas de minúsculas.  
  
 Você pode usar o LIB para executar as seguintes tarefas de gerenciamento: biblioteca\-  
  
-   Para adicionar objetos a uma biblioteca, especifique o nome de arquivo da biblioteca existente e os nomes de arquivo para novos objetos.  
  
-   Para combinar bibliotecas, especifique os nomes do arquivo de biblioteca.  Você pode adicionar objetos e para combinar bibliotecas com um único LIB comando.  
  
-   Para substituir um membro de biblioteca com um novo objeto, especifique a biblioteca que contém o objeto do membro a ser substituídos e o nome do novo objeto \(ou biblioteca que contém o\).  Quando um objeto que tem o mesmo nome existir em mais de um arquivo de entrada, o LIB coloca o objeto do último especificado no comando de LIB na biblioteca de saída.  Quando você substituir um membro de biblioteca, especifique o novo objeto ou biblioteca após a biblioteca que contém o objeto antigo.  
  
-   Para excluir um membro de uma biblioteca, use a opção do \/REMOVE.  O LIB processa todas as especificações de \/REMOVE após a combinação de todos os objetos de entrada, independentemente da ordem de linha de comando.  
  
> [!NOTE]
>  Você não pode excluir um membro e extrair\-lo em um arquivo na mesma etapa.  Primeiro você deve extrair o objeto do membro usando \/EXTRACT, executa no LIB que usa novamente \/REMOVE.  Esse comportamento é diferente do LIB de 16 bits \(para bibliotecas de OMF\) fornecido em outros produtos da Microsoft.  
  
## Consulte também  
 [Referência LIB](../../build/reference/lib-reference.md)