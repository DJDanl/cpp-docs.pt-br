---
title: Classe symbolname
description: A C++ referência da classe symbolname do SDK do insights do Build.
ms.date: 02/12/2020
helpviewer_keywords:
- C++ Build Insights
- C++ Build Insights SDK
- SymbolName
- throughput analysis
- build time analysis
- vcperf.exe
ms.openlocfilehash: b5e9a9b22db99c099b9f7dc1813fb335358a83e8
ms.sourcegitcommit: 3e8fa01f323bc5043a48a0c18b855d38af3648d4
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/05/2020
ms.locfileid: "78332995"
---
# <a name="symbolname-class"></a>Classe symbolname

::: moniker range="<=vs-2015"

O C++ SDK de informações de compilação é compatível com o Visual Studio 2017 e superior. Para ver a documentação dessas versões, defina o controle do seletor de versão do Visual Studio para este artigo como Visual Studio 2017 ou Visual Studio 2019.

::: moniker-end
::: moniker range=">=vs-2017"

A classe `SymbolName` é usada com as funções [MatchEvent](../functions/match-event.md), [MatchEventInMemberFunction](../functions/match-event-in-member-function.md), [MatchEventStack](../functions/match-event-stack.md)e [MatchEventStackInMemberFunction](../functions/match-event-stack-in-member-function.md) . Use-o para corresponder a um evento [SYMBOL_NAME](../event-table.md#symbol-name) .

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

Junto com os membros herdados de sua classe base [SimpleEvent](simple-event.md) , a classe `SymbolName` contém os seguintes membros:

### <a name="constructors"></a>{1&gt;Construtores&lt;1}

[Symbolname](#symbol-name)

### <a name="functions"></a>{1&gt;Funções&lt;1}

[Nome](#name) da
de [chave](#key)

## <a name="key"></a>Chaves

```cpp
const unsigned long long& Key() const;
```

### <a name="return-value"></a>Valor retornado

Um identificador numérico para o tipo representado por este símbolo. Esse identificador é exclusivo em uma passagem de front-end do compilador.

## <a name="name"></a> Name

```cpp
const char* Name() const;
```

### <a name="return-value"></a>Valor retornado

O nome do tipo representado pelo símbolo, codificado em UTF-8.

## <a name="symbol-name"></a>Symbolname

```cpp
SymbolName(const RawEvent& event);
```

### <a name="parameters"></a>Parâmetros

*event*\
Um evento [SYMBOL_NAME](../event-table.md#symbol-name) .

::: moniker-end
