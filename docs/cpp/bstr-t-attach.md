---
title: _bstr_t::Attach | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-language
ms.topic: language-reference
f1_keywords:
- _bstr_t::Attach
dev_langs:
- C++
helpviewer_keywords:
- Attach method [C++]
ms.assetid: 8cad867e-40fc-435b-841f-0d412c2f58d3
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 1eddbc7a01be66430759bb84c3ce6d840f37d098
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46111206"
---
# <a name="bstrtattach"></a>_bstr_t::Attach

**Seção específica da Microsoft**

Vincula um wrapper `_bstr_t` a um `BSTR`.

## <a name="syntax"></a>Sintaxe

```
void Attach(
   BSTR s
);
```

#### <a name="parameters"></a>Parâmetros

*s*<br/>
Um `BSTR` a ser associado ou atribuído à variável `_bstr_t`.

## <a name="remarks"></a>Comentários

Se o `_bstr_t` estava associado anteriormente a outro `BSTR`, o `_bstr_t` limpará o recurso `BSTR`, se nenhuma outra variável `_bstr_t` estiver usando o `BSTR`.

## <a name="example"></a>Exemplo

Ver [_bstr_t::Assign](../cpp/bstr-t-assign.md) para obter um exemplo de uso **Attach**.

**Fim da seção específica da Microsoft**

## <a name="see-also"></a>Consulte também

[Classe _bstr_t](../cpp/bstr-t-class.md)