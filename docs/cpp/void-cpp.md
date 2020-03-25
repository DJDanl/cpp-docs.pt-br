---
title: void (C++)
ms.date: 11/04/2016
f1_keywords:
- void_cpp
helpviewer_keywords:
- void keyword [C++]
- functions [C++], void
- pointers, void
ms.assetid: d203edba-38e6-4056-8b89-011437351057
ms.openlocfilehash: 2de019f908942a58b232877fcd9eebc4689d8e22
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80187473"
---
# <a name="void-c"></a>void (C++)

Quando usado como um tipo de retorno de função, a palavra-chave **void** especifica que a função não retorna um valor. Quando usado para a lista de parâmetros de uma função, **void** especifica que a função não usa nenhum parâmetro. Quando usado na declaração de um ponteiro, **void** especifica que o ponteiro é "Universal".

Se o tipo de um ponteiro for **void\*** , o ponteiro poderá apontar para qualquer variável que não esteja declarada com a palavra-chave **const** ou **volatile** . Um ponteiro de **\*void** não pode ser desreferenciado, a menos que seja convertido em outro tipo. Um ponteiro de **\*void** pode ser convertido em qualquer outro tipo de ponteiro de dados.

Um ponteiro **void** pode apontar para uma função, mas não para um membro de classe C++no.

Você não pode declarar uma variável do tipo **void**.

## <a name="example"></a>Exemplo

```cpp
// void.cpp
void vobject;   // C2182
void *pv;   // okay
int *pint; int i;
int main() {
   pv = &i;
   // Cast optional in C required in C++
   pint = (int *)pv;
}
```

## <a name="see-also"></a>Confira também

[Palavras-chave](../cpp/keywords-cpp.md)<br/>
[Tipos internos](../cpp/fundamental-types-cpp.md)
