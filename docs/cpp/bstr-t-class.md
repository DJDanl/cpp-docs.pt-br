---
title: classe bstr_t | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-language
ms.tgt_pltfrm: 
ms.topic: language-reference
f1_keywords:
- _bstr_t
dev_langs:
- C++
helpviewer_keywords:
- BSTR object
- _bstr_t class
- BSTR object [C++], COM encapsulation
ms.assetid: 58841fef-fe21-4a84-aab9-780262b5201f
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 6943a75f83bac517ce3c9677b0abd8ef560e9b77
ms.sourcegitcommit: 9a0a287d6940591523af959ebdac5affa36220da
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 01/25/2018
---
# <a name="bstrt-class"></a>Classe _bstr_t
**Seção específica da Microsoft**  
  
 Um `_bstr_t` objeto encapsula o [o tipo de dados BSTR](http://msdn.microsoft.com/en-us/1b2d7d2c-47af-4389-a6b6-b01b7e915228). A classe gerencia a alocação e desalocação por meio de chamadas de função **SysAllocString** e **SysFreeString** e outros `BSTR` APIs quando apropriado. A classe `_bstr_t` usa contagem de referências para evitar sobrecarga excessiva.  
  
### <a name="construction"></a>Construção  
  
|||  
|-|-|  
|[_bstr_t](../cpp/bstr-t-bstr-t.md)|Constrói um objeto `_bstr_t`.|  
  
### <a name="operations"></a>Operações  
  
|||  
|-|-|  
|[Assign](../cpp/bstr-t-assign.md)|Copia um `BSTR` para o `BSTR` encapsulado por um `_bstr_t`.|  
|[Anexar](../cpp/bstr-t-attach.md)|Vincula um wrapper `_bstr_t` a um `BSTR`.|  
|[copy](../cpp/bstr-t-copy.md)|Constrói uma cópia do `BSTR` encapsulado.|  
|[Desanexar](../cpp/bstr-t-detach.md)|Retorna o `BSTR` encapsulado por um `_bstr_t` e desanexa o `BSTR` do `_bstr_t`.|  
|[GetAddress](../cpp/bstr-t-getaddress.md)|Aponta para o `BSTR` encapsulado por um `_bstr_t`.|  
|[GetBSTR](../cpp/bstr-t-getbstr.md)|Aponta para o início do `BSTR` encapsulado por `_bstr_t`.|  
|[length](../cpp/bstr-t-length.md)|Retorna o número de caracteres no `_bstr_t`.|  
  
### <a name="operators"></a>Operadores  
  
|||  
|-|-|  
|[operador =](../cpp/bstr-t-operator-equal.md)|Atribui um novo valor a um objeto `_bstr_t` existente.|  
|[+ operador =](../cpp/bstr-t-operator-add-equal-plus.md)|Acrescenta caracteres ao final do objeto `_bstr_t`.|  
|[operador +](../cpp/bstr-t-operator-add-equal-plus.md)|Concatena duas cadeias de caracteres.|  
|[operador !](../cpp/bstr-t-operator-logical-not.md)|Verifica se o encapsulada `BSTR` é um **nulo** cadeia de caracteres.|  
|[operator ==, !=, \<, >, \<=, >=](../cpp/bstr-t-relational-operators.md)|Compara dois objetos `_bstr_t`.|  
|[operador wchar_t * &#124; char\*](../cpp/bstr-t-wchar-t-star-bstr-t-char-star.md)|Extrai os ponteiros para o objeto `BSTR` Unicode ou multibyte encapsulado.|  
  
**Fim da seção específica da Microsoft**  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** \<comutil.h >  
  
 **Lib:** comsuppw.lib ou comsuppwd.lib (consulte [/ZC: (wchar_t é do tipo nativo)](../build/reference/zc-wchar-t-wchar-t-is-native-type.md) para obter mais informações)  
  
## <a name="see-also"></a>Consulte também  
 [Classes de suporte COM do compilador](../cpp/compiler-com-support-classes.md)