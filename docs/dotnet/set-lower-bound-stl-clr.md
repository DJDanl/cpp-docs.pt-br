---
title: 'set:: lower_bound (STL/CLR) | Microsoft Docs'
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-cli
ms.topic: reference
f1_keywords:
- cliext::set::lower_bound
dev_langs:
- C++
helpviewer_keywords:
- lower_bound member [STL/CLR]
ms.assetid: d4da5b8b-ddf2-4d36-8092-f1be81b42348
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- dotnet
ms.openlocfilehash: 3e5c455291f6b109ff117503739d6022aab87fd7
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="setlowerbound-stlclr"></a>set::lower_bound (STL/CLR)
Localiza o início do intervalo que corresponde a uma chave especificada.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
iterator lower_bound(key_type key);  
```  
  
#### <a name="parameters"></a>Parâmetros  
 key  
 O valor chave a ser pesquisado.  
  
## <a name="remarks"></a>Comentários  
 A função de membro determina o primeiro elemento `X` na sequência controlada que tem o equivalente a ordenação para `key`. Se esse elemento não existe, ele retorna [set:: end (STL/CLR)](../dotnet/set-end-stl-clr.md)`()`; caso contrário, ele retorna um iterador que designa `X`. Você pode usá-lo para localizar o início de uma sequência de elementos no momento na sequência controlada que correspondem a uma chave especificada.  
  
## <a name="example"></a>Exemplo  
  
```  
// cliext_set_lower_bound.cpp   
// compile with: /clr   
#include <cliext/set>   
  
typedef cliext::set<wchar_t> Myset;   
int main()   
    {   
    Myset c1;   
    c1.insert(L'a');   
    c1.insert(L'b');   
    c1.insert(L'c');   
  
// display initial contents " a b c"   
    for each (wchar_t elem in c1)   
        System::Console::Write(" {0}", elem);   
    System::Console::WriteLine();   
  
    System::Console::WriteLine("lower_bound(L'x')==end() = {0}",   
        c1.lower_bound(L'x') == c1.end());   
  
    System::Console::WriteLine("*lower_bound(L'a') = {0}",   
        *c1.lower_bound(L'a'));   
    System::Console::WriteLine("*lower_bound(L'b') = {0}",   
        *c1.lower_bound(L'b'));   
    return (0);   
    }  
  
```  
  
```Output  
 a b c  
lower_bound(L'x')==end() = True  
*lower_bound(L'a') = a  
*lower_bound(L'b') = b  
```  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** \<cliext/set >  
  
 **Namespace:** cliext  
  
## <a name="see-also"></a>Consulte também  
 [conjunto (STL/CLR)](../dotnet/set-stl-clr.md)   
 [set:: Count (STL/CLR)](../dotnet/set-count-stl-clr.md)   
 [set:: equal_range (STL/CLR)](../dotnet/set-equal-range-stl-clr.md)   
 [set:: Find (STL/CLR)](../dotnet/set-find-stl-clr.md)   
 [set::upper_bound (STL/CLR)](../dotnet/set-upper-bound-stl-clr.md)