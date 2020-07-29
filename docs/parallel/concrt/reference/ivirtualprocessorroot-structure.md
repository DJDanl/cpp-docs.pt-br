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
ms.openlocfilehash: 869d51144b686dd684f62b337bb90eff8a9a5589
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87193946"
---
# <a name="ivirtualprocessorroot-structure"></a>Estrutura IVirtualProcessorRoot

Uma abstração para um thread de hardware no qual um proxy de thread pode ser executado.

## <a name="syntax"></a>Sintaxe

```cpp
struct IVirtualProcessorRoot : public IExecutionResource;
```

## <a name="members"></a>Membros

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[IVirtualProcessorRoot:: ativar](#activate)|Faz com que o proxy de thread associado à interface de contexto de execução `pContext` inicie a execução nessa raiz do processador virtual.|
|[IVirtualProcessorRoot::D eactivate](#deactivate)|Faz com que o proxy de thread atualmente em execução nesta raiz do processador virtual pare de expedir o contexto de execução. O proxy de thread continuará executando em uma chamada para o `Activate` método.|
|[IVirtualProcessorRoot::EnsureAllTasksVisible](#ensurealltasksvisible)|Faz com que os dados armazenados na hierarquia de memória de processadores individuais se tornem visíveis para todos os processadores no sistema. Ele garante que um limite de memória completa tenha sido executado em todos os processadores antes que o método seja retornado.|
|[IVirtualProcessorRoot:: GetId](#getid)|Retorna um identificador exclusivo para a raiz do processador virtual.|

## <a name="remarks"></a>Comentários

Cada raiz de processador virtual tem um recurso de execução associado. A `IVirtualProcessorRoot` interface herda da interface [IExecutionResource](iexecutionresource-structure.md) . Várias raízes de processador virtual podem corresponder ao mesmo thread de hardware subjacente.

O Gerenciador de recursos concede raízes de processador virtual a agendadores em resposta a solicitações de recursos. Um Agendador pode usar uma raiz de processador virtual para executar o trabalho ativando-o com um contexto de execução.

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[IExecutionResource](iexecutionresource-structure.md)

`IVirtualProcessorRoot`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** concrtrm. h

**Namespace:** simultaneidade

## <a name="ivirtualprocessorrootactivate-method"></a><a name="activate"></a>Método IVirtualProcessorRoot:: Activate

Faz com que o proxy de thread associado à interface de contexto de execução `pContext` inicie a execução nessa raiz do processador virtual.

```cpp
virtual void Activate(_Inout_ IExecutionContext* pContext) = 0;
```

### <a name="parameters"></a>parâmetros

*pContext*<br/>
Uma interface para o contexto de execução que será expedida nesta raiz do processador virtual.

### <a name="remarks"></a>Comentários

O Gerenciador de recursos fornecerá um proxy de thread se um não estiver associado à interface de contexto de execução`pContext`

O `Activate` método pode ser usado para iniciar a execução do trabalho em uma nova raiz de processador virtual retornada pelo Gerenciador de recursos ou para retomar o proxy de thread em uma raiz de processador virtual que foi desativada ou está prestes a ser desativada. Consulte [IVirtualProcessorRoot::D eactivate](#deactivate) para obter mais informações sobre a desativação. Quando você estiver retomando uma raiz do processador virtual desativado, o parâmetro `pContext` deverá ser o mesmo que o parâmetro usado para desativar a raiz do processador virtual.

Depois que uma raiz do processador virtual tiver sido ativada pela primeira vez, pares subsequentes de chamadas para `Deactivate` e `Activate` podem ser corridas entre si. Isso significa que é aceitável que o Gerenciador de recursos receba uma chamada `Activate` antes de receber a `Deactivate` chamada para a qual foi destinado.

Ao ativar uma raiz de processador virtual, você sinaliza ao Gerenciador de recursos que essa raiz do processador virtual está ocupada atualmente com o trabalho. Se o Agendador não conseguir encontrar nenhum trabalho a ser executado nessa raiz, será esperado invocar o `Deactivate` método informando ao Gerenciador de recursos que a raiz do processador virtual está ociosa. O Gerenciador de recursos usa esses dados para balancear a carga do sistema.

`invalid_argument`será gerado se o argumento `pContext` tiver o valor `NULL` .

`invalid_operation`será gerado se o argumento não `pContext` representar o contexto de execução que foi expedido mais recentemente por essa raiz do processador virtual.

O ato de ativar uma raiz de processador virtual aumenta o nível de assinatura do thread de hardware subjacente em um. Para obter mais informações sobre os níveis de assinatura, consulte [IExecutionResource:: CurrentSubscriptionLevel](iexecutionresource-structure.md#currentsubscriptionlevel).

## <a name="ivirtualprocessorrootdeactivate-method"></a><a name="deactivate"></a>IVirtualProcessorRoot: método eactivate de:D

Faz com que o proxy de thread atualmente em execução nesta raiz do processador virtual pare de expedir o contexto de execução. O proxy de thread continuará executando em uma chamada para o `Activate` método.

```cpp
virtual bool Deactivate(_Inout_ IExecutionContext* pContext) = 0;
```

### <a name="parameters"></a>parâmetros

*pContext*<br/>
O contexto que está sendo expedido atualmente por esta raiz.

### <a name="return-value"></a>Valor retornado

Um valor booliano. Um valor **`true`** indica que o proxy de thread retornou do `Deactivate` método em resposta a uma chamada para o `Activate` método. Um valor **`false`** indica que o proxy de thread retornou do método em resposta a um evento de notificação no Gerenciador de recursos. Em um Agendador de threads de modo de usuário agendáveis (UMS), isso indica que os itens apareciam na lista de conclusão do Agendador e o Agendador é necessário para tratá-los.

### <a name="remarks"></a>Comentários

Use esse método para interromper temporariamente a execução de uma raiz do processador virtual quando não for possível encontrar nenhum trabalho no Agendador. Uma chamada para o `Deactivate` método deve se originar de dentro do `Dispatch` método do contexto de execução no qual a raiz do processador virtual foi ativada pela última vez. Em outras palavras, o proxy de thread que invoca o `Deactivate` método deve ser aquele que está sendo executado no momento na raiz do processador virtual. Chamar o método em uma raiz do processador virtual que você não está executando pode resultar em um comportamento indefinido.

Uma raiz de processador virtual desativada pode ser ativadosda com uma chamada para o `Activate` método, com o mesmo argumento que foi passado para o `Deactivate` método. O Agendador é responsável por garantir que as chamadas para `Activate` os `Deactivate` métodos e sejam emparelhadas, mas elas não precisam ser recebidas em uma ordem específica. O Gerenciador de recursos pode manipular o recebimento de uma chamada para o `Activate` método antes de receber uma chamada para o `Deactivate` método para o qual ele foi destinado.

Se uma raiz do processador virtual for ativada e o valor de retorno do `Deactivate` método for o valor **`false`** , o Agendador deverá consultar a lista de conclusão ums por meio do `IUMSCompletionList::GetUnblockNotifications` método, agir sobre essas informações e depois chamar o `Deactivate` método novamente. Isso deve ser repetido até tal hora, pois o `Deactivate` método retorna o valor **`true`** .

`invalid_argument`será gerado se o argumento `pContext` tiver o valor NULL.

`invalid_operation`será gerado se a raiz do processador virtual nunca tiver sido ativada ou o argumento `pContext` não representar o contexto de execução que foi expedida mais recentemente por essa raiz do processador virtual.

O ato de desativar uma raiz de processador virtual diminui o nível de assinatura do thread de hardware subjacente em um. Para obter mais informações sobre os níveis de assinatura, consulte [IExecutionResource:: CurrentSubscriptionLevel](iexecutionresource-structure.md#currentsubscriptionlevel).

## <a name="ivirtualprocessorrootensurealltasksvisible-method"></a><a name="ensurealltasksvisible"></a>Método IVirtualProcessorRoot:: EnsureAllTasksVisible

Faz com que os dados armazenados na hierarquia de memória de processadores individuais se tornem visíveis para todos os processadores no sistema. Ele garante que um limite de memória completa tenha sido executado em todos os processadores antes que o método seja retornado.

```cpp
virtual void EnsureAllTasksVisible(_Inout_ IExecutionContext* pContext) = 0;
```

### <a name="parameters"></a>parâmetros

*pContext*<br/>
O contexto que está sendo expedido atualmente por esta raiz do processador virtual.

### <a name="remarks"></a>Comentários

Esse método pode ser útil quando você deseja sincronizar a desativação de uma raiz do processador virtual com a adição de um novo trabalho no Agendador. Por motivos de desempenho, você pode decidir adicionar itens de trabalho ao seu Agendador sem executar uma barreira de memória, o que significa que os itens de trabalho adicionados por um thread em execução em um processador não ficam visíveis imediatamente para todos os outros processadores. Usando esse método em conjunto com o `Deactivate` método, você pode garantir que o Agendador não desative todas as suas raízes de processador virtual enquanto os itens de trabalho existem nas coleções do Agendador.

Uma chamada para o `EnsureAllTasksVisibleThe` método deve se originar de dentro do `Dispatch` método do contexto de execução no qual a raiz do processador virtual foi ativada pela última vez. Em outras palavras, o proxy de thread que invoca o `EnsureAllTasksVisible` método deve ser aquele que está sendo executado no momento na raiz do processador virtual. Chamar o método em uma raiz do processador virtual que você não está executando pode resultar em um comportamento indefinido.

`invalid_argument`será gerado se o argumento `pContext` tiver o valor `NULL` .

`invalid_operation`será gerado se a raiz do processador virtual nunca tiver sido ativada ou o argumento `pContext` não representar o contexto de execução que foi expedida mais recentemente por essa raiz do processador virtual.

## <a name="ivirtualprocessorrootgetid-method"></a><a name="getid"></a>Método IVirtualProcessorRoot:: GetId

Retorna um identificador exclusivo para a raiz do processador virtual.

```cpp
virtual unsigned int GetId() const = 0;
```

### <a name="return-value"></a>Valor retornado

Um identificador de inteiro.

## <a name="see-also"></a>Confira também

[Namespace de simultaneidade](concurrency-namespace.md)
