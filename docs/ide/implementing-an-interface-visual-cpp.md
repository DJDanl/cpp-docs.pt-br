---
title: Implementando uma Interface (Visual C++) | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-ide
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- interfaces, implementing
ms.assetid: 72f8731b-7e36-45db-8b10-7ef211a773cd
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 309ae9dc576f93574836ab4916e87c5232b37a6c
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="implementing-an-interface-visual-c"></a>Implementando uma interface (Visual C++)
Para implementar uma interface, você deve ter criado um projeto como um aplicativo COM ATL ou como um aplicativo MFC que contém suporte ATL. Você pode usar o [Assistente de projeto de ATL](../atl/reference/atl-project-wizard.md) para criar um aplicativo ATL, ou [adicionar um objeto ATL ao seu aplicativo do MFC](../mfc/reference/adding-atl-support-to-your-mfc-project.md) para implementar o suporte ATL para um aplicativo do MFC.  
  
 Depois de criar o projeto, para implementar uma interface, adicione primeiro um objeto ATL. Consulte [adicionando objetos e controles para um projeto de ATL](../atl/reference/adding-objects-and-controls-to-an-atl-project.md) para obter uma lista de assistentes que adicionar objetos ao seu projeto ATL.  
  
> [!NOTE]
>  O assistente não oferece suporte para as caixas de diálogo do ATL XML Web services usando a ATL, objetos de desempenho ou os contadores de desempenho.  
  
 Se você [adicionar um controle ATL](../atl/reference/adding-an-atl-control.md), você pode especificar se deseja implementar interfaces padrão, listadas a [Interfaces](../atl/reference/interfaces-atl-control-wizard.md) página do ou do assistente e definidos no atlcom.h.  
  
 Depois de adicionar o objeto ou controle, você pode implementar outras interfaces, localizados em qualquer biblioteca de tipos disponíveis, usando o Assistente para implementar a Interface.  
  
 Se você estiver adicionando uma nova interface, você deve adicioná-lo manualmente para o arquivo do projeto. idl. Consulte [adicionando uma nova Interface em um projeto de ATL](../atl/reference/adding-a-new-interface-in-an-atl-project.md) para obter mais informações.  
  
### <a name="to-implement-an-interface"></a>Para implementar uma interface  
  
1.  No modo de exibição de classe, clique no nome de classe para seu objeto ATL.  
  
2.  Clique em **adicionar** do menu de atalho e clique **implementar Interface** para exibir o [Assistente de implementação de Interface](../ide/implement-interface-wizard.md).  
  
3.  Selecione as interfaces para implementar das bibliotecas de tipo apropriado e clique em **concluir**.  
  
4.  No modo de exibição de classe, expanda Bases de dados do objeto e Interfaces de nó para ver a interface que você tenha implementado e, em seguida, expanda o nó da interface para ver suas propriedades disponíveis, métodos e eventos.  
  
    > [!NOTE]
    >  Você também pode usar o [Pesquisador de objetos](http://msdn.microsoft.com/en-us/f89acfc5-1152-413d-9f56-3dc16e3f0470) para examinar os membros da interface.  
  
## <a name="see-also"></a>Consulte também  
 [Criando uma Interface COM](../ide/creating-a-com-interface-visual-cpp.md)   
 [Editando uma interface COM](../ide/editing-a-com-interface.md)