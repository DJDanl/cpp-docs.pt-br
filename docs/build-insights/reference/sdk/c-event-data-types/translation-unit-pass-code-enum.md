---
title: TRANSLATION_UNIT_PASS_CODE enum
description: O SDK do insights de compilação do C++ TRANSLATION_UNIT_PASS_CODE referência de enumeração.
ms.date: 02/12/2020
helpviewer_keywords:
- C++ Build Insights
- C++ Build Insights SDK
- TRANSLATION_UNIT_PASS_CODE
- throughput analysis
- build time analysis
- vcperf.exe
ms.openlocfilehash: 31f3e16ce6d9aa8c3c9db6cf9c11069dc3ec22fe
ms.sourcegitcommit: 9c2b3df9b837879cd17932ae9f61cdd142078260
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/29/2020
ms.locfileid: "92920912"
---
# <a name="translation_unit_pass_code-enum"></a>TRANSLATION_UNIT_PASS_CODE enum

::: moniker range="<=msvc-140"

O SDK do insights de compilação do C++ é compatível com o Visual Studio 2017 e superior. Para ver a documentação dessas versões, defina o controle do seletor de **versão** do Visual Studio para este artigo como visual Studio 2017 ou visual Studio 2019. Ele é encontrado na parte superior do Sumário nesta página.

::: moniker-end
::: moniker range=">=msvc-150"

A `TRANSLATION_UNIT_PASS_CODE` enumeração.

## <a name="members"></a>Membros

| Nome | Valor | Descrição |
|--|--|--|
| `TRANSLATION_UNIT_PASS_CODE_FRONT_END` | 0 (0x00000000) | A passagem de front-end, responsável por analisar o código-fonte e convertê-lo em linguagem intermediária. |
| `TRANSLATION_UNIT_PASS_CODE_BACK_END` | 1 (0x00000001) | A passagem de back-end, responsável por otimizar a linguagem intermediária e convertê-la no código da máquina. |

## <a name="remarks"></a>Comentários

Usado pelas funções do SDK do C.

::: moniker-end
