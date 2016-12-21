---
title: "Estilos de bot&#227;o Girar | Microsoft Docs"
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
  - "Classe CSpinButtonCtrl, estilos"
  - "controle de botão de rotação, estilos"
  - "estilos, CSpinButtonCtrl"
  - "estilos, controle de botão de rotação"
ms.assetid: fb4a7f6f-9182-47be-bccf-0728fdc5332f
caps.latest.revision: 10
caps.handback.revision: 6
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Estilos de bot&#227;o Girar
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Muitas das configurações de um botão de rotação[CSpinButtonCtrl](../mfc/reference/cspinbuttonctrl-class.md)\(\) são controladas por estilos.  Você pode definir os seguintes estilos usando a janela de **Propriedades** no publicador da caixa de diálogo.  
  
-   **Orientação** Vertical ou horizontal.  Controla a orientação dos botões de seta.  Associado ao estilo de `UDS_HORZ` .  
  
-   Um**Alinhamento** de livre, da esquerda, ou da direita.  Controla o local do botão de rotação.  Posição esquerda e direita o botão de rotação ao lado da janela de amigo.  A largura da janela de amigo é diminuída para acomodar o botão de rotação.  Associado aos estilos de `UDS_ALIGNLEFT` e de `UDS_ALIGNRIGHT` .  
  
-   **Buddy Automático** Seleciona automaticamente a janela anterior na ordem z como janela de amigo para o botão de rotação.  Em um modelo da caixa de diálogo, esse é o controle que precede o botão de rotação na ordem da guia.  Associado ao estilo de `UDS_AUTOBUDDY` .  
  
-   **Definir Inteiro Buddy** Faz com que o controle de rotação é incrementada e diminui a legenda da janela de amigo como a posição atual é alterado.  Associado ao estilo de `UDS_SETBUDDYINT` .  
  
-   **No Thousands** não insere o separador de milhar no valor na legenda da janela de amigo.  Associado ao estilo de `UDS_NOTHOUSANDS` .  
  
    > [!NOTE]
    >  Definir esse estilo se você desejar usar a caixa de diálogo de troca de dados \(DDX\) para obter o valor inteiro do controle de amigo.  `DDX_Text` não aceita milhar inseridos.  
  
-   **Wrap** causa a posição “envolver” como o valor é incrementado ou diminuído além do intervalo do controle.  Associado ao estilo de `UDS_WRAP` .  
  
-   **Arrow Keys** faz com que o botão de rotação incrementa ou diminui a posição quando as teclas de SETA PARA CIMA e PARA BAIXO são pressionadas.  Associado ao estilo de `UDS_ARROWKEYS` .  
  
## Consulte também  
 [Usando CSpinButtonCtrl](../mfc/using-cspinbuttonctrl.md)   
 [Controles](../mfc/controls-mfc.md)