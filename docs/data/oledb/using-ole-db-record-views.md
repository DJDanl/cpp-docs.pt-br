---
title: "Usando exibições de registro do OLE DB | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
dev_langs: C++
helpviewer_keywords:
- OLE DB record views
- COleDBRecordView class, overview
- rowsets, record views
- record views, record view objects
- OLE DB, record views
- MFC, record views
ms.assetid: 1cd3e595-ce08-43d8-a0a9-d03b5d3e24ce
caps.latest.revision: "7"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.openlocfilehash: c4e57f320c8b207e7b1c8721ab25744cd1f128bc
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
---
# <a name="using-ole-db-record-views"></a>Usando exibições de registro de banco de dados OLE
Se você deseja exibir dados de conjunto de linhas do OLE DB em um aplicativo MFC, você deve usar a classe do MFC [COleDBRecordView](../../mfc/reference/coledbrecordview-class.md). Criar um objeto de exibição de registro de `COleDBRecordView` permite que você exiba os registros do banco de dados em controles MFC. O modo de exibição de registro é uma exibição de formulário de caixa de diálogo conectada diretamente a um objeto de linhas do OLE DB criado a partir de `CRowset` classe de modelo. Obtendo um identificador para o objeto de conjunto de linhas é simple:  
  
```  
COleDBRecordView myRecordView;  
...  
// CProductAccessor is a user record class  
CRowset<CAccessor<CProductAccessor>> myRowSet = myRecordView.OnGetRowset();  
```  
  
 O modo de exibição exibe os campos do `CRowset` objeto nos controles da caixa de diálogo. O `COleDBRecordView` objeto usa a troca de dados de caixa de diálogo (DDX) e a funcionalidade de navegação incorporados `CRowset` (**MoveFirst**, `MoveNext`, `MovePrev`, e `MoveLast`) para automatizar a movimentação de dados entre os controles no formulário e os campos do conjunto de linhas. `COleDBRecordView`mantém o controle de posição do usuário no conjunto de linhas para que a exibição de registro possa atualizar a interface do usuário e fornece um [OnMove](../../mfc/reference/coledbrecordview-class.md#onmove) método para atualizar o registro atual antes de passar para outro.  
  
 Você pode usar funções DDX com **COleDbRecordView** obter dados diretamente do conjunto de registros do banco de dados e exibi-lo em um controle de caixa de diálogo. Você deve usar o **DDX_\***  métodos (como `DDX_Text`), não o **DDX_Field\***  funções (como `DDX_FieldText`) com **COleDbRecordView** .  
  
## <a name="see-also"></a>Consulte também  
 [Usando acessadores](../../data/oledb/using-accessors.md)   
 [Classe COleDBRecordView](../../mfc/reference/coledbrecordview-class.md)