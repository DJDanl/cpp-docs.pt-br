---
title: "Criando um contêiner de controle ActiveX MFC | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords: vc.appwiz.activex.container
dev_langs: C++
helpviewer_keywords:
- MFC ActiveX controls [MFC], containers
- ActiveX control containers [MFC], creating
- containers [MFC], creating
- OLE controls [MFC], containers
ms.assetid: ec70e137-7c14-4940-bd0e-fd4edcc63ea5
caps.latest.revision: "8"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 2054a11365cc6f9db7a5608f0b056d0d85ff117d
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="creating-an-mfc-activex-control-container"></a>Criando um contêiner de controle ActiveX MFC
Um contêiner de controle ActiveX é um programa de pai que fornece o ambiente para um controle ActiveX (anteriormente OLE) para executar. Você pode criar um aplicativo capaz de conter controles ActiveX com ou sem MFC, mas é muito mais fácil de fazer com MFC.  
  
 Criar um contêiner MFC programa usando o [Assistente de aplicativo MFC](../../mfc/reference/mfc-application-wizard.md) permite que você acesse os muitos recursos de automação e controles ActiveX que são implementados pelas classes MFC e ActiveX. Esses recursos incluem a edição visual, automação, criando arquivos compostos e suportam para controles. As opções de edição visual Assistente de aplicativo MFC que seu programa pai dará suporte incluem a criação de um contêiner, um servidor simplificado, um servidor completo e um programa que é um recipiente e um servidor.  
  
-   **Novo aplicativo do MFC**. Para criar um novo programa MFC que inclui a automação, edição visual, composta de arquivos, ou suporte de controle, use o Assistente de aplicativo MFC e escolha as opções apropriadas de automação.  
  
-   **Aplicativo MFC existente**. Se você estiver adicionando contenção de controle para um aplicativo MFC existente, consulte [contêineres de controle OLE: manualmente habilitando OLE contenção de controle](../../mfc/activex-control-containers-manually-enabling-activex-control-containment.md).  
  
### <a name="to-create-an-activex-container-for-any-of-the-following-types-of-applications"></a>Para criar um contêiner de ActiveX para qualquer um dos seguintes tipos de aplicativos  
  
1.  [Contêineres](../../mfc/containers.md)  
  
2.  [Edição Visual](../../mfc/ole-mfc.md)  
  
3.  [Controles ActiveX MFC](../../mfc/mfc-activex-controls.md)  
  
## <a name="see-also"></a>Consulte também  
 [Tipos de projeto do Visual C++](../../ide/visual-cpp-project-types.md)

