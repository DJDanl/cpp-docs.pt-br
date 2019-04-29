---
title: Classe CRowsetImpl
ms.date: 11/04/2016
f1_keywords:
- CRowsetImpl
- ATL.CRowsetImpl
- ATL::CRowsetImpl
- CRowsetImpl.NameFromDBID
- CRowsetImpl::NameFromDBID
- CRowsetImpl.SetCommandText
- CRowsetImpl::SetCommandText
- GetColumnInfo
- CRowsetImpl.GetColumnInfo
- CRowsetImpl::GetColumnInfo
- CRowsetImpl::GetCommandFromID
- GetCommandFromID
- CRowsetImpl.GetCommandFromID
- CRowsetImpl.ValidateCommandID
- CRowsetImpl::ValidateCommandID
- CRowsetImpl.m_rgRowData
- CRowsetImpl::m_rgRowData
- CRowsetImpl::m_strCommandText
- CRowsetImpl.m_strCommandText
- CRowsetImpl::m_strIndexText
- CRowsetImpl.m_strIndexText
helpviewer_keywords:
- CRowsetImpl class
- NameFromDBID method
- SetCommandText method
- GetColumnInfo method
- GetCommandFromID method
- ValidateCommandID method
- m_rgRowData
- m_strCommandText
- m_strIndexText
ms.assetid: e97614b3-b11d-4806-a0d3-b9401331473f
ms.openlocfilehash: 1fac3a74ca259fe3b680355fadc7f9bbd6e3cc13
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62368702"
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

### <a name="parameters"></a>Parâmetros

*T*<br/>
A classe do usuário que é derivada de `CRowsetImpl`.

*Armazenamento*<br/>
A classe de registro de usuário.

*CreatorClass*<br/>
A classe que contém as propriedades para o conjunto de linhas; normalmente o comando.

*ArrayType*<br/>
A classe que atuará como o armazenamento para dados do conjunto de linhas. Padrão desse parâmetro é `CAtlArray`, mas pode ser qualquer classe compatível com a funcionalidade necessária.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atldb.h

## <a name="members"></a>Membros

### <a name="methods"></a>Métodos

