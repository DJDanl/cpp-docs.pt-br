---
title: Editor da barra de ferramentas | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: conceptual
f1_keywords:
- vc.editors.toolbar.F1
dev_langs:
- C++
helpviewer_keywords:
- resource editors, Toolbar editor
- editors, toolbars
- toolbars [C++], editing
- Toolbar editor
ms.assetid: aa9f0adf-60f6-4f79-ab05-bc330f15ec43
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 997fb10b9bbe54eb26fb2e54bf7a4892dab9b189
ms.sourcegitcommit: 6f8dd98de57bb80bf4c9852abafef1c35a7600f1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/22/2018
ms.locfileid: "42590750"
---
# <a name="toolbar-editor"></a>Editor de Barra de Ferramentas

O **barra de ferramentas** editor permite que você criar recursos de barra de ferramentas e converter os bitmaps para os recursos da barra de ferramentas. O **barra de ferramentas** editor usa uma exibição gráfica para mostrar uma barra de ferramentas e botões que se assemelhem como eles aparecerão em um aplicativo concluído.

Com o **barra de ferramentas** editor, você pode:

- [Criar novas barras de ferramentas e botões](../windows/creating-new-toolbars.md)

- [Converter bitmaps em recursos da barra de ferramentas](../windows/converting-bitmaps-to-toolbars.md)

- [Criar, mover e editar os botões de barra de ferramentas](../windows/creating-moving-and-editing-toolbar-buttons.md)

- [Criar dicas de ferramenta](../windows/creating-a-tool-tip-for-a-toolbar-button.md)

O **barra de ferramentas** janela do editor mostra dois modos de exibição de uma imagem de botão, o mesmo que a janela do editor de imagem. Uma barra de divisão separa os dois painéis. Você pode arrastar a barra de divisão de um lado para o outro para alterar o tamanho relativo dos painéis. O painel ativo exibe uma borda de seleção. Acima de dois modos de exibição da imagem é a barra de ferramentas do assunto.

![Barra de ferramentas do Editor](../mfc/media/vctoolbareditor.gif "vcToolbarEditor")  
Editor de Barra de Ferramentas

O **barra de ferramentas** editor é semelhante ao **imagem** editor na funcionalidade. Os itens de menu, ferramentas gráficas e grade de bitmap são iguais do **imagem** editor. Há um comando de menu na **imagem** menu para permitir que você alterne entre a **barra de ferramentas** editor e o **imagem** editor. Para obter mais informações sobre como usar o **gráficos** barra de ferramentas **cores** paleta, ou **imagem** menu, consulte [Editor de imagens](../windows/image-editor-for-icons.md).

Para obter informações sobre como adicionar recursos a projetos gerenciados, consulte [recursos em aplicativos de área de trabalho](/dotnet/framework/resources/index) na *guia do desenvolvedor do .NET Framework*. Para obter informações sobre como adicionar manualmente os arquivos de recursos a projetos gerenciados, acessar recursos, exibir recursos estáticos e atribuir cadeias de caracteres de recurso a propriedades, consulte [criando arquivos de recursos para aplicativos de área de trabalho](/dotnet/framework/resources/creating-resource-files-for-desktop-apps). Para obter informações sobre globalização e localização de recursos em aplicativos gerenciados, consulte [Globalizing e Localizando aplicativos do .NET Framework](/dotnet/standard/globalization-localization/index).

## <a name="requirements"></a>Requisitos

MFC ou ATL

## <a name="see-also"></a>Consulte também

[Editores de recursos](../windows/resource-editors.md)  
[Menus e outros recursos](http://msdn.microsoft.com/library/windows/desktop/ms632583.aspx)