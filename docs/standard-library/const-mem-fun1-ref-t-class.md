---
title: "Classe const_mem_fun1_ref_t | Microsoft Docs"
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
  - "std::const_mem_fun1_ref_t"
  - "std.const_mem_fun1_ref_t"
  - "xfunctional/std::const_mem_fun1_ref_t"
  - "const_mem_fun1_ref_t"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe const_mem_fun1_ref_t"
ms.assetid: 8220d373-fa1c-44be-a21d-96d49b3ea6bb
caps.latest.revision: 20
caps.handback.revision: 10
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Classe const_mem_fun1_ref_t
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Uma classe de adaptador que permite uma função de membro de **const** que usa um único argumento a ser chamado como um objeto binário da função quando inicializada com um argumento de referência.  
  
## Sintaxe  
  
```  
template<class Result, class Type, class Arg>  
   class const_mem_fun1_ref_t  
      : public binary_function<Type, Arg, Result> {  
   explicit const_mem_fun1_ref_t( Result (Type::*_Pm )( Arg ) const );  
   Result operator()(  
      const Type& _Left,  
      Arg _Right  
   ) const;  
   };  
```  
  
#### Parâmetros  
 `_Pm`  
 Um ponteiro para a função de membro da classe **Tipo** a ser convertido em um objeto da função.  
  
 `_Left`  
 O objeto de **const** que a função de membro de `_Pm` será chamada.  
  
 `_Right`  
 O argumento que está sendo atribuído a `_Pm`.  
  
## Valor de retorno  
 Uma função adaptávela binário.  
  
## Comentários  
 A classe do modelo armazena uma cópia de `_Pm`, que deve ser um ponteiro para uma função de membro da classe **Tipo**, em um objeto de membro particular.  Define sua função de membro `operator()` como retornar \(`_Left`. \* *\_Pm*\) \(`_Right`\) **const**.  
  
## Exemplo  
 O construtor de `const_mem_fun1_ref_t` geralmente não é usado diretamente; a função `mem_fun_ref` auxiliar é usada para adaptar funções de membro.  Consulte [mem\_fun\_ref](../Topic/mem_fun_ref%20Function.md) para obter exemplos de como usar adaptadores da função de membro.  
  
## Requisitos  
 **Cabeçalho:** \<funcional\>  
  
 **Namespace:** std  
  
## Consulte também  
 [Segurança de threads na Biblioteca Padrão C\+\+](../standard-library/thread-safety-in-the-cpp-standard-library.md)   
 [Biblioteca de Modelos Padrão](../misc/standard-template-library.md)