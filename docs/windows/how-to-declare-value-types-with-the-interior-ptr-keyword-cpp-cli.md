---
title: "How to: Declare Value Types with the interior_ptr Keyword (C++/CLI) | Microsoft Docs"
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
  - "_ptr keyword"
  - "value types, declaring"
ms.assetid: 49eea66e-eeba-49bd-95b0-ba297be436e3
caps.latest.revision: 13
caps.handback.revision: 13
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# How to: Declare Value Types with the interior_ptr Keyword (C++/CLI)
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

`interior_ptr` pode ser usado com um tipo de valor.  
  
> [!IMPORTANT]
>  Esse recurso de idioma é suportado pela opção do compilador de **\/clr** , mas não pela opção do compilador de **\/ZW** .  
  
## Exemplo  
  
### Descrição  
 O exemplo de [!INCLUDE[cppcli](../build/reference/includes/cppcli_md.md)] mostra como usar `interior_ptr` com um tipo de valor.  
  
### Código  
  
```  
// interior_ptr_value_types.cpp  
// compile with: /clr  
value struct V {  
   V(int i) : data(i){}  
   int data;  
};  
  
int main() {  
   V v(1);  
   System::Console::WriteLine(v.data);  
  
   // pointing to a value type  
   interior_ptr<V> pv = &v;  
   pv->data = 2;  
  
   System::Console::WriteLine(v.data);  
   System::Console::WriteLine(pv->data);  
  
   // pointing into a value type  
   interior_ptr<int> pi = &v.data;  
   *pi = 3;  
   System::Console::WriteLine(*pi);  
   System::Console::WriteLine(v.data);  
   System::Console::WriteLine(pv->data);  
}  
```  
  
### Saída  
  
```  
1  
2  
2  
3  
3  
3  
```  
  
## Exemplo  
  
### Descrição  
 Em um tipo de valor, o ponteiro de `this` avalia a um interior\_ptr.  
  
 No corpo de uma função de membro de não estáticos de um tipo de valor `V`, `this` é uma expressão de tipo `interior_ptr<V>` cujo valor é o endereço do objeto para o qual a função é chamada.  
  
### Código  
  
```  
// interior_ptr_value_types_this.cpp  
// compile with: /clr /LD  
value struct V {  
   int data;  
   void f() {  
      interior_ptr<V> pv1 = this;  
      // V* pv2 = this;   error  
   }  
};  
```  
  
## Exemplo  
  
### Descrição  
 O exemplo a seguir mostra como usar endereços de operador com membros estáticos.  
  
 O endereço de um membro estático do tipo do Visual C\+\+ gerencie um ponteiro nativo.  O endereço de um membro estático do tipo de valor é um ponteiro gerenciado como o membro do tipo de valor é atribuído no heap de tempo de execução e pode ser movido pelo coletor de lixo.  
  
### Código  
  
```  
// interior_ptr_value_static.cpp  
// compile with: /clr  
using namespace System;  
value struct V { int i; };  
  
ref struct G {  
   static V v = {22};   
   static int i = 23;   
   static String^ pS = "hello";   
};  
  
int main() {  
   interior_ptr<int> p1 = &G::v.i;  
   Console::WriteLine(*p1);  
  
   interior_ptr<int> p2 = &G::i;  
   Console::WriteLine(*p2);  
  
   interior_ptr<String^> p3 = &G::pS;  
   Console::WriteLine(*p3);  
}  
```  
  
### Saída  
  
```  
22  
23  
hello  
```  
  
## Consulte também  
 [interior\_ptr \(C\+\+\/CLI\)](../windows/interior-ptr-cpp-cli.md)