---
title: 'Contêineres de controle ActiveX: habilitando contenção de controle ActiveX manualmente'
ms.date: 09/12/2018
helpviewer_keywords:
- AfxEnableControlContainer method [MFC]
- ActiveX control containers [MFC], enabling
- ActiveX controls [MFC], enabling containers
ms.assetid: 833bcde9-c9ad-4709-ad12-2fc2150fb6a5
ms.openlocfilehash: a8092a77020695163ce4fbacf7eeea2650ae9f86
ms.sourcegitcommit: c21b05042debc97d14875e019ee9d698691ffc0b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 06/09/2020
ms.locfileid: "84625111"
---
# <a name="activex-control-containers-manually-enabling-activex-control-containment"></a>Contêineres de controle ActiveX: habilitando contenção de controle ActiveX manualmente

Se você não habilitou o suporte ao controle ActiveX quando usou o assistente de aplicativo MFC para gerar seu aplicativo, precisará adicionar esse suporte manualmente. Este artigo descreve o processo de adição manual da contenção do controle ActiveX a um aplicativo de contêiner OLE existente. Se você souber antecipadamente que deseja o suporte ao controle ActiveX em seu contêiner OLE, consulte o artigo [criando um contêiner de controle ActiveX do MFC](reference/creating-an-mfc-activex-control-container.md).

>[!IMPORTANT]
> O ActiveX é uma tecnologia herdada que não deve ser usada para novos desenvolvimentos. Para obter mais informações sobre as tecnologias modernas que substituem o ActiveX, consulte [controles ActiveX](activex-controls.md).

> [!NOTE]
> Este artigo usa um projeto de contêiner de controle ActiveX baseado em caixa de diálogo chamado contêiner e um controle inserido chamado CIRC como exemplos nos procedimentos e no código.

Para dar suporte a controles ActiveX, você deve adicionar uma linha de código a dois dos arquivos do seu projeto.

- Modifique a função da caixa de diálogo principal `InitInstance` (encontrada no contêiner. CPP) pelo assistente de aplicativo do MFC fazendo uma chamada para [AfxEnableControlContainer](reference/ole-initialization.md#afxenablecontrolcontainer), como no exemplo a seguir:

   [!code-cpp[NVC_MFCOleContainer#34](codesnippet/cpp/activex-control-containers-manually-enabling-activex-control-containment_1.cpp)]
    [!code-cpp[NVC_MFCOleContainer#35](codesnippet/cpp/activex-control-containers-manually-enabling-activex-control-containment_2.cpp)]

- Adicione o seguinte ao STDAFX do seu projeto. Arquivo de cabeçalho H:

   [!code-cpp[NVC_MFCOleContainer#36](codesnippet/cpp/activex-control-containers-manually-enabling-activex-control-containment_3.h)]

Depois de concluir essas etapas, recompile o projeto clicando em **criar** no menu **Compilar** .

## <a name="see-also"></a>Consulte também

[Contêineres de controle ActiveX](activex-control-containers.md)
