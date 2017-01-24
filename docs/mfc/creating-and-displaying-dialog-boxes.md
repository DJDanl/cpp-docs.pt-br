---
title: "Criando e exibindo caixas de di&#225;logo | Microsoft Docs"
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
  - "caixas de diálogo MFC, criando"
  - "caixas de diálogo MFC, exibindo"
  - "caixas de diálogo modais, criando"
  - "caixas de diálogo sem modo, criando"
  - "abrindo caixas de diálogo"
ms.assetid: 1c5219ee-8b46-44bc-9708-83705d4f248b
caps.latest.revision: 9
caps.handback.revision: 5
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Criando e exibindo caixas de di&#225;logo
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Criar um objeto da caixa de diálogo é uma operação são totalmente concluídas.  Primeiro, crie o objeto da caixa de diálogo, então crie a janela caixa de diálogo.  As caixas de diálogo modais e modeless diferem ligeiramente no processo usado para criá\-los e exibir.  A tabela a seguir lista como as caixas de diálogo modais e modeless normalmente são criadas e exibidas.  
  
### Criação da caixa de diálogo  
  
|Tipo de caixa de diálogo|Como o criar|  
|------------------------------|------------------|  
|[Não modal](../mfc/creating-modeless-dialog-boxes.md)|Construir `CDialog`, chame a função de membro de **Criar** .|  
|[Modal](../mfc/creating-modal-dialog-boxes.md)|A construção `CDialog`, chame a função de membro de `DoModal` .|  
  
 Você pode, se desejar, cria a caixa de diálogo de [modelo de memória da caixa de diálogo](../mfc/using-a-dialog-template-in-memory.md) que você construiu em vez de um recurso do modelo da caixa de diálogo.  Este é um tópico avançado, porém.  
  
## Consulte também  
 [Ciclo de vida de uma caixa de diálogo](../mfc/life-cycle-of-a-dialog-box.md)