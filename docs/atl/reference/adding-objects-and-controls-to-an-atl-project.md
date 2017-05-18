---
title: Adicionando controles e objetos em um projeto ATL | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- vc.appwiz.ATL.controls
dev_langs:
- C++
helpviewer_keywords:
- ATL projects, adding objects
- wizards [C++], ATL projects
- ATL projects, adding controls
- controls [ATL], adding to projects
- objects [C++], adding to ATL projects
- ATL Control Wizard
ms.assetid: c0adcbd0-07fe-4c55-a8fd-8c2c65ecdaad
caps.latest.revision: 12
author: mikeblome
ms.author: mblome
manager: ghogen
translation.priority.ht:
- cs-cz
- de-de
- es-es
- fr-fr
- it-it
- ja-jp
- ko-kr
- pl-pl
- pt-br
- ru-ru
- tr-tr
- zh-cn
- zh-tw
ms.translationtype: Machine Translation
ms.sourcegitcommit: 3168772cbb7e8127523bc2fc2da5cc9b4f59beb8
ms.openlocfilehash: 930409137a2dfdddc4659e828cc1678235922702
ms.contentlocale: pt-br
ms.lasthandoff: 02/25/2017

---
# <a name="adding-objects-and-controls-to-an-atl-project"></a>Adicionando controles e objetos a um projeto do ATL
Você pode usar um dos assistentes de código do ATL para adicionar um objeto ou um controle para seus projetos baseados em MFC ou ATL. Para cada controle ou objeto COM adicionar, o assistente gera. cpp e. h, bem como um arquivo. rgs para suporte ao registro baseado no script. Os seguintes assistentes de código ATL estão disponíveis no Visual Studio:  
  
||||  
|-|-|-|  
|[ATL Simple Object](../../atl/reference/atl-simple-object-wizard.md)|[Caixa de diálogo do ATL](../../atl/reference/atl-dialog-wizard.md)|[Controle ATL](../../atl/reference/atl-control-wizard.md)|  
|[Página de propriedades ATL](../../atl/reference/atl-property-page-wizard.md)|[Componente de página de servidor ativo do ATL](../../atl/reference/atl-active-server-page-component-wizard.md)|[Consumidor ATL OLE DB](../../atl/reference/atl-ole-db-consumer-wizard.md)|  
|[Adicionar suporte ATL ao MFC](../../mfc/reference/adding-atl-support-to-your-mfc-project.md)|[Assistente para ATL COM+ 1.0 do componente](../../atl/reference/atl-com-plus-1-0-component-wizard.md)|[Provedor OLE DB do ATL](../../atl/reference/atl-ole-db-provider-wizard.md)|  
  
> [!NOTE]
>  Antes de adicionar um objeto ATL ao seu projeto, examine os detalhes e requisitos para o objeto seus tópicos de Ajuda relacionados.  
  
### <a name="to-add-an-object-or-a-control-using-the-atl-control-wizard"></a>Para adicionar um objeto ou um controle usando o Assistente de controle ATL  
  
1.  No Solution Explorer, clique com botão direito no nó do projeto e clique em **adicionar** no menu de atalho. Clique em **Adicionar classe**.  
  
     O [Add Class](../../ide/add-class-dialog-box.md) caixa de diálogo é exibida.  
  
2.  Com a pasta ATL selecionada no painel de categorias, selecione um objeto a ser inserido no painel Templates. Clique em **abrir**. O Assistente de código para o objeto selecionado é exibido.  
  
    > [!NOTE]
    >  Se você quiser adicionar um objeto ATL para um projeto MFC, você deve adicionar suporte ATL ao projeto existente. Você pode fazer isso seguindo as instruções em [adicionando suporte ATL ao seu projeto MFC](../../mfc/reference/adding-atl-support-to-your-mfc-project.md).  
  
     Como alternativa, se você tentar adicionar um objeto ATL ao seu projeto MFC sem anteriormente adicionando suporte ATL, o Visual Studio solicita que você especifique se deseja suporte ATL adicionado ao seu projeto. Clique em **Sim** para adicionar suporte ATL ao projeto e abrir o assistente ATL selecionado.  
  
## <a name="see-also"></a>Consulte também  
 [ATL Project Wizard](../../atl/reference/atl-project-wizard.md)   
 [Tipos de projeto do Visual C++](../../ide/visual-cpp-project-types.md)   
 [Criando projetos de Desktop com assistentes de aplicativo](../../ide/creating-desktop-projects-by-using-application-wizards.md)   
 [Conceitos básicos de objetos COM de ATL](../../atl/fundamentals-of-atl-com-objects.md)   
 [Programando com código ATL e C Run-Time](../../atl/programming-with-atl-and-c-run-time-code.md)   
 [Configurações de projeto padrão ATL](../../atl/reference/default-atl-project-configurations.md)


