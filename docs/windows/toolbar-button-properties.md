---
title: "Propriedades de botão da barra de ferramentas | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
dev_langs:
- C++
helpviewer_keywords:
- size, toolbar buttons
- toolbar buttons (in Toolbar editor), setting properties
- Toolbar editor, toolbar button properties
- status bars, active toolbar button text
- command IDs, toolbar buttons
- width, toolbar buttons
ms.assetid: b2705814-7c5d-4f24-8f77-07559b0cdda2
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 5e179cd400b0b8bcc621a7c69a4814eab098fbaa
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="toolbar-button-properties"></a>Propriedades do botão da barra de ferramentas
As propriedades de um botão de barra de ferramentas são:  
  
|Propriedade|Descrição|  
|--------------|-----------------|  
|**ID**|Define a ID do botão. A lista suspensa fornece comuns **ID** nomes.|  
|**Largura**|Define a largura do botão. Recomenda-se 16 pixels.|  
|**Altura**|Define a altura do botão. Observe que a altura de um botão altera a altura de todos os botões na barra de ferramentas. é recomendável 15 pixels.|  
|**Solicitar**|Define a mensagem exibida na barra de status. Adicionando \n e um nome adiciona uma dica de ferramenta ao botão da barra de ferramentas. Para obter mais informações, consulte [criando uma dica de ferramenta](../windows/creating-a-tool-tip-for-a-toolbar-button.md).|  
  
 **Largura** e **altura** se aplicam a todos os botões. Um bitmap que é usado para criar uma barra de ferramentas tem uma largura máxima de 2048. Portanto, se você definir a largura do botão como 512, você só pode ter quatro botões e se você definir a largura como 513, você só pode ter três botões.  
  
 Para obter informações sobre como adicionar recursos a projetos gerenciados, consulte [recursos em aplicativos de área de trabalho](/dotnet/framework/resources/index) no *guia do desenvolvedor do .NET Framework.* Para obter informações sobre como adicionar manualmente os arquivos de recurso para projetos gerenciados, acessar recursos, exibir recursos estáticos e atribuir cadeias de caracteres de recurso para propriedades, consulte [criando arquivos de recursos para aplicativos de área de trabalho](/dotnet/framework/resources/creating-resource-files-for-desktop-apps). Para obter informações sobre globalização e localização de recursos em aplicativos gerenciados, consulte [Globalizing e localização de aplicativos do .NET Framework](/dotnet/standard/globalization-localization/index).  
  
## <a name="requirements"></a>Requisitos  
 MFC ou do ATL  
  
## <a name="see-also"></a>Consulte também  
 [Alterando as propriedades de um botão de barra de ferramentas](../windows/changing-the-properties-of-a-toolbar-button.md)   
 [Editor de barra de ferramentas](../windows/toolbar-editor.md)

