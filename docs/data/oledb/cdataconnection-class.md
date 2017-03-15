---
title: "Classe CDataConnection | Microsoft Docs"
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
  - "ATL::CDataConnection"
  - "ATL.CDataConnection"
  - "CDataConnection"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe CDataConnection"
ms.assetid: 77432d85-4e20-49ec-a0b0-142137828471
caps.latest.revision: 13
caps.handback.revision: 13
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe CDataConnection
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Gerencia a conexão com a fonte de dados.  
  
## Sintaxe  
  
```  
class CDataConnection  
```  
  
## Membros  
  
### Métodos  
  
|||  
|-|-|  
|[CDataConnection](../../data/oledb/cdataconnection-cdataconnection.md)|Construtor.  Cria uma instância e inicializa um objeto de `CDataConnection` .|  
|[Copiar](../../data/oledb/cdataconnection-copy.md)|Cria uma cópia de uma conexão de dados existente.|  
|[Abrir](../../data/oledb/cdataconnection-open.md)|Abre uma conexão a uma fonte de dados usando uma cadeia de caracteres de inicialização.|  
|[OpenNewSession](../../data/oledb/cdataconnection-opennewsession.md)|Abre uma nova sessão na conexão atual.|  
  
### Operadores  
  
|||  
|-|-|  
|[operador BOOL](../../data/oledb/cdataconnection-operator-bool.md)|Determina se a sessão atual será aberta ou não.|  
|[bool do operador](../../data/oledb/cdataconnection-operator-bool-ole-db.md)|Determina se a sessão atual será aberta ou não.|  
|[operador CDataSource&](../../data/oledb/cdataconnection-operator-cdatasource-amp.md)|Retorna uma referência ao objeto contido de `CDataSource` .|  
|[operador CDataSource\*](../Topic/CDataConnection::operator%20CDataSource*.md)|Retorna um ponteiro para o objeto contido de `CDataSource` .|  
|[operador CSession&](../../data/oledb/cdataconnection-operator-csession-amp.md)|Retorna uma referência ao objeto contido de `CSession` .|  
|[operador CSession\*](../../data/oledb/cdataconnection-operator-csession-star.md)|Retorna um ponteiro para o objeto contido de `CSession` .|  
  
## Comentários  
 uma classe`CDataConnection` é útil para criar clientes como encapsula objetos necessários para a fonte de dados \(e\) e qualquer sessão de trabalho que você precisa fazer ao conectar\-se a uma fonte de dados  
  
 Sem `CDataConnection`, você tem que criar um objeto de `CDataSource` , chame o método de [OpenFromInitializationString](../../data/oledb/cdatasource-openfrominitializationstring.md) , para criar uma instância de um objeto de [CSession](../../data/oledb/csession-class.md) , chame o método de [Abrir](../../data/oledb/csession-open.md) , para criar um objeto de [CCommand](../../data/oledb/ccommand-class.md) e chamar seu **Abrir**\* métodos.  
  
 Com `CDataConnection`, você só precisa criar um objeto de conexão, passa uma cadeia de caracteres de inicialização, então o usa essa conexão aos comandos abertos.  Se você planeja usar na conexão com o base de dados repetidamente, é uma boa ideia manter a conexão aberta, e `CDataConnection` fornece um modo conveniente de fazer isso.  
  
> [!NOTE]
>  Se você estiver criando um aplicativo de base de dados que precisa tratar várias sessões, você precisará usar [OpenNewSession](../../data/oledb/cdataconnection-opennewsession.md).  
  
## Requisitos  
 **Header:** atldbcli.h  
  
## Consulte também  
 [Modelos de consumidor de banco de dados OLE](../../data/oledb/ole-db-consumer-templates-cpp.md)   
 [Referência dos modelos de consumidor de banco de dados OLE](../../data/oledb/ole-db-consumer-templates-reference.md)