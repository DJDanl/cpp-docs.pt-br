---
title: FILE_TYPE_CODE enum
description: O C++ SDK da compilação de informações FILE_TYPE_CODE referência de enumeração.
ms.date: 02/12/2020
helpviewer_keywords:
- C++ Build Insights
- C++ Build Insights SDK
- FILE_TYPE_CODE
- throughput analysis
- build time analysis
- vcperf.exe
ms.openlocfilehash: e64f9315c62ce40c436032d6c96fdfa725847a7f
ms.sourcegitcommit: 3e8fa01f323bc5043a48a0c18b855d38af3648d4
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/05/2020
ms.locfileid: "78333716"
---
# <a name="file_type_code-enum"></a>FILE_TYPE_CODE enum

::: moniker range="<=vs-2015"

O C++ SDK de informações de compilação é compatível com o Visual Studio 2017 e superior. Para ver a documentação dessas versões, defina o controle do seletor de versão do Visual Studio para este artigo como Visual Studio 2017 ou Visual Studio 2019.

::: moniker-end
::: moniker range=">=vs-2017"

O `FILE_TYPE_CODE` enum descreve o tipo de um arquivo.

## <a name="members"></a>Membros

| {1&gt;Nome&lt;1} | {1&gt;Valor&lt;1} | Descrição |
|--|--|--|
| `FILE_TYPE_CODE_OTHER` | 0 (0x00000000) | Um tipo de arquivo não listado nesta enumeração. |
| `FILE_TYPE_CODE_OBJ` | 1 (0x00000001) | Um arquivo de objeto (\*. obj). |
| `FILE_TYPE_CODE_EXECUTABLE_IMAGE` | 2 (0x00000002) | Um arquivo executável (\*. exe) ou DLL (\*. dll). |
| `FILE_TYPE_CODE_LIB` | 3 (0x00000003) | Um arquivo de biblioteca estática (*. lib). |
| `FILE_TYPE_CODE_IMP_LIB` | 4 (0x00000004) | Uma biblioteca de importação (*. lib) |
| `FILE_TYPE_CODE_EXP` | 5 (0x00000005) | Um arquivo de exportação (*. exp). |

## <a name="remarks"></a>Comentários

::: moniker-end
