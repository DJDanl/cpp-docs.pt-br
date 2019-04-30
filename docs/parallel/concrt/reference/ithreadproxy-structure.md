---
title: Estrutura IThreadProxy
ms.date: 11/04/2016
f1_keywords:
- IThreadProxy
- CONCRTRM/concurrency::IThreadProxy
- CONCRTRM/concurrency::IThreadProxy::IThreadProxy::GetId
- CONCRTRM/concurrency::IThreadProxy::IThreadProxy::SwitchOut
- CONCRTRM/concurrency::IThreadProxy::IThreadProxy::SwitchTo
- CONCRTRM/concurrency::IThreadProxy::IThreadProxy::YieldToSystem
helpviewer_keywords:
- IThreadProxy structure
ms.assetid: feb89241-a555-4e61-ad48-40add54daeca
ms.openlocfilehash: 906b05800711e89592e5230bec7fa0fe1640379f
ms.sourcegitcommit: c6f8e6c2daec40ff4effd8ca99a7014a3b41ef33
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/24/2019
ms.locfileid: "64346231"
---
# <a name="ithreadproxy-structure"></a>Estrutura IThreadProxy

Uma abstração para um thread de execução. Dependendo do `SchedulerType` chave de política do Agendador, você cria, o Gerenciador de recursos concederá a você um proxy de thread que é apoiado por um thread do Win32 regular ou em um thread (UMS) agendáveis do modo de usuário. Threads UMS são com suporte em sistemas operacionais de 64 bits com a versão do Windows 7 e superior.

## <a name="syntax"></a>Sintaxe

```
struct IThreadProxy;
```

## <a name="members"></a>Membros

### <a name="public-methods"></a>Métodos Públicos

