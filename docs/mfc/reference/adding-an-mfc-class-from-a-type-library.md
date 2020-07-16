---
title: Adicionando uma classe do MFC de uma biblioteca de tipos
ms.date: 11/04/2016
helpviewer_keywords:
- classes [MFC], adding MFC
- MFC, adding classes from type libraries
- type libraries, adding MFC classes from
ms.assetid: aba40476-3cfb-47af-990e-ae2e9e0d79cf
ms.openlocfilehash: 4e8d0f74a73048f172a8030d4bfb081c803e7170
ms.sourcegitcommit: 6b3d793f0ef3bbb7eefaf9f372ba570fdfe61199
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/15/2020
ms.locfileid: "86405111"
---
# <a name="adding-an-mfc-class-from-a-type-library"></a>Adicionando uma classe do MFC de uma biblioteca de tipos

Use este assistente para criar uma classe MFC de uma interface em uma biblioteca de tipos disponível. Adicione uma classe MFC a um [aplicativo MFC](../../mfc/reference/creating-an-mfc-application.md), uma [DLL do MFC](../../mfc/reference/creating-an-mfc-dll-project.md) ou um [controle ActiveX do MFC](../../mfc/reference/creating-an-mfc-activex-control.md).

> [!NOTE]
> Você não precisa criar seu projeto MFC com a automação habilitada para adicionar uma classe de uma biblioteca de tipos.

Uma biblioteca de tipos contém uma descrição binária das interfaces expostas por um componente, definindo os métodos junto com seus parâmetros e tipos de retorno. Sua biblioteca de tipos deve ser registrada para que ela apareça na lista **bibliotecas de tipos disponíveis** no Assistente para adicionar classe do TypeLib.

### <a name="to-add-an-mfc-class-from-a-type-library"></a>Para adicionar uma classe MFC de uma biblioteca de tipos

1. Em qualquer **Gerenciador de soluções** ou [modo de exibição de classe](/visualstudio/ide/viewing-the-structure-of-code), clique com o botão direito do mouse no nome do projeto ao qual você deseja adicionar a classe.

1. No menu de atalho, clique em **Adicionar**e em **Adicionar classe**.

1. Na caixa de diálogo [Adicionar classe](../../ide/add-class-dialog-box.md) , no painel modelos, clique em **classe MFC em TypeLib**e, em seguida, clique em **abrir** para exibir o [Assistente Adicionar classe do TypeLib](../../mfc/reference/add-class-from-typelib-wizard.md).

No assistente, você pode adicionar mais de uma classe em uma biblioteca de tipos. Da mesma forma, você pode adicionar classes de mais de uma biblioteca de tipos em uma única sessão de assistente.

O assistente cria uma classe do MFC, derivada de [COleDispatchDriver](../../mfc/reference/coledispatchdriver-class.md), para cada interface que você adiciona da biblioteca de tipos selecionada. `COleDispatchDriver`implementa o lado do cliente da automação OLE.

## <a name="see-also"></a>Confira também

[Clientes de automação](../../mfc/automation-clients.md)<br/>
[Clientes de automação: usando bibliotecas de tipo](../../mfc/automation-clients-using-type-libraries.md)
