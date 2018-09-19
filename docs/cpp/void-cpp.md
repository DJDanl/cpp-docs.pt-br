---
title: void (C++) | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-language
ms.topic: language-reference
f1_keywords:
- void_cpp
dev_langs:
- C++
helpviewer_keywords:
- void keyword [C++]
- functions [C++], void
- pointers, void
ms.assetid: d203edba-38e6-4056-8b89-011437351057
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 1aab4a8c18424fdbd52ac24444dd35a1660a714b
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46114339"
---
# <a name="void-c"></a>void (C++)

Quando usado como um tipo de retorno de função, o **void** palavra-chave especifica que a função não retorna um valor. Quando usado para a lista de parâmetros de uma função, um item nulo especifica que a função não usa parâmetros. Quando usado em declaração de um ponteiro nulo, especifica que o ponteiro é “universal”.

Se for do tipo de um ponteiro `void *`, o ponteiro pode apontar para qualquer variável que não é declarado com o **const** ou **volátil** palavra-chave. Um ponteiro nulo não pode ter a referência removida a menos que seja convertido para outro tipo. Um ponteiro nulo pode ser convertido em outro tipo de ponteiro de dados.

Um ponteiro nulo pode apontar para uma função, mas não para um membro da classe em C++.

Você não pode declarar uma variável de tipo nulo.

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

## <a name="see-also"></a>Consulte também

[Palavras-chave](../cpp/keywords-cpp.md)<br/>
[Tipos fundamentais](../cpp/fundamental-types-cpp.md)