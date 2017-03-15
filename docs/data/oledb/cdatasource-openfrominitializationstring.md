---
title: "CDataSource::OpenFromInitializationString | Microsoft Docs"
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
  - "CDataSource.OpenFromInitializationString"
  - "OpenFromInitializationString"
  - "CDataSource::OpenFromInitializationString"
  - "ATL::CDataSource::OpenFromInitializationString"
  - "ATL.CDataSource.OpenFromInitializationString"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Método OpenFromInitializationString"
ms.assetid: 5ef1f1fd-92a9-4e1c-ad80-d3601b094b8c
caps.latest.revision: 10
caps.handback.revision: 10
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# CDataSource::OpenFromInitializationString
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Abre uma fonte de dados especificada pela cadeia de caracteres de inicialização fornecida pelo usuário.  
  
## Sintaxe  
  
```  
  
      HRESULT OpenFromInitializationString(   
   LPCOLESTR szInitializationString,   
   bool fPromptForInfo = false    
) throw( );  
```  
  
#### Parâmetros  
 *szInitializationString*  
 \[in\] a cadeia de caracteres de inicialização.  
  
 *fPromptForInfo*  
 \[in\] se esse argumento é definido como **true**, então `OpenFromInitializationString` definirá a propriedade de **DBPROP\_INIT\_PROMPT** a **DBPROMPT\_COMPLETEREQUIRED**, que especifica que o usuário seja solicitado apenas se mais informações é necessária.  Isso é útil em situações nas quais a cadeia de caracteres de inicialização especifica um base de dados que requer uma senha, mas a cadeia de caracteres não contém a senha.  O usuário será solicitado a fornecer uma senha \(ou qualquer outra informações ausentes\) ao tentar se conectar ao base de dados.  
  
 O valor padrão é **false**, que especifica que o usuário seja solicitado \(nunca conjuntos **DBPROP\_INIT\_PROMPT** a **DBPROMPT\_NOPROMPT**\).  
  
## Valor de retorno  
 `HRESULT`padrão.  
  
## Comentários  
 Este método abre um objeto de fonte de dados usando os componentes de serviço em oledb32.dll; este DLL contém a implementação de recursos dos componentes de serviço como um recurso de cluster, inscrição automática da transação, e assim por diante.  
  
## Requisitos  
 **Header:** atldbcli.h  
  
## Consulte também  
 [Classe CDataSource](../Topic/CDataSource%20Class.md)