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
ms.openlocfilehash: 400107a7b61ae28ca1d3ec69ee3217d58f55d9e2
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50665069"
---
# <a name="dialog-boxes"></a>Caixas de diálogo

Aplicativos para Windows com frequência se comunicar com o usuário por meio de caixas de diálogo. Classe [CDialog](../mfc/reference/cdialog-class.md) fornece uma interface para gerenciar caixas de diálogo, o editor de caixa de diálogo do Visual C++ torna fácil a criação de caixas de diálogo e criar seus recursos de modelo de caixa de diálogo e assistentes de código simplificam o processo de inicialização e Validando os controles em uma caixa de diálogo e de coletar os valores inseridos pelo usuário.

Caixas de diálogo contém controles, incluindo:

- Controles comuns do Windows, como editar caixas, comportarem, caixas de listagem, caixas de combinação, controles de árvore, controles de lista e indicadores de progresso.

- Controles ActiveX.

- Controles desenhados pelo proprietário: controles que você é responsável por desenhar na caixa de diálogo.

A maioria das caixas de diálogo são modais, que exigem que o usuário fechar a caixa de diálogo antes de usar qualquer outra parte do programa. Mas é possível criar caixas de diálogo sem janela restrita, que permitem que os usuários a trabalhar com outras janelas enquanto a caixa de diálogo está aberta. MFC é compatível com os dois tipos de caixa de diálogo com a classe `CDialog`. Os controles são organizados e gerenciados usando um recurso de modelo de caixa de diálogo, criado com o [editor de caixa de diálogo](../windows/dialog-editor.md).

[Folhas de propriedade](../mfc/property-sheets-mfc.md), também conhecido como caixas de diálogo de guia, caixas de diálogo que contêm "páginas" de controles de caixa de diálogo distintos. Cada página tem uma pasta de arquivos "guia" na parte superior. Clicar em uma guia traz essa página para a frente da caixa de diálogo.

## <a name="what-do-you-want-to-know-more-about"></a>O que você deseja saber mais sobre

- [Exemplo: exibindo uma caixa de diálogo por meio de um comando de menu](../mfc/example-displaying-a-dialog-box-via-a-menu-command.md)

- [Componentes da caixa de diálogo no framework](../mfc/dialog-box-components-in-the-framework.md)

- [Caixas de diálogo modais e sem janela restrita](../mfc/modal-and-modeless-dialog-boxes.md)

- [Folhas de propriedades e páginas de propriedade](../mfc/property-sheets-and-property-pages-mfc.md) em uma caixa de diálogo

- [Criando o recurso da caixa de diálogo](../mfc/creating-the-dialog-resource.md)

- [Criando uma classe de caixa de diálogo com assistentes de código](../mfc/creating-a-dialog-class-with-code-wizards.md)

- [Ciclo de vida de uma caixa de diálogo](../mfc/life-cycle-of-a-dialog-box.md)

- [Troca de dados de caixa de diálogo (DDX) e a validação (DDV)](../mfc/dialog-data-exchange-and-validation.md)

- [Acesso fortemente tipado a controles em uma caixa de diálogo](../mfc/type-safe-access-to-controls-in-a-dialog-box.md)

- [Mapeando mensagens do Windows para a classe](../mfc/mapping-windows-messages-to-your-class.md)

- [Funções de membro normalmente substituídas](../mfc/commonly-overridden-member-functions.md)

- [Funções de membro normalmente adicionadas](../mfc/commonly-added-member-functions.md)

- [Classes de caixa de diálogo comuns](../mfc/common-dialog-classes.md)

- [Caixas de diálogo em OLE](../mfc/dialog-boxes-in-ole.md)

- Criar um aplicativo cuja interface do usuário é uma caixa de diálogo: consulte a [CMNCTRL1](../visual-cpp-samples.md) ou [CMNCTRL2](../visual-cpp-samples.md) programas de exemplo. O Assistente de aplicativo fornece essa opção também.

- [Amostras](../mfc/dialog-sample-list.md)

## <a name="see-also"></a>Consulte também

[Elementos da Interface do usuário](../mfc/user-interface-elements-mfc.md)
