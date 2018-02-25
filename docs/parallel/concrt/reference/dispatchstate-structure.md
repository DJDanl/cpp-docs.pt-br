---
title: Estrutura DispatchState | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- DispatchState
- CONCRTRM/concurrency::DispatchState
- CONCRTRM/concurrency::DispatchState::DispatchState::DispatchState
- CONCRTRM/concurrency::DispatchState::DispatchState::m_dispatchStateSize
- CONCRTRM/concurrency::DispatchState::DispatchState::m_fIsPreviousContextAsynchronouslyBlocked
- CONCRTRM/concurrency::DispatchState::DispatchState::m_reserved
dev_langs:
- C++
helpviewer_keywords:
- DispatchState structure
ms.assetid: 8c52546e-1650-48a0-985f-7e4a0fc26a90
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 76deac0daa3a8bce2880b2cc9afda0faae263558
ms.sourcegitcommit: d51ed21ab2b434535f5c1d553b22e432073e1478
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/23/2018
---
# <a name="dispatchstate-structure"></a>Estrutura DispatchState
O `DispatchState` estrutura é usada para transferir o estado para o `IExecutionContext::Dispatch` método. Ele descreve as circunstâncias em que o `Dispatch` método é chamado em um `IExecutionContext` interface.  
  
## <a name="syntax"></a>Sintaxe  
  
```
struct DispatchState;
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[DispatchState::DispatchState](#ctor)|Constrói um novo objeto `DispatchState`.|  
  
### <a name="public-data-members"></a>Membros de Dados Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[DispatchState::m_dispatchStateSize](#m_dispatchstatesize)|Tamanho dessa estrutura, que é usado para controle de versão.|  
|[DispatchState::m_fIsPreviousContextAsynchronouslyBlocked](#m_fispreviouscontextasynchronouslyblocked)|Informa se esse contexto tiver inserido o `Dispatch` método porque o contexto anterior assincronamente bloqueada. Isso é usado somente no contexto de programação UMS e é definido como o valor `0` para todos os outros contextos de execução.|  
|[DispatchState::m_reserved](#m_reserved)|Bits reservados para informações futuras passando.|  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 `DispatchState`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** concrtrm.h  
  
 **Namespace:** simultaneidade  
  
##  <a name="ctor"></a>  Construtor dispatchstate:: Dispatchstate  
 Constrói um novo objeto `DispatchState`.  
  
```
DispatchState();
```  
  
##  <a name="m_dispatchstatesize"></a>  DispatchState::m_dispatchStateSize Data Member  
 Tamanho dessa estrutura, que é usado para controle de versão.  
  
```
unsigned long m_dispatchStateSize;
```  
  
##  <a name="m_fispreviouscontextasynchronouslyblocked"></a>  DispatchState::m_fIsPreviousContextAsynchronouslyBlocked Data Member  
 Informa se esse contexto tiver inserido o `Dispatch` método porque o contexto anterior assincronamente bloqueada. Isso é usado somente no contexto de programação UMS e é definido como o valor `0` para todos os outros contextos de execução.  
  
```
unsigned int m_fIsPreviousContextAsynchronouslyBlocked : 1;
```  
  
##  <a name="m_reserved"></a>  DispatchState::m_reserved Data Member  
 Bits reservados para informações futuras passando.  
  
```
unsigned int m_reserved : 31;
```  
  
## <a name="see-also"></a>Consulte também  
 [Namespace de simultaneidade](concurrency-namespace.md)
