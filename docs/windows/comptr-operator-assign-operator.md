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
ms.openlocfilehash: fac3a845ea7c512f5a7ccffdabdf67ce26029ff8
ms.sourcegitcommit: 51f804005b8d921468775a0316de52ad39b77c3e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/02/2018
ms.locfileid: "39466157"
---
# <a name="comptroperator-operator"></a>Operador ComPtr::operator=
Atribui um valor para a atual **ComPtr**.  
  
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
 *U*  
 Uma classe.  
  
 *other*  
 Um ponteiro, referência ou referência rvalue para um tipo ou de outro **ComPtr**.  
  
## <a name="return-value"></a>Valor de retorno  
 Uma referência ao atual **ComPtr**.  
  
## <a name="remarks"></a>Comentários  
 A primeira versão deste operador atribui um valor vazio para a atual **ComPtr**.  
  
 Na segunda versão, se o ponteiro de interface de atribuição não é o mesmo que o atual **ComPtr** ponteiro de interface, o segundo ponteiro de interface é atribuído ao atual **ComPtr**.  
  
 A terceira versão, o ponteiro de interface atribuir é atribuído ao atual **ComPtr**.  
  
 Na quarta versão, se o ponteiro de interface do valor de atribuição não é o mesmo que o atual **ComPtr** ponteiro de interface, o segundo ponteiro de interface é atribuído ao atual **ComPtr**.  
  
 A quinta versão é um operador de cópia; uma referência a um **ComPtr** é atribuído à atual **ComPtr**.  
  
 A versão do sexta é um operador de cópia que usa semântica; uma referência rvalue para um **ComPtr** se qualquer tipo for estático, converter e, em seguida, é atribuído ao atual **ComPtr**.  
  
 A versão do sétima é um operador de cópia que usa semântica; uma referência rvalue para um **ComPtr** do tipo *U* é estático convertido, em seguida e atribuído a atual **ComPtr**.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** client.h  
  
 **Namespace:** Microsoft::WRL  
  
## <a name="see-also"></a>Consulte também  
 [Classe ComPtr](../windows/comptr-class.md)