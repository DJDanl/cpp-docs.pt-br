---
title: Estrutura de SYMBOL_NAME_DATA
description: A referência de estrutura do SDK do insights de compilação do C++ SYMBOL_NAME_DATA.
ms.date: 02/12/2020
helpviewer_keywords:
- C++ Build Insights
- C++ Build Insights SDK
- SYMBOL_NAME_DATA
- throughput analysis
- build time analysis
- vcperf.exe
ms.openlocfilehash: 08c09f304f8cc90bd48a2cecc6771d90c997a7f4
ms.sourcegitcommit: 9c2b3df9b837879cd17932ae9f61cdd142078260
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/29/2020
ms.locfileid: "92920925"
---
# <a name="symbol_name_data-structure"></a>Estrutura de SYMBOL_NAME_DATA

::: moniker range="<=msvc-140"

O SDK do insights de compilação do C++ é compatível com o Visual Studio 2017 e superior. Para ver a documentação dessas versões, defina o controle do seletor de **versão** do Visual Studio para este artigo como visual Studio 2017 ou visual Studio 2019. Ele é encontrado na parte superior do Sumário nesta página.

::: moniker-end
::: moniker range=">=msvc-150"

A `SYMBOL_NAME_DATA` estrutura descreve um símbolo de front-end do compilador.

## <a name="syntax"></a>Sintaxe

```cpp
typedef struct SYMBOL_NAME_DATA_TAG
{
    unsigned long long  Key;
    const char*         Name;

} SYMBOL_NAME_DATA;
```

## <a name="members"></a>Membros

| Nome | Descrição |
|--|--|
| `Key` | A chave do símbolo. Esse valor é exclusivo dentro do rastreamento que está sendo analisado. |
| `Name` | O nome do símbolo. |

## <a name="remarks"></a>Comentários

Os símbolos provenientes de dois passos de front-end do compilador diferentes podem ter o mesmo nome, mas uma chave diferente. Nesse caso, use nomes de símbolo para determinar se dois tipos são os mesmos.

::: moniker-end
