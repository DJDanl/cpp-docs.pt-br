---
title: "_com_error::ErrorInfo | Microsoft Docs"
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
  - "_com_error::ErrorInfo"
  - "ErrorInfo"
  - "_com_error.ErrorInfo"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Método ErrorInfo"
ms.assetid: 071b446c-4395-4fb8-bd3d-300a8b25f5cd
caps.latest.revision: 6
caps.handback.revision: 6
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# _com_error::ErrorInfo
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

**Específico da Microsoft**  
  
 Recupera o objeto **IErrorInfo** passado para o construtor.  
  
## Sintaxe  
  
```  
  
IErrorInfo * ErrorInfo( ) const throw( );  
  
```  
  
## Valor de retorno  
 O item **IErrorInfo** bruto passado para o construtor.  
  
## Comentários  
 Recupera o item **IErrorInfo** encapsulado em um objeto `_com_error`, ou **NULL** se nenhum item **IErrorInfo** for registrado.  O chamador deve chamar **Release** no objeto retornado quando terminar de usá\-lo.  
  
 **FIM de Específico da Microsoft**  
  
## Consulte também  
 [Classe \_com\_error](../cpp/com-error-class.md)