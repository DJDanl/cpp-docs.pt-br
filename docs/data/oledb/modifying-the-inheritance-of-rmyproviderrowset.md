---
title: "Modificando a heran&#231;a de RMyProviderRowset | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "herança [C++]"
  - "RMyProviderRowset"
ms.assetid: 33089c90-98a4-43e7-8e67-d4bb137e267e
caps.latest.revision: 8
caps.handback.revision: 8
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Modificando a heran&#231;a de RMyProviderRowset
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Para adicionar a interface de `IRowsetLocate` somente leitura ao exemplo simples do provedor, modifique a herança de **RMyProviderRowset**.  Inicialmente, **RMyProviderRowset** herda de `CRowsetImpl`.  Você precisa modificá\-la para herdar de **CRowsetBaseImpl**.  
  
 Para fazer isso, crie uma nova classe, `CMyRowsetImpl`, em MyProviderRS.h:  
  
```  
////////////////////////////////////////////////////////////////////////  
// MyProviderRS.h  
  
template <class T, class Storage, class CreatorClass, class ArrayType = CAtlArray<Storage> >  
class CMyRowsetImpl:  
   public CRowsetImpl<T, Storage, CreatorClass, ArrayType, CSimpleRow, IRowsetLocateImpl< T, IRowsetLocate > >  
{  
...  
};  
```  
  
 Agora, edite o mapa da interface COM em MyProviderRS.h para ser:  
  
```  
BEGIN_COM_MAP(CMyRowsetImpl)  
   COM_INTERFACE_ENTRY(IRowsetLocate)  
   COM_INTERFACE_ENTRY_CHAIN(_RowsetBaseClass)  
END_COM_MAP()  
```  
  
 Isso cria um mapa da interface COM que indica `CMyRowsetImpl` para chamar **QueryInterface** para as interfaces de `IRowset` e de `IRowsetLocate` .  Para obter qualquer implementação para as outras classes de conjunto de linhas, o mapa vincula a classe de `CMyRowsetImpl` de volta à classe de **CRowsetBaseImpl** definida pelos modelos OLE DB; o mapa usa a macro de COM\_INTERFACE\_ENTRY\_CHAIN, com modelos OLE DB para examinar o mapa COM em **CRowsetBaseImpl** em resposta a uma chamada de `QueryInterface` .  
  
 Finalmente, link `RAgentRowset` a `CMyRowsetBaseImpl` alterando `RAgentRowset` para herdar de `CMyRowsetImpl`, como segue:  
  
```  
class RAgentRowset : public CMyRowsetImpl<RAgentRowset, CAgentMan, CMyProviderCommand>  
```  
  
 `RAgentRowset` pode usar a interface de `IRowsetLocate` para tirar proveito do restante da implementação da classe do conjunto de linhas.  
  
 Quando isso for feito, você pode [determinar dinamicamente as colunas retornadas ao consumidor](../../data/oledb/dynamically-determining-columns-returned-to-the-consumer.md).  
  
## Consulte também  
 [Melhorando o provedor somente leitura simples](../../data/oledb/enhancing-the-simple-read-only-provider.md)