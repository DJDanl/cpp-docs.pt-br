---
title: "Como declarar identificadores em tipos nativos | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "get-started-article"
f1_keywords: 
  - "gcroot"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Palavra-chave gcroot [C++]"
  - "identificadores, declarando"
  - "tipos [C++], declarando identificadores em"
ms.assetid: b8c0eead-17e5-4003-b21f-b673f997d79f
caps.latest.revision: 14
caps.handback.revision: 12
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Como declarar identificadores em tipos nativos
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Você não pode declarar um identificador em um tipo nativo. vcclr.h fornece o modelo fortemente tipado `gcroot` de invólucro para se referir a um objeto CLR do heap C\+\+.  Esse modelo permite digitar um identificador virtual em um tipo nativo e tratá\-los como se fosse o tipo subjacente.  Na maioria dos casos, você pode usar o objeto de `gcroot` como o tipo inserido sem nenhuma conversão.  No entanto, com [for each, in](../dotnet/for-each-in.md), você tem que usar `static_cast` para recuperar a referência gerenciada subjacentes.  
  
 O modelo de `gcroot` é implementado usando as instalações da classe System::Runtime::InteropServices::GCHandle de valor, que fornece as “identificadores” no heap com coletados.  Observe que os identificadores em si não são limpos e são liberadas quando não em uso pelo destruidor na classe de `gcroot` \(esse destruidor não pode ser chamado manualmente\).  Se você criar uma instância de um objeto de `gcroot` no heap nativo, você deve chamar a exclusão desse recurso.  
  
 O tempo de execução manterá uma associação entre o identificador e o objeto CLR, que referencia.  Quando o objeto CLR se move um com o heap com coletado, o identificador retornará o novo endereço do objeto.  Uma variável não tem que ser fixado antes que seja atribuído a um modelo de `gcroot` .  
  
## Exemplo  
 Este exemplo mostra como criar um objeto de `gcroot` na pilha nativo.  
  
```  
// mcpp_gcroot.cpp  
// compile with: /clr  
#include <vcclr.h>  
using namespace System;  
  
class CppClass {  
public:  
   gcroot<String^> str;   // can use str as if it were String^  
   CppClass() {}  
};  
  
int main() {  
   CppClass c;  
   c.str = gcnew String("hello");  
   Console::WriteLine( c.str );   // no cast required  
}  
```  
  
  **hello**   
## Exemplo  
 Este exemplo mostra como criar um objeto de `gcroot` no heap nativo.  
  
```  
// mcpp_gcroot_2.cpp  
// compile with: /clr  
// compile with: /clr  
#include <vcclr.h>  
using namespace System;  
  
struct CppClass {  
   gcroot<String ^> * str;  
   CppClass() : str(new gcroot<String ^>) {}  
  
   ~CppClass() { delete str; }  
  
};  
  
int main() {  
   CppClass c;  
   *c.str = gcnew String("hello");  
   Console::WriteLine( *c.str );  
}  
```  
  
  **hello**   
## Exemplo  
 Este exemplo mostra como usar `gcroot` para manter referências aos tipos de valor \(não tipos de referência\) em um tipo nativo usando `gcroot` no tipo encaixotado.  
  
```  
// mcpp_gcroot_3.cpp  
// compile with: /clr  
#include < vcclr.h >  
using namespace System;  
  
public value struct V {  
   String^ str;  
};  
  
class Native {  
public:  
   gcroot< V^ > v_handle;  
};  
  
int main() {  
   Native native;  
   V v;  
   native.v_handle = v;  
   native.v_handle->str = "Hello";  
   Console::WriteLine("String in V: {0}", native.v_handle->str);  
}  
```  
  
  **Cadeia de caracteres em V: Hello world**   
## Consulte também  
 [Usando interop C\+\+ \(PInvoke implícito\)](../dotnet/using-cpp-interop-implicit-pinvoke.md)