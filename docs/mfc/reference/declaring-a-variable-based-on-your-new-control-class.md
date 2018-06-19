---
title: Declarando uma variável com base em sua nova classe de controle | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: reference
f1_keywords:
- vc.codewiz.classes.control.variable
dev_langs:
- C++
helpviewer_keywords:
- variables [MFC], control classes
- control classes [MFC], variables
- classes [MFC], declaring variables based on
ms.assetid: 5722dc38-c0eb-40bd-93da-67a808140d03
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 677006d441c940f478b3d23744d1057667307e1a
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33370608"
---
# <a name="declaring-a-variable-based-on-your-new-control-class"></a>Declarando uma variável com base na nova classe de controle
Depois de criar uma classe de controle MFC, você pode declarar uma variável com base nele. Para fornecer um contexto para a nova variável, você deve abrir o editor de caixa de diálogo e edite a caixa de diálogo na qual você deseja usar o controle reutilizável. Além disso, a caixa de diálogo já deve ter uma classe associada a ele. Para obter informações sobre como usar o editor de caixa de diálogo, consulte [Editor de caixa de diálogo](../../windows/dialog-editor.md).  
  
### <a name="to-declare-a-variable-based-on-your-reusable-class"></a>Para declarar uma variável com base em sua classe reutilizável  
  
1.  Ao editar a caixa de diálogo, arraste um controle do mesmo tipo de classe base do novo controle de barra de ferramentas de controles para a caixa de diálogo.  
  
2.  Coloque o ponteiro do mouse sobre o controle descartado.  
  
3.  Ao pressionar a tecla CTRL pressionada, clique duas vezes no controle.  
  
     O [Adicionar variável membro](../../ide/add-member-variable-wizard.md) caixa de diálogo é exibida.  
  
4.  No **acesso** , selecione o acesso correto para seu controle.  
  
5.  Clique o **variável de controle de** caixa de seleção.  
  
6.  No **nome da variável** , digite um nome.  
  
7.  Em **categoria**, clique em **controle**.  
  
8.  No **ID de controle** lista, selecione o controle que você adicionou. O **tipo de variável** lista deve exibir o tipo de variável correto e o **tipo de controle** caixa deve exibir o tipo de controle correto.  
  
9. No **comentário** caixa, adicione qualquer comentário que você deseja exibir em seu código.  
  
10. Clique em **OK**.  
  
## <a name="see-also"></a>Consulte também  
 [Mapeando mensagens para funções](../../mfc/reference/mapping-messages-to-functions.md)   
 [Adicionando funcionalidade com assistentes de código](../../ide/adding-functionality-with-code-wizards-cpp.md)   
 [Adicionando uma classe](../../ide/adding-a-class-visual-cpp.md)   
 [Adicionar uma função de membro](../../ide/adding-a-member-function-visual-cpp.md)   
 [Adicionar uma variável de membro](../../ide/adding-a-member-variable-visual-cpp.md)   
 [Substituindo uma função Virtual](../../ide/overriding-a-virtual-function-visual-cpp.md)   
 [Manipulador de mensagens do MFC](../../mfc/reference/adding-an-mfc-message-handler.md)   
 [Navegando na estrutura de classe](../../ide/navigating-the-class-structure-visual-cpp.md)
