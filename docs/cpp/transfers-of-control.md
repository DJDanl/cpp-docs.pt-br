---
title: Transferências de controle | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-language
ms.topic: language-reference
dev_langs:
- C++
helpviewer_keywords:
- control flow, branching
- control flow, transferring control
ms.assetid: aa51e7f2-060f-4106-b0fe-331f04357423
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: e773a0188eb3450ab1a13a24fc556fa8e8c4f874
ms.sourcegitcommit: 51f804005b8d921468775a0316de52ad39b77c3e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/02/2018
ms.locfileid: "39464263"
---
# <a name="transfers-of-control"></a>Transferências de controle
Você pode usar o **goto** instrução ou um **caso** rotular em um **alternar** instrução para especificar um programa que crie ramificações após um inicializador. Esse código é inválido, a menos que a declaração que contém o inicializador esteja em um bloco delimitado pelo bloco em que a instrução de salto ocorre.  
  
 O exemplo a seguir mostra um loop que declara e inicializa os objetos `total`, `ch` e `i`. Há também um incorretos **goto** instrução que transfere o controle após um inicializador.  
  
```cpp 
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
  
 No exemplo anterior, o **goto** instrução tenta transferir o controle após a inicialização de `i`. No entanto, se `i` tivesse sido declarado, mas não inicializado, a transferência seria válida.  
  
 Os objetos `total` e `ch`, declarada no bloco que serve como o *instrução* da **enquanto** instrução, são destruídos quando esse bloco é fechado usando a  **quebra** instrução.  