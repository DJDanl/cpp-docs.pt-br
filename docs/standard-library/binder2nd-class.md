---
title: "Classe binder2nd | Microsoft Docs"
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
  - "std.binder2nd"
  - "binder2nd"
  - "xfunctional/std::binder2nd"
  - "std::binder2nd"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe binder2nd"
ms.assetid: b2a9c1d1-dfc4-4ca9-a10e-ae84e195a62d
caps.latest.revision: 22
caps.handback.revision: 16
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Classe binder2nd
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Uma classe do modelo que fornece um construtor que converte um objeto binário da função em um objeto unário da função associando o segundo argumento da função binário a um valor especificado.  
  
## Sintaxe  
  
```  
template<class Operation>  
   class binder2nd  
      : public unary_function <  
         typename Operation::first_argument_type,  
         typename Operation::result_type>   
   {  
   public:  
   typedef typename Operation::argument_type argument_type;  
   typedef typename Operation::result_type result_type;  
   binder2nd(  
      const Operation& _Func,  
      const typename Operation::second_argument_type& _Right  
   );  
   result_type operator()(  
      const argument_type& _Left  
   ) const;  
   result_type operator()(  
      argument_type& _Left  
   ) const;  
   protected:  
   Operation op;  
   typename Operation::second_argument_type value;  
   };  
```  
  
#### Parâmetros  
 `_Func`  
 O objeto binário da função a ser convertido em um objeto unário da função.  
  
 `_Right`  
 O valor para o qual o segundo argumento de objeto binário da função deve ser associado.  
  
 `_Left`  
 O valor do argumento que o objeto binário adaptado compara o valor fixo de segundo argumento.  
  
## Valor de retorno  
 O objeto unário de função que resulta da associação o segundo argumento de objeto binário da função ao valor `_Right.`  
  
## Comentários  
 A classe do modelo armazena uma cópia de um objeto de função binário \_*Func* em **op**, e uma cópia de `_Right` em **value**.  Define sua função de membro `operator()` como retornar **op**\(`_Left`, **value**\).  
  
 Se `_Func` é um objeto de tipo **Operação** e c é uma constante, então [bind2nd](../Topic/bind2nd%20Function.md) \( `_Func`, `c` \) é equivalente ao construtor `binder2nd`\<**Operação**\> da classe de `binder2nd` \( `_Func`, `c` \) e mais conveniente.  
  
## Exemplo  
  
```  
// functional_binder2nd.cpp  
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
        binder2nd<greater<int> >(greater<int>(), 10));  
    cout << "The number of elements in v1 greater than 10 is: "  
         << result1 << "." << endl;  
  
    // Compare using binder1st fixing 1st argument:  
    // count the number of integers < 10 in the vector  
    vector<int>::iterator::difference_type result2;  
    result2 = count_if(v1.begin(), v1.end(),  
        binder1st<greater<int> >(greater<int>(), 10));  
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