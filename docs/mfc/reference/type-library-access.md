---
title: "Acesso &#224; biblioteca de tipos | Microsoft Docs"
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
  - "vc.mfc.macros"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "bibliotecas de tipo, acessando"
ms.assetid: a03fa7f0-86c2-4119-bf81-202916fb74b3
caps.latest.revision: 14
caps.handback.revision: 6
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Acesso &#224; biblioteca de tipos
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

As bibliotecas de tipo expõe as interfaces de um controlador OLE para outros aplicativos OLE\- reconhecimento de instância.  Cada controlador OLE deve ter uma biblioteca do tipo se uma ou várias interfaces devem ser exposto.  
  
 Os seguintes macros permitem que um controlador OLE fornece acesso a sua própria biblioteca de tipos:  
  
### Acesso da biblioteca de tipos  
  
|||  
|-|-|  
|[DECLARE\_OLETYPELIB](../Topic/DECLARE_OLETYPELIB.md)|Declara uma função de membro de `GetTypeLib` de um controlador OLE \(deve ser usado na declaração de classe\).|  
|[IMPLEMENT\_OLETYPELIB](../Topic/IMPLEMENT_OLETYPELIB.md)|Implementa uma função de membro de `GetTypeLib` de um controlador OLE \(deve ser usado na implementação da classe\).|  
  
## Consulte também  
 [Macros e globais](../../mfc/reference/mfc-macros-and-globals.md)