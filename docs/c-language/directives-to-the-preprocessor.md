---
title: "Diretivas para o pré-processador | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-language
ms.tgt_pltfrm: 
ms.topic: article
dev_langs:
- C++
ms.assetid: adc6251e-cf6b-4508-bdbb-55f446c838d3
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 764bfd086612a10076e5c4800768b7b850ddbc7e
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="directives-to-the-preprocessor"></a>Diretivas para o pré-processador
Uma "política" instrui o pré-processador C a realizar uma ação específica no texto do programa antes da compilação. As [Diretivas para o pré-processador](../preprocessor/preprocessor-directives.md) são totalmente descritas na *Referência de pré-processador*. Este exemplo usa a política de pré-processador `#define`:  
  
```  
#define MAX 100  
```  
  
 Esta instrução determina que o compilador substitua cada ocorrência de `MAX` por `100` antes da compilação. As políticas de pré-processador do compilador C são:  
  
|#define|#endif|#ifdef|#line|  
|--------------|-------------|-------------|------------|  
|`#elif`|`#error`|**#ifndef**|**#pragma**|  
|`#else`|`#if`|`#include`|`#undef`|  
  
## <a name="see-also"></a>Consulte também  
 [Arquivos e programas de origem](../c-language/source-files-and-source-programs.md)