---
title: "Membros de uni&#227;o e estrutura | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
dev_langs: 
  - "C++"
  - "C"
helpviewer_keywords: 
  - "Operador ."
  - "Operador ->, membros de união e estrutura"
  - "Operador ponto (.)"
  - "operadores de seleção de membro"
  - "operadores [C], seleção de membro"
  - "referenciando membros de estrutura"
  - "seleção de membro de estrutura"
  - "membros de estrutura, referenciando"
ms.assetid: bb1fe304-af49-4f98-808d-afdc99b3e319
caps.latest.revision: 8
caps.handback.revision: 8
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Membros de uni&#227;o e estrutura
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Uma "expressão de seleção de membros" faz referência a membros de estruturas e de uniões.  Essas expressões têm o valor e o tipo do membro selecionado.  
  
```  
  
        postfix-expression . identifier  
postfix-expression –> identifier  
```  
  
 Esta lista descreve as duas formas de expressões de seleção de membro:  
  
1.  No primeiro formato, *expressão postfix* representa um valor do tipo `struct` ou **união** e *identificador* nomeia um membro da estrutura ou da união especificada.  O valor da operação é o de *identificador* e é um l\-value se *expressão postfix* for um l\-value.  Consulte [Expressões de L\-value e R\-value](../Topic/L-Value%20and%20R-Value%20Expressions.md) para obter mais informações.  
  
2.  No segundo formato, *expressão postfix* representa um ponteiro para uma estrutura ou união *identificador* nomeia um membro da estrutura ou união especificada.  O valor é o de *identificador* e é um l\-value.  
  
 As duas formas de expressões de seleção de membros têm efeitos semelhantes.  
  
 De fato, uma expressão que envolva o operador de seleção de membros \(**–\>**\) é uma versão resumida de uma expressão usando o ponto \(**.**\) se a expressão antes do período consistir no operador de indireção \(**\***\) aplicado a um valor do ponteiro.  Portanto,  
  
```  
  
expression –> identifier  
```  
  
 equivale a  
  
```  
  
(*  
expression  
) . identifier  
```  
  
 quando *expressão* for um valor do ponteiro.  
  
## Exemplos  
 Os exemplos a seguir fazem referência a essa declaração de estrutura.  Para obter informações sobre o operador de indireção \(**\***\) usado nestes exemplos, consulte o tópico sobre [operadores de indireção e address\-of](../c-language/indirection-and-address-of-operators.md).  
  
```  
struct pair   
{  
    int a;  
    int b;  
    struct pair *sp;  
} item, list[10];  
```  
  
 Uma expressão de seleção de membros para a estrutura `item` é semelhante a:  
  
```  
item.sp = &item;  
```  
  
 No exemplo anterior, o endereço da estrutura `item` é atribuído ao membro `sp` da estrutura.  Isso significa que `item` contém um ponteiro para si mesmo.  
  
```  
(item.sp)–>a = 24;  
```  
  
 Neste exemplo, a expressão de ponteiro `item.sp` é usada com o operador de seleção de membros \(**–\>**\) para atribuir um valor ao membro `a`.  
  
```  
list[8].b = 12;  
```  
  
 Essa instrução mostra como selecionar um membro individual da estrutura em uma matriz de estruturas.  
  
## Consulte também  
 [Operadores de acesso do membro: . e \-\>](../Topic/Member%20Access%20Operators:%20.%20and%20-%3E.md)