---
title: Estrutura de SYMBOL_NAME_DATA
description: A C++ referência da estrutura de SYMBOL_NAME_DATA do SDK do insights do Build.
ms.date: 02/12/2020
helpviewer_keywords:
- C++ Build Insights
- C++ Build Insights SDK
- SYMBOL_NAME_DATA
- throughput analysis
- build time analysis
- vcperf.exe
ms.openlocfilehash: 618e84f198c20aa089dc7e06e1e6c09b96b6d273
ms.sourcegitcommit: 3e8fa01f323bc5043a48a0c18b855d38af3648d4
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/05/2020
ms.locfileid: "78333632"
---
# <a name="symbol_name_data-structure"></a>Estrutura de SYMBOL_NAME_DATA

::: moniker range="<=vs-2015"

O C++ SDK de informações de compilação é compatível com o Visual Studio 2017 e superior. Para ver a documentação dessas versões, defina o controle do seletor de versão do Visual Studio para este artigo como Visual Studio 2017 ou Visual Studio 2019.

::: moniker-end
::: moniker range=">=vs-2017"

A estrutura de `SYMBOL_NAME_DATA` descreve um símbolo de front-end do compilador.

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
| `Key` | A chave do símbolo. Esse valor é exclusivo dentro do rastreamento que está sendo analisado. |
| `Name` | O nome do símbolo. |

## <a name="remarks"></a>Comentários

Os símbolos provenientes de dois passos de front-end do compilador diferentes podem ter o mesmo nome, mas uma chave diferente. Nesse caso, use nomes de símbolo para determinar se dois tipos são os mesmos.

::: moniker-end
