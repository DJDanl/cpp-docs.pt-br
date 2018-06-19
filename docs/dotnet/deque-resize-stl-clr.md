---
title: 'deque:: Resize (STL/CLR) | Microsoft Docs'
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-cli
ms.topic: reference
f1_keywords:
- cliext::deque::resize
dev_langs:
- C++
helpviewer_keywords:
- resize member [STL/CLR]
ms.assetid: c83f3c57-38b3-4706-a124-59bafbf88484
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- dotnet
ms.openlocfilehash: 0d7e68fa1a58e70d4b414f81ca826e632c8706bd
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33108875"
---
# <a name="dequeresize-stlclr"></a>deque::resize (STL/CLR)
Altera o número de elementos.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
void resize(size_type new_size);  
void resize(size_type new_size, value_type val);  
```  
  
#### <a name="parameters"></a>Parâmetros  
 new_size  
 Novo tamanho de sequência controlada.  
  
 Val  
 Valor do elemento de preenchimento.  
  
## <a name="remarks"></a>Comentários  
 As funções de membro ambos Certifique-se de que [deque (STL/CLR)](../dotnet/deque-size-stl-clr.md) `()` daqui em diante retorna `new_size`. Se for necessário tornar a sequência controlada mais longa, a primeira função membro acrescentará elementos com valor `value_type()`, enquanto a segunda função membro acrescentará elementos com valor `val`. Para tornar a sequência controlada mais curto, ambas as funções de membro efetivamente apagar o último elemento [deque (STL/CLR)](../dotnet/deque-size-stl-clr.md) `() -` `new_size` vezes. Você pode usá-lo para garantir que a sequência controlada tem tamanho `new_size`, cortar ou preenchimento atual sequência controlada.  
  
## <a name="example"></a>Exemplo  
  
```  
// cliext_deque_resize.cpp   
// compile with: /clr   
#include <cliext/deque>   
  
int main()   
    {   
// construct an empty container and pad with default values   
    cliext::deque<wchar_t> c1;   
    System::Console::WriteLine("size() = {0}", c1.size());   
    c1.resize(4);   
    for each (wchar_t elem in c1)   
        System::Console::Write(" {0}", (int)elem);   
    System::Console::WriteLine();   
  
// resize to empty   
    c1.resize(0);   
    System::Console::WriteLine("size() = {0}", c1.size());   
  
// resize and pad   
    c1.resize(5, L'x');   
    for each (wchar_t elem in c1)   
        System::Console::Write(" {0}", elem);   
    System::Console::WriteLine();   
    return (0);   
    }  
  
```  
  
```Output  
size() = 0  
 0 0 0 0  
size() = 0  
 x x x x x  
```  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** \<cliext/deque >  
  
 **Namespace:** cliext  
  
## <a name="see-also"></a>Consulte também  
 [deque (STL/CLR)](../dotnet/deque-stl-clr.md)   
 [deque:: Clear (STL/CLR)](../dotnet/deque-clear-stl-clr.md)   
 [deque (STL/CLR)](../dotnet/deque-erase-stl-clr.md)   
 [deque::insert (STL/CLR)](../dotnet/deque-insert-stl-clr.md)