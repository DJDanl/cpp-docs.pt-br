---
title: Caixa de diálogo novo recurso de barra de ferramentas (C++) | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: conceptual
f1_keywords:
- vc.editors.newtoolbarresource
dev_langs:
- C++
helpviewer_keywords:
- New Toolbar Resource dialog box [C++]
ms.assetid: 52dd01ad-e748-4ab2-b3eb-59f5df990ca6
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 6ca09463a2934db0097c09d6a4f928f108fd0760
ms.sourcegitcommit: f0c90000125a9497bf61e41624de189a043703c0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/10/2018
ms.locfileid: "44316296"
---
# <a name="new-toolbar-resource-dialog-box-c"></a>Caixa de diálogo novo recurso de barra de ferramentas (C++)

O **novos recursos da barra de ferramentas** caixa de diálogo permite que você especifique a largura e altura dos botões que você está adicionando a um recurso da barra de ferramentas em um projeto C++. O padrão é 16 × 15 pixels.

Um bitmap que é usado para criar uma barra de ferramentas tem uma largura máxima de 2048. Portanto, se você definir a **largura do botão** para 512, você só pode ter quatro botões. Se você definir a largura como 513, você só pode ter três botões.

### <a name="button-width"></a>Largura do botão

Fornece um espaço para que você insira a largura para os botões de barra de ferramentas que você está convertendo de um recurso de bitmap para um recurso da barra de ferramentas. As imagens são cortadas para a largura e altura especificadas e as cores são ajustadas para usar cores da barra de ferramentas padrão (16 cores).

### <a name="button-height"></a>Altura do botão

Fornece um espaço para que você insira a altura dos botões de barra de ferramentas que você está convertendo de um recurso de bitmap para um recurso da barra de ferramentas. As imagens são cortadas para a largura e altura especificadas e as cores são ajustadas para usar cores da barra de ferramentas padrão (16 cores).

Para obter informações sobre como adicionar recursos a projetos gerenciados, consulte [recursos em aplicativos de área de trabalho](/dotnet/framework/resources/index) na *guia do desenvolvedor do .NET Framework*. Para obter informações sobre como adicionar manualmente os arquivos de recursos a projetos gerenciados, acessar recursos, exibir recursos estáticos e atribuir cadeias de caracteres de recurso a propriedades, consulte [criando arquivos de recursos para aplicativos de área de trabalho](/dotnet/framework/resources/creating-resource-files-for-desktop-apps). Para obter informações sobre globalização e localização de recursos em aplicativos gerenciados, consulte [Globalizing e Localizando aplicativos do .NET Framework](/dotnet/standard/globalization-localization/index).

## <a name="requirements"></a>Requisitos

MFC ou ATL

## <a name="see-also"></a>Consulte também

[Propriedades do botão de barra de ferramentas](../windows/toolbar-button-properties.md)  
[Convertendo bitmaps em barras de ferramentas](../windows/converting-bitmaps-to-toolbars.md)  
[Editor de barra de ferramentas](../windows/toolbar-editor.md)