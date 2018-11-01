---
title: Criando o provedor
ms.date: 10/15/2018
helpviewer_keywords:
- OLE DB providers, creating
ms.assetid: 2506ba8f-010d-4231-aac1-387432f7b6b9
ms.openlocfilehash: 05ab045e104e3035f8ccd2fa1924b6959164b8d4
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50538170"
---
# <a name="creating-the-provider"></a>Criando o provedor

## <a name="to-create-an-ole-db-provider-with-the-atl-ole-db-provider-wizard"></a>Para criar um provedor OLE DB com o OLE DB Assistente de provedor ATL

1. Clique com botão direito no projeto.

1. No menu de atalho, clique em **Add**e, em seguida, clique em **Adicionar classe**.

1. No **Add Class** caixa de diálogo **instalado** > **Visual C++** > **ATL**, selecione o **Provedor de OLEDB do ATL** ícone e clique **aberto**.

1. No **ATL OLE DB Provider Wizard**, insira um nome curto para o provedor na **nome curto** caixa. Os tópicos a seguir usam o nome curto *personalizado*, mas você pode usar outro nome. As outras caixas de nome populam de acordo com o nome que você inserir.

1. Edite as outras caixas de nome, se necessário. Além dos nomes de objeto e arquivos, você pode editar o seguinte:

   - **Coclass**: O nome do que COM usa para criar o provedor.

   - **ProgID**: O identificador programático, que é uma cadeia de caracteres de texto que pode ser usada em vez de um GUID.

   - **Versão**: usado com o ProgID e Coclass para gerar uma ID de programático dependente de versão.

1. Clique em **Finalizar**.

## <a name="see-also"></a>Consulte também

[Criando um provedor do OLE DB](../../data/oledb/creating-an-ole-db-provider.md)
