---
title: "Método Chaininterfaces: | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords: implements/Microsoft::WRL::ChainInterfaces::Verify
dev_langs: C++
helpviewer_keywords: Verify method
ms.assetid: c591e130-8686-4130-ba69-1aaedc250038
caps.latest.revision: "4"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: d34d117091fd8807dfefda074e510910bf059560
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="chaininterfacesverify-method"></a>Método ChainInterfaces::Verify
Verifica se cada interface definidos pelos parâmetros de modelo `I0` por meio de `I9` herda de IUnknown e/ou IInspectable que `I0` herda de `I1` por meio de `I9`.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
WRL_NOTHROW __forceinline static void Verify();  
```  
  
## <a name="remarks"></a>Comentários  
 Se a operação de verificação falhar, um `static_assert` emite uma mensagem de erro que descreve a falha.  
  
## <a name="remarks"></a>Comentários  
 Parâmetros de modelo `I0` e `I1` são necessários e os parâmetros `I2` por meio de `I9` são opcionais.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** implements.h  
  
 **Namespace:** Microsoft:: wrl  
  
## <a name="see-also"></a>Consulte também  
 [Estrutura ChainInterfaces](../windows/chaininterfaces-structure.md)