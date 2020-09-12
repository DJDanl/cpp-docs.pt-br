---
title: Enumeração endian
description: Enumeração usada para especificar a endian de tipos escalares
ms.date: 08/27/2020
f1_keywords:
- bit/std::endian
helpviewer_keywords:
- std::endian
ms.openlocfilehash: b535bc009fbdc0b047444a6bc2ca36eed7a6d1cb
ms.sourcegitcommit: 6280a4c629de0f638ebc2edd446de2a9b11f0406
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/12/2020
ms.locfileid: "90040074"
---
# <a name="endian-enum"></a>Enumeração endian

Indica a endian de todos os tipos escalares.

## <a name="syntax"></a>Sintaxe

```cpp
enum class endian {
    little = 0,
    big = 1,
    native = little
 };
```

### <a name="members"></a>Membros

|Elemento|Descrição|
|-|-|
| `little` | Indica que os tipos escalares são little-endian. Ou seja, o byte menos significativo é armazenado no menor endereço. Por exemplo, `0x1234` é armazenado `0x34` `0x12` .  |
| `big` | Indica que os tipos escalares são big-endian, ou seja, o byte mais significativo é armazenado no menor endereço. Por exemplo, `0x1234` é armazenado `0x12` `0x34` .  |

## <a name="remarks"></a>Comentários

Todos os tipos escalares nativos são little-endian para as plataformas que Microsoft Visual C++ destinos (x86, x64, ARM, ARM64).

## <a name="requirements"></a>Requisitos

**Cabeçalho:**\<bit>

**Namespace:** std

[/std: c + + mais recente](../build/reference/std-specify-language-standard-version.md) é necessário.

## <a name="see-also"></a>Confira também

[\<bit>](../standard-library/bit.md)  
