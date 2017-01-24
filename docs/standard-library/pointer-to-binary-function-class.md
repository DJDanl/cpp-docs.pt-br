---
title: "Classe pointer_to_binary_function | Microsoft Docs"
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
  - "std::pointer_to_binary_function"
  - "xfunctional/std::pointer_to_binary_function"
  - "pointer_to_binary_function"
  - "std.pointer_to_binary_function"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe pointer_to_binary_function"
  - "Função pointer_to_binary_function"
ms.assetid: fb50599f-bcb3-4076-a669-6dcc3eb189a5
caps.latest.revision: 21
caps.handback.revision: 11
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Classe pointer_to_binary_function
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Converte um ponteiro binária da função em uma função adaptávela binário.  
  
## Sintaxe  
  
```  
template<class Arg1, class Arg2, class Result>  
   class pointer_to_binary_function   
   : public binary_function <Arg1, Arg2, Result>   
   {  
   public:  
   explicit pointer_to_binary_function(  
      Result (*_pfunc )( Arg1, Arg2 )   
   );  
   Result operator()(  
      Arg1 _Left,   
      Arg2 _Right  
   ) const;  
   };  
```  
  
#### Parâmetros  
 `_pfunc`  
 A função binário a ser convertida.  
  
 `_Left`  
 O objeto esquerdo que *o \*\_pfunc* é chamado.  
  
 `_Right`  
 O objeto direito do *\*\_pfunc* é chamado.  
  
## Valor de retorno  
 A classe do modelo armazena uma cópia de **\_pfunc**.  Define sua função de membro `operator()` como retornar \(\***\_pfunc**\)\(\_*Left*, \_*Right*\).  
  
## Comentários  
 Um ponteiro binária da função é um objeto de função e pode ser passado para qualquer algoritmo padrão da biblioteca do modelo que esperar uma função binário como um parâmetro, mas não é adaptável.  Para usá\-lo com um adaptador, como associar\-lhe um valor ou o uso deles com um negator, deve ser fornecida com os tipos **first\_argument\_type**aninhados, **second\_argument\_type**, e **result\_type** que tornam esse adaptação possível.  A conversão por `pointer_to_binary_function` permite que os adaptadores de função funcione com ponteiros binários da função.  
  
## Exemplo  
 O construtor de `pointer_to_binary_function` é raramente usada diretamente.  Consulte a [ptr\_fun](../Topic/ptr_fun%20Function.md) função auxiliar para obter um exemplo de como declarar e usar o predicado do adaptador de `pointer_to_binary_function` .  
  
## Requisitos  
 **Cabeçalho:** \<funcional\>  
  
 **Namespace:** std  
  
## Consulte também  
 [Biblioteca de Modelos Padrão](../misc/standard-template-library.md)