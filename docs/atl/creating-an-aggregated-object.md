---
title: "Criando um objeto agregado | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "objetos agregados [C++], criando"
  - "agregação [C++], criando objetos agregados"
ms.assetid: fc29d7aa-fd53-4276-9c2f-37379f71b179
caps.latest.revision: 10
caps.handback.revision: 5
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Criando um objeto agregado
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

A agregação delega chamadas de **IUnknown** , fornecendo um ponteiro para **IUnknown** do objeto externo ao objeto interno.  
  
### Para criar um objeto agregado  
  
1.  Adicione um ponteiro de **IUnknown** ao objeto da classe e inicializá\-la a **NULO** no construtor.  
  
2.  Substituição [FinalConstruct](../Topic/CComObjectRootEx::FinalConstruct.md) para criar uma agregação.  
  
3.  Use o ponteiro de **IUnknown** , definido na etapa 1, como o segundo parâmetro para macros de [COM\_INTERFACE\_ENTRY\_AGGREGATE](../Topic/COM_INTERFACE_ENTRY_AGGREGATE.md) .  
  
4.  Substituição [FinalRelease](../Topic/CComObjectRootEx::FinalRelease.md) para liberar o ponteiro de **IUnknown** .  
  
> [!NOTE]
>  Se você usar e libera uma interface de objeto agregado durante `FinalConstruct`, você deve adicionar a macro de [DECLARE\_PROTECT\_FINAL\_CONSTRUCT](../Topic/DECLARE_PROTECT_FINAL_CONSTRUCT.md) a definição do seu objeto da classe.  
  
## Consulte também  
 [Fundamentos de objetos COM de ATL](../atl/fundamentals-of-atl-com-objects.md)