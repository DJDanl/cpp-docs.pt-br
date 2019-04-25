---
title: Declarando uma variável com base na nova classe de controle
ms.date: 11/04/2016
f1_keywords:
- vc.codewiz.classes.control.variable
helpviewer_keywords:
- variables [MFC], control classes
- control classes [MFC], variables
- classes [MFC], declaring variables based on
ms.assetid: 5722dc38-c0eb-40bd-93da-67a808140d03
ms.openlocfilehash: b3b1a168619c1c111db3e71e1a9562d441cc710d
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62323002"
---
# <a name="declaring-a-variable-based-on-your-new-control-class"></a>Declarando uma variável com base na nova classe de controle

Depois de criar uma classe de controle do MFC, você pode declarar uma variável com base nele. Para fornecer um contexto para a nova variável, você deve abrir o editor de caixa de diálogo e edite a caixa de diálogo na qual você deseja usar o controle reutilizável. Além disso, a caixa de diálogo já deve ter uma classe associada a ele. Para obter informações sobre como usar o editor de caixa de diálogo, consulte [Editor de caixa de diálogo](../../windows/dialog-editor.md).

### <a name="to-declare-a-variable-based-on-your-reusable-class"></a>Para declarar uma variável com base em sua classe reutilizável

1. Ao editar a caixa de diálogo, arraste um controle do mesmo tipo como a classe base do seu novo controle na barra de ferramentas de controles para a caixa de diálogo.

1. Coloque o ponteiro do mouse sobre o controle removido.

1. Enquanto pressiona a tecla CTRL, clique duas vezes no controle.

   O [Adicionar variável de membro](../../ide/add-member-variable-wizard.md) caixa de diálogo é exibida.

1. No **acesso** , marque o acesso correto para o seu controle.

1. Clique o **variável de controle** caixa de seleção.

1. No **nome da variável** , digite um nome.

1. Sob **categoria**, clique em **controle**.

1. No **ID do controle** lista, selecione o controle que você adicionou. O **tipo de variável** lista deve exibir o tipo correto de variável e o **tipo de controle** caixa deve exibir o tipo de controle correto.

9. No **comentário** caixa, adicione qualquer comentário que você deseja que apareça em seu código.

10. Clique em **OK**.

## <a name="see-also"></a>Consulte também

[Mapeando mensagens para funções](../../mfc/reference/mapping-messages-to-functions.md)<br/>
[Adicionando funcionalidade com assistentes de código](../../ide/adding-functionality-with-code-wizards-cpp.md)<br/>
[Adicionando uma classe](../../ide/adding-a-class-visual-cpp.md)<br/>
[Adicionando uma função de membro](../../ide/adding-a-member-function-visual-cpp.md)<br/>
[Adicionando uma variável de membro](../../ide/adding-a-member-variable-visual-cpp.md)<br/>
[Substituindo uma função virtual](../../ide/overriding-a-virtual-function-visual-cpp.md)<br/>
[Manipulador de mensagens do MFC](../../mfc/reference/adding-an-mfc-message-handler.md)<br/>
[Navegando pela estrutura de classe](../../ide/navigating-the-class-structure-visual-cpp.md)
