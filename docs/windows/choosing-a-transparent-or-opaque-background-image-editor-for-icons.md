---
title: Escolhendo uma tela de fundo transparente ou opaco (editor de imagens para ícones)
ms.date: 11/19/2018
helpviewer_keywords:
- opaque backgrounds [C++]
- colors [C++], image
- Image editor [C++], transparent or opague backgrounds
- images [C++], transparency
- images [C++], opaque background
ms.assetid: 61b743d9-c86b-405d-9a81-0806431b4363
ms.openlocfilehash: ceea31b998d5c4dca52657db570ace664f7e373f
ms.sourcegitcommit: 9e891eb17b73d98f9086d9d4bfe9ca50415d9a37
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 11/20/2018
ms.locfileid: "52175425"
---
# <a name="choosing-a-transparent-or-opaque-background-image-editor-for-icons"></a>Escolhendo uma tela de fundo transparente ou opaco (editor de imagens para ícones)

Quando você move ou copia uma seleção de uma imagem, os pixels da seleção que correspondem à cor do plano de fundo atual são, por padrão, de forma transparente; eles não obscurecem pixels no local de destino.

Você pode alternar de um plano de fundo transparente (o padrão) para um plano de fundo opaco e vice-versa. Quando você usa uma ferramenta de seleção, o **plano de fundo transparente** e **tela de fundo opaca** opções aparecem no **opção** seletor do **doEditordeimagens** barra de ferramentas (conforme mostrado abaixo).

![Opções de plano de fundo &#45; opaca ou transparente](../windows/media/vcimageeditoropaqtranspback.gif "opções de plano de fundo &#45; opaca ou transparente")<br/>
**Opções de transparentes e opacas** sobre o **barra de ferramentas do Editor de imagens**

### <a name="to-switch-between-a-transparent-and-opaque-background"></a>Para alternar entre um plano de fundo transparente e opaco

1. No **Editor de imagens** barra de ferramentas, clique no **opção** seletor e, em seguida, clique em segundo plano apropriado:

   - `Opaque Background (O)`: Imagem existente é obscurecida por todas as partes da seleção.

   - `Transparent Background (T)`: Imagem existente mostra por meio de partes da seleção que correspondem à cor do plano de fundo atual.

   \- ou -

1. Sobre o **imagem** menu, marque ou desmarque **desenho opaco**.

Você pode alterar a cor do plano de fundo enquanto uma seleção já estiver em vigor para alterar quais partes da imagem são transparentes.

Para obter informações sobre como adicionar recursos a projetos gerenciados, consulte [recursos em aplicativos de área de trabalho](/dotnet/framework/resources/index) na *guia do desenvolvedor do .NET Framework*. Para obter informações sobre como adicionar manualmente os arquivos de recursos a projetos gerenciados, acessar recursos, exibir recursos estáticos e atribuir cadeias de caracteres de recurso a propriedades, consulte [criando arquivos de recursos para aplicativos de área de trabalho](/dotnet/framework/resources/creating-resource-files-for-desktop-apps). Para obter informações sobre globalização e localização de recursos em aplicativos gerenciados, consulte [Globalizing e Localizando aplicativos do .NET Framework](/dotnet/standard/globalization-localization/index).

## <a name="requirements"></a>Requisitos

Nenhum

## <a name="see-also"></a>Consulte também

[Teclas de aceleração](../windows/accelerator-keys-image-editor-for-icons.md)<br/>
[Trabalhando com cor](../windows/working-with-color-image-editor-for-icons.md)