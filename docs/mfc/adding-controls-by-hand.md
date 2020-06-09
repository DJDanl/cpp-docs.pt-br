---
title: Adicionando controles manualmente
ms.date: 11/04/2016
helpviewer_keywords:
- Windows common controls [MFC], adding
- dialog box controls [MFC], adding to dialog boxes
- controlling input focus
- input focus control
- focus, controlling input [MFC]
- controls [MFC], adding to dialog boxes
- common controls [MFC], adding
ms.assetid: bc843e59-0c51-4b5b-8bf2-343f716469d2
ms.openlocfilehash: 4efd1c23c7e4d6f7d8e6fa9fe046f8de11c825a6
ms.sourcegitcommit: c21b05042debc97d14875e019ee9d698691ffc0b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 06/09/2020
ms.locfileid: "84626532"
---
# <a name="adding-controls-by-hand"></a>Adicionando controles manualmente

Você pode [Adicionar controles a uma caixa de diálogo com o editor de caixas de diálogo](using-the-dialog-editor-to-add-controls.md) ou adicioná-los por conta própria, com o código.

Para criar um objeto de controle por conta própria, normalmente você incorporará o objeto de controle C++ em um objeto de caixa de diálogo C++ ou janela de quadro. Como muitos outros objetos na estrutura, os controles exigem a construção de dois estágios. Você deve chamar a função de membro **Create** do controle como parte da criação da caixa de diálogo pai ou janela do quadro. Para caixas de diálogo, isso geralmente é feito em [OnInitDialog](reference/cdialog-class.md#oninitdialog)e para janelas de quadros, em [OnCreate](reference/cwnd-class.md#oncreate).

O exemplo a seguir mostra como você pode declarar um `CEdit` objeto na declaração de classe de uma classe de caixa de diálogo derivada e, em seguida, chamar a `Create` função de membro no `OnInitDialog` . Como o `CEdit` objeto é declarado como um objeto incorporado, ele é construído automaticamente quando o objeto da caixa de diálogo é construído, mas ele ainda deve ser inicializado com sua própria `Create` função de membro.

[!code-cpp[NVC_MFCControlLadenDialog#1](codesnippet/cpp/adding-controls-by-hand_1.h)]

A função a seguir `OnInitDialog` configura um retângulo e, em seguida, chama `Create` para criar o controle de edição do Windows e anexá-lo ao objeto não inicializado `CEdit` .

[!code-cpp[NVC_MFCControlLadenDialog#2](codesnippet/cpp/adding-controls-by-hand_2.cpp)]

Depois de criar o objeto de edição, você também pode definir o foco de entrada para o controle chamando a `SetFocus` função de membro. Por fim, você retorna 0 de `OnInitDialog` para mostrar que você definiu o foco. Se você retornar um valor diferente de zero, o Gerenciador de caixas de diálogo definirá o foco para o primeiro item de controle na lista de itens de caixa de diálogo. Na maioria dos casos, você desejará adicionar controles às suas caixas de diálogo com o editor de caixa de diálogo.

## <a name="see-also"></a>Consulte também

[Criando e usando controles](making-and-using-controls.md)<br/>
[Controles](controls-mfc.md)<br/>
[CDialog:: OnInitDialog](reference/cdialog-class.md#oninitdialog)
