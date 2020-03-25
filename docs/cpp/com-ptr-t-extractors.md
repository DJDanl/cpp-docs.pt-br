---
title: Extratores _com_ptr_t
ms.date: 11/04/2016
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
ms.openlocfilehash: 31ac39104c041d1d119f6cd06de5f9c4a620dac0
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80190021"
---
# <a name="_com_ptr_t-extractors"></a>Extratores _com_ptr_t

**Seção específica da Microsoft**

Extrai o ponteiro de interface COM encapsulado.

## <a name="syntax"></a>Sintaxe

```
operator Interface*( ) const throw( );
operator Interface&( ) const;
Interface& operator*( ) const;
Interface* operator->( ) const;
Interface** operator&( ) throw( );
operator bool( ) const throw( );
```

## <a name="remarks"></a>Comentários

- a **interface do operador** <strong>\*</strong> retorna o ponteiro de interface encapsulado, que pode ser nulo.

- **interface do operador &** Retorna uma referência ao ponteiro de interface encapsulado e emite um erro se o ponteiro for nulo.

- o **operador** <strong>\*</strong> permite que um objeto de ponteiro inteligente atue como se fosse a interface encapsulada real quando a referência foi cancelada.

- **operador->** Permite que um objeto de ponteiro inteligente atue como se fosse a interface encapsulada real quando não referenciada.

- **& do operador** Libera qualquer ponteiro de interface encapsulada, substituindo-o por NULL e retorna o endereço do ponteiro encapsulado. Isso permite que o ponteiro inteligente seja passado pelo endereço para uma função que tem um parâmetro *out* por meio do qual ele retorna um ponteiro de interface.

- **booliano de operador** Permite que um objeto de ponteiro inteligente seja usado em uma expressão condicional. Esse operador retornará TRUE se o ponteiro não for nulo.

**Fim da seção específica da Microsoft**

## <a name="see-also"></a>Confira também

[Classe _com_ptr_t](../cpp/com-ptr-t-class.md)
