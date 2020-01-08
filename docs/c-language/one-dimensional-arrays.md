---
title: Matrizes unidimensionais
ms.date: 11/04/2016
helpviewer_keywords:
- brackets [ ]
- brackets [ ], arrays
- one-dimensional arrays
- arrays [C++], one-dimensional
- square brackets [ ]
- square brackets [ ], arrays
- subscript expressions
ms.assetid: e28536e5-3b77-46b5-97fd-9b938c771816
ms.openlocfilehash: 7ac57a65d575ba6a9134f3c4474103735411847d
ms.sourcegitcommit: a5fa9c6f4f0c239ac23be7de116066a978511de7
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/20/2019
ms.locfileid: "75299098"
---
# <a name="one-dimensional-arrays"></a>Matrizes unidimensionais

Uma expressão de pós-fixação seguida por uma expressão entre colchetes ( **[ ]** ) é uma representação assinada de um elemento de um objeto da matriz. Uma expressão subscrita representa o valor no endereço que está na posição *expression*, além de *postfix-expression* quando expresso como

```
postfix-expression [ expression ]
```

Geralmente, o valor representado por *postfix-expression* é um valor do ponteiro, como um identificador de matriz e *expression* é um valor integral. No entanto, tudo o que é necessário sintaticamente é que uma das expressões seja do tipo ponteiro e a outra seja do tipo integral. Assim, o valor integral pode estar na posição de *postfix-expression* e o valor do ponteiro pode estar entre colchetes na posição *expression* ou "subscrita". Por exemplo, esse código é válido:

```c
// one_dimensional_arrays.c
int sum, *ptr, a[10];
int main() {
   ptr = a;
   sum = 4[ptr];
}
```

As expressões subscritas geralmente são usadas para se referir a elementos da matriz, mas você pode aplicar um subscrito a qualquer ponteiro. Independentemente da ordem dos valores, *expression* deve estar entre colchetes ( **[ ]** ).

A expressão subscrita é avaliada mediante adição do valor integral ao valor do ponteiro, seguida por aplicação do operador de indireção (<strong>\*</strong>) ao resultado. (Consulte [indireção e operadores de endereço](../c-language/indirection-and-address-of-operators.md) para uma discussão sobre o operador de indireção.) Em vigor, para uma matriz unidimensional, as quatro expressões a seguir são equivalentes, supondo que `a` é um ponteiro e `b` é um inteiro:

```
a[b]
*(a + b)
*(b + a)
b[a]
```

De acordo com as regras de conversão para o operador de adição (determinadas em [Operadores aditivos](../c-language/c-additive-operators.md)), o valor integral é convertido em um deslocamento do endereço mediante a multiplicação dele pelo comprimento do tipo resolvido pelo ponteiro.

Por exemplo, suponha que o identificador `line` faça referência a uma matriz de valores `int`. O procedimento a seguir é usado para avaliar a expressão subscrita `line[ i ]`:

1. O valor inteiro `i` é multiplicado pelo número de bytes definidos como o comprimento de um item `int`. O valor convertido de `i` representa `i` posições de `int`.

1. Esse valor convertido é adicionado ao valor de ponteiro original (`line`) para produzir um endereço deslocado `i` `int` posições de `line`.

1. O operador de indireção é aplicado ao novo endereço. O resultado é o valor do elemento da matriz nessa posição (intuitivamente, `line [ i ]`).

A expressão subscrita `line[0]` representa o valor do primeiro elemento de linha, desde que o deslocamento de endereço representado por `line` seja 0. Similarmente, uma expressão como `line[5]` se refere ao deslocamento de cinco posições do elemento da linha, ou o sexto elemento da matriz.

## <a name="see-also"></a>Veja também

[Operador subscript:](../cpp/subscript-operator.md)
