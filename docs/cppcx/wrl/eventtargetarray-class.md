---
title: Classe EventTargetArray
ms.date: 10/03/2018
ms.topic: reference
f1_keywords:
- event/Microsoft::WRL::Details::EventTargetArray
- event/Microsoft::WRL::Details::EventTargetArray::AddTail
- event/Microsoft::WRL::Details::EventTargetArray::Begin
- event/Microsoft::WRL::Details::EventTargetArray::End
- event/Microsoft::WRL::Details::EventTargetArray::EventTargetArray
- event/Microsoft::WRL::Details::EventTargetArray::Length
- event/Microsoft::WRL::Details::EventTargetArray::~EventTargetArray
helpviewer_keywords:
- Microsoft::WRL::Details::EventTargetArray class
- Microsoft::WRL::Details::EventTargetArray::AddTail method
- Microsoft::WRL::Details::EventTargetArray::Begin method
- Microsoft::WRL::Details::EventTargetArray::End method
- Microsoft::WRL::Details::EventTargetArray::EventTargetArray, constructor
- Microsoft::WRL::Details::EventTargetArray::Length method
- Microsoft::WRL::Details::EventTargetArray::~EventTargetArray, destructor
ms.assetid: e3cadb7c-2160-4cbb-a2f8-c28733d1e96d
ms.openlocfilehash: 9ea8800aa22a6b5cae0b3342cf337786fb53fc76
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81371489"
---
# <a name="eventtargetarray-class"></a>Classe EventTargetArray

Suporta a infra-estrutura WRL e não se destina a ser usado diretamente do seu código.

## <a name="syntax"></a>Sintaxe

```cpp
class EventTargetArray :
    public Microsoft::WRL::RuntimeClass<
        Microsoft::WRL::RuntimeClassFlags<ClassicCom>,
        IUnknown
    >;
```

## <a name="remarks"></a>Comentários

Representa uma matriz de manipuladores de eventos.

Os manipuladores de eventos associados a um objeto `EventTargetArray` [EventSource](eventsource-class.md) são armazenados em um membro de dados protegido.

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

Nome                                                           | Descrição
-------------------------------------------------------------- | -----------------------------------------------------------
[EventTargetArray::EventTargetArray](#eventtargetarray)        | Inicia uma nova instância da classe `EventTargetArray`.
[EventTargetArray::~EventTargetArray](#tilde-eventtargetarray) | Desinicializa a `EventTargetArray` classe atual.

### <a name="public-methods"></a>Métodos públicos

Nome                                  | Descrição
------------------------------------- | ---------------------------------------------------------------------------------------
[EventTargetArray::AddTail](#addtail) | Anexa o manipulador de eventos especificado ao final da matriz interna de manipuladores de eventos.
[EventTargetArray::Begin](#begin)     | Obtém o endereço do primeiro elemento na matriz interna de manipuladores de eventos.
[EventTargetArray::End](#end)         | Obtém o endereço do último elemento na matriz interna de manipuladores de eventos.
[EventTargetArray::Comprimento](#length)   | Obtém o número atual de elementos na matriz interna de manipuladores de eventos.

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`EventTargetArray`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** event.h

**Espaço de nome:** Microsoft::WRL::Details

## <a name="eventtargetarrayeventtargetarray"></a><a name="tilde-eventtargetarray"></a>EventTargetArray::~EventTargetArray

Suporta a infra-estrutura WRL e não se destina a ser usado diretamente do seu código.

```cpp
~EventTargetArray();
```

### <a name="remarks"></a>Comentários

Desinicializa a `EventTargetArray` classe atual.

## <a name="eventtargetarrayaddtail"></a><a name="addtail"></a>EventTargetArray::AddTail

Suporta a infra-estrutura WRL e não se destina a ser usado diretamente do seu código.

```cpp
void AddTail(
   _In_ IUnknown* element
);
```

### <a name="parameters"></a>Parâmetros

*Elemento*<br/>
Ponteiro para o manipulador de eventos para anexar.

### <a name="remarks"></a>Comentários

Anexa o manipulador de eventos especificado ao final da matriz interna de manipuladores de eventos.

`AddTail()`destina-se a ser usado `EventSource` internamente apenas pela classe.

## <a name="eventtargetarraybegin"></a><a name="begin"></a>EventTargetArray::Begin

Suporta a infra-estrutura WRL e não se destina a ser usado diretamente do seu código.

```cpp
ComPtr<IUnknown>* Begin();
```

### <a name="return-value"></a>Valor retornado

O endereço do primeiro elemento na matriz interna de manipuladores de eventos.

### <a name="remarks"></a>Comentários

Obtém o endereço do primeiro elemento na matriz interna de manipuladores de eventos.

## <a name="eventtargetarrayend"></a><a name="end"></a>EventTargetArray::End

Suporta a infra-estrutura WRL e não se destina a ser usado diretamente do seu código.

```cpp
ComPtr<IUnknown>* End();
```

### <a name="return-value"></a>Valor retornado

O endereço do último elemento na matriz interna de manipuladores de eventos.

### <a name="remarks"></a>Comentários

Obtém o endereço do último elemento na matriz interna de manipuladores de eventos.

## <a name="eventtargetarrayeventtargetarray"></a><a name="eventtargetarray"></a>EventTargetArray::EventTargetArray

Suporta a infra-estrutura WRL e não se destina a ser usado diretamente do seu código.

```cpp
EventTargetArray(
   _Out_ HRESULT* hr,
   size_t items
);
```

### <a name="parameters"></a>Parâmetros

*Hr*<br/>
Após essas operações de construção, o parâmetro *de rh* indica se a alocação da matriz foi bem sucedida ou não. A lista a seguir mostra os possíveis valores para *o RH*.

- S_OK<br/>
  A operação foi realizada com êxito.

- E_OUTOFMEMORY<br/>
  A memória não poderia ser alocada para a matriz.

- S_FALSE<br/>
  Os *itens* de parâmetro são menores ou iguais a zero.

*Itens*<br/>
O número de elementos de matriz para alocar.

### <a name="remarks"></a>Comentários

Inicia uma nova instância da classe `EventTargetArray`.

`EventTargetArray`é usado para manter uma matriz `EventSource` de manipuladores de eventos em um objeto.

## <a name="eventtargetarraylength"></a><a name="length"></a>EventTargetArray::Comprimento

Suporta a infra-estrutura WRL e não se destina a ser usado diretamente do seu código.

```cpp
size_t Length();
```

### <a name="return-value"></a>Valor retornado

O número atual de elementos na matriz interna de manipuladores de eventos.

### <a name="remarks"></a>Comentários

Obtém o número atual de elementos na matriz interna de manipuladores de eventos.
