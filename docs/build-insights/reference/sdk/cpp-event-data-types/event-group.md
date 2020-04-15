---
title: Classe EventGroup
description: A referência da classe C++ Build Insights SDK EventGroup.
ms.date: 02/12/2020
helpviewer_keywords:
- C++ Build Insights
- C++ Build Insights SDK
- EventGroup
- throughput analysis
- build time analysis
- vcperf.exe
ms.openlocfilehash: 596c18ca0e9b4d7b26c4ed5209b16871952c4af2
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81324994"
---
# <a name="eventgroup-class"></a>Classe EventGroup

::: moniker range="<=vs-2015"

O C++ Build Insights SDK é compatível com o Visual Studio 2017 e acima. Para ver a documentação dessas versões, defina o controle do seletor Visual Studio **Version** para este artigo para visual studio 2017 ou Visual Studio 2019. É encontrado no topo da tabela de conteúdo nesta página.

::: moniker-end
::: moniker range=">=vs-2017"

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

*TAtividade* O tipo de atividade contido no grupo.

## <a name="members"></a>Membros

### <a name="functions"></a>Funções

[Back](#back)
[start](#begin)
[end](#end)
Operador[frontal[]](#subscript-operator)
[Front](#front)
[Tamanho](#size)

## <a name="back"></a><a name="back"></a>Voltar

```cpp
const TActivity& Back() const;
```

### <a name="return-value"></a>Valor retornado

Uma referência ao último evento de atividade do grupo.

## <a name="begin"></a><a name="begin"></a>Começar

```cpp
std::deque<TActivity>::const_iterator begin() const;
```

### <a name="return-value"></a>Valor retornado

Um iterizador apontando para o início do grupo de eventos de atividades.

## <a name="end"></a><a name="end"></a>Final

```cpp
std::deque<TActivity>::const_iterator end() const;
```

### <a name="return-value"></a>Valor retornado

Um iterizador apontando uma posição após o fim do grupo de eventos de atividade.

## <a name="front"></a><a name="front"></a>Frente

```cpp
const TActivity& Front() const;
```

### <a name="return-value"></a>Valor retornado

Uma referência ao primeiro evento de atividade do grupo.

## <a name="operator"></a><a name="subscript-operator"></a>operador[]

```cpp
const TActivity& operator[](size_t index) const;
```

### <a name="parameters"></a>Parâmetros

*Índice*\
O índice do elemento a ser acessado no grupo de eventos de atividades.

### <a name="return-value"></a>Valor retornado

O evento da pilha de eventos armazenado na posição indicada pelo *índice*.

## <a name="size"></a><a name="size"></a> Tamanho

```cpp
size_t Size() const;
```

### <a name="return-value"></a>Valor retornado

O tamanho do grupo de eventos.

::: moniker-end
