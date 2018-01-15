---
title: _HAS_ITERATOR_DEBUGGING | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-standard-libraries
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords: _HAS_ITERATOR_DEBUGGING
dev_langs: C++
helpviewer_keywords: _HAS_ITERATOR_DEBUGGING
ms.assetid: 90077dbb-8a76-4963-83a6-29f4854007a8
caps.latest.revision: "7"
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 7c680338fa84fa0f00e01ea4612d07c851570a36
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="hasiteratordebugging"></a>_HAS_ITERATOR_DEBUGGING  
  
Substituída por [_ITERATOR_DEBUG_LEVEL](../standard-library/iterator-debug-level.md), esta macro define se o recurso de depuração do iterador está habilitado em um build de depuração. Por padrão, a depuração de iterador está habilitada em compilações de depuração e desabilitado em compilações comerciais. Para saber mais, consulte [Suporte ao iterador de depuração](../standard-library/debug-iterator-support.md).  
  
> [!IMPORTANT]
> O uso direto da macro `_HAS_ITERATOR_DEBUGGING` foi preterido. Em vez disso, use `_ITERATOR_DEBUG_LEVEL` para controlar configurações de depuração do iterador. Para obter mais informações, consulte [_ITERATOR_DEBUG_LEVEL](../standard-library/iterator-debug-level.md).  
  
## <a name="remarks"></a>Comentários  
Para habilitar a depuração do iterador em compilações de depuração, defina `_ITERATOR_DEBUG_LEVEL` como 2. Isso é equivalente a configurar `_HAS_ITERATOR_DEBUGGING` como 1 ou habilitado:  
  
```  
#define _ITERATOR_DEBUG_LEVEL 2  
```  
  
`_ITERATOR_DEBUG_LEVEL` não pode ser definido como 2 (e `_HAS_ITERATOR_DEBUGGING` não pode ser definido como 1) em compilações comerciais.  
  
Para desabilitar a depuração de iteradores em compilações de depuração, defina `_ITERATOR_DEBUG_LEVEL` como 0 ou 1. Isso é equivalente a configurar `_HAS_ITERATOR_DEBUGGING` como 0 ou desabilitado:  
  
```  
#define _ITERATOR_DEBUG_LEVEL 0  
```  
  
## <a name="see-also"></a>Consulte também  
 [_ITERATOR_DEBUG_LEVEL](../standard-library/iterator-debug-level.md)   
 [Suporte ao iterador de depuração](../standard-library/debug-iterator-support.md)   
 [Iteradores verificados](../standard-library/checked-iterators.md)   
 [Bibliotecas seguras: Biblioteca Padrão C++](../standard-library/safe-libraries-cpp-standard-library.md)

