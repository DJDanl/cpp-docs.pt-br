---
title: Enumerações &lt;codecvt&gt;
ms.date: 11/04/2016
f1_keywords:
- codecvt/std::codecvt_mode
ms.assetid: 46a8b073-01bc-46d3-b3d3-a8540f9422c1
helpviewer_keywords:
- std::codecvt_mode
ms.openlocfilehash: 0b43c7c148076e96dd0d3f444ffa8b6bad7c8b29
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50566147"
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

[\<codecvt>](../standard-library/codecvt.md)<br/>
