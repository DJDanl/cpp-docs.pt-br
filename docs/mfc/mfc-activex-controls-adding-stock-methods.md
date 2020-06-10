---
title: 'Controles ActiveX MFC: adicionando métodos de estoque'
ms.date: 09/12/2018
helpviewer_keywords:
- MFC ActiveX controls [MFC], stock methods
- MFC ActiveX controls [MFC], methods
- DoClick method [MFC]
ms.assetid: bc4fad78-cabd-4cc0-a798-464b1a682f0b
ms.openlocfilehash: 42d8dfecd32b4aecd0daa4034497ec9abff6d11a
ms.sourcegitcommit: c21b05042debc97d14875e019ee9d698691ffc0b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 06/09/2020
ms.locfileid: "84619933"
---
# <a name="mfc-activex-controls-adding-stock-methods"></a>Controles ActiveX MFC: adicionando métodos de estoque

Um método stock é diferente de um método personalizado no qual ele já está implementado pela classe [COleControl](reference/colecontrol-class.md). Por exemplo, `COleControl` contém uma função de membro predefinida que dá suporte ao método Refresh para seu controle. A entrada do mapa de expedição para este método de ação é DISP_STOCKFUNC_REFRESH.

>[!IMPORTANT]
> O ActiveX é uma tecnologia herdada que não deve ser usada para novos desenvolvimentos. Para obter mais informações sobre as tecnologias modernas que substituem o ActiveX, consulte [controles ActiveX](activex-controls.md).

`COleControl`dá suporte a dois métodos de ação: doclique e atualizar. A atualização é invocada pelo usuário do controle para atualizar imediatamente a aparência do controle; DoClick é invocado para acionar o evento de clique do controle.

|Método|Entrada do mapa de expedição|Comentário|
|------------|------------------------|-------------|
|`DoClick`|**DISP_STOCKPROP_DOCLICK ()**|Dispara um evento de clique.|
|`Refresh`|**DISP_STOCKPROP_REFRESH ()**|Atualiza imediatamente a aparência do controle.|

## <a name="adding-a-stock-method-using-the-add-method-wizard"></a><a name="_core_adding_a_stock_method_using_classwizard"></a>Adicionando um método stock usando o assistente para adicionar método

Adicionar um método stock é simples usando o [Assistente para adicionar método](../ide/add-method-wizard.md). O procedimento a seguir demonstra como adicionar o método Refresh a um controle criado usando o assistente de controle ActiveX do MFC.

#### <a name="to-add-the-stock-refresh-method-using-the-add-method-wizard"></a>Para adicionar o método de atualização de estoque usando o assistente para adicionar método

1. Carregue o projeto do seu controle.

1. Em Modo de Exibição de Classe, expanda o nó biblioteca do seu controle.

1. Clique com o botão direito do mouse no nó da interface do seu controle (o segundo nó do nó da biblioteca) para abrir o menu de atalho.

1. No menu de atalho, clique em **Adicionar** e, em seguida, clique em **Adicionar método**.

   Isso abre o assistente para adicionar método.

1. Na caixa **nome do método** , clique em **Atualizar**.

1. Clique em **Concluir**.

## <a name="add-method-wizard-changes-for-stock-methods"></a><a name="_core_classwizard_changes_for_stock_methods"></a>Adicionar alterações do assistente de método para métodos de ações

Como o método de atualização de estoque é suportado pela classe base do controle, o **Assistente para adicionar método** não altera a declaração de classe do controle de forma alguma. Ele adiciona uma entrada para o método ao mapa de expedição do controle e ao seu. Arquivo IDL. A linha a seguir é adicionada ao mapa de expedição do controle, localizado em sua implementação (. CPP) arquivo:

[!code-cpp[NVC_MFC_AxUI#16](codesnippet/cpp/mfc-activex-controls-adding-stock-methods_1.cpp)]

Isso torna o método de atualização disponível para os usuários do controle.

A linha a seguir é adicionada ao controle do. Arquivo IDL:

[!code-cpp[NVC_MFC_AxUI#17](codesnippet/cpp/mfc-activex-controls-adding-stock-methods_2.idl)]

Essa linha atribui o método de atualização a um número de ID específico.

## <a name="see-also"></a>Consulte também

[Controles ActiveX do MFC](mfc-activex-controls.md)
