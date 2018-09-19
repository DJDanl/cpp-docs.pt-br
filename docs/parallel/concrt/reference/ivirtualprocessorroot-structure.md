---
title: Estrutura IVirtualProcessorRoot | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-concrt
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
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: cb34946a9860746bbe96c5ec9bcd96a990c5f281
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46022573"
---
# <a name="ivirtualprocessorroot-structure"></a>Estrutura IVirtualProcessorRoot
Uma abstração para um thread de hardware no qual um proxy de thread pode executar.  
  
## <a name="syntax"></a>Sintaxe  
  
```
struct IVirtualProcessorRoot : public IExecutionResource;
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-methods"></a>Métodos Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[IVirtualProcessorRoot::Activate](#activate)|Faz com que o proxy de thread associado com a interface de contexto de execução `pContext` para iniciar a execução na raiz desse processador virtual.|  
|[IVirtualProcessorRoot::Deactivate](#deactivate)|Faz com que o proxy de thread em execução no momento na raiz desse processador virtual para interromper a expedir o contexto de execução. O proxy de thread continuará em execução em uma chamada para o `Activate` método.|  
|[IVirtualProcessorRoot::EnsureAllTasksVisible](#ensurealltasksvisible)|Faz com que os dados armazenados na hierarquia de memória de processadores individuais se torne visível para todos os processadores no sistema. Isso garante que um limite de memória completo foi executado em todos os processadores antes do método retorna.|  
|[IVirtualProcessorRoot::GetId](#getid)|Retorna um identificador exclusivo para a raiz do processador virtual.|  
  
## <a name="remarks"></a>Comentários  
 Cada raiz de processador virtual tem um recurso de execução associadas. O `IVirtualProcessorRoot` interface herda as [IExecutionResource](iexecutionresource-structure.md) interface. Várias raízes de processador virtual podem corresponder a mesmo thread de hardware subjacente.  
  
 O Gerenciador de recursos concede raízes de processador virtual para agendadores em resposta a solicitações de recursos. Um agendador pode usar uma raiz virtual do processador para executar o trabalho ativando-o com um contexto de execução.  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 [IExecutionResource](iexecutionresource-structure.md)  
  
 `IVirtualProcessorRoot`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** concrtrm. h  
  
 **Namespace:** simultaneidade  
  
##  <a name="activate"></a>  Método ivirtualprocessorroot:: Activate  
 Faz com que o proxy de thread associado com a interface de contexto de execução `pContext` para iniciar a execução na raiz desse processador virtual.  
  
```
virtual void Activate(_Inout_ IExecutionContext* pContext) = 0;
```  
  
### <a name="parameters"></a>Parâmetros  
*pContext*<br/>
Uma interface para o contexto de execução será enviado nessa raiz virtual do processador.  
  
### <a name="remarks"></a>Comentários  
 O Gerenciador de recursos, forneça um proxy de thread se não houver um associado com a interface de contexto de execução `pContext`  
  
 O `Activate` método pode ser usado para iniciar a execução de trabalho em uma nova raiz de processador virtual retornada pelo Gerenciador de recursos ou para retomar o proxy de thread em uma raiz de processador virtual que foi desativado ou está prestes a desativar. Ver [ivirtualprocessorroot:: Deactivate](#deactivate) para obter mais informações sobre a desativação. Quando você está retomando uma raiz de processador virtual desativado, o parâmetro `pContext` deve ser o mesmo que o parâmetro usado para desativar a raiz do processador virtual.  
  
 Depois que uma raiz virtual do processador foi ativada pela primeira vez, subsequentes pares de chamadas para `Deactivate` e `Activate` pode de corrida entre si. Isso significa que é aceitável para o Gerenciador de recursos para receber uma chamada para `Activate` antes de receber o `Deactivate` chamada foi criado.  
  
 Quando você ativa uma raiz virtual do processador, sinalizar para o Gerenciador de recursos que essa raiz virtual do processador está ocupado no momento com o trabalho. Se seu Agendador não é possível encontrar nenhum trabalho a ser executado na raiz desse, espera-se para invocar o `Deactivate` método informando que o Gerenciador de recursos que a raiz virtual do processador está ocioso. O Gerenciador de recursos usa esses dados para o sistema de balanceamento de carga.  
  
 `invalid_argument` será gerada se o argumento `pContext` tem o valor `NULL`.  
  
 `invalid_operation` será gerada se o argumento `pContext` não representa o contexto de execução foi mais recentemente enviado por essa raiz virtual do processador.  
  
 O ato de ativação de uma raiz virtual do processador aumenta o nível de assinatura do thread de hardware subjacentes por um. Para obter mais informações sobre os níveis de assinatura, consulte [iexecutionresource:: Currentsubscriptionlevel](iexecutionresource-structure.md#currentsubscriptionlevel).  
  
##  <a name="deactivate"></a>  Método ivirtualprocessorroot:: Deactivate  
 Faz com que o proxy de thread em execução no momento na raiz desse processador virtual para interromper a expedir o contexto de execução. O proxy de thread continuará em execução em uma chamada para o `Activate` método.  
  
```
virtual bool Deactivate(_Inout_ IExecutionContext* pContext) = 0;
```  
  
### <a name="parameters"></a>Parâmetros  
*pContext*<br/>
O contexto que atualmente está sendo enviado por essa raiz.  
  
### <a name="return-value"></a>Valor de retorno  
 Um valor booliano. Um valor de `true` indica que o proxy de thread retornado do `Deactivate` método em resposta a uma chamada para o `Activate` método. Um valor de `false` indica que o proxy de thread retornado do método em resposta a um evento de notificação no Gerenciador de recursos. Em um modo de usuário agendáveis (UMS) Agendador de threads, isso indica que apareceram itens na lista de conclusão do Agendador e o Agendador é necessária para lidar com eles.  
  
### <a name="remarks"></a>Comentários  
 Use esse método para interromper temporariamente a execução de uma raiz virtual do processador quando você não pode localizar qualquer trabalho em seu Agendador. Uma chamada para o `Deactivate` método deve se originar de dentro de `Dispatch` método do contexto de execução que a raiz do processador virtual foi ativada pela última vez com. Em outras palavras, o proxy de thread invocando o `Deactivate` método deve ser aquele que está sendo executado na raiz do processador virtual. Chamar o método em uma raiz de processador virtual que não estão em execução no pode resultar em comportamento indefinido.  
  
 Uma raiz de processador virtual desativado pode ser ativada com uma chamada para o `Activate` método, com o mesmo argumento que foi passado para o `Deactivate` método. O Agendador é responsável por garantir que chamadas para o `Activate` e `Deactivate` métodos são emparelhados, mas eles não são necessários para ser recebida em uma ordem específica. O Gerenciador de recursos pode manipular o recebimento de uma chamada para o `Activate` método antes de receber uma chamada para o `Deactivate` método foi criado.  
  
 Se uma raiz virtual do processador desperta e o valor de retorno a `Deactivate` método é o valor `false`, o Agendador deve consultar a lista de conclusão de UMS via o `IUMSCompletionList::GetUnblockNotifications` método, agir sobre essas informações e, em seguida, chamar subsequentemente o `Deactivate`método novamente. Isso deve ser repetido até que o `Deactivate` método retorna o valor `true`.  
  
 `invalid_argument` será gerada se o argumento `pContext` tem o valor `NULL`.  
  
 `invalid_operation` será gerada se a raiz do processador virtual nunca tiver sido ativado, ou o argumento `pContext` não representa o contexto de execução foi mais recentemente enviado por essa raiz virtual do processador.  
  
 O ato de desativar uma raiz virtual do processador diminui o nível de assinatura do thread de hardware subjacente. Para obter mais informações sobre os níveis de assinatura, consulte [iexecutionresource:: Currentsubscriptionlevel](iexecutionresource-structure.md#currentsubscriptionlevel).  
  
##  <a name="ensurealltasksvisible"></a>  Método ivirtualprocessorroot:: Ensurealltasksvisible  
 Faz com que os dados armazenados na hierarquia de memória de processadores individuais se torne visível para todos os processadores no sistema. Isso garante que um limite de memória completo foi executado em todos os processadores antes do método retorna.  
  
```
virtual void EnsureAllTasksVisible(_Inout_ IExecutionContext* pContext) = 0;
```  
  
### <a name="parameters"></a>Parâmetros  
*pContext*<br/>
O contexto que está atualmente sendo enviado por essa raiz virtual do processador.  
  
### <a name="remarks"></a>Comentários  
 Você pode ser útil quando você deseja sincronizar a desativação de uma raiz de processador virtual com a adição de novos trabalhos no Agendador. Por motivos de desempenho, você pode decidir adicionar itens de trabalho para seu Agendador sem executar uma barreira de memória, o que significa que os itens de trabalho adicionados por um thread em execução em um processador não ficam imediatamente visíveis para todos os outros processadores. Usando esse método em conjunto com o `Deactivate` raízes de método, você pode garantir que seu Agendador não desativar seu processador virtual enquanto os itens de trabalho existem nas coleções do seu Agendador.  
  
 Uma chamada para o `EnsureAllTasksVisibleThe` método deve se originar de dentro de `Dispatch` método do contexto de execução que a raiz do processador virtual foi ativada pela última vez com. Em outras palavras, o proxy de thread invocando o `EnsureAllTasksVisible` método deve ser aquele que está sendo executado na raiz do processador virtual. Chamar o método em uma raiz de processador virtual que não estão em execução no pode resultar em comportamento indefinido.  
  
 `invalid_argument` será gerada se o argumento `pContext` tem o valor `NULL`.  
  
 `invalid_operation` será gerada se a raiz do processador virtual nunca tiver sido ativado, ou o argumento `pContext` não representa o contexto de execução foi mais recentemente enviado por essa raiz virtual do processador.  
  
##  <a name="getid"></a>  Método ivirtualprocessorroot:: GetID  
 Retorna um identificador exclusivo para a raiz do processador virtual.  
  
```
virtual unsigned int GetId() const = 0;
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um identificador de inteiro.  
  
## <a name="see-also"></a>Consulte também  
 [Namespace de simultaneidade](concurrency-namespace.md)
