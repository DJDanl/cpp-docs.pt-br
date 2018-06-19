---
title: 'Weakref:: Operator&amp; operador | Microsoft Docs'
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: reference
f1_keywords:
- client/Microsoft::WRL::WeakRef::operator&
dev_langs:
- C++
helpviewer_keywords:
- operator& operator
ms.assetid: 900afb73-3801-4d08-9b41-2e6a62011ccd
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 1c8221b405618b1879f4e4c865115a227eb09857
ms.sourcegitcommit: d55ac596ba8f908f5d91d228dc070dad31cb8360
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/08/2018
ms.locfileid: "33890094"
---
# <a name="weakrefoperatoramp-operator"></a>Weakref:: Operator&amp; operador
Retorna um objeto ComPtrRef que representa o objeto WeakRef atual.  
  
## <a name="syntax"></a>Sintaxe  
  
```cpp  
Details::ComPtrRef<WeakRef> operator&() throw()  
```  
  
## <a name="return-value"></a>Valor de retorno  
 Um objeto ComPtrRef que representa o objeto WeakRef atual.  
  
## <a name="remarks"></a>Comentários  
 Este é um operador de auxiliar interno que não se destina a ser usada em seu código.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** client.h  
  
 **Namespace:** Microsoft::WRL  
  
## <a name="see-also"></a>Consulte também  
 [Classe WeakRef](../windows/weakref-class.md)