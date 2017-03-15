---
title: "Diretivas para o pré-processador | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: article
dev_langs:
- C++
ms.assetid: adc6251e-cf6b-4508-bdbb-55f446c838d3
caps.latest.revision: 7
author: mikeblome
ms.author: mblome
manager: ghogen
translation.priority.ht:
- cs-cz
- de-de
- es-es
- fr-fr
- it-it
- ja-jp
- ko-kr
- pl-pl
- pt-br
- ru-ru
- tr-tr
- zh-cn
- zh-tw
translationtype: Human Translation
ms.sourcegitcommit: a937c9d083a7e4331af63323a19fb207142604a0
ms.openlocfilehash: 0c3e8919083d3f5f3ab6345de0a2a6817b93205e
ms.lasthandoff: 02/25/2017

---
# <a name="directives-to-the-preprocessor"></a>Diretivas para o pré-processador
Uma "política" instrui o pré-processador C a realizar uma ação específica no texto do programa antes da compilação. As [Diretivas para o pré-processador](../preprocessor/preprocessor-directives.md) são totalmente descritas na *Referência de pré-processador*. Este exemplo usa a política de pré-processador `#define`:  
  
```  
#define MAX 100  
```  
  
 Esta instrução determina que o compilador substitua cada ocorrência de `MAX` por `100` antes da compilação. As políticas de pré-processador do compilador C são:  
  
|#define|#endif|#ifdef|#linha|  
|--------------|-------------|-------------|------------|  
|`#elif`|`#error`|**#ifndef**|**#pragma**|  
|`#else`|`#if`|`#include`|`#undef`|  
  
## <a name="see-also"></a>Consulte também  
 [Arquivos e programas de origem](../c-language/source-files-and-source-programs.md)
