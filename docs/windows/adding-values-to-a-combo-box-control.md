---
title: "Adicionando valores a um controle de caixa de combinação | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords: vc.editors.dialog.combo
dev_langs: C++
helpviewer_keywords:
- combo boxes [C++], Data property
- controls [Visual Studio], testing values in combo boxes
- combo boxes [C++], adding values
- combo boxes [C++], previewing values
- controls [C++], testing values in combo boxes
- Data property
- combo boxes [C++], testing values
ms.assetid: 22a78f98-fada-48b3-90d8-7fa0d8e4de51
caps.latest.revision: "9"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 9125ad60648f6f867e1214763a6af164d0239a04
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="adding-values-to-a-combo-box-control"></a>Adicionando valores a um controle de caixa de combinação
Você pode adicionar valores para um controle de caixa de combinação, contanto que o editor de caixa de diálogo Abrir.  
  
> [!TIP]
>  É uma boa ideia para adicionar todos os valores para a caixa de combinação *antes de* tamanho caixa no editor de caixa de diálogo, ou você pode truncar o texto que deve aparecer no controle de caixa de combinação.  
  
#### <a name="to-enter-values-into-a-combo-box-control"></a>Para inserir valores em um controle de caixa de combinação  
  
1.  Selecione o controle de caixa de combinação clicando nele.  
  
2.  No [janela propriedades](/visualstudio/ide/reference/properties-window), role para baixo até o **dados** propriedade.  
  
    > [!NOTE]
    >  Se você estiver exibindo propriedades agrupadas por tipo, **dados** aparece no **Misc** propriedades.  
  
3.  Clique na área de valor para o **dados** propriedade e digite os valores de dados, separados por ponto e vírgula.  
  
    > [!NOTE]
    >  Não coloque espaços entre os valores como espaços interferem colocando em ordem alfabética na lista suspensa.  
  
4.  Clique em **Enter** quando tiver terminado de adicionar valores.  
  
 Para obter informações sobre como aumentar a lista suspensa de uma caixa de combinação, consulte [definindo o tamanho da sua lista de lista suspensa de caixa de combinação e](setting-the-size-of-the-combo-box-and-its-drop-down-list.md).  
  
> [!NOTE]
>  Você não pode adicionar valores para projetos de Win32 usando esse procedimento (o **dados** propriedade é esmaecida para projetos de Win32). Porque Win32 projetos não possuem bibliotecas que adicionam essa funcionalidade, você deve adicionar valores para uma caixa de combinação com um projeto do Win32 programaticamente.  
  
#### <a name="to-test-the-appearance-of-values-in-a-combo-box"></a>Para testar a aparência dos valores em uma caixa de combinação  
  
1.  Depois de inserir valores no **dados** propriedade, clique no **teste** botão o [barra de ferramentas do Editor de caixa de diálogo](../windows/showing-or-hiding-the-dialog-editor-toolbar.md).  
  
     Tente rolar para baixo na lista de valor inteiro. Valores são exibidos exatamente como eles são digitados no **dados** propriedade na janela Propriedades. Não há nenhuma verificação de maiusculas e minúsculas ou ortografia.  
  
     Pressione ESC para retornar ao editor de caixa de diálogo.  
  
 Para obter informações sobre como adicionar recursos a projetos gerenciados, consulte [recursos em aplicativos de área de trabalho](/dotnet/framework/resources/index) no *guia do desenvolvedor do .NET Framework.* Para obter informações sobre como adicionar manualmente os arquivos de recurso para projetos gerenciados, acessar recursos, exibir recursos estáticos e atribuir cadeias de caracteres de recurso para propriedades, consulte [criando arquivos de recursos para aplicativos de área de trabalho](/dotnet/framework/resources/creating-resource-files-for-desktop-apps). Para obter informações sobre globalização e localização de recursos em aplicativos gerenciados, consulte [Globalizing e localização de aplicativos do .NET Framework](/dotnet/standard/globalization-localization/index).  
  
### <a name="requirements"></a>Requisitos  
 Win32  
  
## <a name="see-also"></a>Consulte também  
 [Controles em caixas de diálogo](../windows/controls-in-dialog-boxes.md)   
 [Controles](../mfc/controls-mfc.md)

