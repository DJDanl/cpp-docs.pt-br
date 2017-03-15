---
title: "plus (STL/CLR) | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "reference"
f1_keywords: 
  - "cliext::plus"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "função plus [STL/CLR]"
ms.assetid: 7ec8228a-72c7-4e47-9e63-23525d4a5416
caps.latest.revision: 16
caps.handback.revision: 14
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# plus (STL/CLR)
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

A classe do modelo descreve um funtor que, quando chamado, retorna o primeiro argumento mais o segundo.  Use\-a especifica um objeto de função em termos de seu tipo de argumento.  
  
## Sintaxe  
  
```  
template<typename Arg>  
    ref class plus  
    { // wrap operator()  
public:  
    typedef Arg first_argument_type;  
    typedef Arg second_argument_type;  
    typedef Arg result_type;  
    typedef Microsoft::VisualC::StlClr::BinaryDelegate<  
        first_argument_type, second_argument_type, result_type>  
        delegate_type;  
  
    plus();  
    plus(plus<Arg>% right);  
  
    result_type operator()(first_argument_type left,  
        second_argument_type right);  
    operator delegate_type^();  
    };  
```  
  
#### Parâmetros  
 Arg  
 O tipo dos argumentos e o valor de retorno.  
  
## Funções de membro  
  
|Definição de tipo|Descrição|  
|-----------------------|---------------|  
|delegate\_type|O tipo delegado genérico.|  
|first\_argument\_type|O tipo do primeiro argumento de funtor.|  
|result\_type|O tipo de resultado de funtor.|  
|second\_argument\_type|O tipo de argumento de funtor segundo.|  
  
|Membro|Descrição|  
|------------|---------------|  
|positivo|Constrói o funtor.|  
  
|Operador|Descrição|  
|--------------|---------------|  
|operator\(\)|Computa a função desejada.|  
|delegate\_type^ do operador|Converte o funtor a um representante.|  
  
## Comentários  
 A classe do modelo descreve um funtor de dois argumentos.  Define o operador `operator()` membro de forma que, quando o objeto é chamado como uma função, retorna o primeiro argumento mais o segundo.  
  
 Você também pode passar o objeto como um argumento da função cujo tipo é `delegate_type^` e ele será convertido adequadamente.  
  
## Exemplo  
  
```  
// cliext_plus.cpp   
// compile with: /clr   
#include <cliext/algorithm>   
#include <cliext/functional>   
#include <cliext/vector>   
  
typedef cliext::vector<int> Myvector;   
int main()   
    {   
    Myvector c1;   
    c1.push_back(4);   
    c1.push_back(3);   
    Myvector c2;   
    c2.push_back(2);   
    c2.push_back(1);   
    Myvector c3(2, 0);   
  
// display initial contents " 4 3" and " 2 1"   
    for each (int elem in c1)   
        System::Console::Write(" {0}", elem);   
    System::Console::WriteLine();   
  
    for each (int elem in c2)   
        System::Console::Write(" {0}", elem);   
    System::Console::WriteLine();   
  
// transform and display   
    cliext::transform(c1.begin(), c1.begin() + 2,   
        c2.begin(), c3.begin(), cliext::plus<int>());   
    for each (int elem in c3)   
        System::Console::Write(" {0}", elem);   
    System::Console::WriteLine();   
    return (0);   
    }  
  
```  
  
  **4 3**  
 **2 1**  
 **6 4**   
## Requisitos  
 cliext \<de**Cabeçalho:** \/funcional\>  
  
 cliext de**Namespace:**  
  
## Consulte também  
 [minus](../dotnet/minus-stl-clr.md)