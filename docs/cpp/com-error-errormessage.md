---
title: _com_error::ErrorMessage
ms.date: 11/04/2016
f1_keywords:
- _com_error::ErrorMessage
helpviewer_keywords:
- ErrorMessage method [C++]
ms.assetid: e47335b6-01af-4975-a841-121597479eb7
ms.openlocfilehash: b1c1b5a79cdf5ee2a4a17d969d23ce0d0d85ab54
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62155176"
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