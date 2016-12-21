---
title: "Criando o provedor | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Provedores OLE DB, criando"
ms.assetid: 2506ba8f-010d-4231-aac1-387432f7b6b9
caps.latest.revision: 7
caps.handback.revision: 7
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Criando o provedor
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

#### Para criar um provedor OLE DB com o assistente do provedor OLE DB de ATL  
  
1.  Clique com o botão direito do mouse no projeto.  
  
2.  No menu de atalho, clique **Adicionar**, e clique em **Adicionar Classe**.  
  
3.  Na caixa de diálogo de **Adicionar Classe** , selecione o ícone de **ATL OLE DB Provider** , e clique em **Abrir**.  
  
4.  No assistente do provedor OLE DB de ATL, digite um nome curto para o provedor na caixa de **Nome curto** .  Os tópicos a seguir usam o nome curto “MyProvider”, mas você pode usar outro nome.  As outras caixas do nome populam de acordo com o nome digitado.  
  
5.  Editar as outras caixas de nome, se necessário.  Além do objeto e os nomes de arquivo, você pode editar o seguinte:  
  
    -   **Coclass**: O nome que a usa para criar o provedor.  
  
    -   **ProgID**: O identificador programático, que é uma cadeia de caracteres de texto que pode ser usada em vez de GUID.  
  
    -   **Versão**: Usado com o ProgID e os coclass para gerar uma ID programático de progids dependentes  
  
6.  Clique em **Concluir**.  
  
## Consulte também  
 [Criando um provedor de banco de dados OLE](../../data/oledb/creating-an-ole-db-provider.md)