---
title: 'Vector:: Resize (STL/CLR) | Microsoft Docs'
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords: cliext::vector::resize
dev_langs: C++
helpviewer_keywords: resize member [STL/CLR]
ms.assetid: a3556fbc-67d9-463a-9ffc-cb43ee15657f
caps.latest.revision: "17"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
- dotnet
ms.openlocfilehash: 3b4fbc196f9e4ca14ee8d8e744da380e08ec4d8a
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="vectorresize-stlclr"></a>vector::resize (STL/CLR)
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
 As funções de membro ambos Certifique-se de que [Vector (STL/CLR)](../dotnet/vector-size-stl-clr.md) `()` daqui em diante retorna `new_size`. Se for necessário tornar a sequência controlada mais longa, a primeira função membro acrescentará elementos com valor `value_type()`, enquanto a segunda função membro acrescentará elementos com valor `val`. Para tornar a sequência controlada mais curto, ambas as funções de membro efetivamente apagar o último elemento [Vector (STL/CLR)](../dotnet/vector-size-stl-clr.md) `() -` `new_size` vezes. Você pode usá-lo para garantir que a sequência controlada tem tamanho `new_size`, cortar ou preenchimento atual sequência controlada.  
  
## <a name="example"></a>Exemplo  
  
```  
// cliext_vector_resize.cpp   
// compile with: /clr   
#include <cliext/vector>   
  
int main()   
    {   
// construct an empty container and pad with default values   
    cliext::vector<wchar_t> c1;   
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
 **Cabeçalho:** \<cliext/vetor >  
  
 **Namespace:** cliext  
  
## <a name="see-also"></a>Consulte também  
 [vetor (STL/CLR)](../dotnet/vector-stl-clr.md)   
 [Vector (STL/CLR)](../dotnet/vector-clear-stl-clr.md)   
 [Vector:: Erase (STL/CLR)](../dotnet/vector-erase-stl-clr.md)   
 [vector::insert (STL/CLR)](../dotnet/vector-insert-stl-clr.md)