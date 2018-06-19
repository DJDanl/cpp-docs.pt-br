---
title: 'set:: swap (STL/CLR) | Microsoft Docs'
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-cli
ms.topic: reference
f1_keywords:
- cliext::set::swap
dev_langs:
- C++
helpviewer_keywords:
- swap member [STL/CLR]
ms.assetid: c1733a77-d23f-44cb-b038-f1893a6fe6b1
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- dotnet
ms.openlocfilehash: 6d7c05c56767fdd9b058b62d35bf218905c06418
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33171345"
---
# <a name="setswap-stlclr"></a>set::swap (STL/CLR)
Alterna o conteúdo de dois contêineres.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
void swap(set<Key>% right);  
```  
  
#### <a name="parameters"></a>Parâmetros  
 direita  
 Contêiner com o qual trocar conteúdos.  
  
## <a name="remarks"></a>Comentários  
 A função membro troca as sequências controladas entre `this` e `right`. Isso é feito no tempo constante e ele não lança exceções. Você pode usá-lo como uma maneira rápida de trocar o conteúdo de dois contêineres.  
  
## <a name="example"></a>Exemplo  
  
```  
// cliext_set_swap.cpp   
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
  
// construct another container with repetition of values   
    Myset c2;   
    c2.insert(L'd');   
    c2.insert(L'e');   
    c2.insert(L'f');   
    for each (wchar_t elem in c2)   
        System::Console::Write(" {0}", elem);   
    System::Console::WriteLine();   
  
// swap and redisplay   
    c1.swap(c2);   
    for each (wchar_t elem in c1)   
        System::Console::Write(" {0}", elem);   
    System::Console::WriteLine();   
  
    for each (wchar_t elem in c2)   
        System::Console::Write(" {0}", elem);   
    System::Console::WriteLine();   
    return (0);   
    }  
  
```  
  
```Output  
a b c  
d e f  
d e f  
a b c  
```  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** \<cliext/set >  
  
 **Namespace:** cliext  
  
## <a name="see-also"></a>Consulte também  
 [conjunto (STL/CLR)](../dotnet/set-stl-clr.md)   
 [set::operator= (STL/CLR)](../dotnet/set-operator-assign-stl-clr.md)