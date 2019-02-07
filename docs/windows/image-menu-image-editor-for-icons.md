---
title: Menu imagem (Editor de C++ imagens para ícones)
ms.date: 11/04/2016
f1_keywords:
- vc.editors.bitmap
- vc.editors.dialog.GridSettings
- vc.editors.gridsettings
helpviewer_keywords:
- Image menu
- Grid Settings dialog box [C++]
ms.assetid: ac2b4d53-1919-4fd1-a0af-d3c085c45af2
ms.openlocfilehash: e7d7d92401d5910cbb8aba8ab4c6000eca45cb01
ms.sourcegitcommit: bd637e9c39650cfd530520ea978a22fa4caa0e42
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/07/2019
ms.locfileid: "55849724"
---
# <a name="image-menu-c-image-editor-for-icons"></a>Menu imagem (Editor de C++ imagens para ícones)

O **imagem** menu, que é exibido apenas quando o **imagem** editor está ativo, tem comandos para edição de imagens, gerenciando paletas de cores e definindo **Editor de imagens** janela Opções. Além disso, os comandos para o uso de imagens de dispositivo estão disponíveis ao trabalhar com ícones e cursores.

|Comando|Descrição|
|---|---|
|**Inverter cores**|Inverte suas cores. Para obter mais informações, consulte [invertendo as cores em uma seleção](../windows/inverting-the-colors-in-a-selection-image-editor-for-icons.md).|
|**Inverter Horizontalmente**|Inverte a imagem ou seleção horizontalmente. Para obter mais informações, consulte [invertendo uma imagem](../windows/flipping-an-image-image-editor-for-icons.md).|
|**Inverter Verticalmente**|Inverte a imagem ou seleção verticalmente. Para obter mais informações, consulte [invertendo uma imagem](../windows/flipping-an-image-image-editor-for-icons.md).|
|**Girar 90 graus**|A imagem ou seleção gira 90 graus. Para obter mais informações, consulte [invertendo uma imagem](../windows/flipping-an-image-image-editor-for-icons.md).|
|**Mostrar janela de cores**|Abre o [janela de cores](../windows/colors-window-image-editor-for-icons.md), no qual você pode escolher as cores a ser usado para sua imagem. Para obter mais informações, consulte [trabalhando com cor](../windows/working-with-color-image-editor-for-icons.md).|
|**Usar seleção como Pincel**|Permite que você crie um pincel personalizado de uma parte de uma imagem. Sua seleção torna-se um pincel personalizado que distribui as cores na seleção entre a imagem. Cópias da seleção são deixadas ao longo do caminho de arrastamento. Quanto mais lentamente do que você arrastar, são feitas as cópias mais. Para obter mais informações, consulte [criando um pincel personalizado](../windows/creating-a-custom-brush-image-editor-for-icons.md).|
|**Cópia e a seleção de estrutura de tópicos**|Cria uma cópia da seleção atual e a contorna. Se a cor do plano de fundo estiver contida na seleção atual, ela será excluída se você já [transparente](../windows/choosing-a-transparent-or-opaque-background-image-editor-for-icons.md) selecionado.
|**Ajustar cores**|Abre o [seletor de cores personalizada](../windows/custom-color-selector-dialog-box-image-editor-for-icons.md), que permite que você personalize as cores que você pode usar para sua imagem. Para obter mais informações, consulte [personalizando ou alterando cores](../windows/customizing-or-changing-colors-image-editor-for-icons.md).|
|**Carregar paleta**|Abre o [caixa de diálogo Carregar paleta de cores](../windows/load-palette-colors-dialog-box-image-editor-for-icons.md), que permite que você carregar cores de paleta salvas anteriormente para um arquivo. PAL.|
|**Salvar paleta**|Salva a paleta de cores em um arquivo. PAL.|
|**Desenhar opaco**|Quando selecionada, torna a seleção atual opaca. Quando desmarcada, torna transparente a seleção atual. Para obter mais informações, consulte [escolher um plano de fundo transparente ou um opaco](../windows/choosing-a-transparent-or-opaque-background-image-editor-for-icons.md).|
|**Editor de barra de ferramentas**|Abre o [caixa de diálogo novo recurso da barra de ferramentas](../windows/new-toolbar-resource-dialog-box.md).|
|**Configurações da grade**|Abre o **configurações da grade** caixa de diálogo na qual você pode especificar grades para sua imagem.|
|**Novo tipo de imagem**|Abre o [New \<dispositivo > caixa de diálogo de tipo de imagem](../windows/new-device-image-type-dialog-box-image-editor-for-icons.md). Um recurso de ícone único pode conter várias imagens de tamanhos diferentes e windows podem usar o tamanho de ícone apropriado, dependendo de como ela será a ser exibido. Um novo tipo de dispositivo não modifica o tamanho do ícone, mas em vez disso, cria uma nova imagem dentro do ícone. Aplica-se somente a ícones e cursores.|
|**Tipo de imagem de ícone/Cursor atual**|Abre um submenu que lista os primeiro ícone ou cursor de imagens disponíveis (os primeiros nove). O último comando no submenu, **mais...** , abre o [aberto \<dispositivo > caixa de diálogo imagem](../windows/open-device-image-dialog-box-image-editor-for-icons.md).|
|**Excluir tipo de imagem**|Exclui a imagem do dispositivo selecionado.|
|**Ferramentas**|Inicia um submenu que contém todas as ferramentas disponíveis a partir de [barra de ferramentas do Editor de imagens](../windows/toolbar-image-editor-for-icons.md).|

O **configurações da grade** caixa de diálogo permite que você especifique as configurações de grade para a sua imagem e exibe linhas de grade sobre a imagem editada. As linhas são úteis para a imagem de edição, mas não são salvas como parte da imagem em si.

|Propriedade|Descrição|
|---|---|
|**Grade de pixels**|Quando marcada, exibe uma grade em torno de cada pixel no editor de imagem. A grade aparece apenas em 4 × e resoluções mais altas.|
|**Grade lado a lado**|Quando selecionado, exibe uma grade de blocos de pixels no editor de imagens, especificado pelos valores de espaçamento da grade.|
|**Largura**|Especifica a largura de cada bloco lado a lado. Essa propriedade é útil ao desenhar bitmaps que contém várias imagens são organizadas em intervalos regulares.|
|**Altura**|Especifica a altura de cada bloco lado a lado. Essa propriedade é útil ao desenhar bitmaps que contém várias imagens são organizadas em intervalos regulares.|

## <a name="requirements"></a>Requisitos

Nenhum

## <a name="see-also"></a>Consulte também

[Teclas de aceleração](../windows/accelerator-keys-image-editor-for-icons.md)<br/>
[Redimensionando uma imagem](../windows/resizing-an-image-image-editor-for-icons.md)<br/>
[Editor de imagens para ícones](../windows/image-editor-for-icons.md)