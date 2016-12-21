---
title: "Fun&#231;&#245;es globais de depura&#231;&#227;o e relat&#243;rio de erros | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "reference"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "funções [ATL], relatório de erros"
ms.assetid: 11339c02-98cd-428d-b3b9-7deeb155a6a3
caps.latest.revision: 17
caps.handback.revision: 5
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Fun&#231;&#245;es globais de depura&#231;&#227;o e relat&#243;rio de erros
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Essas funções fornecem depurar útil rastreiam e recursos.  
  
|||  
|-|-|  
|[AtlHresultFromLastError](../Topic/AtlHresultFromLastError.md)|Retorna um código de erro de `GetLastError` na forma de um HRESULT.|  
|[AtlHresultFromWin32](../Topic/AtlHresultFromWin32.md)|Converte um código de erro Win32 em um HRESULT.|  
|[AtlReportError](../Topic/AtlReportError.md)|Configura de **IErrorInfo** para fornecer detalhes de erro para um cliente.|  
|[AtlThrow](../Topic/AtlThrow.md)|Gera `CAtlException`.|  
|[AtlThrowLastWin32](../Topic/AtlThrowLastWin32.md)|Chamar essa função para sinalizar um erro com base no resultado da função do windows `GetLastError`.|  
|[AtlTraceLoadSettings](../../misc/atltraceloadsettings.md)|Chamar essa função para carregar configurações de rastreamento de um arquivo.|  
|[AtlTraceSaveSettings](../../misc/atltracesavesettings.md)|Chamar essa função para salvar as configurações atuais de rastreamento em um arquivo.|  
  
## Consulte também  
 [Funções](../../atl/reference/atl-functions.md)   
 [Macros de depuração e relatório de erros](../../atl/reference/debugging-and-error-reporting-macros.md)