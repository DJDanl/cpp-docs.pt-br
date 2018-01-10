---
title: Operadores de acesso de membro:. e -&gt; | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-language
ms.tgt_pltfrm: 
ms.topic: language-reference
f1_keywords:
- .
- ->
dev_langs: C++
helpviewer_keywords:
- member access, expressions
- operators [C++], member access
- dot operator (.)
- -> operator
- member access, operators
- postfix operators [C++]
- . operator
- member access
ms.assetid: f8fc3df9-d728-40c5-b384-276927f5f1b3
caps.latest.revision: "11"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 4dc08bce80d27493a8a13ac24bce7011282d7cd3
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="member-access-operators--and--gt"></a>Operadores de acesso de membro:. e -&gt;
## <a name="syntax"></a>Sintaxe  
  
```  
postfix-expression . name  
postfix-expression -> name  
```  
  
## <a name="remarks"></a>Comentários  
 Os operadores de acesso de membro **.** e  **->**  são usadas para se referir a membros de classes, estruturas e uniões. As expressões de acesso do membro têm o valor e o tipo do membro selecionado.  
  
 Há duas formas de expressões de acesso do membro:  
  
1.  No primeiro formulário, *sufixo expressão* representa um valor de estrutura, classe ou tipo de união e *nome* nomes de membro a estrutura especificada, união ou classe. O valor da operação é de *nome* e é um l-value se *sufixo expressão* é um l-value.  
  
2.  No segundo formulário, *sufixo expressão* representa um ponteiro para uma, união, classe ou estrutura, e *nome* nomes de membro a estrutura especificada, união ou classe. O valor é de *nome* e é um l-value. O  **->**  operador cancelará o ponteiro. Portanto, as expressões *e*  **->**  `member` e **(\****e***)**.`member` (onde *e* representa um ponteiro) geram resultados idênticos (exceto quando os operadores  **->**  ou  **\***  estão sobrecarregados).  
  
## <a name="example"></a>Exemplo  
 O exemplo a seguir demonstra as duas formas de operador de acesso do membro.  
  
```  
// expre_Selection_Operator.cpp  
// compile with: /EHsc  
#include <iostream>  
using namespace std;  
  
struct Date {  
   Date(int i, int j, int k) : day(i), month(j), year(k){}  
   int month;  
   int day;  
   int year;  
};  
  
int main() {  
   Date mydate(1,1,1900);  
   mydate.month = 2;     
   cout  << mydate.month << "/" << mydate.day  
         << "/" << mydate.year << endl;  
  
   Date *mydate2 = new Date(1,1,2000);  
   mydate2->month = 2;  
   cout  << mydate2->month << "/" << mydate2->day  
         << "/" << mydate2->year << endl;  
   delete mydate2;  
}  
```  
  
```Output  
2/1/1900  
2/1/2000  
```  
  
## <a name="see-also"></a>Consulte também  
 [Expressões pós-fixadas](../cpp/postfix-expressions.md)   
 [Operadores C++ internos, precedência e capacidade de associação](../cpp/cpp-built-in-operators-precedence-and-associativity.md)   
 [Classes e structs](../cpp/classes-and-structs-cpp.md)   
 [Membros de união e estrutura](../c-language/structure-and-union-members.md)