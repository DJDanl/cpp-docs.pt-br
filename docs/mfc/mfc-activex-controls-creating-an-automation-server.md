---
title: 'Controles ActiveX MFC: criando um servidor de automação'
ms.date: 11/04/2016
helpviewer_keywords:
- Automation servers [MFC], MFC ActiveX controls
- ActiveX controls [MFC], Automation server
- MFC ActiveX controls [MFC], Automation server
ms.assetid: e0c24ed2-d61c-49ad-a4fa-4e1098d1d39b
ms.openlocfilehash: f2c941e43e810845560b4c35c558ec70248c21ed
ms.sourcegitcommit: c21b05042debc97d14875e019ee9d698691ffc0b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 06/09/2020
ms.locfileid: "84622376"
---
# <a name="mfc-activex-controls-creating-an-automation-server"></a>Controles ActiveX MFC: criando um servidor de automação

Você pode desenvolver um controle ActiveX do MFC como um servidor de automação para a finalidade de incorporar programaticamente esse controle em outro aplicativo e chamar métodos no controle do aplicativo. Esse controle ainda estaria disponível para ser hospedado em um contêiner de controle ActiveX.

### <a name="to-create-a-control-as-an-automation-server"></a>Para criar um controle como um servidor de automação

1. [Crie](reference/mfc-activex-control-wizard.md) o controle.

1. [Adicione métodos](mfc-activex-controls-methods.md).

1. Substitua [IsInvokeAllowed](reference/colecontrol-class.md#isinvokeallowed).

1. Compile o controle.

### <a name="to-programmatically-access-the-methods-in-an-automation-server"></a>Para acessar programaticamente os métodos em um servidor de automação

1. Crie um aplicativo, por exemplo, um [exe do MFC](reference/mfc-application-wizard.md).

1. No início da `InitInstance` função, adicione a seguinte linha:

   [!code-cpp[NVC_MFC_AxCont#17](codesnippet/cpp/mfc-activex-controls-creating-an-automation-server_1.cpp)]

1. Em Modo de Exibição de Classe, clique com o botão direito do mouse no nó do projeto e selecione **Adicionar classe de typelib** para importar a biblioteca de tipos.

   Isso adicionará arquivos com as extensões de nome de arquivo. h e. cpp ao projeto.

1. No arquivo de cabeçalho da classe em que você chamará um ou mais métodos no controle ActiveX, adicione a seguinte linha: `#include filename.h` , em que nome do arquivo é o nome do arquivo de cabeçalho que foi criado quando você importou a biblioteca de tipos.

1. Na função em que uma chamada será feita a um método no controle ActiveX, adicione o código que cria um objeto da classe wrapper do controle e crie o objeto ActiveX. Por exemplo, o código MFC a seguir instancia um `CCirc` controle, obtém a propriedade Caption e exibe o resultado quando o botão OK é clicado em uma caixa de diálogo:

   [!code-cpp[NVC_MFC_AxCont#18](codesnippet/cpp/mfc-activex-controls-creating-an-automation-server_2.cpp)]

Se você adicionar métodos ao controle ActiveX depois de usá-lo em um aplicativo, poderá começar a usar a versão mais recente do controle no aplicativo excluindo os arquivos que foram criados quando você importou a biblioteca de tipos. Em seguida, importe a biblioteca de tipos novamente.

## <a name="see-also"></a>Consulte também

[Controles ActiveX do MFC](mfc-activex-controls.md)
