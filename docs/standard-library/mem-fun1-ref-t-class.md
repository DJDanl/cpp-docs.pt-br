---
title: Classe mem_fun1_ref_t | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-standard-libraries
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- xfunctional/std::mem_fun1_ref_t
dev_langs:
- C++
helpviewer_keywords:
- mem_fun1_ref_t class
ms.assetid: 7d6742f6-19ba-4523-b3c8-0e5b8f11464f
caps.latest.revision: 
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 35dd25e56ba838864eeeb64d43fc8c2d25cff803
ms.sourcegitcommit: d51ed21ab2b434535f5c1d553b22e432073e1478
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/23/2018
---
# <a name="memfun1reft-class"></a>Classe mem_fun1_ref_t
Uma classe de adaptador que permite que uma função membro **non_const** que usa um único argumento seja chamada como um objeto de função binária quando inicializada com um argumento de referência.  
  
## <a name="syntax"></a>Sintaxe  
  
```
template <class Result, class Type, class Arg>
class mem_fun1_ref_t : public binary_function<Type, Arg, Result> {
    explicit mem_fun1_ref_t(
    Result (Type::* _Pm)(Arg));

    Result operator()(
    Type& left,
    Arg right) const;

 };
```  
  
#### <a name="parameters"></a>Parâmetros  
 `_Pm`  
 Um ponteiro para a função membro da classe **Type** a ser convertido em um objeto de função.  
  
 `left`  
 O objeto no qual a função membro `_Pm` é chamada.  
  
 `right`  
 O argumento que está sendo fornecido para `_Pm`.  
  
## <a name="return-value"></a>Valor de retorno  
 Uma função binária adaptável.  
  
## <a name="remarks"></a>Comentários  
 A classe de modelo armazena uma cópia de `_Pm`, que deve ser um ponteiro para uma função membro da classe **Type**, em um objeto de membro privado. Define a função de membro `operator()` como retornando ( **esquerdo**.\* `_Pm`) ( **direita**).  
  
## <a name="example"></a>Exemplo  
 Normalmente, o construtor de `mem_fun1_ref_t` não é usado diretamente; a função auxiliar `mem_fun_ref` é usada para adaptar funções membro. Consulte [mem_fun_ref](../standard-library/functional-functions.md#mem_fun_ref) para obter um exemplo de como usar adaptadores de função membro.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** \<functional>  
  
 **Namespace:** std  
  
## <a name="see-also"></a>Consulte também  
 [Acesso Thread-Safe na Biblioteca Padrão C++](../standard-library/thread-safety-in-the-cpp-standard-library.md)   
 [Referência da biblioteca padrão C++](../standard-library/cpp-standard-library-reference.md)



