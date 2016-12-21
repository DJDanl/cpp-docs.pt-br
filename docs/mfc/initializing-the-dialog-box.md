---
title: "Inicializando a caixa de di&#225;logo | Microsoft Docs"
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
  - "inicializando caixas de diálogo"
  - "caixas de diálogo MFC, inicializando"
  - "caixas de diálogo modais, inicializando"
  - "caixas de diálogo sem modo, inicializando"
  - "Método OnInitDialog"
ms.assetid: 968142f5-19f9-4b34-a1d4-8e6412d4379b
caps.latest.revision: 9
caps.handback.revision: 5
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Inicializando a caixa de di&#225;logo
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Depois que a caixa de diálogo e todos os seus controles são criados mas antes que a caixa de diálogo \(de um ou outro tipo\) é exibido na tela, a função de membro de [OnInitDialog](../Topic/CDialog::OnInitDialog.md) do objeto da caixa de diálogo será chamada.  Para uma caixa de diálogo modal, isso ocorre durante a chamada de `DoModal` .  Para uma caixa de diálogo modeless, `OnInitDialog` é chamado quando **Criar** é chamado.  Você substitui `OnInitDialog` normalmente para inicializar os controles da caixa de diálogo, tais como definir o texto inicial de uma caixa de edição.  Você deve chamar a função de membro de `OnInitDialog` da classe base, `CDialog`, da substituição de `OnInitDialog` .  
  
 Se você quiser definir a cor do plano de fundo da caixa de diálogo \(e a de todas as caixas de diálogo restantes em seu aplicativo\), consulte [Definindo a cor do plano de fundo da caixa de diálogo](../mfc/setting-the-dialog-box’s-background-color.md).  
  
## Consulte também  
 [Ciclo de vida de uma caixa de diálogo](../mfc/life-cycle-of-a-dialog-box.md)