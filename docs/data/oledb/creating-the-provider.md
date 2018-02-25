---
title: Criando o provedor | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: reference
dev_langs:
- C++
helpviewer_keywords:
- OLE DB providers, creating
ms.assetid: 2506ba8f-010d-4231-aac1-387432f7b6b9
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
- data-storage
ms.openlocfilehash: 5521215560c84c19f7b661f0c9662752374b68e4
ms.sourcegitcommit: d51ed21ab2b434535f5c1d553b22e432073e1478
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/23/2018
---
# <a name="creating-the-provider"></a>Criando o provedor
#### <a name="to-create-an-ole-db-provider-with-the-atl-ole-db-provider-wizard"></a>Para criar um provedor OLE DB com o OLE DB Provider assistente ATL  
  
1.  Clique com botão direito no projeto.  
  
2.  No menu de atalho, clique em **adicionar**e, em seguida, clique em **Adicionar classe**.  
  
3.  No **Adicionar classe** caixa de diálogo, selecione o **ATL OLE DB Provider** ícone e clique **abrir**.  
  
4.  No ATL OLE DB Provider assistente, insira um nome curto para o provedor no **nome curto** caixa. Os tópicos a seguir usam o nome curto "MyProvider", mas você pode usar outro nome. As outras caixas de nome populam de acordo com o nome de.  
  
5.  Edite as outras caixas de nome, se necessário. Além dos nomes de objeto e de arquivos, você pode editar o seguinte:  
  
    -   **Coclass**: O nome usado para criar o provedor de COM.  
  
    -   **ProgID**: O identificador programático, que é uma cadeia de caracteres de texto que pode ser usada em vez de um GUID.  
  
    -   **Versão**: usado com o ProgID e coclass para gerar uma ID de programação dependente de versão.  
  
6.  Clique em **Finalizar**.  
  
## <a name="see-also"></a>Consulte também  
 [Criando um provedor do OLE DB](../../data/oledb/creating-an-ole-db-provider.md)