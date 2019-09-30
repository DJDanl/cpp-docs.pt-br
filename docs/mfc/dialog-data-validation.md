---
title: Validação dos dados da caixa de diálogo
ms.date: 11/04/2016
helpviewer_keywords:
- validating data [MFC], message boxes
- data validation [MFC], dialog boxes
- dialog boxes [MFC], validating data
- validating data [MFC], dialog box data entry
- DDV (dialog data validation) [MFC]
- data validation [MFC], message boxes
ms.assetid: f070c309-2044-4ff2-8c92-1ec1ea84af58
ms.openlocfilehash: c89ed82b148062ddb64fa85eaabda12f44e59895
ms.sourcegitcommit: 1e6386be9084f70def7b3b8b4bab319a117102b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/30/2019
ms.locfileid: "71685769"
---
# <a name="dialog-data-validation"></a>Validação dos dados da caixa de diálogo

Você pode especificar a validação, além da troca de dados chamando as funções DDV, conforme mostrado no exemplo na [caixa de diálogo troca de dados](../mfc/dialog-data-exchange.md). A chamada `DDV_MaxChars` no exemplo valida que a cadeia de caracteres inserida no controle da caixa de texto não tem mais de 20 caracteres. A função DDV normalmente alertará o usuário com uma caixa de mensagem se a validação falhar e colocar o foco no controle incorreto para que o usuário possa inserir novamente os dados. Uma função DDV para um determinado controle deve ser chamada imediatamente após a função campo DDX para o mesmo controle.

Você também pode definir suas próprias rotinas de campo DDX e DDV personalizadas. Para obter detalhes sobre esse e outros aspectos de campo DDX e DDV, consulte a [Observação técnica do MFC 26](../mfc/tn026-ddx-and-ddv-routines.md).

O [Assistente para Adicionar variável de membro](../ide/add-member-variable-wizard.md) gravará todas as chamadas campo DDX e DDV no mapa de dados para você.

## <a name="see-also"></a>Consulte também

[Troca e validação de dados da caixa de diálogo](../mfc/dialog-data-exchange-and-validation.md)<br/>
[Trabalhando com caixas de diálogo no MFC](../mfc/life-cycle-of-a-dialog-box.md)<br/>
[Troca de dados da caixa de diálogo](../mfc/dialog-data-exchange.md)
