---
title: Classe CNonStatelessWorker | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- CNonStatelessWorker
- ATLUTIL/ATL::CNonStatelessWorker
- ATLUTIL/ATL::CNonStatelessWorker::RequestType
- ATLUTIL/ATL::CNonStatelessWorker::Execute
- ATLUTIL/ATL::CNonStatelessWorker::Initialize
- ATLUTIL/ATL::CNonStatelessWorker::Terminate
dev_langs:
- C++
helpviewer_keywords:
- CNonStatelessWorker class
ms.assetid: d00936c6-9e7d-49fb-b87d-417b963367d1
caps.latest.revision: 21
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
ms.translationtype: Machine Translation
ms.sourcegitcommit: 5a0c6a1062330f952bb8fa52bc934f6754465513
ms.openlocfilehash: 804b87bf752aac5cecf64cb61b4d53d6269963f2
ms.contentlocale: pt-br
ms.lasthandoff: 02/25/2017

---
# <a name="cnonstatelessworker-class"></a>Classe CNonStatelessWorker
Recebe solicitações de um pool de threads e passa para um objeto de trabalho que é criado e destruído em cada solicitação.  
  
> [!IMPORTANT]
>  Essa classe e seus membros não podem ser usados em aplicativos executados no tempo de execução do Windows.  
  
## <a name="syntax"></a>Sintaxe  
  
```
template <class Worker>  
class CNonStatelessWorker
```  
  
#### <a name="parameters"></a>Parâmetros  
 *Trabalho*  
 Uma classe de thread de trabalho em conformidade com a [arquétipo trabalho](../../atl/reference/worker-archetype.md) adequado para tratar as solicitações em fila no [CThreadPool](../../atl/reference/cthreadpool-class.md).  
  
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
 Essa classe é um thread de trabalho simples para uso com [CThreadPool](../../atl/reference/cthreadpool-class.md). Essa classe não fornece quaisquer recursos de tratamento de solicitação de seu próprio. Em vez disso, ele cria uma instância de *trabalho* por solicitação e delega a implementação de seus métodos para essa instância.  
  
 O benefício dessa classe é que ele fornece uma maneira conveniente de alterar o modelo de estado para classes existentes de thread de trabalho. `CThreadPool`criará um único trabalho para o tempo de vida do thread, portanto, se a classe de trabalho mantém o estado, ele irá mantê-los em várias solicitações. Simplesmente encapsulando dessa classe no `CNonStatelessWorker` modelo antes de usá-lo com `CThreadPool`, a vida útil do trabalhador e o estado que ele contém é limitada a uma única solicitação.  
  
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
 Esse método cria uma instância do *trabalho* classe na pilha de chamadas [inicializar](worker-archetype.md#initialize) nesse objeto. Se a inicialização for bem-sucedida, esse método também chama [Execute](worker-archetype.md#execute) e [Terminate](worker-archetype.md#terminate) no mesmo objeto.  

  
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
 Essa classe trata o mesmo tipo de item de trabalho como a classe usada para o *trabalho* parâmetro do modelo. Consulte [visão geral de CNonStatelessWorker](../../atl/reference/cnonstatelessworker-class.md) para obter detalhes.  
  
##  <a name="terminate"></a>CNonStatelessWorker::Terminate  
 Implementação de [WorkerArchetype::Terminate](worker-archetype.md#terminate).  
  
```
void Terminate(void* /* pvParam */) throw();
```  
  
### <a name="remarks"></a>Comentários  
 Essa classe não faz qualquer limpeza `Terminate`.  
  
## <a name="see-also"></a>Consulte também  
 [Classe CThreadPool](../../atl/reference/cthreadpool-class.md)   
 [Arquétipo de trabalho](../../atl/reference/worker-archetype.md)   
 [Classes](../../atl/reference/atl-classes.md)

