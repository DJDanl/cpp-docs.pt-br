---
title: Atualização de Interface do usuário para exibições de registro (acesso a dados MFC) | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-data
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- user interfaces, updating
- menus, updating as context changes
- record views, user interface
ms.assetid: 2c7914b6-2dc3-40c3-b2f2-8371da2a4063
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- data-storage
ms.openlocfilehash: 1227ba1fe0a14af7013109b336d1d60eda41137e
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="user-interface-updating-for-record-views--mfc-data-access"></a>Atualização de interface do usuário para exibições de registro (Acesso a dados MFC)
`CRecordView` Fornece manipuladores de atualização de interface do usuário de padrão para os comandos de navegação. Esses manipuladores automatizam habilitando e desabilitando os objetos de interface do usuário – itens de menu e botões da barra de ferramentas. O Assistente de aplicativo fornece menus padrão e, se você escolher o **barra de ferramentas Encaixável** opção, um conjunto de botões de barra de ferramentas para os comandos. Se você criar uma classe de exibição do registro usando `CRecordView`, poderá adicionar objetos de interface do usuário semelhantes ao seu aplicativo.  
  
### <a name="to-create-menu-resources-with-the-menu-editor"></a>Para criar recursos de menu com o editor de menu  
  
1.  Referindo-se a informações sobre como usar o [editor de menu](../windows/menu-editor.md), crie seu próprio menu com os mesmos comandos de quatro.  
  
#### <a name="to-create-toolbar-buttons-with-the-graphics-editor"></a>Para criar os botões da barra de ferramentas com o editor de gráficos  
  
1.  Referindo-se a informações sobre como usar o [editor de barra de ferramentas](../windows/toolbar-editor.md), edite o recurso da barra de ferramentas para adicionar botões de barra de ferramentas para os comandos de navegação de registros.  
  
## <a name="see-also"></a>Consulte também  
 [Suporte de navegação em uma exibição de registro](../data/supporting-navigation-in-a-record-view-mfc-data-access.md)   
 [Usando uma exibição de registro](../data/using-a-record-view-mfc-data-access.md)