---
title: "Usando CObject | Microsoft Docs"
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
  - "CObject"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe CObject"
  - "classes derivadas, de CObject"
  - "exemplos [MFC], CObject"
  - "MFC, classe base"
  - "classe de base raiz para MFC"
ms.assetid: d0cd19bb-2856-4b41-abbc-620fd64cb223
caps.latest.revision: 9
caps.handback.revision: 5
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Usando CObject
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

[CObject](../Topic/CObject%20Class.md) é a classe base da raiz para a maioria da biblioteca de classes do Microsoft \(MFC\).  A classe de `CObject` contém muitos recursos úteis que você queira inserir em seu próprio programa objetos, inclusive o suporte de serialização, informações da classe de tempo de execução, objetos e saída de diagnóstico.  Se você deve derivar a sua classe de `CObject`, a sua classe pode explorar esses recursos de `CObject` .  
  
## O que você deseja fazer?  
  
-   [Derivar uma classe de CObject](../mfc/deriving-a-class-from-cobject.md)  
  
-   [Adicionar suporte para as informações da classe de tempo de execução, a criação dinâmico, e a serialização em uma classe derivada](../mfc/specifying-levels-of-functionality.md)  
  
-   [Acessar informações da classe de tempo de execução](../mfc/accessing-run-time-class-information.md)  
  
-   [Crie objetos dinamicamente](../Topic/Dynamic%20Object%20Creation.md)  
  
-   [Esvazia os dados do objeto para fins de diagnóstico](http://msdn.microsoft.com/pt-br/727855b1-5a83-44bd-9fe3-f1d535584b59)  
  
-   Validar o estado interno do objeto \(consulte [MFC ASSERT\_VALID e CObject::AssertValid](http://msdn.microsoft.com/pt-br/7654fb75-9e9a-499a-8165-0a96faf2d5e6)\)  
  
-   [Faça com que a classe serializar\-se para o repositório persistente](../Topic/Serialization%20in%20MFC.md)  
  
-   Consultar uma lista de [Perguntas frequentes de CObject](../mfc/cobject-class-frequently-asked-questions.md)  
  
## Consulte também  
 [Conceitos](../mfc/mfc-concepts.md)   
 [Tópicos MFC gerais](../mfc/general-mfc-topics.md)   
 [Estrutura de CRuntimeClass](../Topic/CRuntimeClass%20Structure.md)   
 [Arquivos](../mfc/files-in-mfc.md)   
 [Serialização](../Topic/Serialization%20in%20MFC.md)