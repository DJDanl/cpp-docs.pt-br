---
title: 'Contêineres de controle ActiveX: usando controles em um contêiner que não seja da caixa de diálogo'
ms.date: 11/04/2016
helpviewer_keywords:
- Create method [MFC], ActiveX controls
- CreateControl method [MFC]
- ActiveX controls [MFC], creating
- ActiveX control containers [MFC], non-dialog containers
- ActiveX control containers [MFC], inserting controls
ms.assetid: 46f195b0-b8ca-4409-8cca-fbfaf2c9ab9f
ms.openlocfilehash: b010c35f32462810cbdb008e5688d4b41254fad1
ms.sourcegitcommit: c21b05042debc97d14875e019ee9d698691ffc0b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 06/09/2020
ms.locfileid: "84620767"
---
# <a name="activex-control-containers-using-controls-in-a-non-dialog-container"></a>Contêineres de controle ActiveX: usando controles em um contêiner que não seja da caixa de diálogo

Em alguns aplicativos, como um aplicativo SDI ou MDI, você desejará inserir um controle em uma janela do aplicativo. A função de membro **Create** da classe wrapper, inserida por Visual C++, pode criar uma instância do controle dinamicamente, sem a necessidade de uma caixa de diálogo.

A função **criar** membro tem os seguintes parâmetros:

*lpszWindowName*<br/>
Um ponteiro para o texto a ser exibido na propriedade Text ou Caption do controle (se houver).

*dwStyle*<br/>
Estilos do Windows. Para obter uma lista completa, consulte [CWnd:: CreateControl](reference/cwnd-class.md#createcontrol).

*Rect*<br/>
Especifica o tamanho e a posição do controle.

*pParentWnd*<br/>
Especifica a janela pai do controle, geralmente um `CDialog` . Ele não deve ser **nulo**.

*nID*<br/>
Especifica a ID de controle e pode ser usada pelo contêiner para fazer referência ao controle.

Um exemplo de como usar essa função para criar dinamicamente um controle ActiveX estaria em uma exibição de formulário de um aplicativo SDI. Em seguida, você pode criar uma instância do controle no `WM_CREATE` manipulador do aplicativo.

Para este exemplo, `CMyView` é a classe de exibição principal, `CCirc` é a classe wrapper e CIRC. H é o cabeçalho (. H) do arquivo da classe wrapper.

A implementação desse recurso é um processo de quatro etapas.

### <a name="to-dynamically-create-an-activex-control-in-a-non-dialog-window"></a>Para criar dinamicamente um controle ActiveX em uma janela que não seja de caixa de diálogo

1. Insira CIRC. H em CMYVIEW. H, logo antes da `CMyView` definição de classe:

   [!code-cpp[NVC_MFC_AxCont#12](codesnippet/cpp/activex-control-containers-using-controls-in-a-non-dialog-container_1.h)]

1. Adicione uma variável de membro (do tipo `CCirc` ) à seção protegida da `CMyView` definição de classe localizada em CMYVIEW. T

   [!code-cpp[NVC_MFC_AxCont#13](codesnippet/cpp/activex-control-containers-using-controls-in-a-non-dialog-container_2.h)]
    [!code-cpp[NVC_MFC_AxCont#14](codesnippet/cpp/activex-control-containers-using-controls-in-a-non-dialog-container_3.h)]

1. Adicione um `WM_CREATE` manipulador de mensagens à classe `CMyView` .

1. Na função de manipulador, `CMyView::OnCreate` , faça uma chamada para a função do controle `Create` usando o **this** ponteiro como a janela pai:

   [!code-cpp[NVC_MFC_AxCont#15](codesnippet/cpp/activex-control-containers-using-controls-in-a-non-dialog-container_4.cpp)]

1. Recompile o projeto. Um controle Circ será criado dinamicamente sempre que a exibição do aplicativo for criada.

## <a name="see-also"></a>Consulte também

[Contêineres de controle ActiveX](activex-control-containers.md)
