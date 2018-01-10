---
title: 'Comptr:: Operator&amp; operador | Microsoft Docs'
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords: client/Microsoft::WRL::ComPtr::operator&
dev_langs: C++
helpviewer_keywords: operator& operator
ms.assetid: 2d77fda6-f4b2-45c1-8a0e-fbc355013531
caps.latest.revision: "5"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: cc5234f10a16141fd91193d634f0d306886aff71
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
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
  
 **Namespace:** Microsoft:: wrl  
  
## <a name="see-also"></a>Consulte também  
 [Classe ComPtr](../windows/comptr-class.md)