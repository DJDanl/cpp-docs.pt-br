---
title: "Definindo o modo de um objeto CStatusBarCtrl | Microsoft Docs"
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
  - "CStatusBarCtrl"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe CStatusBarCtrl, modos simples e não simples"
  - "Método IsSimple, usando"
  - "modo não simples e controles de barra de status"
  - "Método SetSimple"
  - "modo simples e controles de barra de status"
  - "controles da barra de status, modos simples e não simples"
ms.assetid: ca6076e5-1501-4e33-8d35-9308941e46c0
caps.latest.revision: 10
caps.handback.revision: 6
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Definindo o modo de um objeto CStatusBarCtrl
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Há dois modos para um objeto de `CStatusBarCtrl` : simples e simples.  Na maioria dos casos, o controle da barra de status terá uma ou várias partes, junto com o texto e talvez um ícone ou ícones.  Isso é chamado do modo de não.  Para obter mais informações sobre esse modo, consulte [Inicializando as partes de um objeto de CStatusBarCtrl](../mfc/initializing-the-parts-of-a-cstatusbarctrl-object.md).  
  
 Entretanto, há casos em que você só precisa exibir uma única linha de texto.  Nesse caso, o modo simples é suficiente para suas necessidades.  Para alterar o modo do objeto da `CStatusBarCtrl` simples, faça uma chamada à função de membro de [SetSimple](../Topic/CStatusBarCtrl::SetSimple.md) .  Uma vez que o controle da barra de status está no modo simples, definir o texto chamando a função de membro de **SetText** , passando 255 como o valor para o parâmetro de **nPane** .  
  
 Você pode usar a função de [IsSimple](../Topic/CStatusBarCtrl::IsSimple.md) para determinar qual modo o objeto de `CStatusBarCtrl` estiver em.  
  
> [!NOTE]
>  Se o objeto da barra de status está sendo alterado do não como simples, ou vice\-versa, a janela é redesenhada imediatamente e, se aplicável, todas as partes são definidas automaticamente restauradas.  
  
## Consulte também  
 [Usando CStatusBarCtrl](../mfc/using-cstatusbarctrl.md)   
 [Controles](../mfc/controls-mfc.md)