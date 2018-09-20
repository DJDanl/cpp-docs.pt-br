---
title: Criando um contêiner de controle ActiveX do MFC | Microsoft Docs
ms.custom: ''
ms.date: 09/12/2018
ms.technology:
- cpp-mfc
ms.topic: reference
f1_keywords:
- vc.appwiz.activex.container
dev_langs:
- C++
helpviewer_keywords:
- MFC ActiveX controls [MFC], containers
- ActiveX control containers [MFC], creating
- containers [MFC], creating
- OLE controls [MFC], containers
ms.assetid: ec70e137-7c14-4940-bd0e-fd4edcc63ea5
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 37119934a70f8a68d32ed83699fa6deb012d8879
ms.sourcegitcommit: 799f9b976623a375203ad8b2ad5147bd6a2212f0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/19/2018
ms.locfileid: "46404430"
---
# <a name="creating-an-mfc-activex-control-container"></a>Criando um contêiner de controle ActiveX MFC

Um contêiner de controle ActiveX é um programa de pai que fornece o ambiente para um controle ActiveX (anteriormente conhecido como OLE) para executar. Você pode criar um aplicativo capaz de conter controles ActiveX com ou sem MFC, mas é mais fácil fazer com o MFC.

>[!IMPORTANT]
> ActiveX é uma tecnologia herdada que não deve ser usada para novos desenvolvimentos. Para obter mais informações sobre tecnologias modernas que substituem as ActiveX, consulte [controles ActiveX](../activex-controls.md).

Criar um programa de contêiner MFC usando o [Assistente de aplicativo MFC](../../mfc/reference/mfc-application-wizard.md) permite que você acesse os muitos recursos de automação e controles ActiveX que são implementados pelas classes MFC e ActiveX. Esses recursos incluem a edição visual, automação, criando arquivos compostos e suportam para controles. As opções de edição visual Assistente de aplicativo MFC que seu programa pai dará suporte incluem a criação de um contêiner, um minisservidor, um servidor completo e um programa que é um contêiner e um servidor.

- **Novo aplicativo do MFC**. Para criar um novo programa MFC que inclui automação, edição visual, composta de arquivos, ou controlar o suporte, use o Assistente de aplicativo do MFC e escolha as opções de automação apropriadas.

- **Aplicativo MFC existente**. Se você estiver adicionando contenção de controle a um aplicativo MFC existente, consulte [contêineres de controle OLE: manualmente habilitando OLE contenção de controle](../../mfc/activex-control-containers-manually-enabling-activex-control-containment.md).

### <a name="to-create-an-activex-container-for-any-of-the-following-types-of-applications"></a>Para criar um contêiner de ActiveX para qualquer um dos seguintes tipos de aplicativos

1. [Contêineres](../../mfc/containers.md)

1. [Edição Visual](../../mfc/ole-mfc.md)

1. [Controles ActiveX MFC](../../mfc/mfc-activex-controls.md)

## <a name="see-also"></a>Consulte também

[Tipos de projeto do Visual C++](../../ide/visual-cpp-project-types.md)

