---
title: "C-Style Casts with /clr (C++/CLI) | Microsoft Docs"
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
  - "C-style casts and /clr"
ms.assetid: d2a4401a-156a-4da9-8d12-923743e26913
caps.latest.revision: 13
caps.handback.revision: 13
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# C-Style Casts with /clr (C++/CLI)
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

O seguinte tópico aplica\-se apenas ao Common Language Runtime.  
  
 Quando usado com tipos de CLR, o compilador tentar mapear a conversão do C \- estilo a uma das conversões listadas abaixo, na seguinte ordem:  
  
1.  const\_cast  
  
2.  safe\_cast  
  
3.  safe\_cast mais o const\_cast  
  
4.  static\_cast  
  
5.  static\_cast mais o const\_cast  
  
 Se nenhuma das conversões listadas acima é válida e, se o tipo da expressão e o tipo de destino são referência de tipo CLR, mapas de conversão do C \- estilo a uma verificação em tempo de compilação \(instrução de castclass MSIL\).  Se não, c a conversão de estilo é considerada inválida e os problemas do compilador um erro.  
  
## Comentários  
 C a conversão de estilo não é recomendada.  Ao criar com [\/clr \(compilação do Common Language Runtime\)](../build/reference/clr-common-language-runtime-compilation.md), use [safe\_cast](../windows/safe-cast-cpp-component-extensions.md).  
  
 A seguinte c de exemplo mostra a conversão de estilo que mapeia a `const_cast`.  
  
```  
// cstyle_casts_1.cpp  
// compile with: /clr  
using namespace System;  
  
ref struct R {};  
int main() {  
   const R^ constrefR = gcnew R();  
   R^ nonconstR = (R^)(constrefR);   
}  
```  
  
 A seguinte c de exemplo mostra a conversão de estilo que mapeia a `safe_cast`.  
  
```  
// cstyle_casts_2.cpp  
// compile with: /clr  
using namespace System;  
int main() {  
   Object ^ o = "hello";  
   String ^ s = (String^)o;  
}  
```  
  
 A seguinte c de exemplo mostra a conversão de estilo que mapeia a `safe_cast` mais `const_cast`.  
  
```  
// cstyle_casts_3.cpp  
// compile with: /clr  
using namespace System;  
  
ref struct R {};  
ref struct R2 : public R {};  
  
int main() {  
   const R^ constR2 = gcnew R2();  
   try {  
   R2^ b2DR = (R2^)(constR2);  
   }  
   catch(InvalidCastException^ e) {  
      System::Console::WriteLine("Invalid Exception");  
   }  
}  
```  
  
 A seguinte c de exemplo mostra a conversão de estilo que mapeia a `static_cast`.  
  
```  
// cstyle_casts_4.cpp  
// compile with: /clr  
using namespace System;  
  
struct N1 {};  
struct N2 {  
   operator N1() {  
      return N1();  
   }  
};  
  
int main() {  
   N2 n2;  
   N1 n1 ;  
   n1 = (N1)n2;  
}  
```  
  
 A seguinte c de exemplo mostra a conversão de estilo que mapeia a `static_cast` mais `const_cast`.  
  
```  
// cstyle_casts_5.cpp  
// compile with: /clr  
using namespace System;  
struct N1 {};  
  
struct N2 {  
   operator const N1*() {  
      static const N1 n1;  
      return &n1;  
   }  
};  
  
int main() {  
   N2 n2;  
   N1* n1 = (N1*)(const N1*)n2;   // const_cast + static_cast  
}  
```  
  
 A seguinte c de exemplo mostra a conversão de estilo que mapeia para uma verificação de tempo de execução.  
  
```  
// cstyle_casts_6.cpp  
// compile with: /clr  
using namespace System;  
  
ref class R1 {};  
ref class R2 {};  
  
int main() {  
   R1^ r  = gcnew R1();  
   try {  
      R2^ rr = ( R2^)(r);  
   }  
   catch(System::InvalidCastException^ e) {  
      Console::WriteLine("Caught expected exception");  
   }  
}  
```  
  
 O exemplo a seguir mostra uma conversão válida do C \- estilo, que faz com que o compilador emita um erro.  
  
```  
// cstyle_casts_7.cpp  
// compile with: /clr  
using namespace System;  
int main() {  
   String^s = S"hello";  
   int i = (int)s;   // C2440  
}  
```  
  
## Requisitos  
 Opção do compilador: **\/clr**  
  
## Consulte também  
 [Component Extensions for Runtime Platforms](../windows/component-extensions-for-runtime-platforms.md)