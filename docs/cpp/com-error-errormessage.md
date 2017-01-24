---
title: "_com_error::ErrorMessage | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "language-reference"
f1_keywords: 
  - "_com_error::ErrorMessage"
  - "_com_error.ErrorMessage"
  - "ErrorMessage"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Método ErrorMessage"
ms.assetid: e47335b6-01af-4975-a841-121597479eb7
caps.latest.revision: 6
caps.handback.revision: 6
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# _com_error::ErrorMessage
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

**Específico da Microsoft**  
  
 Recupera a mensagem de cadeia de caracteres para `HRESULT` armazenado no objeto `_com_error`.  
  
## Sintaxe  
  
```  
  
const TCHAR * ErrorMessage( ) const throw( );  
  
```  
  
## Valor de retorno  
 Retorna a mensagem de cadeia de caracteres para `HRESULT`, registrado no objeto `_com_error`.  Se `HRESULT` for um [wCode](../cpp/com-error-wcode.md)de 16 bits mapeado, uma mensagem genérica "`IDispatch error #<wCode>`" será retornada.  Se nenhuma mensagem for encontrada, então uma mensagem genérica "`Unknown error #<hresult>`" será retornada.  A cadeia de caracteres retornada será uma cadeia de caracteres Unicode ou multibyte, dependendo do estado da macro **\_UNICODE**.  
  
## Comentários  
 Recupera o texto da mensagem apropriada do sistema para `HRESULT`, gravado no objeto `_com_error`.  O texto da mensagem do sistema é obtido chamando a função do Win32 [FormatMessage](http://msdn.microsoft.com/library/windows/desktop/ms679351).  A cadeia de caracteres retornada é alocada pela API `FormatMessage` e é liberada quando o objeto `_com_error` é destruído.  
  
 **FIM de Específico da Microsoft**  
  
## Consulte também  
 [Classe \_com\_error](../cpp/com-error-class.md)