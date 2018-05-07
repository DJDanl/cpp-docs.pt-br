---
title: MFC COM | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: conceptual
f1_keywords:
- MFC COM (MFC)
dev_langs:
- C++
helpviewer_keywords:
- MFC, COM support
- MFC ActiveX controls [MFC], COM support in MFC
- MFC COM [MFC]
- ActiveX controls [MFC], COM object model
- Active technology [MFC]
- COM [MFC], MFC support
ms.assetid: 7646bdcb-3a06-4ed5-9386-9b00f3979dcb
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 8257631e46a1ebcf5c882d9f87c628c04ccc84f5
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="mfc-com"></a>MFC COM
Um subconjunto de MFC foi projetado para suporte de COM, enquanto a maioria de biblioteca de modelo ativa (ATL) foi projetado para programação COM. Esta seção de tópicos descreve o suporte do MFC para COM.  
  
 Active tecnologias (como ActiveX controles, contenção de documentos ativos, OLE e assim por diante) usam o modelo de objeto de componente (COM) para habilitar os componentes de software interajam uns com os outros em um ambiente de rede, independentemente do idioma com o qual eles foram criado. Tecnologias de ativas podem ser usadas para criar aplicativos que são executados na área de trabalho ou na Internet. Para obter mais informações, consulte [Introdução ao COM](../atl/introduction-to-com.md) ou [o modelo de objeto de componente](http://msdn.microsoft.com/library/windows/desktop/ms694363).  
  
 Tecnologias Active incluem tecnologias de cliente e servidor, incluindo o seguinte:  
  
-   [Contenção de documentos ativos](../mfc/active-document-containment.md), suporte em versões MFC 4.2 e posterior, permite que os usuários exibam [documentos ativos](../mfc/active-documents.md) (como arquivos do Microsoft Excel ou Word) e ativar toda a interface de nativo do documento aplicativo em toda a área cliente de um [contêiner de documento ativo](../mfc/active-document-containers.md) como o Microsoft Office Binder ou o Microsoft Internet Explorer. Os contêineres de atuam como clientes, enquanto os documentos são fornecidos pelo [servidores de documentos ativos](../mfc/active-document-servers.md). Para obter mais informações sobre o uso de documentos ativos em aplicativos da Internet, consulte: [documentos ativos na Internet](../mfc/active-documents-on-the-internet.md).  
  
-   Controles ActiveX são objetos interativos que podem ser usados em contêineres como um site da Web. Para obter mais informações sobre os controles ActiveX, consulte:  
  
    -   [Controles ActiveX do MFC](../mfc/mfc-activex-controls.md)  
  
    -   [Controles ActiveX na Internet](../mfc/activex-controls-on-the-internet.md)  
  
    -   [Visão geral: Internet](../mfc/mfc-internet-programming-basics.md)  
  
    -   [Atualizar um controle ActiveX existente a ser usado na Internet](../mfc/upgrading-an-existing-activex-control.md)  
  
    -   [Depuração de um controle ActiveX](/visualstudio/debugger/how-to-debug-an-activex-control)  
  
-   Script ativo controla o comportamento integrado de um ou mais controles ActiveX em um navegador ou servidor. Para obter mais informações sobre scripts ativos, consulte [tecnologia ativa na Internet](../mfc/active-technology-on-the-internet.md).  
  
-   [Automação](../mfc/automation.md) (anteriormente conhecido como automação OLE) permite que um aplicativo para manipular objetos implementados em outro aplicativo ou "exponha" objetos de forma podem ser manipulados.  
  
     O objeto automatizado pode ser local ou remoto (em outro computador acessível em uma rede). Automação está disponível para objetos COM e OLE.  
  
-   Esta seção também fornece informações sobre como escrever componentes COM usando MFC, por exemplo, em [pontos de Conexão](../mfc/connection-points.md).  
  
 Para uma discussão sobre o que ainda será chamado OLE versus o que é chamado agora de tecnologia ativa, consulte os tópicos sobre [OLE](../mfc/ole-in-mfc.md).  
  
 Além disso, consulte o artigo da Base de dados de Conhecimento Q248019: como: evitar servidor ocupado diálogo caixa do que aparecem durante um COM operação demorada.  
  
## <a name="in-this-section"></a>Nesta seção  
 [Contenção de documentos ativos](../mfc/active-document-containment.md)  
  
 [Automação](../mfc/automation.md)  
  
 [Pontos de conexão](../mfc/connection-points.md)  
  
 [Controles ActiveX do MFC](../mfc/mfc-activex-controls.md)  
  
## <a name="see-also"></a>Consulte também  
 [Conceitos](../mfc/mfc-concepts.md)

