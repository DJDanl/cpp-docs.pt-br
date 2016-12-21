---
title: "Valida&#231;&#227;o dos dados da caixa de di&#225;logo | Microsoft Docs"
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
  - "validação de dados [C++], caixas de diálogo"
  - "validação de dados [C++], caixas de mensagem"
  - "DDV (validação dos dados da caixa de diálogo) [C++]"
  - "caixas de diálogo [C++], validando dados"
  - "validando dados [C++], entrada de dados de caixa de diálogo"
  - "validando dados [C++], caixas de mensagem"
ms.assetid: f070c309-2044-4ff2-8c92-1ec1ea84af58
caps.latest.revision: 9
caps.handback.revision: 5
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Valida&#231;&#227;o dos dados da caixa de di&#225;logo
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Você pode especificar a validação além de troca de dados chamando funções de DDV, conforme mostrado no exemplo em [Caixa de diálogo de troca de dados](../mfc/dialog-data-exchange.md).  A chamada de `DDV_MaxChars` no exemplo verifica se a cadeia de caracteres inserida ao controle da caixa de texto não tem mais de 20 caracteres.  A função de DDV alerta normalmente o usuário com uma caixa de mensagem se a validação falhar e coloca o foco no controle de incorretos para que o usuário pode inserir novamente os dados.  Uma função de DDV para um determinado controle deve ser chamado imediatamente depois que a função de DDX para o mesmo controla.  
  
 Você também pode definir seu próprio personalizadas DDX e rotinas de DDV.  Para obter detalhes em ou e em outros aspectos de DDX e de DDV, consulte [Observação 26 técnica MFC](../mfc/tn026-ddx-and-ddv-routines.md).  
  
 [Adicionar o assistente da variável de membro](../ide/add-member-variable-wizard.md) gravará todos as chamadas de DDX e de DDV no mapa de dados.  
  
## Consulte também  
 [Troca de dados da caixa de diálogo e validação](../mfc/dialog-data-exchange-and-validation.md)   
 [Ciclo de vida de uma caixa de diálogo](../mfc/life-cycle-of-a-dialog-box.md)   
 [Troca de dados da caixa de diálogo](../mfc/dialog-data-exchange.md)