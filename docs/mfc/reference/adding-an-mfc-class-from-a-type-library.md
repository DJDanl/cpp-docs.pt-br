---
title: Adicionando uma classe do MFC de uma biblioteca de tipos | Microsoft Docs
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
- classes [MFC], adding MFC
- MFC, adding classes from type libraries
- type libraries, adding MFC classes from
ms.assetid: aba40476-3cfb-47af-990e-ae2e9e0d79cf
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 1efc61e097d7e1136fdb7b6ef740dc00342077e4
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="adding-an-mfc-class-from-a-type-library"></a>Adicionando uma classe do MFC de uma biblioteca de tipos
Use este assistente para criar uma classe do MFC de uma interface em uma biblioteca de tipos disponíveis. Você pode adicionar uma classe do MFC para um [aplicativo MFC](../../mfc/reference/creating-an-mfc-application.md), uma [DLL MFC](../../mfc/reference/creating-an-mfc-dll-project.md), ou um [controle ActiveX MFC](../../mfc/reference/creating-an-mfc-activex-control.md).  
  
> [!NOTE]
>  Você não precisa criar seu projeto MFC com automação habilitada para adicionar uma classe de uma biblioteca de tipos.  
  
 Uma biblioteca de tipos contém uma descrição binária das interfaces expostas por um componente, definir os métodos junto com seus parâmetros e tipos de retorno. Sua biblioteca de tipo deve ser registrada para ser exibido no **bibliotecas de tipo disponível** lista a adição de classe em Typelib assistente. Consulte "Dentro de Distributed COM: tipo bibliotecas e linguagem integração" na biblioteca MSDN para obter mais informações.  
  
### <a name="to-add-an-mfc-class-from-a-type-library"></a>Para adicionar uma classe do MFC de uma biblioteca de tipos  
  
1.  No **Solution Explorer** ou [exibição de classe](http://msdn.microsoft.com/en-us/8d7430a9-3e33-454c-a9e1-a85e3d2db925), clique no nome do projeto ao qual você deseja adicionar a classe.  
  
2.  No menu de atalho, clique em **adicionar**e, em seguida, clique em **Adicionar classe**.  
  
3.  No [Adicionar classe](../../ide/add-class-dialog-box.md) caixa de diálogo, no painel modelos, clique em **classe do MFC de Typelib**e, em seguida, clique em **abrir** para exibir o [adição de classe em Typelib Assistente ](../../mfc/reference/add-class-from-typelib-wizard.md).  
  
 No assistente, você pode adicionar mais de uma classe em uma biblioteca de tipos. Da mesma forma, você pode adicionar classes de mais de uma biblioteca de tipos em uma única sessão de assistente.  
  
 O assistente cria uma classe do MFC, derivada do [COleDispatchDriver](../../mfc/reference/coledispatchdriver-class.md), para cada interface que você adicionar a biblioteca de tipos selecionados. `COleDispatchDriver`implementa o lado do cliente de automação OLE.  
  
## <a name="see-also"></a>Consulte também  
 [Clientes de automação](../../mfc/automation-clients.md)   
 [Clientes de automação: usando bibliotecas de tipo](../../mfc/automation-clients-using-type-libraries.md)

