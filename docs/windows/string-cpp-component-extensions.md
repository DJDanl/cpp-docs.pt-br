---
title: "String  (C++ Component Extensions) | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "language-reference"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "string support with /clr"
  - "/clr compiler option [C++], string support"
ms.assetid: c695f965-9be0-4e20-9661-373bfee6557e
caps.latest.revision: 19
caps.handback.revision: 17
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# String  (C++ Component Extensions)
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

O compilador do Visual C\+\+ oferece suporte às *cadeias de caracteres*, que são objetos que representam o texto como uma sequência de caracteres.  Visual C\+\+ do oferece suporte a variáveis de cadeia de caracteres, cujo valor está implícito, e literais, cujo valor é uma cadeia de caracteres entre aspas explícita.  
  
## Todos os Tempos de Execução  
 Tempo de Execução do Windows e Common Language Runtime representam cadeias de caracteres como os objetos cujos atribuídas a memória são gerenciadas automaticamente.  Isto é, não é necessário descartar explicitamente a memória para uma cadeia de caracteres quando a variável de cadeia de caracteres ou sai do escopo das extremidades do aplicativo.  Para indicar que o tempo de vida de um objeto de cadeia de caracteres deve ser gerenciado automaticamente, declare o tipo de cadeia de caracteres com o modificador de [alça\-à\-objeto \(^\)](../windows/handle-to-object-operator-hat-cpp-component-extensions.md) .  
  
## Tempo de execução do windows  
 A arquitetura de Tempo de Execução do Windows requer o Visual C\+\+ implementar o tipo de dados de `String` no namespace de `Platform` .  Para sua conveniência, Visual C\+\+ também fornece o tipo de dados de `string` , que é um sinônimo para `Platform::String`, no namespace de `default` .  
  
### Sintaxe  
  
```cpp  
  
// compile with /ZW  
using namespace Platform;  
using namespace default;  
   Platform::String^ MyString1 = "The quick brown fox";  
   String^ MyString2 = "jumped over the lazy dog.";  
   String^ MyString3 = "Hello, world!";  
  
```  
  
### Comentários  
 Para obter mais informações e exemplos sobre cadeias de caracteres, consulte [Platform::String, std::wstring, and Literals \(Platform\)](http://msdn.microsoft.com/pt-br/ec92fbc6-edf3-4137-a85e-8e29bdb857a8)  
  
### Requisitos  
 Opção do compilador: **\/ZW**  
  
## Common Language Runtime  
 Este tópico discute como o compilador do Visual C\+\+ processa literais quando você o executa com a opção do compilador de **\/clr** .  Para usar **\/clr**, você também deve usar Common Language Runtime \(CLR\), a sintaxe de C\+\+\/CLI e objetos gerenciados.  Para obter mais informações sobre **\/clr**, consulte [\/clr \(compilação do Common Language Runtime\)](../build/reference/clr-common-language-runtime-compilation.md).  
  
 Ao criar com **\/clr**, o compilador converterá a cadeia de caracteres em cadeias de caracteres de tipo <xref:System.String>.  Para preservar a compatibilidade com versões anteriores com código existente há duas exceções a este:  
  
-   Manipulação de exceção.  Quando uma literal de cadeia de caracteres é gerada, o compilador capturar\-a\-&z como uma cadeia de caracteres literal.  
  
-   Dedução do modelo.  Quando uma literal de cadeia de caracteres é passado como um argumento de modelo, o compilador não o converterá a <xref:System.String>.  Observação, literais passadas como um argumento genérico será promovida a <xref:System.String>.  
  
 O compilador também tem suporte interno para três operadores, que você pode substituir para personalizar o comportamento:  
  
-   Operador ^ de System::String \+ \(System::String, System::String\);  
  
-   Operador ^ de System::String \+ \(System::Object, System::String\);  
  
-   Operador ^ de System::String \+ \(System::String, System::Object\);  
  
 Quando é passada <xref:System.String>, o compilador encaixotará se necessário, e concatena o objeto com ToString \(\) com a cadeia de caracteres.  
  
 Ao criar com **\/clr:oldSyntax**, os literais de cadeia de caracteres não serão convertidas a <xref:System.String>.  
  
> [!NOTE]
>  O sinal de intercalação \(“^ "\) indica que a variável é declarada um identificador para o objeto gerenciado \+\+\/CLI c.  
  
 Para obter mais informações, consulte [Literais de cadeia de caracteres e de caracteres](../cpp/string-and-character-literals-cpp.md).  
  
### Requisitos  
 Opção do compilador: **\/clr**  
  
### Exemplos  
 **Exemplo**  
  
 O exemplo de código a seguir demonstra concatenar e comparar cadeias de caracteres.  
  
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
  
 **Saída**  
  
  **abcdef**  
 **abcghi**  
 **ghiabc**  
 **c**  
 **abcdefghi**  
 **abczzz**  
 **abc1**  
 **abc97**  
 **abc3.1**  
 **abcdef**  
 **a e b são iguais**  
 **a e b não são iguais**  
 **ABC**  
 **em está vazia** **Exemplo**  
  
 O exemplo a seguir mostra que você pode sobrecarregar completo fornecido, e operadores que o compilador localizará uma sobrecarga da função com base no tipo de <xref:System.String> .  
  
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
  
 **Saída**  
  
  **sobrecarregado \+ \(^ da cadeia de caracteres, ^ de cadeia de caracteres b\)**   
 **sobrecarregado \+ \(^ da cadeia de caracteres, ^ do objeto b\)**   
 **sobrecarregado \+ \(^ ao objeto, ^ de cadeia de caracteres b\)**   
 **^ Da cadeia de caracteres**  
 **char da const \*** **Exemplo**  
  
 O exemplo a seguir mostra que o compilador faz distinção entre cadeias de caracteres nativas e cadeias de caracteres de <xref:System.String> .  
  
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
  
 **Saída**  
  
  **char \***  
 **Str de String^**  
 **System.SByte\***  
 **System.String**   
## Consulte também  
 [Component Extensions for Runtime Platforms](../windows/component-extensions-for-runtime-platforms.md)   
 [Literais de cadeia de caracteres e de caracteres](../cpp/string-and-character-literals-cpp.md)   
 [\/clr \(compilação do Common Language Runtime\)](../build/reference/clr-common-language-runtime-compilation.md)