---
title: Criando um ícone de 256 cores ou um Cursor (Editor de imagens para ícones) | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- 256-color palette
- cursors, color
- colors, icons
- colors, cursors
- icons, color
ms.assetid: 2738089b-4fd3-4c45-96ae-6a15e4c6b780
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 92f5a427399009baf1b157480f0e486e9c4ec538
ms.sourcegitcommit: 37a10996022d738135999cbe71858379386bab3d
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/08/2018
ms.locfileid: "39645217"
---
# <a name="creating-a-256-color-icon-or-cursor-image-editor-for-icons"></a>Criando um ícone ou cursor de 256 cores (editor de imagens para ícones)
Usando o **imagem** editor, ícones e cursores podem ser dimensionados grandes (64 × 64) com uma paleta de 256 cores à sua escolha. Depois de criar o recurso, um estilo de imagem do dispositivo é selecionado.  
  
### <a name="to-create-a-256-color-icon-or-cursor"></a>Para criar um ícone de 256 cores ou cursor  
  
1.  Na [exibição de recurso](../windows/resource-view-window.md), clique com botão direito seu arquivo. RC e escolha **inserir recurso** no menu de atalho. (Se você já tiver um recurso de imagem existente em seu arquivo. RC, como um cursor, você pode simplesmente com o botão direito do **Cursor** pasta e selecione **Cursor inserir** no menu de atalho.)  
  
    > [!NOTE] 
    > Se seu projeto já não contiver um arquivo. RC, consulte [criando um novo arquivo de Script de recurso](../windows/how-to-create-a-resource-script-file.md).  
  
2.  No [caixa de diálogo Inserir recurso](../windows/add-resource-dialog-box.md), selecione **ícone** ou **Cursor** e clique em **novo**.  
  
3.  Sobre o **imagem** menu, clique em **nova imagem de dispositivo**.  
  
4.  Selecione o estilo de imagem de 256 cores que você deseja.  
  
 Para obter informações sobre como adicionar recursos a projetos gerenciados, consulte [recursos em aplicativos de área de trabalho](/dotnet/framework/resources/index) na *guia do desenvolvedor do .NET Framework*. Para obter informações sobre como adicionar manualmente os arquivos de recursos a projetos gerenciados, acessar recursos, exibir recursos estáticos e atribuir cadeias de caracteres de recurso a propriedades, consulte [criando arquivos de recursos para aplicativos de área de trabalho](/dotnet/framework/resources/creating-resource-files-for-desktop-apps). Para obter informações sobre globalização e localização de recursos em aplicativos gerenciados, consulte [Globalizing e Localizando aplicativos do .NET Framework](/dotnet/standard/globalization-localization/index).  
  
## <a name="requirements"></a>Requisitos  
 Nenhum  
  
## <a name="see-also"></a>Consulte também  
 [Usando a paleta de 256 cores](../windows/using-the-256-color-palette-image-editor-for-icons.md)   
 [Teclas de aceleração](../windows/accelerator-keys-image-editor-for-icons.md)   
 [Ícones e cursores: recursos de imagem para exibir dispositivos](../windows/icons-and-cursors-image-resources-for-display-devices-image-editor-for-icons.md)