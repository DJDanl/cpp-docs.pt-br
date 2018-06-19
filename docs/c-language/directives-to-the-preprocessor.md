---
title: Diretivas para o pré-processador | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-language
ms.topic: language-reference
dev_langs:
- C++
ms.assetid: adc6251e-cf6b-4508-bdbb-55f446c838d3
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 711e28a569cefbb500a98ab33cd22c527a5fd7c5
ms.sourcegitcommit: be2a7679c2bd80968204dee03d13ca961eaa31ff
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/03/2018
ms.locfileid: "32382897"
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