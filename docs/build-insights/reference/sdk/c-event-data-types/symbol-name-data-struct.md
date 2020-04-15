---
title: SYMBOL_NAME_DATA estrutura
description: O C++ Build Insights SDK SYMBOL_NAME_DATA referência de estrutura.
ms.date: 02/12/2020
helpviewer_keywords:
- C++ Build Insights
- C++ Build Insights SDK
- SYMBOL_NAME_DATA
- throughput analysis
- build time analysis
- vcperf.exe
ms.openlocfilehash: 1217572f20a772fde629533d6ab170c14dc5b5e0
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81325344"
---
# <a name="symbol_name_data-structure"></a>SYMBOL_NAME_DATA estrutura

::: moniker range="<=vs-2015"

O C++ Build Insights SDK é compatível com o Visual Studio 2017 e acima. Para ver a documentação dessas versões, defina o controle do seletor Visual Studio **Version** para este artigo para visual studio 2017 ou Visual Studio 2019. É encontrado no topo da tabela de conteúdo nesta página.

::: moniker-end
::: moniker range=">=vs-2017"

A `SYMBOL_NAME_DATA` estrutura descreve um símbolo frontal do compilador.

## <a name="syntax"></a>Sintaxe

```cpp
typedef struct SYMBOL_NAME_DATA_TAG
{
    unsigned long long  Key;
    const char*         Name;

} SYMBOL_NAME_DATA;
```

## <a name="members"></a>Membros

|  |  |
|--|--|
| `Key` | A chave do símbolo. Esse valor é único dentro do traço que está sendo analisado. |
| `Name` | O nome do símbolo. |

## <a name="remarks"></a>Comentários

Símbolos provenientes de dois passes front-end de compilador diferentes podem ter o mesmo nome, mas uma chave diferente. Neste caso, use nomes de símbolos para determinar se dois tipos são iguais.

::: moniker-end
