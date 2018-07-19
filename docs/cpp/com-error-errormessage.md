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
ms.openlocfilehash: 2bff5e8f84b316f028daf503c3013667c82aaa4e
ms.sourcegitcommit: 1fd1eb11f65f2999dfd93a2d924390ed0a0901ed
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/10/2018
ms.locfileid: "37940560"
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
 Recupera o texto da mensagem apropriada do sistema para o HRESULT é registrado no `_com_error` objeto. O texto de mensagem do sistema é obtido chamando o Win32 [FormatMessage](http://msdn.microsoft.com/library/windows/desktop/ms679351) função. A cadeia de caracteres retornada é alocada pela API `FormatMessage` e é liberada quando o objeto `_com_error` é destruído.  
  
 **Fim da seção específica da Microsoft**  
  
## <a name="see-also"></a>Consulte também  
 [Classe _com_error](../cpp/com-error-class.md)