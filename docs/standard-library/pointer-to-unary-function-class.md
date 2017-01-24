---
title: "Classe pointer_to_unary_function | Microsoft Docs"
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
  - "xfunctional/std::pointer_to_unary_function"
  - "pointer_to_unary_function"
  - "std.pointer_to_unary_function"
  - "std::pointer_to_unary_function"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe pointer_to_unary_function"
  - "Função pointer_to_unary_function"
ms.assetid: 05600207-b916-4759-beca-6b6facd2d6f6
caps.latest.revision: 21
caps.handback.revision: 11
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Classe pointer_to_unary_function
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Converte um ponteiro unário da função em uma função adaptávela unário.  
  
## Sintaxe  
  
```  
template<class Arg, class Result>  
class pointer_to_unary_function  
    : public unary_function<Arg, Result>   
    {  
    public:  
        explicit pointer_to_unary_function(  
            Result (*_pfunc)(Arg)  
        );  
        Result operator()(  
            Arg _Left  
        ) const;  
    };  
```  
  
#### Parâmetros  
 `_pfunc`  
 A função binário a ser convertida.  
  
 `_Left`  
 O objeto que *o \*\_pfunc* é chamado.  
  
## Valor de retorno  
 A classe do modelo armazena uma cópia de **\_pfunc**.  Define sua função de membro `operator()` como retornar \(\***\_pfunc**\)\(\_*Left*\).  
  
## Comentários  
 Um ponteiro unário da função é um objeto de função e pode ser passado para qualquer algoritmo padrão da biblioteca do modelo que esperar uma função unário como um parâmetro, mas não é adaptável.  Para usá\-lo com um adaptador, como associar\-lhe um valor ou o uso deles com um negator, deve ser fornecida com os tipos **argument\_type** aninhados e **result\_type** que tornam esse adaptação possível.  A conversão por `pointer_to_unary_function` permite que os adaptadores de função funcione com ponteiros binários da função.  
  
## Exemplo  
 O construtor de `pointer_to_unary_function` é raramente usada diretamente.  Consulte a [ptr\_fun](../Topic/ptr_fun%20Function.md) função auxiliar para obter um exemplo de como declarar e usar o predicado do adaptador de `pointer_to_unary_function` .  
  
## Requisitos  
 **Cabeçalho:** \<funcional\>  
  
 **Namespace:** std  
  
## Consulte também  
 [Biblioteca de Modelos Padrão](../misc/standard-template-library.md)