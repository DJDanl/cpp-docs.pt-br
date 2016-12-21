---
title: "Classe _variant_t | Microsoft Docs"
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
  - "Variant"
  - "_variant_t"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe _variant_t"
  - "Classe _variant_t, funções de membro"
  - "Classe _variant_t, operadores"
  - "objeto VARIANT"
  - "objeto VARIANT, encapsulamento COM"
ms.assetid: 6a3cbd4e-0ae8-425e-b4cf-ca0df894c93f
caps.latest.revision: 10
caps.handback.revision: 10
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe _variant_t
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

**Específico da Microsoft**  
  
 Um objeto `_variant_t` encapsula o tipo de dados `VARIANT`.  A classe gerencia a alocação e a desalocação de recursos e faz chamadas de função para **VariantInit** e **VariantClear** conforme apropriado.  
  
### Construção  
  
|||  
|-|-|  
|[\_variant\_t](../Topic/_variant_t::_variant_t.md)|Constrói um objeto `_variant_t`.|  
  
### Operações  
  
|||  
|-|-|  
|[Attach](../cpp/variant-t-attach.md)|Anexa um objeto **VARIANT** ao objeto `_variant_t`.|  
|[Clear](../cpp/variant-t-clear.md)|Limpa o objeto **VARIANT** encapsulado.|  
|[ChangeType](../Topic/_variant_t::ChangeType.md)|Altera o tipo do objeto `_variant_t` para o **VARTYPE** indicado.|  
|[Detach](../cpp/variant-t-detach.md)|Desanexa o objeto **VARIANT** encapsulado deste objeto `_variant_t`.|  
|[SetString](../cpp/variant-t-setstring.md)|Atribui uma cadeia de caracteres a este objeto `_variant_t`.|  
  
### Operadores  
  
|||  
|-|-|  
|[operator \=](../cpp/variant-t-operator-equal.md)|Atribui um novo valor a um objeto `_variant_t` existente.|  
|[operator \=\=, \!\=](../cpp/variant-t-relational-operators.md)|Compare dois objetos `_variant_t` em termos de igualdade ou desigualdade.|  
|[Extratores](../cpp/variant-t-extractors.md)|Extrai dados do objeto **VARIANT** encapsulado.|  
  
## FIM de Específico da Microsoft  
  
## Requisitos  
 **Cabeçalho:** comutil.h  
  
 **Bib:** comsuppw.lib ou comsuppwd.lib \(consulte [\/Zc:wchar\_t \(wchar\_t é do tipo nativo\)](../build/reference/zc-wchar-t-wchar-t-is-native-type.md) para obter mais informações\)  
  
## Consulte também  
 [Classes de suporte COM do compilador](../cpp/compiler-com-support-classes.md)