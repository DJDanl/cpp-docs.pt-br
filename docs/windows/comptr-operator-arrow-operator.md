---
title: 'Comptr:: Operator -&gt; operador | Microsoft Docs'
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: reference
f1_keywords:
- client/Microsoft::WRL::ComPtr::operator->
dev_langs:
- C++
helpviewer_keywords:
- operator-> operator
ms.assetid: 7b7faefd-d1e4-4f31-a77d-17a42e0d6b6a
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 1530f7998f2597aeb2fe46dba09f4844b471cd93
ms.sourcegitcommit: 37a10996022d738135999cbe71858379386bab3d
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/08/2018
ms.locfileid: "39644824"
---
# <a name="comptroperator-gt-operator"></a>Comptr:: Operator -&gt; operador
Recupera um ponteiro para o tipo especificado pelo parâmetro de modelo atual.  
  
## <a name="syntax"></a>Sintaxe  
  
```cpp  
WRL_NOTHROW Microsoft::WRL::Details::RemoveIUnknown<InterfaceType>* operator->() const;  
```  
  
## <a name="return-value"></a>Valor de retorno  
 Ponteiro para o tipo especificado pelo nome do tipo de modelo atual.  
  
## <a name="remarks"></a>Comentários  
 Essa função auxiliar remove causada pelo uso a macro STDMETHOD uma sobrecarga desnecessária. Essa função faz `IUnknown` tipos **privada** em vez de **virtual**.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** client.h  
  
 **Namespace:** Microsoft::WRL  
  
## <a name="see-also"></a>Consulte também  
 [Classe ComPtr](../windows/comptr-class.md)