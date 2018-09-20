---
title: Adicionando controles manualmente | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- Windows common controls [MFC], adding
- dialog box controls [MFC], adding to dialog boxes
- controlling input focus
- input focus control
- focus, controlling input [MFC]
- controls [MFC], adding to dialog boxes
- common controls [MFC], adding
ms.assetid: bc843e59-0c51-4b5b-8bf2-343f716469d2
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 72170e3e21f5ca895b95da0d5905a2167375f721
ms.sourcegitcommit: 799f9b976623a375203ad8b2ad5147bd6a2212f0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/19/2018
ms.locfileid: "46434538"
---
# <a name="adding-controls-by-hand"></a>Adicionando controles manualmente

Você pode [adicionar controles a uma caixa de diálogo com o editor de caixa de diálogo](../mfc/using-the-dialog-editor-to-add-controls.md) ou adicioná-los por conta própria, com o código.

Para criar um objeto de controle, você geralmente será inserir o objeto de controle do C++ em uma caixa de diálogo de C++ ou o objeto de janela do quadro. Como muitos outros objetos na estrutura, controles exigem a construção de dois estágios. Você deve chamar o controle **criar** função de membro como parte da criação da caixa de diálogo caixa ou o quadro de janela pai. Para caixas de diálogo, geralmente isso é feito no [OnInitDialog](../mfc/reference/cdialog-class.md#oninitdialog)e para janelas de quadro, na [OnCreate](../mfc/reference/cwnd-class.md#oncreate).

O exemplo a seguir mostra como você pode declarar uma `CEdit` do objeto na declaração da classe de uma classe derivada de caixa de diálogo e, em seguida, chamar o `Create` função de membro em `OnInitDialog`. Porque o `CEdit` objeto for declarado como um objeto inserido, ele é construído automaticamente quando o objeto de caixa de diálogo é construído, mas ele ainda deve ser inicializado com seu próprio `Create` função de membro.

[!code-cpp[NVC_MFCControlLadenDialog#1](../mfc/codesnippet/cpp/adding-controls-by-hand_1.h)]

O seguinte `OnInitDialog` função configura um retângulo, em seguida, chama `Create` para criar o controle de edição do Windows e anexá-lo para o não inicializado `CEdit` objeto.

[!code-cpp[NVC_MFCControlLadenDialog#2](../mfc/codesnippet/cpp/adding-controls-by-hand_2.cpp)]

Depois de criar o objeto de edição, você também pode definir o foco de entrada para o controle, chamando o `SetFocus` função de membro. Por fim, você pode retornar 0 de `OnInitDialog` para mostrar que você defina o foco. Se você retornar um valor diferente de zero, o Gerenciador de caixa de diálogo define o foco para o primeiro item de controle na lista de itens de caixa de diálogo. Na maioria dos casos, você desejará adicionar controles à sua caixa de diálogo com o editor de caixa de diálogo.

## <a name="see-also"></a>Consulte também

[Criando e usando controles](../mfc/making-and-using-controls.md)<br/>
[Controles](../mfc/controls-mfc.md)<br/>
[CDialog::OnInitDialog](../mfc/reference/cdialog-class.md#oninitdialog)

