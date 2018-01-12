---
title: Extratores com_ptr_t | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-language
ms.tgt_pltfrm: 
ms.topic: language-reference
f1_keywords:
- _com_ptr_t::operatorInterface&
- _com_ptr_t::operatorbool
- _com_ptr_t::operator->
- _com_ptr_t::operator*
dev_langs: C++
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
caps.latest.revision: "6"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 1c006c18b9e00e5c79ff686dfb31fa9ccf56fd4e
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
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