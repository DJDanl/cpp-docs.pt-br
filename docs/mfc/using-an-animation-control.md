---
title: "Usando um controle de anima&#231;&#227;o | Microsoft Docs"
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
  - "controles de animação [C++]"
  - "Classe CAnimateCtrl, controles de animação"
  - "controles [MFC], animação"
ms.assetid: a009a464-e12d-4112-bf52-04a09b28dd88
caps.latest.revision: 10
caps.handback.revision: 6
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Usando um controle de anima&#231;&#227;o
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

O uso típico de um controle de animação segue o padrão abaixo:  
  
-   O controle é criado.  Se o controle for especificado em um modelo da caixa de diálogo, a criação for automático quando a caixa de diálogo é criada. \(Você deve ter um membro de [CAnimateCtrl](../mfc/reference/canimatectrl-class.md) em sua classe da caixa de diálogo que corresponde ao controle de animação.\) Como alternativa, você pode usar a função de membro de [Crie](../Topic/CAnimateCtrl::Create.md) para criar o controle como uma janela filho de qualquer janela.  
  
-   Carregar um recortar de AVI no controle de animação chamando a função de membro de [Abrir](../Topic/CAnimateCtrl::Open.md) .  Se o controle de animação está em uma caixa de diálogo, um bom local para fazer isso está na função de [OnInitDialog](../Topic/CDialog::OnInitDialog.md) da classe da caixa de diálogo.  
  
-   Execute o recortar chamando a função de membro de [Kit](../Topic/CAnimateCtrl::Play.md) .  Se o controle de animação está em uma caixa de diálogo, um bom local para fazer isso está na função de **OnInitDialog** da classe da caixa de diálogo.  A chamada **Executar** não será necessária se o controle de animação tem o estilo de `ACS_AUTOPLAY` definido.  
  
-   Se você quiser visualizar partes de recortar ou para executar as peças pelo quadro, use a função de membro de `Seek` .  Para interromper um recortar que está sendo executado, use a função de membro de `Stop` .  
  
-   Se você não tiver que ser destruído imediatamente o controle, remova o recortar da memória chamando a função de membro de **Fechar** .  
  
-   Se o controle de animação está em uma caixa de diálogo, e o objeto de `CAnimateCtrl` serão destruídos automaticamente.  Caso contrário, você precisa assegurar que a validação e o objeto de `CAnimateCtrl` serem destruídos corretamente.  Destruir o controle fecha automaticamente o recortar de AVI.  
  
## Consulte também  
 [Usando CAnimateCtrl](../Topic/Using%20CAnimateCtrl.md)   
 [Controles](../mfc/controls-mfc.md)