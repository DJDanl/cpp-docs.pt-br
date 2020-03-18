---
title: Classes de caixa de diálogo comuns OLE
ms.date: 11/04/2016
helpviewer_keywords:
- ActiveX classes [MFC]
- dialog classes [MFC], OLE
- OLE common dialog classes [MFC]
- common dialog classes [MFC]
ms.assetid: 706526ae-f94f-4909-a0f8-6b5fe954fd97
ms.openlocfilehash: b44a7b203c17f09f872cfedbb05798affb57f0f9
ms.sourcegitcommit: 63784729604aaf526de21f6c6b62813882af930a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/17/2020
ms.locfileid: "79447665"
---
# <a name="ole-common-dialog-classes"></a>Classes de caixa de diálogo comuns OLE

Essas classes manipulam tarefas OLE comuns implementando várias caixas de diálogo padrão do OLE. Eles também fornecem uma interface de usuário consistente para a funcionalidade OLE.

[COleDialog](../mfc/reference/coledialog-class.md)<br/>
Usado pela estrutura para conter implementações comuns para todas as caixas de diálogo OLE. Todas as classes da caixa de diálogo na categoria user-interface são derivadas dessa classe base. `COleDialog` não pode ser usado diretamente.

[COleInsertDialog](../mfc/reference/coleinsertdialog-class.md)<br/>
Exibe a caixa de diálogo Inserir objeto, a interface do usuário padrão para inserir novos itens vinculados OLE ou incorporados.

[COlePasteSpecialDialog](../mfc/reference/colepastespecialdialog-class.md)<br/>
Exibe a caixa de diálogo colar especial, a interface do usuário padrão para implementar o comando Editar Colar especial.

[COleLinksDialog](../mfc/reference/colelinksdialog-class.md)<br/>
Exibe a caixa de diálogo Editar links, a interface do usuário padrão para modificar informações sobre itens vinculados.

[COleChangeIconDialog](../mfc/reference/colechangeicondialog-class.md)<br/>
Exibe a caixa de diálogo Alterar ícone, a interface do usuário padrão para alterar o ícone associado a um item OLE inserido ou vinculado.

[COleConvertDialog](../mfc/reference/coleconvertdialog-class.md)<br/>
Exibe a caixa de diálogo Converter, a interface do usuário padrão para converter itens OLE de um tipo para outro.

[COlePropertiesDialog](../mfc/reference/colepropertiesdialog-class.md)<br/>
Encapsula a caixa de diálogo Propriedades OLE comuns do Windows. As caixas de diálogo Propriedades OLE comuns fornecem uma maneira fácil de exibir e modificar as propriedades de um item de documento OLE de maneira consistente com os padrões do Windows.

[COleUpdateDialog](../mfc/reference/coleupdatedialog-class.md)<br/>
Exibe a caixa de diálogo atualizar, a interface do usuário padrão para atualizar todos os links em um documento. A caixa de diálogo contém um indicador de progresso para indicar como fechar o procedimento de atualização para conclusão.

[COleChangeSourceDialog](../mfc/reference/colechangesourcedialog-class.md)<br/>
Exibe a caixa de diálogo Alterar origem, a interface do usuário padrão para alterar o destino ou a origem de um link.

[COleBusyDialog](../mfc/reference/colebusydialog-class.md)<br/>
Exibe as caixas de diálogo servidor ocupado e servidor não respondendo, a interface do usuário padrão para manipular chamadas para aplicativos ocupados. Geralmente exibido automaticamente pela implementação de `COleMessageFilter`.

## <a name="see-also"></a>Consulte também

[Visão geral da classe](../mfc/class-library-overview.md)
