---
title: "Usando controles em árvore | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
dev_langs: C++
helpviewer_keywords:
- CTreeCtrl class [MFC], using
- tree controls [MFC], about tree controls
ms.assetid: 4e92941a-e477-4fb1-b1ce-4abeafbef1c1
caps.latest.revision: "10"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: ea3b7e0348cb21aa4338293f7cc1119e380f92dc
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="using-tree-controls"></a>Usando controles de árvore
Um uso típico de um controle de árvore ([CTreeCtrl](../mfc/reference/ctreectrl-class.md)) segue o padrão abaixo:  
  
-   O controle é criado. Se o controle for especificado em um modelo de caixa de diálogo ou se você estiver usando `CTreeView`, criação é automática quando a caixa de diálogo ou o modo de exibição é criado. Se você deseja criar o controle de árvore, como uma janela filho de alguma outra janela, use o [criar](../mfc/reference/ctreectrl-class.md#create) função de membro.  
  
-   Se você desejar que o controle de árvore para usar imagens, defina uma lista de imagens chamando [SetImageList](../mfc/reference/ctreectrl-class.md#setimagelist). Você também pode alterar o recuo chamando [SetIndent](../mfc/reference/ctreectrl-class.md#setindent). É um bom momento para fazer isso em [OnInitDialog](../mfc/reference/cdialog-class.md#oninitdialog) (para controles em caixas de diálogo) ou [OnInitialUpdate](../mfc/reference/cview-class.md#oninitialupdate) (para modos de exibição).  
  
-   Colocar dados no controle chamando o `CTreeCtrl`do [InsertItem](../mfc/reference/ctreectrl-class.md#insertitem) função uma vez para cada item de dados. `InsertItem`Retorna um identificador para o item que você pode usar para se referir a ele mais tarde, por exemplo, ao adicionar itens filhos. É um bom momento para inicializar os dados em `OnInitDialog` (para controles em caixas de diálogo) ou `OnInitialUpdate` (para modos de exibição).  
  
-   Como o usuário interage com o controle, ele envia várias mensagens de notificação. Você pode especificar uma função para lidar com cada uma das mensagens que você deseja manipular adicionando um **ON_NOTIFY_REFLECT** macro no mapa de mensagem da janela de controle ou adicionando um `ON_NOTIFY` macro ao mapa de mensagem da janela de seu pai. Consulte [mensagens de notificação de controle de árvore](../mfc/tree-control-notification-messages.md) mais adiante neste tópico para obter uma lista de notificações possíveis.  
  
-   Chame várias funções de membro de conjunto para definir os valores para o controle. As alterações que você pode fazer incluem definir o recuo e alterar o texto, imagem ou associados a um item de dados.  
  
-   Use as várias funções de Get para examinar o conteúdo do controle. Também é possível percorrer o conteúdo do controle de árvore com funções que permitem recuperar identificadores de pais, filhos e irmãos de um item especificado. Você ainda pode classificar os filhos de um nó específico.  
  
-   Quando tiver terminado com o controle, certifique-se de que corretamente, ele será destruído. Se o controle de árvore está em uma caixa de diálogo ou se é um modo de exibição, ele e o `CTreeCtrl` objeto será destruído automaticamente. Se não, você precisará garantir que ambos o controle e o `CTreeCtrl` objeto corretamente são destruídas.  
  
## <a name="see-also"></a>Consulte também  
 [Usando CTreeCtrl](../mfc/using-ctreectrl.md)   
 [Controles](../mfc/controls-mfc.md)

