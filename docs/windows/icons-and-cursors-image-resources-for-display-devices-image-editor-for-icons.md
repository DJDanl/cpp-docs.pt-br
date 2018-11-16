---
title: 'Ícones e cursores: recursos de imagem para exibir dispositivos (C++ Editor de imagens para ícones)'
ms.date: 11/04/2016
f1_keywords:
- vc.editors.icon
helpviewer_keywords:
- cursors [C++], creating
- image resources [C++], display devices
- icons [C++], creating
- cursors [C++], types
- icons [C++]
- Image editor [C++], icons and cursors
- cursors [C++]
- display devices [C++], creating icons for
- cursors [C++], hot spots
- icons [C++], types
ms.assetid: 8f0809a8-0cf0-4da9-b23d-51f28bf15f5b
ms.openlocfilehash: 91de1351b3e41701d302d290533b60d4fe791b80
ms.sourcegitcommit: b032daf81cb5fdb1f5a988277ee30201441c4945
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 11/15/2018
ms.locfileid: "51693003"
---
# <a name="icons-and-cursors-image-resources-for-display-devices-c-image-editor-for-icons"></a>Ícones e cursores: recursos de imagem para exibir dispositivos (C++ Editor de imagens para ícones)

Ícones e cursores são os recursos gráficos que podem conter várias imagens em tamanhos diferentes e esquemas para diferentes tipos de dispositivos de exibição de cores. Além disso, um cursor tem um "ponto de acesso", o local do Windows usa para acompanhar sua posição. Ícones e cursores são criados e editados usando o **imagem** editor, assim como bitmaps e outras imagens.

Quando você cria um novo ícone ou cursor, o **imagem** editor primeiro cria uma imagem de um tipo padrão. Inicialmente, a imagem é preenchida com a cor da tela (transparente). Se a imagem é um cursor, o ponto de acesso é inicialmente o canto superior esquerdo (coordenadas 0,0).

Por padrão, o **imagem** editor dá suporte à criação de imagens adicionais para os dispositivos mostrados na tabela a seguir. Você pode criar imagens para outros dispositivos, digitando parâmetros de largura, altura e contagem de cor para o [caixa de diálogo imagem personalizada](custom-image-dialog-box-image-editor-for-icons.md).

> [!NOTE]
> Usando o **Editor de imagens**, você pode exibir imagens de 32 bits, mas você não pode editá-los.

|Cor|Largura (pixels)|Altura (pixels)|
|-----------|----------------------|-----------------------|
|Monocromo|16|16|
|Monocromo|32|32|
|Monocromo|48|48|
|Monocromo|64|64|
|Monocromo|96|96|
|16|16|16|
|16|32|32|
|16|64|64|
|16|48|48|
|16|96|96|
|256|16|16|
|256|32|32|
|256|48|48|
|256|64|64|
|256|96|96|

- [Criar uma nova imagem de dispositivo (ícone ou Cursor)](../windows/creating-a-device-image-image-editor-for-icons.md)

- [Adicionando uma imagem para um dispositivo de vídeo diferente](../windows/adding-an-image-for-a-different-display-device-image-editor-for-icons.md)

- [Copiar uma imagem do dispositivo](../windows/copying-a-device-image-image-editor-for-icons.md)

- [Excluir uma imagem de dispositivo](../windows/deleting-a-device-image-image-editor-for-icons.md)

- [Criando regiões transparentes ou inversas em imagens de dispositivo](../windows/creating-transparent-or-inverse-regions-in-device-images.md)

- [Criando um ícone de 256 cores ou um Cursor](creating-a-256-color-icon-or-cursor-image-editor-for-icons.md)

- [Definindo o ponto de acesso de um Cursor](../windows/setting-a-cursor-s-hot-spot-image-editor-for-icons.md)

Para obter informações sobre como adicionar recursos a projetos gerenciados, consulte [recursos em aplicativos de área de trabalho](/dotnet/framework/resources/index) na *guia do desenvolvedor do .NET Framework*. Para obter informações sobre como adicionar manualmente os arquivos de recursos a projetos gerenciados, acessar recursos, exibir recursos estáticos e atribuir cadeias de caracteres de recurso a propriedades, consulte [criando arquivos de recursos para aplicativos de área de trabalho](/dotnet/framework/resources/creating-resource-files-for-desktop-apps). Para obter informações sobre globalização e localização de recursos em aplicativos gerenciados, consulte [Globalizing e Localizando aplicativos do .NET Framework](/dotnet/standard/globalization-localization/index).

## <a name="requirements"></a>Requisitos

Nenhum

## <a name="see-also"></a>Consulte também

[Editor de imagens para ícones](../windows/image-editor-for-icons.md)<br/>
[Ícones](/windows/desktop/menurc/icons)<br/>
[Cursores](/windows/desktop/menurc/cursors)