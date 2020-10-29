---
title: Adição de um consumidor OLE DB da ATL
ms.date: 05/09/2019
helpviewer_keywords:
- ATL OLE DB consumers
ms.assetid: f940a513-4e42-4148-b521-dd0d7dc89fa2
ms.openlocfilehash: c298a841bf0d37f90bcd6b53bc0c6cdf501f4dd3
ms.sourcegitcommit: 9c2b3df9b837879cd17932ae9f61cdd142078260
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/29/2020
ms.locfileid: "92921146"
---
# <a name="adding-an-atl-ole-db-consumer"></a>Adição de um consumidor OLE DB da ATL

::: moniker range="msvc-160"

O Assistente de Consumidor OLE DB da ATL não está disponível no Visual Studio 2019 e posteriores. Ainda é possível adicionar a funcionalidade manualmente. Saiba mais em [Criação de um consumidor sem usar um assistente](../../data/oledb/creating-a-consumer-without-using-a-wizard.md).

::: moniker-end

::: moniker range="<=msvc-150"

Use esse assistente para adicionar um consumidor OLE DB da ATL a um projeto. Um consumidor OLE DB da ATL consiste em uma classe de acessador OLE DB e associação de dados necessárias para acessar uma fonte de dados. O projeto deve ter sido criado como um aplicativo COM da ATL, ou como um aplicativo MFC ou Win32 que é compatível com à ATL (que o Assistente de Consumidor OLE DB da ATL adiciona automaticamente).

> [!NOTE]
> É possível adicionar um consumidor OLE DB a um projeto do MFC. Se você o fizer, o Assistente de Consumidor OLE DB da ATL adiciona o suporte ao COM necessário para seu projeto. Isso pressupõe que, quando criou o projeto do MFC, você marcou a caixa de seleção **Controles ActiveX** (na página **Recursos Avançados** do Assistente de Aplicativo de Projeto do MFC), que é marcada por padrão. Selecionar essa opção garante que o aplicativo chame `CoInitialize` e `CoUninitialize`. Se você não selecionou **Controles ActiveX** quando criou o projeto do MFC, será preciso chamar `CoInitialize` e `CoUninitialize` em seu código principal.

## <a name="to-add-an-atl-ole-db-consumer-to-your-project"></a>Adição de um consumidor OLE DB da ATL ao seu projeto

1. Em **Modo de Exibição de Classe** , clique com o botão direito do mouse no projeto. No menu de atalho, clique em **Adicionar** e em **Adicionar classe** .

1. Na pasta do Visual C++, clique duas vezes no ícone **Consumidor OLE DB da ATL** ou selecione-o e clique em **Abrir** .

   O Assistente de Consumidor OLE DB da ATL abrirá.

1. Defina as configurações conforme descrito em [Assistente de Consumidor OLE DB da ATL](../../atl/reference/atl-ole-db-consumer-wizard.md).

1. Clique em **concluir** para fechar o assistente. O código de consumidor OLE DB recém-criado será inserido em seu projeto.

::: moniker-end

## <a name="see-also"></a>Veja também

[Adicionando funcionalidade com assistentes de código](../../ide/adding-functionality-with-code-wizards-cpp.md)
