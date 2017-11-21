---
title: Adicionando controles manualmente | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
dev_langs: C++
helpviewer_keywords:
- Windows common controls [MFC], adding
- dialog box controls [MFC], adding to dialog boxes
- controlling input focus
- input focus control
- focus, controlling input [MFC]
- controls [MFC], adding to dialog boxes
- common controls [MFC], adding
ms.assetid: bc843e59-0c51-4b5b-8bf2-343f716469d2
caps.latest.revision: "12"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.openlocfilehash: 15712cbcae434f036c6c1b35800a566286932f88
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
---
# <a name="adding-controls-by-hand"></a>Adicionando controles manualmente
Você pode [adicionar controles a uma caixa de diálogo com o editor de caixa de diálogo](../mfc/using-the-dialog-editor-to-add-controls.md) ou adicioná-las por conta própria, com o código.  
  
 Para criar um objeto de controle, você geralmente irá inserir o objeto de controle de C++ em uma caixa de diálogo de C++ ou janela do quadro. Como muitos outros objetos no framework, controles requerem construção de dois estágios. Você deve chamar o controle **criar** função de membro como parte da criação da caixa de diálogo caixa ou quadro de janela pai. Para caixas de diálogo, isso geralmente é feito no [OnInitDialog](../mfc/reference/cdialog-class.md#oninitdialog)e para janelas de quadro no [OnCreate](../mfc/reference/cwnd-class.md#oncreate).  
  
 O exemplo a seguir mostra como você pode declarar uma `CEdit` do objeto na declaração da classe de uma classe derivada da caixa de diálogo e, em seguida, chame o **criar** função de membro em `OnInitDialog`. Porque o `CEdit` objeto for declarado como um objeto inserido, ele é construído automaticamente quando o objeto de caixa de diálogo é construído, mas ainda deve ser inicializado com seu próprio **criar** função de membro.  
  
 [!code-cpp[NVC_MFCControlLadenDialog#1](../mfc/codesnippet/cpp/adding-controls-by-hand_1.h)]  
  
 O seguinte `OnInitDialog` função configura um retângulo, em seguida, chama **criar** para criar o controle de edição do Windows e anexá-lo para o não inicializada `CEdit` objeto.  
  
 [!code-cpp[NVC_MFCControlLadenDialog#2](../mfc/codesnippet/cpp/adding-controls-by-hand_2.cpp)]  
  
 Depois de criar o objeto de edição, você também pode definir o foco de entrada para o controle chamando o `SetFocus` função de membro. Por fim, você pode retornar 0 de `OnInitDialog` para mostrar a você definir o foco. Se você retornar um valor diferente de zero, o Gerenciador de caixa de diálogo define o foco para o primeiro item de controle na lista de item de caixa de diálogo. Na maioria dos casos, você desejará adicionar controles à sua caixa de diálogo com o editor de caixa de diálogo.  
  
## <a name="see-also"></a>Consulte também  
 [Criando e usando controles](../mfc/making-and-using-controls.md)   
 [Controles](../mfc/controls-mfc.md)   
 [CDialog::OnInitDialog](../mfc/reference/cdialog-class.md#oninitdialog)

