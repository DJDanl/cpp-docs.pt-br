---
title: "Erro do Compilador C2993 | Microsoft Docs"
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
  - "C2993"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "C2993"
ms.assetid: 4ffd2b78-654b-46aa-95a6-b62101cf91c8
caps.latest.revision: 8
caps.handback.revision: 8
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Erro do Compilador C2993
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

“identificador”: tipo ilegal para o parâmetro “parâmetro” do modelo que não seja do tipo  
  
 Você não pode declarar um modelo com um argumento da estrutura ou de união.  Use ponteiros para transmitir estruturas e uniões como parâmetros do modelo.  
  
 O seguinte exemplo gera C2993:  
  
```  
// C2993.cpp  
// compile with: /c  
// C2993 expected  
struct MyStruct {  
   int a;char b;  
};  
  
template <class T, struct MyStruct S>   // C2993  
  
// try the following line instead  
// template <class T, struct MyStruct * S>  
class CMyClass {};  
```  
  
 Esse erro será gerado também no resultado do trabalho de conformidade do compilador que foi feito no Visual Studio .NET 2003:. parâmetros do modelo que não seja do tipo de ponto flutuante não permitidos.  O padrão do C\+\+ não permite parâmetros do modelo que não seja do tipo de ponto flutuante.  
  
 Se for um modelo de função, use um argumento de função para transmitir o parâmetro de modelo que não seja do tipo de ponto flutuante \(esse código será válido em versões do Visual Studio .NET. 2003 e do Visual Studio .NET do Visual C\+\+\).  Se for um modelo da classe, não há nenhuma solução alternativa fácil.  
  
```  
// C2993b.cpp  
// compile with: /c  
template<class T, float f> void func(T) {}   // C2993  
  
// OK  
template<class T>   void func2(T, float) {}  
```