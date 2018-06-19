---
title: Função move | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: reference
f1_keywords:
- internal/Microsoft::WRL::Details::Move
dev_langs:
- C++
helpviewer_keywords:
- Move function
ms.assetid: c9525426-97e8-4d8c-9877-b689d8a0dc67
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 8da1a3c839add5d056674896b5a3c6a32145924f
ms.sourcegitcommit: d55ac596ba8f908f5d91d228dc070dad31cb8360
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/08/2018
ms.locfileid: "33876765"
---
# <a name="move-function"></a>Função Move
Oferece suporte à infraestrutura WRL e não se destina a ser usado diretamente no seu código.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
template<class T>  
inline typename RemoveReference<T>::Type&& Move(  
   _Inout_ T&& arg  
);  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `T`  
 O tipo do argumento.  
  
 `arg`  
 Um argumento para mover.  
  
## <a name="return-value"></a>Valor de retorno  
 Parâmetro `arg` após características de referência ou referência de rvalue, se houver, foi removido.  
  
## <a name="remarks"></a>Comentários  
 Move o argumento especificado de um local para outro.  
  
 Para obter mais informações, consulte o **mover semântica** seção [Declarador de referência Rvalue: & &](../cpp/rvalue-reference-declarator-amp-amp.md).  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** internal.h  
  
 **Namespace:** Microsoft::WRL::Details  
  
## <a name="see-also"></a>Consulte também  
 [Namespace Microsoft::WRL::Details](../windows/microsoft-wrl-details-namespace.md)