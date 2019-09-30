---
title: Caixas de diálogo
ms.date: 11/04/2016
helpviewer_keywords:
- modeless dialog boxes [MFC], MFC dialog boxes
- MFC, dialog boxes
- modal dialog boxes [MFC], MFC dialog boxes
- CDialog class [MFC], MFC dialog boxes
- MFC dialog boxes
ms.assetid: e4feea1a-8360-4ccb-9b84-507f1ccd9ef3
ms.openlocfilehash: 18b4c4d1386716a0a3282b88d6fdf5a701abce08
ms.sourcegitcommit: 1e6386be9084f70def7b3b8b4bab319a117102b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/30/2019
ms.locfileid: "71685791"
---
# <a name="dialog-boxes"></a>Caixas de diálogo

Os aplicativos para Windows se comunicam com frequência com o usuário por meio de caixas de diálogo. A classe [CDialog](../mfc/reference/cdialog-class.md) fornece uma interface para gerenciar caixas de diálogo, C++ o editor de caixa de diálogo Visual facilita o design de caixas de diálogo e a criação de seus recursos de modelo de caixa de diálogo, e os assistentes de código simplificam o processo de inicialização e validação do controles em uma caixa de diálogo e de reunir os valores inseridos pelo usuário.

As caixas de diálogo contêm controles, incluindo:

- Controles comuns do Windows, como caixas de edição, supressãos, caixas de listagem, caixas de combinação, controles de árvore, controles de lista e indicadores de progresso.

- Controles ActiveX.

- Controles desenhados pelo proprietário: controles que você é responsável por desenhar na caixa de diálogo.

A maioria das caixas de diálogo são modais, o que exige que o usuário feche a caixa de diálogo antes de usar qualquer outra parte do programa. Mas é possível criar caixas de diálogo sem janela restrita, que permitem que os usuários trabalhem com outras janelas enquanto a caixa de diálogo está aberta. O MFC dá suporte a ambos os tipos de caixa de diálogo com a classe `CDialog`. Os controles são organizados e gerenciados usando um recurso de modelo de caixa de diálogo, criado com o [Editor de caixa de diálogo](../windows/dialog-editor.md).

[Folhas de propriedades](../mfc/property-sheets-mfc.md), também conhecidas como caixas de diálogo de guia, são caixas de diálogo que contêm "páginas" de controles de caixa de diálogo distintos. Cada página tem uma pasta de arquivos "Tab" na parte superior. Clicar em uma guia leva essa página para a frente da caixa de diálogo.

## <a name="what-do-you-want-to-know-more-about"></a>Do que você deseja saber mais sobre

- [Exemplo: exibir uma caixa de diálogo por meio de um comando Menu](../mfc/example-displaying-a-dialog-box-via-a-menu-command.md)

- [Componentes da caixa de diálogo na estrutura](../mfc/dialog-box-components-in-the-framework.md)

- [Caixas de diálogo modais e sem janela restrita](../mfc/modal-and-modeless-dialog-boxes.md)

- [Folhas de propriedades e páginas de propriedades](../mfc/property-sheets-and-property-pages-mfc.md) em uma caixa de diálogo

- [Criando o recurso de caixa de diálogo](../mfc/creating-the-dialog-resource.md)

- [Criando uma classe Dialog com assistentes de código](../mfc/creating-a-dialog-class-with-code-wizards.md)

- [Trabalhando com caixas de diálogo no MFC](../mfc/life-cycle-of-a-dialog-box.md)

- [Troca de dados de caixa de diálogo (campo DDX) e validação (DDV)](../mfc/dialog-data-exchange-and-validation.md)

- [Acesso de tipo seguro a controles em uma caixa de diálogo](../mfc/type-safe-access-to-controls-in-a-dialog-box.md)

- [Mapeando mensagens do Windows para sua classe](../mfc/mapping-windows-messages-to-your-class.md)

- [Funções de membro normalmente substituídas](../mfc/commonly-overridden-member-functions.md)

- [Funções de membro normalmente adicionadas](../mfc/commonly-added-member-functions.md)

- [Classes de diálogo comuns](../mfc/common-dialog-classes.md)

- [Caixas de diálogo no OLE](../mfc/dialog-boxes-in-ole.md)

- Crie um aplicativo cuja interface do usuário seja uma caixa de diálogo: consulte os programas de exemplo [CMNCTRL1](../overview/visual-cpp-samples.md) ou [CMNCTRL2](../overview/visual-cpp-samples.md) . O assistente de aplicativo também fornece essa opção.

- [Amostras](../mfc/dialog-sample-list.md)

## <a name="see-also"></a>Consulte também

[Elementos da interface do usuário](../mfc/user-interface-elements-mfc.md)
