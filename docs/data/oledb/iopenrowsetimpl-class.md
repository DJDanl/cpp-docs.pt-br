---
title: Classe IOpenRowsetImpl | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords: IOpenRowsetImpl
dev_langs: C++
helpviewer_keywords: IOpenRowsetImpl class
ms.assetid: d259cedc-1db4-41cf-bc9f-5030907ab486
caps.latest.revision: "10"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.openlocfilehash: 89a37274fd4040b24c36983fea968674acf4fcab
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
---
# <a name="iopenrowsetimpl-class"></a>Classe IOpenRowsetImpl
Fornece a implementação para o `IOpenRowset` interface.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
template <class SessionClass>  
class IOpenRowsetImpl : public IOpenRowset  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `SessionClass`  
 A classe derivada de `IOpenRowsetImpl`.  
  
## <a name="members"></a>Membros  
  
### <a name="methods"></a>Métodos  
  
|||  
|-|-|  
|[CreateRowset](../../data/oledb/iopenrowsetimpl-createrowset.md)|Cria um objeto de conjunto de linhas. Não é chamado diretamente pelo usuário.|  
|[OpenRowset](../../data/oledb/iopenrowsetimpl-openrowset.md)|Abre e retorna um conjunto de linhas que inclui todas as linhas de uma única tabela base ou índice. (Não em ATLDB. H)|  
  
## <a name="remarks"></a>Comentários  
 O [IOpenRowset](https://msdn.microsoft.com/en-us/library/ms716946.aspx) interface é obrigatória para um objeto de sessão. Ele abre e retorna um conjunto de linhas que inclui todas as linhas de uma única tabela base ou índice.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atldb.h  
  
## <a name="see-also"></a>Consulte também  
 [Modelos de provedor do OLE DB](../../data/oledb/ole-db-provider-templates-cpp.md)   
 [Arquitetura de modelo do provedor do OLE DB](../../data/oledb/ole-db-provider-template-architecture.md)