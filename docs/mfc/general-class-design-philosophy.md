---
title: Filosofia de Design da classe geral | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: conceptual
f1_keywords:
- vc.classes.mfc
dev_langs:
- C++
helpviewer_keywords:
- designing classes [MFC]
- MFC, Windows API
- Visual C, Windows API calls
- classes [MFC], MFC class design
- Windows API [MFC], and MFC
ms.assetid: e6861ae0-1581-4d9c-9ddf-63f9afcdb913
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 7b2d0915c4b2940e93b781e7a56e2640c64a7f20
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
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

