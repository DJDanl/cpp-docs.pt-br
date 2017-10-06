---
title: _com_error::ErrorMessage | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-language
ms.tgt_pltfrm: 
ms.topic: language-reference
f1_keywords:
- _com_error::ErrorMessage
dev_langs:
- C++
helpviewer_keywords:
- ErrorMessage method
ms.assetid: e47335b6-01af-4975-a841-121597479eb7
caps.latest.revision: 6
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
ms.openlocfilehash: 01f244a07e46c70cbd4810af666f55dc899e5c3a
ms.contentlocale: pt-br
ms.lasthandoff: 09/25/2017

---
# <a name="comerrorerrormessage"></a>_com_error::ErrorMessage
**Seção específica da Microsoft**  
  
 Recupera a mensagem de cadeia de caracteres para `HRESULT` armazenado no objeto `_com_error`.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
  
const TCHAR * ErrorMessage( ) const throw( );  
  
```  
  
## <a name="return-value"></a>Valor de retorno  
 Retorna a mensagem de cadeia de caracteres para `HRESULT`, registrado no objeto `_com_error`. Se o `HRESULT` é um mapeada 16 bits [wCode](../cpp/com-error-wcode.md), em seguida, uma mensagem genérica "`IDispatch error #<wCode>`" é retornado. Se nenhuma mensagem for encontrada, então uma mensagem genérica "`Unknown error #<hresult>`" será retornada. A cadeia de caracteres retornada é Unicode ou cadeia de caracteres multibyte, dependendo do estado do **Unicode** macro.  
  
## <a name="remarks"></a>Comentários  
 Recupera o texto da mensagem apropriada do sistema para `HRESULT`, gravado no objeto `_com_error`. O texto de mensagem do sistema é obtido chamando o Win32 [FormatMessage](http://msdn.microsoft.com/library/windows/desktop/ms679351) função. A cadeia de caracteres retornada é alocada pela API `FormatMessage` e é liberada quando o objeto `_com_error` é destruído.  
  
 **Fim da seção específica da Microsoft**  
  
## <a name="see-also"></a>Consulte também  
 [Classe _com_error](../cpp/com-error-class.md)
