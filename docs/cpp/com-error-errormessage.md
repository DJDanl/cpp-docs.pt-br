---
title: _com_error::ErrorMessage | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-language
ms.tgt_pltfrm: 
ms.topic: language-reference
f1_keywords: _com_error::ErrorMessage
dev_langs: C++
helpviewer_keywords: ErrorMessage method [C++]
ms.assetid: e47335b6-01af-4975-a841-121597479eb7
caps.latest.revision: "6"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: e8690c23acf6e42d355cf122f59f54e19cc36d66
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
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