---
title: "Instru&#231;&#227;o if (C) | Microsoft Docs"
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
  - "else"
  - "if"
dev_langs: 
  - "C++"
  - "C"
helpviewer_keywords: 
  - "cláusulas else"
  - "palavra-chave else [C]"
  - "palavra-chave if [C]"
  - "palavra-chave if [C], sintaxe de instrução if"
  - "instruções aninhadas"
ms.assetid: d7fc16a0-fdbc-4f39-b596-76e1ca4ad4a5
caps.latest.revision: 7
caps.handback.revision: 7
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Instru&#231;&#227;o if (C)
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

A instrução **if** controla a ramificação condicional.  O corpo de uma instrução **if** é executado se o valor de expressão for diferente de zero.  A sintaxe da instrução **if** tem dois formatos.  
  
## Sintaxe  
 *selection\-statement*:  
 **if \(**  *expression*  **\)**  *statement*  
  
 **if \(**  *expression*  **\)**  *statement*  **else**  *statement*  
  
 Em ambos os formatos da instrução **if**, as expressões, que podem ter qualquer valor exceto uma estrutura, são avaliadas, inclusive todos os efeitos colaterais.  
  
 No primeiro formato da sintaxe, se a *expressão* for verdadeira \(diferente de zero\), a *instrução* será executada.  Se a *expressão* for falsa, a *instrução* será ignorada.  No segundo formato da sintaxe, que usa **else**, a segunda *instrução* é executada se a *expressão* for falsa.  Com ambos os formatos, o controle passará da instrução **if** para a próxima instrução do programa, a menos que uma das instruções contenha **break**, **continue** ou `goto`.  
  
 Os seguintes são exemplos da instrução **if**:  
  
```  
if ( i > 0 )  
    y = x / i;  
else   
{  
    x = i;  
    y = f( x );  
}  
```  
  
 Neste exemplo, a instrução `y = x/i;` é executada se `i` for maior que 0.  Se `i` for menor ou igual a 0, `i` é atribuído a `x` e `f( x )` é atribuído a `y`.  Observe que a instrução que forma a cláusula **if** termina com um ponto e vírgula.  
  
 Ao aninhar as instruções **if** e cláusulas **else**, use chaves para agrupar as instruções e cláusulas em instruções compostas que esclareçam o seu intento.  Se nenhuma chave estiver presente, o compilador resolve as ambiguidades associando cada **else** com o **if** sem **else** mais próximo.  
  
```  
if ( i > 0 )           /* Without braces */  
    if ( j > i )  
        x = j;  
    else  
        x = i;  
```  
  
 Neste exemplo, A cláusula **else** é associada à instrução **if** interna.  Se `i` for menor ou igual a 0, nenhum valor será atribuído a `x`.  
  
```  
if ( i > 0 )   
{                      /* With braces */  
    if ( j > i )  
        x = j;  
}  
else  
    x = i;  
```  
  
 As chaves que cercam a instrução interna **if** neste exemplo formam a parte da cláusula **else** da instrução exterior **if**.  Se `i` for menor ou igual a 0, `i` é atribuído a `x`.  
  
## Consulte também  
 [Instrução if\-else \(C\+\+\)](../cpp/if-else-statement-cpp.md)