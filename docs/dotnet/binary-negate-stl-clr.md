---
title: binary_negate (STL/CLR) | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.reviewer: ''
ms.suite: ''
ms.technology:
- cpp-windows
ms.tgt_pltfrm: ''
ms.topic: reference
f1_keywords:
- cliext::binary_negate
dev_langs:
- C++
helpviewer_keywords:
- binary_negate function [STL/CLR]
ms.assetid: 0c3b47eb-0f37-4cb2-b879-4c9f0e57d275
caps.latest.revision: 16
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
- dotnet
ms.openlocfilehash: 3780c89c178c0c71f3388d2bd846ed7d52af3ceb
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="binarynegate-stlclr"></a>binary_negate (STL/CLR)
A classe de modelo descreve um functor que, quando chamado, retorna a lógica não é de sua armazenado functor de dois argumentos. Você usá-lo especificar um objeto de função em termos de seu functor armazenado.  
  
## <a name="syntax"></a>Sintaxe  
  
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
  
#### <a name="parameters"></a>Parâmetros  
 Fun  
 O tipo de functor armazenado.  
  
## <a name="member-functions"></a>Funções membro  
  
|Definição do tipo|Descrição|  
|---------------------|-----------------|  
|delegate_type|O tipo de delegado genérico.|  
|first_argument_type|O tipo do primeiro argumento functor.|  
|tipo_resultado|O tipo do resultado functor.|  
|second_argument_type|O tipo do segundo argumento functor.|  
|stored_function_type|O tipo de functor.|  
  
|Membro|Descrição|  
|------------|-----------------|  
|binary_negate|Constrói o functor.|  
  
|Operador|Descrição|  
|--------------|-----------------|  
|operator()|Calcula a função desejada.|  
|operador delegate_type^()|Converte o functor a um delegado.|  
  
## <a name="remarks"></a>Comentários  
 A classe de modelo descreve uma functor de dois argumentos que armazena a outro functor de dois argumentos. Define o operador de membro `operator()` para que, quando o objeto é chamado como uma função, ele retorna lógico não do functor armazenado chamado com dois argumentos.  
  
 Você também pode passar o objeto como um argumento de função cujo tipo é `delegate_type^` e ele será convertido corretamente.  
  
## <a name="example"></a>Exemplo  
  
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
  
```Output  
4 3  
4 4  
1 0  
1 0  
```  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** \<cliext/funcional >  
  
 **Namespace:** cliext  
  
## <a name="see-also"></a>Consulte também  
 [not2 (STL/CLR)](../dotnet/not2-stl-clr.md)