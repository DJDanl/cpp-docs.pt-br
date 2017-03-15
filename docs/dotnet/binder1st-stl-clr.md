---
title: "binder1st (STL/CLR) | Microsoft Docs"
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
  - "cliext::binder1st"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Função binder1st [STL/CLR]"
ms.assetid: a989c9cc-a485-45d9-bd19-519018e6974b
caps.latest.revision: 18
caps.handback.revision: 16
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# binder1st (STL/CLR)
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

A classe do modelo descreve um funtor de um argumento que, quando chamado, retorne seu funtor armazenado de dois argumentos chamado com seu primeiro argumento armazenado e o segundo argumento fornecido.  Use\-a especifica um objeto de função em termos de seu funtor armazenado.  
  
## Sintaxe  
  
```  
template<typename Fun>  
    ref class binder1st  
    { // wrap operator()  
public:  
    typedef Fun stored_function_type;  
    typedef typename Fun::first_argument_type first_argument_type;  
    typedef typename Fun::second_argument_type second_argument_type;  
    typedef typename Fun:result_type result_type;  
    typedef Microsoft::VisualC::StlClr::UnaryDelegate<  
        second_argument_type, result_type>  
        delegate_type;  
  
    binder1st(Fun% functor, first_argument_type left);  
    binder1st(binder1st<Arg>% right);  
  
    result_type operator()(second_argument_type right);  
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
|binder1st|Constrói o funtor.|  
  
|Operador|Descrição|  
|--------------|---------------|  
|operator\(\)|Computa a função desejada.|  
|operador delegate\_type^\(\)|Converte o funtor a um representante.|  
  
## Comentários  
 A classe do modelo descreve um funtor de um argumento que armazena um funtor de dois argumentos e um primeiro argumento.  Define o operador `operator()` membro de forma que, quando o objeto é chamado como uma função, retorna o resultado do funtor armazenado com o primeiro argumento armazenado e o segundo argumento fornecido.  
  
 Você também pode passar o objeto como um argumento da função cujo tipo é `delegate_type^` e ele será convertido adequadamente.  
  
## Exemplo  
  
```  
// cliext_binder1st.cpp   
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
    Myvector c3(2, 0);   
  
// display initial contents " 4 3"   
    for each (int elem in c1)   
        System::Console::Write(" {0}", elem);   
    System::Console::WriteLine();   
  
// transform and display   
    cliext::minus<int> sub_op;   
    cliext::binder1st<cliext::minus<int> > subfrom3(sub_op, 3);   
  
    cliext::transform(c1.begin(), c1.begin() + 2, c3.begin(),   
        subfrom3);   
    for each (int elem in c3)   
        System::Console::Write(" {0}", elem);   
    System::Console::WriteLine();   
  
// transform and display with function   
    cliext::transform(c1.begin(), c1.begin() + 2, c3.begin(),   
        bind1st(sub_op, 3));   
    for each (int elem in c3)   
        System::Console::Write(" {0}", elem);   
    System::Console::WriteLine();   
    return (0);   
    }  
  
```  
  
  **4 3**  
 **\-1 0**  
 **\-1 0**   
## Requisitos  
 cliext \<de**Cabeçalho:** \/funcional\>  
  
 cliext de**Namespace:**  
  
## Consulte também  
 [bind1st](../dotnet/bind1st-stl-clr.md)