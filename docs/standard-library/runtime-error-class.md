---
title: Classe runtime_error
ms.date: 11/04/2016
f1_keywords:
- stdexcept/std::runtime_error
helpviewer_keywords:
- runtime_error class
ms.assetid: 4d0227bf-847b-45a2-a320-2351ebf98368
ms.openlocfilehash: a860e10994934ae0e97950fddb14e573f8752833
ms.sourcegitcommit: f2a135d69a2a8ef1777da60c53d58fe06980c997
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/03/2020
ms.locfileid: "87520895"
---
# <a name="runtime_error-class"></a>Classe runtime_error

A classe serve como classe base para todas as exceções geradas para relatar erros supostamente detectáveis somente durante a execução do programa.

## <a name="syntax"></a>Sintaxe

```cpp
class runtime_error : public exception {
public:
    explicit runtime_error(const string& message);

    explicit runtime_error(const char *message);

};
```

## <a name="remarks"></a>Comentários

O valor retornado por `what()` é uma cópia de `message.data()` . Para obter mais informações, consulte [`what`](../standard-library/exception-class.md) e [`data`](../standard-library/basic-string-class.md#data) .

## <a name="example"></a>Exemplo

```cpp
// runtime_error.cpp
// compile with: /EHsc /GR
#include <iostream>

using namespace std;

int main( )
{
// runtime_error
   try
   {
      locale loc( "test" );
   }
   catch ( exception &e )
   {
      cerr << "Caught " << e.what( ) << endl;
      cerr << "Type " << typeid( e ).name( ) << endl;
   };
}
/* Output:
Caught bad locale name
Type class std::runtime_error
*/
```

## <a name="requirements"></a>Requisitos

**Cabeçalho:**\<stdexcept>

**Namespace:** std

## <a name="see-also"></a>Consulte também

[Classe de exceção](../standard-library/exception-class.md)\
[Segurança de thread na biblioteca padrão C++](../standard-library/thread-safety-in-the-cpp-standard-library.md)
