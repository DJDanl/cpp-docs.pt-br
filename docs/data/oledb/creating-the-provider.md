---
title: Criando o provedor
ms.date: 05/09/2019
helpviewer_keywords:
- OLE DB providers, creating
ms.assetid: 2506ba8f-010d-4231-aac1-387432f7b6b9
ms.openlocfilehash: 2b3b3f56ad4bbd1940beb4159d1a78f08b47d26a
ms.sourcegitcommit: 00e26915924869cd7eb3c971a7d0604388abd316
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/10/2019
ms.locfileid: "65525101"
---
# <a name="creating-the-provider"></a>Criando o provedor

::: moniker range="vs-2019"

O assistente de Provedor OLE DB da ATL não está disponível no Visual Studio 2019 e posteriores.

::: moniker-end

::: moniker range="vs-2017"

## <a name="to-create-an-ole-db-provider-with-the-atl-ole-db-provider-wizard"></a>Criação de um provedor OLE DB com o Assistente de Provedor ATL OLE DB

1. Clique com o botão direito do mouse no projeto.

1. No menu de atalho, clique em **Adicionar** e em **Adicionar Classe**.

1. Na caixa de diálogo **Adicionar Classe**, **em Instalado** > **Visual C++**  > **ATL**, selecione o ícone **Provedor ATL OLEDB** e clique **Abrir**.

1. No **Assistente de Provedor ATL OLE DB**, insira um nome curto para o provedor na caixa **Nome Curto**. Os tópicos a seguir usam o nome curto *Personalizado*, mas você pode usar outro nome. As outras caixas de nome são preenchidas de acordo com o nome que você inserir.

1. Edite as outras caixas de nome, se for necessário. Além dos nomes de objeto e arquivos, você pode editar o seguinte:

   - **Coclass**: o nome usado por COM para criar o provedor.

   - **ProgID**: o identificador programático, que é uma cadeia de caracteres de texto que pode ser usada em vez de um GUID.

   - **Versão**: usado com ProgID e Coclass para gerar uma ID programática dependente da versão.

1. Clique em **Finalizar**.

::: moniker-end

## <a name="see-also"></a>Consulte também

[Criando um provedor do OLE DB](../../data/oledb/creating-an-ole-db-provider.md)
