---
title: 'Método asyncbase:: Start | Microsoft Docs'
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: reference
f1_keywords:
- async/Microsoft::WRL::AsyncBase::Start
dev_langs:
- C++
helpviewer_keywords:
- Start method
ms.assetid: 67405c9d-0d1a-4c1e-8ea4-6ba01c1f90d9
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: ab47405f81cf6fb92af215f1868d8ad7c42bffa7
ms.sourcegitcommit: 51f804005b8d921468775a0316de52ad39b77c3e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/02/2018
ms.locfileid: "39463724"
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
 S_OK se a operação é iniciado ou já foi iniciado; Caso contrário, E_ILLEGAL_STATE_CHANGE.  
  
## <a name="remarks"></a>Comentários  
 **Start ()** é uma implementação padrão de `IAsyncInfo::Start`, e não faz nenhum trabalho real. Para começar, na verdade, uma operação assíncrona, substituir o `OnStart()` método virtual puro.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** async.h  
  
 **Namespace:** Microsoft::WRL  
  
## <a name="see-also"></a>Consulte também  
 [Classe AsyncBase](../windows/asyncbase-class.md)