---
title: Enumerações &lt;codecvt&gt;
ms.date: 11/04/2016
f1_keywords:
- codecvt/std::codecvt_mode
ms.assetid: 46a8b073-01bc-46d3-b3d3-a8540f9422c1
helpviewer_keywords:
- std::codecvt_mode
ms.openlocfilehash: e67290d8de0b8251191c4a93b66b7e19a293ed61
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81371938"
---
# <a name="ltcodecvtgt-enums"></a>Enumerações &lt;codecvt&gt;

## <a name="codecvt_mode-enumeration"></a><a name="codecvt_mode"></a>enumeração codecvt_mode

Especifica as informações de configuração [para](../standard-library/locale-class.md) facetas locais.

```cpp
enum codecvt_mode {
    consume_header = 4,
    generate_header = 2,
    little_endian = 1
};
```

### <a name="remarks"></a>Comentários

A enumeração define três constantes que fornecem informações de configuração às facetas locais declaradas em [ \<codecvt>](../standard-library/codecvt.md). Os valores distintos são:

- `consume_header`, para consumir uma sequência de cabeçalho inicial ao ler uma sequência multibyte e determinar a extremidade da sequência multibyte subsequente a ser lida

- `generate_header`, para gerar uma sequência de cabeçalho inicial ao escrever uma sequência multibyte para anunciar a extremidade da sequência multibyte subsequente a ser escrita

- `little_endian`, para gerar uma sequência multibyte em ordem little endian em oposição à ordem big endian padrão

Essas constantes podem estar ORed juntas em combinações arbitrárias.

## <a name="see-also"></a>Confira também

[\<codecvt>](../standard-library/codecvt.md)
