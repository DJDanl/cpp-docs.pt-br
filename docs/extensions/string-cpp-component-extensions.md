---
title: Cadeia de caracteres (C++/CLI e C++/CX)
ms.date: 10/08/2018
ms.topic: reference
helpviewer_keywords:
- string support with /clr
- /clr compiler option [C++], string support
ms.assetid: c695f965-9be0-4e20-9661-373bfee6557e
ms.openlocfilehash: 8440ddf510f99618c28a6b6d585c8628df85f9cb
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "65516021"
---
# <a name="string--ccli-and-ccx"></a>Cadeia de caracteres (C++/CLI e C++/CX)

O Windows Runtime e o Common Language Runtime representam sequências de caracteres como objetos cuja memória alocada é gerenciada automaticamente. Ou seja, você não é obrigado a descartar explicitamente a memória de uma cadeia de caracteres quando a variável da cadeia de caracteres sai do escopo ou seu aplicativo termina. Para indicar que o tempo de vida de um objeto de cadeia de caracteres deve ser gerenciado automaticamente, declare o tipo de cadeia de caracteres com o modificador [handle-to-object (^)](handle-to-object-operator-hat-cpp-component-extensions.md).

## <a name="windows-runtime"></a>Tempo de Execução do Windows

A arquitetura Windows Runtime requer que o tipo de dados `String` esteja localizado no namespace `Platform`. Para sua conveniência, o Visual C++ também fornece o tipo de dados `string`, que é um sinônimo para `Platform::String`, no namespace `default`.

### <a name="syntax"></a>Sintaxe

```cpp
// compile with /ZW
using namespace Platform;
using namespace default;
   Platform::String^ MyString1 = "The quick brown fox";
   String^ MyString2 = "jumped over the lazy dog.";
   String^ MyString3 = "Hello, world!";
```

### <a name="requirements"></a>Requisitos

Opção do compilador: `/ZW`

## <a name="common-language-runtime"></a>Common Language Runtime

Quando compilar com `/clr`, o compilador converterá literais de cadeia de caracteres em cadeias de caracteres do tipo <xref:System.String>. Para preservar a compatibilidade com versões anteriores do código existente, há duas exceções:

- Tratamento de exceções. Quando um literal de cadeia de caracteres é lançado, o compilador o captura como um literal de cadeia de caracteres.

- Dedução de modelo. Quando um literal de cadeia de caracteres é passado como um argumento de modelo, o compilador não o converterá em um <xref:System.String>. Observe que os literais de cadeia de caracteres transmitidos como um argumento genérico serão promovidos para <xref:System.String>.

O compilador também possui suporte interno para três operadores, que você pode substituir para personalizar seu comportamento:

- System::String^ operator +( System::String, System::String);

- System::String^ operator +( System::Object, System::String);

- System::String^ operator +( System::String, System::Object);

Quando passado um <xref:System.String>, o compilador converterá, se necessário e, em seguida, concatenará o objeto (com ToString) com a cadeia de caracteres.

> [!NOTE]
> O cursor ("^") indica que a variável declarada é um identificador para um objeto gerenciado C++/CLI.

Saiba mais em [Literais de cadeia de caracteres e de caracteres](../cpp/string-and-character-literals-cpp.md).

### <a name="requirements"></a>Requisitos

Opção do compilador: **/clr**

### <a name="examples"></a>Exemplos

O exemplo de código a seguir demonstra a concatenação e comparação de cadeias de caracteres.

```cpp
// string_operators.cpp
// compile with: /clr
// In the following code, the caret ("^") indicates that the
// declared variable is a handle to a C++/CLI managed object.
using namespace System;

int main() {
   String^ a = gcnew String("abc");
   String^ b = "def";   // same as gcnew form
   Object^ c = gcnew String("ghi");

   char d[100] = "abc";

   // variables of System::String returning a System::String
   Console::WriteLine(a + b);
   Console::WriteLine(a + c);
   Console::WriteLine(c + a);

   // accessing a character in the string
   Console::WriteLine(a[2]);

   // concatenation of three System::Strings
   Console::WriteLine(a + b + c);

   // concatenation of a System::String and string literal
   Console::WriteLine(a + "zzz");

   // you can append to a System::String^
   Console::WriteLine(a + 1);
   Console::WriteLine(a + 'a');
   Console::WriteLine(a + 3.1);

   // test System::String^ for equality
   a += b;
   Console::WriteLine(a);
   a = b;
   if (a == b)
      Console::WriteLine("a and b are equal");

   a = "abc";
   if (a != b)
      Console::WriteLine("a and b are not equal");

   // System:String^ and tracking reference
   String^% rstr1 = a;
   Console::WriteLine(rstr1);

   // testing an empty System::String^
   String^ n;
   if (n == nullptr)
      Console::WriteLine("n is empty");
}
```

```Output
abcdef

abcghi

ghiabc

c

abcdefghi

abczzz

abc1

abc97

abc3.1

abcdef

a and b are equal

a and b are not equal

abc

n is empty
```

O exemplo a seguir mostra que você pode sobrecarregar os operadores fornecidos pelo compilador e que o compilador encontrará uma sobrecarga de função com base no tipo <xref:System.String>.

```cpp
// string_operators_2.cpp
// compile with: /clr
using namespace System;

// a string^ overload will be favored when calling with a String
void Test_Overload(const char * a) {
   Console::WriteLine("const char * a");
}
void Test_Overload(String^ a) {
   Console::WriteLine("String^ a");
}

// overload will be called instead of compiler defined operator
String^ operator +(String^ a, String^ b) {
   return ("overloaded +(String^ a, String^ b)");
}

// overload will be called instead of compiler defined operator
String^ operator +(Object^ a, String^ b) {
   return ("overloaded +(Object^ a, String^ b)");
}

// overload will be called instead of compiler defined operator
String^ operator +(String^ a, Object^ b) {
   return ("overloaded +(String^ a, Object^ b)");
}

int main() {
   String^ a = gcnew String("abc");
   String^ b = "def";   // same as gcnew form
   Object^ c = gcnew String("ghi");

   char d[100] = "abc";

   Console::WriteLine(a + b);
   Console::WriteLine(a + c);
   Console::WriteLine(c + a);

   Test_Overload("hello");
   Test_Overload(d);
}
```

```Output
overloaded +(String^ a, String^ b)

overloaded +(String^ a, Object^ b)

overloaded +(Object^ a, String^ b)

String^ a

const char * a
```

O exemplo a seguir mostra que o compilador distingue entre cadeias nativas e cadeias <xref:System.String>.

```cpp
// string_operators_3.cpp
// compile with: /clr
using namespace System;
int func() {
   throw "simple string";   // const char *
};

int func2() {
   throw "string" + "string";   // returns System::String
};

template<typename T>
void func3(T t) {
   Console::WriteLine(T::typeid);
}

int main() {
   try {
      func();
   }
   catch(char * e) {
      Console::WriteLine("char *");
   }

   try {
      func2();
   }
   catch(String^ str) {
      Console::WriteLine("String^ str");
   }

   func3("string");   // const char *
   func3("string" + "string");   // returns System::String
}
```

```Output
char *

String^ str

System.SByte*

System.String
```

## <a name="see-also"></a>Consulte também

[Extensões de componentes para .NET e UWP](component-extensions-for-runtime-platforms.md)<br/>
[Literais de cadeia de caracteres e de caracteres](../cpp/string-and-character-literals-cpp.md)<br/>
[/clr (compilação do Common Language Runtime)](../build/reference/clr-common-language-runtime-compilation.md)