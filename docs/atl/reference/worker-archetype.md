---
title: "Arqu&#233;tipo de trabalho | Microsoft Docs"
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
  - "Arquétipo de trabalho"
ms.assetid: 834145cd-09d3-4149-bc99-620e1871cbfb
caps.latest.revision: 16
caps.handback.revision: 8
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Arqu&#233;tipo de trabalho
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

As classes de acordo com o arquétipo *de trabalho* fornecem código para itens de trabalho de processo enfileirados em um pool de segmentos.  
  
 **Implementação**  
  
 Para implementar uma classe que está de acordo com esse arquétipo, a classe deve fornecer os seguintes recursos:  
  
|Método|Descrição|  
|------------|---------------|  
|[Inicializar](../Topic/WorkerArchetype::Initialize.md)|Chamado para inicializar o objeto de trabalho antes de todas as solicitações são passados para [Executar](../Topic/WorkerArchetype::Execute.md).|  
|[Executar](../Topic/WorkerArchetype::Execute.md)|Chamado para processar um item de trabalho.|  
|[Terminar](../Topic/WorkerArchetype::Terminate.md)|Chamado para uninitialize as solicitações de trabalho do objeto que foram passados a [Executar](../Topic/WorkerArchetype::Execute.md).|  
  
|Typedef|Descrição|  
|-------------|---------------|  
|[RequestType](../Topic/WorkerArchetype::RequestType.md)|Um typedef para o tipo de item de trabalho que pode ser processado pela classe de trabalho.|  
  
 Os aspectos *de trabalho* típicos de uma classe como este:  
  
 [!CODE [NVC_ATL_Utilities#137](../CodeSnippet/VS_Snippets_Cpp/NVC_ATL_Utilities#137)]  
  
 **Implementações existentes**  
  
 Essas classes obedecem a este arquétipo:  
  
|Classe|Descrição|  
|------------|---------------|  
|[CNonStatelessWorker](../Topic/CNonStatelessWorker%20Class.md)|Recebe solicitações do pool de segmentos e passá\-las sobre a um objeto de trabalho que é criado e destruído para cada solicitação.|  
  
 **Uso**  
  
 Esses parâmetros de modelo esperam a classe este arquétipo a seguir:  
  
|Nome de parâmetro|Usado por|  
|-----------------------|---------------|  
|*Trabalhador*|[CThreadPool](../Topic/CThreadPool%20Class.md)|  
|*Trabalhador*|[CNonStatelessWorker](../Topic/CNonStatelessWorker%20Class.md)|  
  
## Requisitos  
 **Cabeçalho:** atlutil.h  
  
## Consulte também  
 [Arquétipos](../../atl/reference/atl-archetypes.md)   
 [Conceitos](../../atl/active-template-library-atl-concepts.md)   
 [Componentes da área de trabalho COM ATL](../../atl/atl-com-desktop-components.md)