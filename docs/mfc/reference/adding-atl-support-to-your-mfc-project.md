---
title: Adicionando suporte ATL ao seu projeto MFC
ms.date: 11/04/2016
f1_keywords:
- vc.codewiz.adding.atl.mfc
helpviewer_keywords:
- MFC, ATL support
- ATL, MFC projects
ms.assetid: b5fe15d6-7752-4818-b9f9-62482ad35c95
ms.openlocfilehash: 0f75ffd09da1502e5f1488dbce0d8d2b9623d396
ms.sourcegitcommit: 65ed563a8a1d4d90f872a2a6edcb086f84ec9f77
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 06/06/2019
ms.locfileid: "66741736"
---
# <a name="adding-atl-support-to-your-mfc-project"></a>Adicionando suporte ATL ao seu projeto MFC

Se você já tiver criado um aplicativo baseado no MFC, em seguida, você pode adicionar suporte para a biblioteca ATL (Active Template) com facilidade, executando o ATL a adicionar suporte ao Assistente de projeto do MFC.

> [!NOTE]
>  ATL e MFC não têm suporte em geral nas edições Express do Visual Studio.

> [!NOTE]
>  Esse suporte só se aplica a objetos COM simples adicionados a um executável do MFC ou um projeto de DLL. Você pode adicionar outros objetos COM (incluindo controles ActiveX) a projetos MFC, mas os objetos poderá não funcionar conforme o esperado.

### <a name="to-add-atl-support-to-your-mfc-project"></a>Para adicionar suporte ATL ao seu projeto MFC

1. No Gerenciador de soluções, clique com botão direito do projeto ao qual você deseja adicionar suporte ATL.

1. No menu de atalho, clique em **Adicionar** e em **Adicionar Classe**.

1. Selecione o **adicionar o suporte ATL ao projeto do MFC** ícone.

    > [!NOTE]
    >  Esse ícone está localizado na pasta em ATL a **categorias** painel.

1. Quando solicitado, clique em **Sim** para adicionar suporte ATL.

Para obter mais informações sobre como adicionar suporte ATL altera o código do seu projeto MFC, consulte [detalhes de ATL suporte adicionado pelo assistente ATL](../../mfc/reference/details-of-atl-support-added-by-the-atl-wizard.md)

## <a name="see-also"></a>Consulte também

[Adicionando uma classe](../../ide/adding-a-class-visual-cpp.md)<br/>
[Adicionando funcionalidade com assistentes de código](../../ide/adding-functionality-with-code-wizards-cpp.md)<br/>
[Adicionando uma função de membro](../../ide/adding-a-member-function-visual-cpp.md)<br/>
[Adicionando uma variável de membro](../../ide/adding-a-member-variable-visual-cpp.md)<br/>
[Substituindo uma função virtual](../../ide/overriding-a-virtual-function-visual-cpp.md)<br/>
[Manipulador de mensagens do MFC](../../mfc/reference/adding-an-mfc-message-handler.md)<br/>
[Navegando pela estrutura de classe](../../ide/navigate-code-cpp.md)
