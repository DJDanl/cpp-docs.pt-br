---
title: Classe binder1st | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- xfunctional/std::binder1st
- binder1st
dev_langs:
- C++
helpviewer_keywords:
- binder1st class
ms.assetid: 6b8ee343-c82f-48f8-867d-06f9d1d324c0
caps.latest.revision: 22
author: corob-msft
ms.author: corob
manager: ghogen
translation.priority.ht:
- cs-cz
- de-de
- es-es
- fr-fr
- it-it
- ja-jp
- ko-kr
- pl-pl
- pt-br
- ru-ru
- tr-tr
- zh-cn
- zh-tw
ms.translationtype: Machine Translation
ms.sourcegitcommit: 4ecf60434799708acab4726a95380a2d3b9dbb3a
ms.openlocfilehash: 4f9198d5b3f29799d38036ce4fd0dd0a67b66137
ms.contentlocale: pt-br
ms.lasthandoff: 04/19/2017

---
# <a name="binder1st-class"></a>Classe binder1st
Uma classe de modelo que fornece um construtor que converte um objeto de função binária em um objeto de função unária, associando o primeiro argumento da função binária a um valor especificado.  
  
## <a name="syntax"></a>Sintaxe  
  
```
template <class Operation>
class binder1st
    : public unaryFunction <typename Operation::second_argument_type,
                             typename Operation::result_type>
{
public:
    typedef typename Operation::argument_type argument_type;
    typedef typename Operation::result_type result_type;
    binder1st(
        const Operation& Func,
        const typename Operation::first_argument_type& left);

    result_type operator()(const argument_type& right) const;
    result_type operator()(const argument_type& right) const;

protected:
    Operation op;
    typename Operation::first_argument_type value;
};
```  
  
#### <a name="parameters"></a>Parâmetros  
 `Func`  
 O objeto de função binária a ser convertido em um objeto de função unária.  
  
 `left`  
 O valor ao qual o primeiro argumento do objeto de função binária deve ser associado.  
  
 `right`  
 O valor do argumento que o objeto binário adaptado compara ao valor fixo do segundo argumento.  
  
## <a name="return-value"></a>Valor de retorno  
 O objeto de função unária que resulta da associação do primeiro argumento do objeto de função binária ao valor `left.`  
  
## <a name="remarks"></a>Comentários  
 A classe de modelo armazena uma cópia de um objeto de função binária `Func` em **op** e uma cópia de `left` em **value**. Define sua função membro `operator()` como **op**(**value**, `right`) de retorno.  
  
 Se `Func` for um objeto do tipo **Operation** e `c` for uma constante, [bind1st](../standard-library/functional-functions.md#bind1st) (`Func`, `c`) será equivalente ao construtor `binder1st`\< **Operation**> (`Func`, `c`) da classe `binder1st` e será mais conveniente.  
  
## <a name="example"></a>Exemplo  
  
```cpp  
// functional_binder1st.cpp  
// compile with: /EHsc  
#include <vector>  
#include <functional>  
#include <algorithm>  
#include <iostream>  
  
using namespace std;  
  
int main()  
{  
    vector<int> v1;  
    vector<int>::iterator Iter;  
  
    int i;  
    for (i = 0; i <= 5; i++)  
    {  
        v1.push_back(5 * i);  
    }  
  
    cout << "The vector v1 = ( ";  
    for (Iter = v1.begin(); Iter != v1.end(); Iter++)  
        cout << *Iter << " ";  
    cout << ")" << endl;  
  
    // Count the number of integers > 10 in the vector  
    vector<int>::iterator::difference_type result1;  
    result1 = count_if(v1.begin(), v1.end(),  
        binder1st<less<int> >(less<int>(), 10));  
    cout << "The number of elements in v1 greater than 10 is: "  
         << result1 << "." << endl;  
  
    // Compare use of binder2nd fixing 2nd argument:  
    // count the number of integers < 10 in the vector  
    vector<int>::iterator::difference_type result2;  
    result2 = count_if(v1.begin(), v1.end(),  
        binder2nd<less<int> >(less<int>(), 10));  
    cout << "The number of elements in v1 less than 10 is: "  
         << result2 << "." << endl;  
}  
\* Output:   
The vector v1 = ( 0 5 10 15 20 25 )  
The number of elements in v1 greater than 10 is: 3.  
The number of elements in v1 less than 10 is: 2.  
*\  
```  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** \<functional>  
  
 **Namespace:** std  
  
## <a name="see-also"></a>Consulte também  
 [Acesso Thread-Safe na Biblioteca Padrão C++](../standard-library/thread-safety-in-the-cpp-standard-library.md)   
 [Referência da biblioteca padrão C++](../standard-library/cpp-standard-library-reference.md)




