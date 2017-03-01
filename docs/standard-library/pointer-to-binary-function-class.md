---
title: Classe pointer_to_binary_function | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- std::pointer_to_binary_function
- xfunctional/std::pointer_to_binary_function
- pointer_to_binary_function
- std.pointer_to_binary_function
dev_langs:
- C++
helpviewer_keywords:
- pointer_to_binary_function function
- pointer_to_binary_function class
ms.assetid: fb50599f-bcb3-4076-a669-6dcc3eb189a5
caps.latest.revision: 21
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
ms.sourcegitcommit: 3f69f0c3176d2fbe19e11ce08c071691a72d858d
ms.openlocfilehash: 9a806934810286e22fdea70c2af982de10f48ee5
ms.lasthandoff: 02/25/2017

---
# <a name="pointertobinaryfunction-class"></a>Classe pointer_to_binary_function
Converte um ponteiro de função binária em uma função binária adaptável.  
  
## <a name="syntax"></a>Sintaxe  
  
```
template <class Arg1, class Arg2, class Result>
class pointer_to_binary_function
    : public binary_function <Arg1, Arg2, Result>
{
public:
    explicit pointer_to_binary_function(
        Result(*pfunc)(Arg1, Arg2));
    Result operator()(Arg1 left, Arg2 right) const;
};
```  
  
#### <a name="parameters"></a>Parâmetros  
 `pfunc`  
 A função binária a ser convertida.  
  
 `left`  
 O objeto à esquerda no qual *\*pfunc* é chamado.  
  
 `right`  
 O objeto à direita no qual *\*pfunc* é chamado.  
  
## <a name="return-value"></a>Valor de retorno  
 A classe de modelo armazena uma cópia de **pfunc**. Ela define sua função membro `operator()` como de retorno (\* **pfunc**)(_ *Left*, \_ *Right*).  
  
## <a name="remarks"></a>Comentários  
 Um ponteiro de função binária é um objeto de função e pode ser passado para qualquer algoritmo da Biblioteca Padrão C++ que esperar uma função binária como parâmetro, mas não é adaptável. Para usá-lo com um adaptador, como ao associar um valor a ele ou usá-lo com um negador, ele deve receber os tipos aninhados **first_argument_type**, **second_argument_type** e **result_type** que possibilitam essa adaptação. A conversão por `pointer_to_binary_function` permite que os adaptadores de função funcionem com ponteiros de função binária.  
  
## <a name="example"></a>Exemplo  
 O construtor de `pointer_to_binary_function` raramente é usado diretamente. Consulte a função auxiliar [ptr_fun](../standard-library/functional-functions.md#ptr_fun_function) para ver um exemplo de como declarar e usar o predicado do adaptador `pointer_to_binary_function`.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** \<functional>  
  
 **Namespace:** std  
  
## <a name="see-also"></a>Consulte também  
 [Referência da biblioteca padrão C++](../standard-library/cpp-standard-library-reference.md)




