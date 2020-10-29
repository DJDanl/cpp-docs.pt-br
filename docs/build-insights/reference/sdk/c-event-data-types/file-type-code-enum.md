---
title: FILE_TYPE_CODE enum
description: O SDK do insights de compilação do C++ FILE_TYPE_CODE referência de enumeração.
ms.date: 02/12/2020
helpviewer_keywords:
- C++ Build Insights
- C++ Build Insights SDK
- FILE_TYPE_CODE
- throughput analysis
- build time analysis
- vcperf.exe
ms.openlocfilehash: ddd625829e94786c0daddf0e78b914e225b2ecfb
ms.sourcegitcommit: 9c2b3df9b837879cd17932ae9f61cdd142078260
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/29/2020
ms.locfileid: "92921017"
---
# <a name="file_type_code-enum"></a>FILE_TYPE_CODE enum

::: moniker range="<=msvc-140"

O SDK do insights de compilação do C++ é compatível com o Visual Studio 2017 e superior. Para ver a documentação dessas versões, defina o controle do seletor de **versão** do Visual Studio para este artigo como visual Studio 2017 ou visual Studio 2019. Ele é encontrado na parte superior do Sumário nesta página.

::: moniker-end
::: moniker range=">=msvc-150"

A `FILE_TYPE_CODE` Enumeração descreve o tipo de um arquivo.

## <a name="members"></a>Membros

| Nome | Valor | Descrição |
|--|--|--|
| `FILE_TYPE_CODE_OTHER` | 0 (0x00000000) | Um tipo de arquivo não listado nesta enumeração. |
| `FILE_TYPE_CODE_OBJ` | 1 (0x00000001) | Um arquivo de objeto ( \* . obj). |
| `FILE_TYPE_CODE_EXECUTABLE_IMAGE` | 2 (0x00000002) | Um arquivo executável ( \* . exe) ou DLL ( \* . dll). |
| `FILE_TYPE_CODE_LIB` | 3 (0x00000003) | Um arquivo de biblioteca estática (*. lib). |
| `FILE_TYPE_CODE_IMP_LIB` | 4 (0x00000004) | Uma biblioteca de importação (*. lib) |
| `FILE_TYPE_CODE_EXP` | 5 (0x00000005) | Um arquivo de exportação (*. exp). |

## <a name="remarks"></a>Comentários

::: moniker-end
