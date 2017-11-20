---
title: "Validação de dados de caixa de diálogo | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
dev_langs: C++
helpviewer_keywords:
- validating data [MFC], message boxes
- data validation [MFC], dialog boxes
- dialog boxes [MFC], validating data
- validating data [MFC], dialog box data entry
- DDV (dialog data validation) [MFC]
- data validation [MFC], message boxes
ms.assetid: f070c309-2044-4ff2-8c92-1ec1ea84af58
caps.latest.revision: "9"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.openlocfilehash: 58fbff4a5192d15a60cf3340ce762574947fb249
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
---
# <a name="dialog-data-validation"></a>Validação dos dados da caixa de diálogo
Você pode especificar validação além de troca de dados chamando funções DDV, conforme mostrado no exemplo de [troca de dados de caixa de diálogo](../mfc/dialog-data-exchange.md). O `DDV_MaxChars` chamada no exemplo valida que a cadeia de caracteres inserida no controle de caixa de texto não é mais de 20 caracteres. A função DDV normalmente alerta o usuário com uma caixa de mensagem se a validação falha e coloca o foco no controle inválido para que o usuário pode inserir os dados novamente. Uma função DDV para um dado controle deve ser chamada imediatamente após a função DDX para o mesmo controle.  
  
 Você também pode definir suas próprias rotinas DDX e DDV personalizadas. Para obter detalhes sobre este e outros aspectos de DDX e DDV, consulte [26 de observação técnica MFC](../mfc/tn026-ddx-and-ddv-routines.md).  
  
 O [Adicionar Assistente de variável de membro](../ide/add-member-variable-wizard.md) gravará todos o DDX e DDV chama no mapa de dados para você.  
  
## <a name="see-also"></a>Consulte também  
 [Caixa de diálogo dados Exchange e validação](../mfc/dialog-data-exchange-and-validation.md)   
 [Ciclo de vida de uma caixa de diálogo](../mfc/life-cycle-of-a-dialog-box.md)   
 [Troca de dados da caixa de diálogo](../mfc/dialog-data-exchange.md)

