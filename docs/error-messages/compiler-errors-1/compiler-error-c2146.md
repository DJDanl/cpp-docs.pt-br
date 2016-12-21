---
title: "Erro do Compilador C2146 | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "error-reference"
f1_keywords: 
  - "C2146"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "C2146"
ms.assetid: 6bfb7de6-6723-4486-9350-c66ef88d7a64
caps.latest.revision: 14
caps.handback.revision: 14
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Erro do Compilador C2146
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

erro de sintaxe: “token ausentes” antes de “identificador identificador”  
  
 `token` previsto compilador e `identifier` localizado em vez disso.  Causas possíveis:  
  
1.  Erros de ortografia ou de capitalização.  
  
2.  Especificador ausente do tipo na declaração do identificador.  
  
 Esse erro pode ser causado por um erro de digitação.  O erro [C2065](../../error-messages/compiler-errors-1/compiler-error-c2065.md) precede geralmente esse erro.  
  
## Exemplo  
 O exemplo a seguir produz C2146.  
  
```  
// C2146.cpp  
class CDeclaredClass {};  
  
class CMyClass {  
   CUndeclared m_myClass;   // C2146  
   CDeclaredClass m_myClass2;   // OK  
};  
  
int main() {  
   int x;  
   int t x;   // C2146 : missing semicolon before 'x'  
}  
```  
  
## Exemplo  
 Esse erro também pode ser gerado no resultado do trabalho de conformidade do compilador que foi feito para Visual Studio .NET 2003:. palavras\-chave de falta de `typename` .  
  
 O exemplo a seguir cria no Visual Studio .NET 2002. mas não no Visual Studio .NET 2003:.  
  
```  
// C2146b.cpp  
// compile with: /c  
template <typename T>  
struct X {  
   struct Y {  
      int i;  
   };  
   Y memFunc();  
};  
  
template <typename T>  
X<T>::Y func() { }   // C2146  
  
// OK  
template <typename T>  
typename X<T>::Y func() { }  
```  
  
## Exemplo  
 Você também verá esse erro no resultado do trabalho de conformidade do compilador que foi feito para Visual Studio .NET 2003:. as especializações explícitas não localizar parâmetros do modelo do modelo primário.  
  
 O uso de `T` do modelo primário não é permitido na especialização explícita.  Para que o código seja válido em versões do Visual Studio .NET. 2003 e do Visual Studio .NET do Visual C\+\+, substituir todas as instâncias de parâmetros do modelo na especialização com o tipo explicitamente especializado.  
  
 O exemplo a seguir cria no Visual Studio .NET mas não no Visual Studio .NET 2003:.  
  
```  
// C2146_c.cpp  
// compile with: /c  
template <class T>   
struct S;  
  
template <>   
struct S<int> {  
   T m_t;   // C2146  
   int m_t2;   // OK  
};  
```