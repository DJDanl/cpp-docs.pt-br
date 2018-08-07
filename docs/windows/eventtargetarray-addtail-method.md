---
title: 'Método eventtargetarray:: Addtail | Microsoft Docs'
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: reference
f1_keywords:
- event/Microsoft::WRL::Details::EventTargetArray::AddTail
dev_langs:
- C++
helpviewer_keywords:
- AddTail method
ms.assetid: d0fafab9-049c-40e0-a40c-d126c9ee63e6
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: b469adedebda2beb64c531c82d10f90cc4114742
ms.sourcegitcommit: d5d6bb9945c3550b8e8864b22b3a565de3691fde
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/06/2018
ms.locfileid: "39570168"
---
# <a name="eventtargetarrayaddtail-method"></a>Método EventTargetArray::AddTail
Oferece suporte a infraestrutura do WRL e não se destina a ser usado diretamente do seu código.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
void AddTail(  
   _In_ IUnknown* element  
);  
```  
  
### <a name="parameters"></a>Parâmetros  
 *Elemento*  
 Ponteiro para o manipulador de eventos para acrescentar.  
  
## <a name="remarks"></a>Comentários  
 Acrescenta o manipulador de eventos especificado ao final da matriz interna de manipuladores de eventos.  
  
 **AddTail()** se destina a ser usado internamente pelo apenas o `EventSource` classe.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** Event. h  
  
 **Namespace:** Microsoft::WRL::Details  
  
## <a name="see-also"></a>Consulte também  
 [Classe EventTargetArray](../windows/eventtargetarray-class.md)   
 [Namespace Microsoft::WRL::Details](../windows/microsoft-wrl-details-namespace.md)