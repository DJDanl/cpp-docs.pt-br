---
title: Classe SymbolName
description: A referência da classe C++ Build Insights SDK SymbolName.
ms.date: 02/12/2020
helpviewer_keywords:
- C++ Build Insights
- C++ Build Insights SDK
- SymbolName
- throughput analysis
- build time analysis
- vcperf.exe
ms.openlocfilehash: 1306fb43d6c2140a75b36c5f142532916cf26ae4
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81324350"
---
# <a name="symbolname-class"></a>Classe SymbolName

::: moniker range="<=vs-2015"

O C++ Build Insights SDK é compatível com o Visual Studio 2017 e acima. Para ver a documentação dessas versões, defina o controle do seletor Visual Studio **Version** para este artigo para visual studio 2017 ou Visual Studio 2019. É encontrado no topo da tabela de conteúdo nesta página.

::: moniker-end
::: moniker range=">=vs-2017"

A `SymbolName` classe é usada com as funções [MatchEvent,](../functions/match-event.md) [MatchEventInMemberFunction,](../functions/match-event-in-member-function.md) [MatchEventStack](../functions/match-event-stack.md)e [MatchEventStackInMemberFunction.](../functions/match-event-stack-in-member-function.md) Use-o para combinar com um evento [SYMBOL_NAME.](../event-table.md#symbol-name)

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

Juntamente com os membros herdados de `SymbolName` sua classe base [SimpleEvent,](simple-event.md) a classe contém os seguintes membros:

### <a name="constructors"></a>Construtores

[Nome do Símbolo](#symbol-name)

### <a name="functions"></a>Funções

[Key](#key)
[Nome-chave](#name)

## <a name="key"></a><a name="key"></a>Chave

```cpp
const unsigned long long& Key() const;
```

### <a name="return-value"></a>Valor retornado

Um identificador numérico para o tipo representado por este símbolo. Este identificador é único dentro de um passe front-end do compilador.

## <a name="name"></a><a name="name"></a>Nome

```cpp
const char* Name() const;
```

### <a name="return-value"></a>Valor retornado

O nome do tipo representado pelo símbolo, codificado em UTF-8.

## <a name="symbolname"></a><a name="symbol-name"></a>Nome do Símbolo

```cpp
SymbolName(const RawEvent& event);
```

### <a name="parameters"></a>Parâmetros

*Evento*\
Um evento [SYMBOL_NAME.](../event-table.md#symbol-name)

::: moniker-end
