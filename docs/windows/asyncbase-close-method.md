---
title: "Método Asyncbase: | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords: async/Microsoft::WRL::AsyncBase::Close
dev_langs: C++
helpviewer_keywords: Close method
ms.assetid: a52b1124-754b-4393-b491-64aae0c22f1c
caps.latest.revision: "3"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 35b7fda0ab10ff80df0f4a27f6e79028e73574fa
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="asyncbaseclose-method"></a>Método AsyncBase::Close
Fecha a operação assíncrona.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
STDMETHOD(  
   Close  
)(void) override;  
```  
  
## <a name="return-value"></a>Valor de retorno  
 S_OK se a operação fecha ou já está fechado; Caso contrário, E_ILLEGAL_STATE_CHANGE.  
  
## <a name="remarks"></a>Comentários  
 Close () é uma implementação padrão de IAsyncInfo::Close e não executa nenhum trabalho real. Para fechar, na verdade, uma operação assíncrona, substitua o método virtual puro de OnClose().  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** async.h  
  
 **Namespace:** Microsoft:: wrl  
  
## <a name="see-also"></a>Consulte também  
 [Classe AsyncBase](../windows/asyncbase-class.md)