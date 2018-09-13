---
title: 'Controles ActiveX MFC: Adicionando métodos de estoque | Microsoft Docs'
ms.custom: ''
ms.date: 09/12/2018
ms.technology:
- cpp-mfc
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- MFC ActiveX controls [MFC], stock methods
- MFC ActiveX controls [MFC], methods
- DoClick method [MFC]
ms.assetid: bc4fad78-cabd-4cc0-a798-464b1a682f0b
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 604a095ab26abf4953d56786e00461cabd07e579
ms.sourcegitcommit: b4432d30f255f0cb58dce69cbc8cbcb9d44bc68b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/13/2018
ms.locfileid: "45534944"
---
# <a name="mfc-activex-controls-adding-stock-methods"></a>Controles ActiveX MFC: adicionando métodos de estoque
Um método de estoque difere de um método personalizado em que ele já foi implementado pela classe [COleControl](../mfc/reference/colecontrol-class.md). Por exemplo, `COleControl` contém uma função de membro predefinidas que suporta o método de atualização para o seu controle. A entrada de mapa de expedição para esse método de estoque é DISP_STOCKFUNC_REFRESH.

>[!IMPORTANT]
> ActiveX é uma tecnologia herdada que não deve ser usada para novos desenvolvimentos. Para obter mais informações sobre tecnologias modernas que substituem as ActiveX, consulte [controles ActiveX](activex-controls.md).  
  
 `COleControl` dá suporte a dois métodos de estoque: DoClick e a atualização. Atualizar seja invocado pelo usuário do controle para atualizar imediatamente a aparência do controle; DoClick é chamado para acionar Click do controle eventos.  
  
|Método|Entrada de mapa de expedição|Comentário|  
|------------|------------------------|-------------|  
|`DoClick`|**(DISP_STOCKPROP_DOCLICK)**|Dispara um evento de clique.|  
|`Refresh`|**(DISP_STOCKPROP_REFRESH)**|Atualiza imediatamente a aparência do controle.|  
  
##  <a name="_core_adding_a_stock_method_using_classwizard"></a> Adicionar um método de ação usando o Assistente do método de adição  
 Adicionando um método de estoque é simple usando o [Assistente de adição de método](../ide/add-method-wizard.md). O procedimento a seguir demonstra como adicionar o método de atualização para um controle criado usando o Assistente de controle de ActiveX do MFC.  
  
#### <a name="to-add-the-stock-refresh-method-using-the-add-method-wizard"></a>Para adicionar o método de atualização de ações usando o Assistente para adicionar método  
  
1.  Carregar o projeto do seu controle.  
  
2.  No modo de exibição de classe, expanda o nó de biblioteca do seu controle.  
  
3.  Para abrir o menu de atalho, clique com botão direito no nó de interface para o seu controle (o segundo nó do nó de biblioteca).  
  
4.  No menu de atalho, clique em **Add** e, em seguida, clique em **Add Method**.  
  
     Isso abre o Assistente para adição de método.  
  
5.  No **nome do método** , clique em **atualizar**.  
  
6.  Clique em **Finalizar**.  
  
##  <a name="_core_classwizard_changes_for_stock_methods"></a> Adicionar Assistente altera o método para métodos de estoque  
 Porque o método de atualização de estoque é suportado pela classe de base do controle, o **Assistente de adição de método** não altera a declaração de classe do controle de forma alguma. Ele adiciona uma entrada para o método de mapa de expedição do controle e à sua. Arquivo IDL. A linha a seguir é adicionada ao mapa de expedição do controle, localizado em sua implementação (. Arquivo CPP):  
  
 [!code-cpp[NVC_MFC_AxUI#16](../mfc/codesnippet/cpp/mfc-activex-controls-adding-stock-methods_1.cpp)]  
  
 Isso torna o método de atualização disponível para usuários do controle.  
  
 A seguinte linha é adicionada para o controle. Arquivo IDL:  
  
 [!code-cpp[NVC_MFC_AxUI#17](../mfc/codesnippet/cpp/mfc-activex-controls-adding-stock-methods_2.idl)]  
  
 Essa linha atribui o método de atualização de um número de ID específico.  
  
## <a name="see-also"></a>Consulte também  
 [Controles ActiveX do MFC](../mfc/mfc-activex-controls.md)

