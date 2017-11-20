---
title: Classe CDataConnection | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- ATL::CDataConnection
- ATL.CDataConnection
- CDataConnection
dev_langs: C++
helpviewer_keywords: CDataConnection class
ms.assetid: 77432d85-4e20-49ec-a0b0-142137828471
caps.latest.revision: "13"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.openlocfilehash: e7ce953304792e5c04c406025a656c22eb8eee13
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
---
# <a name="cdataconnection-class"></a>Classe CDataConnection
Gerencia a conexão com a fonte de dados.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
class CDataConnection  
```  
  
## <a name="members"></a>Membros  
  
### <a name="methods"></a>Métodos  
  
|||  
|-|-|  
|[CDataConnection](../../data/oledb/cdataconnection-cdataconnection.md)|Construtor. Cria e inicializa um `CDataConnection` objeto.|  
|[Copiar](../../data/oledb/cdataconnection-copy.md)|Cria uma cópia de uma conexão de dados existente.|  
|[Abrir](../../data/oledb/cdataconnection-open.md)|Abre uma conexão com uma fonte de dados usando uma cadeia de caracteres de inicialização.|  
|[OpenNewSession](../../data/oledb/cdataconnection-opennewsession.md)|Abre uma nova sessão em que a conexão atual.|  
  
### <a name="operators"></a>Operadores  
  
|||  
|-|-|  
|[operador BOOL](../../data/oledb/cdataconnection-operator-bool.md)|Determina se a sessão atual está aberta ou não.|  
|[operator bool](../../data/oledb/cdataconnection-operator-bool-ole-db.md)|Determina se a sessão atual está aberta ou não.|  
|[operador CDataSource &](../../data/oledb/cdataconnection-operator-cdatasource-amp.md)|Retorna uma referência para o contido `CDataSource` objeto.|  
|[operador CDataSource *](../../data/oledb/cdataconnection-operator-cdatasource-star.md)|Retorna um ponteiro para o contido `CDataSource` objeto.|  
|[operador CSession &](../../data/oledb/cdataconnection-operator-csession-amp.md)|Retorna uma referência para o contido `CSession` objeto.|  
|[operador CSession *](../../data/oledb/cdataconnection-operator-csession-star.md)|Retorna um ponteiro para o contido `CSession` objeto.|  
  
## <a name="remarks"></a>Comentários  
 `CDataConnection`é uma classe útil para criar clientes porque ele encapsula os objetos necessários (fonte de dados e sessão) e parte do trabalho que você precisa fazer ao se conectar a uma fonte de dados  
  
 Sem `CDataConnection`, você precisa criar um `CDataSource` de objeto, chame seu [OpenFromInitializationString](../../data/oledb/cdatasource-openfrominitializationstring.md) método, em seguida, crie uma instância de um [CSession](../../data/oledb/csession-class.md) de objeto, chame seu [ Abra](../../data/oledb/csession-open.md) método, em seguida, criar um [CCommand](../../data/oledb/ccommand-class.md) objeto e chame seu **abrir*** métodos.  
  
 Com `CDataConnection`, você só precisa criar um objeto de conexão, passá-lo em uma cadeia de caracteres de inicialização e usar essa conexão para abrir os comandos. Se você planeja usar sua conexão ao banco de dados repetidamente, é recomendável manter a conexão aberta, e `CDataConnection` fornece uma maneira conveniente de fazer isso.  
  
> [!NOTE]
>  Se você estiver criando um aplicativo de banco de dados que precisa lidar com várias sessões, você precisará usar [OpenNewSession](../../data/oledb/cdataconnection-opennewsession.md).  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atldbcli.h  
  
## <a name="see-also"></a>Consulte também  
 [Modelos de consumidor OLE DB](../../data/oledb/ole-db-consumer-templates-cpp.md)   
 [Referência de modelos de consumidor do OLE DB](../../data/oledb/ole-db-consumer-templates-reference.md)