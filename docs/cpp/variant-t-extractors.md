---
title: Extratores variant_t | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-language
ms.tgt_pltfrm: 
ms.topic: language-reference
f1_keywords:
- _variant_t.operatordouble
- operatorlong
- _variant_t::operator_bstr_t
- operatordouble
- _variant_t.operatorCY
- operatorCY
- _variant_t::operatorCY
- _variant_t::operatordouble
- operatorfloat
- operatorBYTE
- _variant_t.operatorDECIMAL
- _variant_t::operatorlong
- operatorIDispatch
- _variant_t.operatorBYTE
- operatorDECIMAL
- _variant_t.operator_bstr_t
- _variant_t::operatorDECIMAL
- _variant_t.operatorIUnknown
- _variant_t.operatorlong
- _variant_t::operatorIDispatch
- _variant_t::operatorIUnknown
- operatorIUnknown
- _variant_t.operatorbool
- _variant_t::operatorBYTE
- _variant_t.operatorfloat
- operator_bstr_t
- _variant_t::operatorbool
- operatorshort
- _variant_t::operatorshort
- _variant_t::operatorfloat
- _variant_t.operatorIDispatch
- _variant_t.operatorshort
dev_langs: C++
helpviewer_keywords:
- extractors, _variant_t class
- operator CY
- operator IDispatch
- operator SHORT
- operator double
- operator long
- operator _bstr_t
- operator DECIMAL
- operator float
- operator bool
- operator BYTE
- operator IUnknown
ms.assetid: 33c1782f-045a-4673-9619-1d750efc83a9
caps.latest.revision: "6"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.openlocfilehash: 4db692b4847bf6a8aa7fb1ffca3f4a2d96de833c
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
---
# <a name="variantt-extractors"></a>Extratores _variant_t
**Seção específica da Microsoft**  
  
 Extrair dados do encapsulada **VARIANT** objeto.  
  
## <a name="syntax"></a>Sintaxe  
  
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
  
## <a name="remarks"></a>Comentários  
 Extrai dados brutos de um encapsulada **VARIANT**. Se o **VARIANT** já não é do tipo apropriado, **VariantChangeType** é usado para tentar uma conversão, e será gerado um erro em caso de falha:  
  
-   **operador short ()** extrai um **curto** valor inteiro.  
  
-   **operador long ()** extrai um **longo** valor inteiro.  
  
-   **operador float ()** extrai um **float** valor numérico.  
  
-   **operador double ()** extrai um **duplo** valor inteiro.  
  
-   **operador (CY)** extrai um **CY** objeto.  
  
-   **operador bool ()** extrai um `bool` valor.  
  
-   **operador (DECIMAL)** extrai um **DECIMAL** valor.  
  
-   **operador (bytes)** extrai um **bytes** valor.  
  
-   **operador de bstr_t ()** extrai uma cadeia de caracteres, que é encapsulada em um `_bstr_t` objeto.  
  
-   **operador IDispatch\*()** extrai um ponteiro dispinterface de um encapsulada **VARIANT**. `AddRef`é chamado no ponteiro resultante, então você chamar **versão** para liberá-la.  
  
-   **operador IUnknown\*()** extrai um ponteiro de interface COM de um encapsulada **VARIANT**. `AddRef`é chamado no ponteiro resultante, então você chamar **versão** para liberá-la.  
  
 **Fim da seção específica da Microsoft**  
  
## <a name="see-also"></a>Consulte também  
 [Classe _variant_t](../cpp/variant-t-class.md)
