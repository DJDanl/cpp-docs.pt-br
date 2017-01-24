---
title: "Classe mem_fun1_ref_t | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
f1_keywords: 
  - "xfunctional/std::mem_fun1_ref_t"
  - "std::mem_fun1_ref_t"
  - "mem_fun1_ref_t"
  - "std.mem_fun1_ref_t"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe mem_fun1_ref_t"
ms.assetid: 7d6742f6-19ba-4523-b3c8-0e5b8f11464f
caps.latest.revision: 20
caps.handback.revision: 10
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Classe mem_fun1_ref_t
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Uma classe de adaptador que permite uma função de membro de **non\_const** que usa um único argumento a ser chamado como um objeto binário da função quando inicializada com um argumento de referência.  
  
## Sintaxe  
  
```  
template<class Result, class Type, class Arg>  
   class mem_fun1_ref_t : public binary_function<Type, Arg, Result> {  
      explicit mem_fun1_ref_t(  
         Result (Type::* _Pm )( Arg )  
      );  
      Result operator()(  
         Type& _Left,   
         Arg _Right  
      ) const;  
   };  
```  
  
#### Parâmetros  
 `_Pm`  
 Um ponteiro para a função de membro da classe **Tipo** a ser convertido em um objeto da função.  
  
 `_Left`  
 O objeto ao qual a função de membro de `_Pm` será chamada.  
  
 `_Right`  
 O argumento que está sendo atribuído a `_Pm`.  
  
## Valor de retorno  
 Uma função adaptávela binário.  
  
## Comentários  
 A classe do modelo armazena uma cópia de `_Pm`, que deve ser um ponteiro para uma função de membro da classe **Tipo**, em um objeto de membro particular.  Define sua função de membro `operator()` como retornar \(**\_Left**. \* `_Pm`\) \(**\_Right**\).  
  
## Exemplo  
 O construtor de `mem_fun1_ref_t` geralmente não é usado diretamente; a função `mem_fun_ref` auxiliar é usada para adaptar funções de membro.  Consulte [mem\_fun\_ref](../Topic/mem_fun_ref%20Function.md) para obter um exemplo de como usar adaptadores da função de membro.  
  
## Requisitos  
 **Cabeçalho:** \<funcional\>  
  
 **Namespace:** std  
  
## Consulte também  
 [Segurança de threads na Biblioteca Padrão C\+\+](../standard-library/thread-safety-in-the-cpp-standard-library.md)   
 [Biblioteca de Modelos Padrão](../misc/standard-template-library.md)