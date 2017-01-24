---
title: "Constantes de erro de matem&#225;tica | Microsoft Docs"
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
  - "_PLOSS"
  - "_UNDERFLOW"
  - "_TLOSS"
  - "_SING"
  - "_DOMAIN"
  - "_OVERFLOW"
dev_langs: 
  - "C++"
  - "C"
helpviewer_keywords: 
  - "Constante _DOMAIN"
  - "Constante _OVERFLOW"
  - "Constante _PLOSS"
  - "Constante _SING"
  - "Constante _TLOSS"
  - "Constante _UNDERFLOW"
  - "Constante DOMAIN"
  - "constantes de erro de matemática"
  - "Constante OVERFLOW"
  - "Constante PLOSS"
  - "Constante SING"
  - "Constante TLOSS"
  - "Constante UNDERFLOW"
ms.assetid: 4be933a6-674e-45a5-8ac9-090023542f5b
caps.latest.revision: 6
caps.handback.revision: 6
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Constantes de erro de matem&#225;tica
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

## Sintaxe  
  
```  
  
#include <math.h>  
  
```  
  
## Comentários  
 As rotinas matemática de biblioteca de tempo de execução podem gerar constantes de erro matemática.  
  
 Esses erros, descritos abaixo, correspondem aos tipos de exceção definidas em MATH.H e são retornados pela função de `_matherr` quando um erro de matemática ocorre.  
  
|Constante|Significado|  
|---------------|-----------------|  
|`_DOMAIN`|O argumento para a função é domínio externa da função.|  
|`_OVERFLOW`|O resultado é muito grande para ser representado no tipo de retorno de função.|  
|`_PLOSS`|Perda de significância parcial ocorreu.|  
|`_SING`|Singularidade de argumento: o argumento para a função tem o valor ilegal. \(Por exemplo, o valor 0 é passado para funcionar que requer o valor diferente de zero.\)|  
|`_TLOSS`|Perda de significância total ocorreu.|  
|`_UNDERFLOW`|O resultado é muito pequeno para ser representado.|  
  
## Consulte também  
 [\_matherr](../c-runtime-library/reference/matherr.md)   
 [Constantes globais](../c-runtime-library/global-constants.md)