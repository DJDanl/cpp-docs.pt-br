---
title: 'Comptr:: Operator operador = | Microsoft Docs'
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords: client/Microsoft::WRL::ComPtr::operator=
dev_langs: C++
helpviewer_keywords: operator= operator
ms.assetid: 1a0c2752-f7d8-4819-9443-07b88b69ef02
caps.latest.revision: "3"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 30f04bdfe7b508bf83e34992fefdcb10c58b4655
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="comptroperator-operator"></a>Operador ComPtr::operator=
Atribui um valor para o ComPtr atual.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
WRL_NOTHROW ComPtr& operator=(  
   decltype(__nullptr)  
);  
WRL_NOTHROW ComPtr& operator=(  
   _In_opt_ T *other  
);  
template <  
   typename U  
>  
WRL_NOTHROW ComPtr& operator=(  
   _In_opt_ U *other  
);  
WRL_NOTHROW ComPtr& operator=(  
   const ComPtr &other  
);  
template<  
   class U  
>  
WRL_NOTHROW ComPtr& operator=(  
   const ComPtr<U>& other  
);  
WRL_NOTHROW ComPtr& operator=(  
   _Inout_ ComPtr &&other  
);  
template<  
   class U  
>  
WRL_NOTHROW ComPtr& operator=(  
   _Inout_ ComPtr<U>&& other  
);  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `U`  
 Uma classe.  
  
 `other`  
 Uma referência a um tipo ou ComPtr outro ponteiro, referência ou rvalue.  
  
## <a name="return-value"></a>Valor de retorno  
 Uma referência para o ComPtr atual.  
  
## <a name="remarks"></a>Comentários  
 A primeira versão desse operador atribui um valor vazio para o ComPtr atual.  
  
 Na segunda versão, se o ponteiro de interface de atribuição não é o mesmo que o ponteiro de interface ComPtr atual, o segundo ponteiro de interface é atribuído a ComPtr atual.  
  
 Na terceira versão, o ponteiro de interface de atribuição é atribuído para o ComPtr atual.  
  
 Na quarta versão, se o ponteiro de interface do valor de atribuição não é o mesmo que o ponteiro de interface ComPtr atual, o segundo ponteiro de interface é atribuído a ComPtr atual.  
  
 A versão do quinto é um operador de cópia; uma referência a um ComPtr é atribuída para o ComPtr atual.  
  
 A versão do sexto é um operador de cópia que usa mover semântica; uma referência de rvalue para um ComPtr se qualquer tipo é estático convertido e, em seguida, atribuído para o ComPtr atual.  
  
 A versão do sétima é um operador de cópia que usa mover semântica; uma referência de rvalue para um ComPtr do tipo `U` é estático, em seguida, converter e atribuído ao ComPtr atual.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** client.h  
  
 **Namespace:** Microsoft:: wrl  
  
## <a name="see-also"></a>Consulte também  
 [Classe ComPtr](../windows/comptr-class.md)