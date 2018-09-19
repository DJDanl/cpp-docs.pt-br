---
title: _com_error::Error | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-language
ms.topic: language-reference
f1_keywords:
- _com_error::Error
- Error
dev_langs:
- C++
helpviewer_keywords:
- Error method [C++]
ms.assetid: b53a15fd-198e-4276-afcd-13439c4807f7
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 9d56fcf7faaee9d3b0e02964163aa62372a30a78
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46109283"
---
# <a name="comerrorerror"></a>_com_error::Error

**Seção específica da Microsoft**

Recupera o HRESULT transmitido ao construtor.

## <a name="syntax"></a>Sintaxe

```
HRESULT Error( ) const throw( );
```

## <a name="return-value"></a>Valor de retorno

Item HRESULT bruto passado para o construtor.

## <a name="remarks"></a>Comentários

Recupera o item HRESULT encapsulado em um `_com_error` objeto.

**Fim da seção específica da Microsoft**

## <a name="see-also"></a>Consulte também

[Classe _com_error](../cpp/com-error-class.md)