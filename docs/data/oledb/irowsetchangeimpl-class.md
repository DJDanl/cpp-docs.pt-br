---
title: "Classe IRowsetChangeImpl | Microsoft Docs"
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
  - "ATL::IRowsetChangeImpl"
  - "IRowsetChangeImpl"
  - "ATL.IRowsetChangeImpl"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe IRowsetChangeImpl"
  - "provedores, atualizável"
  - "provedores atualizáveis, atualização imediata"
ms.assetid: 1e9fee15-ed9e-4387-af8f-215569beca6c
caps.latest.revision: 11
caps.handback.revision: 11
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe IRowsetChangeImpl
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

A implementação de modelos OLE DB da interface de [IRowsetChange](https://msdn.microsoft.com/en-us/library/ms715790.aspx) na especificação do OLE DB.  
  
## Sintaxe  
  
```  
template <  
   class T,   
   class Storage,   
   class BaseInterface = IRowsetChange,   
   class RowClass = CSimpleRow,   
   class MapClass = CAtlMap < RowClass::KeyType, RowClass* >   
>  
class ATL_NO_VTABLE IRowsetChangeImpl : public BaseInterface  
```  
  
#### Parâmetros  
 `T`  
 Uma classe derivada de `IRowsetChangeImpl`.  
  
 `Storage`  
 O registro do usuário.  
  
 `BaseInterface`  
 A classe base para a interface, como `IRowsetChange`.  
  
 `RowClass`  
 A unidade de armazenamento para o identificador da linha.  
  
 `MapClass`  
 A unidade de armazenamento para todas as alças de linha mantidos pelo provedor.  
  
## Membros  
  
### Métodos da interface \(usados com IRowsetChange\)  
  
|||  
|-|-|  
|[DeleteRows](../Topic/IRowsetChangeImpl::DeleteRows.md)|Exclui linhas do conjunto de linhas.|  
|[InsertRow](../../data/oledb/irowsetchangeimpl-insertrow.md)|Insere uma linha no conjunto de linhas.|  
|[SetData](../Topic/IRowsetChangeImpl::SetData.md)|Define valores de dados em uma ou mais colunas.|  
  
### Método de implementação \(retorno de chamada\)  
  
|||  
|-|-|  
|[FlushData](../../data/oledb/irowsetchangeimpl-flushdata.md)|Overidden pelo provedor para confirmar dados ao seu repositório.|  
  
## Comentários  
 Esta interface é responsável por operações de gravação imediata a um repositório de dados. “Imediata” significa que quando o usuário final \(pessoa que usa o consumidor\) faz todas as alterações, essas alterações serão transmitidas imediatamente ao repositório de dados \(e não pode ser desfeita\).  
  
 `IRowsetChangeImpl` implementa a interface OLE DB `IRowsetChange` , o que permite atualizar os valores das colunas nas linhas existentes, excluir linhas, e inserir novas linhas.  
  
 A implementação de modelos OLE DB oferece suporte a todos os métodos de base \(`SetData`, `InsertRow`, e `DeleteRows`\).  
  
> [!IMPORTANT]
>  É altamente recomendável que você leia a seguir documentação BEFORE de tentar implementar seu provedor:  
  
-   [Criando um provedor atualizável](../../data/oledb/creating-an-updatable-provider.md)  
  
-   Capítulo 6 de *OLE DB Programmer's Reference*  
  
-   Consulte também como a classe de `RUpdateRowset` é usada no exemplo de UpdatePV  
  
## Requisitos  
 **Header:** atldb.h  
  
## Consulte também  
 [Modelos de provedor de banco de dados OLE](../../data/oledb/ole-db-provider-templates-cpp.md)   
 [Arquitetura de modelo do provedor de banco de dados OLE](../../data/oledb/ole-db-provider-template-architecture.md)