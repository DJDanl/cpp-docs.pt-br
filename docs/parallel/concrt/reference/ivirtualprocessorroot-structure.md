---
title: IVirtualProcessorRoot Structure | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- IVirtualProcessorRoot
- CONCRTRM/concurrency::IVirtualProcessorRoot
- CONCRTRM/concurrency::IVirtualProcessorRoot::IVirtualProcessorRoot::Activate
- CONCRTRM/concurrency::IVirtualProcessorRoot::IVirtualProcessorRoot::Deactivate
- CONCRTRM/concurrency::IVirtualProcessorRoot::IVirtualProcessorRoot::EnsureAllTasksVisible
- CONCRTRM/concurrency::IVirtualProcessorRoot::IVirtualProcessorRoot::GetId
dev_langs:
- C++
helpviewer_keywords:
- IVirtualProcessorRoot structure
ms.assetid: 5ef371b8-9e4f-4fef-bb0d-49099693dd2b
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: a385bc12d3add9dd445243794135083c7cc1b3c1
ms.sourcegitcommit: d51ed21ab2b434535f5c1d553b22e432073e1478
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/23/2018
---
# <a name="ivirtualprocessorroot-structure"></a>Estrutura IVirtualProcessorRoot
Uma abstração para um thread de hardware no qual um proxy do thread pode executar.  
  
## <a name="syntax"></a>Sintaxe  
  
