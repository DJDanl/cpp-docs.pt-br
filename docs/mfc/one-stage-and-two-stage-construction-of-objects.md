---
title: "Constru&#231;&#227;o de objetos em um e dois est&#225;gios | Microsoft Docs"
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
  - "criação do objeto, objetos gráficos"
  - "objetos [C++], criando objetos gráficos"
  - "objetos [C++], objetos gráficos"
  - "construção de objetos em um e dois estágios"
ms.assetid: 5a1c410c-4a4b-4dd9-a2ec-ced831aa7f21
caps.latest.revision: 10
caps.handback.revision: 6
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Constru&#231;&#227;o de objetos em um e dois est&#225;gios
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Você pode optar entre duas técnicas para criar objetos gráficos, como penalidades e escovas:  
  
-   *construção de uma fase*: Construir e inicializar o objeto está em fase, todas com o construtor.  
  
-   *Construção de dois estágios*: Construir e inicializar o objeto em duas fases separadas.  O construtor cria o objeto e uma função de inicialização para inicializá\-lo.  
  
 A construção de dois estágios sempre é mais segura.  Na construção de uma fase, o construtor pode gerar uma exceção se você fornecer argumentos incorretos ou a alocação de memória falha.  Esse problema pode ser evitado pela construção de dois estágios, embora você tem que verificar se há falha.  Em ambos os casos, destruir o objeto é o mesmo processo.  
  
> [!NOTE]
>  Essas técnicas se aplicam a criar todos os objetos, não apenas objetos gráficos.  
  
## Exemplo de ambas as técnicas de compilação  
 O seguinte exemplo mostra breve ambos os métodos de construir um objeto de forma:  
  
 [!code-cpp[NVC_MFCDocViewSDI#6](../mfc/codesnippet/CPP/one-stage-and-two-stage-construction-of-objects_1.cpp)]  
  
### Que você deseja saber mais?  
  
-   [Objetos gráficos](../mfc/graphic-objects.md)  
  
-   [Selecionando um objeto gráfico em um contexto do dispositivo](../mfc/selecting-a-graphic-object-into-a-device-context.md)  
  
-   [Contextos de dispositivo](../Topic/Device%20Contexts.md)  
  
-   [Desenhar em uma exibição](../mfc/drawing-in-a-view.md)  
  
## Consulte também  
 [Objetos gráficos](../mfc/graphic-objects.md)