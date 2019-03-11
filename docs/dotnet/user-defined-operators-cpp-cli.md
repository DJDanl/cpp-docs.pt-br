---
title: Operadores definidos pelo usuário (C++/CLI)
ms.date: 11/04/2016
helpviewer_keywords:
- user-defined operators under /clr
ms.assetid: 42f93b4a-6de4-4e34-b07b-5a62ac014f2c
ms.openlocfilehash: 462d0d2819d4c65b0e37d39f24566a7152a44cf3
ms.sourcegitcommit: dedd4c3cb28adec3793329018b9163ffddf890a4
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/11/2019
ms.locfileid: "57739989"
---
# <a name="user-defined-operators-ccli"></a>Operadores definidos pelo usuário (C++/CLI)

Operadores definidos pelo usuário para tipos gerenciados são permitidos como membros estáticos ou membros de instância ou no escopo global. No entanto, somente os operadores estáticos são acessíveis por meio de metadados para os clientes que são escritos em um idioma diferente do Visual C++.

Em um tipo de referência, um dos parâmetros de um operador estático definido pelo usuário deve ser um destes procedimentos:

- Um identificador (`type` ^) a uma instância do tipo delimitador.

- Uma indireção de tipo de referência (`type`^ & ou tipo ^ %) para um identificador para uma instância do tipo delimitador.

Em um tipo de valor, um dos parâmetros de um operador estático definido pelo usuário deve ser um destes procedimentos:

- Do mesmo tipo como o tipo de valor de delimitador.

- Uma indireção de tipo de ponteiro (`type`^) para o tipo delimitador.

- Uma indireção de tipo de referência (`type`% ou `type`&) para o tipo delimitador.

- Uma indireção de tipo de referência (`type`^ % ou `type`^ &) para o identificador.

Você pode definir os seguintes operadores:

|Operador|Formulários de global unário/binário?|
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

## <a name="example"></a>Exemplo

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

## <a name="example"></a>Exemplo

O exemplo a seguir demonstra a síntese de operador, que está disponível apenas quando você usa **/clr** para compilar. Síntese de operador cria o formulário de atribuição de um operador binário, se um não estiver definido, em que o lado esquerdo do operador de atribuição tem um tipo CLR.

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

## <a name="see-also"></a>Consulte também

[Classes e Structs](../windows/classes-and-structs-cpp-component-extensions.md)
