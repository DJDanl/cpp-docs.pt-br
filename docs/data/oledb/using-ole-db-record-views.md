---
title: "Usando exibi&#231;&#245;es de registro de banco de dados OLE | Microsoft Docs"
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
  - "Classe COleDBRecordView, visão geral"
  - "MFC, exibições de registro"
  - "Exibições de registro de OLE DB"
  - "OLE DB, exibições de registro"
  - "exibições de registro, objetos de exibição de registro"
  - "conjuntos de linhas, exibições de registro"
ms.assetid: 1cd3e595-ce08-43d8-a0a9-d03b5d3e24ce
caps.latest.revision: 7
caps.handback.revision: 7
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Usando exibi&#231;&#245;es de registro de banco de dados OLE
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Se desejar exibir dados de conjunto de linhas OLE DB em um aplicativo de MFC, você deve usar a classe [COleDBRecordView](../../mfc/reference/coledbrecordview-class.md)MFC.  Um objeto de exibição de registro criado de `COleDBRecordView` permite que você exiba registros de base de dados em controles de MFC.  A exibição de registro é uma exibição de formulário da caixa de diálogo conectada diretamente a um objeto de conjunto de linhas OLE DB criado da classe do modelo de `CRowset` .  Obter um identificador para o objeto de conjunto de linhas é simples:  
  
```  
COleDBRecordView myRecordView;  
...  
// CProductAccessor is a user record class  
CRowset<CAccessor<CProductAccessor>> myRowSet = myRecordView.OnGetRowset();  
```  
  
 A exibição exibe os campos de objeto de `CRowset` nos controles da caixa de diálogo.  O objeto de `COleDBRecordView` usa a caixa de diálogo de troca de dados \(DDX\) e a funcionalidade de navegação criada em `CRowset` \(**MoveFirst**, `MoveNext`, `MovePrev`, e `MoveLast`\) para automatizar a movimentação de dados entre os controles no formulário e os campos do conjunto de linhas.  `COleDBRecordView` mantém acompanha a posição do usuário no conjunto de linhas de forma que a exibição do registro pode atualizar a interface do usuário e fornece um método de [OnMove](../Topic/COleDBRecordView::OnMove.md) para atualizar o registro atual antes de passar a outro.  
  
 Você pode usar funções de DDX com **COleDbRecordView** para obter dados diretamente de conjuntos de registros base de dados e exibi\-los em um controle da caixa de diálogo.  Você deve usar os métodos de **DDX\_\*** \(como `DDX_Text`\), não as funções de **DDX\_Field\*** \(como `DDX_FieldText`\) com **COleDbRecordView**.  
  
## Consulte também  
 [Usando acessadores](../../data/oledb/using-accessors.md)   
 [Classe de COleDBRecordView](../../mfc/reference/coledbrecordview-class.md)