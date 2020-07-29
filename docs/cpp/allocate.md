---
title: allocate
ms.date: 11/04/2016
f1_keywords:
- allocate_cpp
helpviewer_keywords:
- __declspec keyword [C++], allocate
- allocate __declspec keyword
ms.assetid: 67828b31-de60-4c0e-b0a6-ef3aab22641d
ms.openlocfilehash: 0bf31423cd76c838cbeffa7458bbccb89592bf43
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87227615"
---
# <a name="allocate"></a>allocate

**Específico da Microsoft**

O **`allocate`** especificador de declaração nomeia um segmento de dados no qual o item de dados será alocado.

## <a name="syntax"></a>Sintaxe

> **`__declspec(allocate("`***segname* **`))`** *Declarador*

## <a name="remarks"></a>Comentários

O nome *segname* deve ser declarado usando um dos seguintes pragmas:

- [code_seg](../preprocessor/code-seg.md)

- [const_seg](../preprocessor/const-seg.md)

- [data_seg](../preprocessor/data-seg.md)

- [init_seg](../preprocessor/init-seg.md)

- [Section](../preprocessor/section.md)

## <a name="example"></a>Exemplo

```cpp
// allocate.cpp
#pragma section("mycode", read)
__declspec(allocate("mycode"))  int i = 0;

int main() {
}
```

**FINAL específico da Microsoft**

## <a name="see-also"></a>Confira também

[`__declspec`](../cpp/declspec.md)<br/>
[Palavras-chave](../cpp/keywords-cpp.md)
