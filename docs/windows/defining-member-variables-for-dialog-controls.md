---
title: Definindo variáveis de membro para controles de caixa de diálogo | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- member variables, defining for controls
- variables, dialog box control member variables
- controls [C++], member variables
- Dialog editor, defining member variables for controls
ms.assetid: 84347c63-c33c-4b04-91f5-6d008c45ba58
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 8ba8fc95290ecb90557203be2b6ab4cce18b91e3
ms.sourcegitcommit: d55ac596ba8f908f5d91d228dc070dad31cb8360
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/08/2018
---
# <a name="defining-member-variables-for-dialog-controls"></a>Definindo variáveis de membro para controles da caixa de diálogo
Para definir uma variável de membro de qualquer controle de caixa de diálogo exceto botões, você pode usar o método a seguir.  
  
> [!NOTE]
>  Este artigo se aplica somente a controles de caixa de diálogo dentro de um projeto MFC. Projetos ATL devem usar o **novas mensagens do Windows e manipuladores de eventos** caixa de diálogo.  
  
### <a name="to-define-a-member-variable-for-a-non-button-dialog-box-control"></a>Para definir uma variável de membro para um controle de caixa de diálogo (não-botão)  
  
1.  No [editor de caixa de diálogo](../windows/dialog-editor.md), selecione um controle.  
  
2.  Ao pressionar o **CTRL** da chave, clique duas vezes no controle da caixa de diálogo.  
  
     O [assistente Adicionar variável membro](../ide/add-member-variable-wizard.md) é exibida.  
  
3.  Digite as informações apropriadas no **Adicionar variável membro** assistente. Para obter mais informações, consulte [troca de dados de caixa de diálogo](../mfc/dialog-data-exchange.md).  
  
4.  Clique em **Okey** para retornar ao editor de caixa de diálogo.  
  
    > [!TIP]
    >  Para saltar de qualquer controle de caixa de diálogo para seu manipulador existente, clique duas vezes no controle.  
  

  
 Você também pode usar o **variáveis de membro** guia **Assistente de classe MFC** para adicionar novas variáveis de membro para uma determinada classe e exibir aqueles que já foi definido.  
  
 Requisitos  
  
 MFC  
  
## <a name="see-also"></a>Consulte também  
 [Mapeando mensagens para funções](../mfc/reference/mapping-messages-to-functions.md)   
 [Adicionando funcionalidade com assistentes de código](../ide/adding-functionality-with-code-wizards-cpp.md)   
 [Assistente de classe MFC](../mfc/reference/mfc-class-wizard.md)   
 [Adicionando uma classe](../ide/adding-a-class-visual-cpp.md)   
 [Adicionar uma função de membro](../ide/adding-a-member-function-visual-cpp.md)   
 [Adicionar uma variável de membro](../ide/adding-a-member-variable-visual-cpp.md)   
 [Substituindo uma função Virtual](../ide/overriding-a-virtual-function-visual-cpp.md)   
 [Manipulador de mensagens do MFC](../mfc/reference/adding-an-mfc-message-handler.md)

