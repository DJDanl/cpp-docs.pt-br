---
title: Classe de Contêiner::swap
ms.date: 11/04/2016
helpviewer_keywords:
- swap method
ms.assetid: 898c219c-bc8e-4d14-a149-6240426c693f
ms.openlocfilehash: ccf4ae6ebc3ca13a42ca950310a60e30dbb27034
ms.sourcegitcommit: 0dcab746c49f13946b0a7317fc9769130969e76d
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/24/2019
ms.locfileid: "68450764"
---
# <a name="container-classswap"></a>Classe de Contêiner::swap

> [!NOTE]
> Este tópico está na documentação da C++ Microsoft como um exemplo não funcional de contêineres usados na biblioteca C++ padrão. Para obter mais informações, consulte [Contêineres da biblioteca padrão C++](../standard-library/stl-containers.md).

Troca as sequências controladas entre **\*este** e seu argumento.

## <a name="syntax"></a>Sintaxe

```cpp
void swap(Container& right);
```

## <a name="remarks"></a>Comentários

Se for **\*this.get\_allocator ==** _right_ **.get_allocator**, ele fará uma troca em tempo constante. Caso contrário, executará uma série de atribuições de elemento e de chamadas do construtor proporcional ao número de elementos nas duas sequências controladas.

## <a name="see-also"></a>Consulte também

[Classe de contêiner de amostra](../standard-library/sample-container-class.md)
