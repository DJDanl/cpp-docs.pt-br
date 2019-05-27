---
title: Adicionar um provedor de OLE DB da ATL
ms.date: 05/09/2019
helpviewer_keywords:
- OLE DB, adding ATL OLE DB provider to projects
- ATL projects, adding ATL OLE DB providers
- ATL OLE DB providers
ms.assetid: 26fba1e3-880f-4bc6-90e5-2096a48a3a6c
ms.openlocfilehash: 36c07da6249a106836433e127f95258d4ed5b509
ms.sourcegitcommit: fc1de63a39f7fcbfe2234e3f372b5e1c6a286087
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/15/2019
ms.locfileid: "65706940"
---
# <a name="adding-an-atl-ole-db-provider"></a>Adicionar um provedor de OLE DB da ATL

::: moniker range="vs-2019"

O assistente de Provedor OLE DB da ATL não está disponível no Visual Studio 2019 e posteriores.

::: moniker-end

::: moniker range="<=vs-2017"

Use este assistente para adicionar um provedor de OLE DB da ATL a um projeto. Um provedor de OLE DB da ATL consiste em uma fonte de dados, sessão, comando e classes de conjunto de linhas. O projeto deve ter sido criado como um aplicativo de COM da ATL.

## <a name="to-add-an-atl-ole-db-provider-to-your-project"></a>Adição de um provedor de OLE DB da ATL ao seu projeto

1. Em **Modo de Exibição de Classe**, clique com o botão direito do mouse no projeto. No menu de atalho, clique em **Adicionar** e em **Adicionar Classe**.

1. Na pasta **Visual C++**, clique duas vezes no ícone **Provedor de OLE DB da ATL** ou selecione-o e clique em **Abrir**.

   O Assistente de Provedor ATL OLE DB abrirá.

1. Defina as configurações conforme descrito em [Assistente de Provedor ATL OLE DB](../../atl/reference/atl-ole-db-provider-wizard.md).

1. Clique em **Concluir** para fechar o assistente, o que insere o código do provedor de OLE DB recém-criado em seu projeto.

::: moniker-end

## <a name="see-also"></a>Consulte também

[Adicionando funcionalidade com assistentes de código](../../ide/adding-functionality-with-code-wizards-cpp.md)
