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
ms.openlocfilehash: 08adfcc770551d3050daa46c870b950e468c95b3
ms.sourcegitcommit: eff68e4e82be292a5664616b16a526df3e9d1cda
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80150633"
---
# <a name="operator-ltsample-containergt"></a>operator== (&lt;sample container&gt;)

> [!NOTE]
> Este tópico está na documentação da C++ Microsoft como um exemplo não funcional de contêineres usados na biblioteca C++ padrão. Para obter mais informações, consulte [Contêineres da biblioteca padrão C++](../standard-library/stl-containers.md).

Sobrecargas `operator==` para comparar dois objetos do [contêiner](../standard-library/sample-container-class.md)de modelo de classe.

## <a name="syntax"></a>Sintaxe

```cpp
template <class Ty>
bool operator==(
    const Container <Ty>& left,
    const Container <Ty>& right);
```

## <a name="return-value"></a>Valor retornado

Retorna `left.`[tamanho](../standard-library/container-class-size.md) `== right.size && equal(left.`[início](../standard-library/container-class-begin.md)`, left.``, right.begin)`de [término](../standard-library/container-class-end.md) .

## <a name="see-also"></a>Consulte também

[\<sample container>](../standard-library/sample-container.md)
