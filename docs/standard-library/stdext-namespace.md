---
title: Namespace stdext | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- stdext
dev_langs:
- C++
helpviewer_keywords:
- _DEFINE_DEPRECATED_HASH_CLASSES symbol
- stdext namespace
ms.assetid: 3e94fc89-0584-424f-bc09-081b73379545
caps.latest.revision: 10
author: corob-msft
ms.author: corob
manager: ghogen
translation.priority.ht:
- de-de
- es-es
- fr-fr
- it-it
- ja-jp
- ko-kr
- ru-ru
- zh-cn
- zh-tw
translation.priority.mt:
- cs-cz
- pl-pl
- pt-br
- tr-tr
translationtype: Machine Translation
ms.sourcegitcommit: 3f69f0c3176d2fbe19e11ce08c071691a72d858d
ms.openlocfilehash: 213b760a134a645a0b6552e4c3600fc4762b0bb2
ms.lasthandoff: 02/25/2017

---
# <a name="stdext-namespace"></a>Namespace stdext
Membros dos arquivos de cabeçalho [<hash_map>](../standard-library/hash-map.md) e [<hash_set>](../standard-library/hash-set.md) não são parte do padrão ISO C++. Portanto, esses tipos e membros foram movidos do `std` namespace para o namespace `stdext`, para permanecerem em conformidade com o padrão C++.  
  
 Ao compilar com [/Ze](../build/reference/za-ze-disable-language-extensions.md), que é o padrão, o compilador avisará sobre o uso de `std` para membros dos arquivos de cabeçalho <hash_map> e <hash_set>. Para desabilitar o aviso, use o pragma [warning](../preprocessor/warning.md).  
  
 Para fazer com que o compilador gere um erro para o uso de `std` para membros dos arquivos de cabeçalho <hash_map>e <hash_set> com **/Ze**, adicione a seguinte diretiva antes usar #include para quaisquer arquivos de cabeçalho da biblioteca padrão C++.  
  
```  
#define _DEFINE_DEPRECATED_HASH_CLASSES 0  
```  
  
 Ao compilar com **/Za**, o compilador gerará um erro.  
  
## <a name="see-also"></a>Consulte também  
 [Visão geral da biblioteca padrão C++](../standard-library/cpp-standard-library-overview.md)


