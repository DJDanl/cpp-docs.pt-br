---
title: 'Controles ActiveX MFC: adicionando métodos de estoque'
ms.date: 09/12/2018
helpviewer_keywords:
- MFC ActiveX controls [MFC], stock methods
- MFC ActiveX controls [MFC], methods
- DoClick method [MFC]
ms.assetid: bc4fad78-cabd-4cc0-a798-464b1a682f0b
ms.openlocfilehash: ec59ccc0cbd48fc3114eb2dc0833dd3dd65691de
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81364678"
---
# <a name="mfc-activex-controls-adding-stock-methods"></a>Controles ActiveX MFC: adicionando métodos de estoque

Um método de estoque difere de um método personalizado, pois já é implementado pela classe [COleControl](../mfc/reference/colecontrol-class.md). Por exemplo, `COleControl` contém uma função de membro predefinida que suporta o método Refresh para o seu controle. A entrada do mapa de despacho para este método de estoque é DISP_STOCKFUNC_REFRESH.

>[!IMPORTANT]
> ActiveX é uma tecnologia herdada que não deve ser usada para novos desenvolvimentos. Para obter mais informações sobre tecnologias modernas que substituim o ActiveX, consulte [ActiveX Controls](activex-controls.md).

`COleControl`suporta dois métodos de estoque: DoClick e Refresh. A atualização é invocada pelo usuário do controle para atualizar imediatamente a aparência do controle; DoClick é invocado para disparar o evento Click do controle.

|Método|Entrada do mapa de despacho|Comentário|
|------------|------------------------|-------------|
|`DoClick`|**DISP_STOCKPROP_DOCLICK.**|Dispara um evento Click.|
|`Refresh`|**DISP_STOCKPROP_REFRESH.**|Atualiza imediatamente a aparência do controle.|

## <a name="adding-a-stock-method-using-the-add-method-wizard"></a><a name="_core_adding_a_stock_method_using_classwizard"></a>Adicionando um método de estoque usando o assistente de método de adicionar

Adicionar um método de estoque é simples usando o [Assistente de Método de Adicionar](../ide/add-method-wizard.md). O procedimento a seguir demonstra a adição do método Refresh a um controle criado usando o MFC ActiveX Control Wizard.

#### <a name="to-add-the-stock-refresh-method-using-the-add-method-wizard"></a>Para adicionar o método de atualização de estoque usando o Assistente de Método de Adicionar

1. Carregue o projeto do seu controle.

1. Em Class View, expanda o nó de biblioteca do seu controle.

1. Clique com o botão direito do mouse no nó de interface para o seu controle (o segundo nó do nó da biblioteca) para abrir o menu de atalho.

1. No menu de atalho, clique **em Adicionar** e clique em **Adicionar método**.

   Isso abre o Assistente de Método de Adicionar.

1. Na caixa Nome do **método,** clique **em Atualizar**.

1. Clique em **Concluir**.

## <a name="add-method-wizard-changes-for-stock-methods"></a><a name="_core_classwizard_changes_for_stock_methods"></a>Adicionar alterações do assistente de método para métodos de estoque

Como o método de atualização de estoque é suportado pela classe base do controle, o **Assistente de Método de adicionar** não altera a declaração de classe do controle de forma alguma. Adiciona uma entrada para o método ao mapa de despacho do controle e ao seu . Arquivo IDL. A linha a seguir é adicionada ao mapa de despacho do controle, localizado em sua implementação (. Arquivo CPP):

[!code-cpp[NVC_MFC_AxUI#16](../mfc/codesnippet/cpp/mfc-activex-controls-adding-stock-methods_1.cpp)]

Isso torna o método Refresh disponível para os usuários do controle.

A linha a seguir é adicionada ao controle. Arquivo IDL:

[!code-cpp[NVC_MFC_AxUI#17](../mfc/codesnippet/cpp/mfc-activex-controls-adding-stock-methods_2.idl)]

Esta linha atribui ao método Atualizar um número de ID específico.

## <a name="see-also"></a>Confira também

[Controles ActiveX do MFC](../mfc/mfc-activex-controls.md)
