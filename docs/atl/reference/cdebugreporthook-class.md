---
title: "Classe de CDebugReportHook | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "reference"
f1_keywords: 
  - "ATL.CDebugReportHook"
  - "CDebugReportHook"
  - "ATL::CDebugReportHook"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe de CDebugReportHook"
ms.assetid: 798076c3-6e63-4286-83b8-aa1bbcd0c20c
caps.latest.revision: 22
caps.handback.revision: 10
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe de CDebugReportHook
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Use esta classe para enviar relatórios de depuração para um pipe nomeado.  
  
## Sintaxe  
  
```  
  
class CDebugReportHook  
  
```  
  
## Membros  
  
### Construtores public  
  
|Nome|Descrição|  
|----------|---------------|  
|[CDebugReportHook::CDebugReportHook](../Topic/CDebugReportHook::CDebugReportHook.md)|Chamadas [SetPipeName](../Topic/CDebugReportHook::SetPipeName.md), [SetTimeout](../Topic/CDebugReportHook::SetTimeout.md), e [SetHook](../Topic/CDebugReportHook::SetHook.md).|  
|[CDebugReportHook::~CDebugReportHook](../Topic/CDebugReportHook::~CDebugReportHook.md)|Chamadas [CDebugReportHook::RemoveHook](../Topic/CDebugReportHook::RemoveHook.md).|  
  
### Métodos públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[CDebugReportHook::CDebugReportHookProc](../Topic/CDebugReportHook::CDebugReportHookProc.md)|\(Static\) Função personalizado de relatório que é enganchada no processo de relatório de depuração em tempo de execução de C.|  
|[CDebugReportHook::RemoveHook](../Topic/CDebugReportHook::RemoveHook.md)|Chamar esse método para interromper de enviar relatórios de depuração para o pipe nomeado e restaurar o gancho anterior de relatório.|  
|[CDebugReportHook::SetHook](../Topic/CDebugReportHook::SetHook.md)|Chamar esse método para iniciar enviar relatórios de depuração para o pipe nomeado.|  
|[CDebugReportHook::SetPipeName](../Topic/CDebugReportHook::SetPipeName.md)|Chamar esse método para definir o computador e o nome de pipe aos relatórios de depuração serão fornecidos.|  
|[CDebugReportHook::SetTimeout](../Topic/CDebugReportHook::SetTimeout.md)|Chamar esse método para definir a hora em milissegundos que essa classe esperará o pipe nomeado para estejam disponíveis.|  
  
## Comentários  
 Crie uma instância da classe em compilações de depuração dos serviços de aplicativos ou enviar relatórios de depuração para um pipe nomeado.  Os relatórios de depuração são gerados chamando [\_CrtDbgReport](../../c-runtime-library/reference/crtdbgreport-crtdbgreportw.md) ou usando um wrapper para essa função como macros de [ATLTRACE](../Topic/ATLTRACE%20\(ATL\).md) e de [ATLASSERT](../Topic/ATLASSERT.md) .  
  
 O uso de essa classe permite que você depure interativamente componentes que executam em [estações da janela](http://msdn.microsoft.com/library/windows/desktop/ms687096)não\-interativo.  
  
 Observe que os relatórios de depuração são enviados usando o contexto de segurança de segmentos subjacente.  A representação é desabilitado temporariamente para que os relatórios de depuração podem ser exibidos em situações onde a representação de baixo usuários de privilégio está ocorrendo, como em aplicativos web.  
  
## Requisitos  
 **Cabeçalho:** atlutil.h  
  
## Consulte também  
 [Classes](../../atl/reference/atl-classes.md)