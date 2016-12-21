---
title: "Transfer&#234;ncias de controle | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "language-reference"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "fluxo de controle, ramificação"
  - "fluxo de controle, transferindo o controle"
ms.assetid: aa51e7f2-060f-4106-b0fe-331f04357423
caps.latest.revision: 7
caps.handback.revision: 7
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Transfer&#234;ncias de controle
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Você pode usar a instrução `goto` ou rótulo **case** em uma instrução `switch` para especificar um programa que crie ramificações após um inicializador.  Esse código é inválido, a menos que a declaração que contém o inicializador esteja em um bloco delimitado pelo bloco em que a instrução de salto ocorre.  
  
 O exemplo a seguir mostra um loop que declara e inicializa os objetos `total`, `ch` e `i`.  Há também uma instrução `goto` com erros que transfere o controle após um inicializador.  
  
```  
// transfers_of_control.cpp  
// compile with: /W1  
// Read input until a nonnumeric character is entered.  
int main()  
{  
   char MyArray[5] = {'2','2','a','c'};  
   int i = 0;  
   while( 1 )  
   {  
      int total = 0;  
  
      char ch = MyArray[i++];  
  
      if ( ch >= '0' && ch <= '9' )  
      {  
         goto Label1;  
  
         int i = ch - '0';  
      Label1:  
         total += i;   // C4700: transfers past initialization of i.  
      } // i would be destroyed here if  goto error were not present  
   else  
      // Break statement transfers control out of loop,  
      //  destroying total and ch.  
      break;  
   }  
}  
```  
  
 No exemplo anterior, a instrução `goto` tenta transferir o controle após a inicialização de `i`.  No entanto, se `i` tivesse sido declarado, mas não inicializado, a transferência seria válida.  
  
 Os objetos `total` e `ch`, declarados no bloco que serve como *instrução* da instrução `while`, são destruídos quando esse bloco é fechado usando a instrução `break`.  
  
## Consulte também  
 [\(NOTINBUILD\) Declaration of Automatic Objects](http://msdn.microsoft.com/pt-br/81f941e9-c1b1-4d1c-a28d-70b6ee9765db)