---
title: Estrutura DispatchState | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: article
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
caps.latest.revision: 17
author: mikeblome
ms.author: mblome
manager: ghogen
translation.priority.ht:
- cs-cz
- de-de
- es-es
- fr-fr
- it-it
- ja-jp
- ko-kr
- pl-pl
- pt-br
- ru-ru
- tr-tr
- zh-cn
- zh-tw
translationtype: Machine Translation
ms.sourcegitcommit: 5faef5bd1be6cc02d6614a6f6193c74167a8ff23
ms.openlocfilehash: a617d1f1d7f68c00c7011daffc6ba59f08c43a1e
ms.lasthandoff: 03/17/2017

---
# <a name="dispatchstate-structure"></a>Estrutura DispatchState
O `DispatchState` estrutura é usada para transferir o estado para o `IExecutionContext::Dispatch` método. Ele descreve as circunstâncias em que o `Dispatch` método é invocado em um `IExecutionContext` interface.  
  
## <a name="syntax"></a>Sintaxe  
  
```
struct DispatchState;
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[Dispatchstate:: Dispatchstate](#ctor)|Constrói um novo `DispatchState` objeto.|  
  
### <a name="public-data-members"></a>Membros de Dados Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[Dispatchstate:: M_dispatchstatesize](#m_dispatchstatesize)|Tamanho dessa estrutura, que é usado para controle de versão.|  
|[Dispatchstate:: M_fispreviouscontextasynchronouslyblocked](#m_fispreviouscontextasynchronouslyblocked)|Informa se entrou nesse contexto o `Dispatch` método porque o contexto anterior assíncrona bloqueadas. Isso é usado apenas no contexto de programação UMS e é definido como o valor `0` para todos os outros contextos de execução.|  
|[Dispatchstate:: M_reserved](#m_reserved)|Reservado para futuras informações passando de bits.|  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 `DispatchState`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** concrtrm. h  
  
 **Namespace:** simultaneidade  
  
##  <a name="ctor"></a>Construtor dispatchstate:: Dispatchstate  
 Constrói um novo `DispatchState` objeto.  
  
```
DispatchState();
```  
  
##  <a name="m_dispatchstatesize"></a>Membro de dados dispatchstate:: M_dispatchstatesize  
 Tamanho dessa estrutura, que é usado para controle de versão.  
  
```
unsigned long m_dispatchStateSize;
```  
  
##  <a name="m_fispreviouscontextasynchronouslyblocked"></a>Membro de dados dispatchstate:: M_fispreviouscontextasynchronouslyblocked  
 Informa se entrou nesse contexto o `Dispatch` método porque o contexto anterior assíncrona bloqueadas. Isso é usado apenas no contexto de programação UMS e é definido como o valor `0` para todos os outros contextos de execução.  
  
```
unsigned int m_fIsPreviousContextAsynchronouslyBlocked : 1;
```  
  
##  <a name="m_reserved"></a>Membro de dados dispatchstate:: M_reserved  
 Reservado para futuras informações passando de bits.  
  
```
unsigned int m_reserved : 31;
```  
  
## <a name="see-also"></a>Consulte também  
 [Namespace de simultaneidade](concurrency-namespace.md)

