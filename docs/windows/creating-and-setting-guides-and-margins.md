---
title: Criando e definindo guias e margens | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- guides, clearing
- guides
- Dialog Editor [C++], guides and margins
- dialog box controls [C++], placement
- controls [C++], guides and margins
- guides, creating
- guides, moving
- margins, moving
ms.assetid: fafa4545-8f00-436f-b590-300e76601156
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 0083affb850f35941ca18709785c9bd5e4fc35e8
ms.sourcegitcommit: 799f9b976623a375203ad8b2ad5147bd6a2212f0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/19/2018
ms.locfileid: "46378248"
---
# <a name="creating-and-setting-guides-and-margins"></a>Criando e definindo guias e margens

Se você estiver movendo controles, adicionando controles ou reorganizando um layout atual, guias de podem ajudar a alinhar controles com precisão dentro de uma caixa de diálogo. Guias são exibidas como azul pontilhada entre a caixa de diálogo exibida no editor e setas correspondentes nas réguas (na parte superior e o lado esquerdo dos **caixa de diálogo** editor).

Quando você cria uma caixa de diálogo, são fornecidas as quatro margens. As margens são modificadas guias, que aparecem como linhas pontilhadas azuis.

### <a name="to-create-a-guide"></a>Para criar uma guia

1. Dentro da régua, clique uma vez para criar uma guia. (Um clique cria uma nova guia; clicar duas vezes em lançamentos a [guia de caixa de diálogo de configurações](../windows/guide-settings-dialog-box.md) na qual você pode especificar configurações do guia.)

### <a name="to-set-a-guide"></a>Para definir um guia

1. Na caixa de diálogo, clique na guia e arraste-o para uma nova posição. (Você também pode clicar na seta na régua à arraste a guia associada).

   As coordenadas do guia são exibidas na barra de status na parte inferior da janela e na régua. Mova o ponteiro sobre a seta na régua para exibir a posição exata do guia.

### <a name="to-delete-a-guide"></a>Para excluir uma guia

1. Arraste a guia fora da caixa de diálogo.

\- ou -

- Arraste a seta correspondente fora da régua.

### <a name="to-move-margins"></a>Para mover as margens

1. Arraste a margem para a nova posição.

   Para tornar uma margem desaparecer, mova a margem para uma posição zero. Para trazer de volta a margem, coloque o ponteiro sobre a margem posição zero e mover a margem para a posição.

Para obter informações sobre como adicionar recursos a projetos gerenciados, consulte [recursos em aplicativos de área de trabalho](/dotnet/framework/resources/index) na *guia do desenvolvedor do .NET Framework*. Para obter informações sobre como adicionar manualmente os arquivos de recursos a projetos gerenciados, acessar recursos, exibir recursos estáticos e atribuir cadeias de caracteres de recurso a propriedades, consulte [criando arquivos de recursos para aplicativos de área de trabalho](/dotnet/framework/resources/creating-resource-files-for-desktop-apps). Para obter informações sobre globalização e localização de recursos em aplicativos gerenciados, consulte [Globalizing e Localizando aplicativos do .NET Framework](/dotnet/standard/globalization-localization/index).

## <a name="requirements"></a>Requisitos

Win32

## <a name="see-also"></a>Consulte também

[Estados do Editor de Caixa de Diálogo (guias e grades)](../windows/dialog-editor-states-guides-and-grids.md)<br/>
[Controles em caixas de diálogo](../windows/controls-in-dialog-boxes.md)