|Nome|Descrição|
|----------|-----------------|
|[IThreadProxy::GetId](#getid)|Retorna um identificador exclusivo para o proxy de thread.|
|[IThreadProxy::SwitchOut](#switchout)|Desassocia o contexto da raiz do processador virtual subjacente.|
|[IThreadProxy::SwitchTo](#switchto)|Executa uma alternância de contexto cooperativo de contexto em execução no momento para um diferente.|
|[IThreadProxy::YieldToSystem](#yieldtosystem)|Faz com que o thread de chamada conceda a execução para outro thread que está pronto para ser executado no processador atual. O sistema operacional seleciona o próximo segmento a ser executado.|

## <a name="remarks"></a>Comentários

Proxies de thread estão acoplados a contextos de execução representados pela interface `IExecutionContext` como uma maneira de distribuir o trabalho.

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`IThreadProxy`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** concrtrm. h

**Namespace:** simultaneidade

##  <a name="getid"></a>  Método ithreadproxy:: GetID

Retorna um identificador exclusivo para o proxy de thread.

```
virtual unsigned int GetId() const = 0;
```

### <a name="return-value"></a>Valor de retorno

Um identificador inteiro exclusivo.

##  <a name="switchout"></a>  Método ithreadproxy:: Switchout

Desassocia o contexto da raiz do processador virtual subjacente.

```
virtual void SwitchOut(SwitchingProxyState switchState = Blocking) = 0;
```

### <a name="parameters"></a>Parâmetros

*switchState*<br/>
Indica o estado do proxy de thread que está executando a opção. O parâmetro é do tipo `SwitchingProxyState`.

### <a name="remarks"></a>Comentários

Use `SwitchOut` se você precisar dissociar um contexto da raiz do processador virtual que está sendo executado, por qualquer motivo. Dependendo do valor você passa para o parâmetro `switchState`, e se ele está em execução em uma raiz virtual do processador, a chamada irá retornar imediatamente ou bloquear o proxy de thread associado ao contexto. É um erro ao chamar `SwitchOut` com o parâmetro definido como `Idle`. Isso resultará em uma [invalid_argument](../../../standard-library/invalid-argument-class.md) exceção.

`SwitchOut` é útil quando você deseja reduzir o número de raízes de processador virtual que seu Agendador tem, porque o Gerenciador de recursos o instruiu a fazê-lo, ou porque foi solicitada uma raiz virtual do processador temporária sobrecarregada e usá-la. Nesse caso, você deve chamar o método [IVirtualProcessorRoot::Remove](iexecutionresource-structure.md#remove) na raiz do processador virtual, antes de fazer uma chamada para `SwitchOut` com o parâmetro `switchState` definido como `Blocking`. Isso bloqueará o proxy de thread e retomará a execução quando uma raiz diferente do processador virtual no Agendador estiver disponível para executá-lo. O proxy de thread de bloqueio pode ser retomado chamando a função `SwitchTo` para alternar para o contexto de execução desse proxy de thread. Você também pode retomar o proxy de thread, por meio de seu contexto associado para ativar uma raiz virtual do processador. Para obter mais informações sobre como fazer isso, consulte [ivirtualprocessorroot:: Activate](ivirtualprocessorroot-structure.md#activate).

`SwitchOut` também pode ser usado quando você deseja reinicializar o processador virtual para que ele possa ser ativado no futuro enquanto o bloquear o proxy de thread ou desanexação temporária da raiz do processador virtual está em execução no, e o Agendador que ele está distribuindo trabalho. Use `SwitchOut` com o parâmetro `switchState` definido como `Blocking` se você deseja bloquear o proxy de thread. Ele pode ser retomado posteriormente usando um `SwitchTo` ou `IVirtualProcessorRoot::Activate` conforme observado acima. Use `SwitchOut` com o parâmetro definido como `Nesting` quando você deseja desanexar temporariamente este proxy de thread da raiz do processador virtual que ele está em execução no, e o Agendador de processador virtual é associado. Chamando `SwitchOut` com o parâmetro `switchState` definido como `Nesting` enquanto ele está em execução em uma raiz de processador virtual fará com que a raiz seja reinicializada e o proxy de thread atual para continuar a executar sem a necessidade de uma. O proxy de thread é considerado precisa deixar o Agendador até que ele chama o [ithreadproxy:: Switchout](#switchout) método com `Blocking` em um momento posterior. A segunda chamada para `SwitchOut` com o parâmetro definido como `Blocking` destina-se para retornar o contexto para um estado bloqueado para que ele pode ser retornado por `SwitchTo` ou `IVirtualProcessorRoot::Activate` nele desanexado do Agendador. Porque ele não estava sendo executada em uma raiz virtual do processador, nenhuma reinicialização ocorre.

Uma raiz de processador virtual reinicializada não é diferente de uma nova raiz de processador virtual que seu Agendador recebeu pelo Gerenciador de recursos. Você pode usá-lo para execução ativando-o com um contexto de execução usando `IVirtualProcessorRoot::Activate`.

`SwitchOut` deve ser chamado no `IThreadProxy` interface que representa o thread em execução no momento ou os resultados são indefinidos.

Em bibliotecas e cabeçalhos que acompanham o Visual Studio 2010, este método não levou um parâmetro e não reinicializa a raiz do processador virtual. Para preservar o comportamento antigo, o valor de parâmetro padrão de `Blocking` é fornecido.

##  <a name="switchto"></a>  Método ithreadproxy:: Switchto

Executa uma alternância de contexto cooperativo de contexto em execução no momento para um diferente.

```
virtual void SwitchTo(
    _Inout_ IExecutionContext* pContext,
    SwitchingProxyState switchState) = 0;
```

### <a name="parameters"></a>Parâmetros

*pContext*<br/>
O contexto de execução cooperativamente alternar para.

*switchState*<br/>
Indica o estado do proxy de thread que está executando a opção. O parâmetro é do tipo `SwitchingProxyState`.

### <a name="remarks"></a>Comentários

Use esse método para alternar do contexto de execução de um para outro, do [iexecutioncontext:: Dispatch](iexecutioncontext-structure.md#dispatch) método do contexto de execução primeiro. O método associa o contexto de execução `pContext` com um proxy de thread se ele não ainda estiver associado a um. A propriedade de proxy de thread atual é determinada pelo valor especificado para o `switchState` argumento.

Use o valor `Idle` quando você deseja retornar o proxy de thread em execução no momento para o Gerenciador de recursos. Chamando `SwitchTo` com o parâmetro `switchState` definido como `Idle` fará com que o contexto de execução `pContext` para iniciar a execução no recurso de execução subjacente. A propriedade de proxy de thread é transferida para o Gerenciador de recursos, e você deve retornar a partir do contexto de execução `Dispatch` método logo após `SwitchTo` retorna, para concluir a transferência. O contexto de execução que o proxy de thread foi expedição é dissociado do proxy de thread e o Agendador está livre para reutilizá-la ou destruí-lo conforme desejar.

Use o valor `Blocking` quando deseja que o proxy de thread para entrar em um estado bloqueado. Chamando `SwitchTo` com o parâmetro `switchState` definido como `Blocking` fará com que o contexto de execução `pContext` para iniciar a execução e bloquear o proxy de thread atual até ser retomada. O Agendador reterá a propriedade do proxy de thread quando o proxy de thread está no `Blocking` estado. O proxy de thread de bloqueio pode ser retomado chamando a função `SwitchTo` para alternar para o contexto de execução desse proxy de thread. Você também pode retomar o proxy de thread, por meio de seu contexto associado para ativar uma raiz virtual do processador. Para obter mais informações sobre como fazer isso, consulte [ivirtualprocessorroot:: Activate](ivirtualprocessorroot-structure.md#activate).

Use o valor `Nesting` quando desejar desanexar temporariamente este proxy de thread da raiz do processador virtual que ele está em execução no, e o Agendador que ele está distribuindo trabalho. Chamando `SwitchTo` com o parâmetro `switchState` definido como `Nesting` fará com que o contexto de execução `pContext` para iniciar a execução e atual proxy de thread também continua a execução sem a necessidade de uma raiz virtual do processador. O proxy de thread é considerado precisa deixar o Agendador até que ele chama o [ithreadproxy:: Switchout](#switchout) método em um momento posterior. O `IThreadProxy::SwitchOut` método poderia bloquear o proxy de thread até que uma raiz virtual do processador está disponível para reagendá-la.

`SwitchTo` deve ser chamado no `IThreadProxy` interface que representa o thread em execução no momento ou os resultados são indefinidos. A função lançará `invalid_argument` se o parâmetro `pContext` é definido como `NULL`.

##  <a name="yieldtosystem"></a>  Método ithreadproxy:: Yieldtosystem

Faz com que o thread de chamada conceda a execução para outro thread que está pronto para ser executado no processador atual. O sistema operacional seleciona o próximo segmento a ser executado.

```
virtual void YieldToSystem() = 0;
```

### <a name="remarks"></a>Comentários

Quando chamado por um proxy de thread apoiado por um thread do Windows regular, `YieldToSystem` se comporta exatamente como a função Windows `SwitchToThread`. No entanto, quando chamado a partir de threads (UMS) agendáveis no modo de usuário, o `SwitchToThread` função delega a tarefa de selecionar o próximo segmento a ser executado para o Agendador de modo de usuário, não o sistema operacional. Para obter o efeito desejado de alternar para outro thread pronto no sistema, use `YieldToSystem`.

`YieldToSystem` deve ser chamado no `IThreadProxy` interface que representa o thread em execução no momento ou os resultados são indefinidos.

## <a name="see-also"></a>Consulte também

[Namespace de simultaneidade](concurrency-namespace.md)<br/>
[Estrutura IExecutionContext](iexecutioncontext-structure.md)<br/>
[Estrutura IScheduler](ischeduler-structure.md)<br/>
[Estrutura IVirtualProcessorRoot](ivirtualprocessorroot-structure.md)
