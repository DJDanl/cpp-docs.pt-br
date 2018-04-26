---
title: Classe const_mem_fun1_ref_t | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.reviewer: ''
ms.suite: ''
ms.technology:
- cpp-standard-libraries
ms.tgt_pltfrm: ''
ms.topic: reference
f1_keywords:
- xfunctional/std::const_mem_fun1_ref_t
dev_langs:
- C++
helpviewer_keywords:
- const_mem_fun1_ref_t class
ms.assetid: 8220d373-fa1c-44be-a21d-96d49b3ea6bb
caps.latest.revision: 20
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 4236f510ad942dc0ab8cbe64a34670623ea3aaf2
ms.sourcegitcommit: dd1a509526fa8bb18e97ab7bc7b91cbdb3ec7059
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/26/2018
---
# <a name="constmemfun1reft-class"></a>Classe const_mem_fun1_ref_t

Uma classe de adaptador que permite que uma função membro **const** que usa um único argumento seja chamada como um objeto de função binária quando inicializado com um argumento de referência.

## <a name="syntax"></a>Sintaxe

```cpp
template <class Result, class Type, class Arg>
class const_mem_fun1_ref_t
 : public binary_function<Type, Arg, Result>
 {
    explicit const_mem_fun1_ref_t(Result (Type::* Pm)(Arg) const);
    Result operator()(const Type& left, Arg right) const;
 };
```

### <a name="parameters"></a>Parâmetros

`Pm` Um ponteiro para a função de membro da classe **tipo** a ser convertido em um objeto de função.

`left` O **const** o objeto de `Pm` função de membro é chamada em.

`right` O argumento que está sendo fornecido ao `Pm`.

## <a name="return-value"></a>Valor de retorno

Uma função binária adaptável.

## <a name="remarks"></a>Comentários

A classe de modelo armazena uma cópia de `Pm`, que deve ser um ponteiro para uma função membro da classe **Type**, em um objeto de membro privado. Ela define sua função membro `operator()` como de retorno ( `left`.\* *Pm*)( `right`) **const**.

## <a name="example"></a>Exemplo

Normalmente, o construtor de `const_mem_fun1_ref_t` não é usado diretamente; a função auxiliar `mem_fun_ref` é usada para adaptar funções membro. Consulte [mem_fun_ref](../standard-library/functional-functions.md#mem_fun_ref) para obter exemplos de como usar adaptadores de função membro.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** \<functional>

**Namespace:** std

## <a name="see-also"></a>Consulte também

[Acesso Thread-Safe na Biblioteca Padrão C++](../standard-library/thread-safety-in-the-cpp-standard-library.md)<br/>
[Referência da biblioteca padrão C++](../standard-library/cpp-standard-library-reference.md)<br/>
