---
title: "/IMPORTS (DUMPBIN) | Microsoft Docs"
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
  - "/imports"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Opção /IMPORTS (dumpbin)"
  - "opção dumpbin IMPORTS"
  - "opção dumpbin -IMPORTS"
ms.assetid: 6a296216-2b1b-40f8-8736-cd4553a22456
caps.latest.revision: 7
caps.handback.revision: 7
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# /IMPORTS (DUMPBIN)
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

```  
/IMPORTS[:file]  
```  
  
 Esta opção exibe a lista da DLL \(ambos vinculados estaticamente e [atraso carregado](../../build/reference/linker-support-for-delay-loaded-dlls.md)\) que são importados para um arquivo executável ou DLL e qualquer pessoa importação de cada um desses DLL.  
  
 A especificação opcional de `file` permite especificar que as importações somente para que o DLL serão exibidas.  Por exemplo:  
  
```  
dumpbin /IMPORTS:msvcrt.dll  
```  
  
## Comentários  
 A saída exibida por esta opção são semelhantes a uma saída de [\/EXPORTS](../../build/reference/dash-exports.md) .  
  
 Somente a opção de DUMPBIN de [\/HEADERS](../../build/reference/headers.md) está disponível para uso em arquivos gerados com a opção do compilador de [\/GL](../../build/reference/gl-whole-program-optimization.md) .  
  
## Consulte também  
 [Opções de DUMPBIN](../../build/reference/dumpbin-options.md)