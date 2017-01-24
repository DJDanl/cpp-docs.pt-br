---
title: "Imprimindo em controles de edi&#231;&#227;o avan&#231;ada | Microsoft Docs"
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
  - "Classe CRichEditCtrl, imprimindo"
  - "imprimindo [MFC], CRichEditCtrl"
  - "controles de edição avançada, imprimindo"
ms.assetid: dbda0e40-018f-424e-b5d8-7b489aaf27af
caps.latest.revision: 10
caps.handback.revision: 6
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Imprimindo em controles de edi&#231;&#227;o avan&#231;ada
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Você pode perceber um controle de edição avançado \([CRichEditCtrl](../Topic/CRichEditCtrl%20Class.md)\) para renderizar sua saída para um dispositivo especificado, como uma impressora.  Você também pode especificar o dispositivo de saída para que os formatos de controle de edição avançada do texto.  
  
 Para formatar a parte do conteúdo de um controle de edição avançado para um determinado dispositivo, você pode usar a função de membro de [FormatRange](../Topic/CRichEditCtrl::FormatRange.md) .  A estrutura de [FORMATRANGE](http://msdn.microsoft.com/library/windows/desktop/bb787911) usada por essa função especifica o intervalo de texto para formatar bem como o contexto \(DC\) de dispositivo para o dispositivo de destino.  
  
 Depois do texto formatado para um dispositivo de saída, você pode enviar as saídas no dispositivo usando a função de membro de [DisplayBand](../Topic/CRichEditCtrl::DisplayBand.md) .  Repetidamente usando `FormatRange` e `DisplayBand`, um aplicativo que imprime o conteúdo de um controle de edição avançado pode implementar a borda. \(A borda é divisão de saída em partes menores para fins de impressão.\)  
  
 Você pode usar a função de membro de [SetTargetDevice](../Topic/CRichEditCtrl::SetTargetDevice.md) para especificar o dispositivo de destino para o qual formatos de controle de edição avançada do texto.  Essa função é útil para formatação de WYSIWYG \(o que você vê é o que você obtém\), em que um aplicativo posiciona o texto usando a métrica da fonte de impressora padrão em vez da tela.  
  
## Consulte também  
 [Usando CRichEditCtrl](../mfc/using-cricheditctrl.md)   
 [Controles](../mfc/controls-mfc.md)