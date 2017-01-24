---
title: "Macros de comando e op&#231;&#245;es | Microsoft Docs"
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
  - "macros de comando em NMAKE"
  - "Macros , macros de comando"
  - "Macros , macros de opção"
  - "macros de opção"
ms.assetid: 50dff03c-0dc3-4a8a-9a17-57e0e4ea9bac
caps.latest.revision: 7
caps.handback.revision: 7
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Macros de comando e op&#231;&#245;es
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Macros de comando são predefinidos para produtos do Microsoft.  Macros das opções representam opções para esses produtos e são definidos por padrão.  Ambos são usados em regras de inferência predefinidas e podem ser usados em blocos de descrição ou as regras de inferência definidos pelo usuário.  Macros de comando podem ser redefinidos para representar a parte ou a qualquer linha de comando, incluindo opções.  Macros das opções gerenciem uma cadeia de caracteres nula se deixado indefinido.  
  
|O Microsoft|Macro de comando|Definido como|Opções macro|  
|-----------------|----------------------|-------------------|------------------|  
|Macro assembler|**AS**|ml|**AFLAGS**|  
|Compilador básico|**BC**|bc|**BFLAGS**|  
|Compilador C|**CC**|cl|**CFLAGS**|  
|Compilador C\+\+|**CPP**|cl|**CPPFLAGS**|  
|Compilador C\+\+|**CXX**|cl|**CXXFLAGS**|  
|Compilador de recursos|**RC**|rc|**RFLAGS**|  
  
## Consulte também  
 [Macros NMAKE especiais](../build/special-nmake-macros.md)