---
title: Adicionando valores a um controle de caixa de combinação | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: conceptual
f1_keywords:
- vc.editors.dialog.combo
dev_langs:
- C++
helpviewer_keywords:
- combo boxes [C++], Data property
- controls [Visual Studio], testing values in combo boxes
- combo boxes [C++], adding values
- combo boxes [C++], previewing values
- controls [C++], testing values in combo boxes
- Data property
- combo boxes [C++], testing values
ms.assetid: 22a78f98-fada-48b3-90d8-7fa0d8e4de51
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 3760da2fad7596938acf881cd36af099ad1253cf
ms.sourcegitcommit: 37a10996022d738135999cbe71858379386bab3d
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/08/2018
ms.locfileid: "39643790"
---
# <a name="adding-values-to-a-combo-box-control"></a>Adicionando valores a um controle de caixa de combinação
Você pode adicionar valores a um controle de caixa de combinação, desde que você tenha o **caixa de diálogo** editor aberto.  
  
> [!TIP]
>  É uma boa ideia adicionar todos os valores à caixa de combinação *antes de* você dimensiona a caixa na **caixa de diálogo** editor, ou você pode truncar o texto que deve aparecer no controle de caixa de combinação.  
  
### <a name="to-enter-values-into-a-combo-box-control"></a>Para inserir valores em um controle de caixa de combinação  
  
1.  Selecione o controle de caixa de combinação clicando nele.  
  
2.  No [janela de propriedades](/visualstudio/ide/reference/properties-window), role para baixo até a **dados** propriedade.  
  
    > [!NOTE]
    >  Se você estiver exibindo as propriedades agrupadas por tipo, **dados** aparece na **Misc** propriedades.  
  
3.  Clique na área de valor para o **dados** propriedade e digite os valores de dados, separados por ponto e vírgula.  
  
    > [!NOTE]
    >  Não coloque espaços entre os valores como espaços interferem colocando em ordem alfabética na lista suspensa.  
  
4.  Clique em **Enter** quando tiver terminado de adicionar os valores.  
  
 Para obter informações sobre como aumentar a parte suspensa de uma caixa de combinação, consulte [definindo o tamanho da caixa de combinação e sua lista de suspensa](setting-the-size-of-the-combo-box-and-its-drop-down-list.md).  
  
> [!NOTE]
>  Você não pode adicionar valores para projetos do Win32 usando esse procedimento (o **dados** propriedade fica esmaecida para projetos do Win32). Como projetos do Win32 não têm bibliotecas que adicionam essa funcionalidade, você deve adicionar valores para uma caixa de combinação com um projeto do Win32 por meio de programação.  
  
### <a name="to-test-the-appearance-of-values-in-a-combo-box"></a>Para testar a aparência dos valores em uma caixa de combinação  
  
1.  Depois de inserir valores na **dados** propriedade, clique no **teste** botão o [barra de ferramentas do Editor de caixa de diálogo](../windows/showing-or-hiding-the-dialog-editor-toolbar.md).  
  
     Tente rolar para baixo na lista de todo o valor. Valores são exibidos exatamente como eles são digitados a **dados** propriedade no **propriedades** janela. Não há nenhum ortografia ou verificação de maiusculas e minúsculas.  
  
     Pressione **Esc** para retornar para o **caixa de diálogo** editor.  
  
 Para obter informações sobre como adicionar recursos a projetos gerenciados, consulte [recursos em aplicativos de área de trabalho](/dotnet/framework/resources/index) na *guia do desenvolvedor do .NET Framework*. Para obter informações sobre como adicionar manualmente os arquivos de recursos a projetos gerenciados, acessar recursos, exibir recursos estáticos e atribuir cadeias de caracteres de recurso a propriedades, consulte [criando arquivos de recursos para aplicativos de área de trabalho](/dotnet/framework/resources/creating-resource-files-for-desktop-apps). Para obter informações sobre globalização e localização de recursos em aplicativos gerenciados, consulte [Globalizing e Localizando aplicativos do .NET Framework](/dotnet/standard/globalization-localization/index).  
  
## <a name="requirements"></a>Requisitos  
 Win32  
  
## <a name="see-also"></a>Consulte também  
 [Controles em caixas de diálogo](../windows/controls-in-dialog-boxes.md)   
 [Controles](../mfc/controls-mfc.md)