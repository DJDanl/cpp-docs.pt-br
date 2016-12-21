---
title: "Macros de depura&#231;&#227;o e relat&#243;rio de erros | Microsoft Docs"
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
  - "macros, relatório de erros"
ms.assetid: 4da9b87f-ec5c-4a32-ab93-637780909b9d
caps.latest.revision: 18
caps.handback.revision: 7
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Macros de depura&#231;&#227;o e relat&#243;rio de erros
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Esses macros fornecem depurar útil rastreiam e recursos.  
  
|||  
|-|-|  
|[\_ATL\_DEBUG\_INTERFACES](../Topic/_ATL_DEBUG_INTERFACES.md)|Grava, a janela de saída, alguns vazamentos de interface que são detectados quando `_Module.Term` é chamado.|  
|[\_ATL\_DEBUG\_QI](../Topic/_ATL_DEBUG_QI.md)|Grava todas as chamadas a `QueryInterface` para a janela de saída.|  
|[ATLASSERT](../Topic/ATLASSERT.md)|Executa a mesma funcionalidade que a macro de [\_ASSERTE](../Topic/_ASSERT,%20_ASSERTE,%20_ASSERT_EXPR%20Macros.md) encontrado na biblioteca em tempo de execução de C.|  
|[ATLENSURE](../Topic/ATLENSURE.md)|Executa validação de parâmetros.  Chamada `AtlThrow` se necessário|  
|[ATLTRACENOTIMPL](../Topic/ATLTRACENOTIMPL.md)|Enviar uma mensagem para o dispositivo de despejo que a função especificada não está implementado.|  
|[ATLTRACE](../Topic/ATLTRACE%20\(ATL\).md)|Relata avisos para um dispositivo de saída, como a janela do depurador, de acordo com os sinalizadores e níveis indicados.  Incluído para compatibilidade com versões anteriores.|  
|[ATLTRACE2](../Topic/ATLTRACE2.md)|Relata avisos para um dispositivo de saída, como a janela do depurador, de acordo com os sinalizadores e níveis indicados.|  
  
## Consulte também  
 [Macros](../../atl/reference/atl-macros.md)   
 [Funções globais de depuração e relatório de erros](../../atl/reference/debugging-and-error-reporting-global-functions.md)