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
ms.openlocfilehash: 09819c9e8dd924581ce8cd67233d273f7e8d62ca
ms.sourcegitcommit: 8e285a766523e653aeeb34d412dc6f615ef7b17b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/21/2020
ms.locfileid: "80079903"
---
# <a name="asyncbase-class"></a>Classe AsyncBase

Implementa o Windows Runtime máquina de estado assíncrono.

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

### <a name="parameters"></a>parâmetros

*TComplete*<br/>
Um manipulador de eventos que é chamado quando uma operação assíncrona é concluída.

*TProgress*<br/>
Um manipulador de eventos que é chamado quando uma operação assíncrona em execução relata o progresso atual da operação.

*resultType*<br/>
Um dos valores de enumeração [asyncresulttype](asyncresulttype-enumeration.md) . Por padrão, `SingleResult`.

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

Nome                               | DESCRIÇÃO
---------------------------------- | -------------------------------------------------
[AsyncBase::AsyncBase](#asyncbase) | Inicializa uma instância da classe `AsyncBase`.

### <a name="public-methods"></a>Métodos públicos

Nome                                         | DESCRIÇÃO
-------------------------------------------- | -------------------------------------------------------------------------------------
[AsyncBase:: Cancel](#cancel)                 | Cancela uma operação assíncrona.
[AsyncBase:: fechar](#close)                   | Fecha a operação assíncrona.
[AsyncBase::FireCompletion](#firecompletion) | Invoca o manipulador de eventos de conclusão ou redefine o delegado de progresso interno.
[AsyncBase:: FireProgress](#fireprogress)     | Invoca o manipulador de eventos de progresso atual.
[AsyncBase:: get_ErrorCode](#get-errorcode)   | Recupera o código de erro para a operação assíncrona atual.
[AsyncBase:: get_Id](#get-id)                 | Recupera o identificador da operação assíncrona.
[AsyncBase:: get_Status](#get-status)         | Recupera um valor que indica o status da operação assíncrona.
[AsyncBase::GetOnComplete](#getoncomplete)   | Copia o endereço do manipulador de eventos de conclusão atual para a variável especificada.
[AsyncBase::GetOnProgress](#getonprogress)   | Copia o endereço do manipulador de eventos de progresso atual para a variável especificada.
[AsyncBase::p ut_Id](#put-id)                 | Define o identificador da operação assíncrona.
[AsyncBase::P utOnComplete](#putoncomplete)   | Define o endereço do manipulador de eventos de conclusão como o valor especificado.
[AsyncBase::P utOnProgress](#putonprogress)   | Define o endereço do manipulador de eventos de andamento para o valor especificado.

### <a name="protected-methods"></a>Métodos Protegidos

Nome                                                                         | DESCRIÇÃO
---------------------------------------------------------------------------- | ----------------------------------------------------------------------------------------------------------
[AsyncBase::CheckValidStateForDelegateCall](#checkvalidstatefordelegatecall) | Testa se as propriedades delegadas podem ser modificadas no estado assíncrono atual.
[AsyncBase::CheckValidStateForResultsCall](#checkvalidstateforresultscall)   | Testa se os resultados de uma operação assíncrona podem ser coletados no estado assíncrono atual.
[AsyncBase::ContinueAsyncOperation](#continueasyncoperation)                 | Determina se a operação assíncrona deve continuar processando ou deve ser interrompida.
[AsyncBase::CurrentStatus](#currentstatus)                                   | Recupera o status da operação assíncrona atual.
[AsyncBase:: ErrorCode](#errorcode)                                           | Recupera o código de erro para a operação assíncrona atual.
[AsyncBase:: OnCancel](#oncancel)                                             | Quando substituído em uma classe derivada, cancela uma operação assíncrona.
[AsyncBase:: fechamento](#onclose)                                               | Quando substituído em uma classe derivada, fecha uma operação assíncrona.
[AsyncBase:: OnStart](#onstart)                                               | Quando substituído em uma classe derivada, inicia uma operação assíncrona.
[AsyncBase:: iniciar](#start)                                                   | Inicia a operação assíncrona.
[AsyncBase::TryTransitionToCompleted](#trytransitiontocompleted)             | Indica se a operação assíncrona atual foi concluída.
[AsyncBase::TryTransitionToError](#trytransitiontoerror)                     | Indica se o código de erro especificado pode modificar o estado de erro interno.

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`AsyncBase`

`AsyncBase`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** Async. h

**Namespace:** Microsoft:: WRL

## <a name="asyncbaseasyncbase"></a><a name="asyncbase"></a>AsyncBase::AsyncBase

Inicializa uma instância da classe `AsyncBase`.

```cpp
AsyncBase();
```

## <a name="asyncbasecancel"></a><a name="cancel"></a>AsyncBase:: Cancel

Cancela uma operação assíncrona.

```cpp
STDMETHOD(
   Cancel
)(void);
```

### <a name="return-value"></a>Valor retornado

Por padrão, sempre retorna S_OK.

### <a name="remarks"></a>Comentários

`Cancel()` é uma implementação padrão de `IAsyncInfo::Cancel`e não faz nenhum trabalho real. Para realmente cancelar uma operação assíncrona, substitua o `OnCancel()` método virtual puro.

## <a name="asyncbasecheckvalidstatefordelegatecall"></a><a name="checkvalidstatefordelegatecall"></a>AsyncBase::CheckValidStateForDelegateCall

Testa se as propriedades delegadas podem ser modificadas no estado assíncrono atual.

```cpp
inline HRESULT CheckValidStateForDelegateCall();
```

### <a name="return-value"></a>Valor retornado

S_OK se as propriedades delegadas puderem ser modificadas; caso contrário, E_ILLEGAL_METHOD_CALL.

## <a name="asyncbasecheckvalidstateforresultscall"></a><a name="checkvalidstateforresultscall"></a>AsyncBase::CheckValidStateForResultsCall

Testa se os resultados de uma operação assíncrona podem ser coletados no estado assíncrono atual.

```cpp
inline HRESULT CheckValidStateForResultsCall();
```

### <a name="return-value"></a>Valor retornado

S_OK se os resultados podem ser coletados; caso contrário, E_ILLEGAL_METHOD_CALLE_ILLEGAL_METHOD_CALL.

## <a name="asyncbaseclose"></a><a name="close"></a>AsyncBase:: fechar

Fecha a operação assíncrona.

```cpp
STDMETHOD(
   Close
)(void) override;
```

### <a name="return-value"></a>Valor retornado

S_OK se a operação for fechada ou já estiver fechada; caso contrário, E_ILLEGAL_STATE_CHANGE.

### <a name="remarks"></a>Comentários

`Close()` é uma implementação padrão de `IAsyncInfo::Close`e não faz nenhum trabalho real. Para realmente fechar uma operação assíncrona, substitua o `OnClose()` método virtual puro.

## <a name="asyncbasecontinueasyncoperation"></a><a name="continueasyncoperation"></a>AsyncBase::ContinueAsyncOperation

Determina se a operação assíncrona deve continuar processando ou deve ser interrompida.

```cpp
inline bool ContinueAsyncOperation();
```

### <a name="return-value"></a>Valor retornado

**true** se o estado atual da operação assíncrona for *iniciado*, o que significa que a operação deve continuar. Caso contrário, **false**, o que significa que a operação deve ser interrompida.

## <a name="asyncbasecurrentstatus"></a><a name="currentstatus"></a>AsyncBase::CurrentStatus

Recupera o status da operação assíncrona atual.

```cpp
inline void CurrentStatus(
   Details::AsyncStatusInternal *status
);
```

### <a name="parameters"></a>parâmetros

*status*<br/>
O local onde essa operação armazena o status atual.

### <a name="remarks"></a>Comentários

Esta operação é thread-safe.

## <a name="asyncbaseerrorcode"></a><a name="errorcode"></a>AsyncBase:: ErrorCode

Recupera o código de erro para a operação assíncrona atual.

```cpp
inline void ErrorCode(
   HRESULT *error
);
```

### <a name="parameters"></a>parâmetros

*error*<br/>
O local onde essa operação armazena o código de erro atual.

### <a name="remarks"></a>Comentários

Esta operação é thread-safe.

## <a name="asyncbasefirecompletion"></a><a name="firecompletion"></a>AsyncBase::FireCompletion

Invoca o manipulador de eventos de conclusão ou redefine o delegado de progresso interno.

```cpp
void FireCompletion(
   void
) override;

virtual void FireCompletion();
```

### <a name="remarks"></a>Comentários

A primeira versão do `FireCompletion()` redefine a variável de delegado de progresso interno. A segunda versão invocará o manipulador de eventos de conclusão se a operação assíncrona for concluída.

## <a name="asyncbasefireprogress"></a><a name="fireprogress"></a>AsyncBase:: FireProgress

Invoca o manipulador de eventos de progresso atual.

```cpp
void FireProgress(
   const typename ProgressTraits::Arg2Type arg
);
```

### <a name="parameters"></a>parâmetros

*arg*<br/>
O método do manipulador de eventos a ser invocado.

### <a name="remarks"></a>Comentários

`ProgressTraits` é derivado da [estrutura ArgTraitsHelper](argtraitshelper-structure.md).

## <a name="asyncbaseget_errorcode"></a><a name="get-errorcode"></a>AsyncBase:: get_ErrorCode

Recupera o código de erro para a operação assíncrona atual.

```cpp
STDMETHOD(
   get_ErrorCode
)(HRESULT* errorCode) override;
```

### <a name="parameters"></a>parâmetros

*errorCode*<br/>
O local onde o código de erro atual é armazenado.

### <a name="return-value"></a>Valor retornado

S_OK se for bem-sucedido; caso contrário, E_ILLEGAL_METHOD_CALL se a operação assíncrona atual estiver fechada.

## <a name="asyncbaseget_id"></a><a name="get-id"></a>AsyncBase:: get_Id

Recupera o identificador da operação assíncrona.

```cpp
STDMETHOD(
   get_Id
)(unsigned int *id) override;
```

### <a name="parameters"></a>parâmetros

*id*<br/>
O local onde o identificador deve ser armazenado.

### <a name="return-value"></a>Valor retornado

S_OK se for bem-sucedido; caso contrário, E_ILLEGAL_METHOD_CALL.

### <a name="remarks"></a>Comentários

Esse método implementa `IAsyncInfo::get_Id`.

## <a name="asyncbaseget_status"></a><a name="get-status"></a>AsyncBase:: get_Status

Recupera um valor que indica o status da operação assíncrona.

```cpp
STDMETHOD(
   get_Status
)(AsyncStatus *status) override;
```

### <a name="parameters"></a>parâmetros

*status*<br/>
O local onde o status deve ser armazenado. Para obter mais informações, consulte `Windows::Foundation::AsyncStatus` Enumeration.

### <a name="return-value"></a>Valor retornado

S_OK se for bem-sucedido; caso contrário, E_ILLEGAL_METHOD_CALL.

### <a name="remarks"></a>Comentários

Esse método implementa `IAsyncInfo::get_Status`.

## <a name="asyncbasegetoncomplete"></a><a name="getoncomplete"></a>AsyncBase::GetOnComplete

Copia o endereço do manipulador de eventos de conclusão atual para a variável especificada.

```cpp
STDMETHOD(
   GetOnComplete
)(TComplete** completeHandler);
```

### <a name="parameters"></a>parâmetros

*completeHandler*<br/>
O local onde o endereço do manipulador de eventos de conclusão atual é armazenado.

### <a name="return-value"></a>Valor retornado

S_OK se for bem-sucedido; caso contrário, E_ILLEGAL_METHOD_CALL.

## <a name="asyncbasegetonprogress"></a><a name="getonprogress"></a>AsyncBase::GetOnProgress

Copia o endereço do manipulador de eventos de progresso atual para a variável especificada.

```cpp
STDMETHOD(
   GetOnProgress
)(TProgress** progressHandler);
```

### <a name="parameters"></a>parâmetros

*progressHandler*<br/>
O local onde o endereço do manipulador de eventos de progresso atual é armazenado.

### <a name="return-value"></a>Valor retornado

S_OK se for bem-sucedido; caso contrário, E_ILLEGAL_METHOD_CALL.

## <a name="asyncbaseoncancel"></a><a name="oncancel"></a>AsyncBase:: OnCancel

Quando substituído em uma classe derivada, cancela uma operação assíncrona.

```cpp
virtual void OnCancel(
   void
) = 0;
```

## <a name="asyncbaseonclose"></a><a name="onclose"></a>AsyncBase:: fechamento

Quando substituído em uma classe derivada, fecha uma operação assíncrona.

```cpp
virtual void OnClose(
   void
) = 0;
```

## <a name="asyncbaseonstart"></a><a name="onstart"></a>AsyncBase:: OnStart

Quando substituído em uma classe derivada, inicia uma operação assíncrona.

```cpp
virtual HRESULT OnStart(
   void
) = 0;
```

## <a name="asyncbaseput_id"></a><a name="put-id"></a>AsyncBase::p ut_Id

Define o identificador da operação assíncrona.

```cpp
STDMETHOD(
   put_Id
)(const unsigned int id);
```

### <a name="parameters"></a>parâmetros

*id*<br/>
Um identificador diferente de zero.

### <a name="return-value"></a>Valor retornado

S_OK se for bem-sucedido; caso contrário, E_INVALIDARG ou E_ILLEGAL_METHOD_CALL.

## <a name="asyncbaseputoncomplete"></a><a name="putoncomplete"></a>AsyncBase::P utOnComplete

Define o endereço do manipulador de eventos de conclusão como o valor especificado.

```cpp
STDMETHOD(
   PutOnComplete
)(TComplete* completeHandler);
```

### <a name="parameters"></a>parâmetros

*completeHandler*<br/>
O endereço para o qual o manipulador de eventos de conclusão está definido.

### <a name="return-value"></a>Valor retornado

S_OK se for bem-sucedido; caso contrário, E_ILLEGAL_METHOD_CALL.

## <a name="asyncbaseputonprogress"></a><a name="putonprogress"></a>AsyncBase::P utOnProgress

Define o endereço do manipulador de eventos de andamento para o valor especificado.

```cpp
STDMETHOD(
   PutOnProgress
)(TProgress* progressHandler);
```

### <a name="parameters"></a>parâmetros

*progressHandler*<br/>
O endereço para o qual o manipulador de eventos de andamento está definido.

### <a name="return-value"></a>Valor retornado

S_OK se for bem-sucedido; caso contrário, E_ILLEGAL_METHOD_CALL.

## <a name="asyncbasestart"></a><a name="start"></a>AsyncBase:: iniciar

Inicia a operação assíncrona.

```cpp
STDMETHOD(
   Start
)(void);
```

### <a name="return-value"></a>Valor retornado

S_OK se a operação for iniciada ou já estiver iniciada; caso contrário, E_ILLEGAL_STATE_CHANGE.

### <a name="remarks"></a>Comentários

`Start()` é um método protegido que não é visível externamente porque as operações assíncronas "Hot Start" antes de retornar ao chamador.

## <a name="asyncbasetrytransitiontocompleted"></a><a name="trytransitiontocompleted"></a>AsyncBase::TryTransitionToCompleted

Indica se a operação assíncrona atual foi concluída.

```cpp
bool TryTransitionToCompleted(
   void
);
```

### <a name="return-value"></a>Valor retornado

**true** se a operação assíncrona tiver sido concluída; caso contrário, **false**.

## <a name="asyncbasetrytransitiontoerror"></a><a name="trytransitiontoerror"></a>AsyncBase::TryTransitionToError

Indica se o código de erro especificado pode modificar o estado de erro interno.

```cpp
bool TryTransitionToError(
   const HRESULT error
);
```

### <a name="parameters"></a>parâmetros

*error*<br/>
Um erro HRESULT.

### <a name="return-value"></a>Valor retornado

**true** se o estado de erro interno tiver sido alterado; caso contrário, **false**.

### <a name="remarks"></a>Comentários

Esta operação modificará o estado de erro somente se o estado de erro já estiver definido como S_OK. Esta operação não terá efeito se o estado do erro já for erro, cancelado, concluído ou fechado.
