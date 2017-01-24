---
title: "Interfaces (ATL) | Microsoft Docs"
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
  - "Interfaces COM"
  - "interfaces, COM"
ms.assetid: de6c8b12-6230-4fdc-af66-a28b91d5ee55
caps.latest.revision: 10
caps.handback.revision: 5
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Interfaces (ATL)
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Uma interface é a maneira que um objeto expor sua funcionalidade ao mundo externo.  Em, COM uma interface é uma tabela de ponteiros \(como C\+\+\) vtable funções implementadas pelo objeto.  A tabela representa a interface, e funções a que ele apontam são os métodos da interface.  Um objeto pode expor tantas interfaces como escolher.  
  
 Cada interface é baseado na interface fundamental de COM, [IUnknown](../atl/iunknown.md).  Os métodos de **IUnknown** permitem a navegação para outras interfaces expostas pelo objeto.  
  
 Além de isso, cada interface é fornecida uma identificação exclusiva de interface \(IID\).  Esta exclusividade facilita oferecer suporte ao controle de versão da interface.  Uma nova versão de uma interface é simplesmente uma nova interface, com um novo IID.  
  
> [!NOTE]
>  Para IIDs COM padrão e interfaces VELHOS são predefinidos.  
  
## Consulte também  
 [Introdução ao COM](../atl/introduction-to-com.md)   
 [COM Objects and Interfaces](http://msdn.microsoft.com/library/windows/desktop/ms690343)