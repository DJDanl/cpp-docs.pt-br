---
title: Classe DeferrableEventArgs
ms.date: 10/03/2018
ms.topic: reference
f1_keywords:
- event/Microsoft::WRL::DeferrableEventArgs
- event/Microsoft::WRL::DeferrableEventArgs::GetDeferral
- event/Microsoft::WRL::DeferrableEventArgs::InvokeAllFinished
helpviewer_keywords:
- Microsoft::WRL::DeferrableEventArgs class
- Microsoft::WRL::DeferrableEventArgs::GetDeferral method
- Microsoft::WRL::DeferrableEventArgs::InvokeAllFinished method
ms.assetid: ece89267-7b72-40e1-8185-550c865b070a
ms.openlocfilehash: bae2472a75ab77f138fcee0951a6b869cc7c8e82
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81372559"
---
# <a name="deferrableeventargs-class"></a>Classe DeferrableEventArgs

Uma classe de modelo usada para os tipos de argumento de evento para adiamentos.

## <a name="syntax"></a>Sintaxe

```cpp
template <typename TEventArgsInterface, typename TEventArgsClass>
class DeferrableEventArgs : public TEventArgsInterface;
```

### <a name="parameters"></a>Parâmetros

*TEventArgsInterface*<br/>
O tipo de interface que declara os argumentos para um evento diferido.

*TEventArgsClass*<br/>
A classe que implementa *o TEventArgsInterface*.

## <a name="members"></a>Membros

### <a name="public-methods"></a>Métodos públicos

Nome                                                         | Descrição
------------------------------------------------------------ | -----------------------------------------------------------------------------------------------------------------------------
[DiferindoEventArgs::GetDeferral](#getdeferral)             | Obtém uma referência ao objeto [Diferimento](/uwp/api/windows.foundation.deferral) que representa um evento diferido.
[AdiveleventArgs::InvokeAllFinished](#invokeallfinished) | Chamado para indicar que todo o processamento para lidar com um evento diferido está completo.

## <a name="remarks"></a>Comentários

As instâncias desta classe são passadas aos manipuladores de eventos para eventos diferidos. Os parâmetros do modelo representam uma interface que define os detalhes dos argumentos do evento para um tipo específico de evento diferido e uma classe que implementa essa interface.

A classe aparece como o primeiro argumento para um manipulador de eventos para um evento adiado. Você pode chamar o método [GetDeferredal](#getdeferral) para obter o objeto [Diferimento](/uwp/api/windows.foundation.deferral) do qual você pode obter todas as informações sobre o evento diferido. Após concluir o tratamento do evento, você deve ligar para Completar no objeto Diferimento. Em seguida, você deve chamar [InvokeAllFinished](#invokeallfinished) no final do método de manipulador de eventos, que garante que a conclusão de todos os eventos diferidos seja comunicada corretamente.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** event.h

**Espaço de nome:** Microsoft::WRL

## <a name="deferrableeventargsgetdeferral"></a><a name="getdeferral"></a>DiferindoEventArgs::GetDeferral

Obtém uma referência ao objeto [Diferimento](/uwp/api/windows.foundation.deferral) que representa um evento diferido.

```cpp
HRESULT GetDeferral([out, retval] Windows::Foundation::IDeferral** result)
```

### <a name="parameters"></a>Parâmetros

*Resultado*<br/>
Um ponteiro que fará referência ao objeto [Diferimento](/uwp/api/windows.foundation.deferral) quando a chamada for concluída.

### <a name="return-value"></a>Valor retornado

S_OK se for bem sucedido; caso contrário, um HRESULT que indica o erro.

## <a name="deferrableeventargsinvokeallfinished"></a><a name="invokeallfinished"></a>AdiveleventArgs::InvokeAllFinished

Chamado para indicar que todo o processamento para lidar com um evento diferido está completo.

```cpp
void InvokeAllFinished()
```

### <a name="remarks"></a>Comentários

Você deve chamar este método depois que a fonte do evento chamar [InvokeAll](eventsource-class.md#invokeall). Chamar este método evita que mais adiamentos sejam tomados e força o manipulador de conclusão a executar se nenhum adiamento foi tomado.