|||
|-|-|
|[NameFromDBID](#namefromdbid)|Extrai uma cadeia de caracteres de um `DBID` e o copia para o *bstr* passado.|
|[SetCommandText](#setcommandtext)|Valida e armazena o `DBID`s em duas cadeias de caracteres ([m_strCommandText](../../data/oledb/crowsetimpl-m-strcommandtext.md) e [m_strIndexText](../../data/oledb/crowsetimpl-m-strindextext.md)).|

### <a name="overridable-methods"></a>Métodos substituíveis

|||
|-|-|
|[GetColumnInfo](#getcolumninfo)|Recupera informações de coluna para uma solicitação de cliente específico.|
|[GetCommandFromID](#getcommandfromid)|Verifica se um ou ambos os parâmetros contêm valores de cadeia de caracteres e, em caso afirmativo, copia os valores de cadeia de caracteres para os membros de dados [m_strCommandText](../../data/oledb/crowsetimpl-m-strcommandtext.md) e [m_strIndexText](../../data/oledb/crowsetimpl-m-strindextext.md).|
|[ValidateCommandID](#validatecommandid)|Verifica para ver se qualquer uma ou ambas `DBID`s contêm valores de cadeia de caracteres e, nesse caso, copiá-los em seus membros de dados [m_strCommandText](../../data/oledb/crowsetimpl-m-strcommandtext.md) e [m_strIndexText](../../data/oledb/crowsetimpl-m-strindextext.md).|

### <a name="data-members"></a>Membros de Dados

|||
|-|-|
|[m_rgRowData](#rgrowdata)|Por padrão, uma `CAtlArray` que templatizes sobre o argumento de modelo de registro de usuário para `CRowsetImpl`. Outra classe de tipo de matriz pode ser usado, alterando a `ArrayType` argumento de modelo para `CRowsetImpl`.|
|[m_strCommandText](#strcommandtext)|Contém o comando de inicial do conjunto de linhas.|
|[m_strIndexText](#strindextext)|Contém o índice inicial do conjunto de linhas.|

## <a name="remarks"></a>Comentários

`CRowsetImpl` fornece substituições na forma de upcasts estáticos. Os métodos de controlam a maneira na qual um determinado conjunto de linhas validará o texto do comando. Você pode criar seus próprios `CRowsetImpl`-classe de estilo, tornando suas interfaces de implementação herdada de vários. O único método para o qual você deve fornecer a implementação é `Execute`. Dependendo de qual tipo de conjunto de linhas que você está criando, os métodos de criador esperam assinaturas diferentes para `Execute`. Por exemplo, se você estiver usando um `CRowsetImpl`-derivado da classe para implementar um conjunto de linhas de esquema, o `Execute` método terá a seguinte assinatura:

`HRESULT Execute(LONG* pcRows, ULONG cRestrictions, const VARIANT* rgRestrictions)`

Se você estiver criando um `CRowsetImpl`-derivado da classe para implementar um comando ou conjunto de linhas da sessão, o `Execute` método terá a seguinte assinatura:

`HRESULT Execute(LONG* pcRows, DBPARAMS* pParams)`

Para implementar qualquer uma da `CRowsetImpl`-derivado `Execute` métodos, você deve preencher seus buffers de dados internos ([m_rgRowData](../../data/oledb/crowsetimpl-m-rgrowdata.md)).

## <a name="namefromdbid"></a> CRowsetImpl::NameFromDBID

Extrai uma cadeia de caracteres de um `DBID` e o copia para o *bstr* passado.

### <a name="syntax"></a>Sintaxe

```cpp
HRESULT CRowsetBaseImpl::NameFromDBID(DBID* pDBID,
   CComBSTR& bstr,
   bool bIndex);
```

#### <a name="parameters"></a>Parâmetros

*pDBID*<br/>
[in] Um ponteiro para o `DBID` da qual extrair uma cadeia de caracteres.

*bstr*<br/>
[in] Um [CComBSTR](../../atl/reference/ccombstr-class.md) referência para colocar uma cópia do `DBID` cadeia de caracteres.

*bIndex*<br/>
[in] **verdadeira** se um índice `DBID`; **falsos** se uma tabela `DBID`.

### <a name="return-value"></a>Valor de retorno

Um HRESULT padrão. Dependendo se o `DBID` é uma tabela ou um índice (indicada por *bIndex*), o método retornará DB_E_NOINDEX ou DB_E_NOTABLE.

### <a name="remarks"></a>Comentários

Esse método é chamado pelo `CRowsetImpl` implementací [ValidateCommandID](../../data/oledb/crowsetimpl-validatecommandid.md) e [GetCommandFromID](../../data/oledb/crowsetimpl-getcommandfromid.md).

## <a name="setcommandtext"></a> CRowsetImpl::SetCommandText

Valida e armazena o `DBID`s em duas cadeias de caracteres ([m_strCommandText](../../data/oledb/crowsetimpl-m-strcommandtext.md) e [m_strIndexText](../../data/oledb/crowsetimpl-m-strindextext.md)).

### <a name="syntax"></a>Sintaxe

```cpp
HRESULT CRowsetBaseImpl::SetCommandText(DBID* pTableID,
   DBID* pIndexID);
```

#### <a name="parameters"></a>Parâmetros

*pTableID*<br/>
[in] Um ponteiro para o `DBID` que representa a ID da tabela.

*pIndexID*<br/>
[in] Um ponteiro para o `DBID` representando a ID de índice.

### <a name="return-value"></a>Valor de retorno

Um HRESULT padrão.

### <a name="remarks"></a>Comentários

O `SetCommentText` método é chamado pela `CreateRowset`, um estático modelada método do `IOpenRowsetImpl`.

Este método delega seu trabalho, chamando [ValidateCommandID](../../data/oledb/crowsetimpl-validatecommandid.md) e [GetCommandFromID](../../data/oledb/crowsetimpl-getcommandfromid.md) por meio de um ponteiro upcasted.

## <a name="getcolumninfo"></a> CRowsetImpl::GetColumnInfo

Recupera informações de coluna para uma solicitação de cliente específico.

### <a name="syntax"></a>Sintaxe

```cpp
static ATLCOLUMNINFO* CRowsetBaseImpl::GetColumnInfo(T* pv,
   ULONG* pcCols);
```

#### <a name="parameters"></a>Parâmetros

*pv*<br/>
[in] Um ponteiro para o usuário `CRowsetImpl` classe derivada.

*pcCols*<br/>
[in] Um ponteiro (saída) para o número de colunas retornadas.

### <a name="return-value"></a>Valor de retorno

Um ponteiro para um estático `ATLCOLUMNINFO` estrutura.

### <a name="remarks"></a>Comentários

Esse método é uma substituição avançada.

Esse método é chamado por várias classes de implementação base para recuperar informações de coluna para uma solicitação de cliente específico. Geralmente, esse método seria chamado pelo `IColumnsInfoImpl`. Se você substituir esse método, você deve colocar a versão do método no seu `CRowsetImpl`-classe derivada. Como o método pode ser colocado em uma classe não transformado em modelo, você deve alterar *VP* ao apropriado `CRowsetImpl`-classe derivada.

O exemplo a seguir demonstra `GetColumnInfo` uso. Neste exemplo, `CMyRowset` é um `CRowsetImpl`-classe derivada. Para substituir `GetColumnInfo` para todas as instâncias dessa classe, coloque o seguinte método ao `CMyRowset` definição de classe:

[!code-cpp[NVC_OLEDB_Provider#1](../../data/oledb/codesnippet/cpp/crowsetimpl-getcolumninfo_1.h)]

## <a name="getcommandfromid"></a> CRowsetImpl::GetCommandFromID

Verifica se um ou ambos os parâmetros contêm valores de cadeia de caracteres e, em caso afirmativo, copia os valores de cadeia de caracteres para os membros de dados [m_strCommandText](../../data/oledb/crowsetimpl-m-strcommandtext.md) e [m_strIndexText](../../data/oledb/crowsetimpl-m-strindextext.md).

### <a name="syntax"></a>Sintaxe

```cpp
HRESULT CRowsetBaseImpl::GetCommandFromID(DBID* pTableID,
   DBID* pIndexID);
```

#### <a name="parameters"></a>Parâmetros

*pTableID*<br/>
[in] Um ponteiro para o `DBID` que representa a ID da tabela.

*pIndexID*<br/>
[in] Um ponteiro para o `DBID` que representa a ID de índice.

### <a name="return-value"></a>Valor de retorno

Um HRESULT padrão.

### <a name="remarks"></a>Comentários

Esse método é chamado por meio de um upcast estático por `CRowsetImpl` para preencher os membros de dados [m_strCommandText](../../data/oledb/crowsetimpl-m-strcommandtext.md) e [m_strIndexText](../../data/oledb/crowsetimpl-m-strindextext.md). Por padrão, esse método verifica se um ou ambos os parâmetros contêm valores de cadeia de caracteres. Se eles contiverem valores de cadeia de caracteres, esse método copia os valores de cadeia de caracteres para os membros de dados. Colocando um método com essa assinatura em seu `CRowsetImpl`-derivado da classe, o método será chamado em vez da implementação base.

## <a name="validatecommandid"></a> CRowsetImpl::ValidateCommandID

Verifica para ver se qualquer uma ou ambas `DBID`s contêm valores de cadeia de caracteres e, nesse caso, copiá-los em seus membros de dados [m_strCommandText](../../data/oledb/crowsetimpl-m-strcommandtext.md) e [m_strIndexText](../../data/oledb/crowsetimpl-m-strindextext.md).

### <a name="syntax"></a>Sintaxe

```cpp
HRESULT CRowsetBaseImpl::ValidateCommandID(DBID* pTableID,
   DBID* pIndexID);
```

#### <a name="parameters"></a>Parâmetros

*pTableID*<br/>
[in] Um ponteiro para o `DBID` que representa a ID da tabela.

*pIndexID*<br/>
[in] Um ponteiro para o `DBID` representando a ID de índice.

### <a name="return-value"></a>Valor de retorno

Um HRESULT padrão.

### <a name="remarks"></a>Comentários

Esse método é chamado por meio de um upcast estático por `CRowsetImpl` para preencher seus membros de dados [m_strCommandText](../../data/oledb/crowsetimpl-m-strcommandtext.md) e [m_strIndexText](../../data/oledb/crowsetimpl-m-strindextext.md). Por padrão, esse método verifica para ver se qualquer um dos ou ambos `DBID`s contêm valores de cadeia de caracteres e, nesse caso, copiá-los em seus membros de dados. Colocando um método com essa assinatura em seu `CRowsetImpl`-derivado da classe, o método será chamado em vez da implementação base.

## <a name="rgrowdata"></a> CRowsetImpl::m_rgRowData

Por padrão, uma `CAtlArray` que templatizes sobre o argumento de modelo de registro de usuário para `CRowsetImpl`.

### <a name="syntax"></a>Sintaxe

```cpp
ArrayType CRowsetBaseImpl::m_rgRowData;
```

### <a name="remarks"></a>Comentários

*ArrayType* é um parâmetro de modelo para `CRowsetImpl`.

## <a name="strcommandtext"></a> CRowsetImpl::m_strCommandText

Contém o comando de inicial do conjunto de linhas.

### <a name="syntax"></a>Sintaxe

```cpp
CComBSTR CRowsetBaseImpl::m_strCommandText;
```

## <a name="strindextext"></a> CRowsetImpl::m_strIndexText

Contém o índice inicial do conjunto de linhas.

### <a name="syntax"></a>Sintaxe

```cpp
CComBSTR CRowsetBaseImpl::m_strIndexText;
```