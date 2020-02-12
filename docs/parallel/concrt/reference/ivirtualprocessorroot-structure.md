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
ms.openlocfilehash: 60757b0edea6b60d080c2175d4df4830ffec0cc3
ms.sourcegitcommit: a8ef52ff4a4944a1a257bdaba1a3331607fb8d0f
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/11/2020
ms.locfileid: "77139889"
---
# <a name="ivirtualprocessorroot-structure"></a>Estrutura IVirtualProcessorRoot

Uma abstração para um thread de hardware no qual um proxy de thread pode ser executado.

## <a name="syntax"></a>Sintaxe

```cpp
struct IVirtualProcessorRoot : public IExecutionResource;
```

## <a name="members"></a>Membros

### <a name="public-methods"></a>Métodos públicos

|{1&gt;Nome&lt;1}|Descrição|
|----------|-----------------|
|[IVirtualProcessorRoot:: ativar](#activate)|Faz com que o proxy de thread associado à interface de contexto de execução `pContext` iniciar a execução nessa raiz do processador virtual.|
|[IVirtualProcessorRoot::D eactivate](#deactivate)|Faz com que o proxy de thread atualmente em execução nesta raiz do processador virtual pare de expedir o contexto de execução. O proxy de thread continuará executando em uma chamada para o método `Activate`.|
|[IVirtualProcessorRoot::EnsureAllTasksVisible](#ensurealltasksvisible)|Faz com que os dados armazenados na hierarquia de memória de processadores individuais se tornem visíveis para todos os processadores no sistema. Ele garante que um limite de memória completa tenha sido executado em todos os processadores antes que o método seja retornado.|
|[IVirtualProcessorRoot:: GetId](#getid)|Retorna um identificador exclusivo para a raiz do processador virtual.|

## <a name="remarks"></a>Comentários

Cada raiz de processador virtual tem um recurso de execução associado. A interface de `IVirtualProcessorRoot` herda da interface [IExecutionResource](iexecutionresource-structure.md) . Várias raízes de processador virtual podem corresponder ao mesmo thread de hardware subjacente.

O Gerenciador de recursos concede raízes de processador virtual a agendadores em resposta a solicitações de recursos. Um Agendador pode usar uma raiz de processador virtual para executar o trabalho ativando-o com um contexto de execução.

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[IExecutionResource](iexecutionresource-structure.md)

`IVirtualProcessorRoot`

## <a name="requirements"></a>{1&gt;{2&gt;Requisitos&lt;2}&lt;1}

**Cabeçalho:** concrtrm. h

**Namespace:** simultaneidade

## <a name="activate"></a>Método IVirtualProcessorRoot:: Activate

Faz com que o proxy de thread associado à interface de contexto de execução `pContext` iniciar a execução nessa raiz do processador virtual.

```cpp
virtual void Activate(_Inout_ IExecutionContext* pContext) = 0;
```

### <a name="parameters"></a>Parâmetros

*pContext*<br/>
Uma interface para o contexto de execução que será expedida nesta raiz do processador virtual.

### <a name="remarks"></a>Comentários

O Gerenciador de recursos fornecerá um proxy de thread se um não estiver associado à interface de contexto de execução `pContext`

O método `Activate` pode ser usado para iniciar a execução do trabalho em uma nova raiz de processador virtual retornada pelo Gerenciador de recursos ou para retomar o proxy de thread em uma raiz de processador virtual que tenha sido desativada ou que esteja prestes a ser desativada. Consulte [IVirtualProcessorRoot::D eactivate](#deactivate) para obter mais informações sobre a desativação. Quando você estiver retomando uma raiz do processador virtual desativado, o parâmetro `pContext` deverá ser o mesmo que o parâmetro usado para desativar a raiz do processador virtual.

Depois que uma raiz do processador virtual tiver sido ativada pela primeira vez, pares subsequentes de chamadas para `Deactivate` e `Activate` poderão se comracer entre si. Isso significa que é aceitável que o Gerenciador de recursos receba uma chamada para `Activate` antes de receber a chamada de `Deactivate` para a qual foi destinada.

Ao ativar uma raiz de processador virtual, você sinaliza ao Gerenciador de recursos que essa raiz do processador virtual está ocupada atualmente com o trabalho. Se o Agendador não conseguir encontrar nenhum trabalho a ser executado nessa raiz, será esperado invocar o método `Deactivate` informando ao Gerenciador de recursos que a raiz do processador virtual está ociosa. O Gerenciador de recursos usa esses dados para balancear a carga do sistema.

`invalid_argument` será gerada se o argumento `pContext` tiver o valor `NULL`.

`invalid_operation` será gerada se o argumento `pContext` não representar o contexto de execução que foi expedida mais recentemente por essa raiz do processador virtual.

O ato de ativar uma raiz de processador virtual aumenta o nível de assinatura do thread de hardware subjacente em um. Para obter mais informações sobre os níveis de assinatura, consulte [IExecutionResource:: CurrentSubscriptionLevel](iexecutionresource-structure.md#currentsubscriptionlevel).

## <a name="deactivate"></a>IVirtualProcessorRoot: método eactivate de:D

Faz com que o proxy de thread atualmente em execução nesta raiz do processador virtual pare de expedir o contexto de execução. O proxy de thread continuará executando em uma chamada para o método `Activate`.

```cpp
virtual bool Deactivate(_Inout_ IExecutionContext* pContext) = 0;
```

### <a name="parameters"></a>Parâmetros

*pContext*<br/>
O contexto que está sendo expedido atualmente por esta raiz.

### <a name="return-value"></a>Valor retornado

Um valor booliano. Um valor **true** indica que o proxy de thread retornou do método `Deactivate` em resposta a uma chamada para o método `Activate`. Um valor de `false` indica que o proxy de thread retornou do método em resposta a um evento de notificação no Gerenciador de recursos. Em um Agendador de threads de modo de usuário agendáveis (UMS), isso indica que os itens apareciam na lista de conclusão do Agendador e o Agendador é necessário para tratá-los.

### <a name="remarks"></a>Comentários

Use esse método para interromper temporariamente a execução de uma raiz do processador virtual quando não for possível encontrar nenhum trabalho no Agendador. Uma chamada para o método `Deactivate` deve se originar de dentro do método `Dispatch` do contexto de execução no qual a raiz do processador virtual foi ativada pela última vez. Em outras palavras, o proxy de thread que invoca o método `Deactivate` deve ser aquele que está sendo executado atualmente na raiz do processador virtual. Chamar o método em uma raiz do processador virtual que você não está executando pode resultar em um comportamento indefinido.

Uma raiz de processador virtual desativada pode ser ativadosda com uma chamada para o método `Activate`, com o mesmo argumento que foi passado para o método `Deactivate`. O Agendador é responsável por garantir que as chamadas para os métodos `Activate` e `Deactivate` sejam emparelhadas, mas não precisam ser recebidas em uma ordem específica. O Gerenciador de recursos pode manipular o recebimento de uma chamada para o método `Activate` antes de receber uma chamada para o método de `Deactivate` para o qual ele foi destinado.

Se uma raiz do processador virtual for ativada e o valor de retorno do método `Deactivate` for o valor **false**, o Agendador deverá consultar a lista de conclusão de ums por meio do método `IUMSCompletionList::GetUnblockNotifications`, agir nessas informações e depois chamar o método `Deactivate` novamente. Isso deve ser repetido até o momento em que o método `Deactivate` retorna o valor `true`.

`invalid_argument` será gerada se o argumento `pContext` tiver o valor NULL.

`invalid_operation` será lançada se a raiz do processador virtual nunca tiver sido ativada ou o argumento `pContext` não representar o contexto de execução que foi expedida mais recentemente por essa raiz do processador virtual.

O ato de desativar uma raiz de processador virtual diminui o nível de assinatura do thread de hardware subjacente em um. Para obter mais informações sobre os níveis de assinatura, consulte [IExecutionResource:: CurrentSubscriptionLevel](iexecutionresource-structure.md#currentsubscriptionlevel).

## <a name="ensurealltasksvisible"></a>Método IVirtualProcessorRoot:: EnsureAllTasksVisible

Faz com que os dados armazenados na hierarquia de memória de processadores individuais se tornem visíveis para todos os processadores no sistema. Ele garante que um limite de memória completa tenha sido executado em todos os processadores antes que o método seja retornado.

```cpp
virtual void EnsureAllTasksVisible(_Inout_ IExecutionContext* pContext) = 0;
```

### <a name="parameters"></a>Parâmetros

*pContext*<br/>
O contexto que está sendo expedido atualmente por esta raiz do processador virtual.

### <a name="remarks"></a>Comentários

Esse método pode ser útil quando você deseja sincronizar a desativação de uma raiz do processador virtual com a adição de um novo trabalho no Agendador. Por motivos de desempenho, você pode decidir adicionar itens de trabalho ao seu Agendador sem executar uma barreira de memória, o que significa que os itens de trabalho adicionados por um thread em execução em um processador não ficam visíveis imediatamente para todos os outros processadores. Usando esse método em conjunto com o método `Deactivate`, você pode garantir que o Agendador não desative todas as suas raízes de processador virtual enquanto os itens de trabalho existem nas coleções do Agendador.

Uma chamada para o método `EnsureAllTasksVisibleThe` deve se originar de dentro do método `Dispatch` do contexto de execução no qual a raiz do processador virtual foi ativada pela última vez. Em outras palavras, o proxy de thread que invoca o método `EnsureAllTasksVisible` deve ser aquele que está sendo executado atualmente na raiz do processador virtual. Chamar o método em uma raiz do processador virtual que você não está executando pode resultar em um comportamento indefinido.

`invalid_argument` será gerada se o argumento `pContext` tiver o valor `NULL`.

`invalid_operation` será lançada se a raiz do processador virtual nunca tiver sido ativada ou o argumento `pContext` não representar o contexto de execução que foi expedida mais recentemente por essa raiz do processador virtual.

## <a name="getid"></a>Método IVirtualProcessorRoot:: GetId

Retorna um identificador exclusivo para a raiz do processador virtual.

```cpp
virtual unsigned int GetId() const = 0;
```

### <a name="return-value"></a>Valor retornado

Um identificador de inteiro.

## <a name="see-also"></a>Consulte também

[Namespace de simultaneidade](concurrency-namespace.md)
