---
title: no_smart_pointers | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-tools
ms.topic: reference
f1_keywords:
- no_search_pointers
dev_langs:
- C++
helpviewer_keywords:
- no_smart_pointers attribute
ms.assetid: d69dd71e-08a8-4446-a3d0-a062dc29cb17
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 8e4503ab027589f54c5b5bce60dc405a570dcc59
ms.sourcegitcommit: d55ac596ba8f908f5d91d228dc070dad31cb8360
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/07/2018
ms.locfileid: "33849685"
---
# <a name="nosmartpointers"></a>no_smart_pointers
**Específicas do C++**  
  
 Suprime a criação de ponteiros inteligentes para todas as interfaces na biblioteca de tipos.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
no_smart_pointers  
```  
  
## <a name="remarks"></a>Comentários  
 Por padrão, quando você usa `#import`, consegue uma declaração de ponteiro inteligente em todas as interfaces na biblioteca de tipos. Esses ponteiros inteligentes são do tipo [com_ptr_t classe](../cpp/com-ptr-t-class.md).  
  
 **TÉRMINO específicas do C++**  
  
## <a name="see-also"></a>Consulte também  
 [atributos de #import](../preprocessor/hash-import-attributes-cpp.md)   
 [#import diretiva](../preprocessor/hash-import-directive-cpp.md)