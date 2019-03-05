---
title: 'Controles ActiveX MFC: Criando um servidor de automação'
ms.date: 11/04/2016
helpviewer_keywords:
- Automation servers [MFC], MFC ActiveX controls
- ActiveX controls [MFC], Automation server
- MFC ActiveX controls [MFC], Automation server
ms.assetid: e0c24ed2-d61c-49ad-a4fa-4e1098d1d39b
ms.openlocfilehash: 01f0162e124c5c49d45ce4a90f5243c88b09b5a0
ms.sourcegitcommit: c3093251193944840e3d0a068ecc30e6449624ba
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/04/2019
ms.locfileid: "57303723"
---
# <a name="mfc-activex-controls-creating-an-automation-server"></a>Controles ActiveX MFC: Criando um servidor de automação

Você pode desenvolver um controle ActiveX do MFC como um servidor de automação para fins de inserir o controle em outro aplicativo de forma programática e chamar métodos no controle do aplicativo. Um controle desse tipo ainda estaria disponível para ser hospedado em um contêiner de controle ActiveX.

### <a name="to-create-a-control-as-an-automation-server"></a>Para criar um controle como um servidor de automação

1. [Criar](../mfc/reference/mfc-activex-control-wizard.md) o controle.

1. [Adicione métodos](../mfc/mfc-activex-controls-methods.md).

1. Substituir [IsInvokeAllowed](../mfc/reference/colecontrol-class.md#isinvokeallowed).

1. Compile o controle.

### <a name="to-programmatically-access-the-methods-in-an-automation-server"></a>Para acessar programaticamente os métodos em um servidor de automação

1. Criar um aplicativo, por exemplo, uma [MFC exe](../mfc/reference/mfc-application-wizard.md).

1. No início do `InitInstance` de função, adicione a seguinte linha:

   [!code-cpp[NVC_MFC_AxCont#17](../mfc/codesnippet/cpp/mfc-activex-controls-creating-an-automation-server_1.cpp)]

1. No modo de exibição de classe, clique com botão direito no nó do projeto e selecione **Adicionar classe de typelib** para importar a biblioteca de tipos.

   Isso adicionará arquivos com o. cpp e. h de extensões de nome de arquivo ao projeto.

1. No arquivo de cabeçalho da classe em que você chamará um ou mais métodos no controle ActiveX, adicione a seguinte linha: `#include filename.h`, onde o nome do arquivo é o nome do arquivo de cabeçalho que foi criado quando você importou a biblioteca de tipos.

1. Na função em que uma chamada será feita a um método no controle ActiveX, adicione o código que cria um objeto da classe de wrapper do controle e crie o objeto ActiveX. Por exemplo, o código MFC a seguir cria uma instância de um `CCirc` controle, obtém a propriedade Caption e exibe o resultado quando o botão Okey é clicado em uma caixa de diálogo:

   [!code-cpp[NVC_MFC_AxCont#18](../mfc/codesnippet/cpp/mfc-activex-controls-creating-an-automation-server_2.cpp)]

Se você adicionar métodos para o controle ActiveX depois que você pode usá-lo em um aplicativo, você pode começar a usar a versão mais recente do controle no aplicativo, excluindo os arquivos que foram criados quando você importou a biblioteca de tipos. Em seguida, importe novamente a biblioteca de tipos.

## <a name="see-also"></a>Consulte também

[Controles ActiveX do MFC](../mfc/mfc-activex-controls.md)
