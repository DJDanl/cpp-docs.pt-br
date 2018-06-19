---
title: 'Vector:: Vector (STL/CLR) | Microsoft Docs'
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-cli
ms.topic: reference
f1_keywords:
- cliext::vector::vector
dev_langs:
- C++
helpviewer_keywords:
- vector member [STL/CLR]
ms.assetid: a0b5e807-1ef2-422b-b772-1f96cd62fb51
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- dotnet
ms.openlocfilehash: f6921428c43ccc46b28b14523f8b17fff9185453
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33172560"
---
# <a name="vectorvector-stlclr"></a>vector::vector (STL/CLR)
Constrói um objeto contêiner.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
vector();  
vector(vector<Value>% right);  
vector(vector<Value>^ right);  
explicit vector(size_type count);  
vector(size_type count, value_type val);  
template<typename InIt>  
    vector(InIt first, InIt last);  
vector(System::Collections::Generic::IEnumerable<Value>^ right);  
```  
  
#### <a name="parameters"></a>Parâmetros  
 count  
 Número de elementos a inserir.  
  
 primeiro  
 Início do intervalo a ser inserido.  
  
 last  
 Fim do intervalo a ser inserido.  
  
 direita  
 Objeto ou intervalo a inserir.  
  
 Val  
 Valor do elemento a ser inserido.  
  
## <a name="remarks"></a>Comentários  
 O construtor:  
  
 `vector();`  
  
 inicializa a sequência controlada com nenhum elemento. Você pode usá-lo para especificar uma sequência vazia de controlado inicial.  
  
 O construtor:  
  
 `vector(vector<Value>% right);`  
  
 inicializa a sequência controlada com a sequência [`right.begin()`, `right.end()`). Você pode usá-lo para especificar uma sequência controlada inicial que é uma cópia da sequência controlada pelo objeto vector `right`.  
  
 O construtor:  
  
 `vector(vector<Value>^ right);`  
  
 inicializa a sequência controlada com a sequência [`right->begin()`, `right->end()`). Você pode usá-lo para especificar uma sequência controlada inicial que é uma cópia da sequência controlada pelo objeto vector cujo identificador é `right`.  
  
 O construtor:  
  
 `explicit vector(size_type count);`  
  
 inicializa a sequência controlada com `count` elementos com o valor `value_type()`. Você usá-lo para preencher o contêiner com elementos todos com o valor padrão.  
  
 O construtor:  
  
 `vector(size_type count, value_type val);`  
  
 inicializa a sequência controlada com `count` elementos com o valor `val`. Você usá-lo para preencher o contêiner com elementos todos com o mesmo valor.  
  
 O construtor:  
  
 `template<typename InIt>`  
  
 `vector(InIt first, InIt last);`  
  
 inicializa a sequência controlada com a sequência [`first`, `last`). Você pode usá-lo para fazer uma cópia de outra sequência de sequência controlada.  
  
 O construtor:  
  
 `vector(System::Collections::Generic::IEnumerable<Value>^ right);`  
  
 inicializa a sequência controlada com a sequência designada pelo enumerador `right`. Você pode usá-lo para fazer uma cópia de outra sequência descrita por um enumerador de sequência controlada.  
  
## <a name="example"></a>Exemplo  
  
```  
// cliext_vector_construct.cpp   
// compile with: /clr   
#include <cliext/vector>   
  
int main()   
    {   
// construct an empty container   
    cliext::vector<wchar_t> c1;   
    System::Console::WriteLine("size() = {0}", c1.size());   
  
// construct with a repetition of default values   
    cliext::vector<wchar_t> c2(3);   
    for each (wchar_t elem in c2)   
        System::Console::Write(" {0}", (int)elem);   
    System::Console::WriteLine();   
  
// construct with a repetition of values   
    cliext::vector<wchar_t> c3(6, L'x');   
    for each (wchar_t elem in c3)   
        System::Console::Write(" {0}", elem);   
    System::Console::WriteLine();   
  
// construct with an iterator range   
    cliext::vector<wchar_t>::iterator it = c3.end();   
    cliext::vector<wchar_t> c4(c3.begin(), --it);   
    for each (wchar_t elem in c4)   
        System::Console::Write(" {0}", elem);   
    System::Console::WriteLine();   
  
// construct with an enumeration   
    cliext::vector<wchar_t> c5(   // NOTE: cast is not needed   
        (System::Collections::Generic::IEnumerable<wchar_t>^)%c3);   
    for each (wchar_t elem in c5)   
        System::Console::Write(" {0}", elem);   
    System::Console::WriteLine();   
  
// construct by copying another container   
    cliext::vector<wchar_t> c7(c3);   
    for each (wchar_t elem in c7)   
        System::Console::Write(" {0}", elem);   
    System::Console::WriteLine();   
  
// construct by copying a container handle   
    cliext::vector<wchar_t> c8(%c3);   
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
 **Cabeçalho:** \<cliext/vetor >  
  
 **Namespace:** cliext  
  
## <a name="see-also"></a>Consulte também  
 [vetor (STL/CLR)](../dotnet/vector-stl-clr.md)   
 [Vector:: Assign (STL/CLR)](../dotnet/vector-assign-stl-clr.md)   
 [Vector::generic_container (STL/CLR)](../dotnet/vector-generic-container-stl-clr.md)   
 [vector::operator= (STL/CLR)](../dotnet/vector-operator-assign-stl-clr.md)