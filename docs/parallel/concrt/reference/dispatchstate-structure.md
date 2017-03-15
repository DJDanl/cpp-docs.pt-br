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
- concrtrm/concurrency::DispatchState
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
ms.sourcegitcommit: fa774c7f025b581d65c28d65d83e22ff2d798230
ms.openlocfilehash: 46c2219464e57da4931596e970199549405d02ec
ms.lasthandoff: 02/25/2017

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
|[Construtor dispatchstate:: Dispatchstate](#ctor)|Constrói um novo `DispatchState` objeto.|  
  
### <a name="public-data-members"></a>Membros de Dados Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[Membro de dados dispatchstate:: M_dispatchstatesize](#m_dispatchstatesize)|Tamanho dessa estrutura, que é usado para controle de versão.|  
|[Membro de dados dispatchstate:: M_fispreviouscontextasynchronouslyblocked](#m_fispreviouscontextasynchronouslyblocked)|Informa se entrou nesse contexto o `Dispatch` método porque o contexto anterior assíncrona bloqueadas. Isso é usado apenas no contexto de programação UMS e é definido como o valor `0` para todos os outros contextos de execução.|  
|[Membro de dados dispatchstate:: M_reserved](#m_reserved)|Reservado para futuras informações passando de bits.|  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 `DispatchState`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** concrtrm. h  
  
 **Namespace:** simultaneidade  
  
##  <a name="a-namectora--dispatchstatedispatchstate-constructor"></a><a name="ctor"></a>Construtor dispatchstate:: Dispatchstate  
 Constrói um novo `DispatchState` objeto.  
  
```
DispatchState();
```  
  
##  <a name="a-namemdispatchstatesizea--dispatchstatemdispatchstatesize-data-member"></a><a name="m_dispatchstatesize"></a>Membro de dados dispatchstate:: M_dispatchstatesize  
 Tamanho dessa estrutura, que é usado para controle de versão.  
  
```
unsigned long m_dispatchStateSize;
```  
  
##  <a name="a-namemfispreviouscontextasynchronouslyblockeda--dispatchstatemfispreviouscontextasynchronouslyblocked-data-member"></a><a name="m_fispreviouscontextasynchronouslyblocked"></a>Membro de dados dispatchstate:: M_fispreviouscontextasynchronouslyblocked  
 Informa se entrou nesse contexto o `Dispatch` método porque o contexto anterior assíncrona bloqueadas. Isso é usado apenas no contexto de programação UMS e é definido como o valor `0` para todos os outros contextos de execução.  
  
```
unsigned int m_fIsPreviousContextAsynchronouslyBlocked : 1;
```  
  
##  <a name="a-namemreserveda--dispatchstatemreserved-data-member"></a><a name="m_reserved"></a>Membro de dados dispatchstate:: M_reserved  
 Reservado para futuras informações passando de bits.  
  
```
unsigned int m_reserved : 31;
```  
  
## <a name="see-also"></a>Consulte também  
 [Namespace de simultaneidade](concurrency-namespace.md)

