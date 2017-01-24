---
title: "Classe _bstr_t | Microsoft Docs"
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
  - "_bstr_t"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe _bstr_t"
  - "objeto BSTR"
  - "objeto BSTR, encapsulamento COM"
ms.assetid: 58841fef-fe21-4a84-aab9-780262b5201f
caps.latest.revision: 9
caps.handback.revision: 9
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe _bstr_t
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

**Específico da Microsoft**  
  
 Um objeto `_bstr_t` encapsula o [tipo de dados BSTR](http://msdn.microsoft.com/pt-br/1b2d7d2c-47af-4389-a6b6-b01b7e915228).  A classe gerencia a alocação e a desalocação de recursos por meio de chamadas de função para **SysAllocString** e **SysFreeString** e outras APIs `BSTR` quando apropriado.  A classe `_bstr_t` usa contagem de referências para evitar sobrecarga excessiva.  
  
### Construção  
  
|||  
|-|-|  
|[\_bstr\_t](../cpp/bstr-t-bstr-t.md)|Constrói um objeto `_bstr_t`.|  
  
### Operações  
  
|||  
|-|-|  
|[Assign](../cpp/bstr-t-assign.md)|Copia um `BSTR` para o `BSTR` encapsulado por um `_bstr_t`.|  
|[Attach](../cpp/bstr-t-attach.md)|Vincula um wrapper `_bstr_t` a um `BSTR`.|  
|[copy](../cpp/bstr-t-copy.md)|Constrói uma cópia do `BSTR` encapsulado.|  
|[Detach](../cpp/bstr-t-detach.md)|Retorna o `BSTR` encapsulado por um `_bstr_t` e desanexa o `BSTR` do `_bstr_t`.|  
|[GetAddress](../cpp/bstr-t-getaddress.md)|Aponta para o `BSTR` encapsulado por um `_bstr_t`.|  
|[GetBSTR](../Topic/_bstr_t::GetBSTR.md)|Aponta para o início do `BSTR` encapsulado por `_bstr_t`.|  
|[length](../cpp/bstr-t-length.md)|Retorna o número de caracteres no `_bstr_t`.|  
  
### Operadores  
  
|||  
|-|-|  
|[operador \=](../cpp/bstr-t-operator-equal.md)|Atribui um novo valor a um objeto `_bstr_t` existente.|  
|[operator \+\=](../cpp/bstr-t-operator-add-equal-plus.md)|Acrescenta caracteres ao final do objeto `_bstr_t`.|  
|[operator \+](../cpp/bstr-t-operator-add-equal-plus.md)|Concatena duas cadeias de caracteres.|  
|[operator \!](../cpp/bstr-t-operator-logical-not.md)|Verifica se o `BSTR` encapsulado é uma cadeia de caracteres **NULL**.|  
|[operator \=\=, \!\=, \<, \>, \<\=, \>\=](../cpp/bstr-t-relational-operators.md)|Compara dois objetos `_bstr_t`.|  
|[operator wchar\_t\* &#124; char\*](../cpp/bstr-t-wchar-t-star-bstr-t-char-star.md)|Extrai os ponteiros para o objeto `BSTR` Unicode ou multibyte encapsulado.|  
  
## FIM de Específico da Microsoft  
  
## Requisitos  
 **Cabeçalho:** comutil.h  
  
 **Bib:** comsuppw.lib ou comsuppwd.lib \(consulte [\/Zc:wchar\_t \(wchar\_t é do tipo nativo\)](../build/reference/zc-wchar-t-wchar-t-is-native-type.md) para obter mais informações\)  
  
## Consulte também  
 [Classes de suporte COM do compilador](../cpp/compiler-com-support-classes.md)