---
title: TRANSLATION_UNIT_PASS_CODE enum
description: O C++ Build Insights SDK TRANSLATION_UNIT_PASS_CODE referência enum.
ms.date: 02/12/2020
helpviewer_keywords:
- C++ Build Insights
- C++ Build Insights SDK
- TRANSLATION_UNIT_PASS_CODE
- throughput analysis
- build time analysis
- vcperf.exe
ms.openlocfilehash: b0162d7e53bb7ee7035b94a6b640f6db87cd8b8d
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81325287"
---
# <a name="translation_unit_pass_code-enum"></a>TRANSLATION_UNIT_PASS_CODE enum

::: moniker range="<=vs-2015"

O C++ Build Insights SDK é compatível com o Visual Studio 2017 e acima. Para ver a documentação dessas versões, defina o controle do seletor Visual Studio **Version** para este artigo para visual studio 2017 ou Visual Studio 2019. É encontrado no topo da tabela de conteúdo nesta página.

::: moniker-end
::: moniker range=">=vs-2017"

O `TRANSLATION_UNIT_PASS_CODE` enum.

## <a name="members"></a>Membros

| Nome | Valor | Descrição |
|--|--|--|
| `TRANSLATION_UNIT_PASS_CODE_FRONT_END` | 0 (0x0000000000) | O passe front-end, responsável por analisar o código-fonte e convertê-lo em linguagem intermediária. |
| `TRANSLATION_UNIT_PASS_CODE_BACK_END` | 1 (0x00000001) | O back-end pass, responsável por otimizar a linguagem intermediária e convertê-la em código de máquina. |

## <a name="remarks"></a>Comentários

Usado pelas funções C SDK.

::: moniker-end
