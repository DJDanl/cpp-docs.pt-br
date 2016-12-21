---
title: "CDataSource::GetInitializationString | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
f1_keywords: 
  - "ATL::CDataSource::GetInitializationString"
  - "CDataSource.GetInitializationString"
  - "GetInitializationString"
  - "CDataSource::GetInitializationString"
  - "ATL.CDataSource.GetInitializationString"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Método GetInitializationString"
ms.assetid: 97134723-6e99-4004-a56d-ec57543dbf3b
caps.latest.revision: 8
caps.handback.revision: 8
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# CDataSource::GetInitializationString
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Recupera a cadeia de caracteres de inicialização de uma fonte de dados que está aberta.  
  
## Sintaxe  
  
```  
  
      HRESULT GetInitializationString(   
   BSTR* pInitializationString,   
   bool bIncludePassword = false    
) throw( );  
```  
  
#### Parâmetros  
 *pInitializationString*  
 \[out\] ponteiro para a cadeia de caracteres de inicialização.  
  
 *bIncludePassword*  
 \[in\] **true** se a cadeia de caracteres inclui uma senha; se não **false**.  
  
## Valor de retorno  
 `HRESULT`padrão.  
  
## Comentários  
 A cadeia de caracteres de inicialização resultante pode ser usada para reabrir posteriormente esta conexão de fonte de dados.  
  
## Requisitos  
 **Header:** atldbcli.h  
  
## Consulte também  
 [Classe CDataSource](../Topic/CDataSource%20Class.md)