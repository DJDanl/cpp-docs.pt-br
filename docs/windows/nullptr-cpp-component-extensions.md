---
title: "nullptr  (C++ Component Extensions) | Microsoft Docs"
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
  - "__nullptr keyword (C++)"
  - "nullptr keyword [C++]"
ms.assetid: 594cfbf7-06cb-4366-9ede-c0b703e1d095
caps.latest.revision: 24
caps.handback.revision: 22
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# nullptr  (C++ Component Extensions)
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

A palavra\-chave de `nullptr` representa *um valor do ponteiro nulo*.  Use um valor de ponteiro nulo para indicar que um identificador de objeto, um ponteiro interior, ou um tipo nativo do ponteiro não aponte para um objeto.  
  
 Use `nullptr` com o código gerenciado ou nativo.  O compilador emite instruções apropriadas mas diferentes para valores de ponteiro nulo gerenciados e nativos.  Para obter informações sobre como usar a versão do padrão ISO C\+\+ dessa palavra\-chave, consulte [nullptr](../Topic/nullptr.md).  
  
 A palavra\-chave de `__nullptr` é uma palavra\-chave microsoft específico que tem o mesmo significado que `nullptr`, mas só se aplica em código nativo.  Se você usar `nullptr` com código nativo C\/C\+\+ e o compila com a opção do compilador de [\/clr](../build/reference/clr-common-language-runtime-compilation.md) , o compilador não pode determinar se `nullptr` indica um nativo ou um valor do ponteiro nulo gerenciado.  Para fazer seu espaço livre de intenção de leitura ao compilador, use `nullptr` para especificar um valor gerenciado ou `__nullptr` para especificar um valor nativo.  
  
 A palavra\-chave de `nullptr` é equivalente a `Nothing` no Visual Basic e a `null` no C\#.  
  
## Uso  
 A palavra\-chave de `nullptr` pode ser usado em qualquer lugar um identificador, ponteiro nativo, ou o argumento da função pode ser usado.  
  
 A palavra\-chave de `nullptr` não é um tipo para o qual não há suporte para uso com:  
  
-   [sizeof](../cpp/sizeof-operator.md)  
  
-   [typeid](../cpp/typeid-operator.md)  
  
-   `throw nullptr` \(embora `throw (Object^)nullptr;` funcionará\)  
  
 A palavra\-chave de `nullptr` pode ser usado na inicialização dos seguintes tipos de ponteiro:  
  
-   Ponteiro nativo  
  
-   Identificador de Tempo de Execução do Windows  
  
-   Identificador gerenciado  
  
-   Ponteiro interior gerenciado  
  
 A palavra\-chave de `nullptr` pode ser usado para testar se uma referência de ponteiro for nula ou manipular antes que a referência é usada.  
  
 As chamadas de funções entre os idiomas que usam valores de ponteiro nulo para verificar os erros devem ser interpretados corretamente.  
  
 Você não pode inicializar um identificador em zero; somente `nullptr` pode ser usado.  A atribuição da constante 0 para um identificador de objeto gerencia `Int32` encaixotado e uma conversão a `Object^`.  
  
## Exemplo  
 O exemplo de código a seguir demonstra que a palavra\-chave de `nullptr` pode ser usado onde um identificador, ponteiro nativo, ou argumento da função pode ser usada.  E o exemplo a seguir demonstra que a palavra\-chave de `nullptr` pode ser usado para verificar uma referência antes de ser usado.  
  
```  
// mcpp_nullptr.cpp  
// compile with: /clr  
value class V {};  
ref class G {};  
void f(System::Object ^) {}  
  
int main() {  
// Native pointer.  
   int *pN = nullptr;  
// Managed handle.  
   G ^pG = nullptr;  
   V ^pV1 = nullptr;  
// Managed interior pointer.  
   interior_ptr<V> pV2 = nullptr;  
// Reference checking before using a pointer.  
   if (pN == nullptr) {}  
   if (pG == nullptr) {}  
   if (pV1 == nullptr) {}  
   if (pV2 == nullptr) {}  
// nullptr can be used as a function argument.  
   f(nullptr);   // calls f(System::Object ^)  
}  
```  
  
