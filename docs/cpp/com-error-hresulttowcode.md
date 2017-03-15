---
title: "_com_error::HRESULTToWCode | Microsoft Docs"
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
  - "HRESULTToWCode"
  - "_com_error.HRESULTToWCode"
  - "_com_error::HRESULTToWCode"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Método HRESULTToWCode"
ms.assetid: ff3789f5-1047-41a0-b7e3-86dd8f638dba
caps.latest.revision: 6
caps.handback.revision: 6
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# _com_error::HRESULTToWCode
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

**Específico da Microsoft**  
  
 Mapeia um `HRESULT` de 32 bits para um `wCode` de 16 bits.  
  
## Sintaxe  
  
```  
  
      static WORD HRESULTToWCode(  
   HRESULT hr   
) throw( );  
```  
  
#### Parâmetros  
 `hr`  
 O `HRESULT` de 32 bits a ser mapeado para o  `wCode` de 16 bits.  
  
## Valor de retorno  
 O `wCode` de 16 bits mapeado para o `HRESULT` de 32 bits.  
  
## Comentários  
 Consulte [\_com\_error::WCode](../cpp/com-error-wcode.md) para obter mais informações.  
  
 **FIM de Específico da Microsoft**  
  
## Consulte também  
 [\_com\_error::WCode](../cpp/com-error-wcode.md)   
 [\_com\_error::WCodeToHRESULT](../Topic/_com_error::WCodeToHRESULT.md)   
 [Classe \_com\_error](../cpp/com-error-class.md)