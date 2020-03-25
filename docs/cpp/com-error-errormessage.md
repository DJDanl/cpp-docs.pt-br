---
title: _com_error::ErrorMessage
ms.date: 11/04/2016
f1_keywords:
- _com_error::ErrorMessage
helpviewer_keywords:
- ErrorMessage method [C++]
ms.assetid: e47335b6-01af-4975-a841-121597479eb7
ms.openlocfilehash: b5e884956b5a51d3c714f1a81dc6945409f74f4b
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80180661"
---
# <a name="_com_errorerrormessage"></a>_com_error::ErrorMessage

**Seção específica da Microsoft**

Recupera a mensagem de cadeia de caracteres para o HRESULT armazenado no objeto `_com_error`.

## <a name="syntax"></a>Sintaxe

```
const TCHAR * ErrorMessage( ) const throw( );
```

## <a name="return-value"></a>Valor retornado

Retorna a mensagem de cadeia de caracteres para o HRESULT registrado no objeto `_com_error`. Se o HRESULT for um [wCode](../cpp/com-error-wcode.md)de 16 bits mapeado, uma mensagem genérica "`IDispatch error #<wCode>`" será retornada. Se nenhuma mensagem for encontrada, então uma mensagem genérica "`Unknown error #<hresult>`" será retornada. A cadeia de caracteres retornada será uma cadeia de caracteres Unicode ou multibyte, dependendo do estado da macro _UNICODE.

## <a name="remarks"></a>Comentários

Recupera o texto apropriado da mensagem do sistema para HRESULT registrado no objeto `_com_error`. O texto da mensagem do sistema é obtido chamando a função [FormatMessage](/windows/win32/api/winbase/nf-winbase-formatmessage) do Win32. A cadeia de caracteres retornada é alocada pela API `FormatMessage` e é liberada quando o objeto `_com_error` é destruído.

**Fim da seção específica da Microsoft**

## <a name="see-also"></a>Confira também

[Classe _com_error](../cpp/com-error-class.md)
