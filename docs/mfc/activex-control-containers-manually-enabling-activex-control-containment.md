---
title: 'Contêineres de controle ActiveX: habilitando contenção de controle ActiveX manualmente'
ms.date: 09/12/2018
helpviewer_keywords:
- AfxEnableControlContainer method [MFC]
- ActiveX control containers [MFC], enabling
- ActiveX controls [MFC], enabling containers
ms.assetid: 833bcde9-c9ad-4709-ad12-2fc2150fb6a5
ms.openlocfilehash: 94ad6e8356b5dab54ae97dbdd90812039d1425c9
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81322060"
---
# <a name="activex-control-containers-manually-enabling-activex-control-containment"></a>Contêineres de controle ActiveX: habilitando contenção de controle ActiveX manualmente

Se você não habilitou o suporte ao controle ActiveX quando usou o MFC Application Wizard para gerar seu aplicativo, você terá que adicionar esse suporte manualmente. Este artigo descreve o processo para adicionar manualmente a contenção de controle ActiveX a uma aplicação de contêiner OLE existente. Se você sabe com antecedência que deseja suporte ao controle ActiveX em seu contêiner OLE, consulte o artigo [Criando um contêiner de controle MFC ActiveX](../mfc/reference/creating-an-mfc-activex-control-container.md).

>[!IMPORTANT]
> ActiveX é uma tecnologia herdada que não deve ser usada para novos desenvolvimentos. Para obter mais informações sobre tecnologias modernas que substituim o ActiveX, consulte [ActiveX Controls](activex-controls.md).

> [!NOTE]
> Este artigo usa um projeto de contêiner de controle ActiveX baseado em diálogo chamado Container e um controle incorporado chamado Circ como exemplos nos procedimentos e código.

Para suportar controles ActiveX, você deve adicionar uma linha de código a dois arquivos do seu projeto.

- Modifique a função `InitInstance` da caixa de diálogo principal (encontrada no CONTAINER. CPP) pelo Assistente de Aplicativo MFC fazendo uma chamada para [AfxEnableControlContainer,](reference/ole-initialization.md#afxenablecontrolcontainer)como no exemplo a seguir:

   [!code-cpp[NVC_MFCOleContainer#34](../mfc/codesnippet/cpp/activex-control-containers-manually-enabling-activex-control-containment_1.cpp)]
    [!code-cpp[NVC_MFCOleContainer#35](../mfc/codesnippet/cpp/activex-control-containers-manually-enabling-activex-control-containment_2.cpp)]

- Adicione o seguinte ao STDAFX do seu projeto. Arquivo de cabeçalho H:

   [!code-cpp[NVC_MFCOleContainer#36](../mfc/codesnippet/cpp/activex-control-containers-manually-enabling-activex-control-containment_3.h)]

Depois de concluir essas etapas, reconstrua seu projeto clicando em **Construir** no menu **Construir.**

## <a name="see-also"></a>Confira também

[Contêineres de controle ActiveX](../mfc/activex-control-containers.md)
