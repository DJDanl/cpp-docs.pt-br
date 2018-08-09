---
title: 'Construtor invokehelper:: Invokehelper | Microsoft Docs'
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: reference
f1_keywords:
- event/Microsoft::WRL::Details::InvokeHelper::InvokeHelper
dev_langs:
- C++
helpviewer_keywords:
- InvokeHelper, constructor
ms.assetid: 0223c574-abc3-4fc0-99e6-38626ba79243
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 75ad1b82d6d4a28db94ef00a234547091969722b
ms.sourcegitcommit: 38af5a1bf35249f0a51e3aafc6e4077859c8f0d9
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/09/2018
ms.locfileid: "40020021"
---
# <a name="invokehelperinvokehelper-constructor"></a>Construtor InvokeHelper::InvokeHelper
Oferece suporte a infraestrutura do WRL e não se destina a ser usado diretamente do seu código.  
  
## <a name="syntax"></a>Sintaxe  
  
```cpp  
explicit InvokeHelper(  
   TCallback callback  
);  
```  
  
### <a name="parameters"></a>Parâmetros  
 *retorno de chamada*  
 Um manipulador de eventos.  
  
## <a name="remarks"></a>Comentários  
 Inicializa uma nova instância dos **InvokeHelper** classe.  
  
 O `TCallback` parâmetro de modelo especifica o tipo de manipulador de eventos.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** Event. h  
  
 **Namespace:** Microsoft::WRL::Details  
  
## <a name="see-also"></a>Consulte também  
 [Estrutura InvokeHelper](../windows/invokehelper-structure.md)   
 [Namespace Microsoft::WRL::Details](../windows/microsoft-wrl-details-namespace.md)