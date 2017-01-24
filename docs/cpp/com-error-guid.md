---
title: "_com_error::GUID | Microsoft Docs"
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
  - "GUID"
  - "_com_error.GUID"
  - "_com_error::GUID"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Método GUID"
ms.assetid: e84c2c23-d02e-48f8-b776-9bd6937296d2
caps.latest.revision: 6
caps.handback.revision: 6
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# _com_error::GUID
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

**Específico da Microsoft**  
  
 Chama a função **IErrorInfo::GetGUID**.  
  
## Sintaxe  
  
```  
  
GUID GUID( ) const throw( );  
  
```  
  
## Valor de retorno  
 Retorna o resultado de **IErrorInfo::GetGUID** para o objeto **IErrorInfo** registrado no objeto `_com_error`.  Se nenhum objeto **IErrorInfo** for registrado, retorna `GUID_NULL`.  
  
## Comentários  
 Qualquer falha ao chamar o método **IErrorInfo::GetGUID** é ignorada.  
  
 **FIM de Específico da Microsoft**  
  
## Consulte também  
 [Classe \_com\_error](../cpp/com-error-class.md)