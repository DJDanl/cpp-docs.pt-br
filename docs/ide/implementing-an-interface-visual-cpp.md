---
title: Implementando uma interface (Visual C++) | Microsoft Docs
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
ms.openlocfilehash: cfee61f1632fad2d762c41149c1bc302a1c4b9da
ms.sourcegitcommit: a7046aac86f1c83faba1088c80698474e25fe7c3
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/04/2018
ms.locfileid: "43691980"
---
# <a name="implementing-an-interface-visual-c"></a>Implementando uma interface (Visual C++)
Para implementar uma interface, você precisa ter criado um projeto como um aplicativo ATL COM ou como um aplicativo MFC que contém suporte para ATL. Use o [Assistente de Projeto ATL](../atl/reference/atl-project-wizard.md) para criar um aplicativo ATL ou [Adicionar um objeto ATL ao aplicativo MFC](../mfc/reference/adding-atl-support-to-your-mfc-project.md) para implementar o suporte à ATL para um aplicativo MFC.  
  
 Depois de criar o projeto, para implementar uma interface, adicione primeiro um objeto ATL. Confira [Adicionando objetos e controles a um projeto ATL](../atl/reference/adding-objects-and-controls-to-an-atl-project.md) para obter uma lista de assistentes que adicionam objetos ao projeto ATL.  
  
> [!NOTE]
>  O assistente não dá suporte a caixas de diálogo da ATL, serviços Web XML que usam a ATL, objetos de desempenho ou contadores de desempenho.  
  
 Se você [adicionar um controle ATL](../atl/reference/adding-an-atl-control.md), especifique se deseja implementar interfaces padrão, listadas na página [Interfaces](../atl/reference/interfaces-atl-control-wizard.md) do assistente e definidas em atlcom.h.  
  
 Depois de adicionar o objeto ou o controle, implemente outras interfaces, localizadas em qualquer biblioteca de tipos disponível, usando o Assistente para Implementação de Interface.  
  
 Caso esteja adicionando uma nova interface, adicione-a manualmente ao arquivo .idl do projeto. Confira [Adicionando uma nova interface a um projeto ATL](../atl/reference/adding-a-new-interface-in-an-atl-project.md) para obter mais informações.  
  
### <a name="to-implement-an-interface"></a>Para implementar uma interface  
  
1.  Em Modo de Exibição de Classe, clique com o botão direito do mouse no nome da classe do objeto ATL.  
  
2.  Clique em **Adicionar** no menu de atalho e, em seguida, clique em **Implementar Interface** para exibir o [Assistente para Implementação de Interface](../ide/implement-interface-wizard.md).  
  
3.  Selecione as interfaces a serem implementadas nas bibliotecas de tipos apropriadas e clique em **Concluir**.  
  
4.  Em Modo de Exibição de Classe, expanda o nó Bases e Interfaces do objeto para ver a interface implementada e, em seguida, expanda o nó da interface para ver as propriedades, os métodos e os eventos disponíveis.  
  
    > [!NOTE]
    >  Use também o [Pesquisador de Objetos](/visualstudio/ide/viewing-the-structure-of-code) para examinar os membros da interface.  
  
## <a name="see-also"></a>Consulte também  
 [Criando uma interface COM](../ide/creating-a-com-interface-visual-cpp.md)   
 [Editando uma interface COM](../ide/editing-a-com-interface.md)