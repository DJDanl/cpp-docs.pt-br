---
title: "S&#237;mbolos: Identificadores de recursos | Microsoft Docs"
ms.custom: ""
ms.date: "12/14/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
f1_keywords: 
  - "vc.editors.symbol.identifiers"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "símbolos, identificadores de recurso"
  - "símbolos, criando"
  - "símbolos de recurso"
  - "símbolos, edição"
  - "editores de recursos, símbolos de recurso"
ms.assetid: 8fccc09a-0237-4a65-b9c4-57d60c59e324
caps.latest.revision: 13
caps.handback.revision: 9
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# S&#237;mbolos: Identificadores de recursos
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Um símbolo é um identificador de recurso \(ID\) que consiste em duas partes: uma cadeia de texto \(nome de símbolo\) mapeada para um valor inteiro \(valor de símbolo\). Por exemplo:  
  
```  
IDC_EDITNAME = 5100  
```  
  
 Nomes de símbolos são geralmente denominados identificadores.  
  
 Símbolos fornecem uma maneira descritiva de como fazer referência a recursos e objetos de interface do usuário, no seu código\-fonte e enquanto estiver trabalhando com eles nos editores de recursos. Você pode exibir e manipular símbolos em um local conveniente usando o [caixa de diálogo símbolos de recurso](../windows/viewing-resource-symbols.md).  
  
 Quando você cria um novo recurso ou objeto de recurso, o [editores de recursos](../mfc/resource-editors.md) forneça um nome padrão para o recurso, por exemplo, `IDC_RADIO1`, e atribuir um valor a ela. A definição de mais valor name é armazenada no arquivo Resource.h.  
  
> [!NOTE]
>  Quando você estiver copiando recursos ou objetos de recursos de um arquivo. RC para outro, Visual C\+\+ pode alterar o recurso transferido símbolo valor, ou nome de símbolo e, para evitar conflitos com nomes de símbolos ou valores no arquivo existente.  
  
 À medida que seu aplicativo aumenta em tamanho e sofisticação, aumenta o número de recursos e símbolos. Grandes números de símbolos espalhados por vários arquivos de rastreamento pode ser difícil. O [caixa de diálogo símbolos de recurso](../windows/resource-symbols-dialog-box.md) simplifica o gerenciamento de símbolo, oferecendo uma ferramenta central por meio do qual você pode:  
  
-   [Símbolos de recurso de exibição](../windows/viewing-resource-symbols.md)  
  
-   [Criar novos símbolos](../windows/creating-new-symbols.md)  
  
-   [Alterar símbolos não atribuídos](../Topic/Changing%20Unassigned%20Symbols.md)  
  
-   [Excluir símbolos não atribuídos](../windows/deleting-unassigned-symbols.md)  
  
-   [Abra o Editor de recursos para um determinado símbolo](../Topic/Opening%20the%20Resource%20Editor%20for%20a%20Given%20Symbol.md)  
  
-   [Alterar um símbolo ou um nome de símbolo \(ID\)](../windows/changing-a-symbol-or-symbol-name-id.md)  
  
-   [Altere o valor numérico do símbolo](../windows/changing-a-symbol-s-numeric-value.md)  
  
-   [Alterar os nomes dos arquivos de cabeçalho de símbolo](../windows/changing-the-names-of-symbol-header-files.md)  
  
-   [Incluir compartilhados \(somente leitura\) ou calculados símbolos](../windows/including-shared-read-only-or-calculated-symbols.md)  
  
-   [Exibir IDs de símbolo predefinido](../windows/predefined-symbol-ids.md)  
  
 Para obter informações sobre como adicionar recursos a projetos gerenciados, consulte [recursos em aplicativos](../Topic/Resources%20in%20Desktop%20Apps.md) no *Guia do desenvolvedor do .NET Framework.* Para obter informações sobre como adicionar manualmente os arquivos de recurso para projetos gerenciados, acessar recursos, exibir recursos estáticos e atribuir cadeias de caracteres de recursos a propriedades, consulte [passo a passo: Localizando Windows Forms](http://msdn.microsoft.com/pt-br/9a96220d-a19b-4de0-9f48-01e5d82679e5) e [Walkthrough: Using Resources for Localization with ASP.NET](../Topic/Walkthrough:%20Using%20Resources%20for%20Localization%20with%20ASP.NET.md).  
  
## Requisitos  
 Win32  
  
## Consulte também  
 [Como procurar símbolos em recursos](../windows/how-to-search-for-symbols-in-resources.md)   
 [Editores de recursos](../mfc/resource-editors.md)   
 [Arquivos de recursos](../mfc/resource-files-visual-studio.md)