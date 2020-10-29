---
title: Classe de evento
description: A referência da classe de evento do SDK do insights de compilação do C++.
ms.date: 02/12/2020
helpviewer_keywords:
- C++ Build Insights
- C++ Build Insights SDK
- EventGroup
- throughput analysis
- build time analysis
- vcperf.exe
ms.openlocfilehash: 57cbc7a053132909149aee182b9560e2ee33c161
ms.sourcegitcommit: 9c2b3df9b837879cd17932ae9f61cdd142078260
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/29/2020
ms.locfileid: "92923308"
---
# <a name="eventgroup-class"></a>Classe de evento

::: moniker range="<=msvc-140"

O SDK do insights de compilação do C++ é compatível com o Visual Studio 2017 e superior. Para ver a documentação dessas versões, defina o controle do seletor de **versão** do Visual Studio para este artigo como visual Studio 2017 ou visual Studio 2019. Ele é encontrado na parte superior do Sumário nesta página.

::: moniker-end
::: moniker range=">=msvc-150"

O `EventGroup` modelo de classe é a classe base para todas as classes de captura de grupo.

## <a name="syntax"></a>Sintaxe

```cpp
template <typename TActivity>
class EventGroup;
{
public:
    size_t Size() const;

    const TActivity& operator[](size_t index) const;
    const TActivity& Front() const;
    const TActivity& Back() const;

    std::deque<TActivity>::const_iterator begin() const;
    std::deque<TActivity>::const_iterator end() const;
};
```

### <a name="parameters"></a>Parâmetros

*TActivity* O tipo de atividade contido no grupo.

## <a name="members"></a>Membros

### <a name="functions"></a>Funções

[Voltar](#back) 
 [Iniciar](#begin) 
 [fim](#end) 
 [Frente](#front) 
 [operador []](#subscript-operator) 
 [Tamanho](#size)

## <a name="back"></a><a name="back"></a> Voltar

```cpp
const TActivity& Back() const;
```

### <a name="return-value"></a>Valor Retornado

Uma referência ao evento da última atividade no grupo.

## <a name="begin"></a><a name="begin"></a> Comece

```cpp
std::deque<TActivity>::const_iterator begin() const;
```

### <a name="return-value"></a>Valor Retornado

Um iterador que aponta para o início do grupo de eventos de atividade.

## <a name="end"></a><a name="end"></a> completo

```cpp
std::deque<TActivity>::const_iterator end() const;
```

### <a name="return-value"></a>Valor Retornado

Um iterador que aponta uma posição após o final do grupo de eventos de atividade.

## <a name="front"></a><a name="front"></a> Dianteiro

```cpp
const TActivity& Front() const;
```

### <a name="return-value"></a>Valor Retornado

Uma referência ao primeiro evento de atividade no grupo.

## <a name="operator"></a><a name="subscript-operator"></a> operador []

```cpp
const TActivity& operator[](size_t index) const;
```

### <a name="parameters"></a>Parâmetros

*index*\
O índice do elemento a ser acessado no grupo de eventos de atividade.

### <a name="return-value"></a>Valor Retornado

O evento da pilha de eventos armazenada na posição indicada pelo *índice* .

## <a name="size"></a><a name="size"></a> Tamanho

```cpp
size_t Size() const;
```

### <a name="return-value"></a>Valor Retornado

O tamanho do grupo de eventos.

::: moniker-end
