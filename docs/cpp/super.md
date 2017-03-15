---
title: "__super | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "language-reference"
f1_keywords: 
  - "__super_cpp"
  - "__super"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Palavra-chave __super [C++]"
ms.assetid: f0957c31-9256-405b-b402-cad182404b5f
caps.latest.revision: 7
caps.handback.revision: 7
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# __super
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

**Específico da Microsoft**  
  
 Permite que você indique explicitamente que está chamando uma implementação da classe base para uma função que está substituindo.  
  
## Sintaxe  
  
```  
  
__super::  
member_function  
();  
  
```  
  
## Comentários  
 Todos os métodos acessíveis da classe base são considerados durante a fase de resolução de sobrecarga e a função que fornece a melhor correspondência é a chamada.  
  
 `__super` só pode aparecer no corpo de uma função membro.  
  
 `__super` não pode ser usado com uma declaração de uso.  Consulte [Declaração de uso](../cpp/using-declaration.md) para obter mais informações.  
  
 Com a introdução de [atributos](../windows/cpp-attributes-reference.md) que injetam código, seu código pode conter uma ou várias classes base cujos nomes você pode não saber, mas que contêm métodos que você deseja chamar.  
  
## Exemplo  
  
```  
// deriv_super.cpp  
// compile with: /c  
struct B1 {  
   void mf(int) {}  
};  
  
struct B2 {  
   void mf(short) {}  
  
   void mf(char) {}  
};  
  
struct D : B1, B2 {  
   void mf(short) {  
      __super::mf(1);   // Calls B1::mf(int)  
      __super::mf('s');   // Calls B2::mf(char)  
   }  
};  
```  
  
 **FIM de Específico da Microsoft**  
  
## Consulte também  
 [Palavras\-chave C\+\+](../cpp/keywords-cpp.md)