---
title: "Construção de objetos em um e dois estágios | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
dev_langs: C++
helpviewer_keywords:
- objects [MFC], creating graphic objects
- object creation [MFC], graphic objects
- objects [MFC], graphic objects
- one-stage and two-stage construction of objects [MFC]
ms.assetid: 5a1c410c-4a4b-4dd9-a2ec-ced831aa7f21
caps.latest.revision: "10"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 677a29d4f0b65a9490f24a5906d606a05bb4573b
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="one-stage-and-two-stage-construction-of-objects"></a>Construção de objetos em um e dois estágios
Você pode escolher entre duas técnicas para criar objetos gráficos, como pincéis e canetas:  
  
-   *Construção de um estágio*: construção e inicializar o objeto em um estágio, tudo com o construtor.  
  
-   *Construção de dois estágios*: construção e inicializar o objeto em duas fases separadas. O construtor cria o objeto e a inicializa uma função de inicialização.  
  
 Construção de dois estágios sempre é mais segura. Na construção de um estágio, o construtor pode gerar uma exceção se você fornecer argumentos incorretos ou falha de alocação de memória. Esse problema é evitado pela construção de dois estágios, embora seja necessário que verificar se há falha. Em ambos os casos, destruir o objeto é o mesmo processo.  
  
> [!NOTE]
>  Essas técnicas se aplicam à criação de quaisquer objetos, os objetos gráficos não apenas.  
  
## <a name="example-of-both-construction-techniques"></a>Exemplo de ambas as técnicas de construção  
 O exemplo a seguir breve mostra ambos os métodos de construção de um objeto de caneta:  
  
 [!code-cpp[NVC_MFCDocViewSDI#6](../mfc/codesnippet/cpp/one-stage-and-two-stage-construction-of-objects_1.cpp)]  
  
### <a name="what-do-you-want-to-know-more-about"></a>O que você deseja saber mais sobre  
  
-   [Objetos gráficos](../mfc/graphic-objects.md)  
  
-   [Selecionando um objeto gráfico em um contexto de dispositivo](../mfc/selecting-a-graphic-object-into-a-device-context.md)  
  
-   [Contextos de dispositivo](../mfc/device-contexts.md)  
  
-   [Desenhando em uma exibição](../mfc/drawing-in-a-view.md)  
  
## <a name="see-also"></a>Consulte também  
 [Objetos gráficos](../mfc/graphic-objects.md)

