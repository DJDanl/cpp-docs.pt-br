---
title: Estrutura IVirtualProcessorRoot
ms.date: 11/04/2016
f1_keywords:
- IVirtualProcessorRoot
- CONCRTRM/concurrency::IVirtualProcessorRoot
- CONCRTRM/concurrency::IVirtualProcessorRoot::IVirtualProcessorRoot::Activate
- CONCRTRM/concurrency::IVirtualProcessorRoot::IVirtualProcessorRoot::Deactivate
- CONCRTRM/concurrency::IVirtualProcessorRoot::IVirtualProcessorRoot::EnsureAllTasksVisible
- CONCRTRM/concurrency::IVirtualProcessorRoot::IVirtualProcessorRoot::GetId
helpviewer_keywords:
- IVirtualProcessorRoot structure
ms.assetid: 5ef371b8-9e4f-4fef-bb0d-49099693dd2b
ms.openlocfilehash: f642a29d0a80568f7a5f2a5e89f6951d4819243e
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81364257"
---
# <a name="ivirtualprocessorroot-structure"></a>Estrutura IVirtualProcessorRoot

Uma abstração para um segmento de hardware no qual um proxy de segmento pode executar.

## <a name="syntax"></a>Sintaxe

```cpp
struct IVirtualProcessorRoot : public IExecutionResource;
```

