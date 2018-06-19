---
title: 'Comptr:: Operator operador = | Microsoft Docs'
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: reference
f1_keywords:
- client/Microsoft::WRL::ComPtr::operator=
dev_langs:
- C++
helpviewer_keywords:
- operator= operator
ms.assetid: 1a0c2752-f7d8-4819-9443-07b88b69ef02
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: f4066db37de8a993802970784f09141352fef028
ms.sourcegitcommit: d55ac596ba8f908f5d91d228dc070dad31cb8360
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/08/2018
ms.locfileid: "33871195"
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
template <typename U>  
WRL_NOTHROW ComPtr& operator=(  
   _In_opt_ U *other  
);  
WRL_NOTHROW ComPtr& operator=(  
   const ComPtr &other  
);  
template<class U>  
WRL_NOTHROW ComPtr& operator=(  
   const ComPtr<U>& other  
);  
WRL_NOTHROW ComPtr& operator=(  
   _Inout_ ComPtr &&other  
);  
template<class U>  
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
  
 **Namespace:** Microsoft::WRL  
  
## <a name="see-also"></a>Consulte também  
 [Classe ComPtr](../windows/comptr-class.md)