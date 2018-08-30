---
title: Adicionando uma classe do MFC de uma biblioteca de tipos | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: reference
dev_langs:
- C++
helpviewer_keywords:
- classes [MFC], adding MFC
- MFC, adding classes from type libraries
- type libraries, adding MFC classes from
ms.assetid: aba40476-3cfb-47af-990e-ae2e9e0d79cf
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 656d5c357874a7b470eb2fd630c91ad0aefa5a0d
ms.sourcegitcommit: 9a0905c03a73c904014ec9fd3d6e59e4fa7813cd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/29/2018
ms.locfileid: "43205367"
---
# <a name="adding-an-mfc-class-from-a-type-library"></a>Adicionando uma classe do MFC de uma biblioteca de tipos
Use este assistente para criar uma classe MFC de uma interface em uma biblioteca de tipos disponíveis. Adicione uma classe MFC a um [aplicativo MFC](../../mfc/reference/creating-an-mfc-application.md), uma [DLL do MFC](../../mfc/reference/creating-an-mfc-dll-project.md) ou um [controle ActiveX do MFC](../../mfc/reference/creating-an-mfc-activex-control.md).  
  
> [!NOTE]
>  Você não precisará criar seu projeto MFC com automação habilitada para adicionar uma classe de uma biblioteca de tipos.  
  
 Uma biblioteca de tipos contém uma descrição binária de interfaces expostas por um componente, definindo os métodos, juntamente com seus parâmetros e tipos de retorno. Sua biblioteca de tipos deve ser registrada para que ele apareça na **bibliotecas de tipos disponíveis** lista na classe de Typelib assistente Adicionar. Consulte "Dentro de Distributed COM: tipo bibliotecas e linguagem integração" na biblioteca MSDN para obter mais informações.  
  
### <a name="to-add-an-mfc-class-from-a-type-library"></a>Para adicionar uma classe MFC de uma biblioteca de tipos  
  
1.  Em ambos **Gerenciador de soluções** ou [exibição de classe](https://msdn.microsoft.com/8d7430a9-3e33-454c-a9e1-a85e3d2db925), clique no nome do projeto ao qual você deseja adicionar a classe.  
  
2.  No menu de atalho, clique em **Adicionar** e, em seguida, em **Adicionar Classe**.  
  
3.  No [Add Class](../../ide/add-class-dialog-box.md) caixa de diálogo, no painel modelos, clique em **MFC classe em Typelib**e, em seguida, clique em **abrir** para exibir o [Adicionar classe de Typelib Assistente ](../../mfc/reference/add-class-from-typelib-wizard.md).  
  
 No assistente, você pode adicionar mais de uma classe em uma biblioteca de tipos. Da mesma forma, você pode adicionar classes de mais de uma biblioteca de tipos em uma única sessão de assistente.  
  
 O assistente cria uma classe do MFC, derivada de [COleDispatchDriver](../../mfc/reference/coledispatchdriver-class.md), para cada interface que você adicione da biblioteca de tipo selecionado. `COleDispatchDriver` implementa o lado do cliente da automação OLE.  
  
## <a name="see-also"></a>Consulte também  
 [Clientes de automação](../../mfc/automation-clients.md)   
 [Clientes de automação: usando bibliotecas de tipo](../../mfc/automation-clients-using-type-libraries.md)

