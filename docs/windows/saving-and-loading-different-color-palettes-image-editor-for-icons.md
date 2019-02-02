---
title: Salvando e carregando paletas de cores diferentes (editor de imagens para ícones)
ms.date: 11/04/2016
f1_keywords:
- vc.editors.image.color
- vc.editors.loadcolorpalette
helpviewer_keywords:
- color palettes [C++]
- palettes
- palettes, Image editor
- colors [C++], Image editor
- Image editor [C++], palettes
- color palettes
- Load Palette Colors dialog box [C++]
ms.assetid: 694b6346-e606-4f19-aa01-9b4ceb47f423
ms.openlocfilehash: fd2664407d33d8e3ed594921501b7f80e6c8850b
ms.sourcegitcommit: efcc8c97570ddf7631570226c700e8f6ebb6c7be
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/01/2019
ms.locfileid: "55560264"
---
# <a name="saving-and-loading-different-color-palettes-image-editor-for-icons"></a>Salvando e carregando paletas de cores diferentes (editor de imagens para ícones)

Você pode salvar e carregar um **cores** paleta que contém [personalizado de cores](../windows/customizing-or-changing-colors-image-editor-for-icons.md). (Por padrão, o **cores** paleta usada mais recentemente é carregada automaticamente quando você inicia o Visual Studio.)

> [!TIP]
> Uma vez que o **imagem** editor não tem meios para restaurar o padrão **cores** paleta, você deve salvar o padrão **cores** paleta sob um nome como  *Standard.PAL* ou *default.pal* para que você possa facilmente restaurar as configurações padrão.

Use o **carregar cores de paleta** caixa de diálogo Carregar paletas de cores especiais para usar no projeto do C++. As propriedades a seguir incluídas são:

|Propriedade|Descrição|
|---|---|
|**Examinar**|Especifica o local onde você deseja localizar um arquivo ou pasta. Selecione a seta para escolher outro local, ou selecione o ícone de pasta na barra de ferramentas para mover para cima níveis.|
|**Nome do arquivo**|Fornece um espaço para você digitar o nome do arquivo que você deseja abrir. Para localizar rapidamente um arquivo aberto anteriormente, selecione o nome do arquivo na lista suspensa, se disponível.<br/><br/>Se você estiver procurando por um arquivo, você pode usar asteriscos (*) como caracteres curinga. Por exemplo, você pode digitar \*.\* para ver uma lista de todos os arquivos. Você também pode digitar o caminho completo de um arquivo, por exemplo, C:\My Documents\MyColorPalette.pal ou \\\NetworkServer\MyFolder\MyColorPalette.pal.|
|**Arquivos de tipo**|Lista os tipos de arquivos a serem exibidos. Paleta (*. PAL) é o tipo de arquivo padrão para paletas de cores.|

## <a name="to-save-a-custom-colors-palette"></a>Para salvar uma paleta de cores personalizadas

1. Dos **imagem** menu, escolha **Salvar paleta**.

1. Navegue até o diretório onde você deseja salvar a paleta e digite um nome para a paleta.

1. Selecione **Salvar**.

## <a name="to-load-a-custom-colors-palette"></a>Para carregar uma paleta de cores personalizadas

1. Dos **imagem** menu, escolha **carregar paleta**.

1. No **carregar paleta de cores** caixa de diálogo caixa, navegue até o diretório correto e selecione a paleta que você deseja carregar. **Cor** paletas são salvos com uma extensão de arquivo. PAL.

## <a name="requirements"></a>Requisitos

Nenhum

## <a name="see-also"></a>Consulte também

[Teclas de aceleração](../windows/accelerator-keys-image-editor-for-icons.md)<br/>
[Trabalhando com cor](../windows/working-with-color-image-editor-for-icons.md)<br/>
[Editor de imagens para ícones](../windows/image-editor-for-icons.md)