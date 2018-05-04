---
title: Implementando uma caixa de diálogo | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-atl
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- CSimpleDialog class, implementing dialog boxes in ATL
- dialog boxes, ATL
- CAxDialogImpl class, implementing dialog boxes in ATL
- ATL, dialog boxes
ms.assetid: 478525f2-aa6a-435a-b162-68fc8aa98a8e
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 672696027a43cd5a50e2ad630824d305f7ca4b68
ms.sourcegitcommit: be2a7679c2bd80968204dee03d13ca961eaa31ff
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/03/2018
---
# <a name="implementing-a-dialog-box"></a>Implementando uma caixa de diálogo
Há duas maneiras de adicionar uma caixa de diálogo ao seu projeto ATL: usar o Assistente de caixa de diálogo do ATL ou adicioná-lo manualmente.  
  
## <a name="adding-a-dialog-box-with-the-atl-dialog-wizard"></a>Adicionar uma caixa de diálogo com o Assistente de caixa de diálogo do ATL  
 No [caixa de diálogo Adicionar classe](../ide/add-class-dialog-box.md), selecione o objeto de caixa de diálogo do ATL para adicionar uma caixa de diálogo ao seu projeto ATL. Preencha o Assistente de caixa de diálogo do ATL conforme apropriado e clique em **concluir**. O assistente adiciona uma classe derivada de [CAxDialogImpl](../atl/reference/caxdialogimpl-class.md) ao seu projeto. Abra o modo de exibição de recursos da **exibição** menu, localize a caixa de diálogo e clique duas vezes nele para abri-lo no editor de recursos.  
  
> [!NOTE]
>  Se a caixa de diálogo é derivada de `CAxDialogImpl`, ele pode hospedar ambos ActiveX e controles de Windows. Se você não quiser a sobrecarga de suporte de controle ActiveX em sua classe de caixa de diálogo, use [CSimpleDialog](../atl/reference/csimpledialog-class.md) ou [CDialogImpl](../atl/reference/cdialogimpl-class.md) em vez disso.  
  
 Manipuladores de eventos e a mensagem podem ser adicionados à sua classe de caixa de diálogo da exibição de classe. Para obter mais informações, consulte [adicionando um manipulador de mensagem ATL](../atl/adding-an-atl-message-handler.md).  
  
## <a name="adding-a-dialog-box-manually"></a>Adicionar uma caixa de diálogo manualmente  
 Implementar uma caixa de diálogo é semelhante à implementação de uma janela. Derivar uma classe do [CAxDialogImpl](../atl/reference/caxdialogimpl-class.md), [CDialogImpl](../atl/reference/cdialogimpl-class.md), ou [CSimpleDialog](../atl/reference/csimpledialog-class.md) e declarar um [mapa de mensagem](../atl/message-maps-atl.md) para lidar com mensagens. No entanto, você também deve especificar uma ID de recurso de modelo de caixa de diálogo em sua classe derivada. A classe deve ter um membro de dados chamado `IDD` para manter esse valor.  
  
> [!NOTE]
>  Quando você cria uma caixa de diálogo usando o Assistente de caixa de diálogo da ATL, o assistente adicionará automaticamente o `IDD` membro como um `enum` tipo.  
  
 `CDialogImpl` permite que você implemente um modal ou uma caixa de diálogo sem janela restrita que hospeda os controles do Windows. `CAxDialogImpl` permite que você implemente um modal ou uma caixa de diálogo sem janela restrita que hospeda os controles ActiveX e o Windows.  
  
 Para criar uma caixa de diálogo modal, crie uma instância do seu `CDialogImpl`-derivados (ou `CAxDialogImpl`-derivado) de classe e, em seguida, chame o [DoModal](../atl/reference/cdialogimpl-class.md#domodal) método. Para fechar a caixa de diálogo modal, chame o [EndDialog](../atl/reference/cdialogimpl-class.md#enddialog) método de um manipulador de mensagens. Para criar uma caixa de diálogo sem janela restrita, chame o [criar](../atl/reference/cdialogimpl-class.md#create) método em vez de `DoModal`. Para destruir uma caixa de diálogo sem janela restrita, chame [DestroyWindow](../atl/reference/cdialogimpl-class.md#destroywindow).  
  
 Recebendo eventos é feito automaticamente em [CAxDialogImpl](../atl/reference/caxdialogimpl-class.md). Implementar manipuladores de mensagens da caixa de diálogo, como você faria manipuladores em um `CWindowImpl`-classe derivada. Se houver um valor de retorno de mensagem específicos, retorná-lo como um `LRESULT`. Retornado `LRESULT` valores são mapeados por ATL para manipulação adequada pelo Gerenciador de caixa de diálogo do Windows. Para obter detalhes, consulte o código-fonte para [CDialogImplBaseT::DialogProc](../atl/reference/cdialogimpl-class.md#dialogproc) em atlwin.h.  
  
## <a name="example"></a>Exemplo  
 A seguinte classe implementa uma caixa de diálogo:  
  
 [!code-cpp[NVC_ATL_Windowing#66](../atl/codesnippet/cpp/implementing-a-dialog-box_1.h)]  
  
## <a name="see-also"></a>Consulte também  
 [Classes de janela](../atl/atl-window-classes.md)

