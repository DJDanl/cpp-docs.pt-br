---
title: "Declarando uma variável com base na nova classe de controle | Documentos do Microsoft"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- vc.codewiz.classes.control.variable
dev_langs:
- C++
helpviewer_keywords:
- variables, control classes
- control classes, variables
- classes [C++], declaring variables based on
ms.assetid: 5722dc38-c0eb-40bd-93da-67a808140d03
caps.latest.revision: 9
author: mikeblome
ms.author: mblome
manager: ghogen
translation.priority.ht:
- cs-cz
- de-de
- es-es
- fr-fr
- it-it
- ja-jp
- ko-kr
- pl-pl
- pt-br
- ru-ru
- tr-tr
- zh-cn
- zh-tw
ms.translationtype: Machine Translation
ms.sourcegitcommit: 4fafe461008e3545243d693e0d9e34acd57163e0
ms.openlocfilehash: a5777019ca87616fbb7c6a0d27140b3fabbf7fde
ms.contentlocale: pt-br
ms.lasthandoff: 02/25/2017

---
# <a name="declaring-a-variable-based-on-your-new-control-class"></a>Declarando uma variável com base na nova classe de controle
Depois de criar uma classe de controle do MFC, você pode declarar uma variável com base nele. Para fornecer um contexto para a nova variável, você deve abrir o editor de caixa de diálogo e edite a caixa de diálogo na qual você deseja usar o controle reutilizável. Além disso, a caixa de diálogo já deve ter uma classe associada a ele. Para obter informações sobre como usar o editor de diálogo, consulte [Editor de diálogo](../../windows/dialog-editor.md).  
  
### <a name="to-declare-a-variable-based-on-your-reusable-class"></a>Para declarar uma variável com base em sua classe reutilizável  
  
1.  Ao editar a caixa de diálogo, arraste um controle do mesmo tipo como a classe base do seu novo controle na barra de ferramentas de controles para a caixa de diálogo.  
  
2.  Coloque o ponteiro do mouse sobre o controle descartado.  
  
3.  Enquanto pressiona a tecla CTRL pressionada, clique duas vezes no controle.  
  
     O [Adicionar variável membro](../../ide/add-member-variable-wizard.md) caixa de diálogo é exibida.  
  
4.  No **acesso** , selecione o acesso correto para o seu controle.  
  
5.  Clique o **variável de controle** caixa de seleção.  
  
6.  No **o nome da variável** , digite um nome.  
  
7.  Em **categoria**, clique em **controle**.  
  
8.  No **ID do controle** lista, selecione o controle que você adicionou. O **tipo de variável** lista deve exibir o tipo de variável correto e o **tipo de controle** caixa deve exibir o tipo de controle correto.  
  
9. No **comentário** caixa, adicione qualquer comentário que você deseja que apareça no seu código.  
  
10. Clique em **OK**.  
  
## <a name="see-also"></a>Consulte também  
 [Mapeando mensagens para funções](../../mfc/reference/mapping-messages-to-functions.md)   
 [Adicionando funcionalidade com assistentes de código](../../ide/adding-functionality-with-code-wizards-cpp.md)   
 [Adicionando uma classe](../../ide/adding-a-class-visual-cpp.md)   
 [Adicionando uma função de membro](../../ide/adding-a-member-function-visual-cpp.md)   
 [Adicionando uma variável de membro](../../ide/adding-a-member-variable-visual-cpp.md)   
 [Substituindo uma função Virtual](../../ide/overriding-a-virtual-function-visual-cpp.md)   
 [Manipulador de mensagens do MFC](../../mfc/reference/adding-an-mfc-message-handler.md)   
 [Navegando na estrutura da classe](../../ide/navigating-the-class-structure-visual-cpp.md)

