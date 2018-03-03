---
title: 'Vector:: Assign (STL/CLR) | Microsoft Docs'
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- cliext::vector::assign
dev_langs:
- C++
helpviewer_keywords:
- assign member [STL/CLR]
ms.assetid: 945e2048-6c61-4701-b13c-8241cbee3fa1
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
- dotnet
ms.openlocfilehash: 37f2f75e6274748cc3289dffd42e4debff96fc91
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="vectorassign-stlclr"></a>vector::assign (STL/CLR)
Substitui todos os elementos.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
void assign(size_type count, value_type val);  
template<typename InIt>  
    void assign(InIt first, InIt last);  
void assign(System::Collections::Generic::IEnumerable<Value>^ right);  
```  
  
#### <a name="parameters"></a>Parâmetros  
 count  
 Número de elementos a inserir.  
  
 primeiro  
 Início do intervalo a ser inserido.  
  
 last  
 Fim do intervalo a ser inserido.  
  
 direita  
 Enumeração para inserir.  
  
 Val  
 Valor do elemento a ser inserido.  
  
## <a name="remarks"></a>Comentários  
 A primeira função de membro substitui sequência controlada por uma repetição de `count` elementos de valor `val`. Você usá-lo para preencher o contêiner com elementos todos com o mesmo valor.  
  
 Se `InIt` é do tipo integer, a segunda função de membro se comporta como `assign((size_type)first, (value_type)last)`. Caso contrário, ele substitui a sequência controlada com a sequência [`first`, `last`). Você usá-lo para fazer o controlado de sequência de uma cópia outra sequência.  
  
 A terceira função membro substitui sequência controlada com a sequência designada pelo enumerador `right`. Você pode usá-lo para fazer uma cópia de uma sequência descrita por um enumerador de sequência controlada.  
  
## <a name="example"></a>Exemplo  
  
```  
// cliext_vector_assign.cpp   
// compile with: /clr   
#include <cliext/vector>   
  
int main()   
    {   
    cliext::vector<wchar_t> c1;   
    c1.push_back(L'a');   
    c1.push_back(L'b');   
    c1.push_back(L'c');   
  
// assign a repetition of values   
    cliext::vector<wchar_t> c2;   
    c2.assign(6, L'x');   
    for each (wchar_t elem in c2)   
        System::Console::Write(" {0}", elem);   
    System::Console::WriteLine();   
  
// assign an iterator range   
    c2.assign(c1.begin(), c1.end() - 1);   
    for each (wchar_t elem in c2)   
        System::Console::Write(" {0}", elem);   
    System::Console::WriteLine();   
  
// assign an enumeration   
    c2.assign(   // NOTE: cast is not needed   
        (System::Collections::Generic::IEnumerable<wchar_t>^)%c1);   
    for each (wchar_t elem in c2)   
        System::Console::Write(" {0}", elem);   
    System::Console::WriteLine();   
    return (0);   
    }  
  
```  
  
```Output  
x x x x x x  
a b  
a b c  
```  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** \<cliext/vetor >  
  
 **Namespace:** cliext  
  
## <a name="see-also"></a>Consulte também  
 [vetor (STL/CLR)](../dotnet/vector-stl-clr.md)   
 [vector::operator= (STL/CLR)](../dotnet/vector-operator-assign-stl-clr.md)