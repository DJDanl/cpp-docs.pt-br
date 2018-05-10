---
title: 'Comptr:: Operator&amp; operador | Microsoft Docs'
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: reference
f1_keywords:
- client/Microsoft::WRL::ComPtr::operator&
dev_langs:
- C++
helpviewer_keywords:
- operator& operator
ms.assetid: 2d77fda6-f4b2-45c1-8a0e-fbc355013531
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 0bfe8cf9091d888c33420f53f584ca5509d80527
ms.sourcegitcommit: d55ac596ba8f908f5d91d228dc070dad31cb8360
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/08/2018
---
# <a name="comptroperatoramp-operator"></a>Comptr:: Operator&amp; operador
Libera a interface associada a esta `ComPtr` de objeto e, em seguida, recupera o endereço do `ComPtr` objeto.  
  
## <a name="syntax"></a>Sintaxe  
  
```cpp  
Details::ComPtrRef<WeakRef> operator&()  
  
const Details::ComPtrRef<const WeakRef> operator&() const  
```  
  
## <a name="return-value"></a>Valor de retorno  
 Uma referência fraca a atual `ComPtr`.  
  
## <a name="remarks"></a>Comentários  
 Esse método difere [: Getaddressof](../windows/comptr-getaddressof-method.md) em que esse método libera uma referência para o ponteiro de interface. Use `ComPtr::GetAddressOf` quando você exigir o endereço do ponteiro de interface, mas não deseja liberar essa interface.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** client.h  
  
 **Namespace:** Microsoft::WRL  
  
## <a name="see-also"></a>Consulte também  
 [Classe ComPtr](../windows/comptr-class.md)