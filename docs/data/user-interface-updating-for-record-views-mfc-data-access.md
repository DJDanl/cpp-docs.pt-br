---
title: Atualização de interface do usuário para exibições de registro (Acesso a dados MFC)
ms.date: 11/04/2016
helpviewer_keywords:
- user interfaces, updating
- menus, updating as context changes
- record views, user interface
ms.assetid: 2c7914b6-2dc3-40c3-b2f2-8371da2a4063
ms.openlocfilehash: 9bfb907d21c928c605b304c595acb834d0046e35
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80209047"
---
# <a name="user-interface-updating-for-record-views--mfc-data-access"></a>Atualização de interface do usuário para exibições de registro (Acesso a dados MFC)

`CRecordView` fornece manipuladores de atualização de interface do usuário padrão para os comandos de navegação. Esses manipuladores automatizam habilitando e desabilitando os objetos de interface do usuário – itens de menu e botões da barra de ferramentas. O assistente de aplicativo fornece menus padrão e, se você escolher a opção de **barra de ferramentas encaixáveis** , um conjunto de botões da barra de ferramentas para os comandos. Se você criar uma classe de exibição do registro usando `CRecordView`, poderá adicionar objetos de interface do usuário semelhantes ao seu aplicativo.

### <a name="to-create-menu-resources-with-the-menu-editor"></a>Para criar recursos de menu com o editor de menu

1. Referindo-se às informações sobre como usar o [Editor de menu](../windows/menu-editor.md), crie seu próprio menu com os mesmos quatro comandos.

#### <a name="to-create-toolbar-buttons-with-the-graphics-editor"></a>Para criar os botões da barra de ferramentas com o editor de gráficos

1. Consultando as informações sobre como usar o [Editor da barra de ferramentas](../windows/toolbar-editor.md), edite o recurso da barra de ferramentas para adicionar botões da barra de ferramentas para seus comandos de navegação de registros.

## <a name="see-also"></a>Confira também

[Suporte à navegação em uma exibição de registro](../data/supporting-navigation-in-a-record-view-mfc-data-access.md)<br/>
[Usando uma exibição de registro](../data/using-a-record-view-mfc-data-access.md)
