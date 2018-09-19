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
ms.openlocfilehash: 35778fe3bdf75738f67b280cbbe4c8ceeb498634
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46016995"
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

*S1*<br/>
Um objeto `_bstr_t` a ser atribuído a um objeto existente `_bstr_t`.

*S2*<br/>
Uma cadeia de caracteres multibyte a ser atribuída a um objeto `_bstr_t` existente.

*S3*<br/>
Uma cadeia de caracteres Unicode a ser atribuída a um objeto `_bstr_t` existente.

*var*<br/>
Um objeto `_variant_t` a ser atribuído a um objeto existente `_bstr_t`.

**Fim da seção específica da Microsoft**

## <a name="example"></a>Exemplo

Ver [_bstr_t::Assign](../cpp/bstr-t-assign.md) para obter um exemplo de como usar **operador =**.

## <a name="see-also"></a>Consulte também

[Classe _bstr_t](../cpp/bstr-t-class.md)