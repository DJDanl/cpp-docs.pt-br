---
title: "Classe const_mem_fun_t | Microsoft Docs"
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
  - "const_mem_fun_t"
  - "std.const_mem_fun_t"
  - "xfunctional/std::const_mem_fun_t"
  - "std::const_mem_fun_t"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe const_mem_fun_t"
ms.assetid: f169d381-019b-4a0e-a9a3-54da6d948270
caps.latest.revision: 20
caps.handback.revision: 10
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Classe const_mem_fun_t
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Uma classe de adaptador que permite uma função de membro de const que não leve argumentos a ser chamado como um objeto unário da função quando inicializada com um argumento de referência.  
  
## Sintaxe  
  
```  
template<class Result, class Type>  
   class const_mem_fun_t : public unary_function <Type *, Result>   
   {  
   explicit const_mem_fun_t( Result ( Type::* _Pm )( ) const );  
   Result operator()(  
      const Type* _Pleft  
   ) const;  
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
 A classe do modelo armazena uma cópia de `_Pm`, que deve ser um ponteiro para uma função de membro da classe **Tipo**, em um objeto de membro particular.  Define sua função de membro `operator()` como retornar`_Pleft`\-\>\(\*\) `_Pm`\(\) **const**.  
  
## Exemplo  
 O construtor de `const_mem_fun_t` geralmente não é usado diretamente; a função `mem_fun` auxiliar é usada para adaptar funções de membro.  Consulte [mem\_fun](../Topic/mem_fun%20Function.md) para obter um exemplo de como usar adaptadores da função de membro.  
  
## Requisitos  
 **Cabeçalho:** \<funcional\>  
  
 **Namespace:** std  
  
## Consulte também  
 [Segurança de threads na Biblioteca Padrão C\+\+](../standard-library/thread-safety-in-the-cpp-standard-library.md)   
 [Biblioteca de Modelos Padrão](../misc/standard-template-library.md)