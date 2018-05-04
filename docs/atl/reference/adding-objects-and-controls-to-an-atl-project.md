---
title: Adicionando controles e objetos para um projeto de ATL | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-atl
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
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 5a6f9102aeebd0cc60765c70cf74fb2329bc801f
ms.sourcegitcommit: be2a7679c2bd80968204dee03d13ca961eaa31ff
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/03/2018
---
# <a name="adding-objects-and-controls-to-an-atl-project"></a>Adicionando controles a um projeto ATL e objetos
Você pode usar um dos assistentes de código de ATL para adicionar um objeto ou um controle de seus projetos com base em ATL ou MFC. Para cada controle ou um objeto COM adicionar, o assistente gera arquivos. h e. cpp, bem como um arquivo. rgs para suporte a registro baseado no script. Os seguintes assistentes de código ATL estão disponíveis no Visual Studio:  
  
||||  
|-|-|-|  
|[Objeto ATL simples](../../atl/reference/atl-simple-object-wizard.md)|[Caixa de diálogo do ATL](../../atl/reference/atl-dialog-wizard.md)|[Controle ATL](../../atl/reference/atl-control-wizard.md)|  
|[Página de propriedades ATL](../../atl/reference/atl-property-page-wizard.md)|[Componente de página de servidor ativo do ATL](../../atl/reference/atl-active-server-page-component-wizard.md)|[Consumidor do ATL OLE DB](../../atl/reference/atl-ole-db-consumer-wizard.md)|  
|[Adicionar suporte ATL ao MFC](../../mfc/reference/adding-atl-support-to-your-mfc-project.md)|[Assistente de componente de COM+ 1.0 da ATL](../../atl/reference/atl-com-plus-1-0-component-wizard.md)|[Provedor OLE DB do ATL](../../atl/reference/atl-ole-db-provider-wizard.md)|  
  
> [!NOTE]
>  Antes de adicionar um objeto ATL ao seu projeto, você deve revisar os detalhes e requisitos para o objeto em seus tópicos de Ajuda relacionados.  
  
### <a name="to-add-an-object-or-a-control-using-the-atl-control-wizard"></a>Para adicionar um objeto ou um controle usando o Assistente de controle ATL  
  
1.  No Gerenciador de soluções, clique com botão direito no nó do projeto e clique em **adicionar** no menu de atalho. Clique em **Adicionar classe**.  
  
     O [Adicionar classe](../../ide/add-class-dialog-box.md) caixa de diálogo é exibida.  
  
2.  Com a pasta ATL selecionada no painel de categorias, selecione um objeto a ser inserido no painel modelos. Clique em **abrir**. O Assistente de código para o objeto selecionado é exibido.  
  
    > [!NOTE]
    >  Se você deseja adicionar um objeto ATL a um projeto, você deve adicionar suporte ATL ao projeto existente. Você pode fazer isso, seguindo as instruções em [adicionar suporte ATL ao seu projeto MFC](../../mfc/reference/adding-atl-support-to-your-mfc-project.md).  
  
     Como alternativa, se você tentar adicionar um objeto ATL ao seu projeto MFC sem anteriormente adicionar suporte ATL, o Visual Studio solicitará que você especifique se deseja que o suporte ATL adicionado ao seu projeto. Clique em **Sim** para adicionar suporte ATL ao projeto e abrir o assistente ATL selecionado.  
  
## <a name="see-also"></a>Consulte também  
 [Assistente de projeto ATL](../../atl/reference/atl-project-wizard.md)   
 [Tipos de projeto do Visual C++](../../ide/visual-cpp-project-types.md)   
 [Criando projetos de área de trabalho usando os assistentes de aplicativo](../../ide/creating-desktop-projects-by-using-application-wizards.md)   
 [Conceitos básicos de objetos COM de ATL](../../atl/fundamentals-of-atl-com-objects.md)   
 [Programando com código ATL e C Run-Time](../../atl/programming-with-atl-and-c-run-time-code.md)   
 [Configurações de projeto padrão da ATL](../../atl/reference/default-atl-project-configurations.md)

