---
title: Enumerações &lt;codecvt&gt;
ms.date: 11/04/2016
f1_keywords:
- codecvt/std::codecvt_mode
ms.assetid: 46a8b073-01bc-46d3-b3d3-a8540f9422c1
helpviewer_keywords:
- std::codecvt_mode
ms.openlocfilehash: bbef1fe28c3321f06c0cc586062cd017168f8e73
ms.sourcegitcommit: 0dcab746c49f13946b0a7317fc9769130969e76d
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/24/2019
ms.locfileid: "68459787"
---
# <a name="ltcodecvtgt-enums"></a>Enumerações &lt;codecvt&gt;

## <a name="codecvt_mode"></a>  Enumeração codecvt_mode

Especifica informações de configuração para facetas de [localidade](../standard-library/locale-class.md).

```cpp
enum codecvt_mode {
    consume_header = 4,
    generate_header = 2,
    little_endian = 1
};
```

### <a name="remarks"></a>Comentários

A enumeração define três constantes que fornecem informações de configuração para as facetas de localidade declaradas em [\<codecvt>](../standard-library/codecvt.md). Os valores distintos são:

- `consume_header`, para consumir uma sequência de cabeçalho inicial ao ler uma sequência multibyte e determinar a extremidade da sequência multibyte subsequente a ser lida

- `generate_header`, para gerar uma sequência de cabeçalho inicial ao escrever uma sequência multibyte para anunciar a extremidade da sequência multibyte subsequente a ser escrita

- `little_endian`, para gerar uma sequência multibyte em ordem little endian em oposição à ordem big endian padrão

Essas constantes podem estar ORed juntas em combinações arbitrárias.

## <a name="see-also"></a>Consulte também

[\<codecvt>](../standard-library/codecvt.md)
