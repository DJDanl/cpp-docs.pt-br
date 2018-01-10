---
title: Estrutura DispatchState | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- DispatchState
- CONCRTRM/concurrency::DispatchState
- CONCRTRM/concurrency::DispatchState::DispatchState::DispatchState
- CONCRTRM/concurrency::DispatchState::DispatchState::m_dispatchStateSize
- CONCRTRM/concurrency::DispatchState::DispatchState::m_fIsPreviousContextAsynchronouslyBlocked
- CONCRTRM/concurrency::DispatchState::DispatchState::m_reserved
dev_langs: C++
helpviewer_keywords: DispatchState structure
ms.assetid: 8c52546e-1650-48a0-985f-7e4a0fc26a90
caps.latest.revision: "17"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: d58fc12aa31c9d6a72acac6287a425044d42777c
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
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
|[Dispatchstate:: Dispatchstate](#ctor)|Constrói um novo objeto `DispatchState`.|  
  
### <a name="public-data-members"></a>Membros de Dados Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[Dispatchstate:: M_dispatchstatesize](#m_dispatchstatesize)|Tamanho dessa estrutura, que é usado para controle de versão.|  
|[Dispatchstate:: M_fispreviouscontextasynchronouslyblocked](#m_fispreviouscontextasynchronouslyblocked)|Informa se esse contexto tiver inserido o `Dispatch` método porque o contexto anterior assincronamente bloqueada. Isso é usado somente no contexto de programação UMS e é definido como o valor `0` para todos os outros contextos de execução.|  
|[Dispatchstate:: M_reserved](#m_reserved)|Bits reservados para informações futuras passando.|  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 `DispatchState`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** concrtrm.h  
  
 **Namespace:** simultaneidade  
  
##  <a name="ctor"></a>Construtor dispatchstate:: Dispatchstate  
 Constrói um novo objeto `DispatchState`.  
  
```
DispatchState();
```  
  
##  <a name="m_dispatchstatesize"></a>Membro de dados dispatchstate:: M_dispatchstatesize  
 Tamanho dessa estrutura, que é usado para controle de versão.  
  
```
unsigned long m_dispatchStateSize;
```  
  
##  <a name="m_fispreviouscontextasynchronouslyblocked"></a>Membro de dados dispatchstate:: M_fispreviouscontextasynchronouslyblocked  
 Informa se esse contexto tiver inserido o `Dispatch` método porque o contexto anterior assincronamente bloqueada. Isso é usado somente no contexto de programação UMS e é definido como o valor `0` para todos os outros contextos de execução.  
  
```
unsigned int m_fIsPreviousContextAsynchronouslyBlocked : 1;
```  
  
##  <a name="m_reserved"></a>Membro de dados dispatchstate:: M_reserved  
 Bits reservados para informações futuras passando.  
  
```
unsigned int m_reserved : 31;
```  
  
## <a name="see-also"></a>Consulte também  
 [Namespace de simultaneidade](concurrency-namespace.md)
