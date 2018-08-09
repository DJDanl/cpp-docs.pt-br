---
title: 'Método Implements:: cancastto | Microsoft Docs'
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
ms.openlocfilehash: a73aac6fb36270f0cd04615d9e530b29841850f8
ms.sourcegitcommit: 38af5a1bf35249f0a51e3aafc6e4077859c8f0d9
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/09/2018
ms.locfileid: "40010916"
---
# <a name="implementscancastto-method"></a>Método Implements::CanCastTo
Obtém um ponteiro para a interface especificada.  
  
## <a name="syntax"></a>Sintaxe  
  
```cpp  
__forceinline HRESULT CanCastTo(  
   REFIID riid,  
   _Deref_out_ void **ppv  
);  
```  
  
### <a name="parameters"></a>Parâmetros  
 *riid*  
 Uma referência a uma ID de interface.  
  
 *ppv*  
 Se for bem-sucedido, um ponteiro para a interface especificada por *riid*.  
  
## <a name="return-value"></a>Valor de retorno  
 S_OK se bem-sucedido; Caso contrário, um HRESULT que indica o erro, como E_NOINTERFACE.  
  
## <a name="remarks"></a>Comentários  
 Essa é uma função de auxiliar interno que executa uma operação de QueryInterface.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** Implements. h  
  
 **Namespace:** Microsoft::WRL  
  
## <a name="see-also"></a>Consulte também  
 [Estrutura Implements](../windows/implements-structure.md)