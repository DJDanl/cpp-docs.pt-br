---
title: Classe mem_fun_ref_t | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-standard-libraries
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords: xfunctional/std::mem_fun_ref_t
dev_langs: C++
helpviewer_keywords: mem_fun_ref_t class
ms.assetid: 7dadcac3-8d33-4e4b-a792-81bd53d3df39
caps.latest.revision: "20"
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 5e610db4ff4a80a240708c45dd0e32ae890f9b4d
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="memfunreft-class"></a>Classe mem_fun_ref_t
Uma classe de adaptador que permite que uma função membro **non_const** que não usa argumentos seja chamada como um objeto de função unária quando inicializada com um argumento de referência.  
  
## <a name="syntax"></a>Sintaxe  
  
```
template <class Result, class Type>
class mem_fun_ref_t : public unary_function<Type, Result> {
    explicit mem_fun_ref_t(
    Result (Type::* _Pm)());

    Result operator()(Type& left) const;

 };
```  
  
#### <a name="parameters"></a>Parâmetros  
 `_Pm`  
 Um ponteiro para a função membro da classe **Type** a ser convertido em um objeto de função.  
  
 `left`  
 O objeto no qual a função membro `_Pm` é chamada.  
  
## <a name="return-value"></a>Valor de retorno  
 Uma função unária adaptável.  
  
## <a name="remarks"></a>Comentários  
 A classe de modelo armazena uma cópia de `_Pm`, que deve ser um ponteiro para uma função membro da classe **Type**, em um objeto de membro privado. Ela define sua função membro `operator()` como de retorno (**left**.* `_Pm`)( ).  
  
## <a name="example"></a>Exemplo  
  Normalmente, o construtor de `mem_fun_ref_t` não é usado diretamente; a função auxiliar `mem_fun_ref` é usada para adaptar funções membro. Consulte [mem_fun_ref](../standard-library/functional-functions.md#mem_fun_ref) para obter um exemplo de como usar adaptadores de função membro.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** \<functional>  
  
 **Namespace:** std  
  
## <a name="see-also"></a>Consulte também  
 [Acesso Thread-Safe na Biblioteca Padrão C++](../standard-library/thread-safety-in-the-cpp-standard-library.md)   
 [Referência da biblioteca padrão C++](../standard-library/cpp-standard-library-reference.md)



