---
title: Nova caixa de diálogo do recurso da barra de ferramentas | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: conceptual
f1_keywords:
- vc.editors.newtoolbarresource
dev_langs:
- C++
helpviewer_keywords:
- New Toolbar Resource dialog box
ms.assetid: 52dd01ad-e748-4ab2-b3eb-59f5df990ca6
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 6662fcfab3c9bb1d805e39147bd2838e6bbce5b2
ms.sourcegitcommit: d55ac596ba8f908f5d91d228dc070dad31cb8360
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/08/2018
ms.locfileid: "33877534"
---
# <a name="new-toolbar-resource-dialog-box"></a>Caixa de diálogo Novo Recurso da Barra de Ferramentas
A caixa de diálogo novo recurso da barra de ferramentas permite que você especifique a largura e altura dos botões do qual que você está adicionando a um recurso da barra de ferramentas. O padrão é 16 × 15 pixels.  
  
 Um bitmap que é usado para criar uma barra de ferramentas tem uma largura máxima de 2048. Portanto, se você definir o **largura do botão** para 512, você só pode ter quatro botões. Se você definir a largura como 513, você só pode ter três botões.  
  
 **Largura do botão**  
 Fornece um espaço para você digitar a largura dos botões de barra de ferramentas que você está convertendo de um recurso de bitmap a um recurso da barra de ferramentas. As imagens são cortadas para a largura e altura especificada e as cores são ajustadas para usar cores da barra de ferramentas padrão (16 cores).  
  
 **Altura do botão**  
 Fornece um espaço para você digitar a altura dos botões de barra de ferramentas que você está convertendo de um recurso de bitmap a um recurso da barra de ferramentas. As imagens são cortadas para a largura e altura especificada e as cores são ajustadas para usar cores da barra de ferramentas padrão (16 cores).  
  
 Para obter informações sobre como adicionar recursos a projetos gerenciados, consulte [recursos em aplicativos de área de trabalho](/dotnet/framework/resources/index) no *guia do desenvolvedor do .NET Framework.* Para obter informações sobre como adicionar manualmente os arquivos de recurso para projetos gerenciados, acessar recursos, exibir recursos estáticos e atribuir cadeias de caracteres de recurso para propriedades, consulte [criando arquivos de recursos para aplicativos de área de trabalho](/dotnet/framework/resources/creating-resource-files-for-desktop-apps). Para obter informações sobre globalização e localização de recursos em aplicativos gerenciados, consulte [Globalizing e localização de aplicativos do .NET Framework](/dotnet/standard/globalization-localization/index).  
  
## <a name="requirements"></a>Requisitos  
 MFC ou do ATL  
  
## <a name="see-also"></a>Consulte também  
 [Propriedades de botão da barra de ferramentas](../windows/toolbar-button-properties.md)   
 [Convertendo Bitmaps em barras de ferramentas](../windows/converting-bitmaps-to-toolbars.md)   
 [Editor de barra de ferramentas](../windows/toolbar-editor.md)

