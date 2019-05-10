---
title: operator&gt; (&lt;sample container&gt;)
ms.date: 11/04/2016
f1_keywords:
- std::operator>
- operator>
- std::>
- '>'
helpviewer_keywords:
- '> operator, comparing specific objects'
- operator >
ms.assetid: 49bd417a-3305-4ffa-9884-39d3904ed87d
ms.openlocfilehash: 6d195148e725857c16a0f037b87a7fa0f71841a4
ms.sourcegitcommit: da32511dd5baebe27451c0458a95f345144bd439
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/07/2019
ms.locfileid: "65220480"
---
# <a name="operatorgt-ltsample-containergt"></a>operator&gt; (&lt;sample container&gt;)

> [!NOTE]
> Este tópico é no Microsoft C++ como um exemplo não funcional de contêineres usados na documentação do C++ biblioteca padrão. Para obter mais informações, consulte [Contêineres da biblioteca padrão C++](../standard-library/stl-containers.md).

Sobrecarrega **operator>** para comparar dois objetos da classe de modelo [Container](../standard-library/sample-container-class.md).

## <a name="syntax"></a>Sintaxe

```cpp
template <class Ty>
bool operator*gt;(
    const Container <Ty>& left,
    const Container <Ty>& right);
```

## <a name="return-value"></a>Valor de retorno

Retorna `right < left`.

## <a name="see-also"></a>Consulte também

[\<sample container>](../standard-library/sample-container.md)<br/>
