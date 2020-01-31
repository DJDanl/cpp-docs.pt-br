---
title: Função de retorno de chamada (WRL)
ms.date: 11/04/2016
ms.topic: reference
f1_keywords:
- event/Microsoft::WRL::Callback
ms.assetid: afb15d25-3230-44f7-b321-e17c54872943
ms.openlocfilehash: 10fb053ed97aaca0f4a31e3843d96aa194d8949d
ms.sourcegitcommit: b8c22e6d555cf833510753cba7a368d57e5886db
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 01/29/2020
ms.locfileid: "76821682"
---
# <a name="callback-function-wrl"></a>Função de retorno de chamada (WRL)

Cria um objeto cuja função de membro é um método de retorno de chamada.

## <a name="syntax"></a>Sintaxe

```cpp
template<
   typename TDelegateInterface,
   typename TCallback
>
ComPtr<TDelegateInterface> Callback(
   TCallbackcallback
);
template<
   typename TDelegateInterface,
   typename TCallbackObject
>
ComPtr<TDelegateInterface> Callback(
   _In_ TCallbackObject *object,
   _In_ HRESULT (TCallbackObject::* method)()
);
template<
   typename TDelegateInterface,
   typename TCallbackObject,
   typename TArg1
>
ComPtr<TDelegateInterface> Callback(
   _In_ TCallbackObject *object,
   _In_ HRESULT (TCallbackObject::* method)(TArg1)
);
template<
   typename TDelegateInterface,
   typename TCallbackObject,
   typename TArg1,
   typename TArg2
>
ComPtr<TDelegateInterface> Callback(
   _In_ TCallbackObject *object,
   _In_ HRESULT (TCallbackObject::* method)(TArg1,
   TArg2)
);
template<
   typename TDelegateInterface,
   typename TCallbackObject,
   typename TArg1,
   typename TArg2,
   typename TArg3
>
ComPtr<TDelegateInterface> Callback(
   _In_ TCallbackObject *object,
   _In_ HRESULT (TCallbackObject::* method)(TArg1,
   TArg2,
   TArg3)
);
template<
   typename TDelegateInterface,
   typename TCallbackObject,
   typename TArg1,
   typename TArg2,
   typename TArg3,
   typename TArg4
>
ComPtr<TDelegateInterface> Callback(
   _In_ TCallbackObject *object,
   _In_ HRESULT (TCallbackObject::* method)(TArg1,
   TArg2,
   TArg3,
   TArg4)
);
template<
   typename TDelegateInterface,
   typename TCallbackObject,
   typename TArg1,
   typename TArg2,
   typename TArg3,
   typename TArg4,
   typename TArg5
>
ComPtr<TDelegateInterface> Callback(
   _In_ TCallbackObject *object,
   _In_ HRESULT (TCallbackObject::* method)(TArg1,
   TArg2,
   TArg3,
   TArg4,
   TArg5)
);
template<
   typename TDelegateInterface,
   typename TCallbackObject,
   typename TArg1,
   typename TArg2,
   typename TArg3,
   typename TArg4,
   typename TArg5,
   typename TArg6
>
ComPtr<TDelegateInterface> Callback(
   _In_ TCallbackObject *object,
   _In_ HRESULT (TCallbackObject::* method)(TArg1,
   TArg2,
   TArg3,
   TArg4,
   TArg5,
   TArg6)
);
template<
   typename TDelegateInterface,
   typename TCallbackObject,
   typename TArg1,
   typename TArg2,
   typename TArg3,
   typename TArg4,
   typename TArg5,
   typename TArg6,
   typename TArg7
>
ComPtr<TDelegateInterface> Callback(
   _In_ TCallbackObject *object,
   _In_ HRESULT (TCallbackObject::* method)(TArg1,
   TArg2,
   TArg3,
   TArg4,
   TArg5,
   TArg6,
   TArg7)
);
template<
   typename TDelegateInterface,
   typename TCallbackObject,
   typename TArg1,
   typename TArg2,
   typename TArg3,
   typename TArg4,
   typename TArg5,
   typename TArg6,
   typename TArg7,
   typename TArg8
>
ComPtr<TDelegateInterface> Callback(
   _In_ TCallbackObject *object,
   _In_ HRESULT (TCallbackObject::* method)(TArg1,
   TArg2,
   TArg3,
   TArg4,
   TArg5,
   TArg6,
   TArg7,
   TArg8)
);
template<
   typename TDelegateInterface,
   typename TCallbackObject,
   typename TArg1,
   typename TArg2,
   typename TArg3,
   typename TArg4,
   typename TArg5,
   typename TArg6,
   typename TArg7,
   typename TArg8,
   typename TArg9
>
ComPtr<TDelegateInterface> Callback(
   _In_ TCallbackObject *object,
   _In_ HRESULT (TCallbackObject::* method)(TArg1,
   TArg2,
   TArg3,
   TArg4,
   TArg5,
   TArg6,
   TArg7,
   TArg8,
   TArg9)
);
```

### <a name="parameters"></a>Parâmetros

*TDelegateInterface*<br/>
Um parâmetro de modelo que especifica a interface do delegado a ser chamada quando um evento ocorre.

*TCallback*<br/>
Um parâmetro de modelo que especifica o tipo de um objeto que representa um objeto e sua função de membro de retorno de chamada.

*TCallbackObject*<br/>
Um parâmetro de modelo que especifica o objeto cuja função de membro é o método a ser chamado quando um evento ocorre.

*TArg1*<br/>
Um parâmetro de modelo que especifica o tipo do primeiro argumento de método de retorno de chamada.

*TArg2*<br/>
Um parâmetro de modelo que especifica o tipo do segundo argumento de método de retorno de chamada.

*TArg3*<br/>
Um parâmetro de modelo que especifica o tipo do terceiro argumento de método de retorno de chamada.

*TArg4*<br/>
Um parâmetro de modelo que especifica o tipo do quarto argumento de método de retorno de chamada.

*TArg5*<br/>
Um parâmetro de modelo que especifica o tipo do quinto argumento de método de retorno de chamada.

*TArg6*<br/>
Um parâmetro de modelo que especifica o tipo do argumento do método sexto de retorno de chamada.

*TArg7*<br/>
Um parâmetro de modelo que especifica o tipo do sétimo argumento do método de retorno de chamada.

*TArg8*<br/>
Um parâmetro de modelo que especifica o tipo do oitavo argumento do método de retorno de chamada.

*TArg9*<br/>
Um parâmetro de modelo que especifica o tipo do argumento do método nono callback.

*callback*<br/>
Um objeto que representa o objeto de retorno de chamada e sua função de membro.

*object*<br/>
O objeto cuja função de membro é chamada quando ocorre um evento.

*forma*<br/>
A função de membro a ser chamada quando um evento ocorrer.

## <a name="return-value"></a>Valor de retorno

Um objeto cuja função de membro é o método de retorno de chamada especificado.

## <a name="remarks"></a>Comentários

A base de um objeto delegado deve ser `IUnknown`, não `IInspectable`.

## <a name="requirements"></a>Requisitos do

**Cabeçalho:** Event. h

**Namespace:** Microsoft::WRL

## <a name="see-also"></a>Veja também

[Namespace Microsoft::WRL](microsoft-wrl-namespace.md)