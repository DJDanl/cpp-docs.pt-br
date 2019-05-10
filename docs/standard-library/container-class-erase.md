---
title: Classe de Contêiner::erase
ms.date: 11/04/2016
helpviewer_keywords:
- erase method
ms.assetid: abc091c5-5a80-4bd8-93a8-a2d9bde2efec
ms.openlocfilehash: 0ef4db1c14942fc896f10095ff2331648d27c820
ms.sourcegitcommit: da32511dd5baebe27451c0458a95f345144bd439
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/07/2019
ms.locfileid: "65221642"
---
# <a name="container-classerase"></a>Classe de Contêiner::erase

> [!NOTE]
> Este tópico é no Microsoft C++ como um exemplo não funcional de contêineres usados na documentação do C++ biblioteca padrão. Para obter mais informações, consulte [Contêineres da biblioteca padrão C++](../standard-library/stl-containers.md).

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

A primeira função membro remove o elemento da sequência controlada apontada por *_Where*. A segunda função de membro remove os elementos da sequência controlada no intervalo [`first`, `last`). As duas retornarão um iterador que designa o primeiro elemento restante além de todos os elementos removidos ou [end](../standard-library/container-class-end.md) se esse elemento não existir.

As funções de membro gerarão uma exceção apenas se uma operação de cópia gerar uma exceção.

## <a name="see-also"></a>Consulte também

[Classe de contêiner de amostra](../standard-library/sample-container-class.md)<br/>
