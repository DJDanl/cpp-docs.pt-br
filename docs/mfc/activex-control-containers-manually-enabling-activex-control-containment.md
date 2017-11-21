---
title: "Contêineres de controle ActiveX: Habilitando contenção de controle ActiveX manualmente | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
dev_langs: C++
helpviewer_keywords:
- AfxEnableControlContainer method [MFC]
- ActiveX control containers [MFC], enabling
- ActiveX controls [MFC], enabling containers
ms.assetid: 833bcde9-c9ad-4709-ad12-2fc2150fb6a5
caps.latest.revision: "10"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.openlocfilehash: 625a4445aebcb03cce7068c216782326619e3c6b
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
---
# <a name="activex-control-containers-manually-enabling-activex-control-containment"></a>Contêineres de controle ActiveX: habilitando contenção de controle ActiveX manualmente
Se você não habilitou o suporte de controle ActiveX quando você usou o Assistente de aplicativo do MFC para gerar seu aplicativo, você precisará adicionar este suporte manualmente. Este artigo descreve o processo para adicionar manualmente a contenção de controle ActiveX para um aplicativo de contêiner OLE existente. Se você souber de antemão que você deseja que o suporte de controle ActiveX em seu contêiner OLE, consulte o artigo [criando um contêiner de controle ActiveX MFC](../mfc/reference/creating-an-mfc-activex-control-container.md).  
  
> [!NOTE]
>  Este artigo usa um baseado na caixa de diálogo ActiveX controle recipiente projeto chamado recipiente e um controle inserido chamado c como exemplos de procedimentos e código.  
  
 Para oferecer suporte a controles ActiveX, você deve adicionar uma linha de código a dois dos arquivos do projeto.  
  
-   Modificar a caixa de diálogo principal `InitInstance` função (localizada no CONTÊINER. CPP) pelo Assistente de aplicativo MFC fazendo uma chamada para [AfxEnableControlContainer](reference/ole-initialization.md#afxenablecontrolcontainer), conforme mostrado no exemplo a seguir:  
  
     [!code-cpp[NVC_MFCOleContainer#34](../mfc/codesnippet/cpp/activex-control-containers-manually-enabling-activex-control-containment_1.cpp)]  
    [!code-cpp[NVC_MFCOleContainer#35](../mfc/codesnippet/cpp/activex-control-containers-manually-enabling-activex-control-containment_2.cpp)]  
  
-   Adicione o seguinte ao STDAFX do seu projeto. Arquivo de cabeçalho H:  
  
     [!code-cpp[NVC_MFCOleContainer#36](../mfc/codesnippet/cpp/activex-control-containers-manually-enabling-activex-control-containment_3.h)]  
  
 Depois de concluir essas etapas, recrie seu projeto clicando **criar** no **criar** menu.  
  
## <a name="see-also"></a>Consulte também  
 [Contêineres de controle ActiveX](../mfc/activex-control-containers.md)

