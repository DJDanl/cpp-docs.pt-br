---
title: "Classe binder1st | Microsoft Docs"
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
  - "xfunctional/std::binder1st"
  - "std::binder1st"
  - "binder1st"
  - "std.binder1st"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe binder1st"
ms.assetid: 6b8ee343-c82f-48f8-867d-06f9d1d324c0
caps.latest.revision: 22
caps.handback.revision: 16
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Classe binder1st
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Uma classe do modelo que fornece um construtor que converte um objeto binário da função em um objeto unário da função associando o primeiro argumento da função binário a um valor especificado.  
  
## Sintaxe  
  
```  
template<class Operation>  
class binder1st  
   : public unary_function <  
      typename Operation::second_argument_type,  
      typename Operation::result_type>   
  {  
   public:  
   typedef typename Operation::argument_type argument_type;  
   typedef typename Operation::result_type result_type;  
   binder1st(  
      const Operation & _Func,  
      const typename Operation::first_argument_type& _Left  
   );  
   result_type operator()(  
      const argument_type& _Right  
   ) const;  
   result_type operator()(  
      const argument_type& _Right  
   ) const;  
   protected:  
   Operation op;  
   typename Operation::first_argument_type value;  
   };  
```  
  
#### Parâmetros  
 `_Func`  
 O objeto binário da função a ser convertido em um objeto unário da função.  
  
 `_Left`  
 O valor para o qual o primeiro argumento de objeto binário da função deve ser associado.  
  
 `_Right`  
 O valor do argumento que o objeto binário adaptado compara o valor fixo de segundo argumento.  
  
## Valor de retorno  
 O objeto unário de função que resulta da associação o primeiro argumento de objeto binário da função ao valor `_Left.`  
  
## Comentários  
 A classe do modelo armazena uma cópia de um objeto binário `_Func` da função em **op**, e uma cópia de `_Left` em **value**.  Define sua função de membro `operator()` como retornar **op**\(**value**, `_Right`\).  
  
 Se `_Func` é um objeto de tipo **Operação** e `c` é uma constante, então [bind1st](../Topic/bind1st%20Function.md) \( `_Func`, `c` \) é equivalente ao construtor `binder1st`\<**Operação**\> da classe de `binder1st` \( `_Func`, `c` \) e mais conveniente.  
  
## Exemplo  
  
```  
// functional_binder1st.cpp  
// compile with: /EHsc  
#include <vector>  
#include <functional>  
#include <algorithm>  
#include <iostream>  
  
using namespace std;  
  
int main()  
{  
    vector<int> v1;  
    vector<int>::iterator Iter;  
  
    int i;  
    for (i = 0; i <= 5; i++)  
    {  
        v1.push_back(5 * i);  
    }  
  
    cout << "The vector v1 = ( ";  
    for (Iter = v1.begin(); Iter != v1.end(); Iter++)  
        cout << *Iter << " ";  
    cout << ")" << endl;  
  
    // Count the number of integers > 10 in the vector  
    vector<int>::iterator::difference_type result1;  
    result1 = count_if(v1.begin(), v1.end(),  
        binder1st<less<int> >(less<int>(), 10));  
    cout << "The number of elements in v1 greater than 10 is: "  
         << result1 << "." << endl;  
  
    // Compare use of binder2nd fixing 2nd argument:  
    // count the number of integers < 10 in the vector  
    vector<int>::iterator::difference_type result2;  
    result2 = count_if(v1.begin(), v1.end(),  
        binder2nd<less<int> >(less<int>(), 10));  
    cout << "The number of elements in v1 less than 10 is: "  
         << result2 << "." << endl;  
}  
```  
  
  **O vetor v1 \= \(0 5 10 15 20 25\)**  
**O número de elementos em v1 maior que 10 é: 3.**  
**O número de elementos em v1 menos de 10 é: 2.**   
## Requisitos  
 **Cabeçalho:** \<funcional\>  
  
 **Namespace:** std  
  
## Consulte também  
 [Segurança de threads na Biblioteca Padrão C\+\+](../standard-library/thread-safety-in-the-cpp-standard-library.md)   
 [Biblioteca de Modelos Padrão](../misc/standard-template-library.md)