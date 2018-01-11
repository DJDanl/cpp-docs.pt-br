---
title: maior (STL/CLR) | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords: cliext::greater
dev_langs: C++
helpviewer_keywords: greater function [STL/CLR]
ms.assetid: a6dfe5e3-b5a5-4ec4-8e53-8dd33a37d10d
caps.latest.revision: "18"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
- dotnet
ms.openlocfilehash: d4940e94619807b85050c7037976e0d47b7a66f8
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="greater-stlclr"></a>greater (STL/CLR)
A classe de modelo descreve um functor que, quando chamado, retornará true somente se o primeiro argumento for maior que o segundo. Você usá-lo especificar um objeto de função em termos de seu tipo de argumento.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
template<typename Arg>  
    ref class greater  
    { // wrap operator()  
public:  
    typedef Arg first_argument_type;  
    typedef Arg second_argument_type;  
    typedef bool result_type;  
    typedef Microsoft::VisualC::StlClr::BinaryDelegate<  
        first_argument_type, second_argument_type, result_type>  
        delegate_type;  
  
    greater();  
    greater(greater<Arg>% right);  
  
    result_type operator()(first_argument_type left,  
        second_argument_type right);  
    operator delegate_type^();  
    };  
```  
  
#### <a name="parameters"></a>Parâmetros  
 Arg  
 O tipo dos argumentos.  
  
## <a name="member-functions"></a>Funções membro  
  
|Definição do tipo|Descrição|  
|---------------------|-----------------|  
|delegate_type|O tipo de delegado genérico.|  
|first_argument_type|O tipo do primeiro argumento functor.|  
|tipo_resultado|O tipo do resultado functor.|  
|second_argument_type|O tipo do segundo argumento functor.|  
  
|Membro|Descrição|  
|------------|-----------------|  
|greater|Constrói o functor.|  
  
|Operador|Descrição|  
|--------------|-----------------|  
|operator()|Calcula a função desejada.|  
|operador delegate_type ^|Converte o functor a um delegado.|  
  
## <a name="remarks"></a>Comentários  
 A classe de modelo descreve uma functor de dois argumentos. Define o operador de membro `operator()` para que, quando o objeto é chamado como uma função, ela retorna true somente se o primeiro argumento é maior que o segundo.  
  
 Você também pode passar o objeto como um argumento de função cujo tipo é `delegate_type^` e ele será convertido corretamente.  
  
## <a name="example"></a>Exemplo  
  
```  
// cliext_greater.cpp   
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
    c2.push_back(3);   
    c2.push_back(3);   
    Myvector c3(2, 0);   
  
// display initial contents " 4 3" and " 3 3"   
    for each (int elem in c1)   
        System::Console::Write(" {0}", elem);   
    System::Console::WriteLine();   
  
    for each (int elem in c2)   
        System::Console::Write(" {0}", elem);   
    System::Console::WriteLine();   
  
// transform and display   
    cliext::transform(c1.begin(), c1.begin() + 2,   
        c2.begin(), c3.begin(), cliext::greater<int>());   
    for each (int elem in c3)   
        System::Console::Write(" {0}", elem);   
    System::Console::WriteLine();   
    return (0);   
    }  
  
```  
  
```Output  
4 3  
3 3  
1 0  
```  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** \<cliext/funcional >  
  
 **Namespace:** cliext  
  
## <a name="see-also"></a>Consulte também  
 [less_equal (STL/CLR)](../dotnet/less-equal-stl-clr.md)