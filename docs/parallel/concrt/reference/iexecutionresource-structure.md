---
title: Estrutura IExecutionResource | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- IExecutionResource
- CONCRTRM/concurrency::IExecutionResource
- CONCRTRM/concurrency::IExecutionResource::IExecutionResource::CurrentSubscriptionLevel
- CONCRTRM/concurrency::IExecutionResource::IExecutionResource::GetExecutionResourceId
- CONCRTRM/concurrency::IExecutionResource::IExecutionResource::GetNodeId
- CONCRTRM/concurrency::IExecutionResource::IExecutionResource::Remove
dev_langs:
- C++
helpviewer_keywords:
- IExecutionResource structure
ms.assetid: 6b27042b-b98c-4f7f-b831-566950af84cd
caps.latest.revision: 16
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
ms.sourcegitcommit: 5faef5bd1be6cc02d6614a6f6193c74167a8ff23
ms.openlocfilehash: fa3c65780ac9e001e6f6b8a015dc7f70df47181f
ms.contentlocale: pt-br
ms.lasthandoff: 03/17/2017

---
# <a name="iexecutionresource-structure"></a>Estrutura IExecutionResource
Uma abstração de um thread de hardware.  
  
## <a name="syntax"></a>Sintaxe  
  
```
struct IExecutionResource;
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-methods"></a>Métodos Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[Currentsubscriptionlevel](#currentsubscriptionlevel)|Retorna o número de processadores virtuais ativado raízes e inscritos externos threads atualmente associados ao thread de hardware subjacentes que representa esse recurso de execução.|  
|[Getexecutionresourceid](#getexecutionresourceid)|Retorna um identificador exclusivo para o thread de hardware que representa esse recurso de execução.|  
|[Getnodeid](#getnodeid)|Retorna um identificador exclusivo para o nó de processador que esse recurso de execução pertence.|  
|[Iexecutionresource](#remove)|Esse recurso de execução retorna para o Gerenciador de recursos.|  
  
## <a name="remarks"></a>Comentários  
 Recursos de execução podem ser autônomo ou associadas a raízes do processador virtual. Um recurso de execução autônoma é criado quando um thread em seu aplicativo cria uma assinatura de thread. Os métodos [ISchedulerProxy::SubscribeThread](ischedulerproxy-structure.md#subscribecurrentthread) e [Requestinitialvirtualprocessors](ischedulerproxy-structure.md#requestinitialvirtualprocessors) criar assinaturas de thread e retornar um `IExecutionResource` interface que representa a assinatura. Criar uma assinatura de thread é uma maneira de informar o Gerenciador de recursos que um determinado thread farão parte do trabalho na fila para um programador, juntamente com as raízes de processador virtual Gerenciador de recursos atribui ao Agendador. O Gerenciador de recursos usa as informações para evitar o aproveitamento de threads de hardware onde possível.  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 `IExecutionResource`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** concrtrm. h  
  
 **Namespace:** simultaneidade  
  
##  <a name="currentsubscriptionlevel"></a>Método Currentsubscriptionlevel  
 Retorna o número de processadores virtuais ativado raízes e inscritos externos threads atualmente associados ao thread de hardware subjacentes que representa esse recurso de execução.  
  
```
virtual unsigned int CurrentSubscriptionLevel() const = 0;
```  
  
### <a name="return-value"></a>Valor de retorno  
 O nível de assinatura atual.  
  
### <a name="remarks"></a>Comentários  
 O nível de assinatura informa quantos threads em execução associados ao thread de hardware. Isso inclui apenas os threads, o Gerenciador de recursos está ciente de na forma de segmentos inscritos e raízes de processadores virtuais que estão em execução ativamente proxies de thread.  
  
 Chamar o método [Subscribecurrentthread](ischedulerproxy-structure.md#subscribecurrentthread), ou o método [Requestinitialvirtualprocessors](ischedulerproxy-structure.md#requestinitialvirtualprocessors) com o parâmetro `doSubscribeCurrentThread` definido como o valor `true` incrementa o nível de assinatura de um thread de hardware em um. Eles também retornam um `IExecutionResource` interface que representa a assinatura. Uma chamada correspondente para o [Iexecutionresource](#remove) diminui o nível da assinatura do thread de hardware por um.  
  
 O ato de ativação de uma raiz de processador virtual usando o método [Ivirtualprocessorroot](ivirtualprocessorroot-structure.md#activate) incrementa o nível de assinatura de um thread de hardware em um. Os métodos [Ivirtualprocessorroot](ivirtualprocessorroot-structure.md#deactivate), ou [Iexecutionresource](#remove) diminuir o nível de assinatura por um quando invocado em uma raiz de processador virtual ativado.  
  
 O Gerenciador de recursos usa informações de nível de assinatura como uma das maneiras de determinar quando mover recursos entre os agendadores.  
  
##  <a name="getexecutionresourceid"></a>Método Getexecutionresourceid  
 Retorna um identificador exclusivo para o thread de hardware que representa esse recurso de execução.  
  
```
virtual unsigned int GetExecutionResourceId() const = 0;
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um identificador exclusivo para o thread de hardware subjacentes desse recurso de execução.  
  
