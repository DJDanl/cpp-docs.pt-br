---
title: "Contêineres de controle ActiveX: Usando controles em um contêiner não da caixa de diálogo | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
dev_langs:
- C++
helpviewer_keywords:
- Create method [MFC], ActiveX controls
- CreateControl method [MFC]
- ActiveX controls [MFC], creating
- ActiveX control containers [MFC], non-dialog containers
- ActiveX control containers [MFC], inserting controls
ms.assetid: 46f195b0-b8ca-4409-8cca-fbfaf2c9ab9f
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: c380d0a525c2f026054ebae1812450c4d4634c1e
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="activex-control-containers-using-controls-in-a-non-dialog-container"></a>Contêineres de controle ActiveX: usando controles em um contêiner que não seja da caixa de diálogo
Em alguns aplicativos, como um SDI ou aplicativo MDI, você deve inserir um controle em uma janela do aplicativo. O **criar** função de membro da classe wrapper, inserida pelo Visual C++, poderá criar uma instância do controle dinamicamente, sem a necessidade de uma caixa de diálogo.  
  
 O **criar** função membro tem os seguintes parâmetros:  
  
 `lpszWindowName`  
 Um ponteiro para o texto a ser exibido na propriedade do controle de texto ou uma legenda (se houver).  
  
 `dwStyle`  
 Estilos de Windows. Para obter uma lista completa, consulte [CWnd::CreateControl](../mfc/reference/cwnd-class.md#createcontrol).  
  
 `rect`  
 Especifica o tamanho e a posição do controle.  
  
 `pParentWnd`  
 Especifica a janela do controle pai, geralmente um `CDialog`. Ele não deve ser **nulo**.  
  
 `nID`  
 Especifica a ID de controle e pode ser usado pelo contêiner para se referir ao controle.  
  
 Um exemplo de como usar essa função para criar dinamicamente um controle ActiveX seria em um modo de exibição de formulário de um aplicativo SDI. Em seguida, você pode criar uma instância do controle no `WM_CREATE` manipulador do aplicativo.  
  
 Neste exemplo, `CMyView` é a classe de exibição principal, `CCirc` é a classe de invólucro e CIRC. H é o cabeçalho (. H) o arquivo da classe wrapper.  
  
 Implementar esse recurso é um processo de quatro etapas.  
  
### <a name="to-dynamically-create-an-activex-control-in-a-non-dialog-window"></a>Para criar um controle ActiveX dinamicamente em uma janela de diálogo não  
  
1.  Inserir CIRC. H em CMYVIEW. H, antes de `CMyView` definição da classe:  
  
     [!code-cpp[NVC_MFC_AxCont#12](../mfc/codesnippet/cpp/activex-control-containers-using-controls-in-a-non-dialog-container_1.h)]  
  
2.  Adicionar uma variável de membro (do tipo `CCirc`) para a seção protegida a `CMyView` localizada em CMYVIEW de definição de classe. H:  
  
     [!code-cpp[NVC_MFC_AxCont#13](../mfc/codesnippet/cpp/activex-control-containers-using-controls-in-a-non-dialog-container_2.h)]  
    [!code-cpp[NVC_MFC_AxCont#14](../mfc/codesnippet/cpp/activex-control-containers-using-controls-in-a-non-dialog-container_3.h)]  
  
3.  Adicionar um `WM_CREATE` manipulador de mensagens para classe `CMyView`.  
  
4.  A função do manipulador, `CMyView::OnCreate`, fazer uma chamada para o controle `Create` função usando o **isso** ponteiro como a janela pai:  
  
     [!code-cpp[NVC_MFC_AxCont#15](../mfc/codesnippet/cpp/activex-control-containers-using-controls-in-a-non-dialog-container_4.cpp)]  
  
5.  Recompile o projeto. Um controle de c será criado dinamicamente sempre que o modo de exibição do aplicativo é criado.  
  
## <a name="see-also"></a>Consulte também  
 [Contêineres de controle ActiveX](../mfc/activex-control-containers.md)

