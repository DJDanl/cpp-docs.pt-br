---
title: '&lt;bit&gt;'
description: Funções para acessar, manipular e processar bits individuais e sequências de bits.
ms.date: 08/28/2020
f1_keywords:
- <bit>
helpviewer_keywords:
- bit header
ms.openlocfilehash: f9742ce1e15a817923c144544eb3bb6325e76765
ms.sourcegitcommit: a1676bf6caae05ecd698f26ed80c08828722b237
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/29/2020
ms.locfileid: "91509956"
---
# <a name="ltbitgt"></a>&lt;bit&gt;

Define funções para acessar, manipular e processar bits individuais e sequências de bits.

Por exemplo, há funções para girar bits, localizar o número de bits definidos ou limpos consecutivos, ver se um número é uma potência integral de dois, localizar o menor número de bits para representar um número e assim por diante.

## <a name="requirements"></a>Requisitos

**Cabeçalho:**\<bit>

**Namespace:** std

[/std: c + + mais recente](../build/reference/std-specify-language-standard-version.md) é necessário.

## <a name="members"></a>Membros

### <a name="types"></a>Tipos

| Tipo | Descrição |
|--------|----------|
| [extremidade](bit-enum.md) | Especifica a endian de tipos escalares. |

### <a name="functions"></a>Funções

| Função | Descrição |
|-----|-----|
|[bit_cast](bit-functions.md#bit_cast) | Reinterprete a representação de objeto de um tipo para outro. |
|[bit_ceil](bit-functions.md#bit_ceil) | Localize a menor potência de dois maiores ou iguais a um valor. |
|[bit_floor](bit-functions.md#bit_floor) | Localize a maior potência integral de dois que não seja maior que um valor. |
|[bit_width](bit-functions.md#bit_width) | Localize o menor número de bits necessários para representar um valor. |
|[countl_zero](bit-functions.md#countl_zero) | Conte o número de bits consecutivos definidos como zero, começando do bit mais significativo. |
|[countl_one](bit-functions.md#countl_one) | Conte o número de bits consecutivos definidos como um, começando do bit mais significativo. |
|[countr_zero](bit-functions.md#countr_zero) | Conte o número de bits consecutivos definidos como zero, começando do bit menos significativo. |
|[countr_one](bit-functions.md#countl_one) | Conte o número de bits consecutivos definidos como um, começando do bit menos significativo. |
|[has_single_bit](bit-functions.md#has_single_bit) | Verifique se um valor tem apenas um conjunto de bits único como um. Isso é o mesmo que testar se um valor é uma potência de dois. |
|[popcount](bit-functions.md#popcount) | Conte o número de bits definidos como um. |
|[rotl](bit-functions.md#rotl) | Computar o resultado de uma rotação de um bit à esquerda. |
|[rotr](bit-functions.md#rotr) | Computar o resultado de uma rotação para a direita. |

## <a name="see-also"></a>Consulte também

[Referência de Arquivos de Cabeçalho](cpp-standard-library-header-files.md)
