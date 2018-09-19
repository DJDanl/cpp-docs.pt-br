---
title: _com_error::ErrorMessage | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-language
ms.topic: language-reference
f1_keywords:
- _com_error::ErrorMessage
dev_langs:
- C++
helpviewer_keywords:
- ErrorMessage method [C++]
ms.assetid: e47335b6-01af-4975-a841-121597479eb7
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: afe11d570658ee077e8fdffe925349731f1921fd
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46111362"
---
# <a name="comerrorerrormessage"></a>_com_error::ErrorMessage

**Seção específica da Microsoft**

Recupera a mensagem de cadeia de caracteres para o HRESULT armazenado no objeto `_com_error`.

## <a name="syntax"></a>Sintaxe

```
const TCHAR * ErrorMessage( ) const throw( );
```

## <a name="return-value"></a>Valor de retorno

Retorna a mensagem de cadeia de caracteres para o HRESULT é registrado no `_com_error` objeto. Se o HRESULT for um 16 bits mapeado [wCode](../cpp/com-error-wcode.md), em seguida, uma mensagem genérica "`IDispatch error #<wCode>`" é retornado. Se nenhuma mensagem for encontrada, então uma mensagem genérica "`Unknown error #<hresult>`" será retornada. A cadeia de caracteres retornada é uma cadeia de caracteres multibyte, dependendo do estado da macro Unicode ou Unicode.

## <a name="remarks"></a>Comentários

Recupera o texto da mensagem apropriada do sistema para o HRESULT é registrado no `_com_error` objeto. O texto de mensagem do sistema é obtido chamando o Win32 [FormatMessage](/windows/desktop/api/winbase/nf-winbase-formatmessage) função. A cadeia de caracteres retornada é alocada pela API `FormatMessage` e é liberada quando o objeto `_com_error` é destruído.

**Fim da seção específica da Microsoft**

## <a name="see-also"></a>Consulte também

[Classe _com_error](../cpp/com-error-class.md)