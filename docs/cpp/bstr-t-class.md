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
- BSTR object, COM encapsulation
ms.assetid: 58841fef-fe21-4a84-aab9-780262b5201f
caps.latest.revision: 9
author: mikeblome
ms.author: mblome
manager: ghogen
translation.priority.ht:
- cs-cz
- de-de
- es-es
- fr-fr
- it-it
- ja-jp
- ko-kr
- pl-pl
- pt-br
- ru-ru
- tr-tr
- zh-cn
- zh-tw
ms.translationtype: HT
ms.sourcegitcommit: 6ffef5f51e57cf36d5984bfc43d023abc8bc5c62
ms.openlocfilehash: ce63f8243bc46d77116dbacdf82f821333cba785
ms.contentlocale: pt-br
ms.lasthandoff: 09/25/2017

---
# <a name="bstrt-class"></a>Classe _bstr_t
**Seção específica da Microsoft**  
  
 Um `_bstr_t` objeto encapsula o [o tipo de dados BSTR](http://msdn.microsoft.com/en-us/1b2d7d2c-47af-4389-a6b6-b01b7e915228). A classe gerencia a alocação e desalocação por meio de chamadas de função **SysAllocString** e **SysFreeString** e outros `BSTR` APIs quando apropriado. A classe `_bstr_t` usa contagem de referências para evitar sobrecarga excessiva.  
  
### <a name="construction"></a>Construção  
  
|||  
|-|-|  
|[bstr_t](../cpp/bstr-t-bstr-t.md)|Constrói um objeto `_bstr_t`.|  
  
### <a name="operations"></a>Operações  
  
|||  
|-|-|  
|[Atribuir](../cpp/bstr-t-assign.md)|Copia um `BSTR` para o `BSTR` encapsulado por um `_bstr_t`.|  
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
|[operador = =,! =, \<, >, \<=, > =](../cpp/bstr-t-relational-operators.md)|Compara dois objetos `_bstr_t`.|  
|[operador wchar_t * &#124; char\*](../cpp/bstr-t-wchar-t-star-bstr-t-char-star.md)|Extrai os ponteiros para o objeto `BSTR` Unicode ou multibyte encapsulado.|  
  
**Fim da seção específica da Microsoft**  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** comutil.h  
  
 **Lib:** comsuppw.lib ou comsuppwd.lib (consulte [/ZC: (wchar_t é do tipo nativo)](../build/reference/zc-wchar-t-wchar-t-is-native-type.md) para obter mais informações)  
  
## <a name="see-also"></a>Consulte também  
 [Classes de suporte COM do compilador](../cpp/compiler-com-support-classes.md)
