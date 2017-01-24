---
title: "Operadores definidos pelo usu&#225;rio (C++/CLI) | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "operadores definidos pelo usuário sob /clr"
ms.assetid: 42f93b4a-6de4-4e34-b07b-5a62ac014f2c
caps.latest.revision: 16
caps.handback.revision: 14
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Operadores definidos pelo usu&#225;rio (C++/CLI)
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

São permitidos operadores definidos pelo usuário para tipos gerenciados como membros estáticos ou membros de instância, ou no escopo global.  Porém, apenas os operadores estáticos são acessíveis pelos metadados para os clientes que são gravados em um idioma diferente do Visual C\+\+.  
  
 Em um tipo de referência, um dos parâmetros de um operador definido pelo usuário estático deve ser um destes:  
  
-   Um identificador de`type` \(^\) a uma instância do tipo inclusive.  
  
-   Uma ação indireta do tipo de referência \(^& \) ou type^% de`type`a um identificador para uma instância do tipo inclusive.  
  
 Em um tipo de valor, um dos parâmetros de um operador definido pelo usuário estático deve ser um destes:  
  
-   Do mesmo tipo do tipo de valor inclusive.  
  
-   Uma ação indireta do tipo de ponteiro \(^\) para o tipo de`type`inclusive.  
  
-   Uma ação indireta do tipo de referência \(`type`% ou `type`&\) para o tipo inclusive.  
  
-   Uma ação indireta do tipo de referência \(`type`^% ou ^&de `type`\) ao identificador.  
  
 Você pode definir os seguintes operadores:  
  
|Operador|Formas unários\/binários?|  
|--------------|-------------------------------|  
|\!|Unário|  
|\!\=|Binary|  
|%|Binary|  
|&|Unário e binário|  
|&&|Binary|  
|\*|Unário e binário|  
|\+|Unário e binário|  
|\+\+|Unário|  
|,|Binary|  
|\-|Unário e binário|  
|\-\-|Unário|  
|\-\>|Unário|  
|\/|Binary|  
|\<|Binary|  
|\<\<|Binary|  
|\<\=|Binary|  
|\=|Binary|  
|\=\=|Binary|  
|\>|Binary|  
|\>\=|Binary|  
|\>\>|Binary|  
|^|Binary|  
|false|Unário|  
|true|Unário|  
|&#124;|Binary|  
|&#124;&#124;|Binary|  
|~|Unário|  
  
## Exemplo  
  
```  
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
  
  **\-5**  
**\-4**  
**\-3**  
**\-2**  
**\-1**  
**\-2**  
**\-3**   
## Exemplo  
 O exemplo a seguir demonstra a síntese do operador, que está disponível somente quando você usa para criar **\/clr** .  A síntese do operador cria o formulário de atribuição de um operador binário, se não estiver definido, onde o lado esquerdo do operador de atribuição tem um tipo CLR.  
  
```  
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
  
  **30**   
## Consulte também  
 [Classes and Structs](../windows/classes-and-structs-cpp-component-extensions.md)