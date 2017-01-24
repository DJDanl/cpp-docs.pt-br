---
title: "CDataSource::OpenWithPromptFileName | Microsoft Docs"
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
  - "CDataSource.OpenWithPromptFileName"
  - "OpenWithPromptFileName"
  - "ATL::CDataSource::OpenWithPromptFileName"
  - "ATL.CDataSource.OpenWithPromptFileName"
  - "CDataSource::OpenWithPromptFileName"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Método OpenWithPromptFileName"
ms.assetid: 89460504-1aaf-4412-aa7b-fa5a4b39ada3
caps.latest.revision: 10
caps.handback.revision: 10
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# CDataSource::OpenWithPromptFileName
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Este método solicita ao usuário uma caixa de diálogo, então, abre uma fonte de dados usando o arquivo especificado pelo usuário.  
  
## Sintaxe  
  
```  
  
        HRESULT OpenWithPromptFileName(   
   HWND hWnd = GetActiveWindow(   
   ),   
   DBPROMPTOPTIONS dwPromptOptions = DBPROMPTOPTIONS_NONE,   
   LPCOLESTR szInitialDirectory = NULL    
) throw( );  
```  
  
#### Parâmetros  
 `hWnd`  
 \[in\] Identificador para a janela que deve ser o pai da caixa de diálogo.  
  
 `dwPromptOptions`  
 \[in\] Determina o estilo da caixa de diálogo de localizador para exibir.  Consulte Msdasc.h para obter valores possíveis.  
  
 *szInitialDirectory*  
 \[in\] O diretório inicial para exibir a caixa de diálogo do localizador.  
  
## Valor de retorno  
 Um padrão `HRESULT`.  
  
## Comentários  
 Este método abre um objeto de fonte de dados usando os componentes de serviço em Oledb32; Essa DLL contém a implementação de recursos de componentes de serviço, como o pool de recursos, a inscrição automática de transação e assim por diante.  Para obter mais informações, consulte "Serviço OLE DB" na referência de OLE DB do programador em [http:\/\/msdn.microsoft.com\/library\/default.asp?url\=\/library\/oledb\/htm\/oledbole\_db\_services.asp?frame\=true](http://msdn.microsoft.com/library/default.asp?url=/library/oledb/htm/oledbole_db_services.asp?frame=true).  
  
## Requisitos  
 **Cabeçalho:** atldbcli.h  
  
## Consulte também  
 [Classe CDataSource](../Topic/CDataSource%20Class.md)