---
title: 'Controles ActiveX MFC: Criando um servidor de automação | Microsoft Docs'
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- Automation servers [MFC], MFC ActiveX controls
- ActiveX controls [MFC], Automation server
- MFC ActiveX controls [MFC], Automation server
ms.assetid: e0c24ed2-d61c-49ad-a4fa-4e1098d1d39b
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 617d84b8603467da74b21be8c2bfb2e6cb418f7b
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="mfc-activex-controls-creating-an-automation-server"></a>Controles ActiveX MFC: criando um servidor de automação
Você pode desenvolver um controle ActiveX MFC como um servidor de automação com a finalidade programaticamente inserindo controle em outro aplicativo e chamar os métodos no controle do aplicativo. Um controle como ainda estaria disponível para ser hospedado em um contêiner de controle ActiveX.  
  
### <a name="to-create-a-control-as-an-automation-server"></a>Para criar um controle como um servidor de automação  
  
1.  [Criar](../mfc/reference/mfc-activex-control-wizard.md) o controle.  
  
2.  [Adicionar métodos](../mfc/mfc-activex-controls-methods.md).  
  
3.  Substituir [IsInvokeAllowed](../mfc/reference/colecontrol-class.md#isinvokeallowed). Para obter mais informações, consulte o artigo da Base de dados de Conhecimento Q146120.  
  
4.  Crie o controle.  
  
### <a name="to-programmatically-access-the-methods-in-an-automation-server"></a>Para acessar programaticamente os métodos em um servidor de automação  
  
1.  Criar um aplicativo, por exemplo, uma [exe do MFC](../mfc/reference/mfc-application-wizard.md).  
  
2.  No início de `InitInstance` função, adicione a seguinte linha:  
  
     [!code-cpp[NVC_MFC_AxCont#17](../mfc/codesnippet/cpp/mfc-activex-controls-creating-an-automation-server_1.cpp)]  
  
3.  No modo de exibição de classe, clique com botão direito no nó do projeto e selecione **Adicionar classe de typelib** para importar a biblioteca de tipos.  
  
     Isso adicionará arquivos com o. h de extensões de nome de arquivo e. cpp para o projeto.  
  
4.  No arquivo de cabeçalho da classe onde você chamará um ou mais métodos no controle ActiveX, adicione a seguinte linha: `#include filename.h`, onde o nome de arquivo é o nome do arquivo de cabeçalho que foi criado quando você importou a biblioteca de tipos.  
  
5.  Na função em que uma chamada será feita a um método no controle ActiveX, adicione o código que cria um objeto da classe de wrapper do controle e criar o objeto ActiveX. Por exemplo, o seguinte código MFC instancia um `CCirc` controle, obtém a propriedade de legenda e exibe o resultado quando o botão Okey é clicado em uma caixa de diálogo:  
  
     [!code-cpp[NVC_MFC_AxCont#18](../mfc/codesnippet/cpp/mfc-activex-controls-creating-an-automation-server_2.cpp)]  
  
 Se você adicionar métodos para o controle ActiveX depois que você pode usá-lo em um aplicativo, você pode começar a usar a versão mais recente do controle no aplicativo, excluindo os arquivos que foram criados quando você importou a biblioteca de tipos. Em seguida, importe novamente a biblioteca de tipos.  
  
## <a name="see-also"></a>Consulte também  
 [Controles ActiveX do MFC](../mfc/mfc-activex-controls.md)

