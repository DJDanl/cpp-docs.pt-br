---
title: "Método Implementshelper: | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords: implements/Microsoft::WRL::Details::ImplementsHelper::CastToUnknown
dev_langs: C++
helpviewer_keywords: CastToUnknown method
ms.assetid: 5bcfcbaf-c75f-4d43-87b3-0d6838c838d9
caps.latest.revision: "5"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: d07e716e085b7f10220f3ed3db4956ae7b1b3cf9
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="implementshelpercasttounknown-method"></a>Método ImplementsHelper::CastToUnknown
Oferece suporte à infraestrutura WRL e não se destina a ser usado diretamente no seu código.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
IUnknown* CastToUnknown();  
```  
  
## <a name="return-value"></a>Valor de retorno  
 Ponteiro para a interface IUnknown subjacente.  
  
## <a name="remarks"></a>Comentários  
 Obtém um ponteiro para a interface IUnknown subjacente para a estrutura implementa atual.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** implements.h  
  
 **Namespace:** Microsoft::WRL::Details  
  
## <a name="see-also"></a>Consulte também  
 [Estrutura ImplementsHelper](../windows/implementshelper-structure.md)   
 [Namespace Microsoft::WRL::Details](../windows/microsoft-wrl-details-namespace.md)