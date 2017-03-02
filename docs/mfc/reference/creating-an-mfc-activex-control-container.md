---
title: "Criando um contêiner de controle ActiveX MFC | Documentos do Microsoft"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- vc.appwiz.activex.container
dev_langs:
- C++
helpviewer_keywords:
- MFC ActiveX controls [C++], containers
- ActiveX control containers [C++], creating
- containers [C++], creating
- OLE controls [C++], containers
ms.assetid: ec70e137-7c14-4940-bd0e-fd4edcc63ea5
caps.latest.revision: 8
author: mikeblome
ms.author: mblome
manager: ghogen
translation.priority.ht:
- cs-cz
- de-de
- es-es
- fr-fr
- it-it
- ja-jp
- ko-kr
- pl-pl
- pt-br
- ru-ru
- tr-tr
- zh-cn
- zh-tw
translationtype: Machine Translation
ms.sourcegitcommit: 3168772cbb7e8127523bc2fc2da5cc9b4f59beb8
ms.openlocfilehash: 54e2edef0a0b37da1260e9d62c57524e864356be
ms.lasthandoff: 02/25/2017

---
# <a name="creating-an-mfc-activex-control-container"></a>Criando um contêiner de controle ActiveX MFC
Um contêiner de controle ActiveX é um programa pai que fornece o ambiente para um controle ActiveX (anteriormente OLE) para executar. Você pode criar um aplicativo capaz de conter controles ActiveX com ou sem MFC, mas é muito mais fácil de fazer com o MFC.  
  
 Criando um contêiner MFC programa usando o [MFC Application Wizard](../../mfc/reference/mfc-application-wizard.md) permite acessar muitos recursos de automação e controles ActiveX que são implementados pelas classes do MFC e ActiveX. Esses recursos incluem a edição visual, automação, criando arquivos compostos e suportam para controles. As opções de edição visual MFC Application Wizard que oferecerá suporte a seu programa pai incluem a criação de um contêiner, um servidor simplificado, um servidor completo e um programa que é um contêiner e um servidor.  
  
-   **Novo aplicativo do MFC**. Para criar um novo programa MFC que inclui automação, edição visual, composta de arquivos, ou controlar suporte, use o Assistente para aplicativo do MFC e escolha as opções de automação apropriadas.  
  
-   **Aplicativo MFC existente**. Se você estiver adicionando contenção de controle a um aplicativo MFC existente, consulte [contêineres de controle OLE: manualmente habilitando OLE contenção de controle](../../mfc/activex-control-containers-manually-enabling-activex-control-containment.md).  
  
### <a name="to-create-an-activex-container-for-any-of-the-following-types-of-applications"></a>Para criar um contêiner do ActiveX para qualquer um dos seguintes tipos de aplicativos  
  
1.  [Contêineres](../../mfc/containers.md)  
  
2.  [Edição Visual](../../mfc/ole-mfc.md)  
  
3.  [Controles ActiveX MFC](../../mfc/mfc-activex-controls.md)  
  
## <a name="see-also"></a>Consulte também  
 [Tipos de projeto do Visual C++](../../ide/visual-cpp-project-types.md)


