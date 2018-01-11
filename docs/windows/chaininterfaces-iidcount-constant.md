---
title: 'Constante chaininterfaces:: Iidcount | Microsoft Docs'
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords: implements/Microsoft::WRL::ChainInterfaces::IidCount
dev_langs: C++
helpviewer_keywords: IidCount constant
ms.assetid: d4a90aa0-513c-4e99-b978-e12149734936
caps.latest.revision: "3"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 1a1336bb5b8b43e833325c304a4d870220a40b84
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="chaininterfacesiidcount-constant"></a>Constante ChainInterfaces::IidCount
O número total de IDs contidos nas interfaces de especificados pelos parâmetros de modelo de interface `I0` por meio de `I9`.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
static const unsigned long IidCount = Details::InterfaceTraits<I0>::IidCount + Details::InterfaceTraits<I1>::IidCount + Details::InterfaceTraits<I2>::IidCount + Details::InterfaceTraits<I3>::IidCount + Details::InterfaceTraits<I4>::IidCount + Details::InterfaceTraits<I5>::IidCount + Details::InterfaceTraits<I6>::IidCount + Details::InterfaceTraits<I7>::IidCount + Details::InterfaceTraits<I8>::IidCount + Details::InterfaceTraits<I9>::IidCount;  
```  
  
## <a name="return-value"></a>Valor de retorno  
 O número total de identificadores de interface.  
  
## <a name="remarks"></a>Comentários  
 Parâmetros de modelo `I0` e `I1` são necessários e os parâmetros `I2` por meio de `I9` são opcionais. A contagem IID de cada interface normalmente é 1.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** implements.h  
  
 **Namespace:** Microsoft:: wrl  
  
## <a name="see-also"></a>Consulte também  
 [Estrutura ChainInterfaces](../windows/chaininterfaces-structure.md)