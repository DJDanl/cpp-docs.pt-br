---
title: _bstr_t::Operator = | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-language
ms.topic: language-reference
f1_keywords:
- _bstr_t::operator=
dev_langs:
- C++
helpviewer_keywords:
- operator = [C++], bstr
- operator= [C++], bstr
ms.assetid: fb31bb1b-ce29-4388-b5fd-8dac830cf18a
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 43e28aa7d7b3682c45f4f8b7a94e990374d83b46
ms.sourcegitcommit: 1fd1eb11f65f2999dfd93a2d924390ed0a0901ed
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/10/2018
ms.locfileid: "37942115"
---
# <a name="bstrtoperator-"></a>_bstr_t::operator =
**Seção específica da Microsoft**  
  
 Atribui um novo valor a um objeto `_bstr_t` existente.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
  
_bstr_t& operator=(const _bstr_t& s1) throw ( );  
_bstr_t& operator=(const char* s2);  
_bstr_t& operator=(const wchar_t* s3);  
_bstr_t& operator=(const _variant_t& var);  
```  
  
#### <a name="parameters"></a>Parâmetros  
 *S1*  
 Um objeto `_bstr_t` a ser atribuído a um objeto existente `_bstr_t`.  
  
 *S2*  
 Uma cadeia de caracteres multibyte a ser atribuída a um objeto `_bstr_t` existente.  
  
 *S3*  
 Uma cadeia de caracteres Unicode a ser atribuída a um objeto `_bstr_t` existente.  
  
 *var*  
 Um objeto `_variant_t` a ser atribuído a um objeto existente `_bstr_t`.  
  
 **Fim da seção específica da Microsoft**  
  
## <a name="example"></a>Exemplo  
 Ver [_bstr_t::Assign](../cpp/bstr-t-assign.md) para obter um exemplo de como usar **operador =**.  
  
## <a name="see-also"></a>Consulte também  
 [Classe _bstr_t](../cpp/bstr-t-class.md)