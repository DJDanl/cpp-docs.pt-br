---
title: "_bstr_t::copy | Microsoft Docs"
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
  - "_bstr_t::copy"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "objeto BSTR, copy"
  - "Método Copy"
ms.assetid: 00ba7311-e82e-4a79-8106-5329fa2f869a
caps.latest.revision: 6
caps.handback.revision: 6
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# _bstr_t::copy
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

**Específico da Microsoft**  
  
 Constrói uma cópia do `BSTR` encapsulado.  
  
## Sintaxe  
  
```  
  
      BSTR copy(  
  bool fCopy = true  
) const;  
```  
  
#### Parâmetros  
 `fCopy`  
 Se for **true**, **copy** retornará uma cópia do `BSTR` contido; caso contrário, **copy** retornará o BSTR real.  
  
## Comentários  
 Retorna uma cópia recém\-alocada do objeto `BSTR` encapsulado.  
  
## Exemplo  
  
```  
STDMETHODIMP CAlertMsg::get_ConnectionStr(BSTR *pVal){ //  m_bsConStr is _bstr_t  
   *pVal = m_bsConStr.copy();  
}  
```  
  
 **FIM de Específico da Microsoft**  
  
## Consulte também  
 [Classe \_bstr\_t](../cpp/bstr-t-class.md)