## <a name="members"></a>Membros

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[iVirtualProcessorroot::Ativar](#activate)|Faz com que o proxy `pContext` de segmento associado à interface de contexto de execução comece a ser executado nesta raiz de processador virtual.|
|[iVirtualProcessorRoot::Deactivate](#deactivate)|Faz com que o proxy de thread atualmente em execução nesta raiz do processador virtual pare de despachar o contexto de execução. O proxy de segmento retomará a `Activate` execução em uma chamada para o método.|
|[iVirtualProcessorroot::ensureAllTasksvisible](#ensurealltasksvisible)|Faz com que os dados armazenados na hierarquia de memória de processadores individuais se tornem visíveis para todos os processadores do sistema. Ele garante que uma cerca de memória completa tenha sido executada em todos os processadores antes que o método retorne.|
|[iVirtualProcessorRoot::GetId](#getid)|Retorna um identificador exclusivo para a raiz do processador virtual.|

## <a name="remarks"></a>Comentários

Cada raiz de processador virtual tem um recurso de execução associado. A `IVirtualProcessorRoot` interface herda da interface [IExecutionResource.](iexecutionresource-structure.md) Várias raízes do processador virtual podem corresponder ao mesmo segmento de hardware subjacente.

O Gerenciador de Recursos concede raízes de processadores virtuais a agendadores em resposta a solicitações de recursos. Um agendador pode usar uma raiz de processador virtual para realizar o trabalho ativando-o com um contexto de execução.

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[Iexecutionresource](iexecutionresource-structure.md)

`IVirtualProcessorRoot`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** concrtrm.h

**Namespace:** concurrency

## <a name="ivirtualprocessorrootactivate-method"></a><a name="activate"></a>IVirtualProcessorRoot::Activate Method

Faz com que o proxy `pContext` de segmento associado à interface de contexto de execução comece a ser executado nesta raiz de processador virtual.

```cpp
virtual void Activate(_Inout_ IExecutionContext* pContext) = 0;
```

### <a name="parameters"></a>Parâmetros

*pContext*<br/>
Uma interface para o contexto de execução que será despachada nesta raiz de processador virtual.

### <a name="remarks"></a>Comentários

O Gerenciador de recursos fornecerá um proxy de segmento se não estiver associado à interface de contexto de execução`pContext`

O `Activate` método pode ser usado para começar a executar o trabalho em uma nova raiz de processador virtual retornada pelo Gerenciador de recursos, ou para retomar o proxy de thread em uma raiz de processador virtual que desativou ou está prestes a desativar. Consulte [IVirtualProcessorRoot::Deactivate](#deactivate) para obter mais informações sobre a desativação. Quando você está retomando uma raiz de `pContext` processador virtual desativada, o parâmetro deve ser o mesmo que o parâmetro usado para desativar a raiz do processador virtual.

Uma vez que uma raiz de processador virtual tenha sido `Deactivate` ativada pela primeira vez, pares subsequentes de chamadas para e `Activate` podem correr entre si. Isso significa que é aceitável que o Gerenciador de Recursos receba uma chamada antes `Activate` de receber a chamada para a `Deactivate` sua intenção.

Quando você ativa uma raiz de processador virtual, você sinaliza para o Gerenciador de recursos que essa raiz de processador virtual está atualmente ocupada com o trabalho. Se o seu agendador não encontrar qualquer trabalho para executar `Deactivate` nesta raiz, espera-se que ele invoque o método informando ao Gerenciador de Recursos que a raiz do processador virtual está ociosa. O Gerenciador de Recursos usa esses dados para carregar o equilíbrio do sistema.

`invalid_argument`é jogado se `pContext` o `NULL`argumento tem o valor .

`invalid_operation`é jogado se `pContext` o argumento não representa o contexto de execução que foi despachado mais recentemente por esta raiz de processador virtual.

O ato de ativar uma raiz de processador virtual aumenta o nível de assinatura do segmento de hardware subjacente por um. Para obter mais informações sobre os níveis de assinatura, consulte [IExecutionResource::CurrentSubscriptionLevel](iexecutionresource-structure.md#currentsubscriptionlevel).

## <a name="ivirtualprocessorrootdeactivate-method"></a><a name="deactivate"></a>IVirtualProcessorRoot::Deactivate Method

Faz com que o proxy de thread atualmente em execução nesta raiz do processador virtual pare de despachar o contexto de execução. O proxy de segmento retomará a `Activate` execução em uma chamada para o método.

```cpp
virtual bool Deactivate(_Inout_ IExecutionContext* pContext) = 0;
```

### <a name="parameters"></a>Parâmetros

*pContext*<br/>
O contexto que está sendo despachado por essa raiz.

### <a name="return-value"></a>Valor retornado

Um valor booliano. Um valor de **verdade** indica que o `Deactivate` proxy de segmento retornou do método em resposta a uma chamada para o `Activate` método. Um valor `false` de indica que o proxy de segmento retornou do método em resposta a um evento de notificação no Gerenciador de recursos. Em um agendador de thread sumable (ums) de modo de usuário, isso indica que os itens apareceram na lista de conclusão do agendador, e o agendador é necessário para manuseá-los.

### <a name="remarks"></a>Comentários

Use este método para parar temporariamente a execução de uma raiz de processador virtual quando você não encontrar qualquer trabalho em seu agendador. Uma chamada `Deactivate` para o método `Dispatch` deve se originar dentro do método do contexto de execução com o qual a raiz do processador virtual foi ativada pela última vez. Em outras palavras, o `Deactivate` proxy de thread invocando o método deve ser o que está sendo executado atualmente na raiz do processador virtual. Chamar o método em uma raiz de processador virtual que você não está executando pode resultar em um comportamento indefinido.

Uma raiz de processador virtual desativada pode `Activate` ser acordada com uma chamada para `Deactivate` o método, com o mesmo argumento que foi passado para o método. O agendador é responsável por garantir `Activate` `Deactivate` que as chamadas e os métodos sejam emparelhados, mas eles não são obrigados a serem recebidos em uma ordem específica. O Gerenciador de Recursos pode `Activate` lidar com o recebimento `Deactivate` de uma chamada para o método antes de receber uma chamada para o método para o seu método.

Se uma raiz de processador virtual despertar `Deactivate` e o valor de retorno do método for o `IUMSCompletionList::GetUnblockNotifications` valor **falso,** o agendador deve consultar a lista de conclusão da UMS através do método, agir sobre essas informações e, posteriormente, chamar o `Deactivate` método novamente. Isso deve ser repetido até `Deactivate` que o `true`método devolva o valor.

`invalid_argument`é jogado se `pContext` o argumento tem o valor NULO.

`invalid_operation`é jogado se a raiz do processador virtual `pContext` nunca foi ativada, ou o argumento não representa o contexto de execução que foi despachado mais recentemente por essa raiz de processador virtual.

O ato de desativar uma raiz de processador virtual diminui o nível de assinatura do segmento de hardware subjacente por um. Para obter mais informações sobre os níveis de assinatura, consulte [IExecutionResource::CurrentSubscriptionLevel](iexecutionresource-structure.md#currentsubscriptionlevel).

## <a name="ivirtualprocessorrootensurealltasksvisible-method"></a><a name="ensurealltasksvisible"></a>IVirtualProcessorRoot::EnsureAllTasksVisible Method

Faz com que os dados armazenados na hierarquia de memória de processadores individuais se tornem visíveis para todos os processadores do sistema. Ele garante que uma cerca de memória completa tenha sido executada em todos os processadores antes que o método retorne.

```cpp
virtual void EnsureAllTasksVisible(_Inout_ IExecutionContext* pContext) = 0;
```

### <a name="parameters"></a>Parâmetros

*pContext*<br/>
O contexto que está sendo despachado por essa raiz de processador virtual.

### <a name="remarks"></a>Comentários

Você pode achar este método útil quando quiser sincronizar a desativação de uma raiz de processador virtual com a adição de um novo trabalho no agendador. Por razões de desempenho, você pode decidir adicionar itens de trabalho ao seu agendador sem executar uma barreira de memória, o que significa que itens de trabalho adicionados por um thread executando em um processador não são imediatamente visíveis para todos os outros processadores. Ao usar este método `Deactivate` em conjunto com o método, você pode garantir que seu agendador não desative todas as suas raízes de processador virtual enquanto existem itens de trabalho nas coleções do seu agendador.

Uma chamada `EnsureAllTasksVisibleThe` para o método `Dispatch` deve se originar dentro do método do contexto de execução com o qual a raiz do processador virtual foi ativada pela última vez. Em outras palavras, o `EnsureAllTasksVisible` proxy de thread invocando o método deve ser o que está sendo executado atualmente na raiz do processador virtual. Chamar o método em uma raiz de processador virtual que você não está executando pode resultar em um comportamento indefinido.

`invalid_argument`é jogado se `pContext` o `NULL`argumento tem o valor .

`invalid_operation`é jogado se a raiz do processador virtual `pContext` nunca foi ativada, ou o argumento não representa o contexto de execução que foi despachado mais recentemente por essa raiz de processador virtual.

## <a name="ivirtualprocessorrootgetid-method"></a><a name="getid"></a>IVirtualProcessorRoot::GetId Method

Retorna um identificador exclusivo para a raiz do processador virtual.

```cpp
virtual unsigned int GetId() const = 0;
```

### <a name="return-value"></a>Valor retornado

Um identificador inteiro.

## <a name="see-also"></a>Confira também

[namespace de concorrência](concurrency-namespace.md)
