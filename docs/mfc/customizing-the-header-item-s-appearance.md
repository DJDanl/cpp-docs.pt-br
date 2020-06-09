---
title: Personalizando a aparência do item de cabeçalho&#39;s
ms.date: 11/04/2016
helpviewer_keywords:
- header controls [MFC], customization of items
- CHeaderCtrl class [MFC], customizing the items
- HDS_ styles
ms.assetid: b1e1e326-ec7d-4dbd-a46f-96a3e2055618
ms.openlocfilehash: 8bf1bdad6a0408746b50b6b0dcbecbce308f5ede
ms.sourcegitcommit: c21b05042debc97d14875e019ee9d698691ffc0b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 06/09/2020
ms.locfileid: "84617076"
---
# <a name="customizing-the-header-item39s-appearance"></a>Personalizando a aparência do item de cabeçalho&#39;s

Ao definir o parâmetro *dwStyle* ao criar um controle de cabeçalho ([CHeaderCtrl:: Create](reference/cheaderctrl-class.md#create)) pela primeira vez, você pode definir a aparência e o comportamento dos itens de cabeçalho ou do próprio controle de cabeçalho.

Aqui está uma amostra dos estilos que você pode definir e sua finalidade:

- Para fazer com que um item de cabeçalho pareça um botão de pressão, use o estilo de **HDS_BUTTONS** .

   Use este estilo se você quiser executar ações em resposta a cliques do mouse em um item de cabeçalho, como classificar dados por uma determinada coluna, como é feito no Microsoft Outlook.

- Para dar aos itens de cabeçalho uma aparência de "acompanhamento dinâmico" quando o cursor do mouse passa sobre eles, use o estilo de **HDS_HOTTRACK** .

   O Hot Tracking exibe uma estrutura de tópicos 3D conforme o ponteiro passa sobre um item em uma barra plana de outra forma.

- Para indicar que o controle de cabeçalho deve estar oculto, use o estilo de **HDS_HIDDEN** .

   O estilo **HDS_HIDDEN** indica que o controle de cabeçalho deve ser usado como um contêiner de dados e não um controle visual. Esse estilo não oculta automaticamente o controle, mas, em vez disso, afeta o comportamento de `CHeaderCtrl::Layout` . O valor retornado no membro *CY* da `WINDOWPOS` estrutura será zero, indicando que o controle não deve ser visível para o usuário.

Para obter mais informações sobre essas propriedades, consulte [itens](/windows/win32/Controls/header-controls) no SDK do Windows. Para obter informações sobre como adicionar itens a um controle de cabeçalho, consulte [adicionando itens ao controle de cabeçalho](adding-items-to-the-header-control.md).

## <a name="see-also"></a>Consulte também

[Usando CHeaderCtrl](using-cheaderctrl.md)<br/>
[Controles](controls-mfc.md)
