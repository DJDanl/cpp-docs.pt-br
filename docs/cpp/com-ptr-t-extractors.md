---
title: Extratores _com_ptr_t
description: Descreve os operadores de extração para a classe _com_ptr_t.
ms.date: 07/07/2020
f1_keywords:
- _com_ptr_t::operatorInterface&
- _com_ptr_t::operatorbool
- _com_ptr_t::operator->
- _com_ptr_t::operator*
helpviewer_keywords:
- operator Interface& [C++]
- '* operator [C++], with specific objects'
- operator& [C++]
- operator* [C++]
- -> operator [C++], with specific objects
- '& operator [C++], with specific objects'
- operator Interface* [C++]
- operator * [C++]
- operator->
- operator bool
- extractors, _com_ptr_t class
- extractors [C++]
ms.assetid: 194b9e0e-123c-49ff-a187-0a7fcd68145a
ms.openlocfilehash: e7b06bb11ab34a1a1a7f6fab98d177821f60b20c
ms.sourcegitcommit: e17cc8a478b51739d67304d7d82422967b35f716
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/08/2020
ms.locfileid: "86127863"
---
# <a name="_com_ptr_t-extractors"></a>`_com_ptr_t`Extratores

**Específico da Microsoft**

Extrai o ponteiro de interface COM encapsulado.

## <a name="syntax"></a>Sintaxe

```c++
operator Interface*( ) const throw( );
operator Interface&( ) const;
Interface& operator*( ) const;
Interface* operator->( ) const;
Interface** operator&( ) throw( );
operator bool( ) const throw( );
```

## <a name="remarks"></a>Comentários

- **`operator Interface*`** Retorna o ponteiro de interface encapsulado, que pode ser nulo.

- **`operator Interface&`** Retorna uma referência ao ponteiro de interface encapsulado e emite um erro se o ponteiro for nulo.

- **`operator*`** Permite que um objeto de ponteiro inteligente atue como se fosse a interface encapsulada real quando não referenciada.

- **`operator->`** Permite que um objeto de ponteiro inteligente atue como se fosse a interface encapsulada real quando não referenciada.

- **`operator&`** Libera qualquer ponteiro de interface encapsulada, substituindo-o por NULL e retorna o endereço do ponteiro encapsulado. Esse operador permite passar o ponteiro inteligente por endereço para uma função que tem um parâmetro *out* por meio do qual ele retorna um ponteiro de interface.

- **`operator bool`** Permite que um objeto de ponteiro inteligente seja usado em uma expressão condicional. Esse operador retornará TRUE se o ponteiro não for nulo.

  > [!NOTE]
  > Como o **`operator bool`** não é declarado como **`explicit`** , `_com_ptr_t` é implicitamente conversível para **`bool`** , que é conversível para qualquer tipo escalar. Isso pode ter consequências inesperadas em seu código. Habilite o [aviso do compilador (nível 4) C4800](../error-messages/compiler-warnings/compiler-warning-level-3-c4800.md) para impedir o uso não intencional dessa conversão.

## <a name="see-also"></a>Confira também

[Classe _com_ptr_t](../cpp/com-ptr-t-class.md)
