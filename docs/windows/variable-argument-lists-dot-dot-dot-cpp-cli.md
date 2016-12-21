---
title: "Variable Argument Lists (...) (C++/CLI) | Microsoft Docs"
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
  - "variable argument lists"
  - "parameter arrays"
ms.assetid: db1a27f4-02a8-4318-8690-1f2893f52b38
caps.latest.revision: 22
caps.handback.revision: 22
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Variable Argument Lists (...) (C++/CLI)
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Este exemplo mostra como você pode usar a sintaxe `...` no Visual C\+\+ para implementar as funções que têm um número variável de argumentos.  
  
> [!NOTE]
>  Este tópico refere\-se a C\+\+\/CLI.  Para obter informações sobre o uso de `...` no C\+\+ Padrão ISO, consulte [Reticências e modelos variadic](../cpp/ellipses-and-variadic-templates.md) e [Reticências e argumentos padrão](../misc/ellipses-and-default-arguments.md).  
  
 O parâmetro que usa `...` deve ser o último parâmetro da lista.  
  
## Exemplo  
  
### Código  
  
```  
// mcppv2_paramarray.cpp  
// compile with: /clr  
using namespace System;  
double average( ... array<Int32>^ arr ) {  
   int i = arr->GetLength(0);  
   double answer = 0.0;  
  
   for (int j = 0 ; j < i ; j++)  
      answer += arr[j];  
  
   return answer / i;  
}  
  
int main() {  
   Console::WriteLine("{0}", average( 1, 2, 3, 6 ));  
}  
```  
  
### Saída  
  
```  
3  
```  
  
## Exemplo de código  
 O exemplo a seguir mostra como chamar de C\# uma função do Visual C\+\+ que recebe um número variável de argumentos.  
  
```  
// mcppv2_paramarray2.cpp  
// compile with: /clr:safe /LD  
using namespace System;  
  
public ref class C {  
public:   
   void f( ... array<String^>^ a ) {}  
};  
```  
  
 A função `f` pode ser chamada do C\# ou Visual Basic, por exemplo, como se fosse uma função que pode ser um número variável de argumentos.  
  
 No C\#, um argumento que é passado para um parâmetro `ParamArray` pode ser chamado por um número variável de argumentos.  O exemplo de código a seguir está em C\#.  
  
```  
// mcppv2_paramarray3.cs  
// compile with: /r:mcppv2_paramarray2.dll  
// a C# program  
  
public class X {  
   public static void Main() {  
      // Visual C# will generate a String array to match the   
      // ParamArray attribute  
      C myc = new C();  
      myc.f("hello", "there", "world");  
   }  
}  
```  
  
 Uma chamada para `f` no Visual C\+\+ pode passar uma matriz inicializada ou uma matriz de comprimento variável.  
  
```  
// mcpp_paramarray4.cpp  
// compile with: /clr  
using namespace System;  
  
public ref class C {  
public:   
   void f( ... array<String^>^ a ) {}  
};  
  
int main() {  
   C ^ myc = gcnew C();  
   myc->f("hello", "world", "!!!");  
}  
```  
  
## Consulte também  
 [Arrays](../windows/arrays-cpp-component-extensions.md)