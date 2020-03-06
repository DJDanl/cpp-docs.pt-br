---
title: Estrutura de INVOCATION_VERSION_DATA
description: A C++ referência da estrutura de INVOCATION_VERSION_DATA do SDK do insights do Build.
ms.date: 02/12/2020
helpviewer_keywords:
- C++ Build Insights
- C++ Build Insights SDK
- INVOCATION_VERSION_DATA
- throughput analysis
- build time analysis
- vcperf.exe
ms.openlocfilehash: 040b0f90b14133ec2b25f7a12d35b88d382c4f7a
ms.sourcegitcommit: 3e8fa01f323bc5043a48a0c18b855d38af3648d4
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/05/2020
ms.locfileid: "78333674"
---
# <a name="invocation_version_data-structure"></a>Estrutura de INVOCATION_VERSION_DATA

::: moniker range="<=vs-2015"

O C++ SDK de informações de compilação é compatível com o Visual Studio 2017 e superior. Para ver a documentação dessas versões, defina o controle do seletor de versão do Visual Studio para este artigo como Visual Studio 2017 ou Visual Studio 2019.

::: moniker-end
::: moniker range=">=vs-2017"

A estrutura de `INVOCATION_VERSION_DATA` descreve um número de versão como um grupo de valores integrais.

## <a name="syntax"></a>Sintaxe

```cpp
typedef struct INVOCATION_VERSION_DATA_TAG
{
    unsigned short VersionMajor;
    unsigned short VersionMinor;
    unsigned short BuildNumberMajor;
    unsigned short BuildNumberMinor;

} INVOCATION_VERSION_DATA;
```

## <a name="members"></a>Membros

|  |  |
|--|--|
| `VersionMajor` | O número principal da versão. |
| `VersionMinor` | O número secundário da versão. |
| `BuildNumberMajor` | O número principal da compilação. |
| `BuildNumberMinor` | O número secundário da compilação. |

::: moniker-end
