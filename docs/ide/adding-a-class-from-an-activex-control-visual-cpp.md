---
title: Adicionando uma classe a partir de um controle ActiveX (Visual C++) | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-ide
ms.tgt_pltfrm: 
ms.topic: article
dev_langs:
- C++
helpviewer_keywords:
- ActiveX controls [C++], adding classes
- classes [C++], creating
ms.assetid: 729fcb37-54b8-44d5-9b4e-50bb16e0eea4
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: f059396c91ddb51247347d10e6c8f79a6c95522f
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="adding-a-class-from-an-activex-control-visual-c"></a>Adicionando uma classe a partir de um controle ActiveX (Visual C++)
Use este assistente para criar uma classe do MFC de uma interface em um controle ActiveX disponível. Você pode adicionar uma classe do MFC para um [aplicativo MFC](../mfc/reference/creating-an-mfc-application.md), uma [DLL MFC](../mfc/reference/creating-an-mfc-dll-project.md), ou um [controle ActiveX MFC](../mfc/reference/creating-an-mfc-activex-control.md).  
  
> [!NOTE]
>  Você não precisa criar seu projeto MFC com automação habilitada para adicionar uma classe a partir de um controle ActiveX.  
  
 Um controle ActiveX é um componente de software reutilizáveis com base no modelo COM (Component Object) que oferece suporte a uma ampla variedade de funcionalidades OLE e podem ser personalizadas para atender às várias necessidades de software. Controles ActiveX são projetados para uso em contêineres de controle ActiveX comuns e na Internet em páginas da Web.  
  
### <a name="to-add-an-mfc-class-from-an-activex-control"></a>Para adicionar uma classe do MFC de um controle ActiveX  
  
1.  No **Solution Explorer** ou [exibição de classe](http://msdn.microsoft.com/en-us/8d7430a9-3e33-454c-a9e1-a85e3d2db925), clique no nome do projeto ao qual você deseja adicionar a classe de controle ActiveX.  
  
2.  No menu de atalho, clique em **adicionar**e, em seguida, clique em **Adicionar classe**.  
  
3.  No [Adicionar classe](../ide/add-class-dialog-box.md) caixa de diálogo, no painel modelos, clique em **classe do controle ActiveX MFC**e, em seguida, clique em **abrir** para exibir o [Adicionar classe do ActiveX Assistente de controle](../ide/add-class-from-activex-control-wizard.md).  
  
 No assistente, você pode adicionar mais de uma interface em um controle ActiveX. Da mesma forma, você pode criar classes de mais de um controle ActiveX em uma única sessão de assistente.  
  
 Você pode adicionar classes de controles ActiveX registrados em seu sistema, ou você pode adicionar classes de controles ActiveX localizados em arquivos de biblioteca de tipo (. tlb, olb,. dll,. ocx ou .exe) sem primeiro registrando-os no seu sistema. Consulte [registrar controles de OLE](../mfc/reference/registering-ole-controls.md) para obter mais informações sobre como registrar os controles ActiveX.  
  
 O assistente cria uma classe do MFC, derivada do [CWnd](../mfc/reference/cwnd-class.md) ou [COleDispatchDriver](../mfc/reference/coledispatchdriver-class.md), para cada interface que você adicionar a partir do controle ActiveX selecionado.  
  
## <a name="see-also"></a>Consulte também  
 [Controles ActiveX MFC](../mfc/mfc-activex-controls.md)   
 [Introdução ao COM e à ATL](../atl/introduction-to-com-and-atl.md)