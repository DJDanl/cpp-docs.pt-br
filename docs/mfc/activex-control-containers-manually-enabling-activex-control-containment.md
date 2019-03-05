---
title: 'Contêineres de controle ActiveX: Habilitando contenção de controle ActiveX manualmente'
ms.date: 09/12/2018
helpviewer_keywords:
- AfxEnableControlContainer method [MFC]
- ActiveX control containers [MFC], enabling
- ActiveX controls [MFC], enabling containers
ms.assetid: 833bcde9-c9ad-4709-ad12-2fc2150fb6a5
ms.openlocfilehash: 80ca25192f3dbda711b0398917cfa68571cd2c55
ms.sourcegitcommit: c3093251193944840e3d0a068ecc30e6449624ba
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/04/2019
ms.locfileid: "57302710"
---
# <a name="activex-control-containers-manually-enabling-activex-control-containment"></a>Contêineres de controle ActiveX: Habilitando contenção de controle ActiveX manualmente

Se você não tiver habilitado o suporte a controles ActiveX quando você usou o Assistente de aplicativo do MFC para gerar seu aplicativo, você precisará adicionar esse suporte manualmente. Este artigo descreve o processo para adicionar manualmente a contenção de controle ActiveX a um aplicativo de contêiner OLE existente. Se você souber de antemão que você deseja que suporte a controles ActiveX em seu contêiner OLE, consulte o artigo [criando um contêiner de controle ActiveX MFC](../mfc/reference/creating-an-mfc-activex-control-container.md).

>[!IMPORTANT]
> ActiveX é uma tecnologia herdada que não deve ser usada para novos desenvolvimentos. Para obter mais informações sobre tecnologias modernas que substituem o ActiveX, consulte [controles ActiveX](activex-controls.md).

> [!NOTE]
>  Este artigo usa um baseado em diálogo ActiveX contêiner projeto de controle de contêiner e um controle inserido chamado c como exemplos nos procedimentos e código de chamada.

Para dar suporte a controles ActiveX, você deve adicionar uma linha de código para os dois arquivos do seu projeto.

- Modificar a caixa de diálogo principal `InitInstance` função (localizada no CONTÊINER. CPP) pelo Assistente de aplicativo MFC fazendo uma chamada para [AfxEnableControlContainer](reference/ole-initialization.md#afxenablecontrolcontainer), conforme mostrado no exemplo a seguir:

   [!code-cpp[NVC_MFCOleContainer#34](../mfc/codesnippet/cpp/activex-control-containers-manually-enabling-activex-control-containment_1.cpp)]
    [!code-cpp[NVC_MFCOleContainer#35](../mfc/codesnippet/cpp/activex-control-containers-manually-enabling-activex-control-containment_2.cpp)]

- Adicione o seguinte ao STDAFX seu projeto. Arquivo de cabeçalho H:

   [!code-cpp[NVC_MFCOleContainer#36](../mfc/codesnippet/cpp/activex-control-containers-manually-enabling-activex-control-containment_3.h)]

Depois de concluir essas etapas, recompile o projeto clicando **compilar** sobre o **compilar** menu.

## <a name="see-also"></a>Consulte também

[Contêineres de controle ActiveX](../mfc/activex-control-containers.md)
