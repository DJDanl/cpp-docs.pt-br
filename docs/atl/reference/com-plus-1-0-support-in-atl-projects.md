---
title: "Suporte para COM+ 1.0 em projetos ATL | Microsoft Docs"
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
  - "vc.appwiz.ATL.MTS"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "projetos ATL, suporte para COM+ 1.0"
ms.assetid: 51fb08ac-d632-4657-a4e0-d3f989f0b6f8
caps.latest.revision: 10
caps.handback.revision: 5
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Suporte para COM+ 1.0 em projetos ATL
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Você pode usar [Assistente de projeto de ATL](../../atl/reference/creating-an-atl-project.md) para criar um projeto com suporte básico para componentes com \+ 1,0.  
  
 COM\+ 1,0 é criado desenvolvendo aplicativos baseados em componentes distribuídos.  Também fornece uma infra\-estrutura de tempo de execução para implantar e gerenciar esses aplicativos.  
  
 Se você marcar a caixa de seleção de **Support COM\+ 1.0** , o assistente altera o script de compilação na etapa de link.  Especificamente, os links de projeto COM\+ 1,0 para bibliotecas seguintes:  
  
-   comsvcs.lib  
  
-   Mtxguid.lib  
  
 Se você marcar a caixa de seleção de **Support COM\+ 1.0** , você também pode selecionar **Support component registrar**.  O escrivão componente permite que seu objeto COM\+ 1,0 obter uma lista de componentes, de componentes do registro, ou de componentes de unregister \(individualmente ou de uma vez.\)  
  
## Consulte também  
 [Fundamentos de objetos COM de ATL](../../atl/fundamentals-of-atl-com-objects.md)   
 [Programando com código de tempo de execução ATL e C](../../atl/programming-with-atl-and-c-run-time-code.md)   
 [Configurações padrão do projeto ATL](../../atl/reference/default-atl-project-configurations.md)