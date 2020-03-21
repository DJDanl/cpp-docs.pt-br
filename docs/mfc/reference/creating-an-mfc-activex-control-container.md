---
title: Criando um contêiner de controle ActiveX MFC
ms.date: 09/12/2018
f1_keywords:
- vc.appwiz.activex.container
helpviewer_keywords:
- MFC ActiveX controls [MFC], containers
- ActiveX control containers [MFC], creating
- containers [MFC], creating
- OLE controls [MFC], containers
ms.assetid: ec70e137-7c14-4940-bd0e-fd4edcc63ea5
ms.openlocfilehash: 27f229a23595d4842a77409a3cedc7a57aa43e6c
ms.sourcegitcommit: 8e285a766523e653aeeb34d412dc6f615ef7b17b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/21/2020
ms.locfileid: "80079434"
---
# <a name="creating-an-mfc-activex-control-container"></a>Criando um contêiner de controle ActiveX MFC

Um contêiner de controle ActiveX é um programa pai que fornece ao ambiente um controle ActiveX (anteriormente conhecido como OLE) a ser executado. Você pode criar um aplicativo capaz de conter controles ActiveX com ou sem MFC, mas é muito mais fácil de fazer com o MFC.

>[!IMPORTANT]
> O ActiveX é uma tecnologia herdada que não deve ser usada para novos desenvolvimentos. Para obter mais informações sobre as tecnologias modernas que substituem o ActiveX, consulte [controles ActiveX](../activex-controls.md).

A criação de um programa de contêiner do MFC usando o [Assistente de aplicativo MFC](../../mfc/reference/mfc-application-wizard.md) permite que você acesse vários recursos dos controles ActiveX e da automação que são implementados pelas classes MFC e ActiveX. Esses recursos incluem edição visual, automação, criação de arquivos compostos e suporte para controles. As opções de edição visual do assistente de aplicativo MFC para as quais seu programa pai oferecerá suporte incluem a criação de um contêiner, um mini-servidor, um servidor completo e um programa que seja um contêiner e um servidor.

- **Novo aplicativo MFC**. Para criar um novo programa MFC que inclui automação, edição visual, arquivos compostos ou suporte a controle, use o assistente de aplicativo MFC e escolha as opções de automação apropriadas.

- **Aplicativo MFC existente**. Se você estiver adicionando a contenção de controle a um aplicativo MFC existente, consulte [contêineres de controle OLE: habilitando manualmente o controle OLE confinamento](../../mfc/activex-control-containers-manually-enabling-activex-control-containment.md).

### <a name="to-create-an-activex-container-for-any-of-the-following-types-of-applications"></a>Para criar um contêiner ActiveX para qualquer um dos seguintes tipos de aplicativos

1. [Contêineres](../../mfc/containers.md)

1. [Edição Visual](../../mfc/ole-mfc.md)

1. [Controles ActiveX do MFC](../../mfc/mfc-activex-controls.md)

## <a name="see-also"></a>Confira também

[Tipos de projeto do C++ no Visual Studio](../../build/reference/visual-cpp-project-types.md)
