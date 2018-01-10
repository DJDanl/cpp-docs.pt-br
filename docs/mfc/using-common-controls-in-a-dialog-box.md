---
title: "Usando controles comuns em uma caixa de diálogo | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
dev_langs: C++
helpviewer_keywords:
- common controls [MFC], in dialog boxes
- dialog box controls [MFC], common controls
- Windows common controls [MFC], in dialog boxes
ms.assetid: 17713caf-09f8-484a-bf54-5f48bf09cce9
caps.latest.revision: "11"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 67a9c77e6a8e5721bca6e3741b4b337cfdb42393
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="using-common-controls-in-a-dialog-box"></a>Usando controles comuns em uma caixa de diálogo
Controles comuns do Windows podem ser usados em [caixas de diálogo](../mfc/dialog-boxes.md), exibições, exibições de registro e qualquer outra janela baseada em um modelo de caixa de diálogo de formulário. O procedimento a seguir, com algumas pequenas alterações, funcionará para formulários.  
  
## <a name="procedures"></a>Procedimentos  
  
#### <a name="to-use-a-common-control-in-a-dialog-box"></a>Para usar um controle comum em uma caixa de diálogo  
  
1.  Posicione o controle sobre o modelo de caixa de diálogo [usando o editor de caixa de diálogo](../mfc/using-the-dialog-editor-to-add-controls.md).  
  
2.  Adicione uma variável de membro que representa o controle para a classe de caixa de diálogo. No **Adicionar variável de membro** caixa de diálogo seleção **variável de controle de** e certifique-se de que **controle** é selecionado para o **categoria**.  
  
3.  Se este controle comum é fornecer entrada para o programa, declare membro adicionais variable(s) na classe de caixa de diálogo para lidar com os valores de entrada.  
  
    > [!NOTE]
    >  Você pode adicionar as variáveis de membro usando o menu de contexto no modo de exibição de classe (consulte [adicionar uma variável de membro](../ide/adding-a-member-variable-visual-cpp.md)).  
  
4.  Em [OnInitDialog](../mfc/reference/cdialog-class.md#oninitdialog) para sua classe de caixa de diálogo, defina as condições inicias para o controle comum. Usando a variável de membro criada na etapa anterior, use as funções de membro para definir o valor inicial e outras configurações. Consulte as seguintes descrições dos controles para obter detalhes sobre configurações.  
  
     Você também pode usar [troca de dados de caixa de diálogo](../mfc/dialog-data-exchange-and-validation.md) (DDX) para inicializar a controles em uma caixa de diálogo.  
  
5.  Em manipuladores para controles de caixa de diálogo, use a variável de membro para manipular o controle. Consulte as seguintes descrições dos controles para obter detalhes sobre métodos.  
  
    > [!NOTE]
    >  A variável de membro continuará a existir somente enquanto existe a caixa de diálogo. Você não poderá consultar o controle para valores de entrada depois que a caixa de diálogo foi fechada. Para trabalhar com valores de entrada de um controle comum, substituir `OnOK` em sua classe de caixa de diálogo. Na sua substituição, o controle para valores de entrada de consulta e armazenar esses valores em variáveis de membro da classe de caixa de diálogo.  
  
    > [!NOTE]
    >  Você também pode usar a troca de dados de caixa de diálogo para definir ou recuperar os valores dos controles em uma caixa de diálogo.  
  
## <a name="remarks"></a>Comentários  
 A adição de alguns controles comuns para uma caixa de diálogo fará com que a caixa de diálogo não funcionem. Consulte [adicionando controles a uma caixa de diálogo faz com que a caixa de diálogo para a função não é mais](../windows/adding-controls-to-a-dialog-causes-the-dialog-to-no-longer-function.md) para obter mais informações sobre como tratar essa situação.  
  
## <a name="what-do-you-want-to-do"></a>O que você deseja fazer  
  
-   [Adicionar controles a uma caixa de diálogo manualmente em vez de com o editor de caixa de diálogo](../mfc/adding-controls-by-hand.md)  
  
-   [Derivar o controle de um dos controles comuns do Windows padrão](../mfc/deriving-controls-from-a-standard-control.md)  
  
-   [Usar um controle comum como uma janela filho](../mfc/using-a-common-control-as-a-child-window.md)  
  
-   [Receber mensagens de notificação de um controle](../mfc/receiving-notification-from-common-controls.md)  
  
-   [Use a troca de dados de caixa de diálogo (DDX)](../mfc/dialog-data-exchange-and-validation.md)  
  
## <a name="see-also"></a>Consulte também  
 [Criando e usando controles](../mfc/making-and-using-controls.md)   
 [Controles](../mfc/controls-mfc.md)

