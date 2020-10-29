---
title: Classe symbolname
description: A referência da classe Symbolname do SDK do insights de compilação do C++.
ms.date: 02/12/2020
helpviewer_keywords:
- C++ Build Insights
- C++ Build Insights SDK
- SymbolName
- throughput analysis
- build time analysis
- vcperf.exe
ms.openlocfilehash: a749d95b3812df8b1cc0cd7d2da037e98467cefc
ms.sourcegitcommit: 9c2b3df9b837879cd17932ae9f61cdd142078260
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/29/2020
ms.locfileid: "92920470"
---
# <a name="symbolname-class"></a>Classe symbolname

::: moniker range="<=msvc-140"

O SDK do insights de compilação do C++ é compatível com o Visual Studio 2017 e superior. Para ver a documentação dessas versões, defina o controle do seletor de **versão** do Visual Studio para este artigo como visual Studio 2017 ou visual Studio 2019. Ele é encontrado na parte superior do Sumário nesta página.

::: moniker-end
::: moniker range=">=msvc-150"

A `SymbolName` classe é usada com as funções [MatchEvent](../functions/match-event.md), [MatchEventInMemberFunction](../functions/match-event-in-member-function.md), [MatchEventStack](../functions/match-event-stack.md)e [MatchEventStackInMemberFunction](../functions/match-event-stack-in-member-function.md) . Use-o para corresponder a um evento [SYMBOL_NAME](../event-table.md#symbol-name) .

## <a name="syntax"></a>Sintaxe

```cpp
class SymbolName : public SimpleEvent
{
public:
    SymbolName(const RawEvent& event);

    const unsigned long long&  Key() const;
    const char*                Name() const;
};
```

## <a name="members"></a>Membros

Junto com os membros herdados de sua classe base [SimpleEvent](simple-event.md) , a `SymbolName` classe contém os seguintes membros:

### <a name="constructors"></a>Construtores

[SymbolName](#symbol-name)

### <a name="functions"></a>Funções

[Chave](#key) 
 [Nome](#name) do

## <a name="key"></a><a name="key"></a> Chaves

```cpp
const unsigned long long& Key() const;
```

### <a name="return-value"></a>Valor Retornado

Um identificador numérico para o tipo representado por este símbolo. Esse identificador é exclusivo em uma passagem de front-end do compilador.

## <a name="name"></a><a name="name"></a> Nomes

```cpp
const char* Name() const;
```

### <a name="return-value"></a>Valor Retornado

O nome do tipo representado pelo símbolo, codificado em UTF-8.

## <a name="symbolname"></a><a name="symbol-name"></a> Symbolname

```cpp
SymbolName(const RawEvent& event);
```

### <a name="parameters"></a>Parâmetros

*circunstância*\
Um evento [SYMBOL_NAME](../event-table.md#symbol-name) .

::: moniker-end
