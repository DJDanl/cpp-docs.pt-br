---
title: "Método Chaininterfaces: | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords: implements/Microsoft::WRL::ChainInterfaces::CastToUnknown
dev_langs: C++
helpviewer_keywords: CastToUnknown method
ms.assetid: a6a58555-e5b0-4773-aba0-959d9d362c6b
caps.latest.revision: "3"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.openlocfilehash: 8851396cf817ec52d072ba0bfb6267ec094a82b0
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
---
# <a name="chaininterfacescasttounknown-method"></a>Método ChainInterfaces::CastToUnknown
Converte o ponteiro de interface do tipo definido pelo `I0` parâmetro de modelo para um ponteiro IUnknown.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
__forceinline IUnknown* CastToUnknown();  
```  
  
## <a name="return-value"></a>Valor de retorno  
 Um ponteiro IUnknown.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** implements.h  
  
 **Namespace:** Microsoft:: wrl  
  
## <a name="see-also"></a>Consulte também  
 [Estrutura ChainInterfaces](../windows/chaininterfaces-structure.md)