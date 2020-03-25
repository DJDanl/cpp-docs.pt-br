---
title: allocate
ms.date: 11/04/2016
f1_keywords:
- allocate_cpp
helpviewer_keywords:
- __declspec keyword [C++], allocate
- allocate __declspec keyword
ms.assetid: 67828b31-de60-4c0e-b0a6-ef3aab22641d
ms.openlocfilehash: 6d9429aa7c079f0f99a936019e5945092dc1f006
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80181519"
---
# <a name="allocate"></a>allocate

**Seção específica da Microsoft**

O especificador de Declaração **ALLOCATE** nomeia um segmento de dados no qual o item de dados será alocado.

## <a name="syntax"></a>Sintaxe

```
   __declspec(allocate("segname")) declarator
```

## <a name="remarks"></a>Comentários

O nome *segname* deve ser declarado usando um dos seguintes pragmas:

- [code_seg](../preprocessor/code-seg.md)

- [const_seg](../preprocessor/const-seg.md)

- [data_seg](../preprocessor/data-seg.md)

- [init_seg](../preprocessor/init-seg.md)

- [seção](../preprocessor/section.md)

## <a name="example"></a>Exemplo

```cpp
// allocate.cpp
#pragma section("mycode", read)
__declspec(allocate("mycode"))  int i = 0;

int main() {
}
```

**Fim da seção específica da Microsoft**

## <a name="see-also"></a>Confira também

[__declspec](../cpp/declspec.md)<br/>
[Palavras-chave](../cpp/keywords-cpp.md)
