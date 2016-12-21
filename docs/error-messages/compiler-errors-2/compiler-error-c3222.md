---
title: "Erro do Compilador C3222 | Microsoft Docs"
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
  - "C3222"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "C3222"
ms.assetid: 5624bde8-2fd0-4b8b-92ce-5dfbaf91cf93
caps.latest.revision: 10
caps.handback.revision: 10
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Erro do Compilador C3222
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

'parâmetro': não é possível declarar argumentos padrão para o membro de um gerenciado ou tipo WinRT ou genéricas funções  
  
 Não é permitido para declarar um parâmetro de método com um argumento padrão.  Um formulário de sobrecarga do método é uma maneira de contornar esse problema.  Ou seja, defina um método com o mesmo nome sem parâmetros e, em seguida, inicialize a variável no corpo do método.  
  
 O exemplo a seguir gera C3222:  
  
```  
// C3222_2.cpp  
// compile with: /clr  
public ref class G {  
   void f( int n = 0 );   // C3222  
};  
```  
  
 O exemplo a seguir gera C3222:  
  
```  
// C3222.cpp  
// compile with: /clr:oldSyntax  
public __gc class G {  
   void f( int n = 0 );   // C3222  
};  
```