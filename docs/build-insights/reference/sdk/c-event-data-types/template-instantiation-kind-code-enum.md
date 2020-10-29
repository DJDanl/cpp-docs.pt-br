---
title: TEMPLATE_INSTANTIATION_KIND_CODE enum
description: O SDK do insights de compilação do C++ TEMPLATE_INSTANTIATION_KIND_CODE referência de enumeração.
ms.date: 02/12/2020
helpviewer_keywords:
- C++ Build Insights
- C++ Build Insights SDK
- TEMPLATE_INSTANTIATION_KIND_CODE
- throughput analysis
- build time analysis
- vcperf.exe
ms.openlocfilehash: 2ee85af4e3d7f19b1b5dc9163dab6090f5ce4e42
ms.sourcegitcommit: 9c2b3df9b837879cd17932ae9f61cdd142078260
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/29/2020
ms.locfileid: "92920938"
---
# <a name="template_instantiation_kind_code-enum"></a>TEMPLATE_INSTANTIATION_KIND_CODE enum

::: moniker range="<=msvc-140"

O SDK do insights de compilação do C++ é compatível com o Visual Studio 2017 e superior. Para ver a documentação dessas versões, defina o controle do seletor de **versão** do Visual Studio para este artigo como visual Studio 2017 ou visual Studio 2019. Ele é encontrado na parte superior do Sumário nesta página.

::: moniker-end
::: moniker range=">=msvc-150"

A `TEMPLATE_INSTANTIATION_KIND_CODE` enumeração.

## <a name="members"></a>Membros

| Nome | Valor | Descrição |
|--|--|--|
| `TEMPLATE_INSTANTIATION_KIND_CODE_CLASS` | 0 (0x00000000) | Uma instanciação de modelo de classe. |
| `TEMPLATE_INSTANTIATION_KIND_CODE_FUNCTION` | 1 (0x00000001) | Uma instanciação de modelo de função. |
| `TEMPLATE_INSTANTIATION_KIND_CODE_VARIABLE` | 2 (0x00000002) | Uma instanciação de variável constexpr. |
| `TEMPLATE_INSTANTIATION_KIND_CODE_CONCEPT` | 3 (0x00000003) | Uma instanciação de modelo de conceito. |

## <a name="remarks"></a>Comentários

::: moniker-end
