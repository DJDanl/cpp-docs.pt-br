---
title: "Filosofia de design da classe geral | Microsoft Docs"
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
  - "vc.classes.mfc"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "classes [C++], projeto de classe de MFC"
  - "projetando classes"
  - "MFC [C++], API do Windows"
  - "Visual C, Chamadas à API do Windows"
  - "API do Windows [C++], e MFC"
ms.assetid: e6861ae0-1581-4d9c-9ddf-63f9afcdb913
caps.latest.revision: 9
caps.handback.revision: 5
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Filosofia de design da classe geral
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Microsoft Windows foi criado muito antes da linguagem C\+\+ fosse popular.  Como os milhares de aplicativos usam a interface de programação de aplicativo \(API\) do Windows do C \- idioma, essa interface será mantida para o futuro próximo.  Qualquer interface do windows C\+\+ em virtude disso deve ser criada sobre o C \- idioma API de procedimento.  Isso garante que os aplicativos C\+\+ podem coexistir com aplicativos C.  
  
 A biblioteca de classes do Microsoft é uma interface orientada a objeto para o windows que satisfaça os seguintes metas de design:  
  
-   Redução significativa no máximo para escrever um aplicativo do windows.  
  
-   Comparável a velocidade de execução de linguagem C \- API.  
  
-   Sobrecarga mínima do tamanho de código.  
  
-   Capacidade de chamar diretamente qualquer função C do windows.  
  
-   Conversão mais fácil dos aplicativos existentes de C a C\+\+.  
  
-   Capacidade de aproveitar a base existente do windows do C \- linguagem de programação a experiência do.  
  
-   Uso mais fácil da API do windows com C\+\+ do que com C.  
  
-   Mais fácil de usar o entanto abstrações avançadas de recursos complicada como controles ActiveX, suporte da base de dados, impressão, barras de ferramentas, e barras de status.  
  
-   Retifique API do windows para C\+\+ que usa recursos efetivamente de linguagem C\+\+.  
  
 Para obter mais na criação da biblioteca MFC, consulte:  
  
-   [A estrutura de aplicativo](../mfc/application-framework.md)  
  
-   [Relação a linguagem C \- API](../mfc/relationship-to-the-c-language-api.md)  
  
## Consulte também  
 [Visão geral da classe](../mfc/class-library-overview.md)