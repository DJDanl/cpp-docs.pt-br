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
ms.openlocfilehash: 2283806d3fe7c4ff6bd3abc2ae6a86f5dd176d10
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50483337"
---
# <a name="dialog-data-validation"></a>Validação dos dados da caixa de diálogo

Você pode especificar a validação, além de troca de dados chamando funções DDV, conforme mostrado no exemplo na [troca de dados de caixa de diálogo](../mfc/dialog-data-exchange.md). O `DDV_MaxChars` chamada no exemplo valida que a cadeia de caracteres inserida no controle de caixa de texto não é mais de 20 caracteres. A função DDV normalmente alertará o usuário com uma caixa de mensagem se a validação falha e coloca o foco no controle incorreto para que o usuário pode inserir os dados novamente. Uma função de DDV para um determinado controle deve ser chamada imediatamente após a função DDX para o mesmo controle.

Você também pode definir suas próprias rotinas DDX e DDV personalizadas. Para obter detalhes sobre esse e outros aspectos do DDX e DDV, consulte [26 de observação técnica MFC](../mfc/tn026-ddx-and-ddv-routines.md).

O [Adicionar Assistente de variável de membro](../ide/add-member-variable-wizard.md) gravará todos o DDX e DDV chama no mapa de dados para você.

## <a name="see-also"></a>Consulte também

[Troca e validação de dados da caixa de diálogo](../mfc/dialog-data-exchange-and-validation.md)<br/>
[Ciclo de vida de uma caixa de diálogo](../mfc/life-cycle-of-a-dialog-box.md)<br/>
[Troca de dados da caixa de diálogo](../mfc/dialog-data-exchange.md)

