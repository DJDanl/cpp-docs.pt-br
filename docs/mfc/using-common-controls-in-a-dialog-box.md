---
title: Usando controles comuns em uma caixa de diálogo
ms.date: 11/04/2016
helpviewer_keywords:
- common controls [MFC], in dialog boxes
- dialog box controls [MFC], common controls
- Windows common controls [MFC], in dialog boxes
ms.assetid: 17713caf-09f8-484a-bf54-5f48bf09cce9
ms.openlocfilehash: 1a3dcb7151952b52affcfeb838ced15f0d116fce
ms.sourcegitcommit: a1676bf6caae05ecd698f26ed80c08828722b237
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/29/2020
ms.locfileid: "91500350"
---
# <a name="using-common-controls-in-a-dialog-box"></a>Usando controles comuns em uma caixa de diálogo

Os controles comuns do Windows podem ser usados em [caixas de diálogo](../mfc/dialog-boxes.md), exibições de formulário, exibições de registro e qualquer outra janela com base em um modelo de caixa de diálogo. O procedimento a seguir, com pequenas alterações, também funcionará para formulários.

## <a name="procedures"></a>Procedimentos

#### <a name="to-use-a-common-control-in-a-dialog-box"></a>Para usar um controle comum em uma caixa de diálogo

1. Coloque o controle no modelo de caixa de diálogo [usando o editor de caixa de diálogo](../mfc/using-the-dialog-editor-to-add-controls.md).

1. Adicione à classe da caixa de diálogo uma variável de membro que representa o controle. Na caixa de diálogo **Adicionar variável de membro** , verifique a **variável de controle** e verifique se o **controle** está selecionado para a **categoria**.

1. Se esse controle comum estiver fornecendo entrada para o programa, declare variáveis de membro adicionais na classe Dialog para lidar com esses valores de entrada.

    > [!NOTE]
    >  Você pode adicionar essas variáveis de membro usando o menu de contexto no Modo de Exibição de Classe (consulte [adicionando uma variável de membro](../ide/adding-a-member-variable-visual-cpp.md)).

1. Em [OnInitDialog](../mfc/reference/cdialog-class.md#oninitdialog) para sua classe de caixa de diálogo, defina as condições iniciais para o controle comum. Usando a variável de membro criada na etapa anterior, use as funções de membro para definir o valor inicial e outras configurações. Consulte as seguintes descrições dos controles para obter detalhes sobre as configurações.

   Você também pode usar a [troca de dados de caixa de diálogo](../mfc/dialog-data-exchange-and-validation.md) (campo DDX) para inicializar controles em uma caixa de diálogo.

1. Em manipuladores para controles na caixa de diálogo, use a variável de membro para manipular o controle. Consulte as descrições a seguir dos controles para obter detalhes sobre os métodos.

    > [!NOTE]
    >  A variável de membro existirá somente contanto que a própria caixa de diálogo exista. Você não poderá consultar o controle em busca de valores de entrada depois que a caixa de diálogo tiver sido fechada. Para trabalhar com valores de entrada de um controle comum, substitua `OnOK` em sua classe de caixa de diálogo. Em sua substituição, consulte o controle para obter os valores de entrada e armazene esses valores em variáveis de membro da classe DIALOG.

    > [!NOTE]
    >  Você também pode usar a troca de dados de caixa de diálogo para definir ou recuperar valores dos controles em uma caixa de diálogo.

## <a name="remarks"></a>Comentários

A adição de alguns controles comuns a uma caixa de diálogo fará com que a caixa de diálogo não funcione mais. Consulte [Adicionar controles a uma caixa de diálogo faz com que a caixa de diálogo não funcione mais](../windows/adding-editing-or-deleting-controls.md) para obter mais informações sobre como lidar com essa situação.

## <a name="what-do-you-want-to-do"></a>O que você deseja fazer

- [Adicionar controles a uma caixa de diálogo manualmente, em vez de ao editor da caixa de diálogo](../mfc/adding-controls-by-hand.md)

- [Derive meu controle de um dos controles comuns do Windows padrão](../mfc/deriving-controls-from-a-standard-control.md)

- [Usar um controle comum como uma janela filho](../mfc/using-a-common-control-as-a-child-window.md)

- [Receber mensagens de notificação de um controle](../mfc/receiving-notification-from-common-controls.md)

- [Usar troca de dados de caixa de diálogo (campo DDX)](../mfc/dialog-data-exchange-and-validation.md)

## <a name="see-also"></a>Consulte também

[Criando e usando controles](../mfc/making-and-using-controls.md)<br/>
[Controles](../mfc/controls-mfc.md)
