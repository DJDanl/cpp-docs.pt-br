---
title: "Extratores _variant_t | Microsoft Docs"
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
  - "_variant_t.operatordouble"
  - "operatorlong"
  - "_variant_t::operator_bstr_t"
  - "operatordouble"
  - "_variant_t.operatorCY"
  - "operatorCY"
  - "_variant_t::operatorCY"
  - "_variant_t::operatordouble"
  - "operatorfloat"
  - "operatorBYTE"
  - "_variant_t.operatorDECIMAL"
  - "_variant_t::operatorlong"
  - "operatorIDispatch"
  - "_variant_t.operatorBYTE"
  - "operatorDECIMAL"
  - "_variant_t.operator_bstr_t"
  - "_variant_t::operatorDECIMAL"
  - "_variant_t.operatorIUnknown"
  - "_variant_t.operatorlong"
  - "_variant_t::operatorIDispatch"
  - "_variant_t::operatorIUnknown"
  - "operatorIUnknown"
  - "_variant_t.operatorbool"
  - "_variant_t::operatorBYTE"
  - "_variant_t.operatorfloat"
  - "operator_bstr_t"
  - "_variant_t::operatorbool"
  - "operatorshort"
  - "_variant_t::operatorshort"
  - "_variant_t::operatorfloat"
  - "_variant_t.operatorIDispatch"
  - "_variant_t.operatorshort"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "extratores, Classe _variant_t"
  - "operator _bstr_t"
  - "Operador bool"
  - "Operador BYTE"
  - "Operador CY"
  - "Operador DECIMAL"
  - "Operador double"
  - "Operador float"
  - "Operador IDispatch"
  - "Operador IUnknown"
  - "Operador long"
  - "operador SHORT"
ms.assetid: 33c1782f-045a-4673-9619-1d750efc83a9
caps.latest.revision: 6
caps.handback.revision: 6
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Extratores _variant_t
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

**Específico da Microsoft**  
  
 Extrai dados do objeto **VARIANT** encapsulado.  
  
## Sintaxe  
  
```  
  
      operator short( ) const;   
operator long( ) const;   
operator float( ) const;   
operator double( ) const;   
operator CY( ) const;   
operator _bstr_t( ) const;   
operator IDispatch*( ) const;   
operator bool( ) const;   
operator IUnknown*( ) const;   
operator DECIMAL( ) const;   
operator BYTE( ) const;  
operator VARIANT() const throw();  
operator char() const;  
operator unsigned short() const;  
operator unsigned long() const;  
operator int() const;  
operator unsigned int() const;  
operator __int64() const;  
operator unsigned __int64() const;  
```  
  
## Comentários  
 Extrai dados brutos de um **VARIANT** encapsulado.  Se **VARIANT** ainda não for do tipo apropriado, **VariantChangeType** será usado para tentar uma conversão, e um erro será gerado mediante falha:  
  
-   **operador short\( \)** Extrai um valor inteiro **short**.  
  
-   **operador long\( \)** Extrai um valor inteiro **long**.  
  
-   **operador float\( \)** Extrai um valor numérico **float**.  
  
-   **operador double\( \)** Extrai um valor inteiro **double**.  
  
-   **operador CY\( \)** Extrai um objeto **CY**.  
  
-   **operador bool\( \)** Extrai um valor `bool`.  
  
-   **operador DECIMAL\( \)** Extrai um valor **DECIMAL**.  
  
-   **operador BYTE\( \)** Extrai um valor **BYTE**.  
  
-   **operador \_bstr\_t\( \)** Extrai uma cadeia de caracteres, que é encapsulada em um objeto `_bstr_t`.  
  
-   **operador IDispatch\*\( \)** Extrai um ponteiro dispinterface de um **VARIANT** encapsulado.  `AddRef` é chamado do ponteiro resultante; então, cabe a você chamar **Release** para liberá\-lo.  
  
-   **operador IUnknown\*\( \)** Extrai um ponteiro da interface COM de um **VARIANT** encapsulado.  `AddRef` é chamado do ponteiro resultante; então, cabe a você chamar **Release** para liberá\-lo.  
  
 **FIM de Específico da Microsoft**  
  
## Consulte também  
 [Classe \_variant\_t](../cpp/variant-t-class.md)