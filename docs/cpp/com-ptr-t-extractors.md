---
title: Extratores com_ptr_t | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-language
ms.topic: language-reference
f1_keywords:
- _com_ptr_t::operatorInterface&
- _com_ptr_t::operatorbool
- _com_ptr_t::operator->
- _com_ptr_t::operator*
dev_langs:
- C++
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
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: d1343d7dd5f6a35bb222b731294ec897116b9e4b
ms.sourcegitcommit: be2a7679c2bd80968204dee03d13ca961eaa31ff
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/03/2018
---
# <a name="comptrt-extractors"></a>Extratores _com_ptr_t
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
  
-   **operador Interface\***  retorna o ponteiro de interface encapsulados, o que pode ser **nulo**.  
  
-   **operador Interface &** retorna uma referência para o ponteiro de interface encapsulados e emite um erro se o ponteiro for **nulo**.  
  
-   **operador\***  permite que um objeto de ponteiro inteligente atuar como se fosse a interface encapsulada real quando cancelada.  
  
-   **operador ->** permite que um objeto de ponteiro inteligente atuar como se fosse a interface encapsulada real quando cancelada.  
  
-   **operador &** libera qualquer ponteiro de interface encapsulada, substituí-lo com **nulo**e retorna o endereço do ponteiro encapsulado. Isso permite que o ponteiro inteligente deve passar pelo endereço de uma função que tem um **out** parâmetro por meio do qual ele retorna um ponteiro de interface.  
  
-   **operador bool** permite que um objeto de ponteiro inteligente a ser usado em uma expressão condicional. Esse operador retorna **true** se o ponteiro não é **nulo**.  
  
 **Fim da seção específica da Microsoft**  
  
## <a name="see-also"></a>Consulte também  
 [Classe _com_ptr_t](../cpp/com-ptr-t-class.md)