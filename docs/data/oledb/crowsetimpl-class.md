---
title: Classe CRowsetImpl | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- CRowsetImpl
- ATL.CRowsetImpl
- ATL::CRowsetImpl
dev_langs:
- C++
helpviewer_keywords:
- CRowsetImpl class
ms.assetid: e97614b3-b11d-4806-a0d3-b9401331473f
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
- data-storage
ms.openlocfilehash: c126c757ae4776d0b2a5d2bec352ee8d58c4f0d4
ms.sourcegitcommit: 6002df0ac79bde5d5cab7bbeb9d8e0ef9920da4a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/14/2018
---
# <a name="crowsetimpl-class"></a>Classe CRowsetImpl
Fornece uma implementação padrão do conjunto de linhas OLE DB sem a necessidade de várias heranças de várias interfaces de implementação.  
  
## <a name="syntax"></a>Sintaxe

```cpp
template <  
   class T,  
   class Storage,  
   class CreatorClass,  
   class ArrayType = CAtlArray<Storage>,   
   class RowClass = CSimpleRow,   
   class RowsetInterface = IRowsetImpl <T, IRowset>   
>  
class CRowsetImpl :    
   public CComObjectRootEx<CreatorClass::_ThreadModel>,   
   public CRowsetBaseImpl<T, Storage, ArrayType, RowsetInterface>,   
   public IRowsetInfoImpl<T, CreatorClass::_PropClass>  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `T`  
 Classe do usuário que deriva de `CRowsetImpl`.  
  
 `Storage`  
 A classe de registro de usuário.  
  
 `CreatorClass`  
 A classe que contém propriedades de conjunto de linhas; normalmente o comando.  
  
 `ArrayType`  
 A classe que atuará como o armazenamento de dados do conjunto de linhas. Padrão desse parâmetro é `CAtlArray`, mas pode ser qualquer classe que suporta a funcionalidade necessária.  
  
## <a name="members"></a>Membros  
  
### <a name="methods"></a>Métodos  
  
|||  
|-|-|  
|[NameFromDBID](../../data/oledb/crowsetimpl-namefromdbid.md)|Extrai uma cadeia de caracteres de um **DBID** e copiá-lo para o `bstr` passado.|  
|[SetCommandText](../../data/oledb/crowsetimpl-setcommandtext.md)|Valida e armazena o **DBID**s em duas cadeias de caracteres ([m_strCommandText](../../data/oledb/crowsetimpl-m-strcommandtext.md) e [m_strIndexText](../../data/oledb/crowsetimpl-m-strindextext.md)).|  
  
### <a name="overridable-methods"></a>Métodos substituíveis  
  
|||  
|-|-|  
|[GetColumnInfo](../../data/oledb/crowsetimpl-getcolumninfo.md)|Recupera informações de coluna para uma solicitação de cliente específico.|  
|[GetCommandFromID](../../data/oledb/crowsetimpl-getcommandfromid.md)|Verifica se um ou ambos os parâmetros contêm valores de cadeia de caracteres e, em caso afirmativo, copia os valores de cadeia de caracteres para os membros de dados [m_strCommandText](../../data/oledb/crowsetimpl-m-strcommandtext.md) e [m_strIndexText](../../data/oledb/crowsetimpl-m-strindextext.md).|  
|[ValidateCommandID](../../data/oledb/crowsetimpl-validatecommandid.md)|Verifica para ver se um ou ambos **DBID**s contêm valores de cadeia de caracteres e, nesse caso, copiá-los em seus membros de dados [m_strCommandText](../../data/oledb/crowsetimpl-m-strcommandtext.md) e [m_strIndexText](../../data/oledb/crowsetimpl-m-strindextext.md).|  
  
### <a name="data-members"></a>Membros de Dados  
  
|||  
|-|-|  
|[m_rgRowData](../../data/oledb/crowsetimpl-m-rgrowdata.md)|Por padrão, um `CAtlArray` que templatizes no argumento de modelo de registro de usuário `CRowsetImpl`. Outra classe de tipo de matriz pode ser usado por alterar o `ArrayType` argumento de modelo `CRowsetImpl`.|  
|[m_strCommandText](../../data/oledb/crowsetimpl-m-strcommandtext.md)|Contém o comando inicial do conjunto de linhas.|  
|[m_strIndexText](../../data/oledb/crowsetimpl-m-strindextext.md)|Contém o índice inicial do conjunto de linhas.|  
  
## <a name="remarks"></a>Comentários  
 `CRowsetImpl` fornece substituições na forma de upcasts estáticos. Os métodos de controlam a maneira na qual um determinado conjunto de linhas será validado, o texto do comando. Você pode criar seus próprios `CRowsetImpl`-classe de estilo, fazendo com que as interfaces de implementação herdada vários. O único método para o qual você deve fornecer a implementação é **Execute**. Dependendo de qual tipo de conjunto de linhas que você está criando, os métodos creator esperará assinaturas diferentes para **Execute**. Por exemplo, se você estiver usando um `CRowsetImpl`-derivado da classe para implementar um conjunto de linhas de esquema, o **Execute** método terá a seguinte assinatura:  
  
 `HRESULT Execute(LONG* pcRows, ULONG cRestrictions, const VARIANT* rgRestrictions)`  
  
 Se você estiver criando um `CRowsetImpl`-derivado da classe para implementar um comando ou conjunto de linhas da sessão, o **Execute** método terá a seguinte assinatura:  
  
 `HRESULT Execute(LONG* pcRows, DBPARAMS* pParams)`  
  
 Para implementar qualquer uma da `CRowsetImpl`-derivado **Execute** métodos, você deve preencher seus buffers de dados interno ([m_rgRowData](../../data/oledb/crowsetimpl-m-rgrowdata.md)).  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atldb.h