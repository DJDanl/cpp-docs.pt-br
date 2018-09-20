---
title: Desenhando linhas ou figuras fechadas (Editor de imagens para ícones) | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- Image editor [C++], drawing lines
- shapes, drawing
ms.assetid: 7edd86db-77b1-451f-8001-bbfed9c6304f
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 0ab40be4843b33e98daaf0f990e10544cb966a7d
ms.sourcegitcommit: 799f9b976623a375203ad8b2ad5147bd6a2212f0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/19/2018
ms.locfileid: "46404378"
---
# <a name="drawing-lines-or-closed-figures-image-editor-for-icons"></a>Desenhando linhas ou figuras fechadas (editor de imagens para ícones)

Ferramentas do editor de imagens para desenhar linhas e de figuras fechadas todos funcionam da mesma forma: colocar o ponto de inserção em um ponto e arraste para outro. Para linhas, esses pontos são os pontos de extremidade. Para figuras fechadas, esses pontos são cantos opostos de um retângulo delimitador a figura.

Linhas são desenhadas em uma determinado pela seleção atual do pincel de largura e são enquadradas figuras são desenhadas em uma largura determinada pela seleção largura atual. Linhas e todas as figuras, enquadrados tanto preenchido, são desenhadas na cor de primeiro plano atual se você pressionar o botão esquerdo do mouse, ou na cor de plano de fundo atual se você pressionar o botão direito do mouse.

### <a name="to-draw-a-line"></a>Para desenhar uma linha

1. Sobre o [barra de ferramentas do Editor de imagens](../windows/toolbar-image-editor-for-icons.md) (ou do **imagem** menu, **ferramentas** comando), clique no **linha** ferramenta.

2. Se necessário, selecione as cores e um pincel:

   - No [paleta de cores](../windows/colors-window-image-editor-for-icons.md), clique no botão esquerdo do mouse para selecionar uma cor de primeiro plano ou o botão direito do mouse para selecionar uma cor de plano de fundo.

   - No [seletor de opções](../windows/toolbar-image-editor-for-icons.md), clique em uma forma que representa o pincel que você deseja usar.

3. Coloque o ponteiro no ponto de partida da linha.

4. Arraste o ponto de extremidade da linha.

### <a name="to-draw-a-closed-figure"></a>Para desenhar uma figura fechada

1. No **Editor de imagens** barra de ferramentas (ou do **imagem** menu, **ferramentas** comando), clique em um **figura fechada desenho** ferramenta.

   O **fechado Figura desenho** ferramentas criam figuras conforme indicado em seus respectivos botões.

2. Se necessário, selecione as cores e uma largura de linha.

3. Mova o ponteiro para um canto da área retangular na qual você deseja desenhar a figura.

4. Arraste o ponteiro para o canto diagonal oposto.

Para obter informações sobre como adicionar recursos a projetos gerenciados, consulte [recursos em aplicativos de área de trabalho](/dotnet/framework/resources/index) na *guia do desenvolvedor do .NET Framework*. Para obter informações sobre como adicionar manualmente os arquivos de recursos a projetos gerenciados, acessar recursos, exibir recursos estáticos e atribuir cadeias de caracteres de recurso a propriedades, consulte [criando arquivos de recursos para aplicativos de área de trabalho](/dotnet/framework/resources/creating-resource-files-for-desktop-apps). Para obter informações sobre globalização e localização de recursos em aplicativos gerenciados, consulte [Globalizing e Localizando aplicativos do .NET Framework](/dotnet/standard/globalization-localization/index).

## <a name="requirements"></a>Requisitos

Nenhum

## <a name="see-also"></a>Consulte também

[Teclas de aceleração](../windows/accelerator-keys-image-editor-for-icons.md)<br/>
[Editando recursos gráficos](../windows/editing-graphical-resources-image-editor-for-icons.md)<br/>
[Editor de imagens para ícones](../windows/image-editor-for-icons.md)<br/>
[Trabalhando com cor](../windows/working-with-color-image-editor-for-icons.md)