### <a name="remarks"></a>Comentários  
 Cada thread de hardware é atribuído um identificador exclusivo no tempo de execução de simultaneidade. Se vários recursos de execução são hardware associado thread, eles terão o mesmo identificador de recurso de execução.  
  
##  <a name="getnodeid"></a>Método Getnodeid  
 Retorna um identificador exclusivo para o nó de processador que esse recurso de execução pertence.  
  
```
virtual unsigned int GetNodeId() const = 0;
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um identificador exclusivo para um nó de processador.  
  
### <a name="remarks"></a>Comentários  
 O tempo de execução de simultaneidade representa segmentos de hardware do sistema em grupos de nós de processador. Nós geralmente são derivados da topologia do hardware do sistema. Por exemplo, todos os processadores em um soquete específico ou um nó NUMA específico podem pertencer ao mesmo nó do processador. O Gerenciador de recursos atribui identificadores exclusivos para esses nós começando com `0` até e incluindo `nodeCount - 1`, onde `nodeCount` representa o número total de nós de processador no sistema.  
  
 A contagem de nós pode ser obtida da função [GetProcessorNodeCount](concurrency-namespace-functions.md).  
  
##  <a name="remove"></a>Método Iexecutionresource::  
 Esse recurso de execução retorna para o Gerenciador de recursos.  
  
```
virtual void Remove(_Inout_ IScheduler* pScheduler) = 0;
```  
  
### <a name="parameters"></a>Parâmetros  
 `pScheduler`  
 Uma interface para o Agendador de fazer a solicitação para remover esse recurso de execução.  
  
### <a name="remarks"></a>Comentários  
 Use este método para retornar os recursos de execução autônoma, bem como recursos de execução associados raízes do processador virtual para o Gerenciador de recursos.  
  
 Se esse é um recurso de execução autônoma recebido de um dos métodos [Subscribecurrentthread](ischedulerproxy-structure.md#subscribecurrentthread) ou [Requestinitialvirtualprocessors](ischedulerproxy-structure.md#requestinitialvirtualprocessors), chamando o método `Remove` terminará a assinatura de thread que o recurso foi criado para representar. São necessárias para encerrar todas as assinaturas de thread antes de desligar um proxy do Agendador e deve chamar `Remove` do thread que criou a assinatura.  
  
 Raízes do processador virtual, também podem ser retornados para o Gerenciador de recursos invocando o `Remove` método, porque a interface `IVirtualProcessorRoot` herda o `IExecutionResource` interface. Talvez você precise retornar uma raiz virtual do processador em resposta a uma chamada para o [Removevirtualprocessors](ischeduler-structure.md#removevirtualprocessors) método, ou quando você terminar com uma raiz de processador virtual assinadas é obtido o [Createoversubscriber](ischedulerproxy-structure.md#createoversubscriber) método. Para raízes de processador virtual, não existem restrições em qual thread pode chamar o `Remove` método.  
  
 `invalid_argument`é lançada se o parâmetro `pScheduler` é definido como `NULL`.  
  
 `invalid_operation`é lançada se o parâmetro `pScheduler` é diferente do Agendador que este recurso de execução foi criado para ou, com um recurso de execução autônoma, se o thread atual é diferente do thread que criou a assinatura de thread.  
  
## <a name="see-also"></a>Consulte também  
 [Namespace de simultaneidade](concurrency-namespace.md)   
 [Estrutura IVirtualProcessorRoot](ivirtualprocessorroot-structure.md)

