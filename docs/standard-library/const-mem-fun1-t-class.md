---
title: "Classe const_mem_fun1_t | Microsoft Docs"
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
  - "std.const_mem_fun1_t"
  - "xfunctional/std::const_mem_fun1_t"
  - "std::const_mem_fun1_t"
  - "const_mem_fun1_t"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe const_mem_fun1_t"
ms.assetid: 250fac30-9663-4133-9051-6303f76ea259
caps.latest.revision: 20
caps.handback.revision: 10
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Classe const_mem_fun1_t
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Uma classe de adaptador que permite uma função de membro de **const** que usa um único argumento a ser chamado como um objeto binário da função quando inicializada com um argumento do ponteiro.  
  
## Sintaxe  
  
```  
template<class Result, class Type, class Arg>  
   class const_mem_fun1_t  
      : public binary_function<const Type *, Arg, Result>   
   {  
   explicit const_mem_fun1_t( Result ( Type::* _Pm )( Arg ) const );  
   Result operator()(  
      const Type* _Pleft,   
      Arg _Right  
   ) const;  
   };  
```  
  
#### Parâmetros  
 `_Pm`  
 Um ponteiro para a função de membro da classe **Tipo** a ser convertido em um objeto da função.  
  
 `_Pleft`  
 O objeto de **const** que a função de membro de `_Pm` será chamada.  
  
 `_Right`  
 O argumento que está sendo atribuído a `_Pm`.  
  
## Valor de retorno  
 Uma função adaptávela binário.  
  
## Comentários  
 A classe do modelo armazena uma cópia de `_Pm`, que deve ser um ponteiro para uma função de membro da classe **Tipo**, em um objeto de membro particular.  Define sua função de membro `operator()` como retornar \(**\_Pleft**\-\>\* *Pm\)\(***Right**\) **const**.  
  
## Exemplo  
 O construtor de `const_mem_fun1_t` geralmente não é usado diretamente; a função `mem_fun` auxiliar é usada para adaptar funções de membro.  Consulte [mem\_fun](../Topic/mem_fun%20Function.md) para obter um exemplo de como usar adaptadores da função de membro.  
  
## Requisitos  
 **Cabeçalho:** \<funcional\>  
  
 **Namespace:** std  
  
## Consulte também  
 [Segurança de threads na Biblioteca Padrão C\+\+](../standard-library/thread-safety-in-the-cpp-standard-library.md)   
 [Biblioteca de Modelos Padrão](../misc/standard-template-library.md)