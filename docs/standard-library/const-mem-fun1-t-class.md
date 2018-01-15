---
title: Classe const_mem_fun1_t | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-standard-libraries
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords: xfunctional/std::const_mem_fun1_t
dev_langs: C++
helpviewer_keywords: const_mem_fun1_t class
ms.assetid: 250fac30-9663-4133-9051-6303f76ea259
caps.latest.revision: "20"
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 788f49d3aa4cefd46e5ea97517a02a35a9747403
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="constmemfun1t-class"></a>Classe const_mem_fun1_t
Uma classe de adaptador que permite que uma função de membro **const** que usa um único argumento seja chamada como um objeto de função binário quando inicializada com um argumento de ponteiro.  
  
## <a name="syntax"></a>Sintaxe  
  
```
template <class Result, class Type, class Arg>
class const_mem_fun1_t
 : public binary_function<const Type *, Arg, Result>  
{
    explicit const_mem_fun1_t(Result (Type::* _Pm)(Arg) const);
    Result operator()(const Type* _Pleft, Arg right) const;
 };
```  
  
#### <a name="parameters"></a>Parâmetros  
 `_Pm`  
 Um ponteiro para a função membro da classe **Type** a ser convertido em um objeto de função.  
  
 `_Pleft`  
 O objeto **const** no qual a função membro `_Pm` é chamada.  
  
 `right`  
 O argumento que está sendo fornecido para `_Pm`.  
  
## <a name="return-value"></a>Valor de retorno  
 Uma função binária adaptável.  
  
## <a name="remarks"></a>Comentários  
 A classe de modelo armazena uma cópia de `_Pm`, que deve ser um ponteiro para uma função membro da classe **Type**, em um objeto de membro privado. Ela define sua função de membro `operator()` como de retorno ( **_Pleft**->\* *Pm)(***Right**) **const**.  
  
## <a name="example"></a>Exemplo  
 Normalmente, o construtor de `const_mem_fun1_t` não é usado diretamente; a função auxiliar `mem_fun` é usada para adaptar funções membro. Consulte [mem_fun](../standard-library/functional-functions.md#mem_fun) para obter um exemplo de como usar adaptadores de função membro.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** \<functional>  
  
 **Namespace:** std  
  
## <a name="see-also"></a>Consulte também  
 [Acesso Thread-Safe na Biblioteca Padrão C++](../standard-library/thread-safety-in-the-cpp-standard-library.md)   
 [Referência da biblioteca padrão C++](../standard-library/cpp-standard-library-reference.md)



