---
title: Aviso do compilador (nível 1) C4369
ms.date: 11/04/2016
f1_keywords:
- C4369
helpviewer_keywords:
- C4369
ms.assetid: ade87e84-36be-4e00-be99-2930af848feb
ms.openlocfilehash: 617cb2cc3774b288581a3868125ced19b28ba45a
ms.sourcegitcommit: e5192a25c084eda9eabfa37626f3274507e026b3
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 11/12/2019
ms.locfileid: "73966504"
---
# <a name="compiler-warning-level-1-c4369"></a>Aviso do compilador (nível 1) C4369

' Enumerator ': o valor do enumerador ' value ' não pode ser representado como ' type ', o valor é ' new_value '

Um enumerador foi calculado para ser maior que o maior valor para o tipo subjacente especificado.  Isso causou um estouro e o compilador encapsulava o valor do enumerador para o menor valor possível para o tipo.

## <a name="example"></a>Exemplo

O exemplo a seguir gera C4369.

```cpp
// C4369.cpp
// compile with: /W1
int main() {
   enum Color: char { red = 0x7e, green, blue };   // C4369
   enum Color2: char { red2 = 0x7d, green2, blue2};   // OK
}
```