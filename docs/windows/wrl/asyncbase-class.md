---
title: Classe AsyncBase
ms.date: 10/08/2018
ms.topic: reference
f1_keywords:
- async/Microsoft::WRL::AsyncBase
- async/Microsoft::WRL::AsyncBase::AsyncBase
- async/Microsoft::WRL::AsyncBase::Cancel
- async/Microsoft::WRL::AsyncBase::CheckValidStateForDelegateCall
- async/Microsoft::WRL::AsyncBase::CheckValidStateForResultsCall
- async/Microsoft::WRL::AsyncBase::Close
- async/Microsoft::WRL::AsyncBase::ContinueAsyncOperation
- async/Microsoft::WRL::AsyncBase::CurrentStatus
- async/Microsoft::WRL::AsyncBase::ErrorCode
- async/Microsoft::WRL::AsyncBase::FireCompletion
- async/Microsoft::WRL::AsyncBase::FireProgress
- async/Microsoft::WRL::AsyncBase::get_ErrorCode
- async/Microsoft::WRL::AsyncBase::get_Id
- async/Microsoft::WRL::AsyncBase::get_Status
- async/Microsoft::WRL::AsyncBase::GetOnComplete
- async/Microsoft::WRL::AsyncBase::GetOnProgress
- async/Microsoft::WRL::AsyncBase::OnCancel
- async/Microsoft::WRL::AsyncBase::OnClose
- async/Microsoft::WRL::AsyncBase::OnStart
- async/Microsoft::WRL::AsyncBase::put_Id
- async/Microsoft::WRL::AsyncBase::PutOnComplete
- async/Microsoft::WRL::AsyncBase::PutOnProgress
- async/Microsoft::WRL::AsyncBase::TryTransitionToCompleted
- async/Microsoft::WRL::AsyncBase::TryTransitionToError
helpviewer_keywords:
- Microsoft::WRL::AsyncBase class
- Microsoft::WRL::AsyncBase::AsyncBase, constructor
- Microsoft::WRL::AsyncBase::Cancel method
- Microsoft::WRL::AsyncBase::CheckValidStateForDelegateCall method
- Microsoft::WRL::AsyncBase::CheckValidStateForResultsCall method
- Microsoft::WRL::AsyncBase::Close method
- Microsoft::WRL::AsyncBase::ContinueAsyncOperation method
- Microsoft::WRL::AsyncBase::CurrentStatus method
- Microsoft::WRL::AsyncBase::ErrorCode method
- Microsoft::WRL::AsyncBase::FireCompletion method
- Microsoft::WRL::AsyncBase::FireProgress method
- Microsoft::WRL::AsyncBase::get_ErrorCode method
- Microsoft::WRL::AsyncBase::get_Id method
- Microsoft::WRL::AsyncBase::get_Status method
- Microsoft::WRL::AsyncBase::GetOnComplete method
- Microsoft::WRL::AsyncBase::GetOnProgress method
- Microsoft::WRL::AsyncBase::OnCancel method
- Microsoft::WRL::AsyncBase::OnClose method
- Microsoft::WRL::AsyncBase::OnStart method
- Microsoft::WRL::AsyncBase::put_Id method
- Microsoft::WRL::AsyncBase::PutOnComplete method
- Microsoft::WRL::AsyncBase::PutOnProgress method
- Microsoft::WRL::AsyncBase::TryTransitionToCompleted method
- Microsoft::WRL::AsyncBase::TryTransitionToError method
ms.assetid: 64259b9b-f427-4ffd-a611-e7a2f82362b2
ms.openlocfilehash: 367d0b0cd3197623b27ee1a50e804cca797aedf3
ms.sourcegitcommit: 360b55e89e5954f494e52b1cf989fbaceda06f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 01/16/2019
ms.locfileid: "54335454"
---
# <a name="asyncbase-class"></a>Classe AsyncBase