```
struct IVirtualProcessorRoot : public IExecutionResource;
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-methods"></a>Métodos Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[IVirtualProcessorRoot::Activate](#activate)|Faz com que o proxy de thread associado à interface de contexto de execução `pContext` para iniciar a execução na raiz desse processador virtual.|  
|[IVirtualProcessorRoot::Deactivate](#deactivate)|Faz com que o proxy de thread em execução no momento na raiz desse processador virtual pare de expedir o contexto de execução. O proxy de thread continuará em execução em uma chamada para o `Activate` método.|  
|[IVirtualProcessorRoot::EnsureAllTasksVisible](#ensurealltasksvisible)|Faz com que os dados armazenados na hierarquia de memória processadores individuais se tornarão visíveis para todos os processadores no sistema. Isso garante que um limite de memória completa foi executado em todos os processadores antes do método retorna.|  
|[IVirtualProcessorRoot::GetId](#getid)|Retorna um identificador exclusivo para a raiz do processador virtual.|  
  
## <a name="remarks"></a>Comentários  
 Cada raiz do processador virtual tem um recurso de execução associadas. O `IVirtualProcessorRoot` interface herda o [IExecutionResource](iexecutionresource-structure.md) interface. Várias raízes de processador virtual podem corresponder ao mesmo segmento hardware subjacente.  
  
 O Gerenciador de recursos concede raízes de processador virtual para agendadores em resposta a solicitações de recursos. Um agendador pode usar uma raiz de processador virtual para executar o trabalho ativá-lo com um contexto de execução.  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 [IExecutionResource](iexecutionresource-structure.md)  
  
 `IVirtualProcessorRoot`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** concrtrm.h  
  
 **Namespace:** simultaneidade  
  
##  <a name="activate"></a>  IVirtualProcessorRoot::Activate Method  
 Faz com que o proxy de thread associado à interface de contexto de execução `pContext` para iniciar a execução na raiz desse processador virtual.  
  
```
virtual void Activate(_Inout_ IExecutionContext* pContext) = 0;
```  
  
### <a name="parameters"></a>Parâmetros  
 `pContext`  
 Uma interface para o contexto de execução será enviado na raiz desse processador virtual.  
  
### <a name="remarks"></a>Comentários  
 O Gerenciador de recursos fornecerá um proxy de thread se um não está associado com a interface de contexto de execução `pContext`  
  
 O `Activate` método pode ser usado para iniciar a execução do trabalho em uma nova raiz de processador virtual retornada pelo Gerenciador de recursos ou para retomar o proxy de thread em uma raiz de processador virtual que foi desativado ou está prestes a desativar. Consulte [Ivirtualprocessorroot](#deactivate) para obter mais informações sobre a desativação. Quando você está retomando uma raiz de processador virtual desativadas, o parâmetro `pContext` deve ser o mesmo que o parâmetro usado para desativar a raiz de processador virtual.  
  
 Depois de uma raiz de processador virtual tiver sido ativada pela primeira vez, subsequentes pares de chamadas para `Deactivate` e `Activate` poderão rapidamente entre si. Isso significa que é aceitável para o Gerenciador de recursos para receber uma chamada para `Activate` antes de receber o `Deactivate` chamada foi criado.  
  
 Quando você ativa uma raiz de processador virtual, sinal para o Gerenciador de recursos que raiz desse processador virtual está ocupado no momento com o trabalho. Se o Agendador não é possível encontrar nenhum trabalho a executar na raiz desse, espera-se chamar o `Deactivate` método informando que o Gerenciador de recursos que a raiz virtual do processador está ociosa. O Gerenciador de recursos usa esses dados para o sistema de balanceamento de carga.  
  
 `invalid_argument` será gerada se o argumento `pContext` tem o valor `NULL`.  
  
 `invalid_operation` será gerada se o argumento `pContext` não representa o contexto de execução mais recente foi enviado pela raiz desse processador virtual.  
  
 O ato de ativação de uma raiz de processador virtual aumenta o nível de assinatura do thread de hardware subjacentes por um. Para obter mais informações sobre níveis de assinatura, consulte [: Currentsubscriptionlevel](iexecutionresource-structure.md#currentsubscriptionlevel).  
  
##  <a name="deactivate"></a>  IVirtualProcessorRoot::Deactivate Method  
 Faz com que o proxy de thread em execução no momento na raiz desse processador virtual pare de expedir o contexto de execução. O proxy de thread continuará em execução em uma chamada para o `Activate` método.  
  
```
virtual bool Deactivate(_Inout_ IExecutionContext* pContext) = 0;
```  
  
### <a name="parameters"></a>Parâmetros  
 `pContext`  
 O contexto que está atualmente sendo despachado por esta raiz.  
  
### <a name="return-value"></a>Valor de retorno  
 Um valor booliano. Um valor de `true` indica que o proxy de thread retornado do `Deactivate` método em resposta a uma chamada para o `Activate` método. Um valor de `false` indica que o proxy de thread retornado do método em resposta a um evento de notificação no Gerenciador de recursos. Em um modo de usuário agendáveis () thread Agendador UMS, isso indica que itens apareceu na lista de conclusão do Agendador e o Agendador é necessária para lidar com eles.  
  
### <a name="remarks"></a>Comentários  
 Use esse método para interromper temporariamente uma raiz de processador virtual em execução quando você não encontrar nenhum trabalho em seu Agendador. Uma chamada para o `Deactivate` método deve originar-se de dentro de `Dispatch` método do contexto de execução que a raiz do processador virtual foi ativada pela última vez com. Em outras palavras, o proxy de thread invocando o `Deactivate` método deve ser aquele que está sendo executado na raiz do processador virtual. Chamar o método em uma raiz de processador virtual que não está em execução no pode resultar em um comportamento indefinido.  
  
 Uma raiz de processador virtual desativadas pode ser ativada com uma chamada para o `Activate` método com o mesmo argumento foi passado para o `Deactivate` método. O Agendador é responsável por garantir que chamadas para o `Activate` e `Deactivate` métodos são combinados, mas eles não são necessários para ser recebida em uma ordem específica. O Gerenciador de recursos pode tratar o recebimento de uma chamada para o `Activate` método antes de receber uma chamada para o `Deactivate` método foi criado.  
  
 Se uma raiz de processador virtual desperta e o valor de retorno a `Deactivate` método é o valor `false`, o Agendador deve consultar a lista de conclusão de UMS via o `IUMSCompletionList::GetUnblockNotifications` método, agir sobre essas informações e, em seguida, chamar subsequentemente o `Deactivate`método novamente. Isso deve ser repetido até que o `Deactivate` método retornará o valor `true`.  
  
 `invalid_argument` será gerada se o argumento `pContext` tem o valor `NULL`.  
  
 `invalid_operation` será gerada se a raiz do processador virtual nunca foi ativada, ou o argumento `pContext` não representa o contexto de execução mais recente foi enviado pela raiz desse processador virtual.  
  
 O ato de desativar uma raiz de processador virtual diminui o nível de assinatura do thread hardware subjacente. Para obter mais informações sobre níveis de assinatura, consulte [: Currentsubscriptionlevel](iexecutionresource-structure.md#currentsubscriptionlevel).  
  
##  <a name="ensurealltasksvisible"></a>  IVirtualProcessorRoot::EnsureAllTasksVisible Method  
 Faz com que os dados armazenados na hierarquia de memória processadores individuais se tornarão visíveis para todos os processadores no sistema. Isso garante que um limite de memória completa foi executado em todos os processadores antes do método retorna.  
  
```
virtual void EnsureAllTasksVisible(_Inout_ IExecutionContext* pContext) = 0;
```  
  
### <a name="parameters"></a>Parâmetros  
 `pContext`  
 O contexto que é atualmente sendo enviado pela raiz desse processador virtual.  
  
### <a name="remarks"></a>Comentários  
 Você pode ser útil quando você deseja sincronizar a desativação de uma raiz de processador virtual com a adição de novos trabalhos no Agendador. Por motivos de desempenho, você pode decidir adicionar itens de trabalho para o Agendador sem executar uma barreira de memória, o que significa que os itens de trabalho adicionados por um thread de execução em um processador não ficam imediatamente visíveis para todos os outros processadores. Usando esse método em conjunto com o `Deactivate` raízes do método que você pode garantir que o Agendador não desativar todos os seu processador virtual enquanto existirem itens de trabalho em coleções do Agendador.  
  
 Uma chamada para o `EnsureAllTasksVisibleThe` método deve originar-se de dentro de `Dispatch` método do contexto de execução que a raiz do processador virtual foi ativada pela última vez com. Em outras palavras, o proxy de thread invocando o `EnsureAllTasksVisible` método deve ser aquele que está sendo executado na raiz do processador virtual. Chamar o método em uma raiz de processador virtual que não está em execução no pode resultar em um comportamento indefinido.  
  
 `invalid_argument` será gerada se o argumento `pContext` tem o valor `NULL`.  
  
 `invalid_operation` será gerada se a raiz do processador virtual nunca foi ativada, ou o argumento `pContext` não representa o contexto de execução mais recente foi enviado pela raiz desse processador virtual.  
  
##  <a name="getid"></a>  IVirtualProcessorRoot::GetId Method  
 Retorna um identificador exclusivo para a raiz do processador virtual.  
  
```
virtual unsigned int GetId() const = 0;
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um identificador de inteiro.  
  
## <a name="see-also"></a>Consulte também  
 [Namespace de simultaneidade](concurrency-namespace.md)
