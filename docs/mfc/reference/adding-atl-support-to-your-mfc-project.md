---
title: Adicionando suporte ATL ao seu projeto MFC
ms.date: 11/04/2016
f1_keywords:
- vc.codewiz.adding.atl.mfc
helpviewer_keywords:
- MFC, ATL support
- ATL, MFC projects
ms.assetid: b5fe15d6-7752-4818-b9f9-62482ad35c95
ms.openlocfilehash: 05c4e8ba54d9a573b422f136c9e8cf69e48d1c9a
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81371678"
---
# <a name="adding-atl-support-to-your-mfc-project"></a>Adicionando suporte ATL ao seu projeto MFC

Se você já criou um aplicativo baseado em MFC, então você pode adicionar suporte para a Active Template Library (ATL) facilmente usando o IDE.

> [!NOTE]
> Esse suporte só se aplica a objetos COM simples adicionados a um executável do MFC ou um projeto de DLL. Você pode adicionar outros objetos COM (incluindo controles ActiveX) a projetos de MFC, mas os objetos podem não funcionar como esperado.

::: moniker range=">=vs-2019"

1. No Solution Explorer, clique com o botão direito do mouse no nó do projeto.

1. No menu de atalho, clique em **Adicionar**, depois em **Novo Item**.

1. Escolha **ATL** no painel esquerdo e escolha **suporte ATL** no painel central.

::: moniker-end

::: moniker range="<=vs-2017"

### <a name="to-add-atl-support-to-your-mfc-project"></a>Para adicionar suporte atl ao seu projeto MFC

1. No Solution Explorer, clique com o botão direito do mouse no nó do projeto.

1. No menu de atalho, clique em **Adicionar** e, em seguida, em **Adicionar Classe**.

1. Selecione **ATL** no painel esquerdo e escolha **Adicionar suporte ATL ao Projeto MFC** no painel central.

::: moniker-end

Para obter mais informações sobre como a adição de suporte atl altera o código do projeto MFC, consulte [Detalhes do suporte ATL adicionados pelo assistente ATL](../../mfc/reference/details-of-atl-support-added-by-the-atl-wizard.md)

## <a name="see-also"></a>Confira também

[Adicionando uma classe](../../ide/adding-a-class-visual-cpp.md)<br/>
[Adicionando funcionalidade com assistentes de código](../../ide/adding-functionality-with-code-wizards-cpp.md)<br/>
[Adicionando uma função de membro](../../ide/adding-a-member-function-visual-cpp.md)<br/>
[Adicionando uma variável de membro](../../ide/adding-a-member-variable-visual-cpp.md)<br/>
[Substituindo uma função virtual](../../ide/overriding-a-virtual-function-visual-cpp.md)<br/>
[Manipulador de mensagens do MFC](../../mfc/reference/adding-an-mfc-message-handler.md)<br/>
[Navegando pela estrutura de classe](../../ide/navigate-code-cpp.md)
