---
title: 'Método WeakReference:: | Microsoft Docs'
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: reference
f1_keywords:
- implements/Microsoft::WRL::Details::WeakReference::Resolve
dev_langs:
- C++
helpviewer_keywords:
- Resolve method
ms.assetid: fc65a4b7-48a0-4d64-a793-37f566fdd8e7
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: dccdf7554f8d102230bedc18231feb74625d621b
ms.sourcegitcommit: d55ac596ba8f908f5d91d228dc070dad31cb8360
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/08/2018
ms.locfileid: "33890467"
---
# <a name="weakreferenceresolve-method"></a>Método WeakReference::Resolve
Oferece suporte à infraestrutura WRL e não se destina a ser usado diretamente no seu código.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
  
STDMETHOD(Resolve)  
   (REFIID riid,   
   _Deref_out_opt_ IInspectable **ppvObject  
);  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `riid`  
 Uma ID de interface.  
  
 `ppvObject`  
 Quando essa operação for concluída, uma cópia da referência forte atual se a contagem de referência forte é diferente de zero.  
  
## <a name="return-value"></a>Valor de retorno  
  
-   S_OK se essa operação for bem-sucedida e a contagem de referência forte é zero. O parâmetro `ppvObject` é definido como `nullptr`.  
  
-   S_OK se essa operação for bem-sucedida e a contagem de referência forte é diferente de zero. O `ppvObject` parâmetro for definido como a referência forte.  
  
-   Caso contrário, o HRESULT que indica o motivo pelo qual esta operação falhou.  
  
## <a name="remarks"></a>Comentários  
 Define o ponteiro especificado para o valor de referência forte atual se a contagem de referência forte é diferente de zero.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** implements.h  
  
 **Namespace:** Microsoft::WRL::Details  
  
## <a name="see-also"></a>Consulte também  
 [WeakReference Class1](../windows/weakreference-class1.md)   
 [Namespace Microsoft::WRL::Details](../windows/microsoft-wrl-details-namespace.md)