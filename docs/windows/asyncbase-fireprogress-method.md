---
title: "Método Asyncbase: | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords: async/Microsoft::WRL::AsyncBase::FireProgress
dev_langs: C++
helpviewer_keywords: FireProgress method
ms.assetid: 4512bef6-0ebc-4465-9b8a-4c9dfa82084c
caps.latest.revision: "3"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 358a85f6ec0a451534684f2201caffefb1c1ad1b
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="asyncbasefireprogress-method"></a>Método AsyncBase::FireProgress
Invoca o manipulador de eventos de andamento atual.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
void FireProgress(  
   const typename ProgressTraits::Arg2Type arg  
);  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `arg`  
 O método do manipulador de eventos para invocar.  
  
## <a name="remarks"></a>Comentários  
 `ProgressTraits`é derivado de [estrutura ArgTraitsHelper](../windows/argtraitshelper-structure.md).  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** async.h  
  
 **Namespace:** Microsoft:: wrl  
  
## <a name="see-also"></a>Consulte também  
 [Classe AsyncBase](../windows/asyncbase-class.md)