---
title: Classe pointer_to_unary_function | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-standard-libraries
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords: xfunctional/std::pointer_to_unary
dev_langs: C++
helpviewer_keywords:
- pointer_to_unary_function function
- pointer_to_unary_function class
ms.assetid: 05600207-b916-4759-beca-6b6facd2d6f6
caps.latest.revision: "21"
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: df7d37c06408fff0333c13d72dd3157f4df6e77b
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="pointertounaryfunction-class"></a>Classe pointer_to_unary_function
Converte um ponteiro de função unária em uma função unária adaptável.  
  
## <a name="syntax"></a>Sintaxe  
  
```
template <class Arg, class Result>
class pointer_to_unary_function
    : public unary_function<Arg, Result>
{
public:
    explicit pointer_to_unary_function(Result(*pfunc)(Arg));
    Result operator()(Arg left) const;
};
```  
  
#### <a name="parameters"></a>Parâmetros  
 `pfunc`  
 A função binária a ser convertida.  
  
 `left`  
 O objeto no qual o  *\*pfunc* é chamado.  
  
## <a name="return-value"></a>Valor de retorno  
 A classe de modelo armazena uma cópia de **pfunc**. Ela define sua função membro `operator()` como de retorno (\* **pfunc**)(_ *Left*).  
  
## <a name="remarks"></a>Comentários  
 Um ponteiro de função unária é um objeto de função e pode ser passado para qualquer algoritmo da Biblioteca Padrão C++ que esperar uma função unária como parâmetro, mas não é adaptável. Para usá-lo com um adaptador, como ao associar um valor a ele ou usá-lo com um negador, ele deve receber os tipos aninhados **argument_type** e **result_type** que possibilitam essa adaptação. A conversão por `pointer_to_unary_function` permite que os adaptadores de função funcionem com ponteiros de função binária.  
  
## <a name="example"></a>Exemplo  
 O construtor de `pointer_to_unary_function` raramente é usado diretamente. Consulte a função auxiliar [ptr_fun](../standard-library/functional-functions.md#ptr_fun) para ver um exemplo de como declarar e usar o predicado do adaptador `pointer_to_unary_function`.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** \<functional>  
  
 **Namespace:** std  
  
## <a name="see-also"></a>Consulte também  
 [Referência da biblioteca padrão C++](../standard-library/cpp-standard-library-reference.md)



