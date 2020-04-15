---
title: FILE_TYPE_CODE enum
description: O C++ Build Insights SDK FILE_TYPE_CODE referência enum.
ms.date: 02/12/2020
helpviewer_keywords:
- C++ Build Insights
- C++ Build Insights SDK
- FILE_TYPE_CODE
- throughput analysis
- build time analysis
- vcperf.exe
ms.openlocfilehash: dea603a072d7b2f472112a75b2e9ccded78399a9
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81325556"
---
# <a name="file_type_code-enum"></a>FILE_TYPE_CODE enum

::: moniker range="<=vs-2015"

O C++ Build Insights SDK é compatível com o Visual Studio 2017 e acima. Para ver a documentação dessas versões, defina o controle do seletor Visual Studio **Version** para este artigo para visual studio 2017 ou Visual Studio 2019. É encontrado no topo da tabela de conteúdo nesta página.

::: moniker-end
::: moniker range=">=vs-2017"

O `FILE_TYPE_CODE` enum descreve o tipo de arquivo.

## <a name="members"></a>Membros

| Nome | Valor | Descrição |
|--|--|--|
| `FILE_TYPE_CODE_OTHER` | 0 (0x0000000000) | Um tipo de arquivo não listado neste enum. |
| `FILE_TYPE_CODE_OBJ` | 1 (0x00000001) | Um arquivo\*object (.obj). |
| `FILE_TYPE_CODE_EXECUTABLE_IMAGE` | 2 (0x000000002) | Um arquivo\*executável (.exe)\*ou DLL (.dll). |
| `FILE_TYPE_CODE_LIB` | 3 (0x0000000003) | Um arquivo de biblioteca estática (*.lib). |
| `FILE_TYPE_CODE_IMP_LIB` | 4 (0x0000000004) | Uma biblioteca de importação (*.lib) |
| `FILE_TYPE_CODE_EXP` | 5 (0x000000005) | Um arquivo de exportação (*.exp). |

## <a name="remarks"></a>Comentários

::: moniker-end
