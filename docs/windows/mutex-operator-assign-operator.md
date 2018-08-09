---
title: 'Mutex:: Operator operador = | Microsoft Docs'
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: reference
f1_keywords:
- corewrappers/Microsoft::WRL::Wrappers::Mutex::operator=
dev_langs:
- C++
helpviewer_keywords:
- operator= operator
ms.assetid: 9b0ee206-a930-4fea-8dc0-1f79839e9d13
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 9ce42a1e14e3de77b8ac10c67a8f15b6ee3f080f
ms.sourcegitcommit: 38af5a1bf35249f0a51e3aafc6e4077859c8f0d9
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/09/2018
ms.locfileid: "40019950"
---
# <a name="mutexoperator-operator"></a>Operador Mutex::operator=
Atribui (se move) especificado **Mutex** objeto atual **Mutex** objeto.  
  
## <a name="syntax"></a>Sintaxe  
  
```cpp  
Mutex& operator=(  
   _Inout_ Mutex&& h  
);  
```  
  
### <a name="parameters"></a>Parâmetros  
 *h*  
 Uma referência rvalue para um **Mutex** objeto.  
  
## <a name="return-value"></a>Valor de retorno  
 Uma referência ao atual **Mutex** objeto.  
  
## <a name="remarks"></a>Comentários  
 Para obter mais informações, consulte o **mover semântica** seção [Declarador de referência Rvalue: & &](../cpp/rvalue-reference-declarator-amp-amp.md).  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** corewrappers. h  
  
 **Namespace:** Microsoft::WRL::Wrappers
 
 ## <a name="see-also"></a>Consulte também
 [Classe Mutex](../windows/mutex-class1.md)