---
title: 'set:: Count (STL/CLR) | Microsoft Docs'
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-cli
ms.topic: reference
f1_keywords:
- cliext::set::Count
dev_langs:
- C++
helpviewer_keywords:
- count member [STL/CLR]
ms.assetid: 78855f8c-3de5-4d3e-800b-0bbea5e829dd
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- dotnet
ms.openlocfilehash: 4eec1e7eaa68bf7273855a4f77e09280e2737a93
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33162776"
---
# <a name="setcount-stlclr"></a>set::count (STL/CLR)
Localiza o número de elementos que correspondem a uma chave especificada.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
size_type count(key_type key);  
```  
  
#### <a name="parameters"></a>Parâmetros  
 key  
 O valor chave a ser pesquisado.  
  
## <a name="remarks"></a>Comentários  
 A função de membro retorna o número de elementos na sequência controlada que têm uma ordenação equivalente com `key`. Usado para determinar o número de elementos que estão na sequência controlada no momento e que correspondem a uma chave especificada.  
  
## <a name="example"></a>Exemplo  
  
```  
// cliext_set_count.cpp   
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
  
    System::Console::WriteLine("count(L'A') = {0}", c1.count(L'A'));   
    System::Console::WriteLine("count(L'b') = {0}", c1.count(L'b'));   
    System::Console::WriteLine("count(L'C') = {0}", c1.count(L'C'));   
    return (0);   
    }  
  
```  
  
```Output  
 a b c  
count(L'A') = 0  
count(L'b') = 1  
count(L'C') = 0  
```  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** \<cliext/set >  
  
 **Namespace:** cliext  
  
## <a name="see-also"></a>Consulte também  
 [conjunto (STL/CLR)](../dotnet/set-stl-clr.md)   
 [set::equal_range (STL/CLR)](../dotnet/set-equal-range-stl-clr.md)