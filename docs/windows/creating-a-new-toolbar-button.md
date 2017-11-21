---
title: "Criar um novo botão de barra de ferramentas | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords: vc.editors.toolbar
dev_langs: C++
helpviewer_keywords:
- Toolbar editor, creating buttons
- toolbar buttons (in Toolbar editor), button image
- toolbar buttons (in Toolbar editor), creating
- toolbar buttons (in Toolbar editor)
ms.assetid: 46c120fe-4f2a-4887-a08f-bd1fea04b3f4
caps.latest.revision: "10"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.openlocfilehash: 340756fcb85af8402f3c01d9efb8f1c62c6b0b41
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
---
# <a name="creating-a-new-toolbar-button"></a>Criando um novo botão da barra de ferramentas
### <a name="to-create-a-new-toolbar-button"></a>Para criar um novo botão de barra de ferramentas  
  
1.  Em [exibição recursos](../windows/resource-view-window.md) expanda a pasta de recurso (por exemplo, Project1.rc).  
  
    > [!NOTE]
    >  Se o projeto já não contiver um arquivo. RC, consulte [criar um novo arquivo de Script de recurso](../windows/how-to-create-a-resource-script-file.md).  
  
2.  Expanda o **barra de ferramentas** pasta e selecione uma barra de ferramentas para editar.  
  
3.  Atribua uma ID para o botão em branco na extremidade direita da barra de ferramentas. Você pode fazer isso editando o **ID** propriedade o [janela propriedades](/visualstudio/ide/reference/properties-window). Por exemplo, convém fornecer um botão de barra de ferramentas a mesma ID como uma opção de menu. Nesse caso, use a caixa de listagem suspensa para selecionar o **ID** da opção de menu.  
  
     -ou-  
  
     Selecione o botão em branco na extremidade direita da barra de ferramentas (no painel de exibição da barra de ferramentas) e iniciar desenho. Uma ID de comando de botão padrão é atribuída (ID_BUTTON\<n >).  
  
 Você também pode copiar e colar uma imagem em uma barra de ferramentas como um novo botão.  
  
#### <a name="to-add-an-image-to-a-toolbar-as-a-button"></a>Para adicionar uma imagem de uma barra de ferramentas, como um botão  
  
1.  Em [exibição recursos](../windows/resource-view-window.md), abra a barra de ferramentas clicando duas vezes nele.  
  
2.  Em seguida, abra a imagem que você deseja adicionar à barra de ferramentas.  
  
    > [!NOTE]
    >  Se você abrir a imagem no Visual Studio, ele será aberto no editor de imagem. Você também pode abrir a imagem em outros programas de elementos gráficos.  
  
3.  Do **editar** menu, escolha **cópia**.  
  
4.  Alterne para a barra de ferramentas clicando na guia na parte superior da janela de origem.  
  
5.  Do **editar** menu, escolha **colar**.  
  
     A imagem será exibida na barra de ferramentas, como um novo botão.  
  
 Para obter informações sobre como adicionar recursos a projetos gerenciados, consulte [recursos em aplicativos de área de trabalho](https://msdn.microsoft.com/library/f45fce5x.aspx) no *guia do desenvolvedor do .NET Framework.* Para obter informações sobre como adicionar manualmente os arquivos de recurso para projetos gerenciados, acessar recursos, exibir recursos estáticos e atribuir cadeias de caracteres de recurso para propriedades, consulte [criando arquivos de recursos para aplicativos de área de trabalho](https://msdn.microsoft.com/library/xbx3z216.aspx). Para obter informações sobre globalização e localização de recursos em aplicativos gerenciados, consulte [Globalizing e localização de aplicativos do .NET Framework](https://msdn.microsoft.com/library/h6270d0z.aspx).  
  
### <a name="requirements"></a>Requisitos  
 MFC ou do ATL  
  
## <a name="see-also"></a>Consulte também  
 [Propriedades de botão da barra de ferramentas](../windows/toolbar-button-properties.md)   
 [Criando, movendo e editando botões da barra de ferramentas](../windows/creating-moving-and-editing-toolbar-buttons.md)   
 [Editor de barra de ferramentas](../windows/toolbar-editor.md)

