---
title: Criando a imagem de um dispositivo (editor de imagens para ícones)
ms.date: 11/04/2016
f1_keywords:
- vc.editors.icon
- vc.editors.newimagetype
- vc.editors.customimage
- vc.editors.opendeviceimage
helpviewer_keywords:
- cursors [C++], creating
- icons [C++], creating
- display devices [C++], creating image
- images [C++], creating for display devices
- icons [C++], inserting
- New <Device> Image Type dialog box [C++]
- Custom Image dialog box [C++]
- Open <Device> Image dialog box [C++]
ms.assetid: 5a536928-32df-4ace-beb1-1521ce3b871f
ms.openlocfilehash: ce1069f6f410d7a60d631461086ca8870ef679c0
ms.sourcegitcommit: efcc8c97570ddf7631570226c700e8f6ebb6c7be
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/01/2019
ms.locfileid: "55560290"
---
# <a name="creating-a-device-image-image-editor-for-icons"></a>Criando a imagem de um dispositivo (editor de imagens para ícones)

Quando você cria um novo ícone ou cursor, o **imagem** editor primeiro cria uma imagem em um estilo específico (32 × 32, 16 cores para ícones e 32 × 32, monocromo para cursores). Você pode, em seguida, adicionar imagens em tamanhos diferentes e estilos para o ícone inicial ou o cursor e edite cada imagem adicional, conforme necessário, para os dispositivos de exibição diferentes. Você também pode editar uma imagem usando uma operação de copiar e colar a partir de um tipo de imagem existente ou um bitmap criado em um programa de gráfico.

Quando você abre o recurso de ícone ou cursor na [editor de imagens](../windows/image-editor-for-icons.md), a imagem a maioria dos combinar o dispositivo de exibição atual é aberta por padrão.

Para obter informações sobre como adicionar recursos a projetos gerenciados, consulte [recursos em aplicativos de área de trabalho](/dotnet/framework/resources/index) na *guia do desenvolvedor do .NET Framework*. Para obter informações sobre como adicionar manualmente os arquivos de recursos a projetos gerenciados, acessar recursos, exibir recursos estáticos e atribuir cadeias de caracteres de recurso a propriedades, consulte [criando arquivos de recursos para aplicativos de área de trabalho](/dotnet/framework/resources/creating-resource-files-for-desktop-apps). Para obter informações sobre globalização e localização de recursos em aplicativos gerenciados, consulte [Globalizing e Localizando aplicativos do .NET Framework](/dotnet/standard/globalization-localization/index).

## <a name="new-ltdevicegt-image-type-dialog-box"></a>Novos &lt;dispositivo&gt; caixa de diálogo de tipo de imagem

O **New &lt;dispositivo&gt; tipo de imagem** caixa de diálogo permite que você crie uma nova imagem de dispositivo de um tipo especificado. Para abrir o **New \<dispositivo > imagem** caixa de diálogo, selecione **novo tipo de imagem** sobre a **imagem** menu. As seguintes propriedades incluídas estão **tipo de imagem de destino** e **personalizado**.

### <a name="target-image-type"></a>Tipo de imagem de destino

Lista os tipos de imagem disponível. Selecione o tipo de imagem que você deseja abrir:

||||
|-|-|-|
|– 16 x 16, 16 cores|-48 x 48, 16 cores|-96 x 96, 16 cores|
|– 16 x 16, 256 cores|-48 x 48, 256 cores|-96 x 96, 256 cores|
|– 16 x 16, monocromo|-48 x 48, monocromo|-96 x 96, monocromo|
|-32 x 32, 16 cores|-64 x 64, 16 cores||
|-32 x 32, 256 cores|-64 x 64, 256 cores||
|-32 x 32, monocromo|-64 x 64, monocromo||

> [!NOTE]
> Todas as imagens existentes não serão exibidas nessa lista.

### <a name="custom"></a>Personalizado

Abre o **imagem personalizada** caixa de diálogo na qual você pode criar uma nova imagem com um tamanho personalizado e o número de cores.

O **imagem personalizada** caixa de diálogo permite que você crie uma nova imagem com um tamanho personalizado e o número de cores. As propriedades a seguir incluídas são:

|Propriedade|Descrição|
|---|---|
|**Largura**|Fornece um espaço para que você insira a largura da imagem personalizada em pixels (1-512, o limite de 2048).|
|**Altura**|Fornece um espaço para que você insira a altura da imagem personalizada em pixels (1-512, o limite de 2048).|
|**Cores**|Fornece um espaço para que você escolha o número de cores para a imagem personalizada: 2, 16 ou 256.|

## <a name="open-ltdevicegt-image-dialog-box"></a>Abra &lt;dispositivo&gt; caixa de diálogo imagem

Use o **abra &lt;dispositivo&gt; imagem** caixa de diálogo para abrir imagens de dispositivo em projetos do C++. Ele lista as imagens de dispositivo existentes no recurso atual (imagens que fazem parte do recurso atual). É a seguinte propriedade incluída:

|Propriedade|Descrição|
|---|---|
|**Imagens atuais**|Lista as imagens incluídas no recurso. Selecione o tipo de imagem que você deseja abrir.|

## <a name="to-create-a-new-icon-or-cursor"></a>Para criar um novo ícone ou cursor

1. Na [exibição de recurso](../windows/resource-view-window.md), clique com botão direito seu arquivo. RC e escolha **inserir recurso** no menu de atalho. (Se você já tiver um recurso de imagem existente em seu arquivo. RC, como um cursor, você pode clique com botão direito do **Cursor** pasta e selecione **Cursor inserir** no menu de atalho.)

   > [!NOTE]
   > Se seu projeto já não contiver um arquivo. RC, consulte [criando um novo arquivo de Script de recurso](../windows/how-to-create-a-resource-script-file.md).

1. No [caixa de diálogo Inserir recurso](../windows/add-resource-dialog-box.md), selecione **ícone** ou **Cursor** e escolha **novo**. Para ícones, essa ação cria um recurso de ícone com um 32 × 32, o ícone de 16 cores. Para cursores de 32 × 32, imagem monocromática de (2 cores) é criada.

   Se um sinal de adição (**+**) é exibido ao lado do tipo de recurso de imagem no **inserir recurso** caixa de diálogo, isso significa que os modelos de barra de ferramentas estão disponíveis. Selecione o sinal de adição para expandir a lista de modelos, selecione um modelo e escolha **New**.

## <a name="requirements"></a>Requisitos

Nenhum

## <a name="see-also"></a>Consulte também

[Ícones e cursores: Recursos de imagem para exibir dispositivos](../windows/icons-and-cursors-image-resources-for-display-devices-image-editor-for-icons.md)<br/>
[Teclas de aceleração](../windows/accelerator-keys-image-editor-for-icons.md)<br/>
[Ícones e cursores: Recursos de imagem para exibir dispositivos](../windows/icons-and-cursors-image-resources-for-display-devices-image-editor-for-icons.md)<br/>
[Menu imagem](../windows/image-menu-image-editor-for-icons.md)<br/>
[Editor de imagens para ícones](../windows/image-editor-for-icons.md)<br/>
