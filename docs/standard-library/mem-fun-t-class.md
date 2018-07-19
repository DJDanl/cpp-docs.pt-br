---
title: Classe mem_fun_t | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-standard-libraries
ms.topic: reference
f1_keywords:
- xfunctional/std::mem_fun_t
dev_langs:
- C++
helpviewer_keywords:
- mem_fun_t class
ms.assetid: 242566d4-750c-4c87-9d63-2e2c9d19ca2a
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 27182d6c1b2f3c37353f653235449982e921d692
ms.sourcegitcommit: 3614b52b28c24f70d90b20d781d548ef74ef7082
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/11/2018
ms.locfileid: "38956382"
---
# <a name="memfunt-class"></a>Classe mem_fun_t

Uma classe de adaptador que permite uma `non_const` função de membro que não usa argumentos seja chamada como um objeto de função unária quando inicializado com um argumento de ponteiro.

## <a name="syntax"></a>Sintaxe

```cpp
template <class Result, class Type>
class mem_fun_t : public unary_function<Type *, Result> {
    explicit mem_fun_t(Result (Type::* _Pm)());

    Result operator()(Type* _Pleft) const;

};
```

### <a name="parameters"></a>Parâmetros

*_Pm* um ponteiro para a função de membro da classe `Type` a ser convertido em um objeto de função.

*Pleft* o objeto que o *_Pm* função de membro é chamada em.

## <a name="return-value"></a>Valor de retorno

Uma função unária adaptável.

## <a name="remarks"></a>Comentários

A classe de modelo armazena uma cópia dos *_Pm*, que deve ser um ponteiro para uma função de membro de classe `Type`, em um objeto de membro privado. Ela define sua função membro `operator()` como de retorno (`_Pleft`->* `_Pm`)( ).

## <a name="example"></a>Exemplo

Normalmente, o construtor de `mem_fun_t` não é usado diretamente; a função auxiliar `mem_fun` é usada para adaptar funções membro. Consulte [mem_fun](../standard-library/functional-functions.md#mem_fun) para obter um exemplo de como usar adaptadores de função membro.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** \<functional>

**Namespace:** std

## <a name="see-also"></a>Consulte também

[\<functional>](../standard-library/functional.md)<br/>
[Acesso Thread-Safe na Biblioteca Padrão C++](../standard-library/thread-safety-in-the-cpp-standard-library.md)<br/>
[Referência da biblioteca padrão C++](../standard-library/cpp-standard-library-reference.md)<br/>
