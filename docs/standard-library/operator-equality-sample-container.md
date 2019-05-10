---
title: operator== (&lt;sample container&gt;)
ms.date: 11/04/2016
f1_keywords:
- std.==
- std::==
- operator==
- std.operator==
- std::operator==
- ==
helpviewer_keywords:
- operator ==, containers
- operator==, containers
- == operator, with specific standard C++ objects
ms.assetid: d3d8754e-5157-4b8b-bf9c-da41856f5eed
ms.openlocfilehash: 9313df5d75efa043f2fb9df6090c125de75a2636
ms.sourcegitcommit: da32511dd5baebe27451c0458a95f345144bd439
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/07/2019
ms.locfileid: "65220262"
---
# <a name="operator-ltsample-containergt"></a>operator== (&lt;sample container&gt;)

> [!NOTE]
> Este tópico é no Microsoft C++ como um exemplo não funcional de contêineres usados na documentação do C++ biblioteca padrão. Para obter mais informações, consulte [Contêineres da biblioteca padrão C++](../standard-library/stl-containers.md).

Sobrecarrega `operator==` para comparar dois objetos da classe de modelo [Container](../standard-library/sample-container-class.md).

## <a name="syntax"></a>Sintaxe

```cpp
template <class Ty>
bool operator==(
    const Container <Ty>& left,
    const Container <Ty>& right);
```

## <a name="return-value"></a>Valor de retorno

Retorna `left.` [tamanho](../standard-library/container-class-size.md) ` == right.size && equal(left.` [começar](../standard-library/container-class-begin.md)`, left.`[final](../standard-library/container-class-end.md)`, right.begin)`.

## <a name="see-also"></a>Consulte também

[\<sample container>](../standard-library/sample-container.md)<br/>
