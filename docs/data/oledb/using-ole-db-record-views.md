---
title: Usando exibições de registro do OLE DB | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-data
ms.topic: reference
dev_langs:
- C++
helpviewer_keywords:
- OLE DB record views
- COleDBRecordView class, overview
- rowsets, record views
- record views, record view objects
- OLE DB, record views
- MFC, record views
ms.assetid: 1cd3e595-ce08-43d8-a0a9-d03b5d3e24ce
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- data-storage
ms.openlocfilehash: b0b787686fc09d943de030645d56465cd259bc37
ms.sourcegitcommit: 9a0905c03a73c904014ec9fd3d6e59e4fa7813cd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/29/2018
ms.locfileid: "43215761"
---
# <a name="using-ole-db-record-views"></a>Usando exibições de registro de banco de dados OLE
Se você deseja exibir dados de conjunto de linhas do OLE DB em um aplicativo MFC, você deve usar a classe do MFC [COleDBRecordView](../../mfc/reference/coledbrecordview-class.md). Um objeto de exibição do registro criado a partir `COleDBRecordView` permite que você exibir registros de banco de dados nos controles do MFC. O modo de exibição do registro é uma exibição de formulário de caixa de diálogo conectada diretamente a um objeto de linhas do OLE DB criado a partir de `CRowset` classe de modelo. Obtendo um identificador para o objeto de conjunto de linhas é simple:  
  
```cpp  
COleDBRecordView myRecordView;  
...  
// CProductAccessor is a user record class  
CRowset<CAccessor<CProductAccessor>> myRowSet = myRecordView.OnGetRowset();  
```  
  
 O modo de exibição exibe os campos do `CRowset` objeto nos controles da caixa de diálogo. O `COleDBRecordView` usa o objeto de troca de dados de caixa de diálogo (DDX) e a funcionalidade de navegação é incorporada `CRowset` (`MoveFirst`, `MoveNext`, `MovePrev`, e `MoveLast`) para automatizar a movimentação de dados entre os controles no formulário e os campos do conjunto de linhas. `COleDBRecordView` mantém o controle de posição do usuário no conjunto de linhas para que o modo de exibição de registro possa atualizar a interface do usuário e fornece um [OnMove](../../mfc/reference/coledbrecordview-class.md#onmove) método para atualizar o registro atual antes de passar para outro.  
  
 Você pode usar funções DDX com `COleDbRecordView` obter dados diretamente do conjunto de registros de banco de dados e exibi-lo em um controle de caixa de diálogo. Você deve usar o **funções DDX _** <strong>\*</strong> métodos (como `DDX_Text`), e não o **DDX_Field** <strong>\*</strong> funções (como `DDX_FieldText`) com `COleDbRecordView`.  
  
## <a name="see-also"></a>Consulte também  
 [Usando acessadores](../../data/oledb/using-accessors.md)   
 [Classe COleDBRecordView](../../mfc/reference/coledbrecordview-class.md)