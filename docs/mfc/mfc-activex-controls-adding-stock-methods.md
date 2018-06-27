---
title: 'Controles ActiveX MFC: Adicionando métodos de estoque | Microsoft Docs'
ms.custom: ''
ms.date: 11/04/2016
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
ms.openlocfilehash: 2005391c6d91ee09703194eb8b8062ecfe08ba77
ms.sourcegitcommit: 060f381fe0807107ec26c18b46d3fcb859d8d2e7
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 06/25/2018
ms.locfileid: "36929793"
---
# <a name="mfc-activex-controls-adding-stock-methods"></a>Controles ActiveX MFC: adicionando métodos de estoque
Um método de ação difere de um método personalizado em que ele já foi implementado pela classe [COleControl](../mfc/reference/colecontrol-class.md). Por exemplo, `COleControl` contém uma função de membro predefinidas que suporta o método de atualização para o seu controle. A entrada de mapa de expedição para esse método de estoque é DISP_STOCKFUNC_REFRESH.  
  
 `COleControl` oferece suporte a dois métodos de estoque: DoClick e a atualização. A atualização é chamada pelo usuário do controle para atualizar imediatamente a aparência do controle; DoClick é chamado para acionar o clique do controle eventos.  
  
|Método|Entrada de mapa de expedição|Comentário|  
|------------|------------------------|-------------|  
|`DoClick`|**(DISP_STOCKPROP_DOCLICK)**|Dispara um evento de clique.|  
|`Refresh`|**(DISP_STOCKPROP_REFRESH)**|Atualiza imediatamente a aparência do controle.|  
  
##  <a name="_core_adding_a_stock_method_using_classwizard"></a> Adicionando um método de ação usando o Assistente para o método adicionar  
 Adicionando um método de estoque é simple usando o [Assistente para adição de método](../ide/add-method-wizard.md). O procedimento a seguir demonstra como adicionar o método de atualização para um controle criado usando o Assistente de controle ActiveX MFC.  
  
#### <a name="to-add-the-stock-refresh-method-using-the-add-method-wizard"></a>Para adicionar o método de atualização de estoque usando o Assistente para adição de método  
  
1.  Carregar projeto do controle.  
  
2.  No modo de exibição de classe, expanda o nó de biblioteca de seu controle.  
  
3.  Para abrir o menu de atalho, clique com botão direito no nó de interface de seu controle (o segundo nó do nó de biblioteca).  
  
4.  No menu de atalho, clique em **adicionar** e, em seguida, clique em **Adicionar método**.  
  
     Isso abre o Assistente para adição de método.  
  
5.  No **nome do método** , clique em **atualizar**.  
  
6.  Clique em **Finalizar**.  
  
##  <a name="_core_classwizard_changes_for_stock_methods"></a> Adicionar Assistente altera o método para métodos de estoque  
 Porque o método de atualização de estoque é suportado pela classe de base do controle, o **Assistente para adição de método** não altera a declaração de classe do controle de qualquer forma. Adiciona uma entrada para o método para o mapa de expedição do controle e seu. Arquivo IDL. A seguinte linha é adicionada ao mapa de expedição do controle, localizado em sua implementação (. Arquivo CPP):  
  
 [!code-cpp[NVC_MFC_AxUI#16](../mfc/codesnippet/cpp/mfc-activex-controls-adding-stock-methods_1.cpp)]  
  
 Isso torna o método de atualização disponíveis para usuários do controle.  
  
 A seguinte linha é adicionada para o controle. Arquivo IDL:  
  
 [!code-cpp[NVC_MFC_AxUI#17](../mfc/codesnippet/cpp/mfc-activex-controls-adding-stock-methods_2.idl)]  
  
 Essa linha atribui o método de atualização de um determinado número de ID.  
  
## <a name="see-also"></a>Consulte também  
 [Controles ActiveX do MFC](../mfc/mfc-activex-controls.md)

