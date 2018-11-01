---
title: Operadores de acesso de membro:. e -&gt;
ms.date: 11/04/2016
f1_keywords:
- .
- ->
helpviewer_keywords:
- member access, expressions
- operators [C++], member access
- dot operator (.)
- -> operator
- member access, operators
- postfix operators [C++]
- . operator
- member access
ms.assetid: f8fc3df9-d728-40c5-b384-276927f5f1b3
ms.openlocfilehash: 0f370aa04af2e78efd5edfb7836fb71a4c4516a7
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50468738"
---
# <a name="member-access-operators--and--gt"></a>Operadores de acesso de membro:. e -&gt;

## <a name="syntax"></a>Sintaxe

```
postfix-expression . name
postfix-expression -> name
```

## <a name="remarks"></a>Comentários

Os operadores de acesso de membro **.** e **->** são usados para fazer referência a membros de estruturas, uniões e classes. As expressões de acesso do membro têm o valor e o tipo do membro selecionado.

Há duas formas de expressões de acesso do membro:

1. No primeiro formato, *postfix-expression* representa um valor de struct, classe ou tipo de união, e *nome* nomeia um membro da estrutura especificada, união ou classe. O valor da operação é de *nome* e é um l-value se *postfix-expression* é um l-value.

1. Na segunda forma *postfix-expression* representa um ponteiro para uma estrutura, união ou classe, e *nome* nomeia um membro da estrutura especificada, união ou classe. O valor é de *nome* e é um l-value. O **->** operador desreferencia o ponteiro. Portanto, as expressões `e->member` e `(*e).member` (onde *eletrônico* representa um ponteiro) geram resultados idênticos (exceto quando os operadores **->** ou <strong>\*</strong> são sobrecarregados).

## <a name="example"></a>Exemplo

O exemplo a seguir demonstra as duas formas de operador de acesso do membro.

```cpp
// expre_Selection_Operator.cpp
// compile with: /EHsc
#include <iostream>
using namespace std;

struct Date {
   Date(int i, int j, int k) : day(i), month(j), year(k){}
   int month;
   int day;
   int year;
};

int main() {
   Date mydate(1,1,1900);
   mydate.month = 2;
   cout  << mydate.month << "/" << mydate.day
         << "/" << mydate.year << endl;

   Date *mydate2 = new Date(1,1,2000);
   mydate2->month = 2;
   cout  << mydate2->month << "/" << mydate2->day
         << "/" << mydate2->year << endl;
   delete mydate2;
}
```

```Output
2/1/1900
2/1/2000
```

## <a name="see-also"></a>Consulte também

[Expressões pós-fixadas](../cpp/postfix-expressions.md)<br/>
[Operadores internos, precedência e associatividade C++](../cpp/cpp-built-in-operators-precedence-and-associativity.md)<br/>
[Classes e Structs](../cpp/classes-and-structs-cpp.md)<br/>
[Membros de união e estrutura](../c-language/structure-and-union-members.md)