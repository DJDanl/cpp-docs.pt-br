---
title: "Classe CStreamRowset | Microsoft Docs"
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
  - "ATL::CStreamRowset<TAccessor>"
  - "ATL::CStreamRowset"
  - "CStreamRowset"
  - "ATL.CStreamRowset<TAccessor>"
  - "ATL.CStreamRowset"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe CStreamRowset"
ms.assetid: a106e953-a38a-464e-8ea5-28963d9e4811
caps.latest.revision: 11
caps.handback.revision: 11
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe CStreamRowset
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Usado em uma declaração de `CCommand` ou de `CTable` .  
  
## Sintaxe  
  
```  
template <class TAccessor = CAccessorBase>  
class CStreamRowset  
```  
  
#### Parâmetros  
 `TAccessor`  
 Uma classe do acessador.  
  
## Membros  
  
### Métodos  
  
|||  
|-|-|  
|[CStreamRowset](../../data/oledb/cstreamrowset-cstreamrowset.md)|Construtor.  Cria uma instância e inicializa o objeto de `CStreamRowset` .|  
|[Fechar](../../data/oledb/cstreamrowset-close.md)|Libera o ponteiro de interface de [ISequentialStream](https://msdn.microsoft.com/en-us/library/ms718035.aspx) na classe.|  
  
## Comentários  
 Use `CStreamRowset` em sua declaração de `CCommand` ou de `CTable` , por exemplo:  
  
 [!code-cpp[NVC_OLEDB_Consumer#11](../../data/oledb/codesnippet/CPP/cstreamrowset-class_1.cpp)]  
  
 ou  
  
 [!code-cpp[NVC_OLEDB_Consumer#12](../../data/oledb/codesnippet/CPP/cstreamrowset-class_2.cpp)]  
  
 `ICommand::Execute` retorna um ponteiro de `ISequentialStream` , que é armazenado em `m_spStream`.  Você usa o método de **Ler** \(para recuperar os dados de cadeia de caracteres Unicode\) em formato XML.  Por exemplo:  
  
 [!code-cpp[NVC_OLEDB_Consumer#13](../../data/oledb/codesnippet/CPP/cstreamrowset-class_3.cpp)]  
  
 SQL Server 2000 executa a formatação XML, e retornará todas as linhas do conjunto de linhas como uma cadeia de caracteres XML.  
  
> [!NOTE]
>  Esse recurso funciona apenas com o SQL Server 2000.  
  
## Requisitos  
 **Header:** atldbcli.h  
  
## Consulte também  
 [Modelos de consumidor de banco de dados OLE](../../data/oledb/ole-db-consumer-templates-cpp.md)   
 [Referência dos modelos de consumidor de banco de dados OLE](../../data/oledb/ole-db-consumer-templates-reference.md)