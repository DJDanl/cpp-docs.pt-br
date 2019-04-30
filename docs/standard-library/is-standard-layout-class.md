---
title: Classe is_standard_layout
ms.date: 11/04/2016
f1_keywords:
- type_traits/std::is_standard_layout
helpviewer_keywords:
- is_standard_layout class
- is_standard_layout
ms.assetid: 15ccf111-f537-45ef-b552-59152a7ba312
ms.openlocfilehash: 75691c1b09b71580474cc22cdc8382bff55a5e29
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62413484"
---
# <a name="isstandardlayout-class"></a>Classe is_standard_layout

Testa se o tipo é um layout padrão.

## <a name="syntax"></a>Sintaxe

```cpp
template <class Ty>
struct is_standard_layout;
```

### <a name="parameters"></a>Parâmetros

|Parâmetro|Descrição|
|---------------|-----------------|
|*Ty*|O tipo a ser consultado|

## <a name="remarks"></a>Comentários

Uma instância deste predicado de tipo será verdadeira se o tipo *Ty* é uma classe que tem um layout padrão dos objetos de membro na memória, caso contrário, será falsa.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** \<type_traits>

**Namespace:** std

## <a name="see-also"></a>Consulte também

[<type_traits>](../standard-library/type-traits.md)<br/>
