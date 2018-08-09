---
title: 'Método WeakReference:: resolve | Microsoft Docs'
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
ms.openlocfilehash: fe78f8644768563507f98157ac859993776d7fe9
ms.sourcegitcommit: 37a10996022d738135999cbe71858379386bab3d
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/08/2018
ms.locfileid: "39646196"
---
# <a name="weakreferenceresolve-method"></a>Método WeakReference::Resolve
Oferece suporte a infraestrutura do WRL e não se destina a ser usado diretamente do seu código.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
STDMETHOD(Resolve)  
   (REFIID riid,   
   _Deref_out_opt_ IInspectable **ppvObject  
);  
```  
  
### <a name="parameters"></a>Parâmetros  
 *riid*  
 Uma ID de interface.  
  
 *ppvObject*  
 Quando essa operação for concluída, uma cópia da referência forte atual se a contagem de referência forte for diferente de zero.  
  
## <a name="return-value"></a>Valor de retorno  
  
-   S_OK se essa operação for bem-sucedida e a contagem de referência forte é zero. O *ppvObject* parâmetro for definido como **nullptr**.  
  
-   S_OK se essa operação for bem-sucedida e a contagem de referência forte é diferente de zero. O *ppvObject* parâmetro for definido como a referência forte.  
  
-   Caso contrário, um HRESULT que indica o motivo pelo qual esta operação falhou.  
  
## <a name="remarks"></a>Comentários  
 Define o ponteiro especificado para o valor atual de referência forte se a contagem de referência forte for diferente de zero.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** Implements. h  
  
 **Namespace:** Microsoft::WRL::Details  
  
## <a name="see-also"></a>Consulte também  
 [WeakReference Class1](../windows/weakreference-class1.md)   
 [Namespace Microsoft::WRL::Details](../windows/microsoft-wrl-details-namespace.md)