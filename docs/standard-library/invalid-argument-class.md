---
title: Classe invalid_argument
ms.date: 11/04/2016
f1_keywords:
- stdexcept/std::invalid_argument
helpviewer_keywords:
- invalid_argument class
ms.assetid: af6c227d-ad7c-4e63-9dee-67af81d83506
ms.openlocfilehash: e6b56e98a1adc7426fe0d1b65d623549a4391c8d
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62404841"
---
# <a name="invalidargument-class"></a>Classe invalid_argument

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

O valor retornado por [what](../standard-library/exception-class.md) é uma cópia de **message**`.`[data](../standard-library/basic-string-class.md#data).

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

**Cabeçalho:** \<stdexcept>

**Namespace:** std

## <a name="see-also"></a>Consulte também

[Classe logic_error](../standard-library/logic-error-class.md)<br/>
[Acesso Thread-Safe na Biblioteca Padrão C++](../standard-library/thread-safety-in-the-cpp-standard-library.md)<br/>
