---
title: Classe de Contêiner::erase
ms.date: 11/04/2016
helpviewer_keywords:
- erase method
ms.assetid: abc091c5-5a80-4bd8-93a8-a2d9bde2efec
ms.openlocfilehash: 1463a854c314884f0b3b6bffa5d37dfb7fec4a6f
ms.sourcegitcommit: 0dcab746c49f13946b0a7317fc9769130969e76d
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/24/2019
ms.locfileid: "68454507"
---
# <a name="container-classerase"></a>Classe de Contêiner::erase

> [!NOTE]
> Este tópico está na documentação da C++ Microsoft como um exemplo não funcional de contêineres usados na biblioteca C++ padrão. Para obter mais informações, consulte [Contêineres da biblioteca padrão C++](../standard-library/stl-containers.md).

Apaga um elemento.

## <a name="syntax"></a>Sintaxe

```

    iterator erase(
    iterator _Where);

iterator erase(
    iterator first,
    iterator last);
```

## <a name="remarks"></a>Comentários

A primeira função de membro remove o elemento da sequência controlada apontada por *_Where*. A segunda função de membro remove os elementos da sequência controlada no intervalo [`first`, `last`). As duas retornarão um iterador que designa o primeiro elemento restante além de todos os elementos removidos ou [end](../standard-library/container-class-end.md) se esse elemento não existir.

As funções de membro gerarão uma exceção apenas se uma operação de cópia gerar uma exceção.

## <a name="see-also"></a>Consulte também

[Classe de contêiner de amostra](../standard-library/sample-container-class.md)
