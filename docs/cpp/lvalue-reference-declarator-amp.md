---
title: 'Declarador de referência lvalue: &amp; | Microsoft Docs'
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-language
ms.topic: language-reference
f1_keywords:
- '&'
dev_langs:
- C++
helpviewer_keywords:
- reference operator
- '& operator [C++], reference operator'
ms.assetid: edf0513d-3dcc-4663-b276-1269795dda51
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 28e5d247c866247b42da8937894fed878985be44
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46090070"
---
# <a name="lvalue-reference-declarator-amp"></a>Declarador de referência lvalue: &amp;

Contém o endereço de um objeto mas se comporta sintaticamente como um objeto.

## <a name="syntax"></a>Sintaxe

```
type-id & cast-expression
```

## <a name="remarks"></a>Comentários

Você pode pensar em uma referência de lvalue como outro nome para um objeto. Uma declaração de referência de lvalue consiste de uma lista opcional de especificadores seguidos por um declarador de referência. Uma referência deve ser inicializada e não pode ser alterada.

Qualquer objeto cujo endereço possa ser convertido em um determinado tipo de ponteiro também pode ser convertido no tipo semelhante de referência. Por exemplo, qualquer objeto cujo endereço possa ser convertido para o tipo `char *` também pode ser convertido para o tipo `char &`.

Não confunda declarações de referência com o uso do [operador address-of](../cpp/address-of-operator-amp.md). Quando o `&` *identificador* é precedido por um tipo, como **int** ou **char**, *identificador* é declarado como uma referência a o tipo. Quando `&` *identificador* não é precedido por um tipo, é o uso do operador address-of.

## <a name="example"></a>Exemplo

O exemplo a seguir demonstra o declarador de referência declarando um objeto `Person` e uma referência a esse objeto. Como `rFriend` é uma referência a `myFriend`, atualizar qualquer variável altera o mesmo objeto.

```cpp
// reference_declarator.cpp
// compile with: /EHsc
// Demonstrates the reference declarator.
#include <iostream>
using namespace std;

struct Person
{
    char* Name;
    short Age;
};

int main()
{
   // Declare a Person object.
   Person myFriend;

   // Declare a reference to the Person object.
   Person& rFriend = myFriend;

   // Set the fields of the Person object.
   // Updating either variable changes the same object.
   myFriend.Name = "Bill";
   rFriend.Age = 40;

   // Print the fields of the Person object to the console.
   cout << rFriend.Name << " is " << myFriend.Age << endl;
}
```

```Output
Bill is 40
```

## <a name="see-also"></a>Consulte também

[Referências](../cpp/references-cpp.md)<br/>
[Argumentos de função de tipo de referência](../cpp/reference-type-function-arguments.md)<br/>
[Retornos de função de tipo de referência](../cpp/reference-type-function-returns.md)<br/>
[Referências a ponteiros](../cpp/references-to-pointers.md)