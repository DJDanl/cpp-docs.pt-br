---
title: Classe CNonStatelessWorker | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- CNonStatelessWorker
- ATLUTIL/ATL::CNonStatelessWorker
- ATLUTIL/ATL::CNonStatelessWorker::RequestType
- ATLUTIL/ATL::CNonStatelessWorker::Execute
- ATLUTIL/ATL::CNonStatelessWorker::Initialize
- ATLUTIL/ATL::CNonStatelessWorker::Terminate
dev_langs: C++
helpviewer_keywords: CNonStatelessWorker class
ms.assetid: d00936c6-9e7d-49fb-b87d-417b963367d1
caps.latest.revision: "21"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.openlocfilehash: 08b440a60b23182c3efff1c0236773ad2b98bf97
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
---
# <a name="cnonstatelessworker-class"></a>Classe CNonStatelessWorker
Recebe solicitações de um pool de threads e as transmite para um objeto de trabalho que é criado e destruído em cada solicitação.  
  
> [!IMPORTANT]
>  Essa classe e seus membros não podem ser usados em aplicativos que são executados o tempo de execução do Windows.  
  
## <a name="syntax"></a>Sintaxe  
  
```
template <class Worker>  
class CNonStatelessWorker
```  
  
#### <a name="parameters"></a>Parâmetros  
 *Operador*  
 Uma classe do thread de trabalho em conformidade com a [arquétipo trabalho](../../atl/reference/worker-archetype.md) adequado para tratar as solicitações em fila em [CThreadPool](../../atl/reference/cthreadpool-class.md).  
  
## <a name="members"></a>Membros  
  
### <a name="public-typedefs"></a>Typedefs públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CNonStatelessWorker::RequestType](#requesttype)|Implementação de [WorkerArchetype::RequestType](worker-archetype.md#requesttype).|  
  
### <a name="public-methods"></a>Métodos públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CNonStatelessWorker::Execute](#execute)|Implementação de [WorkerArchetype::Execute](worker-archetype.md#execute).|  
|[CNonStatelessWorker::Initialize](#initialize)|Implementação de [WorkerArchetype::Initialize](worker-archetype.md#initialize).|  
|[CNonStatelessWorker::Terminate](#terminate)|Implementação de [WorkerArchetype::Terminate](worker-archetype.md#terminate).|  
  
## <a name="remarks"></a>Comentários  
 Essa classe é um thread de trabalho simples para uso com [CThreadPool](../../atl/reference/cthreadpool-class.md). Essa classe não fornece todos os recursos de seu próprio tratamento de solicitação. Em vez disso, ele cria uma instância de *trabalho* por solicitação e delega a implementação de seus métodos para essa instância.  
  
 A vantagem dessa classe é que ele fornece uma maneira conveniente para alterar o modelo de estado para as classes existentes de thread de trabalho. `CThreadPool`criará um único trabalho para o tempo de vida do thread, portanto, se a classe de trabalho mantém o estado, ele irá armazená-lo em várias solicitações. Simplesmente encapsulando dessa classe no `CNonStatelessWorker` modelo antes de usá-lo com `CThreadPool`, o tempo de vida de trabalhador e o estado em que ele contém é limitado a uma única solicitação.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atlutil.h  
  
##  <a name="execute"></a>CNonStatelessWorker::Execute  
 Implementação de [WorkerArchetype::Execute](worker-archetype.md#execute).  

  
```
void Execute(
    Worker::RequestType request,
    void* pvWorkerParam,
    OVERLAPPED* pOverlapped);
```  
  
### <a name="remarks"></a>Comentários  
 Esse método cria uma instância do *trabalho* classe na pilha de chamadas [inicializar](worker-archetype.md#initialize) nesse objeto. Se a inicialização for bem-sucedida, este método também chama [Execute](worker-archetype.md#execute) e [Terminate](worker-archetype.md#terminate) no mesmo objeto.  

  
##  <a name="initialize"></a>CNonStatelessWorker::Initialize  
 Implementação de [WorkerArchetype::Initialize](worker-archetype.md#initialize).  
  
```
BOOL Initialize(void* /* pvParam */) throw();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Sempre retorna TRUE.  
  
### <a name="remarks"></a>Comentários  
 Essa classe não faça qualquer inicialização `Initialize`.  
  
##  <a name="requesttype"></a>CNonStatelessWorker::RequestType  
 Implementação de [WorkerArchetype::RequestType](worker-archetype.md#requesttype).  
  
```
typedef Worker::RequestType RequestType;
```  
  
### <a name="remarks"></a>Comentários  
 Essa classe gerencia o mesmo tipo de item de trabalho como a classe usada para o *trabalho* parâmetro do modelo. Consulte [visão geral de CNonStatelessWorker](../../atl/reference/cnonstatelessworker-class.md) para obter detalhes.  
  
##  <a name="terminate"></a>CNonStatelessWorker::Terminate  
 Implementação de [WorkerArchetype::Terminate](worker-archetype.md#terminate).  
  
```
void Terminate(void* /* pvParam */) throw();
```  
  
### <a name="remarks"></a>Comentários  
 Essa classe não faça qualquer limpeza `Terminate`.  
  
## <a name="see-also"></a>Consulte também  
 [Classe CThreadPool](../../atl/reference/cthreadpool-class.md)   
 [Trabalho arquétipo](../../atl/reference/worker-archetype.md)   
 [Classes](../../atl/reference/atl-classes.md)
