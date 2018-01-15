---
title: "Criando uma dica de ferramenta para um botão de barra de ferramentas | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
dev_langs: C++
helpviewer_keywords:
- tool tips [C++], adding to toolbar buttons
- "\nin tool tip"
- toolbar buttons [C++], tool tips
- buttons [C++], tool tips
- Toolbar editor, creating tool tips
ms.assetid: 0af65342-fd78-4e78-8d0d-dc68f7fc462e
caps.latest.revision: "10"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 5b5bb25a14d68c01c25d9242df89c1183511ca83
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="creating-a-tool-tip-for-a-toolbar-button"></a>Criando uma dica de ferramenta para um botão da barra de ferramentas
### <a name="to-create-a-tool-tip"></a>Para criar uma dica de ferramenta  
  
1.  Selecione o botão de barra de ferramentas.  
  
2.  No [janela propriedades](/visualstudio/ide/reference/properties-window), no **Prompt** campo de propriedade, adicione uma descrição do botão da barra de status; após a mensagem, adicione \n e o nome de dica de ferramenta.  
  
 Um exemplo comum de uma dica de ferramenta é o botão de impressão no WordPad:  
  
 1. Abrir o WordPad.  
  
 2. Passe o ponteiro do mouse sobre o **impressão** botão da barra de ferramentas.  
  
 3. Observe que a palavra 'Imprimir' agora é flutuante sob o ponteiro do mouse.  
  
 4. Observe a barra de status (na parte inferior da janela do WordPad) - Observe que agora mostra o texto "Imprime o documento ativo".  
  
 O 'Print' na etapa 3 é o "nome de dica de ferramenta" e o 'imprime o documento ativo ' da etapa 4 é a "Descrição do botão da barra de status de".  
  
 Se você quiser que esse efeito usando o **barra de ferramentas** editor, defina o **Prompt** propriedade **imprime o document\nPrint active**.  
  
> [!NOTE]
>  Você pode editar o texto de aviso usando o [janela propriedades](/visualstudio/ide/reference/properties-window).  
  
 Para obter informações sobre como adicionar recursos a projetos gerenciados, consulte [recursos em aplicativos de área de trabalho](/dotnet/framework/resources/index) no *guia do desenvolvedor do .NET Framework.* Para obter informações sobre como adicionar manualmente os arquivos de recurso para projetos gerenciados, acessar recursos, exibir recursos estáticos e atribuir cadeias de caracteres de recurso para propriedades, consulte [criando arquivos de recursos para aplicativos de área de trabalho](/dotnet/framework/resources/creating-resource-files-for-desktop-apps). Para obter informações sobre globalização e localização de recursos em aplicativos gerenciados, consulte [Globalizing e localização de aplicativos do .NET Framework](/dotnet/standard/globalization-localization/index).  
  
 Requisitos  
  
 MFC ou do ATL  
  
## <a name="see-also"></a>Consulte também  
 [Criando, movendo e editando botões da barra de ferramentas](../windows/creating-moving-and-editing-toolbar-buttons.md)   
 [Editor de barra de ferramentas](../windows/toolbar-editor.md)

