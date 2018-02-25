---
title: _SECURE_SCL | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-standard-libraries
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- _SECURE_SCL
dev_langs:
- C++
helpviewer_keywords:
- _SECURE_SCL
ms.assetid: 4ffbc788-cc12-4c6a-8cd7-490081675086
caps.latest.revision: 
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: b49e101e944d4309a1d05e605a49452d9e17083c
ms.sourcegitcommit: d51ed21ab2b434535f5c1d553b22e432073e1478
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/23/2018
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

