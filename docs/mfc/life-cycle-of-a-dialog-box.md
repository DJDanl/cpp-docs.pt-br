---
title: "Ciclo de vida de uma caixa de di&#225;logo | Microsoft Docs"
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
  - "caixas de diálogo, ciclo de vida"
  - "ciclo de vida de caixas de diálogo"
  - "caixas de diálogo MFC, ciclo de vida"
  - "caixas de diálogo modais, ciclo de vida"
  - "caixas de diálogo sem modo, ciclo de vida"
ms.assetid: e16fd78e-238d-4f31-8c9d-8564f3953bd9
caps.latest.revision: 9
caps.handback.revision: 5
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Ciclo de vida de uma caixa de di&#225;logo
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Durante o ciclo de vida de uma caixa de diálogo, o usuário invoca a caixa de diálogo, normalmente dentro de um manipulador de comando que cria e inicializa o objeto da caixa de diálogo, o usuário interage com a caixa de diálogo e, na caixa de diálogo é fechada.  
  
 Para caixas de diálogo modal, o manipulador coleta todos os dados que o usuário inscrito uma vez que a caixa de diálogo fechar.  Desde que o objeto da caixa de diálogo existe depois que a janela da caixa de diálogo se foi desligado, você pode simplesmente usar as variáveis de membro da classe da caixa de diálogo para extrair os dados.  
  
 Para caixas de diálogo modeless, muitas vezes você pode extrair dados do objeto da caixa de diálogo quando a caixa de diálogo ainda está visível.  Em algum ponto, o objeto da caixa de diálogo é destruído; quando isso acontecer depende de seu código.  
  
## Que você deseja saber mais?  
  
-   [Criando e exibindo caixas de diálogo](../mfc/creating-and-displaying-dialog-boxes.md)  
  
-   [Criando caixas de diálogo modais](../mfc/creating-modal-dialog-boxes.md)  
  
-   [Criando caixas de diálogo modeless](../mfc/creating-modeless-dialog-boxes.md)  
  
-   [Usando um modelo da caixa de diálogo na memória](../mfc/using-a-dialog-template-in-memory.md)  
  
-   [Definindo a cor do plano de fundo da caixa de diálogo](../mfc/setting-the-dialog-box’s-background-color.md)  
  
-   [Inicializando a caixa de diálogo](../mfc/initializing-the-dialog-box.md)  
  
-   [Manipulação de mensagens do windows na caixa de diálogo](../mfc/handling-windows-messages-in-your-dialog-box.md)  
  
-   [Recuperando dados do objeto da caixa de diálogo](../Topic/Retrieving%20Data%20from%20the%20Dialog%20Object.md)  
  
-   [Fechando a caixa de diálogo](../mfc/closing-the-dialog-box.md)  
  
-   [Destruindo a caixa de diálogo](../Topic/Destroying%20the%20Dialog%20Box.md)  
  
-   [Caixa de diálogo de troca de dados \(DDX\) e validação \(DDV\)](../mfc/dialog-data-exchange-and-validation.md)  
  
-   [Caixas de diálogo de folha de propriedade](../mfc/property-sheets-and-property-pages-mfc.md)  
  
## Consulte também  
 [Caixas de diálogo](../mfc/dialog-boxes.md)