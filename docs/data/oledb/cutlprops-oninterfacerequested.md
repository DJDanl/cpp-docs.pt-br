---
title: "CUtlProps::OnInterfaceRequested | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
f1_keywords: 
  - "CUtlProps"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Método OnInterfaceRequested"
ms.assetid: a5e1a879-cff3-4e01-b902-2249a152984f
caps.latest.revision: 8
caps.handback.revision: 8
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# CUtlProps::OnInterfaceRequested
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Trata solicitações para uma interface opcional quando um consumidor chama um método em uma das interfaces de criação do objeto.  
  
## Sintaxe  
  
```  
  
      virtual HRESULT CUtlPropsBase::OnInterfaceRequested(  
   REFIID riid  
);  
```  
  
#### Parâmetros  
 `riid`  
 \[in\] O IID da interface solicitada.  Para obter mais detalhes, consulte a descrição do parâmetro `riid` de `ICommand::Execute` na *referência do programador de OLE DB* \(no *MDAC SDK*\).  
  
## Comentários  
 **OnInterfaceRequested** trata solicitações de consumidor para uma interface opcional quando um consumidor chama um método em uma das interfaces de criação de objeto \(como **IDBCreateSession**, **IDBCreateCommand**, `IOpenRowset`, ou `ICommand`\).  Define a propriedade OLE DB correspondente para a interface solicitada.  Por exemplo, se o consumidor solicita **IID\_IRowsetLocate**, **OnInterfaceRequested** define a interface de **DBPROP\_IRowsetLocate** .  Fazer isso mantém o estado correto durante a criação do conjunto de linhas.  
  
 Este método é chamado quando o consumidor chama **IOpenRowset::OpenRowset** ou `ICommand::Execute`.  
  
 Se um consumidor abre um objeto e solicita uma interface opcional, o provedor deve definir a propriedade associada a essa interface a `VARIANT_TRUE`.  Para permitir que o processamento com específico, **OnInterfaceRequested** é chamado antes que o método de **Executar** do provedor foi chamado.  Por padrão, **OnInterfaceRequested** trata as seguintes interfaces:  
  
-   `IRowsetLocate`  
  
-   `IRowsetChange`  
  
-   `IRowsetUpdate`  
  
-   **IConnectionPointContainer**  
  
-   `IRowsetScroll`  
  
 Se você quiser tratar outras interfaces, substitua esta função na fonte de dados, sessão, comando, ou a classe do conjunto de linhas processar funções.  A substituição deve passar pelo conjunto comum das interfaces\/obtém propriedades para garantir que definir propriedades também configure todas as propriedades [OnPropertyChanged](../../data/oledb/cutlprops-onpropertychanged.md)encadeadas \(consulte\).  
  
## Requisitos  
 **Header:** atldb.h  
  
## Consulte também  
 [Classe CUtlProps](../../data/oledb/cutlprops-class.md)