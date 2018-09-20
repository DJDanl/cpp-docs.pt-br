---
title: Mostrando ou ocultando a barra de ferramentas do Editor de caixa de diálogo (C++) | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- controls [C++], showing or hiding Dialog editor toolbar
- toolbars [C++], showing
- toolbars [C++], hiding
- Dialog Editor [C++], showing or hiding toolbar
ms.assetid: 93c255e1-90eb-48b6-8602-450acda75bed
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 02deeeed3eecf717cff380e43317e5a75c1fddf7
ms.sourcegitcommit: 799f9b976623a375203ad8b2ad5147bd6a2212f0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/19/2018
ms.locfileid: "46381238"
---
# <a name="showing-or-hiding-the-dialog-editor-toolbar-c"></a>Mostrando ou ocultando a barra de ferramentas do Editor de caixa de diálogo (C++)

Quando você abre o **caixa de diálogo** editor em um projeto do C++, o **Editor de caixa de diálogo** barra de ferramentas aparece automaticamente na parte superior da sua solução.

### <a name="dialog-editor-toolbar"></a>Barra de ferramentas do Editor de caixa de diálogo

|Ícone|Significado|Ícone|Significado|
|----------|-------------|----------|-------------|
|![Botão da caixa de diálogo de teste](../mfc/media/vcdialogeditortestdialog.png "vcDialogEditorTestDialog")|Caixa de diálogo de teste|![Botão de espaço entre](../mfc/media/vcdialogeditoracross.png "vcDialogEditorAcross")|Entre|
|![Alinhar botão esquerdas](../mfc/media/vcdialogeditoralignlefts.png "vcDialogEditorAlignLefts")|Alinhar à esquerda|![Botão espaço para baixo](../mfc/media/vcdialogeditordown.png "vcDialogEditorDown")|Abaixo|
|![Alinhar o botão de direitos](../mfc/media/vcdialogeditoralignrights.png "vcDialogEditorAlignRights")|Alinhar os direitos|![Botão de mesma largura Make](../mfc/media/vcdialogeditorsamewidth.png "vcDialogEditorSameWidth")|Fazer a mesma largura|
|![Alinhar botão Tops](../mfc/media/vcdialogeditoraligntops.png "vcDialogEditorAlignTops")|Alinhar partes superiores|![Botão de mesma altura Make](../mfc/media/vcdialogeditormakesameheight.png "vcDialogEditorMakeSameHeight")|Mesma altura|
|![Botão inferior alinhar](../mfc/media/vcdialogeditoralignbottoms.png "vcDialogEditorAlignBottoms")|Alinhar partes inferiores|![Botão de mesmo tamanho de marca](../mfc/media/vcdialogeditorsamesize.png "vcDialogEditorSameSize")|Igualar tamanho|
|![Botão de centro Vertical](../mfc/media/vcdialogeditorvertical.png "vcDialogEditorVertical")|Vertical|![Botão de alternância de grade](../mfc/media/vcdialogeditortogglegrid.png "vcDialogEditorToggleGrid")|Ativar/Desativar Grade|
|![Botão de centro Horizontal](../mfc/media/vcdialogeditorhorizontal.png "vcDialogEditorHorizontal")|Horizontal|![Botão de guias de alternância](../mfc/media/vcdialogeditortoggleguides.png "vcDialogEditorToggleGuides")|Ativar/desativar guias|

O **Editor de caixa de diálogo** barra de ferramentas contém botões para organizar o layout dos controles na caixa de diálogo, por exemplo tamanho e alinhamento. **Editor de caixa de diálogo** botões da barra de ferramentas correspondem aos comandos na **formato** menu. Para obter detalhes, consulte [teclas de aceleração para o Editor de caixa de diálogo](../windows/accelerator-keys-for-the-dialog-editor.md).

Quando você está no **caixa de diálogo** editor, você pode alternar a exibição da **Editor de caixa de diálogo** barra de ferramentas, selecionando-o na lista de barras de ferramentas disponíveis e windows.

### <a name="to-show-or-hide-the-dialog-editor-toolbar"></a>Para mostrar ou ocultar a barra de ferramentas do editor de caixa de diálogo

1. Sobre o **exibição** menu, clique em **barras de ferramentas** , em seguida, escolha **Editor de caixa de diálogo** do submenu.

   > [!NOTE]
   > O **Editor de caixa de diálogo** barra de ferramentas é exibida por padrão, quando você abre um recurso de caixa de diálogo no editor de caixa de diálogo; no entanto, se você fechar explicitamente a barra de ferramentas, você precisará invocá-lo na próxima vez que você abrir um recurso de caixa de diálogo.

Para obter informações sobre como adicionar recursos a projetos gerenciados, consulte [recursos em aplicativos de área de trabalho](/dotnet/framework/resources/index) na *guia do desenvolvedor do .NET Framework*. Para obter informações sobre como adicionar manualmente os arquivos de recursos a projetos gerenciados, acessar recursos, exibir recursos estáticos e atribuir cadeias de caracteres de recurso a propriedades, consulte [criando arquivos de recursos para aplicativos de área de trabalho](/dotnet/framework/resources/creating-resource-files-for-desktop-apps). Para obter informações sobre globalização e localização de recursos em aplicativos gerenciados, consulte [Globalizing e Localizando aplicativos do .NET Framework](/dotnet/standard/globalization-localization/index).

## <a name="requirements"></a>Requisitos

Win32

## <a name="see-also"></a>Consulte também

[Organização de controles em caixas de diálogo](../windows/arrangement-of-controls-on-dialog-boxes.md)<br/>
[Como criar um recurso](../windows/how-to-create-a-resource.md)<br/>
[Arquivos de recurso](../windows/resource-files-visual-studio.md)<br/>
[Editor de caixa de diálogo](../windows/dialog-editor.md)