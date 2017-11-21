---
title: "Mostrando ou ocultando a barra de ferramentas do Editor de caixa de diálogo | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
dev_langs: C++
helpviewer_keywords:
- controls [C++], showing or hiding Dialog editor toolbar
- toolbars [C++], showing
- toolbars [C++], hiding
- Dialog editor, showing or hiding toolbar
ms.assetid: 93c255e1-90eb-48b6-8602-450acda75bed
caps.latest.revision: "10"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.openlocfilehash: e794cb6e24e86aa83fe7ea5b36f700c9dc9893f4
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
---
# <a name="showing-or-hiding-the-dialog-editor-toolbar"></a>Mostrando ou ocultando a barra de ferramentas Editor de Caixa de Diálogo
Quando você abre o editor de caixa de diálogo, a barra de ferramentas do Editor de caixa de diálogo é exibida automaticamente na parte superior da sua solução.  
  
### <a name="dialog-editor-toolbar"></a>Barra de ferramentas do Editor de caixa de diálogo  
  
|Ícone|Significado|Ícone|Significado|  
|----------|-------------|----------|-------------|  
|![Botão da caixa de diálogo de teste](../mfc/media/vcdialogeditortestdialog.png "vcDialogEditorTestDialog")|Caixa de diálogo de teste|![Botão de espaço em](../mfc/media/vcdialogeditoracross.png "vcDialogEditorAcross")|Em|  
|![Alinhar à esquerda botão](../mfc/media/vcdialogeditoralignlefts.png "vcDialogEditorAlignLefts")|Alinhar à esquerda|![Botão espaço para baixo](../mfc/media/vcdialogeditordown.png "vcDialogEditorDown")|Abaixo|  
|![Alinhar botão direitos](../mfc/media/vcdialogeditoralignrights.png "vcDialogEditorAlignRights")|Alinhar os direitos|![Botão de mesma largura Verifique](../mfc/media/vcdialogeditorsamewidth.png "vcDialogEditorSameWidth")|Igualar largura|  
|![Alinhar partes superiores botão](../mfc/media/vcdialogeditoraligntops.png "vcDialogEditorAlignTops")|Alinhar as partes superiores|![Botão de mesma altura Verifique](../mfc/media/vcdialogeditormakesameheight.png "vcDialogEditorMakeSameHeight")|Igualar altura|  
|![Alinhar botão inferiores](../mfc/media/vcdialogeditoralignbottoms.png "vcDialogEditorAlignBottoms")|Alinhar a parte inferior|![Botão de mesmo tamanho Verifique](../mfc/media/vcdialogeditorsamesize.png "vcDialogEditorSameSize")|Igualar tamanho|  
|![Botão Vertical central](../mfc/media/vcdialogeditorvertical.png "vcDialogEditorVertical")|Vertical|![Um botão de alternância grade](../mfc/media/vcdialogeditortogglegrid.png "vcDialogEditorToggleGrid")|Ativar/Desativar Grade|  
|![Botão Horizontal Center](../mfc/media/vcdialogeditorhorizontal.png "vcDialogEditorHorizontal")|Horizontal|![Um botão de alternância guias](../mfc/media/vcdialogeditortoggleguides.png "vcDialogEditorToggleGuides")|Ativar/desativar guias|  
  
 A barra de ferramentas do Editor de caixa de diálogo contém botões para organizar o layout dos controles na caixa de diálogo, por exemplo, tamanho e alinhamento. Botões de barra de ferramentas do Editor de caixa de diálogo correspondem aos comandos do menu Formatar. Para obter detalhes, consulte [teclas de aceleração para o Editor de caixa de diálogo](../windows/accelerator-keys-for-the-dialog-editor.md).  
  
 Quando você estiver no editor de caixa de diálogo, você pode alternar a exibição da barra de ferramentas do Editor de caixa de diálogo selecionando-o na lista de barras de ferramentas disponíveis e windows.  
  
### <a name="to-show-or-hide-the-dialog-editor-toolbar"></a>Para mostrar ou ocultar a barra de ferramentas do editor de caixa de diálogo  
  
1.  No **exibição** menu clique **barras de ferramentas** , em seguida, escolha **Editor de caixa de diálogo** do submenu.  
  
    > [!NOTE]
    >  A barra de ferramentas do Editor de caixa de diálogo é exibida por padrão quando você abrir um recurso de caixa de diálogo no editor de caixa de diálogo; No entanto, se você fechar explicitamente a barra de ferramentas, você precisará invocá-lo na próxima vez que você abrir um recurso de caixa de diálogo.  
  
 Para obter informações sobre como adicionar recursos a projetos gerenciados, consulte [recursos em aplicativos de área de trabalho](https://msdn.microsoft.com/library/f45fce5x.aspx) no *guia do desenvolvedor do .NET Framework.* Para obter informações sobre como adicionar manualmente os arquivos de recurso para projetos gerenciados, acessar recursos, exibir recursos estáticos e atribuir cadeias de caracteres de recurso para propriedades, consulte [criando arquivos de recursos para aplicativos de área de trabalho](https://msdn.microsoft.com/library/xbx3z216.aspx). Para obter informações sobre globalização e localização de recursos em aplicativos gerenciados, consulte [Globalizing e localização de aplicativos do .NET Framework](https://msdn.microsoft.com/library/h6270d0z.aspx).  
  
 Requisitos  
  
 Win32  
  
## <a name="see-also"></a>Consulte também  
 [Organização dos controles em caixas de diálogo](../windows/arrangement-of-controls-on-dialog-boxes.md)   
 [Como: criar um recurso](../windows/how-to-create-a-resource.md)   
 [Arquivos de recurso](../windows/resource-files-visual-studio.md)   
 [Editor de caixa de diálogo](../windows/dialog-editor.md)

