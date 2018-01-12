---
title: Classe CStreamRowset | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- ATL::CStreamRowset<TAccessor>
- ATL::CStreamRowset
- CStreamRowset
- ATL.CStreamRowset<TAccessor>
- ATL.CStreamRowset
dev_langs: C++
helpviewer_keywords: CStreamRowset class
ms.assetid: a106e953-a38a-464e-8ea5-28963d9e4811
caps.latest.revision: "11"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
- data-storage
ms.openlocfilehash: 32c4aa20f805ee141918e7c073709ec33b4d29ca
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="cstreamrowset-class"></a>Classe CStreamRowset
Usado em uma `CCommand` ou `CTable` declaração.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
template <class TAccessor = CAccessorBase>  
class CStreamRowset  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `TAccessor`  
 Uma classe de acessador.  
  
## <a name="members"></a>Membros  
  
### <a name="methods"></a>Métodos  
  
|||  
|-|-|  
|[CStreamRowset](../../data/oledb/cstreamrowset-cstreamrowset.md)|Construtor. Cria e inicializa o `CStreamRowset` objeto.|  
|[Fechar](../../data/oledb/cstreamrowset-close.md)|Versões de [ISequentialStream](https://msdn.microsoft.com/en-us/library/ms718035.aspx) ponteiro de interface na classe.|  
  
## <a name="remarks"></a>Comentários  
 Use `CStreamRowset` no seu `CCommand` ou `CTable` declaração, por exemplo:  
  
 [!code-cpp[NVC_OLEDB_Consumer#11](../../data/oledb/codesnippet/cpp/cstreamrowset-class_1.cpp)]  
  
 ou  
  
 [!code-cpp[NVC_OLEDB_Consumer#12](../../data/oledb/codesnippet/cpp/cstreamrowset-class_2.cpp)]  
  
 `ICommand::Execute`Retorna um `ISequentialStream` ponteiro, que é armazenado em `m_spStream`. Você usa o **leitura** método para recuperar os dados (cadeia de caracteres Unicode) em formato XML. Por exemplo:  
  
 [!code-cpp[NVC_OLEDB_Consumer#13](../../data/oledb/codesnippet/cpp/cstreamrowset-class_3.cpp)]  
  
 SQL Server 2000 executa a formatação de XML e retorna todas as colunas e todas as linhas do conjunto de linhas como uma cadeia de caracteres XML.  
  
> [!NOTE]
>  Esse recurso funciona apenas com o SQL Server 2000.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atldbcli.h  
  
## <a name="see-also"></a>Consulte também  
 [Modelos de consumidor OLE DB](../../data/oledb/ole-db-consumer-templates-cpp.md)   
 [Referência de modelos de consumidor do OLE DB](../../data/oledb/ole-db-consumer-templates-reference.md)