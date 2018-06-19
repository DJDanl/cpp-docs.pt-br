---
title: 'hash_set:: Insert (STL/CLR) | Microsoft Docs'
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-cli
ms.topic: reference
f1_keywords:
- cliext::hash_set::insert
dev_langs:
- C++
helpviewer_keywords:
- insert member [STL/CLR]
ms.assetid: 0a9bc9aa-012e-4101-9e8c-f1f4b6b76af7
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- dotnet
ms.openlocfilehash: 9bab7d42d981cd54cd72c318f978f482a84a465b
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33129997"
---
# <a name="hashsetinsert-stlclr"></a>hash_set::insert (STL/CLR)
Adiciona elementos.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
cliext::pair<iterator, bool> insert(value_type val);  
iterator insert(iterator where, value_type val);  
template<typename InIter>  
    void insert(InIter first, InIter last);  
void insert(System::Collections::Generic::IEnumerable<value_type>^ right);  
```  
  
#### <a name="parameters"></a>Parâmetros  
 primeiro  
 Início do intervalo a ser inserido.  
  
 last  
 Fim do intervalo a ser inserido.  
  
 direita  
 Enumeração para inserir.  
  
 Val  
 Valor da chave a ser inserido.  
  
 onde  
 Onde no contêiner para inserir (dica).  
  
## <a name="remarks"></a>Comentários  
 Cada uma das funções membro insere uma sequência especificada por operandos restantes.  
  
 A primeira função de membro endeavors inserir um elemento com valor `val`e retorna um par de valores `X`. Se `X.second` for true, `X.first` designa o elemento recém-inserida; caso contrário `X.first` designa um elemento com equivalentes pedidos que já existe e nenhum elemento novo é inserido. Você pode usá-lo para inserir um único elemento.  
  
 A segunda função de membro insere um elemento com o valor `val`usando `where` como uma dica (para melhorar o desempenho) e retorna um iterador que designa o elemento recentemente inserido. Você pode usá-lo para inserir um único elemento que pode ser adjacente a um elemento que você sabe.  
  
 A terceira função do membro insere a sequência [`first`, `last`). Você pode usá-lo para inserir zero ou mais elementos copiados de outra sequência.  
  
 A função de membro quarta insere a sequência designada pelo `right`. Você pode usá-lo para inserir uma sequência descrita por um enumerador.  
  
 Cada inserção de elemento demora proporcional de logaritmo do número de elementos na sequência controlada. Inserção pode ocorrer em tempo de constante amortizado, no entanto, considerando uma dica que designa um elemento adjacente ao ponto de inserção.  
  
## <a name="example"></a>Exemplo  
  
```  
// cliext_hash_set_insert.cpp   
// compile with: /clr   
#include <cliext/hash_set>   
  
typedef cliext::hash_set<wchar_t> Myhash_set;   
typedef Myhash_set::pair_iter_bool Pairib;   
int main()   
    {   
    Myhash_set c1;   
    c1.insert(L'a');   
    c1.insert(L'b');   
    c1.insert(L'c');   
  
// display initial contents " a b c"   
    for each (wchar_t elem in c1)   
        System::Console::Write(" {0}", elem);   
    System::Console::WriteLine();   
  
// insert a single value, unique and duplicate   
    Pairib pair1 = c1.insert(L'x');   
    System::Console::WriteLine("insert(L'x') = [{0} {1}]",   
        *pair1.first, pair1.second);   
  
    pair1 = c1.insert(L'b');   
    System::Console::WriteLine("insert(L'b') = [{0} {1}]",   
        *pair1.first, pair1.second);   
  
    for each (wchar_t elem in c1)   
        System::Console::Write(" {0}", elem);   
    System::Console::WriteLine();   
  
// insert a single value with hint   
    System::Console::WriteLine("insert(begin(), L'y') = {0}",   
        *c1.insert(c1.begin(), L'y'));   
    for each (wchar_t elem in c1)   
        System::Console::Write(" {0}", elem);   
    System::Console::WriteLine();   
  
// insert an iterator range   
    Myhash_set c2;   
    Myhash_set::iterator it = c1.end();   
    c2.insert(c1.begin(), --it);   
    for each (wchar_t elem in c2)   
        System::Console::Write(" {0}", elem);   
    System::Console::WriteLine();   
  
// insert an enumeration   
    Myhash_set c3;   
    c3.insert(   // NOTE: cast is not needed   
        (System::Collections::Generic::IEnumerable<wchar_t>^)%c1);   
    for each (wchar_t elem in c3)   
        System::Console::Write(" {0}", elem);   
    System::Console::WriteLine();   
    return (0);   
    }  
  
```  
  
```Output  
 a b c  
insert(L'x') = [x True]  
insert(L'b') = [b False]  
 a b c x  
insert(begin(), L'y') = y  
 a b c x y  
 a b c x  
 a b c x y  
```  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** \<cliext/hash_set >  
  
 **Namespace:** cliext  
  
## <a name="see-also"></a>Consulte também  
 [hash_set (STL/CLR)](../dotnet/hash-set-stl-clr.md)