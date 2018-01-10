---
title: 'Cutlprops:: Oninterfacerequested | Microsoft Docs'
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords: CUtlProps
dev_langs: C++
helpviewer_keywords: OnInterfaceRequested method
ms.assetid: a5e1a879-cff3-4e01-b902-2249a152984f
caps.latest.revision: "8"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
- data-storage
ms.openlocfilehash: c458eaf7c1e41ade5d29fa020bacfebb2b278e82
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="cutlpropsoninterfacerequested"></a>CUtlProps::OnInterfaceRequested
Trata solicitações para uma interface opcional quando um consumidor chama um método em um objeto de interfaces de criação.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
  
      virtual HRESULT CUtlPropsBase::OnInterfaceRequested(  
   REFIID riid  
);  
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