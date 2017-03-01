---
title: Classe gslice_array | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- std::gslice_array
- gslice_array
- valarray/std::gslice_array
- std.gslice_array
dev_langs:
- C++
helpviewer_keywords:
- gslice_array class
ms.assetid: ad1b4514-b14a-4baf-a293-d5a8e8674c75
caps.latest.revision: 20
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
translationtype: Machine Translation
ms.sourcegitcommit: 3168772cbb7e8127523bc2fc2da5cc9b4f59beb8
ms.openlocfilehash: ae8f5df6cf27fb3b1ec70041de356ed67ef5557a
ms.lasthandoff: 02/25/2017

---
# <a name="gslicearray-class"></a>Classe gslice_array
Uma classe de modelo auxiliar interna, que dá suporte a objetos de fatia geral fornecendo operações entre matrizes de subconjunto definidas pela fatia geral de um valarray.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
template <class Type>  
class gslice_array : public gsplice {  
public:  
    typedef Type value_type;  
    void operator=(const valarray<Type>& x) const;

 
 
    void operator=(const Type& x) const;

 
 
    void operator*=(const valarray<Type>& x) const;

 
 
    void operator/=(const valarray<Type>& x) const;

 
 
    void operator%=(const valarray<Type>& x) const;

 
 
    void operator+=(const valarray<Type>& x) const;

 
 
    void operator-=(const valarray<Type>& x) const;

 
 
    void operator^=(const valarray<Type>& x) const;

 
 
    void operator&=(const valarray<Type>& x) const;

 
 
    void operator|=(const valarray<Type>& x) const;

 
 
    void operator<<=(const valarray<Type>& x) const;

 
 
    void operator>>=(const valarray<Type>& x) const;

 
 
// The rest is private or implementation defined  
}  
```  
  
## <a name="remarks"></a>Comentários  
 A classe descreve um objeto que armazena uma referência a um objeto **va** da classe [valarray](../standard-library/valarray-class.md)**\<Tipo>**, bem como um objeto **gs** da classe [gslice](../standard-library/gslice-class.md), que descreve a sequência de elementos a serem selecionados do objeto **valarray\<Tipo>**.  
  
 Você constrói um objeto **gslice_array\<Tipo>** apenas escrevendo uma expressão no formato [va&#91;gs&#93;](../standard-library/valarray-class.md#valarray__operator_at). As funções membro da classe gslice_array, então, se comportam como as assinaturas de função correspondentes definidas para **valarray\<Tipo>**, exceto pelo fato de somente a sequência de elementos selecionados ser afetada.  
  
 A classe de modelo é criada indiretamente por determinadas operações de valarray e não pode ser usada diretamente no programa. Em vez disso, uma classe de modelo auxiliar interna é usada pelo operador de subscrito da fatia:  
  
 `gslice_array`\< **Tipo**> `valarray`\< **Tipo**>:: `operator[]` ( **constgslice&**).  
  
 Você constrói um objeto **gslice_array\<Tipo>** apenas escrevendo uma expressão no formato **va[gsl]**, para uma fatia **gsl** do valarray **va**. As funções membro da classe gslice_array, então, se comportam como as assinaturas de função correspondentes definidas para **valarray\<Tipo>**, exceto pelo fato de somente a sequência de elementos selecionados ser afetada. A sequência controlada por gslice_array é definida pelos três parâmetros do construtor de fatia, o índice do primeiro elemento na primeira fatia, o número de elementos em cada fatia e a distância entre os elementos de cada fatia.  
  
 No exemplo a seguir:  
  
```  
const size_t lv[] = {2, 3};  
const size_t dv[] = {7, 2};  
const valarray<size_t> len(lv, 2), str(dv, 2);

// va[gslice(3, len, str)] selects elements with  
//   indices 3, 5, 7, 10, 12, 14  
```  
  
 Os índices devem ser válidos para que o procedimento seja válido.  
  
## <a name="example"></a>Exemplo  
 Veja o exemplo de [gslice::gslice](../standard-library/gslice-class.md#gslice__gslice) para obter um exemplo de como declarar e usar um slice_array.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** \<valarray>  
  
 **Namespace:** std  
  
## <a name="see-also"></a>Consulte também  
 [Acesso Thread-Safe na Biblioteca Padrão C++](../standard-library/thread-safety-in-the-cpp-standard-library.md)


