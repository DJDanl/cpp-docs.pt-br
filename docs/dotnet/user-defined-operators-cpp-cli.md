---
title: Operadores definidos pelo usuário (C++/CLI)
ms.date: 11/04/2016
helpviewer_keywords:
- user-defined operators under /clr
ms.assetid: 42f93b4a-6de4-4e34-b07b-5a62ac014f2c
ms.openlocfilehash: ee5aa122983a315e55884c643a9b7894f075e260
ms.sourcegitcommit: 43cee7a0d41a062661229043c2f7cbc6ace17fa3
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/13/2020
ms.locfileid: "92008956"
---
# <a name="user-defined-operators-ccli"></a>Operadores definidos pelo usuário (C++/CLI)

Os operadores definidos pelo usuário para tipos gerenciados são permitidos como membros estáticos ou membros de instância, ou em escopo global. No entanto, somente os operadores estáticos podem ser acessados por meio de metadados para clientes que são gravados em uma linguagem diferente de Visual C++.

Em um tipo de referência, um dos parâmetros de um operador estático definido pelo usuário deve ser um destes:

- Um identificador ( `type` ^) para uma instância do tipo delimitador.

- Um indireção de tipo de referência ( `type` ^& ou tipo ^%) para um identificador para uma instância do tipo delimitador.

Em um tipo de valor, um dos parâmetros de um operador estático definido pelo usuário deve ser um destes:

- Do mesmo tipo que o tipo de valor de circunscrição.

- Um indireção de tipo de ponteiro ( `type` ^) para o tipo delimitador.

- Um indireção de tipo de referência ( `type` % ou `type`&) para o tipo delimitador.

- Um indireção de tipo de referência ( `type` ^% ou `type` ^&) para o identificador.

Você pode definir os seguintes operadores:

|Operador|Formulários unários/binários?|
|--------------|--------------------------|
|!|Unário|
|!=|Binário|
|%|Binário|
|&|Unário e binário|
|&&|Binário|
|*|Unário e binário|
|+|Unário e binário|
|++|Unário|
|,|Binário|
|-|Unário e binário|
|--|Unário|
|->|Unário|
|/|Binário|
|<|Binário|
|<<|Binário|
|\<=|Binário|
|=|Binário|
|==|Binário|
|>|Binário|
|>=|Binário|
|>>|Binário|
|^|Binário|
|false|Unário|
|true|Unário|
|&#124;|Binário|
|&#124;&#124;|Binário|
|~|Unário|

## <a name="example-user-defined-operators"></a>Exemplo: operadores definidos pelo usuário

```cpp
// mcppv2_user-defined_operators.cpp
// compile with: /clr
using namespace System;
public ref struct X {
   X(int i) : m_i(i) {}
   X() {}

   int m_i;

   // static, binary, user-defined operator
   static X ^ operator + (X^ me, int i) {
      return (gcnew X(me -> m_i + i));
   }

   // instance, binary, user-defined operator
   X^ operator -( int i ) {
      return gcnew X(this->m_i - i);
   }

   // instance, unary, user-defined pre-increment operator
   X^ operator ++() {
      return gcnew X(this->m_i++);
   }

   // instance, unary, user-defined post-increment operator
   X^ operator ++(int i) {
      return gcnew X(this->m_i++);
   }

   // static, unary user-defined pre- and post-increment operator
   static X^ operator-- (X^ me) {
      return (gcnew X(me -> m_i - 1));
   }
};

int main() {
   X ^hX = gcnew X(-5);
   System::Console::WriteLine(hX -> m_i);

   hX = hX + 1;
   System::Console::WriteLine(hX -> m_i);

   hX = hX - (-1);
   System::Console::WriteLine(hX -> m_i);

   ++hX;
   System::Console::WriteLine(hX -> m_i);

   hX++;
   System::Console::WriteLine(hX -> m_i);

   hX--;
   System::Console::WriteLine(hX -> m_i);

   --hX;
   System::Console::WriteLine(hX -> m_i);
}
```

```Output
-5
-4
-3
-2
-1
-2
-3
```

## <a name="example-operator-synthesis"></a>Exemplo: síntese de operador

O exemplo a seguir demonstra a síntese do operador, que está disponível somente quando você usa **/CLR** para compilar. A síntese do operador cria o formulário de atribuição de um operador binário, se um não estiver definido, onde o lado esquerdo do operador de atribuição tiver um tipo CLR.

```cpp
// mcppv2_user-defined_operators_2.cpp
// compile with: /clr
ref struct A {
   A(int n) : m_n(n) {};
   static A^ operator + (A^ r1, A^ r2) {
      return gcnew A( r1->m_n + r2->m_n);
   };
   int m_n;
};

int main() {
   A^ a1 = gcnew A(10);
   A^ a2 = gcnew A(20);

   a1 += a2;   // a1 = a1 + a2   += not defined in source
   System::Console::WriteLine(a1->m_n);
}
```

```Output
30
```

## <a name="see-also"></a>Veja também

[Classes e structs](../extensions/classes-and-structs-cpp-component-extensions.md)
