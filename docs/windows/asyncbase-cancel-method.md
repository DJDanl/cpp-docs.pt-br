---
title: 'Método asyncbase:: Cancel | Microsoft Docs'
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
ms.openlocfilehash: ee338d4e90f94ed7cb7f9158235c66b72e9f2e52
ms.sourcegitcommit: 51f804005b8d921468775a0316de52ad39b77c3e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/02/2018
ms.locfileid: "39464740"
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
 `Cancel()` é uma implementação padrão de `IAsyncInfo::Cancel`, e não faz nenhum trabalho real. Para cancelar, na verdade, uma operação assíncrona, substituir o `OnCancel()` método virtual puro.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** async.h  
  
 **Namespace:** Microsoft::WRL  
  
## <a name="see-also"></a>Consulte também  
 [Classe AsyncBase](../windows/asyncbase-class.md)