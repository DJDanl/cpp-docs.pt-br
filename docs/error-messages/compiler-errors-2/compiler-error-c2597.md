---
title: "Erro do Compilador C2597 | Microsoft Docs"
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
  - "C2597"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "C2597"
ms.assetid: 2e48127d-e3ff-4a40-8156-2863e45b1a38
caps.latest.revision: 10
caps.handback.revision: 10
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Erro do Compilador C2597
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

referência inválida para membro não estático 'identifier'  
  
 Possíveis causas:  
  
1.  Um membro não estático é especificado em uma função de membro estático.  Para acessar o membro não estático, você deve passar ou criar uma instância da classe local e usar um operador de acesso de membro \(`.` ou `->`\).  
  
2.  O identificador especificado não é um membro de uma classe, estrutura ou união.  Verifica a ortografia de identificador.  
  
3.  Um operador de acesso de membro se refere a uma função não é membro.  
  
4.  O exemplo a seguir gera C2597 e mostra como corrigi\-lo:  
  
```  
// C2597.cpp  
// compile with: /c  
struct s1 {  
   static void func();  
   static void func2(s1&);  
   int i;  
};  
  
void s1::func() {  
   i = 1;    // C2597 - static function can't access non-static data member  
}  
  
// OK - fix by passing an instance of s1  
void s1::func2(s1& a) {  
   a.i = 1;  
}  
  
```