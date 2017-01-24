---
title: "Extratores _com_ptr_t | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "language-reference"
f1_keywords: 
  - "_com_ptr_t::operatorInterface&"
  - "operatorInterface*"
  - "operatorInterface&"
  - "_com_ptr_t::operatorbool"
  - "_com_ptr_t.operator->"
  - "_com_ptr_t.operator*"
  - "_com_ptr_t::operator->"
  - "_com_ptr_t::operator*"
  - "_com_ptr_t.operatorInterface&"
  - "_com_ptr_t.operatorbool"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Operador &, com objetos específicos"
  - "Operador *, com objetos específicos"
  - "Operador ->, com objetos específicos"
  - "extratores"
  - "extratores, Classe _com_ptr_t"
  - "Operador *"
  - "Operador bool"
  - "Operador Interface&"
  - "Operador Interface*"
  - "operator&"
  - "operator*"
  - "operator->"
ms.assetid: 194b9e0e-123c-49ff-a187-0a7fcd68145a
caps.latest.revision: 6
caps.handback.revision: 6
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Extratores _com_ptr_t
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

**Específico da Microsoft**  
  
 Extrai o ponteiro de interface COM encapsulado.  
  
## Sintaxe  
  
```  
  
      operator Interface*( ) const throw( );   
operator Interface&( ) const;   
Interface& operator*( ) const;   
Interface* operator->( ) const;   
Interface** operator&( ) throw( );   
operator bool( ) const throw( );  
```  
  
## Comentários  
  
-   **operador Interface\*** Retorna o ponteiro de interface encapsulado, que pode ser **NULL**.  
  
-   **operador Interface&** Retorna uma referência ao ponteiro de interface encapsulado, e emite um erro se o ponteiro for **NULL**.  
  
-   **operador \*** Permite que um objeto de ponteiro inteligente atue como se fosse a interface encapsulada real quando desreferenciado.  
  
-   **operador \-\>** Permite que um objeto de ponteiro inteligente atue como se fosse a interface encapsulada real quando desreferenciado.  
  
-   **operador &** Libera qualquer ponteiro de interface encapsulado, substituindo\-o por **NULL**, e retorna o endereço do ponteiro encapsulado.  Isso permite que o ponteiro inteligente seja passado pelo endereço para uma função que possui um parâmetro **out** pelo qual retorna um ponteiro de interface.  
  
-   **operador bool** Permite que um objeto de ponteiro inteligente seja usado em uma expressão condicional.  Esse operador retornará **true** se o ponteiro não for **NULL**.  
  
 **FIM de Específico da Microsoft**  
  
## Consulte também  
 [Classe \_com\_ptr\_t](../cpp/com-ptr-t-class.md)