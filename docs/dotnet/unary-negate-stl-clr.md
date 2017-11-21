---
title: unary_negate (STL/CLR) | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords: cliext::unary_negate
dev_langs: C++
helpviewer_keywords: unary_negate function [STL/CLR]
ms.assetid: 83bbdd86-199c-4451-9f70-72f9ade2264a
caps.latest.revision: "17"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.openlocfilehash: 530a75cdebd5799e8c46fd6f8ae1f40d4f785ba6
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
---
# <a name="unarynegate-stlclr"></a>unary_negate (STL/CLR)
A classe de modelo descreve um functor que, quando chamado, retorna a lógica não é de sua functor armazenado de um argumento. Você usá-lo especificar um objeto de função em termos de seu functor armazenado.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
template<typename Fun>  
    ref class unary_negate  
    { // wrap operator()  
public:  
    typedef Fun stored_function_type;  
    typedef typename Fun::argument_type argument_type;  
    typedef bool result_type;  
    typedef Microsoft::VisualC::StlClr::UnaryDelegate<  
        argument_type, result_type>  
        delegate_type;  
  
    unary_negate(Fun% functor);  
    unary_negate(unary_negate<Fun>% right);  
  
    result_type operator()(argument_type left);  
    operator delegate_type^();  
    };  
```  
  
#### <a name="parameters"></a>Parâmetros  
 Fun  
 O tipo de functor armazenado.  
  
## <a name="member-functions"></a>Funções membro  
  
|Definição do tipo|Descrição|  
|---------------------|-----------------|  
|argument_type|O tipo do argumento functor.|  
|delegate_type|O tipo de delegado genérico.|  
|tipo_resultado|O tipo do resultado functor.|  
  
|Membro|Descrição|  
|------------|-----------------|  
|unary_negate|Constrói o functor.|  
  
|Operador|Descrição|  
|--------------|-----------------|  
|operator()|Calcula a função desejada.|  
|delegate_type ^|Converte o functor a um delegado.|  
  
## <a name="remarks"></a>Comentários  
 A classe de modelo descreve um functor um argumento que armazena a outro functor de um argumento. Define o operador de membro `operator()` para que, quando o objeto é chamado como uma função, ele retorna lógico não do functor armazenado chamado com o argumento.  
  
 Você também pode passar o objeto como um argumento de função cujo tipo é `delegate_type^` e ele será convertido corretamente.  
  
## <a name="example"></a>Exemplo  
  
```  
// cliext_unary_negate.cpp   
// compile with: /clr   
#include <cliext/algorithm>   
#include <cliext/functional>   
#include <cliext/vector>   
  
typedef cliext::vector<int> Myvector;   
int main()   
    {   
    Myvector c1;   
    c1.push_back(4);   
    c1.push_back(0);   
    Myvector c3(2, 0);   
  
// display initial contents " 4 0"   
    for each (int elem in c1)   
        System::Console::Write(" {0}", elem);   
    System::Console::WriteLine();   
  
// transform and display   
    cliext::logical_not<int> not_op;   
  
    cliext::transform(c1.begin(), c1.begin() + 2, c3.begin(),   
        cliext::unary_negate<cliext::logical_not<int> >(not_op));   
    for each (int elem in c3)   
        System::Console::Write(" {0}", elem);   
    System::Console::WriteLine();   
  
// transform and display with function   
    cliext::transform(c1.begin(), c1.begin() + 2, c3.begin(),   
        cliext::not1(not_op));   
    for each (int elem in c3)   
        System::Console::Write(" {0}", elem);   
    System::Console::WriteLine();   
    return (0);   
    }  
  
```  
  
```Output  
4 0  
1 0  
1 0  
```  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** \<cliext/funcional >  
  
 **Namespace:** cliext  
  
## <a name="see-also"></a>Consulte também  
 [not1 (STL/CLR)](../dotnet/not1-stl-clr.md)