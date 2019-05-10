---
title: operator&lt;= (&lt;sample container&gt;)
ms.date: 11/04/2016
f1_keywords:
- std::<=
- std.operator<=
- operator<=
- std.<=
- std::operator<=
- <=
helpviewer_keywords:
- operator<=
- operator <=
- <= operator, with specific objects
- <= operator
ms.assetid: 338577dd-dc88-4a2b-9e12-0379c54fc8a2
ms.openlocfilehash: 78d49f82f39bc0e96f88ffdcad2cde8a20b0f123
ms.sourcegitcommit: da32511dd5baebe27451c0458a95f345144bd439
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/07/2019
ms.locfileid: "65221373"
---
# <a name="operatorlt-ltsample-containergt"></a>operator&lt;= (&lt;sample container&gt;)

> [!NOTE]
> Este tópico é no Microsoft C++ como um exemplo não funcional de contêineres usados na documentação do C++ biblioteca padrão. Para obter mais informações, consulte [Contêineres da biblioteca padrão C++](../standard-library/stl-containers.md).

Sobrecarrega **operator<=** para comparar dois objetos da classe de modelo [Container](../standard-library/sample-container-class.md).

## <a name="syntax"></a>Sintaxe

```cpp
template <class Ty>
bool operator<=(
    const Container <Ty>& left,
    const Container <Ty>& right);
```

## <a name="return-value"></a>Valor de retorno

Retorna `!(right < left)`.

## <a name="see-also"></a>Consulte também

[\<sample container>](../standard-library/sample-container.md)<br/>
