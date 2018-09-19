---
title: Criando o provedor | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-data
ms.topic: reference
dev_langs:
- C++
helpviewer_keywords:
- OLE DB providers, creating
ms.assetid: 2506ba8f-010d-4231-aac1-387432f7b6b9
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- data-storage
ms.openlocfilehash: 3149e59a239401c7c847da9371619821824a5d37
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46032088"
---
# <a name="creating-the-provider"></a>Criando o provedor

#### <a name="to-create-an-ole-db-provider-with-the-atl-ole-db-provider-wizard"></a>Para criar um provedor OLE DB com o OLE DB Assistente de provedor ATL  
  
1. Clique com botão direito no projeto.  
  
1. No menu de atalho, clique em **Add**e, em seguida, clique em **Adicionar classe**.  
  
1. No **Add Class** caixa de diálogo, selecione o **ATL OLE DB Provider** ícone e clique **abrir**.  
  
1. No ATL OLE DB Provider assistente, insira um nome curto para o provedor na **Short Name** caixa. Os tópicos a seguir usam o nome curto "MyProvider", mas você pode usar outro nome. As outras caixas de nome populam de acordo com o nome que você inserir.  
  
1. Edite as outras caixas de nome, se necessário. Além dos nomes de objeto e arquivos, você pode editar o seguinte:  
  
    -   **Coclass**: O nome do que COM usa para criar o provedor.  
  
    -   **ProgID**: O identificador programático, que é uma cadeia de caracteres de texto que pode ser usada em vez de um GUID.  
  
    -   **Versão**: usado com o ProgID e coclass para gerar uma ID de programático dependente de versão.  
  
1. Clique em **Finalizar**.  
  
## <a name="see-also"></a>Consulte também  

[Criando um provedor do OLE DB](../../data/oledb/creating-an-ole-db-provider.md)