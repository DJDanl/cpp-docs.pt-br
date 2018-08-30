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
ms.openlocfilehash: d63a09dec74fc1b7b41f8029dcff285b62b017f1
ms.sourcegitcommit: 9a0905c03a73c904014ec9fd3d6e59e4fa7813cd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/29/2018
ms.locfileid: "43203221"
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
  
-   **operador Interface** <strong>\*</strong> retorna o ponteiro de interface encapsulado, que pode ser NULL.  
  
-   **operador Interface &** retorna uma referência ao ponteiro de interface encapsulado e emitirá um erro se o ponteiro é NULL.  
  
-   **operador** <strong>\*</strong> permite que um objeto de ponteiro inteligente atue como se fosse a interface encapsulada real quando desreferenciado.  
  
-   **operador ->** permite que um objeto de ponteiro inteligente atue como se fosse a interface encapsulada real quando desreferenciado.  
  
-   **operador &** libera qualquer ponteiro de interface encapsulado, substituindo-o por NULL e retorna o endereço do ponteiro encapsulado. Isso permite que o ponteiro inteligente a ser passado pelo endereço para uma função que tem um *out* parâmetro por meio do qual ele retorna um ponteiro de interface.  
  
-   **operador bool** permite que um objeto de ponteiro inteligente a ser usado em uma expressão condicional. Esse operador retornará TRUE se o ponteiro não for nulo.  
  
 **Fim da seção específica da Microsoft**  
  
## <a name="see-also"></a>Consulte também  
 [Classe _com_ptr_t](../cpp/com-ptr-t-class.md)