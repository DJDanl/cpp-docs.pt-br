---
title: "_com_error::HelpContext | Microsoft Docs"
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
  - "_com_error::HelpContext"
  - "HelpContext"
  - "_com_error.HelpContext"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Método HelpContext"
ms.assetid: 160d6443-9b68-4cf5-a540-50da951a5b2b
caps.latest.revision: 6
caps.handback.revision: 6
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# _com_error::HelpContext
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

**Específico da Microsoft**  
  
 Chama a função **IErrorInfo::GetHelpContext**.  
  
## Sintaxe  
  
```  
  
DWORD HelpContext( ) const throw( );  
  
```  
  
## Valor de retorno  
 Retorna o resultado de **IErrorInfo::GetHelpContext** para o objeto **IErrorInfo** registrado no objeto `_com_error`.  Se nenhum objeto **IErrorInfo** for registrado, retornará zero.  
  
## Comentários  
 Qualquer falha ao chamar o método **IErrorInfo::GetHelpContext** é ignorada.  
  
 **FIM de Específico da Microsoft**  
  
## Consulte também  
 [Classe \_com\_error](../cpp/com-error-class.md)