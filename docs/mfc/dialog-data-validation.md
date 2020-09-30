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
ms.openlocfilehash: 9de2db002d7f06e797531c09af0a021c402eec7d
ms.sourcegitcommit: a1676bf6caae05ecd698f26ed80c08828722b237
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/29/2020
ms.locfileid: "91502276"
---
# <a name="dialog-data-validation"></a>Validação dos dados da caixa de diálogo

Você pode especificar a validação, além da troca de dados chamando as funções DDV, conforme mostrado no exemplo na [caixa de diálogo troca de dados](dialog-data-exchange.md). A `DDV_MaxChars` chamada no exemplo valida que a cadeia de caracteres inserida no controle da caixa de texto não tem mais de 20 caracteres. A função DDV normalmente alertará o usuário com uma caixa de mensagem se a validação falhar e colocar o foco no controle incorreto para que o usuário possa inserir novamente os dados. Uma função DDV para um determinado controle deve ser chamada imediatamente após a função campo DDX para o mesmo controle.

Você também pode definir suas próprias rotinas de campo DDX e DDV personalizadas. Para obter detalhes sobre esse e outros aspectos de campo DDX e DDV, consulte a [Observação técnica do MFC 26](tn026-ddx-and-ddv-routines.md).

O [Assistente para Adicionar variável de membro](../ide/adding-a-member-variable-visual-cpp.md#add-member-variable-wizard) gravará todas as chamadas campo DDX e DDV no mapa de dados para você.

## <a name="see-also"></a>Consulte também

[Troca de dados de caixa de diálogo e validação](dialog-data-exchange-and-validation.md)<br/>
[Trabalhar com caixas de diálogo no MFC](life-cycle-of-a-dialog-box.md)<br/>
[Troca de dados da caixa de diálogo](dialog-data-exchange.md)
