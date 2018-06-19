---
title: 'Método: Setunknown | Microsoft Docs'
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: reference
f1_keywords:
- implements/Microsoft::WRL::Details::WeakReference::SetUnknown
dev_langs:
- C++
helpviewer_keywords:
- SetUnknown method
ms.assetid: 5dddb9e3-a7c1-4195-8166-97c5ab6e972f
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 28b25645b21d3101e2f2b2004f02f29482320808
ms.sourcegitcommit: d55ac596ba8f908f5d91d228dc070dad31cb8360
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/08/2018
ms.locfileid: "33891002"
---
# <a name="weakreferencesetunknown-method"></a>Método WeakReference::SetUnknown
Oferece suporte à infraestrutura WRL e não se destina a ser usado diretamente no seu código.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
void SetUnknown(  
   _In_ IUnknown* unk  
);  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `unk`  
 Um ponteiro para o `IUnknown` interface de um objeto.  
  
## <a name="remarks"></a>Comentários  
 Define a referência forte do atual `WeakReference` objeto para o ponteiro de interface especificado.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** implements.h  
  
 **Namespace:** Microsoft::WRL::Details  
  
## <a name="see-also"></a>Consulte também
[Classe WeakReference](../windows/weakreference-class1.md)  
 [Namespace Microsoft::WRL::Details](../windows/microsoft-wrl-details-namespace.md)