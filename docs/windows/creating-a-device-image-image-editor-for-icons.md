---
title: Criando uma imagem de dispositivo (Editor de imagens para ícones) | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: conceptual
f1_keywords:
- vc.editors.icon
dev_langs:
- C++
helpviewer_keywords:
- cursors [C++], creating
- icons [C++], creating
- display devices
- display devices, creating image
- images [C++], creating for display devices
- icons [C++], inserting
ms.assetid: 5a536928-32df-4ace-beb1-1521ce3b871f
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 0a8af9b18b8fc1afb4ad7d0770a1b302e4e7a0e9
ms.sourcegitcommit: 6f8dd98de57bb80bf4c9852abafef1c35a7600f1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/22/2018
ms.locfileid: "42597369"
---
# <a name="creating-a-device-image-image-editor-for-icons"></a>Criando a imagem de um dispositivo (editor de imagens para ícones)

Quando você cria um novo ícone ou cursor, o **imagem** editor primeiro cria uma imagem em um estilo específico (32 × 32, 16 cores para ícones e 32 × 32, monocromo para cursores). Você pode, em seguida, adicionar imagens em tamanhos diferentes e estilos para o ícone inicial ou o cursor e edite cada imagem adicional, conforme necessário, para os dispositivos de exibição diferentes. Você também pode editar uma imagem executando uma operação de copiar e colar a partir de um tipo de imagem existente ou um bitmap criado em um programa de gráfico.

Quando você abre o recurso de ícone ou cursor na [editor de imagens](../windows/image-editor-for-icons.md), a imagem a maioria dos combinar o dispositivo de exibição atual é aberta por padrão.

### <a name="to-create-a-new-icon-or-cursor"></a>Para criar um novo ícone ou cursor

1. Na [exibição de recurso](../windows/resource-view-window.md), clique com botão direito seu arquivo. RC e escolha **inserir recurso** no menu de atalho. (Se você já tiver um recurso de imagem existente em seu arquivo. RC, como um cursor, você pode simplesmente com o botão direito do **Cursor** pasta e selecione **Cursor inserir** no menu de atalho.)

   > [!NOTE]
   > Se seu projeto já não contiver um arquivo. RC, consulte [criando um novo arquivo de Script de recurso](../windows/how-to-create-a-resource-script-file.md).

2. No [caixa de diálogo Inserir recurso](../windows/add-resource-dialog-box.md), selecione **ícone** ou **Cursor** e clique em **novo**. Para ícones, isso cria um recurso de ícone com um 32 × 32, o ícone de 16 cores. Para cursores de 32 × 32, imagem monocromática de (2 cores) é criada.

   Se um sinal de adição (**+**) é exibido ao lado do tipo de recurso de imagem no **inserir recurso** caixa de diálogo, isso significa que os modelos de barra de ferramentas estão disponíveis. Clique no sinal de adição para expandir a lista de modelos, selecione um modelo e clique em **New**.

Para obter informações sobre como adicionar recursos a projetos gerenciados, consulte [recursos em aplicativos de área de trabalho](/dotnet/framework/resources/index) na *guia do desenvolvedor do .NET Framework*. Para obter informações sobre como adicionar manualmente os arquivos de recursos a projetos gerenciados, acessar recursos, exibir recursos estáticos e atribuir cadeias de caracteres de recurso a propriedades, consulte [criando arquivos de recursos para aplicativos de área de trabalho](/dotnet/framework/resources/creating-resource-files-for-desktop-apps). Para obter informações sobre globalização e localização de recursos em aplicativos gerenciados, consulte [Globalizing e Localizando aplicativos do .NET Framework](/dotnet/standard/globalization-localization/index).

## <a name="requirements"></a>Requisitos

Nenhum

## <a name="see-also"></a>Consulte também

[Ícones e cursores: recursos de imagem para exibir dispositivos](../windows/icons-and-cursors-image-resources-for-display-devices-image-editor-for-icons.md)  
[Teclas de aceleração](../windows/accelerator-keys-image-editor-for-icons.md)  
[Ícones e cursores: recursos de imagem para exibir dispositivos](../windows/icons-and-cursors-image-resources-for-display-devices-image-editor-for-icons.md)