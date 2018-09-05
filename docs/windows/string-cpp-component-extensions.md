---
title: Cadeia de caracteres (extensões de componentes C++) | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: reference
dev_langs:
- C++
helpviewer_keywords:
- string support with /clr
- /clr compiler option [C++], string support
ms.assetid: c695f965-9be0-4e20-9661-373bfee6557e
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 5e37a3a934fbc66af62a30fd2fc2c23e1c659ef2
ms.sourcegitcommit: a7046aac86f1c83faba1088c80698474e25fe7c3
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/04/2018
ms.locfileid: "43692092"
---
# <a name="string--c-component-extensions"></a>Cadeia de caracteres (Extensões de Componentes C++)

O compilador de Visual C++ oferece suporte ao *cadeias de caracteres*, que são objetos que representam o texto como uma sequência de caracteres. Visual C++ oferece suporte a variáveis de cadeia de caracteres, cujo valor é implícito, e literais, cujo valor é uma cadeia de caracteres entre aspas explícita.

## <a name="all-runtimes"></a>Todos os Tempos de Execução

O tempo de execução do Windows e o common language runtime representam cadeias de caracteres como objetos cuja memória alocada é gerenciada automaticamente. Ou seja, você não deve descartar explicitamente a memória para uma cadeia de caracteres quando termina o sai de variável de cadeia de caracteres do escopo ou seu aplicativo. Para indicar que o tempo de vida de um objeto de cadeia de caracteres deve ser gerenciado automaticamente, declare o tipo de cadeia de caracteres com o [handle-to-object (^)](../windows/handle-to-object-operator-hat-cpp-component-extensions.md) modificador.

## <a name="windows-runtime"></a>Tempo de Execução do Windows

A arquitetura de tempo de execução do Windows requer o Visual C++ implementar o `String` tipo de dados no `Platform` namespace. Para sua conveniência, o Visual C++ também fornece o `string` tipo de dados, que é um sinônimo de `Platform::String`, no `default` namespace.

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

Este tópico discute como o compilador do Visual C++ processa os literais de cadeia de caracteres quando você executá-lo usando o `/clr` opção de compilador. Para usar `/clr`, você também deve usar o runtime de linguagem comum (CLR), C + + c++ /CLI sintaxe da CLI e objetos gerenciados. Para obter mais informações sobre `/clr`, consulte [/clr (compilação de tempo de execução de linguagem comum)](../build/reference/clr-common-language-runtime-compilation.md).

Ao compilar com `/clr`, o compilador irá converter literais de cadeia de caracteres para cadeias de caracteres do tipo <xref:System.String>. Para preservar a compatibilidade com versões anteriores com o código existente há são duas exceções a isso:

- Manipulação de exceção. Quando um literal de cadeia de caracteres é gerada, o compilador irá capturá-la como um literal de cadeia de caracteres.

- Dedução de modelo. Quando um literal de cadeia de caracteres é passada como um argumento de modelo, o compilador não irá convertê-lo para um <xref:System.String>. Observe que os literais de cadeia de caracteres passados como um argumento genérico serão promovidos a <xref:System.String>.

O compilador também tem suporte interno para três operadores, que você pode substituir para personalizar seu comportamento:

- System:: string ^ operador + (System:: String, System:: String);

- System:: string ^ operador + (System:: Object, System:: String);

- System:: string ^ operador + (System:: String, System:: Object);

Quando passado um <xref:System.String>, o compilador caixa, se necessário e, em seguida, concatenar o objeto (com ToString) com a cadeia de caracteres.

> [!NOTE]
> O sinal de interpolação ("^") indica que a variável declarada é um identificador para um C + + c++ /CLI do objeto gerenciado de CLI.

Para obter mais informações, consulte [cadeia de caracteres e literais de caracteres](../cpp/string-and-character-literals-cpp.md).

### <a name="requirements"></a>Requisitos

Opção de compilador: **/clr**

### <a name="examples"></a>Exemplos

O exemplo de código a seguir demonstra a concatenação e comparando cadeias de caracteres.

```cpp
// string_operators.cpp
// compile with: /clr
// In the following code, the caret ("^") indicates that the
// declared variable is a handle to a C++/CLI managed object.
using namespace System;

int main() {
   String ^ a = gcnew String("abc");
   String ^ b = "def";   // same as gcnew form
   Object ^ c = gcnew String("ghi");

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

   // you can append to a System::String ^
   Console::WriteLine(a + 1);
   Console::WriteLine(a + 'a');
   Console::WriteLine(a + 3.1);

   // test System::String ^ for equality
   a += b;
   Console::WriteLine(a);
   a = b;
   if (a == b)  
      Console::WriteLine("a and b are equal");

   a = "abc";
   if (a != b)  
      Console::WriteLine("a and b are not equal");

   // System:String ^ and tracking reference
   String^% rstr1 = a;
   Console::WriteLine(rstr1);

   // testing an empty System::String ^
   String ^ n;
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

O exemplo a seguir mostra que você pode sobrecarregar os operadores fornecidos pelo compilador e que o compilador encontrará uma sobrecarga de função com base no <xref:System.String> tipo.

```cpp
// string_operators_2.cpp
// compile with: /clr
using namespace System;

// a string^ overload will be favored when calling with a String
void Test_Overload(const char * a) {
   Console::WriteLine("const char * a");
}
void Test_Overload(String ^ a) {
   Console::WriteLine("String ^ a");
}

// overload will be called instead of compiler defined operator
String ^ operator +(String ^ a, String ^ b) {
   return ("overloaded +(String ^ a, String ^ b)");
}

// overload will be called instead of compiler defined operator
String ^ operator +(Object ^ a, String ^ b) {
   return ("overloaded +(Object ^ a, String ^ b)");
}

// overload will be called instead of compiler defined operator
String ^ operator +(String ^ a, Object ^ b) {
   return ("overloaded +(String ^ a, Object ^ b)");
}

int main() {
   String ^ a = gcnew String("abc");
   String ^ b = "def";   // same as gcnew form
   Object ^ c = gcnew String("ghi");

   char d[100] = "abc";

   Console::WriteLine(a + b);
   Console::WriteLine(a + c);
   Console::WriteLine(c + a);

   Test_Overload("hello");
   Test_Overload(d);
}
```

```Output
overloaded +(String ^ a, String ^ b)

overloaded +(String ^ a, Object ^ b)

overloaded +(Object ^ a, String ^ b)

String ^ a

const char * a
```

O exemplo a seguir mostra que o compilador faz a distinção entre cadeias de caracteres nativas e <xref:System.String> cadeias de caracteres.

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

[Extensões de componentes para plataformas de tempo de execução](../windows/component-extensions-for-runtime-platforms.md)  
[Literais de cadeia de caracteres e de caracteres](../cpp/string-and-character-literals-cpp.md)  
[/clr (compilação do Common Language Runtime)](../build/reference/clr-common-language-runtime-compilation.md)