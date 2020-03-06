---
title: TRANSLATION_UNIT_PASS_CODE enum
description: O C++ SDK da compilação de informações TRANSLATION_UNIT_PASS_CODE referência de enumeração.
ms.date: 02/12/2020
helpviewer_keywords:
- C++ Build Insights
- C++ Build Insights SDK
- TRANSLATION_UNIT_PASS_CODE
- throughput analysis
- build time analysis
- vcperf.exe
ms.openlocfilehash: 1219eed98fd01e8c91d8750977e2d8ca4498d649
ms.sourcegitcommit: 3e8fa01f323bc5043a48a0c18b855d38af3648d4
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/05/2020
ms.locfileid: "78333576"
---
# <a name="translation_unit_pass_code-enum"></a>TRANSLATION_UNIT_PASS_CODE enum

::: moniker range="<=vs-2015"

O C++ SDK de informações de compilação é compatível com o Visual Studio 2017 e superior. Para ver a documentação dessas versões, defina o controle do seletor de versão do Visual Studio para este artigo como Visual Studio 2017 ou Visual Studio 2019.

::: moniker-end
::: moniker range=">=vs-2017"

A `TRANSLATION_UNIT_PASS_CODE` enum.

## <a name="members"></a>Membros

| {1&gt;Nome&lt;1} | {1&gt;Valor&lt;1} | Descrição |
|--|--|--|
| `TRANSLATION_UNIT_PASS_CODE_FRONT_END` | 0 (0x00000000) | A passagem de front-end, responsável por analisar o código-fonte e convertê-lo em linguagem intermediária. |
| `TRANSLATION_UNIT_PASS_CODE_BACK_END` | 1 (0x00000001) | A passagem de back-end, responsável por otimizar a linguagem intermediária e convertê-la no código da máquina. |

## <a name="remarks"></a>Comentários

Usado pelas funções do SDK do C.

::: moniker-end
