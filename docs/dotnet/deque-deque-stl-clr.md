---
title: 'deque:: deque (STL/CLR) | Microsoft Docs'
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-cli
ms.topic: reference
f1_keywords:
- cliext::deque::deque
dev_langs:
- C++
helpviewer_keywords:
- deque member [STL/CLR]
ms.assetid: e5bc9511-619e-469c-b50a-e06858e7fce7
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- dotnet
ms.openlocfilehash: 433b6ff053db0c642c2a81a5765755c9f42e1a0d
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33112115"
---
# <a name="dequedeque-stlclr"></a>deque::deque (STL/CLR)
Constrói um objeto contêiner.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
deque();  
deque(deque<Value>% right);  
deque(deque<Value>^ right);  
explicit deque(size_type count);  
deque(size_type count, value_type val);  
template<typename InIt>  
    deque(InIt first, InIt last);  
deque(System::Collections::Generic::IEnumerable<Value>^ right);  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `count`  
 Número de elementos a inserir.  
  
 `first`  
 Início do intervalo a ser inserido.  
  
 `last`  
 Fim do intervalo a ser inserido.  
  
 `right`  
 Objeto ou intervalo a inserir.  
  
 `val`  
 Valor do elemento a ser inserido.  
  
## <a name="remarks"></a>Comentários  
 O construtor:  
  
 `deque();`  
  
 inicializa a sequência controlada com nenhum elemento. Você pode usá-lo para especificar uma sequência vazia de controlado inicial.  
  
 O construtor:  
  
 `deque(deque<Value>% right);`  
  
 inicializa a sequência controlada com a sequência [`right.begin()`, `right.end()`). Você pode usá-lo para especificar uma sequência controlada inicial que é uma cópia da sequência controlada pelo objeto deque `right`. Para obter mais informações sobre os iteradores, consulte [deque (STL/CLR)](../dotnet/deque-begin-stl-clr.md) e [deque:: end (STL/CLR)](../dotnet/deque-end-stl-clr.md).  
  
 O construtor:  
  
 `deque(deque<Value>^ right);`  
  
 inicializa a sequência controlada com a sequência [`right->begin()`, `right->end()`). Você pode usá-lo para especificar uma sequência controlada inicial que é uma cópia da sequência controlada pelo objeto deque cujo identificador é `right`.  
  
 O construtor:  
  
 `explicit deque(size_type count);`  
  
 inicializa a sequência controlada com `count` elementos com o valor `value_type()`. Você usá-lo para preencher o contêiner com elementos todos com o valor padrão.  
  
 O construtor:  
  
 `deque(size_type count, value_type val);`  
  
 inicializa a sequência controlada com `count` elementos com o valor `val`. Você usá-lo para preencher o contêiner com elementos todos com o mesmo valor.  
  
 O construtor:  
  
 `template<typename InIt>`  
  
 `deque(InIt first, InIt last);`  
  
 inicializa a sequência controlada com a sequência [`first`, `last`). Você pode usá-lo para fazer uma cópia de outra sequência de sequência controlada.  
  
 O construtor:  
  
 `deque(System::Collections::Generic::IEnumerable<Value>^ right);`  
  
 inicializa a sequência controlada com a sequência designada pelo enumerador `right`. Você pode usá-lo para fazer uma cópia de outra sequência descrita por um enumerador de sequência controlada.  
  
## <a name="example"></a>Exemplo  
  
```cpp  
// cliext_deque_construct.cpp   
// compile with: /clr   
#include <cliext/deque>   
  
int main()   
    {   
// construct an empty container   
    cliext::deque<wchar_t> c1;   
    System::Console::WriteLine("size() = {0}", c1.size());   
  
// construct with a repetition of default values   
    cliext::deque<wchar_t> c2(3);   
    for each (wchar_t elem in c2)   
        System::Console::Write(" {0}", (int)elem);   
    System::Console::WriteLine();   
  
// construct with a repetition of values   
    cliext::deque<wchar_t> c3(6, L'x');   
    for each (wchar_t elem in c3)   
        System::Console::Write(" {0}", elem);   
    System::Console::WriteLine();   
  
// construct with an iterator range   
    cliext::deque<wchar_t>::iterator it = c3.end();   
    cliext::deque<wchar_t> c4(c3.begin(), --it);   
    for each (wchar_t elem in c4)   
        System::Console::Write(" {0}", elem);   
    System::Console::WriteLine();   
  
// construct with an enumeration   
    cliext::deque<wchar_t> c5(   // NOTE: cast is not needed   
        (System::Collections::Generic::IEnumerable<wchar_t>^)%c3);   
    for each (wchar_t elem in c5)   
        System::Console::Write(" {0}", elem);   
    System::Console::WriteLine();   
  
// construct by copying another container   
    cliext::deque<wchar_t> c7(c3);   
    for each (wchar_t elem in c7)   
        System::Console::Write(" {0}", elem);   
    System::Console::WriteLine();   
  
// construct by copying a container handle   
    cliext::deque<wchar_t> c8(%c3);   
    for each (wchar_t elem in c8)   
        System::Console::Write(" {0}", elem);   
    System::Console::WriteLine();   
  
    return (0);   
    }  
  
```  
  
```Output  
size() = 0  
 0 0 0  
 x x x x x x  
 x x x x x  
 x x x x x x  
 x x x x x x  
 x x x x x x  
```  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** \<cliext/deque >  
  
 **Namespace:** cliext  
  
## <a name="see-also"></a>Consulte também  
 [deque (STL/CLR)](../dotnet/deque-stl-clr.md)   
 [Assign (STL/CLR)](../dotnet/deque-assign-stl-clr.md)   
 [deque::generic_container (STL/CLR)](../dotnet/deque-generic-container-stl-clr.md)   
 [operator= (deque) (STL/CLR)](../dotnet/operator-assign-deque-stl-clr.md)