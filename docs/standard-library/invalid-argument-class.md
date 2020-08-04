---
title: Classe invalid_argument
ms.date: 11/04/2016
f1_keywords:
- stdexcept/std::invalid_argument
helpviewer_keywords:
- invalid_argument class
ms.assetid: af6c227d-ad7c-4e63-9dee-67af81d83506
ms.openlocfilehash: 4fb15785cbff18daa1bfa9a1198a64d018383764
ms.sourcegitcommit: f2a135d69a2a8ef1777da60c53d58fe06980c997
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/03/2020
ms.locfileid: "87521194"
---
# <a name="invalid_argument-class"></a>Classe invalid_argument

A classe serve como a classe base para todas as exceções geradas para relatar um argumento inválido.

## <a name="syntax"></a>Sintaxe

```cpp
class invalid_argument : public logic_error {
public:
    explicit invalid_argument(const string& message);

    explicit invalid_argument(const char *message);

};
```

## <a name="remarks"></a>Comentários

O valor retornado por `what()` é uma cópia de `message.data()` . Para obter mais informações, consulte [`what`](../standard-library/exception-class.md) e [`data`](../standard-library/basic-string-class.md#data) .

## <a name="example"></a>Exemplo

```cpp
// invalid_arg.cpp
// compile with: /EHsc /GR
#include <bitset>
#include <iostream>

using namespace std;

int main( )
{
   try
   {
      bitset< 32 > bitset( string( "11001010101100001b100101010110000") );
   }
   catch ( exception &e )
   {
      cerr << "Caught " << e.what( ) << endl;
      cerr << "Type " << typeid( e ).name( ) << endl;
   };
}
/* Output:
Caught invalid bitset<N> char
Type class std::invalid_argument
*/
```

## <a name="requirements"></a>Requisitos

**Cabeçalho:**\<stdexcept>

**Namespace:** std

## <a name="see-also"></a>Consulte também

[Classe logic_error](../standard-library/logic-error-class.md)\
[Segurança de thread na biblioteca padrão C++](../standard-library/thread-safety-in-the-cpp-standard-library.md)
