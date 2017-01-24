---
title: "Classe mem_fun_t | Microsoft Docs"
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
  - "mem_fun_t"
  - "xfunctional/std::mem_fun_t"
  - "std::mem_fun_t"
  - "std.mem_fun_t"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe mem_fun_t"
ms.assetid: 242566d4-750c-4c87-9d63-2e2c9d19ca2a
caps.latest.revision: 19
caps.handback.revision: 9
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Classe mem_fun_t
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Uma classe de adaptador que permite uma função de membro de **non\_const** que não leve argumentos a ser chamado como um objeto unário da função quando inicializada com um argumento do ponteiro.  
  
## Sintaxe  
  
```  
template<class Result, class Type>  
   class mem_fun_t : public unary_function<Type *, Result> {  
      explicit mem_fun_t(Result ( Type::*_Pm )( ) );  
      Result operator()( Type* _Pleft ) const;  
   };  
```  
  
#### Parâmetros  
 `_Pm`  
 Um ponteiro para a função de membro da classe **Tipo** a ser convertido em um objeto da função.  
  
 `_Pleft`  
 O objeto ao qual a função de membro de `_Pm` será chamada.  
  
## Valor de retorno  
 Uma função adaptávela unário.  
  
## Comentários  
 A classe do modelo armazena uma cópia de `_Pm`, que deve ser um ponteiro para uma função de membro da classe **Tipo**, em um objeto de membro particular.  Define sua função de membro `operator()` como retornar \(`_Pleft`\-\>\* `_Pm`\)\( \).  
  
## Exemplo  
 O construtor de `mem_fun_t` geralmente não é usado diretamente; a função `mem_fun` auxiliar é usada para adaptar funções de membro.  Consulte [mem\_fun](../Topic/mem_fun%20Function.md) para obter um exemplo de como usar adaptadores da função de membro.  
  
## Requisitos  
 **Cabeçalho:** \<funcional\>  
  
 **Namespace:** std  
  
## Consulte também  
 [\<functional\>](../standard-library/functional.md)   
 [Segurança de threads na Biblioteca Padrão C\+\+](../standard-library/thread-safety-in-the-cpp-standard-library.md)   
 [Biblioteca de Modelos Padrão](../misc/standard-template-library.md)