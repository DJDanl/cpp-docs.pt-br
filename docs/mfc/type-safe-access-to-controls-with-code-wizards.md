---
title: Acesso fortemente tipado a controles com assistentes de código | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- DDX (dialog data exchange), access to controls
- code wizards
- dialog boxes [MFC], access to controls
- dialog box controls [MFC], accessing
ms.assetid: b8874393-ee48-4124-8d78-e3648a7e29b9
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 025fd280dc6bf0947dae59cf77abe141bc312df8
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33385180"
---
# <a name="type-safe-access-to-controls-with-code-wizards"></a>Acesso fortemente tipado a controles com assistentes de código
Se você estiver familiarizado com recursos DDX, você pode usar a propriedade de controle no [Adicionar Assistente de variável de membro](../ide/add-member-variable-wizard.md) para criar acesso fortemente tipado. Essa abordagem é mais fácil do que a criação de controles sem assistentes de código.  
  
 Se você quiser simplesmente acesso ao valor de um controle, DDX fornece. Se você quiser mais de um valor de controle de acesso, use o Assistente para adição de variável de membro para adicionar uma variável de membro da classe apropriada para sua classe de caixa de diálogo. Anexe a essa variável de membro para a propriedade de controle.  
  
 Variáveis de membro podem ter uma propriedade de controle, em vez de uma propriedade de valor. A propriedade de valor se refere ao tipo de dados retornados de controle, como `CString` ou `int`. A propriedade de controle permite acesso direto ao controle por meio de um membro de dados cujo tipo é uma das classes de controle em MFC, tais como `CButton` ou `CEdit`.  
  
> [!NOTE]
>  Para um determinado controle, você pode, se desejar, ter diversas variáveis de membro com a propriedade de valor e no máximo a variável de um membro com a propriedade de controle. Você pode ter apenas um objeto MFC mapeado para um controle porque vários objetos anexados a um controle ou qualquer outra janela, poderia levar a uma ambiguidade no mapa de mensagem.  
  
 Você pode usar esse objeto para chamar funções de qualquer membro para o objeto de controle. Essas chamadas afetam o controle na caixa de diálogo. Por exemplo, para um controle de caixa de seleção representado por uma variável `m_Checkbox`, do tipo `CButton`, você poderia chamar:  
  
 [!code-cpp[NVC_MFCControlLadenDialog#52](../mfc/codesnippet/cpp/type-safe-access-to-controls-with-code-wizards_1.cpp)]  
  
 Aqui, a variável membro `m_Checkbox` tem a mesma finalidade da função de membro `GetMyCheckbox` mostrado em [acesso fortemente tipado a controles sem assistentes de código](../mfc/type-safe-access-to-controls-without-code-wizards.md). Se a caixa de seleção não é uma caixa de seleção automática, ainda precisará um manipulador em sua classe de caixa de diálogo para o **BN_CLICKED** mensagem de notificação de controle quando o botão é clicado.  
  
 Para obter mais informações sobre os controles, consulte [controles](../mfc/controls-mfc.md).  
  
## <a name="see-also"></a>Consulte também  
 [Acesso fortemente tipado a controles em uma caixa de diálogo](../mfc/type-safe-access-to-controls-in-a-dialog-box.md)   
 [Ciclo de vida de uma caixa de diálogo](../mfc/life-cycle-of-a-dialog-box.md)   
 [Acesso fortemente tipado a controles sem assistentes de código](../mfc/type-safe-access-to-controls-without-code-wizards.md)

