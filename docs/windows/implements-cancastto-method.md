---
title: 'Método: cancastto | Microsoft Docs'
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: reference
f1_keywords:
- implements/Microsoft::WRL::Implements::CanCastTo
dev_langs:
- C++
helpviewer_keywords:
- CanCastTo method
ms.assetid: a8e85c7d-4dcd-446d-bebc-a97da46ce44a
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 4fd6e6736c74e1ce895031e17c1d5268eb4ce646
ms.sourcegitcommit: d55ac596ba8f908f5d91d228dc070dad31cb8360
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/08/2018
ms.locfileid: "33877067"
---
# <a name="implementscancastto-method"></a>Método Implements::CanCastTo
Obtém um ponteiro para a interface especificada.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
__forceinline HRESULT CanCastTo(  
   REFIID riid,  
   _Deref_out_ void **ppv  
);  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `riid`  
 Uma referência a uma ID de interface.  
  
 `ppv`  
 Se for bem-sucedido, um ponteiro para a interface especificada pelo `riid`.  
  
## <a name="return-value"></a>Valor de retorno  
 S_OK se bem-sucedido; Caso contrário, o HRESULT que indica o erro, como E_NOINTERFACE.  
  
## <a name="remarks"></a>Comentários  
 Isso é uma função auxiliar interno que executa uma operação de QueryInterface.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** implements.h  
  
 **Namespace:** Microsoft::WRL  
  
## <a name="see-also"></a>Consulte também  
 [Estrutura Implements](../windows/implements-structure.md)