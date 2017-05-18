---
title: _SECURE_SCL | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-standard-libraries
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- _SECURE_SCL
dev_langs:
- C++
helpviewer_keywords:
- _SECURE_SCL
ms.assetid: 4ffbc788-cc12-4c6a-8cd7-490081675086
caps.latest.revision: 10
author: corob-msft
ms.author: corob
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
ms.translationtype: Machine Translation
ms.sourcegitcommit: 9e2bfb1095c28ea3592c5af2b89cb2fbeddcb60c
ms.openlocfilehash: f3712b4417c0fed972d9a20b6d82479561cce4b0
ms.contentlocale: pt-br
ms.lasthandoff: 02/25/2017

---
# <a name="securescl"></a>_SECURE_SCL
  
Substituído por [_ITERATOR_DEBUG_LEVEL](../standard-library/iterator-debug-level.md), essa macro define se os [Iteradores verificados](../standard-library/checked-iterators.md) estão habilitados. Por padrão, a depuração de iterador está habilitada em builds de depuração e desabilitado em builds de varejo.  
  
> [!IMPORTANT]
> O uso direto da macro `_SECURE_SCL` foi preterido. Em vez disso, use `_ITERATOR_DEBUG_LEVEL` para controlar configurações do iterador verificado. Para obter mais informações, consulte [_ITERATOR_DEBUG_LEVEL](../standard-library/iterator-debug-level.md).  
  
## <a name="remarks"></a>Comentários  
  
Quando iteradores verificados estão habilitados, o uso de um iterador não seguro causa um erro em tempo de execução e o programa é encerrado. Para habilitar os iteradores verificados, defina `_ITERATOR_DEBUG_LEVEL` como 1 ou 2. Isso é equivalente a configurar `_SECURE_SCL` como 1 ou habilitado:  
  
```  
#define _ITERATOR_DEBUG_LEVEL 1  
```  
  
Para desabilitar os iteradores verificados, defina `_ITERATOR_DEBUG_LEVEL` como 0. Isso é equivalente a configurar `_SECURE_SCL` como 0 ou desabilitado:  
  
```  
#define _ITERATOR_DEBUG_LEVEL 0  
```  
  
Para obter informações sobre como desabilitar avisos sobre iteradores verificados, consulte [_SCL_SECURE_NO_WARNINGS](../standard-library/scl-secure-no-warnings.md).  
  
## <a name="see-also"></a>Consulte também  
[_ITERATOR_DEBUG_LEVEL](../standard-library/iterator-debug-level.md)   
[Iteradores verificados](../standard-library/checked-iterators.md)   
[Suporte ao iterador de depuração](../standard-library/debug-iterator-support.md)   
[Bibliotecas seguras: Biblioteca Padrão C++](../standard-library/safe-libraries-cpp-standard-library.md)


