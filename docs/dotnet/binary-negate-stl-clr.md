---
title: "binary_negate (STL/CLR) | Microsoft Docs"
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
  - "cliext::binary_negate"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Função binary_negate [STL/CLR]"
ms.assetid: 0c3b47eb-0f37-4cb2-b879-4c9f0e57d275
caps.latest.revision: 16
caps.handback.revision: 14
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# binary_negate (STL/CLR)
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

A classe do modelo descreve um funtor que, quando chamado, retorna o NOT lógico do funtor armazenado de dois argumentos.  Use\-a especifica um objeto de função em termos de seu funtor armazenado.  
  
## Sintaxe  
  
```  
template<typename Fun>  
    ref class binary_negate  
    { // wrap operator()  
public:  
    typedef Fun stored_function_type;  
    typedef typename Fun::first_argument_type first_argument_type;  
    typedef typename Fun::second_argument_type second_argument_type;  
    typedef bool result_type;  
    typedef Microsoft::VisualC::StlClr::BinaryDelegate<  
        first_argument_type, second_argument_type, result_type>  
        delegate_type;  
  
    explicit binary_negate(Fun% functor);  
    binary_negate(binary_negate<Arg>% right);  
  
    result_type operator()(first_argument_type left,  
        second_argument_type right);  
    operator delegate_type^();  
    };  
```  
  
#### Parâmetros  
 Divertimento  
 O tipo de funtor armazenado.  
  
## Funções de membro  
  
|Definição de tipo|Descrição|  
|-----------------------|---------------|  
|delegate\_type|O tipo delegado genérico.|  
|first\_argument\_type|O tipo do primeiro argumento de funtor.|  
|result\_type|O tipo de resultado de funtor.|  
|second\_argument\_type|O tipo de argumento de funtor segundo.|  
|stored\_function\_type|O tipo de funtor.|  
  
|Membro|Descrição|  
|------------|---------------|  
|binary\_negate|Constrói o funtor.|  
  
|Operador|Descrição|  
|--------------|---------------|  
|operator\(\)|Computa a função desejada.|  
|operador delegate\_type^\(\)|Converte o funtor a um representante.|  
  
## Comentários  
 A classe do modelo descreve um funtor de dois argumentos que armazena outro funtor de dois argumentos.  Define o operador `operator()` membro de forma que, quando o objeto é chamado como uma função, retorna o NOT lógico de funtor armazenado chamado com os dois argumentos.  
  
 Você também pode passar o objeto como um argumento da função cujo tipo é `delegate_type^` e ele será convertido adequadamente.  
  
## Exemplo  
  
```  
// cliext_binary_negate.cpp   
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
    c2.push_back(4);   
    c2.push_back(4);   
    Myvector c3(2, 0);   
  
// display initial contents " 4 3" and " 4 4"   
    for each (int elem in c1)   
        System::Console::Write(" {0}", elem);   
    System::Console::WriteLine();   
  
    for each (int elem in c2)   
        System::Console::Write(" {0}", elem);   
    System::Console::WriteLine();   
  
// transform and display   
    cliext::less<int> less_op;   
  
    cliext::transform(c1.begin(), c1.begin() + 2,   
        c2.begin(), c3.begin(),   
        cliext::binary_negate<cliext::less<int> >(less_op));   
    for each (int elem in c3)   
        System::Console::Write(" {0}", elem);   
    System::Console::WriteLine();   
  
// transform and display with function   
    cliext::transform(c1.begin(), c1.begin() + 2,   
        c2.begin(), c3.begin(), cliext::not2(less_op));   
    for each (int elem in c3)   
        System::Console::Write(" {0}", elem);   
    System::Console::WriteLine();   
    return (0);   
    }  
  
```  
  
  **4 3**  
 **4 4**  
 **1 0**  
 **1 0**   
## Requisitos  
 cliext \<de**Cabeçalho:** \/funcional\>  
  
 cliext de**Namespace:**  
  
## Consulte também  
 [not2](../dotnet/not2-stl-clr.md)