Implementa a máquina de estado assíncrona do tempo de execução do Windows.

## <a name="syntax"></a>Sintaxe

```cpp
template <
    typename TComplete,
    typename TProgress = Details::Nil,
    AsyncResultType resultType = SingleResult
>
class AsyncBase : public AsyncBase<TComplete, Details::Nil, resultType>;

template <typename TComplete, AsyncResultType resultType>
class AsyncBase<TComplete, Details::Nil, resultType> :
    public Microsoft::WRL::Implements<IAsyncInfo>;
```

### <a name="parameters"></a>Parâmetros

*TComplete*<br/>
Um manipulador de eventos é chamado quando uma operação assíncrona é concluída.

*TProgress*<br/>
Um manipulador de eventos é chamado quando uma operação assíncrona em execução relata o progresso atual da operação.

*resultType*<br/>
Um dos [AsyncResultType](asyncresulttype-enumeration.md) valores de enumeração. Por padrão, `SingleResult`.

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores Públicos

Nome                               | Descrição
---------------------------------- | -------------------------------------------------
[AsyncBase::AsyncBase](#asyncbase) | Inicializa uma instância da classe `AsyncBase`.

### <a name="public-methods"></a>Métodos públicos

Nome                                         | Descrição
-------------------------------------------- | -------------------------------------------------------------------------------------
[AsyncBase::Cancel](#cancel)                 | Cancela uma operação assíncrona.
[AsyncBase::Close](#close)                   | Fecha a operação assíncrona.
[AsyncBase::FireCompletion](#firecompletion) | Invoca o manipulador de eventos de conclusão ou redefine o delegado de progresso interno.
[AsyncBase::FireProgress](#fireprogress)     | Invoca o manipulador de eventos de andamento atual.
[AsyncBase::get_ErrorCode](#get-errorcode)   | Recupera o código de erro para a operação assíncrona atual.
[AsyncBase::get_Id](#get-id)                 | Recupera o identificador da operação assíncrona.
[AsyncBase::get_Status](#get-status)         | Recupera um valor que indica o status da operação assíncrona.
[AsyncBase::GetOnComplete](#getoncomplete)   | Copia o endereço do manipulador de eventos de conclusão atual para a variável especificada.
[AsyncBase::GetOnProgress](#getonprogress)   | Copia o endereço do manipulador de eventos de andamento atual para a variável especificada.
[AsyncBase::put_Id](#put-id)                 | Define o identificador da operação assíncrona.
[AsyncBase::PutOnComplete](#putoncomplete)   | Define o endereço do manipulador de eventos de conclusão para o valor especificado.
[AsyncBase::PutOnProgress](#putonprogress)   | Define o endereço do manipulador de eventos de andamento para o valor especificado.


### <a name="protected-methods"></a>Métodos Protegidos

Nome                                                                         | Descrição
---------------------------------------------------------------------------- | ----------------------------------------------------------------------------------------------------------
[AsyncBase::CheckValidStateForDelegateCall](#checkvalidstatefordelegatecall) | Testa se as propriedades de delegado podem ser modificadas no estado assíncrono atual.
[AsyncBase::CheckValidStateForResultsCall](#checkvalidstateforresultscall)   | Testa se os resultados de uma operação assíncrona que podem ser coletados no estado assíncrono atual.
[AsyncBase::ContinueAsyncOperation](#continueasyncoperation)                 | Determina se a operação assíncrona devam continuar o processamento ou deve parar.
[AsyncBase::CurrentStatus](#currentstatus)                                   | Recupera o status da operação assíncrona atual.
[AsyncBase::ErrorCode](#errorcode)                                           | Recupera o código de erro para a operação assíncrona atual.
[AsyncBase::OnCancel](#oncancel)                                             | Quando substituído em uma classe derivada, cancela uma operação assíncrona.
[AsyncBase::OnClose](#onclose)                                               | Quando substituído em uma classe derivada, fecha uma operação assíncrona.
[AsyncBase::OnStart](#onstart)                                               | Quando substituído em uma classe derivada, inicia uma operação assíncrona.
[AsyncBase::Start](#start)                                                   | Inicia a operação assíncrona.
[AsyncBase::TryTransitionToCompleted](#trytransitiontocompleted)             | Indica se a operação assíncrona atual foi concluída.
[AsyncBase::TryTransitionToError](#trytransitiontoerror)                     | Indica se o código de erro especificado pode modificar o estado de erro interno.

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`AsyncBase`

`AsyncBase`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** async.h

**Namespace:** Microsoft::WRL

## <a name="asyncbase"></a>AsyncBase::AsyncBase

Inicializa uma instância da classe `AsyncBase`.

```cpp
AsyncBase();
```

## <a name="cancel"></a>AsyncBase::Cancel

Cancela uma operação assíncrona.

```cpp
STDMETHOD(
   Cancel
)(void);
```

### <a name="return-value"></a>Valor de retorno

Por padrão, sempre retorna S_OK.

### <a name="remarks"></a>Comentários

`Cancel()` é uma implementação padrão de `IAsyncInfo::Cancel`, e não faz nenhum trabalho real. Para cancelar, na verdade, uma operação assíncrona, substituir o `OnCancel()` método virtual puro.

## <a name="checkvalidstatefordelegatecall"></a>AsyncBase::CheckValidStateForDelegateCall

Testa se as propriedades de delegado podem ser modificadas no estado assíncrono atual.

```cpp
inline HRESULT CheckValidStateForDelegateCall();
```

### <a name="return-value"></a>Valor de retorno

S_OK se propriedades de delegado podem ser modificadas; Caso contrário, E_ILLEGAL_METHOD_CALL.

## <a name="checkvalidstateforresultscall"></a>AsyncBase::CheckValidStateForResultsCall

Testa se os resultados de uma operação assíncrona que podem ser coletados no estado assíncrono atual.

```cpp
inline HRESULT CheckValidStateForResultsCall();
```

### <a name="return-value"></a>Valor de retorno

S_OK se os resultados podem ser coletados; Caso contrário, E_ILLEGAL_METHOD_CALLE_ILLEGAL_METHOD_CALL.

## <a name="close"></a>AsyncBase::Close

Fecha a operação assíncrona.

```cpp
STDMETHOD(
   Close
)(void) override;
```

### <a name="return-value"></a>Valor de retorno

S_OK se a operação fecha ou já está fechado; Caso contrário, E_ILLEGAL_STATE_CHANGE.

### <a name="remarks"></a>Comentários

`Close()` é uma implementação padrão de `IAsyncInfo::Close`, e não faz nenhum trabalho real. Para realmente fechar uma operação assíncrona, substituir o `OnClose()` método virtual puro.

## <a name="continueasyncoperation"></a>AsyncBase::ContinueAsyncOperation

Determina se a operação assíncrona devam continuar o processamento ou deve parar.

```cpp
inline bool ContinueAsyncOperation();
```

### <a name="return-value"></a>Valor de retorno

**Verdadeiro** se o estado atual da operação assíncrona for *iniciado*, que significa que a operação deve continuar. Caso contrário, **falsos**, que significa que a operação deve parar.

## <a name="currentstatus"></a>AsyncBase::CurrentStatus

Recupera o status da operação assíncrona atual.

```cpp
inline void CurrentStatus(
   Details::AsyncStatusInternal *status
);
```

### <a name="parameters"></a>Parâmetros

*status*<br/>
O local em que essa operação armazena o status atual.

### <a name="remarks"></a>Comentários

Esta operação é thread-safe.

## <a name="errorcode"></a>AsyncBase::ErrorCode

Recupera o código de erro para a operação assíncrona atual.

```cpp
inline void ErrorCode(
   HRESULT *error
);
```

### <a name="parameters"></a>Parâmetros

*error*<br/>
O local em que essa operação armazena o código de erro atual.

### <a name="remarks"></a>Comentários

Esta operação é thread-safe.

## <a name="firecompletion"></a>AsyncBase::FireCompletion

Invoca o manipulador de eventos de conclusão ou redefine o delegado de progresso interno.

```cpp
void FireCompletion(
   void
) override;

virtual void FireCompletion();
```

### <a name="remarks"></a>Comentários

A primeira versão do `FireCompletion()` redefine a variável do delegado de progresso interno. A segunda versão invoca o manipulador de eventos de conclusão, se a operação assíncrona for concluída.

## <a name="fireprogress"></a>AsyncBase::FireProgress

Invoca o manipulador de eventos de andamento atual.

```cpp
void FireProgress(
   const typename ProgressTraits::Arg2Type arg
);
```

### <a name="parameters"></a>Parâmetros

*arg*<br/>
O método de manipulador de eventos para invocar.

### <a name="remarks"></a>Comentários

`ProgressTraits` é derivado de [estrutura ArgTraitsHelper](argtraitshelper-structure.md).

## <a name="get-errorcode"></a>AsyncBase::get_ErrorCode

Recupera o código de erro para a operação assíncrona atual.

```cpp
STDMETHOD(
   get_ErrorCode
)(HRESULT* errorCode) override;
```

### <a name="parameters"></a>Parâmetros

*errorCode*<br/>
O local em que o código de erro atual é armazenado.

### <a name="return-value"></a>Valor de retorno

S_OK se bem-sucedido; Caso contrário, E_ILLEGAL_METHOD_CALL se a operação assíncrona atual está fechada.

## <a name="get-id"></a>AsyncBase::get_Id

Recupera o identificador da operação assíncrona.

```cpp
STDMETHOD(
   get_Id
)(unsigned int *id) override;
```

### <a name="parameters"></a>Parâmetros

*id*<br/>
O local em que o identificador deve ser armazenado.

### <a name="return-value"></a>Valor de retorno

S_OK se bem-sucedido; Caso contrário, E_ILLEGAL_METHOD_CALL.

### <a name="remarks"></a>Comentários

Esse método implementa `IAsyncInfo::get_Id`.

## <a name="get-status"></a>AsyncBase::get_Status

Recupera um valor que indica o status da operação assíncrona.

```cpp
STDMETHOD(
   get_Status
)(AsyncStatus *status) override;
```

### <a name="parameters"></a>Parâmetros

*status*<br/>
O local em que o status deve ser armazenado. Para obter mais informações, consulte `Windows::Foundation::AsyncStatus` enumeração.

### <a name="return-value"></a>Valor de retorno

S_OK se bem-sucedido; Caso contrário, E_ILLEGAL_METHOD_CALL.

### <a name="remarks"></a>Comentários

Esse método implementa `IAsyncInfo::get_Status`.

## <a name="getoncomplete"></a>AsyncBase::GetOnComplete

Copia o endereço do manipulador de eventos de conclusão atual para a variável especificada.

```cpp
STDMETHOD(
   GetOnComplete
)(TComplete** completeHandler);
```

### <a name="parameters"></a>Parâmetros

*completeHandler*<br/>
O local em que o endereço do manipulador de eventos de conclusão atual é armazenado.

### <a name="return-value"></a>Valor de retorno

S_OK se bem-sucedido; Caso contrário, E_ILLEGAL_METHOD_CALL.

## <a name="getonprogress"></a>AsyncBase::GetOnProgress

Copia o endereço do manipulador de eventos de andamento atual para a variável especificada.

```cpp
STDMETHOD(
   GetOnProgress
)(TProgress** progressHandler);
```

### <a name="parameters"></a>Parâmetros

*progressHandler*<br/>
O local em que o endereço do manipulador de eventos de andamento atual é armazenado.

### <a name="return-value"></a>Valor de retorno

S_OK se bem-sucedido; Caso contrário, E_ILLEGAL_METHOD_CALL.

## <a name="oncancel"></a>AsyncBase::OnCancel

Quando substituído em uma classe derivada, cancela uma operação assíncrona.

```cpp
virtual void OnCancel(
   void
) = 0;
```

## <a name="onclose"></a>AsyncBase::OnClose

Quando substituído em uma classe derivada, fecha uma operação assíncrona.

```cpp
virtual void OnClose(
   void
) = 0;
```

## <a name="onstart"></a>AsyncBase::OnStart

Quando substituído em uma classe derivada, inicia uma operação assíncrona.

```cpp
virtual HRESULT OnStart(
   void
) = 0;
```

## <a name="put-id"></a>AsyncBase::put_Id

Define o identificador da operação assíncrona.

```cpp
STDMETHOD(
   put_Id
)(const unsigned int id);
```

### <a name="parameters"></a>Parâmetros

*id*<br/>
Um identificador diferente de zero.

### <a name="return-value"></a>Valor de retorno

S_OK se bem-sucedido; Caso contrário, E_INVALIDARG ou E_ILLEGAL_METHOD_CALL.

## <a name="putoncomplete"></a>AsyncBase::PutOnComplete

Define o endereço do manipulador de eventos de conclusão para o valor especificado.

```cpp
STDMETHOD(
   PutOnComplete
)(TComplete* completeHandler);
```

### <a name="parameters"></a>Parâmetros

*completeHandler*<br/>
O endereço ao qual o manipulador de eventos de conclusão é definido.

### <a name="return-value"></a>Valor de retorno

S_OK se bem-sucedido; Caso contrário, E_ILLEGAL_METHOD_CALL.

## <a name="putonprogress"></a>AsyncBase::PutOnProgress

Define o endereço do manipulador de eventos de andamento para o valor especificado.

```cpp
STDMETHOD(
   PutOnProgress
)(TProgress* progressHandler);
```

### <a name="parameters"></a>Parâmetros

*progressHandler*<br/>
O endereço ao qual o manipulador de eventos de andamento é definido.

### <a name="return-value"></a>Valor de retorno

S_OK se bem-sucedido; Caso contrário, E_ILLEGAL_METHOD_CALL.

## <a name="start"></a>AsyncBase::Start

Inicia a operação assíncrona.

```cpp
STDMETHOD(
   Start
)(void);
```

### <a name="return-value"></a>Valor de retorno

S_OK se a operação é iniciado ou já foi iniciado; Caso contrário, E_ILLEGAL_STATE_CHANGE.

### <a name="remarks"></a>Comentários

`Start()` é um método protegido que não seja externamente visível porque operações assíncronas "quente start" antes de retornar ao chamador.

## <a name="trytransitiontocompleted"></a>AsyncBase::TryTransitionToCompleted

Indica se a operação assíncrona atual foi concluída.

```cpp
bool TryTransitionToCompleted(
   void
);
```

### <a name="return-value"></a>Valor de retorno

**Verdadeiro** se a operação assíncrona foi concluída; caso contrário, **falso**.

## <a name="trytransitiontoerror"></a>AsyncBase::TryTransitionToError

Indica se o código de erro especificado pode modificar o estado de erro interno.

```cpp
bool TryTransitionToError(
   const HRESULT error
);
```

### <a name="parameters"></a>Parâmetros

*error*<br/>
Um erro HRESULT.

### <a name="return-value"></a>Valor de retorno

**Verdadeiro** se o estado de erro interno foi alterado; caso contrário, **falso**.

### <a name="remarks"></a>Comentários

Esta operação modifica o estado de erro somente se o estado de erro já está definido como S_OK. Esta operação não tem efeito se o estado de erro já é um erro, cancelado, concluído ou fechada.
