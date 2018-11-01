---
title: Operadores relacionais _com_ptr_t
ms.date: 11/04/2016
f1_keywords:
- _com_ptr_t::operator>
- _com_ptr_t::operator>=
- _com_ptr_t::operator<=
- _com_ptr_t::operator==
- _com_ptr_t::operator!=
- _com_ptr_t::operator<
helpviewer_keywords:
- '>= operator [C++], comparing specific objects'
- '!= operator'
- operator > [C++], pointers
- operator>= [C++], pointers
- operator < [C++], pointers
- operator!= [C++], relational operators
- < operator [C++], comparing specific objects
- operator== [C++], pointers
- operator == [C++], pointers
- <= operator [C++], with specific objects
- relational operators [C++], _com_ptr_t class
- operator >= [C++], pointers
- operator != [C++], relational operators
- operator <= [C++], pointers
- '> operator [C++], comparing specific objects'
- operator<= [C++], pointers
- operator< [C++], pointers
- == operator [C++], with specific Visual C++ objects
ms.assetid: 5ae4028c-33ee-485d-bbda-88d2604d6d4b
ms.openlocfilehash: eea752410ce350417252c1de58e73ec49bf3f54f
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50440294"
---
# <a name="comptrt-relational-operators"></a>Operadores relacionais _com_ptr_t

**Seção específica da Microsoft**

Comparar o objeto de ponteiro inteligente com outro ponteiro inteligente, o ponteiro de interface bruto ou NULL.

## <a name="syntax"></a>Sintaxe

```
template<typename _OtherIID> 
bool operator==( const _com_ptr_t<_OtherIID>& p );

template<typename _OtherIID>  
bool operator==( _com_ptr_t<_OtherIID>& p );

template<typename _InterfaceType> 
bool operator==( _InterfaceType* p );

template<> 
bool operator==( Interface* p );

template<> 
bool operator==( const _com_ptr_t& p ) throw();

template<> 
bool operator==( _com_ptr_t& p ) throw();

bool operator==( Int null );

template<typename _OtherIID> 
bool operator!=( const _com_ptr_t<_OtherIID>& p );

template<typename _OtherIID> 
bool operator!=( _com_ptr_t<_OtherIID>& p );

template<typename _InterfaceType> 
bool operator!=( _InterfaceType* p );

bool operator!=( Int null );

template<typename _OtherIID> 
bool operator<( const _com_ptr_t<_OtherIID>& p );

template<typename _OtherIID> 
bool operator<( _com_ptr_t<_OtherIID>& p );

template<typename _InterfaceType> 
bool operator<( _InterfaceType* p );

template<typename _OtherIID> 
bool operator>( const _com_ptr_t<_OtherIID>& p );

template<typename _OtherIID> 
bool operator>(_com_ptr_t< _OtherIID>& p );

template<typename _InterfaceType> 
bool operator>( _InterfaceType* p );

template<typename _OtherIID> 
bool operator<=( const _com_ptr_t<_OtherIID>& p );

template<typename _OtherIID> 
bool operator<=( _com_ptr_t<_OtherIID>& p );

template<typename _InterfaceType> 
bool operator<=( _InterfaceType* p );

template<typename _OtherIID>
bool operator>=( const _com_ptr_t<_OtherIID>& p );

template<typename _OtherIID> 
bool operator>=( _com_ptr_t<_OtherIID>& p );

template<typename _InterfaceType> 
bool operator>=( _InterfaceType* p );
```

## <a name="remarks"></a>Comentários

Compara um ponteiro inteligente do objeto para outro inteligente de ponteiro, ponteiro de interface bruto ou NULL. Exceto para os testes de ponteiro nulo, esses operadores primeiro consultam os dois ponteiros para `IUnknown`e comparar os resultados.

**Fim da seção específica da Microsoft**

## <a name="see-also"></a>Consulte também

[Classe _com_ptr_t](../cpp/com-ptr-t-class.md)