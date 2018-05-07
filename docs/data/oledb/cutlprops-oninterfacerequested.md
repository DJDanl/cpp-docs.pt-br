---
title: 'Cutlprops:: Oninterfacerequested | Microsoft Docs'
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-data
ms.topic: reference
f1_keywords:
- CUtlProps
dev_langs:
- C++
helpviewer_keywords:
- OnInterfaceRequested method
ms.assetid: a5e1a879-cff3-4e01-b902-2249a152984f
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- data-storage
ms.openlocfilehash: 50a1f17294a91446e71a51ffdac6c5aec83f2c9a
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="cutlpropsoninterfacerequested"></a>CUtlProps::OnInterfaceRequested
Trata solicitações para uma interface opcional quando um consumidor chama um método em um objeto de interfaces de criação.  
  
## <a name="syntax"></a>Sintaxe  
  
```cpp
      virtual HRESULT CUtlPropsBase::OnInterfaceRequested(REFIID riid);  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `riid`  
 [in] O IID da interface solicitada. Para obter mais detalhes, consulte a descrição do `riid` parâmetro de `ICommand::Execute` no *referência do programador de DB OLE* (no *SDK do MDAC*).  
  
## <a name="remarks"></a>Comentários  
 **OnInterfaceRequested** trata das solicitações do cliente para uma interface opcional quando um consumidor chama um método em um objeto de interfaces de criação (como **IDBCreateSession**, **IDBCreateCommand**, `IOpenRowset`, ou `ICommand`). Ele define a propriedade OLE DB correspondente para a interface solicitada. Por exemplo, se o consumidor solicita **IID_IRowsetLocate**, **OnInterfaceRequested** define o **DBPROP_IRowsetLocate** interface. Isso mantém o estado correto durante a criação do conjunto de linhas.  
  
 Este método é chamado quando o consumidor chama **IOpenRowset:: OPENROWSET** ou `ICommand::Execute`.  
  
 Se um consumidor abre um objeto e solicita uma interface opcional, o provedor deve definir a propriedade associada a essa interface para `VARIANT_TRUE`. Para permitir o processamento da propriedade específica, **OnInterfaceRequested** é chamado antes do provedor **Execute** método é chamado. Por padrão, **OnInterfaceRequested** lida com as seguintes interfaces:  
  
-   `IRowsetLocate`  
  
-   `IRowsetChange`  
  
-   `IRowsetUpdate`  
  
-   **IConnectionPointContainer**  
  
-   `IRowsetScroll`  
  
 Se você deseja lidar com outras interfaces, substitua essa função em sua classe de origem, sessão, comando ou conjunto de linhas de dados para funções de processo. Sua substituição deve percorrer as interfaces de propriedades de conjunto normal/get para garantir que a definição de propriedades também define quaisquer propriedades de cadeia (consulte [OnPropertyChanged](../../data/oledb/cutlprops-onpropertychanged.md)).  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atldb.h  
  
## <a name="see-also"></a>Consulte também  
 [Classe CUtlProps](../../data/oledb/cutlprops-class.md)