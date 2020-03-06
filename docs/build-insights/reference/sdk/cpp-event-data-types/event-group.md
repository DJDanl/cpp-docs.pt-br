---
title: Classe de evento
description: A C++ referência da classe de evento do SDK do insights do Build.
ms.date: 02/12/2020
helpviewer_keywords:
- C++ Build Insights
- C++ Build Insights SDK
- EventGroup
- throughput analysis
- build time analysis
- vcperf.exe
ms.openlocfilehash: ac8ac70f3fc160714b86dd0c483808a4d06e7699
ms.sourcegitcommit: 3e8fa01f323bc5043a48a0c18b855d38af3648d4
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/05/2020
ms.locfileid: "78333429"
---
# <a name="eventgroup-class"></a>Classe de evento

::: moniker range="<=vs-2015"

O C++ SDK de informações de compilação é compatível com o Visual Studio 2017 e superior. Para ver a documentação dessas versões, defina o controle do seletor de versão do Visual Studio para este artigo como Visual Studio 2017 ou Visual Studio 2019.

::: moniker-end
::: moniker range=">=vs-2017"

O modelo de classe de `EventGroup` é a classe base para todas as classes de captura de grupo.

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

### <a name="functions"></a>{1&gt;Funções&lt;1}

[Voltar](#back)
[começar](#begin)
[end](#end)
operador de
[frontal](#front) [[]](#subscript-operator) [tamanho](#size) do


## <a name="back"></a>Voltar

```cpp
const TActivity& Back() const;
```

### <a name="return-value"></a>Valor retornado

Uma referência ao evento da última atividade no grupo.

## <a name="begin"></a>Comece

```cpp
std::deque<TActivity>::const_iterator begin() const;
```

### <a name="return-value"></a>Valor retornado

Um iterador que aponta para o início do grupo de eventos de atividade.

## <a name="end"></a>completo

```cpp
std::deque<TActivity>::const_iterator end() const;
```

### <a name="return-value"></a>Valor retornado

Um iterador que aponta uma posição após o final do grupo de eventos de atividade.

## <a name="front"></a>Dianteiro

```cpp
const TActivity& Front() const;
```

### <a name="return-value"></a>Valor retornado

Uma referência ao primeiro evento de atividade no grupo.

## <a name="subscript-operator"></a>operador []

```cpp
const TActivity& operator[](size_t index) const;
```

### <a name="parameters"></a>Parâmetros

\ de *índice*
O índice do elemento a ser acessado no grupo de eventos de atividade.

### <a name="return-value"></a>Valor retornado

O evento da pilha de eventos armazenada na posição indicada pelo *índice*.

## <a name="size"></a>Tamanho

```cpp
size_t Size() const;
```

### <a name="return-value"></a>Valor retornado

O tamanho do grupo de eventos.

::: moniker-end
