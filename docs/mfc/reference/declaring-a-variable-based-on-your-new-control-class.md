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
ms.openlocfilehash: 994f81524001a80d1cf0dd3783b9de742d61e84d
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81365838"
---
# <a name="declaring-a-variable-based-on-your-new-control-class"></a>Declarando uma variável com base na nova classe de controle

Depois de criar uma classe de controle MFC, você pode declarar uma variável com base nela. Para fornecer um contexto para a nova variável, você deve abrir o editor de diálogo e editar a caixa de diálogo na qual deseja usar seu controle reutilizável. Além disso, a caixa de diálogo já deve ter uma classe associada a ela. Para obter informações sobre o uso do editor de diálogo, consulte [Editor de diálogo](../../windows/dialog-editor.md).

### <a name="to-declare-a-variable-based-on-your-reusable-class"></a>Para declarar uma variável com base em sua classe reutilizável

1. Ao editar a caixa de diálogo, arraste um controle do mesmo tipo que a classe base do seu novo controle da barra de ferramentas Controles para a caixa de diálogo.

1. Coloque o ponteiro do mouse sobre o controle descartado.

1. Ao pressionar a tecla CTRL, clique duas vezes no controle.

   A caixa de diálogo [Adicionar variável de membro](../../ide/add-member-variable-wizard.md) é exibida.

1. Na caixa **Acesso,** selecione o acesso correto para o seu controle.

1. Clique na caixa de seleção **variável Controle.**

1. Na **caixa nome da variável,** digite um nome.

1. Em **Categoria,** clique em **Controlar**.

1. Na lista **de id de controle,** escolha o controle que você adicionou. A **lista de tipos variáveis** deve exibir o tipo de variável correto, e a caixa tipo **controle** deve exibir o tipo de controle correto.

1. Na caixa **Comentário,** adicione qualquer comentário que você deseja aparecer em seu código.

1. Clique em **OK**.

## <a name="see-also"></a>Confira também

[Mapeando mensagens para funções](../../mfc/reference/mapping-messages-to-functions.md)<br/>
[Adicionando funcionalidade com assistentes de código](../../ide/adding-functionality-with-code-wizards-cpp.md)<br/>
[Adicionando uma classe](../../ide/adding-a-class-visual-cpp.md)<br/>
[Adicionando uma função de membro](../../ide/adding-a-member-function-visual-cpp.md)<br/>
[Adicionando uma variável de membro](../../ide/adding-a-member-variable-visual-cpp.md)<br/>
[Substituindo uma função virtual](../../ide/overriding-a-virtual-function-visual-cpp.md)<br/>
[Manipulador de mensagens do MFC](../../mfc/reference/adding-an-mfc-message-handler.md)<br/>
[Navegando pela estrutura de classe](../../ide/navigate-code-cpp.md)
