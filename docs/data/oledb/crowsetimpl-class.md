---
title: "Classe CRowsetImpl | Microsoft Docs"
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
  - "CRowsetImpl"
  - "ATL.CRowsetImpl"
  - "ATL::CRowsetImpl"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe CRowsetImpl"
ms.assetid: e97614b3-b11d-4806-a0d3-b9401331473f
caps.latest.revision: 12
caps.handback.revision: 12
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe CRowsetImpl
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Fornece uma implementação padrão de conjunto de linhas OLE DB sem exigir a herança múltipla das interfaces de implementação.  
  
## Sintaxe  
  
```  
template <  
   class T,  
   class Storage,  
   class CreatorClass,  
   class ArrayType = CAtlArray<Storage>,   
   class RowClass = CSimpleRow,   
   class RowsetInterface = IRowsetImpl < T, IRowset >   
>  
class CRowsetImpl :    
   public CComObjectRootEx<CreatorClass::_ThreadModel>,   
   public CRowsetBaseImpl<T, Storage, ArrayType, RowsetInterface>,   
   public IRowsetInfoImpl<T, CreatorClass::_PropClass>  
```  
  
#### Parâmetros  
 `T`  
 A classe do usuário que se deriva de `CRowsetImpl`.  
  
 `Storage`  
 A classe de registro do usuário.  
  
 `CreatorClass`  
 A classe que contém as propriedades do conjunto de linhas; normalmente o comando.  
  
 `ArrayType`  
 A classe que atuará como armazenamento para os dados do conjunto de linhas.  Esse parâmetro assume como padrão `CAtlArray`, mas pode ser qualquer classe que ofereça suporte à funcionalidade necessária.  
  
## Membros  
  
### Métodos  
  
|||  
|-|-|  
|[NameFromDBID](../../data/oledb/crowsetimpl-namefromdbid.md)|Extrai uma cadeia de caracteres de **DBID** e copiá\-lo em `bstr` passado.|  
|[SetCommandText](../../data/oledb/crowsetimpl-setcommandtext.md)|Valida e armazena **DBID**s em duas cadeias de caracteres \([m\_strCommandText](../../data/oledb/crowsetimpl-m-strcommandtext.md) e [m\_strIndexText](../../data/oledb/crowsetimpl-m-strindextext.md)\).|  
  
### Métodos substituível  
  
|||  
|-|-|  
|[GetColumnInfo](../../data/oledb/crowsetimpl-getcolumninfo.md)|Recupera informações de coluna para uma solicitação de cliente específica.|  
|[GetCommandFromID](../../data/oledb/crowsetimpl-getcommandfromid.md)|Verifica se um ou ambos os parâmetros contêm valores de cadeia de caracteres e, em caso afirmativo, copia os valores da cadeia de caracteres os membros de dados [m\_strCommandText](../../data/oledb/crowsetimpl-m-strcommandtext.md) e [m\_strIndexText](../../data/oledb/crowsetimpl-m-strindextext.md).|  
|[ValidateCommandID](../../data/oledb/crowsetimpl-validatecommandid.md)|Verifica se um ou ambos **DBID**s contém valores de cadeia de caracteres e, em caso afirmativo, copiá\-los para os membros de dados [m\_strCommandText](../../data/oledb/crowsetimpl-m-strcommandtext.md) e [m\_strIndexText](../../data/oledb/crowsetimpl-m-strindextext.md).|  
  
### Membros de dados  
  
|||  
|-|-|  
|[m\_rgRowData](../../data/oledb/crowsetimpl-m-rgrowdata.md)|Por padrão, `CAtlArray` que templatizes no argumento do modelo de registro de usuário a `CRowsetImpl`.  Outra classe do tipo de matriz pode ser usada alterando o argumento do modelo de `ArrayType` a `CRowsetImpl`.|  
|[m\_strCommandText](../../data/oledb/crowsetimpl-m-strcommandtext.md)|Contém o comando inicial do conjunto de linhas.|  
|[m\_strIndexText](../../data/oledb/crowsetimpl-m-strindextext.md)|Contém o índice inicial do conjunto de linhas.|  
  
## Comentários  
 `CRowsetImpl` fornece substituições na forma de upcasts estáticos.  Os métodos controlam o modo no qual um determinado conjunto de linhas validará o texto do comando.  Você pode criar seu próprio `CRowsetImpl`\- classe de estilo fazendo as interfaces de implementação vários herdadas.  O único método para o qual você deve fornecer uma implementação é **Executar**.  Dependendo do tipo de conjunto de linhas estiver sendo criado, os métodos do designer esperarão assinaturas diferentes para **Executar**.  Por exemplo, se você estiver usando `CRowsetImpl`\- classe derivada a implementar um conjunto de linhas de esquema, o método de **Executar** terá a seguinte assinatura:  
  
 `HRESULT Execute(LONG* pcRows, ULONG cRestrictions, const VARIANT* rgRestrictions)`  
  
 Se você estiver criando `CRowsetImpl`\- classe derivada a implementar um conjunto de linhas de comando ou de sessão, o método de **Executar** terá a seguinte assinatura:  
  
 `HRESULT Execute(LONG* pcRows, DBPARAMS* pParams)`  
  
 Para implementar qualquer um de `CRowsetImpl`\- métodos derivados de **Executar** , você deve popular seus buffers de dados internas \([m\_rgRowData](../../data/oledb/crowsetimpl-m-rgrowdata.md)\).  
  
## Requisitos  
 **Header:** atldb.h