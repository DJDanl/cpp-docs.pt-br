---
title: Salvando e carregando diferentes (Editor de imagens para ícones) de paletas de cores | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: conceptual
f1_keywords:
- vc.editors.image.color
dev_langs:
- C++
helpviewer_keywords:
- color palettes [C++]
- palettes
- palettes, Image editor
- colors [C++], Image editor
- Image editor [C++], palettes
ms.assetid: 694b6346-e606-4f19-aa01-9b4ceb47f423
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 50e74c65e080b11583e6ff1e591ef612b17e9533
ms.sourcegitcommit: 799f9b976623a375203ad8b2ad5147bd6a2212f0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/19/2018
ms.locfileid: "46438880"
---
# <a name="saving-and-loading-different-color-palettes-image-editor-for-icons"></a>Salvando e carregando paletas de cores diferentes (editor de imagens para ícones)

Você pode salvar e carregar um **cores** paleta que contém [personalizado de cores](../windows/customizing-or-changing-colors-image-editor-for-icons.md). (Por padrão, o **cores** paleta usada mais recentemente é carregada automaticamente quando você inicia o Visual Studio.)

> [!TIP]
> Uma vez que o **imagem** editor não tem meios para restaurar o padrão **cores** paleta, você deve salvar o padrão **cores** paleta sob um nome como  *Standard.PAL* ou *default.pal* para que você possa facilmente restaurar as configurações padrão.

### <a name="to-save-a-custom-colors-palette"></a>Para salvar uma paleta de cores personalizadas

1. Dos **imagem** menu, escolha **Salvar paleta**.

2. Navegue até o diretório onde você deseja salvar a paleta e digite um nome para a paleta.

3. Clique em **Salvar**.

### <a name="to-load-a-custom-colors-palette"></a>Para carregar uma paleta de cores personalizadas

1. Dos **imagem** menu, escolha **carregar paleta**.

2. No [caixa de diálogo Carregar paleta de cores](../windows/load-palette-colors-dialog-box-image-editor-for-icons.md), navegue até o diretório correto e selecione a paleta que você deseja carregar. **Cor** paletas são salvos com uma extensão de arquivo. PAL.

## <a name="requirements"></a>Requisitos

Nenhum

## <a name="see-also"></a>Consulte também

[Teclas de aceleração](../windows/accelerator-keys-image-editor-for-icons.md)<br/>
[Trabalhando com cor](../windows/working-with-color-image-editor-for-icons.md)