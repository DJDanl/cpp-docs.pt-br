---
title: Filosofia de Design da classe geral | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords: vc.classes.mfc
dev_langs: C++
helpviewer_keywords:
- designing classes [MFC]
- MFC, Windows API
- Visual C, Windows API calls
- classes [MFC], MFC class design
- Windows API [MFC], and MFC
ms.assetid: e6861ae0-1581-4d9c-9ddf-63f9afcdb913
caps.latest.revision: "9"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.openlocfilehash: 7e4c5c15e7d18fb768b7b0fffa99140ae64075da
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
---
# <a name="general-class-design-philosophy"></a>Filosofia de design da classe geral
Microsoft Windows foi projetado muito antes que a linguagem C++ se tornou popular. Como milhares de aplicativos usam a interface de programação de aplicativo (API) do Windows da linguagem C, essa interface será mantida para um futuro próximo. Nenhuma interface do Windows do C++, portanto, deve ser criada sobre a procedimento API da linguagem C. Isso garante que os aplicativos C++ poderão coexistir com aplicativos C.  
  
 A biblioteca Microsoft Foundation Class é uma interface orientada a objeto para o Windows que atenda aos seguintes objetivos de design:  
  
-   Redução significativa na tentativa de gravar um aplicativo do Windows.  
  
-   Velocidade de execução comparável ao que a API da linguagem C.  
  
-   Sobrecarga de tamanho mínimo de código.  
  
-   Capacidade de chamar qualquer função de C do Windows diretamente.  
  
-   Conversão mais fácil de aplicativos existentes de C para C++.  
  
-   Capacidade de aproveitar de base existente da linguagem C de experiência de programação do Windows.  
  
-   Facilitar o uso da API do Windows com C++ que com C.  
  
-   Mais fácil de uso ainda poderosas abstrações de complicado recursos, como controles ActiveX, suporte de banco de dados, impressão, barras de ferramentas e barras de status.  
  
-   API do Windows True para C++ que usa com eficiência os recursos de linguagem do C++.  
  
 Para obter mais informações sobre o design da biblioteca MFC, consulte:  
  
-   [A estrutura de aplicativo](../mfc/application-framework.md)  
  
-   [Relacionamento com a API da linguagem C](../mfc/relationship-to-the-c-language-api.md)  
  
## <a name="see-also"></a>Consulte também  
 [Visão geral da classe](../mfc/class-library-overview.md)

