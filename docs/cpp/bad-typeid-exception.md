---
title: Exceção bad_typeid
ms.date: 11/04/2016
f1_keywords:
- bad_typeid
- bad_typeid_cpp
helpviewer_keywords:
- bad_typeid exception
- exceptions [C++], bad_typeid
ms.assetid: 5963ed58-4ede-4597-957d-f7bbd06299c2
ms.openlocfilehash: 2ff7339b02cfe8c21cebfa7d9bb0cc98b3e08799
ms.sourcegitcommit: 3590dc146525807500c0477d6c9c17a4a8a2d658
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/16/2019
ms.locfileid: "68242271"
---
# <a name="badtypeid-exception"></a>Exceção bad_typeid

O **bad_typeid** exceção é lançada pela [operador typeid](../cpp/typeid-operator.md) quando o operando **typeid** é um ponteiro nulo.

## <a name="syntax"></a>Sintaxe

```
catch (bad_typeid)
   statement
```

## <a name="remarks"></a>Comentários

A interface para **bad_typeid** é:

```cpp
class bad_typeid : public exception
{
public:
   bad_typeid();
   bad_typeid(const char * _Message = "bad typeid");
   bad_typeid(const bad_typeid &);
   virtual ~bad_typeid();

   bad_typeid& operator=(const bad_typeid&);
   const char* what() const;
};
```

A exemplo a seguir mostra a **typeid** operador lançando uma **bad_typeid** exceção.

```cpp
// expre_bad_typeid.cpp
// compile with: /EHsc /GR
#include <typeinfo.h>
#include <iostream>

class A{
public:
   // object for class needs vtable
   // for RTTI
   virtual ~A();
};

using namespace std;
int main() {
A* a = NULL;

try {
   cout << typeid(*a).name() << endl;  // Error condition
   }
catch (bad_typeid){
   cout << "Object is NULL" << endl;
   }
}
```

## <a name="output"></a>Saída

```Output
Object is NULL
```

## <a name="see-also"></a>Consulte também

[Informações de tipo em tempo de execução](../cpp/run-time-type-information.md)<br/>
[Palavras-chave](../cpp/keywords-cpp.md)