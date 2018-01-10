---
title: "Criar uma imagem de dispositivo (Editor de imagens para ícones) | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords: vc.editors.icon
dev_langs: C++
helpviewer_keywords:
- cursors [C++], creating
- icons [C++], creating
- display devices
- display devices, creating image
- images [C++], creating for display devices
- icons [C++], inserting
ms.assetid: 5a536928-32df-4ace-beb1-1521ce3b871f
caps.latest.revision: "12"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: d68a9d35471e43296cade829700fc6c5b311ce2a
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="creating-a-device-image-image-editor-for-icons"></a>Criando a imagem de um dispositivo (editor de imagens para ícones)
Quando você cria um novo ícone ou cursor de recurso, a imagem do editor cria primeiro uma imagem em um estilo específico (32 x 32, 16 cores de ícones e 32 x 32, monocromática para cursores). Você pode adicionar imagens em estilos e tamanhos diferentes para o cursor ou ícone inicial e editar cada imagem adicional, conforme necessário, para os dispositivos de exibição diferente. Você também pode editar uma imagem, executando uma operação recortar e colar a partir de um tipo de imagem existente ou um bitmap criado em um programa de elementos gráficos.  
  
 Quando você abre o recurso de ícone ou cursor no [editor de imagem](../windows/image-editor-for-icons.md), a imagem mais perto correspondência o dispositivo de vídeo atual está aberto por padrão.  
  
### <a name="to-create-a-new-icon-or-cursor"></a>Para criar um novo ícone ou cursor  
  
1.  Em [exibição recursos](../windows/resource-view-window.md), clique com o arquivo. RC e escolha **inserir recursos** no menu de atalho. (Se você já tiver um recurso de imagem existente em seu arquivo. RC, como um cursor, você pode simplesmente clique o **Cursor** pasta e selecione **inserir Cursor** no menu de atalho.)  
  
    > [!NOTE]
    >  Se o projeto já não contiver um arquivo. RC, consulte [criar um novo arquivo de Script de recurso](../windows/how-to-create-a-resource-script-file.md).  
  
2.  No [caixa de diálogo Inserir recurso](../windows/add-resource-dialog-box.md), selecione **ícone** ou **Cursor** e clique em **novo**. Para ícones, isso cria um recurso de ícone com um 32 x 32, o ícone de 16 cores. Para cursores, 32 x 32, a imagem monocromática de (cor 2) é criada.  
  
     Se um sinal de adição (**+**) é exibido ao lado de tipo de recurso de imagem no **inserir recursos** caixa de diálogo, isso significa que os modelos de barra de ferramentas estão disponíveis. Clique no sinal de adição para expandir a lista de modelos, selecione um modelo e clique em **novo**.  
  
 Para obter informações sobre como adicionar recursos a projetos gerenciados, consulte [recursos em aplicativos de área de trabalho](/dotnet/framework/resources/index) no *guia do desenvolvedor do .NET Framework.* Para obter informações sobre como adicionar manualmente os arquivos de recurso para projetos gerenciados, acessar recursos, exibir recursos estáticos e atribuir cadeias de caracteres de recurso para propriedades, consulte [criando arquivos de recursos para aplicativos de área de trabalho](/dotnet/framework/resources/creating-resource-files-for-desktop-apps). Para obter informações sobre globalização e localização de recursos em aplicativos gerenciados, consulte [Globalizing e localização de aplicativos do .NET Framework](/dotnet/standard/globalization-localization/index).  
  
 **Requisitos**  
  
 Nenhum  
  
## <a name="see-also"></a>Consulte também  
 [Ícones e cursores: recursos de imagem para exibir dispositivos](../windows/icons-and-cursors-image-resources-for-display-devices-image-editor-for-icons.md)   
 [Teclas de aceleração](../windows/accelerator-keys-image-editor-for-icons.md)   
 [Ícones e cursores: recursos de imagem para exibir dispositivos](../windows/icons-and-cursors-image-resources-for-display-devices-image-editor-for-icons.md)
