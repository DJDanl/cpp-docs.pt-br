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
ms.openlocfilehash: 0afff1699a4c7a3a14f07967cfb5ba5727ba0320
ms.sourcegitcommit: 51f804005b8d921468775a0316de52ad39b77c3e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/02/2018
ms.locfileid: "39461556"
---
# <a name="comptroperatoramp-operator"></a>Comptr:: Operator&amp; operador
Libera a interface associada a este **ComPtr** do objeto e, em seguida, recupera o endereço da **ComPtr** objeto.  
  
## <a name="syntax"></a>Sintaxe  
  
```cpp  
Details::ComPtrRef<WeakRef> operator&()  
  
const Details::ComPtrRef<const WeakRef> operator&() const  
```  
  
## <a name="return-value"></a>Valor de retorno  
 Uma referência fraca ao atual **ComPtr**.  
  
## <a name="remarks"></a>Comentários  
 Esse método difere [comptr:: Getaddressof](../windows/comptr-getaddressof-method.md) em que esse método libera uma referência para o ponteiro de interface. Use `ComPtr::GetAddressOf` quando você exigir o endereço do ponteiro da interface, mas não deseja liberar essa interface.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** client.h  
  
 **Namespace:** Microsoft::WRL  
  
## <a name="see-also"></a>Consulte também  
 [Classe ComPtr](../windows/comptr-class.md)