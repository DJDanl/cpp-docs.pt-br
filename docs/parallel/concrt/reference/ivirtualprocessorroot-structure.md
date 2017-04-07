---
title: Estrutura IVirtualProcessorRoot | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: article
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
caps.latest.revision: 18
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
ms.openlocfilehash: 2635f1c18dd61127360b8398ad1b0da03f1666d7
ms.lasthandoff: 03/17/2017

---
# <a name="ivirtualprocessorroot-structure"></a>Estrutura IVirtualProcessorRoot
Uma abstração de um thread de hardware no qual um proxy de thread pode executar.  
  
## <a name="syntax"></a>Sintaxe  
  
```
struct IVirtualProcessorRoot : public IExecutionResource;
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-methods"></a>Métodos Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[Ivirtualprocessorroot](#activate)|Faz com que o proxy thread associado à interface de contexto de execução `pContext` para iniciar a execução na raiz desse processador virtual.|  
|[Ivirtualprocessorroot](#deactivate)|Faz com que o proxy de thread em execução na raiz desse processador virtual para expedir o contexto de execução. O proxy thread continuará em execução em uma chamada para o `Activate` método.|  
|[Ivirtualprocessorroot](#ensurealltasksvisible)|Faz com que os dados armazenados na hierarquia de memória de processadores individuais se tornem visíveis para todos os processadores no sistema. Isso garante que um limite de memória completo foi executado em todos os processadores antes do método retorna.|  
|[Ivirtualprocessorroot](#getid)|Retorna um identificador exclusivo para a raiz do processador virtual.|  
  
## <a name="remarks"></a>Comentários  
 Raiz de cada processador virtual tem um recurso de execução associadas. O `IVirtualProcessorRoot` interface herda o [IExecutionResource](iexecutionresource-structure.md) interface. Várias raízes de processador virtual podem corresponder ao mesmo segmento hardware subjacente.  
  
 O Gerenciador de recursos concede raízes do processador virtual para agendadores em resposta a solicitações de recursos. Um programador pode usar uma raiz de processador virtual para realizar o trabalho ativando-o com um contexto de execução.  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 [IExecutionResource](iexecutionresource-structure.md)  
  
 `IVirtualProcessorRoot`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** concrtrm. h  
  
 **Namespace:** simultaneidade  
  
##  <a name="activate"></a>Método Ivirtualprocessorroot::  
 Faz com que o proxy thread associado à interface de contexto de execução `pContext` para iniciar a execução na raiz desse processador virtual.  
  
```
virtual void Activate(_Inout_ IExecutionContext* pContext) = 0;
```  
  
### <a name="parameters"></a>Parâmetros  
 `pContext`  
 Uma interface para o contexto de execução será enviado na raiz desse processador virtual.  
  
### <a name="remarks"></a>Comentários  
 O Gerenciador de recursos fornecerá um proxy de thread se um não está associado com a interface de contexto de execução`pContext`  
  
 O `Activate` método pode ser usado para iniciar a execução do trabalho em uma nova raiz de processador virtual retornada pelo Gerenciador de recursos ou retomar o proxy de thread em uma raiz de processador virtual que foi desativado ou está prestes a desativar. Consulte [Ivirtualprocessorroot](#deactivate) para obter mais informações sobre a desativação. Quando você está retomando uma raiz de processador virtual desativado, o parâmetro `pContext` deve ser o mesmo que o parâmetro usado para desativar a raiz do processador virtual.  
  
 Depois de uma raiz de processador virtual tiver sido ativada pela primeira vez, subsequentes pares de chamadas para `Deactivate` e `Activate` poderão rapidamente entre si. Isso significa que é aceitável para o Gerenciador de recursos para receber uma chamada para `Activate` antes de receber o `Deactivate` chamada foi criado.  
  
 Quando você ativa uma raiz virtual do processador, sinalizar para o Gerenciador de recursos que a raiz desse processador virtual está ocupado com o trabalho. Se o Agendador não conseguir localizar qualquer trabalho para executar essa raiz, ele deve chamar o `Deactivate` método informando o Gerenciador de recursos que a raiz virtual do processador está ociosa. O Gerenciador de recursos usa esses dados para o sistema de balanceamento de carga.  
  
 `invalid_argument`é lançada se o argumento `pContext` tem o valor `NULL`.  
  
 `invalid_operation`é lançada se o argumento `pContext` não representa o contexto de execução que recentemente foi enviado pela raiz desse processador virtual.  
  
 O ato de ativação de uma raiz de processador virtual aumenta o nível de assinatura do thread de hardware subjacentes por um. Para obter mais informações sobre níveis de assinatura, consulte [Currentsubscriptionlevel](iexecutionresource-structure.md#currentsubscriptionlevel).  
  
##  <a name="deactivate"></a>Método Ivirtualprocessorroot::  
 Faz com que o proxy de thread em execução na raiz desse processador virtual para expedir o contexto de execução. O proxy thread continuará em execução em uma chamada para o `Activate` método.  
  
```
virtual bool Deactivate(_Inout_ IExecutionContext* pContext) = 0;
```  
  
### <a name="parameters"></a>Parâmetros  
 `pContext`  
 O contexto que está atualmente sendo despachado por essa raiz.  
  
### <a name="return-value"></a>Valor de retorno  
 Um valor booleano. Um valor de `true` indica que o proxy de thread retornado do `Deactivate` método em resposta a uma chamada para o `Activate` método. Um valor de `false` indica que o proxy de thread retornado do método em resposta a um evento de notificação no Gerenciador de recursos. Em um modo de usuário agendáveis () thread Agendador UMS, isso indica que itens aparecerem na lista de conclusão do Agendador e o Agendador é necessária para lidar com eles.  
  
### <a name="remarks"></a>Comentários  
 Use esse método para interromper temporariamente a raiz de um processador virtual em execução quando não é possível encontrar nenhum trabalho no Agendador. Uma chamada para o `Deactivate` método deve se originar de dentro do `Dispatch` método o contexto de execução que a raiz do processador virtual foi ativada pela última vez com. Em outras palavras, o proxy thread chamar o `Deactivate` método deve ser aquele que está sendo executado na raiz do processador virtual. Chamando o método em uma raiz de processadores virtuais que não está em execução no pode resultar em um comportamento indefinido.  
  
 Uma raiz de desativado processador virtual pode ser ativada com uma chamada para o `Activate` método com o mesmo argumento foi passado para o `Deactivate` método. O Agendador é responsável por garantir que chama o `Activate` e `Deactivate` métodos estão emparelhados, mas eles não são necessários para ser recebida em uma ordem específica. O Gerenciador de recursos pode manipular receber uma chamada para o `Activate` método antes de receber uma chamada para o `Deactivate` método foi criado.  
  
 Se uma raiz de processador virtual fica ativa e o valor de retorno a `Deactivate` método é o valor `false`, o Agendador deve consultar a lista de conclusão UMS via o `IUMSCompletionList::GetUnblockNotifications` método, agir em informações e, posteriormente, chamar o `Deactivate` método novamente. Isso deve ser repetido até o momento em que o `Deactivate` método retorna o valor `true`.  
  
 `invalid_argument`é lançada se o argumento `pContext` tem o valor `NULL`.  
  
 `invalid_operation`será gerada se a raiz do processador virtual nunca tiver sido ativada, ou o argumento `pContext` não representa o contexto de execução que recentemente foi enviado pela raiz desse processador virtual.  
  
 O ato de desativar uma raiz de processador virtual diminui o nível de assinatura do thread de hardware subjacentes. Para obter mais informações sobre níveis de assinatura, consulte [Currentsubscriptionlevel](iexecutionresource-structure.md#currentsubscriptionlevel).  
  
##  <a name="ensurealltasksvisible"></a>Método Ivirtualprocessorroot::  
 Faz com que os dados armazenados na hierarquia de memória de processadores individuais se tornem visíveis para todos os processadores no sistema. Isso garante que um limite de memória completo foi executado em todos os processadores antes do método retorna.  
  
```
virtual void EnsureAllTasksVisible(_Inout_ IExecutionContext* pContext) = 0;
```  
  
### <a name="parameters"></a>Parâmetros  
 `pContext`  
 O contexto que é atualmente sendo enviado pela raiz desse processador virtual.  
  
### <a name="remarks"></a>Comentários  
 Você pode localizar esse método úteis quando você deseja sincronizar a desativação de uma raiz virtual do processador com a adição de novos trabalhos no Agendador. Por motivos de desempenho, você poderá adicionar itens de trabalho para o Agendador sem executar uma barreira de memória, o que significa que itens de trabalho adicionados por um thread em execução em um processador não ficam imediatamente visíveis para todos os outros processadores. Usando esse método em conjunto com o `Deactivate` raízes de método, você pode garantir que o Agendador não desativar todos os seu processador virtual enquanto os itens de trabalho existem nas coleções do Agendador.  
  
 Uma chamada para o `EnsureAllTasksVisibleThe` método deve se originar de dentro do `Dispatch` método o contexto de execução que a raiz do processador virtual foi ativada pela última vez com. Em outras palavras, o proxy thread chamar o `EnsureAllTasksVisible` método deve ser aquele que está sendo executado na raiz do processador virtual. Chamando o método em uma raiz de processadores virtuais que não está em execução no pode resultar em um comportamento indefinido.  
  
 `invalid_argument`é lançada se o argumento `pContext` tem o valor `NULL`.  
  
 `invalid_operation`será gerada se a raiz do processador virtual nunca tiver sido ativada, ou o argumento `pContext` não representa o contexto de execução que recentemente foi enviado pela raiz desse processador virtual.  
  
##  <a name="getid"></a>Método Ivirtualprocessorroot::  
 Retorna um identificador exclusivo para a raiz do processador virtual.  
  
```
virtual unsigned int GetId() const = 0;
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um identificador de inteiro.  
  
## <a name="see-also"></a>Consulte também  
 [Namespace de simultaneidade](concurrency-namespace.md)