## Exemplo  
 **Exemplo**  
  
 O exemplo de código mostra que `nullptr` e zero podem ser usados alternadamente os ponteiros nativos.  
  
```  
// mcpp_nullptr_1.cpp  
// compile with: /clr  
class MyClass {  
public:  
   int i;  
};  
  
int main() {  
   MyClass * pMyClass = nullptr;  
   if ( pMyClass == nullptr)  
      System::Console::WriteLine("pMyClass == nullptr");  
  
   if ( pMyClass == 0)  
      System::Console::WriteLine("pMyClass == 0");  
  
   pMyClass = 0;  
   if ( pMyClass == nullptr)  
      System::Console::WriteLine("pMyClass == nullptr");  
  
   if ( pMyClass == 0)  
      System::Console::WriteLine("pMyClass == 0");  
}  
```  
  
 **Saída**  
  
  **nullptr \=\= de pMyClass**  
 **\=\= 0 de pMyClass**  
 **nullptr \=\= de pMyClass**  
 **\=\= 0 de pMyClass**   
## Exemplo  
 **Exemplo**  
  
 O exemplo de código a seguir mostra que `nullptr` será interpretado como um identificador em qualquer tipo ou a um ponteiro nativo para qualquer tipo.  No caso de sobrecarregamento de função com identificadores para tipos diferentes de ambiguidade, um erro será gerado.  `nullptr` precisará ser convertido explicitamente em um tipo.  
  
```  
// mcpp_nullptr_2.cpp  
// compile with: /clr /LD  
void f(int *){}  
void f(int ^){}  
  
void f_null() {  
   f(nullptr);   // C2668  
   // try one of the following lines instead  
   f((int *) nullptr);  
   f((int ^) nullptr);  
}  
```  
  
## Exemplo  
 **Exemplo**  
  
 O exemplo de código a seguir mostra que converter `nullptr` é permitido e retorna um ponteiro ou um identificador para o tipo convertido que contém o valor de `nullptr` .  
  
```  
// mcpp_nullptr_3.cpp  
// compile with: /clr /LD  
using namespace System;  
template <typename T>   
void f(T) {}   // C2036 cannot deduce template type because nullptr can be any type  
  
int main() {  
   f((Object ^) nullptr);   // T = Object^, call f(Object ^)  
  
   // Delete the following line to resolve.  
   f(nullptr);  
  
   f(0);   // T = int, call f(int)  
}  
```  
  
## Exemplo  
 **Exemplo**  
  
 O exemplo de código a seguir mostra que `nullptr` pode ser usado como um parâmetro de função.  
  
```  
// mcpp_nullptr_4.cpp  
// compile with: /clr  
using namespace System;  
void f(Object ^ x) {  
   Console::WriteLine("test");  
}  
  
int main() {  
   f(nullptr);  
}  
```  
  
 **Saída**  
  
  **testar**   
## Exemplo  
 **Exemplo**  
  
 O exemplo de código a seguir mostra que quando identificadores são declaradas explicitamente e não inicializadas, eles é inicializada a opção `nullptr`.  
  
```  
// mcpp_nullptr_5.cpp  
// compile with: /clr  
using namespace System;  
ref class MyClass {  
public:  
   void Test() {  
      MyClass ^pMyClass;   // gc type  
      if (pMyClass == nullptr)  
         Console::WriteLine("NULL");  
   }  
};  
  
int main() {  
   MyClass ^ x = gcnew MyClass();  
   x -> Test();  
}  
```  
  
 **Saída**  
  
  **NULL**   
## Exemplo  
 **Exemplo**  
  
 O exemplo de código a seguir mostra que `nullptr` pode ser atribuído a um ponteiro nativo quando você compila com **\/clr**.  
  
```  
// mcpp_nullptr_6.cpp  
// compile with: /clr  
int main() {  
   int * i = 0;  
   int * j = nullptr;  
}  
```  
  
## Requisitos  
 Opção de compilador: \(Não necessário; suporte de todas as opções de geração de código, inclusive **\/ZW** e **\/clr**\)  
  
## Consulte também  
 [Component Extensions for Runtime Platforms](../windows/component-extensions-for-runtime-platforms.md)   
 [nullptr](../Topic/nullptr.md)