---
title: Adicionando suporte ATL ao seu projeto MFC
ms.date: 11/04/2016
f1_keywords:
- vc.codewiz.adding.atl.mfc
helpviewer_keywords:
- MFC, ATL support
- ATL, MFC projects
ms.assetid: b5fe15d6-7752-4818-b9f9-62482ad35c95
ms.openlocfilehash: fba79db013cd9f4cc62ba5826b53e5fa9b15c83a
ms.sourcegitcommit: bf1940a39029dbbd861f95480f55e5e8bd25cda0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/28/2019
ms.locfileid: "70108409"
---
# <a name="adding-atl-support-to-your-mfc-project"></a>Adicionando suporte ATL ao seu projeto MFC

Se você já tiver criado um aplicativo baseado em MFC, poderá adicionar suporte para o Active Template Library (ATL) facilmente usando o IDE.

> [!NOTE]
>  Esse suporte só se aplica a objetos COM simples adicionados a um executável do MFC ou um projeto de DLL. Você pode adicionar outros objetos COM (incluindo controles ActiveX) a projetos MFC, mas os objetos podem não funcionar conforme o esperado.

::: moniker range=">=vs-2019"

1. Em Gerenciador de Soluções, clique com o botão direito do mouse no nó do projeto.

1. No menu de atalho, clique em **Adicionar**, depois em **Novo Item**.

1. Escolha **ATL** no painel esquerdo e, em seguida, escolha **suporte ATL** no painel central.

::: moniker-end

::: moniker range="<=vs-2017"

### <a name="to-add-atl-support-to-your-mfc-project"></a>Para adicionar suporte ATL ao seu projeto do MFC

1. Em Gerenciador de Soluções, clique com o botão direito do mouse no nó do projeto.

1. No menu de atalho, clique em **Adicionar** e em **Adicionar Classe**.

1. Selecione **ATL** no painel esquerdo e escolha **Adicionar suporte ATL ao projeto MFC** no painel central.

::: moniker-end

Para obter mais informações sobre como adicionar suporte a ATL altera o código do projeto MFC, consulte [detalhes do suporte ATL adicionado pelo assistente do ATL](../../mfc/reference/details-of-atl-support-added-by-the-atl-wizard.md)

## <a name="see-also"></a>Consulte também

[Adicionando uma classe](../../ide/adding-a-class-visual-cpp.md)<br/>
[Adicionando funcionalidade com assistentes de código](../../ide/adding-functionality-with-code-wizards-cpp.md)<br/>
[Adicionando uma função de membro](../../ide/adding-a-member-function-visual-cpp.md)<br/>
[Adicionando uma variável de membro](../../ide/adding-a-member-variable-visual-cpp.md)<br/>
[Substituindo uma função virtual](../../ide/overriding-a-virtual-function-visual-cpp.md)<br/>
[Manipulador de mensagens do MFC](../../mfc/reference/adding-an-mfc-message-handler.md)<br/>
[Navegando pela estrutura de classe](../../ide/navigate-code-cpp.md)
