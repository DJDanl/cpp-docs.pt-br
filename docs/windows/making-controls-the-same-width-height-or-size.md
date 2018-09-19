---
title: Criando controles com a mesma largura, altura ou tamanho | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- Make Same Size command
- controls [C++], sizing
ms.assetid: 94b50613-67e2-497b-a2b6-6d98dccfd345
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: fe7831c12a9ea68525334a55aec5a1fa2ecb847d
ms.sourcegitcommit: 799f9b976623a375203ad8b2ad5147bd6a2212f0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/19/2018
ms.locfileid: "46405106"
---
# <a name="making-controls-the-same-width-height-or-size"></a>Criando controles com a mesma largura, a altura ou o tamanho

Você pode redimensionar um grupo de controles com base no tamanho do controle dominante. Você também pode [redimensionar um controle com base nas dimensões de seu texto de legenda](../windows/sizing-individual-controls.md).

### <a name="to-make-controls-the-same-width-height-or-size"></a>Para tornar controla a mesma largura, altura ou tamanho

1. [Selecione os controles](../windows/selecting-multiple-controls.md) você deseja redimensionar.

   O controle selecionado primeiro da série é o controle dominante. O tamanho final dos controles no grupo depende do tamanho do controle dominante. Para obter mais informações sobre como selecionar o controle dominante, consulte [especificando um controle dominante](../windows/specifying-the-dominant-control.md).

2. Dos **formato** menu, escolha **Igualar tamanho**, em seguida, escolha um dos seguintes comandos:

   - **Ambos**

   - **Altura**

   - **Largura**

Para obter informações sobre como adicionar recursos a projetos gerenciados, consulte [recursos em aplicativos de área de trabalho](/dotnet/framework/resources/index) na *guia do desenvolvedor do .NET Framework*. Para obter informações sobre como adicionar manualmente os arquivos de recursos a projetos gerenciados, acessar recursos, exibir recursos estáticos e atribuir cadeias de caracteres de recurso a propriedades, consulte [criando arquivos de recursos para aplicativos de área de trabalho](/dotnet/framework/resources/creating-resource-files-for-desktop-apps). Para obter informações sobre globalização e localização de recursos em aplicativos gerenciados, consulte [Globalizing e Localizando aplicativos do .NET Framework](/dotnet/standard/globalization-localization/index).

## <a name="requirements"></a>Requisitos

Win32

## <a name="see-also"></a>Consulte também

[Controles em caixas de diálogo](../windows/controls-in-dialog-boxes.md)<br/>
[Controles](../mfc/controls-mfc.md)