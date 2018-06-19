---
title: 'Método Asyncbase: | Microsoft Docs'
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: reference
f1_keywords:
- async/Microsoft::WRL::AsyncBase::Cancel
dev_langs:
- C++
helpviewer_keywords:
- Cancel method
ms.assetid: 8bfebc63-3848-4629-bc89-aa538ed7e7ad
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 0559f32315265a7db5543e8559097177c2a670fa
ms.sourcegitcommit: d55ac596ba8f908f5d91d228dc070dad31cb8360
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/08/2018
ms.locfileid: "33859846"
---
# <a name="asyncbasecancel-method"></a>Método AsyncBase::Cancel
Cancela uma operação assíncrona.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
STDMETHOD(  
   Cancel  
)(void);  
```  
  
## <a name="return-value"></a>Valor de retorno  
 Por padrão, sempre retorna S_OK.  
  
## <a name="remarks"></a>Comentários  
 Cancel () é uma implementação padrão de IAsyncInfo::Cancel e não executa nenhum trabalho real. Para realmente cancelar uma operação assíncrona, substitua o método virtual puro de OnCancel().  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** async.h  
  
 **Namespace:** Microsoft::WRL  
  
## <a name="see-also"></a>Consulte também  
 [Classe AsyncBase](../windows/asyncbase-class.md)