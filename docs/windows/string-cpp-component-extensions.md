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
ms.openlocfilehash: cfab95c400aad949f06a559fffbdb42993910bb7
ms.sourcegitcommit: d55ac596ba8f908f5d91d228dc070dad31cb8360
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/08/2018
ms.locfileid: "33889216"
---
# <a name="string--c-component-extensions"></a>Cadeia de caracteres (Extensões de Componentes C++)
O suporte de compilador do Visual C++ *cadeias de caracteres*, que são objetos que representam o texto como uma cadeia de caracteres. Visual C++ dá suporte a variáveis de cadeia de caracteres, cujo valor é implícita, e literais, cujo valor é uma cadeia de caracteres entre aspas explícita.  
  
## <a name="all-runtimes"></a>Todos os Tempos de Execução  
 O tempo de execução do Windows e o common language runtime representam cadeias de caracteres como objetos cuja memória alocada é gerenciada automaticamente. Ou seja, não é necessário descartar explicitamente a memória para uma cadeia de caracteres quando termina o vai de variável de cadeia de caracteres fora do escopo ou seu aplicativo. Para indicar que o tempo de vida de um objeto de cadeia de caracteres a serem gerenciados automaticamente, declare o tipo de cadeia de caracteres com o [handle-to-object (^)](../windows/handle-to-object-operator-hat-cpp-component-extensions.md) modificador.  
  
## <a name="windows-runtime"></a>Tempo de Execução do Windows  
 A arquitetura de tempo de execução do Windows requer o Visual C++ implementar o `String` no tipo de dados a `Platform` namespace. Para sua conveniência, Visual C++ também fornece o `string` tipo de dados, que é um sinônimo para `Platform::String`, no `default` namespace.  
  
### <a name="syntax"></a>Sintaxe  
  
```cpp  
// compile with /ZW  
using namespace Platform;  
using namespace default;  
   Platform::String^ MyString1 = "The quick brown fox";  
   String^ MyString2 = "jumped over the lazy dog.";  
   String^ MyString3 = "Hello, world!";  
  
```  
  
### <a name="remarks"></a>Comentários  
 Para obter mais informações e exemplos sobre cadeias de caracteres, consulte [Platform:: String, std:: wstring e literais (plataforma)](http://msdn.microsoft.com/en-us/ec92fbc6-edf3-4137-a85e-8e29bdb857a8)  
  
### <a name="requirements"></a>Requisitos  
 Opção do compilador: **/ZW**  
  
## <a name="common-language-runtime"></a>Common Language Runtime  
 Este tópico discute como o compilador do Visual C++ processa literais de cadeia de caracteres quando você executá-lo usando o **/clr** opção de compilador. Para usar **/clr**, você também deve usar o common language runtime (CLR), C + + sintaxe CLI e objetos gerenciados. Para obter mais informações sobre **/clr**, consulte [/clr (Common Language Runtime Compilation)](../build/reference/clr-common-language-runtime-compilation.md).  
  
 Ao compilar com **/clr**, o compilador converterá literais de cadeia de caracteres em cadeias de caracteres do tipo <xref:System.String>. Para preservar a compatibilidade com versões anteriores com o código existente há são duas exceções a isso:  
  
-   Tratamento de exceção. Quando uma cadeia de caracteres literal for lançada, o compilador detectará como uma cadeia de caracteres literal.  
  
-   Dedução do modelo. Quando uma literal de cadeia de caracteres é passada como um argumento de modelo, o compilador não converterá para um <xref:System.String>. Observe que os literais de cadeia de caracteres passados como um argumento genérico serão promovidos para <xref:System.String>.  
  
 O compilador também tem suporte interno para três operadores que você pode substituir para personalizar seu comportamento:  
  
-   System:: string ^ operador + (System:: String, System:: String);  
  
-   System:: string ^ operador + (System::Object, System:: String);  
  
-   System:: string ^ operador + (System:: String, System::Object);  
  
 Quando passado um <xref:System.String>, o compilador caixa, se necessário e, em seguida, concatenar o objeto (com ToString) com a cadeia de caracteres.  
  
> [!NOTE]
>  O cursor ("^") indica que a variável declarada é um identificador para um C + + do objeto gerenciado de CLI.  
  
 Para obter mais informações, consulte [cadeia de caracteres e literais de caracteres](../cpp/string-and-character-literals-cpp.md).  
  
### <a name="requirements"></a>Requisitos  
 Opção de compilador: **/clr**  
  
### <a name="examples"></a>Exemplos  
 **Exemplo**  
  
 O exemplo de código a seguir demonstra a concatenação e comparação de cadeias de caracteres.  
  
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
  
 **Exemplo**  
  
 O exemplo a seguir mostra o que você pode sobrecarregar os operadores fornecidos pelo compilador e que o compilador encontra uma sobrecarga de função com base no <xref:System.String> tipo.  
  
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
  
```Output  
overloaded +(String ^ a, String ^ b)   
  
overloaded +(String ^ a, Object ^ b)   
  
overloaded +(Object ^ a, String ^ b)   
  
String ^ a  
  
const char * a  
```  
  
 **Exemplo**  
  
 O exemplo a seguir mostra que o compilador faz distinção entre cadeias de caracteres nativas e <xref:System.String> cadeias de caracteres.  
  
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
  
```Output  
char *  
  
String^ str  
  
System.SByte*  
  
System.String  
```  
  
## <a name="see-also"></a>Consulte também  
 [Extensões de componentes para plataformas de tempo de execução](../windows/component-extensions-for-runtime-platforms.md)   
 [Cadeia de caracteres e literais de caracteres](../cpp/string-and-character-literals-cpp.md)   
 [/clr (compilação do Common Language Runtime)](../build/reference/clr-common-language-runtime-compilation.md)