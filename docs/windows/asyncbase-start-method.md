---
title: "Método Asyncbase: | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords: async/Microsoft::WRL::AsyncBase::Start
dev_langs: C++
helpviewer_keywords: Start method
ms.assetid: 67405c9d-0d1a-4c1e-8ea4-6ba01c1f90d9
caps.latest.revision: "3"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 419cbec3500977ec5dbeb063e444c1fced8783aa
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="asyncbasestart-method"></a>Método AsyncBase::Start
Inicia a operação assíncrona.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
STDMETHOD(  
   Start  
)(void);  
```  
  
## <a name="return-value"></a>Valor de retorno  
 S_OK se a operação for iniciado ou já foi iniciado; Caso contrário, E_ILLEGAL_STATE_CHANGE.  
  
## <a name="remarks"></a>Comentários  
 Start () é uma implementação padrão de IAsyncInfo::Start e não executa nenhum trabalho real. Para realmente iniciar uma operação assíncrona, substitua o método virtual puro de OnStart ().  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** async.h  
  
 **Namespace:** Microsoft:: wrl  
  
## <a name="see-also"></a>Consulte também  
 [Classe AsyncBase](../windows/asyncbase-class.md)