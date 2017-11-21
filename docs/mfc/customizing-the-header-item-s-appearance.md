---
title: "Personalizando o Item de cabeçalho &#39; aparência de s | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
dev_langs: C++
helpviewer_keywords:
- header controls [MFC], customization of items
- CHeaderCtrl class [MFC], customizing the items
- HDS_ styles
ms.assetid: b1e1e326-ec7d-4dbd-a46f-96a3e2055618
caps.latest.revision: "11"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.openlocfilehash: 494372aa3e6dcc418a6ffdacbb7b06635a010310
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
---
# <a name="customizing-the-header-item39s-appearance"></a>Personalizando o Item de cabeçalho &#39; s aparência
Definindo o *dwStyle* parâmetro quando você cria um controle de cabeçalho ([CHeaderCtrl::Create](../mfc/reference/cheaderctrl-class.md#create)), você pode definir a aparência e comportamento do cabeçalho de itens ou do cabeçalho de controle em si.  
  
 Aqui está uma amostra dos estilos que você pode definir e sua finalidade:  
  
-   Para fazer com que um item de cabeçalho a aparência de um botão de ação, use o `HDS_BUTTONS` estilo.  
  
     Se você quiser executar ações em resposta aos cliques do mouse em um item de cabeçalho, como classificar dados por uma coluna específica, como é feito no Microsoft Outlook, use este estilo.  
  
-   Para fornecer os itens de cabeçalho uma aparência "rastreio" quando o cursor do mouse passa sobre eles, use o `HDS_HOTTRACK` estilo.  
  
     Rastreio importante exibe uma estrutura de tópicos 3D conforme o ponteiro passa sobre um item em uma outra forma simples barra.  
  
-   Para indicar que o controle de cabeçalho deve ser ocultado, use o `HDS_HIDDEN` estilo.  
  
     O `HDS_HIDDEN` estilo indica que o controle de cabeçalho é destinado a ser usado como um contêiner de dados e não um controle visual. Este estilo não oculta o controle automaticamente, mas, em vez disso, afeta o comportamento de `CHeaderCtrl::Layout`. O valor retornado no **cy** membro o `WINDOWPOS` estrutura será zero que indica que o controle não deve ser visível para o usuário.  
  
 Para obter mais informações sobre essas propriedades, consulte [itens](http://msdn.microsoft.com/library/windows/desktop/bb775238) no SDK do Windows. Para obter informações sobre como adicionar itens a um controle de cabeçalho, consulte [adicionando itens ao controle de cabeçalho](../mfc/adding-items-to-the-header-control.md).  
  
## <a name="see-also"></a>Consulte também  
 [Usando CHeaderCtrl](../mfc/using-cheaderctrl.md)   
 [Controles](../mfc/controls-mfc.md)

