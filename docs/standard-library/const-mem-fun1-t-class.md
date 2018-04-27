---
title: Classe const_mem_fun1_t | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.reviewer: ''
ms.suite: ''
ms.technology:
- cpp-standard-libraries
ms.tgt_pltfrm: ''
ms.topic: reference
f1_keywords:
- xfunctional/std::const_mem_fun1_t
dev_langs:
- C++
helpviewer_keywords:
- const_mem_fun1_t class
ms.assetid: 250fac30-9663-4133-9051-6303f76ea259
caps.latest.revision: 20
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 81ee887e048e774cd8aafcfd59fe5d27338e2837
ms.sourcegitcommit: dd1a509526fa8bb18e97ab7bc7b91cbdb3ec7059
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/26/2018
---
# <a name="constmemfun1t-class"></a>Classe const_mem_fun1_t

Uma classe de adaptador que permite que uma função de membro **const** que usa um único argumento seja chamada como um objeto de função binário quando inicializada com um argumento de ponteiro.

## <a name="syntax"></a>Sintaxe

```cpp
template <class Result, class Type, class Arg>
class const_mem_fun1_t
 : public binary_function<const Type *, Arg, Result>
{
    explicit const_mem_fun1_t(Result (Type::* _Pm)(Arg) const);
    Result operator()(const Type* _Pleft, Arg right) const;
 };
```

### <a name="parameters"></a>Parâmetros

`_Pm` Um ponteiro para a função de membro da classe **tipo** a ser convertido em um objeto de função.

`_Pleft` O **const** o objeto de `_Pm` função de membro é chamada em.

`right` O argumento que está sendo fornecido ao `_Pm`.

## <a name="return-value"></a>Valor de retorno

Uma função binária adaptável.

## <a name="remarks"></a>Comentários

A classe de modelo armazena uma cópia de `_Pm`, que deve ser um ponteiro para uma função membro da classe **Type**, em um objeto de membro privado. Define a função de membro `operator()` como retornando ( **_Pleft** -> \* * Pm) (***direita**) **const**.

## <a name="example"></a>Exemplo

Normalmente, o construtor de `const_mem_fun1_t` não é usado diretamente; a função auxiliar `mem_fun` é usada para adaptar funções membro. Consulte [mem_fun](../standard-library/functional-functions.md#mem_fun) para obter um exemplo de como usar adaptadores de função membro.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** \<functional>

**Namespace:** std

## <a name="see-also"></a>Consulte também

[Acesso Thread-Safe na Biblioteca Padrão C++](../standard-library/thread-safety-in-the-cpp-standard-library.md)<br/>
[Referência da biblioteca padrão C++](../standard-library/cpp-standard-library-reference.md)<br/>
