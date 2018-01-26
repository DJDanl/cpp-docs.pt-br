---
title: classe variant_t | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-language
ms.tgt_pltfrm: 
ms.topic: language-reference
f1_keywords: _variant_t
dev_langs: C++
helpviewer_keywords:
- _variant_t class [C++], operators
- _variant_t class
- _variant_t class [C++], member functions
- VARIANT object
- VARIANT object [C++], COM encapsulation
ms.assetid: 6a3cbd4e-0ae8-425e-b4cf-ca0df894c93f
caps.latest.revision: "10"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 57a4d7e4019e742ff8adc50bb78a926dff34d55a
ms.sourcegitcommit: 9a0a287d6940591523af959ebdac5affa36220da
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 01/25/2018
---
# <a name="variantt-class"></a>Classe _variant_t
**Seção específica da Microsoft**  
  
 Um objeto `_variant_t` encapsula o tipo de dados `VARIANT`. A classe gerencia a alocação e desalocação e faz chamadas de função **VariantInit** e **VariantClear** conforme apropriado.  
  
### <a name="construction"></a>Construção  
  
|||  
|-|-|  
|[_variant_t](../cpp/variant-t-variant-t.md)|Constrói um objeto `_variant_t`.|  
  
### <a name="operations"></a>Operações  
  
|||  
|-|-|  
|[Anexar](../cpp/variant-t-attach.md)|Anexa uma **VARIANT** objeto para o `_variant_t` objeto.|  
|[Limpar](../cpp/variant-t-clear.md)|Limpa o encapsulada **VARIANT** objeto.|  
|[ChangeType](../cpp/variant-t-changetype.md)|Altera o tipo do `_variant_t` objeto do tipo **VARTYPE**.|  
|[Desanexar](../cpp/variant-t-detach.md)|Desanexa o encapsulada **VARIANT** objeto neste `_variant_t` objeto.|  
|[SetString](../cpp/variant-t-setstring.md)|Atribui uma cadeia de caracteres a este objeto `_variant_t`.|  
  
### <a name="operators"></a>Operadores  
  
|||  
|-|-|  
|[Operador =](../cpp/variant-t-operator-equal.md)|Atribui um novo valor a um objeto `_variant_t` existente.|  
|[operator ==, !=](../cpp/variant-t-relational-operators.md)|Compare dois objetos `_variant_t` em termos de igualdade ou desigualdade.|  
|[Extratores](../cpp/variant-t-extractors.md)|Extrair dados do encapsulada **VARIANT** objeto.|  
  
**Fim da seção específica da Microsoft**  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** \<comutil.h >  
  
 **Lib:** comsuppw.lib ou comsuppwd.lib (consulte [/ZC: (wchar_t é do tipo nativo)](../build/reference/zc-wchar-t-wchar-t-is-native-type.md) para obter mais informações)  
  
## <a name="see-also"></a>Consulte também  
 [Classes de suporte COM do compilador](../cpp/compiler-com-support-classes.md)