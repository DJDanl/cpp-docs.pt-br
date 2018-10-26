---
title: Personalizando o Item de cabeçalho&#39;aparência s | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- header controls [MFC], customization of items
- CHeaderCtrl class [MFC], customizing the items
- HDS_ styles
ms.assetid: b1e1e326-ec7d-4dbd-a46f-96a3e2055618
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 75e32021420848e7493d9652bb37cb12fa4df56b
ms.sourcegitcommit: a9dcbcc85b4c28eed280d8e451c494a00d8c4c25
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/25/2018
ms.locfileid: "50055457"
---
# <a name="customizing-the-header-item39s-appearance"></a>Personalizando o Item de cabeçalho&#39;s aparência

Definindo o *dwStyle* parâmetro quando você cria um controle de cabeçalho ([CHeaderCtrl::Create](../mfc/reference/cheaderctrl-class.md#create)), você pode definir a aparência e comportamento do cabeçalho de itens ou do cabeçalho de controle em si.

Aqui está uma amostragem dos estilos que podem ser definidas e sua finalidade:

- Para fazer com que um item de cabeçalho se parecer com um botão de ação, use o **HDS_BUTTONS** estilo.

   Use esse estilo se você quiser executar ações em resposta a cliques do mouse em um item de cabeçalho, como classificar dados por uma coluna específica, como é feito no Microsoft Outlook.

- Para fornecer os itens de cabeçalho uma aparência "rastreio importante" quando o cursor do mouse passa sobre eles, use o **HDS_HOTTRACK** estilo.

   Rastreio importante exibe uma estrutura de tópicos 3D quando o ponteiro passa sobre um item em uma outra forma simples barra.

- Para indicar que o controle de cabeçalho deve ser ocultado, use o **HDS_HIDDEN** estilo.

   O **HDS_HIDDEN** estilo indica que o controle de cabeçalho é destinado a ser usado como um contêiner de dados e não um controle visual. Esse estilo não oculta o controle automaticamente, mas, em vez disso, afeta o comportamento de `CHeaderCtrl::Layout`. O valor retornado na *cy* membro do `WINDOWPOS` estrutura será zero que indica que o controle não deve ser visível para o usuário.

Para obter mais informações sobre essas propriedades, consulte [itens](/windows/desktop/Controls/header-controls) no SDK do Windows. Para obter informações sobre como adicionar itens a um controle de cabeçalho, consulte [adicionando itens ao controle de cabeçalho](../mfc/adding-items-to-the-header-control.md).

## <a name="see-also"></a>Consulte também

[Usando CHeaderCtrl](../mfc/using-cheaderctrl.md)<br/>
[Controles](../mfc/controls-mfc.md)

