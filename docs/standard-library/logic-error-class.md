---
title: Classe logic_error
ms.date: 11/04/2016
f1_keywords:
- stdexcept/std::logic_error
helpviewer_keywords:
- logic_error class
ms.assetid: b290d73d-94e1-4288-af86-2bb5d71f677a
ms.openlocfilehash: b94f7f4c2482f0317e37c6f4bf3618b91a175147
ms.sourcegitcommit: f2a135d69a2a8ef1777da60c53d58fe06980c997
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/03/2020
ms.locfileid: "87521181"
---
# <a name="logic_error-class"></a>Classe logic_error

A classe serve como classe base para todas as exceções geradas para relatar erros supostamente detectáveis antes da execução do programa, como violações de pré-condições lógicas.

## <a name="syntax"></a>Sintaxe

```cpp
class logic_error : public exception {
public:
    explicit logic_error(const string& message);

    explicit logic_error(const char *message);

};
```

## <a name="remarks"></a>Comentários

O valor retornado por `what()` é uma cópia de `message.data()` . Para obter mais informações, consulte [`what`](../standard-library/exception-class.md) e [`data`](../standard-library/basic-string-class.md#data) .

## <a name="example"></a>Exemplo

```cpp
// logic_error.cpp
// compile with: /EHsc /GR
#include <iostream>
using namespace std;

int main( )
{
   try
   {
      throw logic_error( "logic error" );
   }
   catch ( exception &e )
   {
      cerr << "Caught: " << e.what( ) << endl;
      cerr << "Type: " << typeid( e ).name( ) << endl;
   };
}
```

```Output
Caught: logic error
Type: class std::logic_error
```

## <a name="requirements"></a>Requisitos

**Cabeçalho:**\<stdexcept>

**Namespace:** std

## <a name="see-also"></a>Consulte também

[Classe de exceção](../standard-library/exception-class.md)\
[Segurança de thread na biblioteca padrão C++](../standard-library/thread-safety-in-the-cpp-standard-library.md)
