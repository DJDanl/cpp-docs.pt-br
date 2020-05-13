---
title: Adicionando uma classe do MFC de uma biblioteca de tipos
ms.date: 11/04/2016
helpviewer_keywords:
- classes [MFC], adding MFC
- MFC, adding classes from type libraries
- type libraries, adding MFC classes from
ms.assetid: aba40476-3cfb-47af-990e-ae2e9e0d79cf
ms.openlocfilehash: bf9c763a215a4880d5b0ad206f6a347341fea9eb
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81371718"
---
# <a name="adding-an-mfc-class-from-a-type-library"></a>Adicionando uma classe do MFC de uma biblioteca de tipos

Use este assistente para criar uma classe MFC a partir de uma interface em uma biblioteca de tipos disponível. Adicione uma classe MFC a um [aplicativo MFC](../../mfc/reference/creating-an-mfc-application.md), uma [DLL do MFC](../../mfc/reference/creating-an-mfc-dll-project.md) ou um [controle ActiveX do MFC](../../mfc/reference/creating-an-mfc-activex-control.md).

> [!NOTE]
> Você não precisa criar seu projeto MFC com automação habilitada para adicionar uma classe a partir de uma biblioteca de tipos.

Uma biblioteca de tipos contém uma descrição binária das interfaces expostas por um componente, definindo os métodos juntamente com seus parâmetros e tipos de retorno. Sua biblioteca de tipos deve ser registrada para que ela seja exibida na lista **bibliotecas do tipo Disponível** no Assistente Adicionar classe do Typelib. Consulte "Inside Distributed COM: Type Libraryes and Language Integration" na biblioteca MSDN para obter mais informações.

### <a name="to-add-an-mfc-class-from-a-type-library"></a>Para adicionar uma classe MFC a partir de uma biblioteca de tipos

1. Em **Solution Explorer** ou [Class View,](/visualstudio/ide/viewing-the-structure-of-code)clique com o botão direito do mouse no nome do projeto ao qual deseja adicionar a classe.

1. No menu de atalho, clique **em Adicionar**e clique em **Adicionar classe**.

1. Na caixa de diálogo [Adicionar classe,](../../ide/add-class-dialog-box.md) no painel Modelos, clique em **Classe MFC de Typelib**e clique em **Abrir** para exibir a classe adicionar do [assistente Typelib](../../mfc/reference/add-class-from-typelib-wizard.md).

No assistente, você pode adicionar mais de uma classe em uma biblioteca de tipos. Da mesma forma, você pode adicionar classes de mais de uma biblioteca de tipo em uma única sessão de assistente.

O assistente cria uma classe MFC, derivada do [COleDispatchDriver,](../../mfc/reference/coledispatchdriver-class.md)para cada interface que você adicionar da biblioteca de tipos selecionada. `COleDispatchDriver`implementa o lado cliente da automação OLE.

## <a name="see-also"></a>Confira também

[Clientes de automação](../../mfc/automation-clients.md)<br/>
[Clientes de automação: usando bibliotecas de tipo](../../mfc/automation-clients-using-type-libraries.md)
