---
title: "Constantes de matem&#225;tica | Microsoft Docs"
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
  - "c.constants"
dev_langs: 
  - "C++"
  - "C"
helpviewer_keywords: 
  - "Constante _USE_MATH_DEFINES"
  - "constantes, matemática"
  - "Constante M_1_PI"
  - "Constante M_2_PI"
  - "Constante M_2_SQRTPI"
  - "Constante M_E"
  - "Constante M_LN10"
  - "Constante M_LN2"
  - "Constante M_LOG10E"
  - "Constante M_LOG2E"
  - "Constante M_PI"
  - "Constante M_PI_2"
  - "Constante M_PI_4"
  - "Constante M_SQRT1_2"
  - "Constante M_SQRT2"
  - "constantes de matemática"
  - "Constante USE_MATH_DEFINES"
ms.assetid: db533c3f-6ae8-4520-9d35-c8fabbef3529
caps.latest.revision: 8
caps.handback.revision: 8
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Constantes de matem&#225;tica
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

## Sintaxe  
  
```  
#define _USE_MATH_DEFINES // for C++  
#include <cmath>  
  
#define _USE_MATH_DEFINES // for C  
#include <math.h>  
```  
  
## Comentários  
 Os seguintes símbolos são definidos para os valores das expressões indicadas:  
  
|Símbolo|Expressão|Valor|  
|-------------|---------------|-----------|  
|M\_E|e|2.71828182845904523536|  
|M\_LOG2E|log2 \(e\)|1.44269504088896340736|  
|M\_LOG10E|log10 \(e\)|0.434294481903251827651|  
|M\_LN2|ln \(2\)|0.693147180559945309417|  
|M\_LN10|ln \(10\)|2.30258509299404568402|  
|M\_PI|pi|3.14159265358979323846|  
|M\_PI\_2|pi\/2|1.57079632679489661923|  
|M\_PI\_4|pi\/4|0.785398163397448309616|  
|M\_1\_PI|1\/pi|0.318309886183790671538|  
|M\_2\_PI|2\/pi|0.636619772367581343076|  
|M\_2\_SQRTPI|2\/sqrt \(pi\)|1.12837916709551257390|  
|M\_SQRT2|SQRT \(2\)|1.41421356237309504880|  
|M\_SQRT1\_2|1\/sqrt \(2\)|0.707106781186547524401|  
  
 As constantes de matemática não são definidas no padrão C\/C\+\+.  Para usá\-las, você deve primeiro definir `_USE_MATH_DEFINES` e depois incluir o cmath ou o math.h.  
  
 O arquivo ATLComTime.h inclui math.h quando o projeto é o modo interno da versão.  Se você usar uma ou mais das constantes de matemática em um projeto que também inclui ATLComTime.h, você deve definir `_USE_MATH_DEFINES` antes que você inclua ATLComTime.h.  
  
## Consulte também  
 [Constantes globais](../c-runtime-library/global-constants.md)