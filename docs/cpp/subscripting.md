---
title: Subscrito
ms.date: 11/04/2016
helpviewer_keywords:
- subscript operator [C++], overloaded
- arrays [C++], subscripting
- subscripting [C++]
- operators [C++], overloading
- operator overloading [C++], examples
- subscript operator
ms.assetid: eb151281-6733-401d-9787-39ab6754c62c
ms.openlocfilehash: 2573f30b2dfee20d12afea2a1072bbdcef46228b
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87231072"
---
# <a name="subscripting"></a>Subscrito

O operador de subscrito (**[]**), como o operador de chamada de função, é considerado um operador binário. O operador subscrito deve ser uma função de membro não estático que usa um único argumento. Este argumento ou pode ser de qualquer tipo e designa o subscrito de matriz desejado.

## <a name="example"></a>Exemplo

O exemplo a seguir demonstra como criar um vetor do tipo **`int`** que implementa a verificação de limites:

```cpp
// subscripting.cpp
// compile with: /EHsc
#include <iostream>

using namespace std;
class IntVector {
public:
   IntVector( int cElements );
   ~IntVector() { delete [] _iElements; }
   int& operator[](int nSubscript);
private:
   int *_iElements;
   int _iUpperBound;
};

// Construct an IntVector.
IntVector::IntVector( int cElements ) {
   _iElements = new int[cElements];
   _iUpperBound = cElements;
}

// Subscript operator for IntVector.
int& IntVector::operator[](int nSubscript) {
   static int iErr = -1;

   if( nSubscript >= 0 && nSubscript < _iUpperBound )
      return _iElements[nSubscript];
   else {
      clog << "Array bounds violation." << endl;
      return iErr;
   }
}

// Test the IntVector class.
int main() {
   IntVector v( 10 );
   int i;

   for( i = 0; i <= 10; ++i )
      v[i] = i;

   v[3] = v[9];

   for ( i = 0; i <= 10; ++i )
      cout << "Element: [" << i << "] = " << v[i] << endl;
}
```

```Output
Array bounds violation.
Element: [0] = 0
Element: [1] = 1
Element: [2] = 2
Element: [3] = 9
Element: [4] = 4
Element: [5] = 5
Element: [6] = 6
Element: [7] = 7
Element: [8] = 8
Element: [9] = 9
Array bounds violation.
Element: [10] = 10
```

## <a name="comments"></a>Comentários

Quando `i` atinge 10 no programa anterior, **Operator []** detecta que um subscrito fora dos limites está sendo usado e emite uma mensagem de erro.

Observe que o **operador function []** retorna um tipo de referência. Isso a torna um l-value, permitindo usar as expressões subscritas em ambos os lados dos operadores de atribuição.

## <a name="see-also"></a>Confira também

[Sobrecarga de operador](../cpp/operator-overloading.md)
