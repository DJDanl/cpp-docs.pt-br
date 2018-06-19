---
title: 'Método Implementshelper: | Microsoft Docs'
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: reference
f1_keywords:
- implements/Microsoft::WRL::Details::ImplementsHelper::CanCastTo
dev_langs:
- C++
helpviewer_keywords:
- CanCastTo method
ms.assetid: 9ae6fa17-d0b1-4e31-9ae5-da6ae4026e32
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 6de971f2de2421a2d7987dab30ba73fa2d225b15
ms.sourcegitcommit: d55ac596ba8f908f5d91d228dc070dad31cb8360
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/08/2018
ms.locfileid: "33876547"
---
# <a name="implementshelpercancastto-method"></a>Método ImplementsHelper::CanCastTo
Oferece suporte à infraestrutura WRL e não se destina a ser usado diretamente no seu código.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
  
HRESULT CanCastTo(  
   REFIID riid,  
   _Deref_out_ void **ppv  
);  
  
HRESULT CanCastTo(  
   _In_ const IID &iid,  
   _Deref_out_ void **ppv  
);  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `riid`  
 Referência a uma ID de interface.  
  
 `ppv`  
 Se essa operação for bem-sucedida, um ponteiro para a interface especificada pela `riid` ou `iid`.  
  
 `iid`  
 Referência a uma ID de interface.  
  
## <a name="return-value"></a>Valor de retorno  
 S_OK se bem-sucedido; Caso contrário, o HRESULT que indica o erro.  
  
## <a name="remarks"></a>Comentários  
 Obtém um ponteiro para a ID de interface especificado.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** implements.h  
  
 **Namespace:** Microsoft::WRL::Details  
  
## <a name="see-also"></a>Consulte também  
 [Estrutura ImplementsHelper](../windows/implementshelper-structure.md)   
 [Namespace Microsoft::WRL::Details](../windows/microsoft-wrl-details-namespace.md)