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
ms.openlocfilehash: 9c2e5923fe35287a7586cd4b52bc60e4a5b27b2d
ms.sourcegitcommit: 63784729604aaf526de21f6c6b62813882af930a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/17/2020
ms.locfileid: "79441150"
---
# <a name="crowsetimpl-class"></a>Classe CRowsetImpl

Fornece uma implementação de conjunto de linhas OLE DB padrão sem exigir várias heranças de muitas interfaces de implementação.

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
A classe do usuário que deriva de `CRowsetImpl`.

*Storage*<br/>
A classe de registro de usuário.

*CreatorClass*<br/>
A classe que contém propriedades para o conjunto de linhas; Normalmente, o comando.

*ArrayType*<br/>
A classe que atuará como armazenamento para os dados do conjunto de linhas. O padrão desse parâmetro é `CAtlArray`, mas pode ser qualquer classe que ofereça suporte à funcionalidade necessária.

## <a name="requirements"></a>{1&gt;{2&gt;Requisitos&lt;2}&lt;1}

**Cabeçalho:** Atldb. h

## <a name="members"></a>Membros

### <a name="methods"></a>{1&gt;Métodos&lt;1}

|||
|-|-|
|[NameFromDBID](#namefromdbid)|Extrai uma cadeia de caracteres de uma `DBID` e a copia para o *BSTR* passado.|
|[SetCommandText](#setcommandtext)|Valida e armazena as `DBID`s nas duas cadeias de caracteres ([m_strCommandText](../../data/oledb/crowsetimpl-m-strcommandtext.md) e [m_strIndexText](../../data/oledb/crowsetimpl-m-strindextext.md)).|

### <a name="overridable-methods"></a>Métodos substituíveis

|||
|-|-|
|[GetColumnInfo](#getcolumninfo)|Recupera informações de coluna para uma solicitação de cliente específica.|
|[GetCommandFromID](#getcommandfromid)|Verifica se um ou ambos os parâmetros contêm valores de cadeia de caracteres e, nesse caso, copia os valores de cadeia de caracteres para os membros de dados [m_strCommandText](../../data/oledb/crowsetimpl-m-strcommandtext.md) e [m_strIndexText](../../data/oledb/crowsetimpl-m-strindextext.md).|
|[ValidateCommandID](#validatecommandid)|Verifica se um ou ambos os `DBID`s contêm valores de cadeia de caracteres e, nesse caso, os copia para seus membros de dados [m_strCommandText](../../data/oledb/crowsetimpl-m-strcommandtext.md) e [m_strIndexText](../../data/oledb/crowsetimpl-m-strindextext.md).|

### <a name="data-members"></a>Membros de Dados

|||
|-|-|
|[m_rgRowData](#rgrowdata)|Por padrão, um `CAtlArray` que templatizes no argumento de modelo de registro de usuário para `CRowsetImpl`. Outra classe de tipo de matriz pode ser usada alterando o argumento de modelo `ArrayType` para `CRowsetImpl`.|
|[m_strCommandText](#strcommandtext)|Contém o comando inicial do conjunto de linhas.|
|[m_strIndexText](#strindextext)|Contém o índice inicial do conjunto de linhas.|

## <a name="remarks"></a>Comentários

`CRowsetImpl` fornece substituições na forma de upcasts estáticos. Os métodos controlam a maneira como um determinado conjunto de linhas validará o texto do comando. Você pode criar sua própria classe de estilo `CRowsetImpl`tornando suas interfaces de implementação múltiplas herdadas. O único método para o qual você deve fornecer a implementação é `Execute`. Dependendo do tipo de conjunto de linhas que você está criando, os métodos criadores esperam assinaturas diferentes para `Execute`. Por exemplo, se você estiver usando uma classe derivada de `CRowsetImpl`para implementar um conjunto de linhas de esquema, o método `Execute` terá a seguinte assinatura:

`HRESULT Execute(LONG* pcRows, ULONG cRestrictions, const VARIANT* rgRestrictions)`

Se você estiver criando uma classe derivada de `CRowsetImpl`para implementar o conjunto de linhas de um comando ou de uma sessão, o método `Execute` terá a seguinte assinatura:

`HRESULT Execute(LONG* pcRows, DBPARAMS* pParams)`

Para implementar qualquer um dos métodos de `Execute` derivados de `CRowsetImpl`, você deve preencher os buffers de dados internos ([m_rgRowData](../../data/oledb/crowsetimpl-m-rgrowdata.md)).

## <a name="namefromdbid"></a>CRowsetImpl::NameFromDBID

Extrai uma cadeia de caracteres de uma `DBID` e a copia para o *BSTR* passado.

### <a name="syntax"></a>Sintaxe

```cpp
HRESULT CRowsetBaseImpl::NameFromDBID(DBID* pDBID,
   CComBSTR& bstr,
   bool bIndex);
```

#### <a name="parameters"></a>Parâmetros

*pDBID*<br/>
no Um ponteiro para a `DBID` da qual extrair uma cadeia de caracteres.

*BSTR*<br/>
no Uma referência de [CComBSTR](../../atl/reference/ccombstr-class.md) para fazer uma cópia da cadeia de caracteres de `DBID`.

*bIndex*<br/>
no **true** se um índice `DBID`; **false** se uma tabela `DBID`.

### <a name="return-value"></a>Valor retornado

Um HRESULT padrão. Dependendo se a `DBID` é uma tabela ou um índice (indicado por *bIndex*), o método retornará DB_E_NOINDEX ou DB_E_NOTABLE.

### <a name="remarks"></a>Comentários

Esse método é chamado pelo `CRowsetImpl` implementações de [ValidateCommandID](../../data/oledb/crowsetimpl-validatecommandid.md) e [GetCommandFromID](../../data/oledb/crowsetimpl-getcommandfromid.md).

## <a name="setcommandtext"></a>CRowsetImpl:: SetCommandText

Valida e armazena as `DBID`s nas duas cadeias de caracteres ([m_strCommandText](../../data/oledb/crowsetimpl-m-strcommandtext.md) e [m_strIndexText](../../data/oledb/crowsetimpl-m-strindextext.md)).

### <a name="syntax"></a>Sintaxe

```cpp
HRESULT CRowsetBaseImpl::SetCommandText(DBID* pTableID,
   DBID* pIndexID);
```

#### <a name="parameters"></a>Parâmetros

*pTableID*<br/>
no Um ponteiro para a `DBID` que representa a ID da tabela.

*pIndexID*<br/>
no Um ponteiro para a `DBID` que representa a ID do índice.

### <a name="return-value"></a>Valor retornado

Um HRESULT padrão.

### <a name="remarks"></a>Comentários

O método `SetCommentText` é chamado por `CreateRowset`, um método modelos estático de `IOpenRowsetImpl`.

Esse método delega seu trabalho chamando [ValidateCommandID](../../data/oledb/crowsetimpl-validatecommandid.md) e [GetCommandFromID](../../data/oledb/crowsetimpl-getcommandfromid.md) por meio de um ponteiro convertido.

## <a name="getcolumninfo"></a>CRowsetImpl:: GetColumnInfo

Recupera informações de coluna para uma solicitação de cliente específica.

### <a name="syntax"></a>Sintaxe

```cpp
static ATLCOLUMNINFO* CRowsetBaseImpl::GetColumnInfo(T* pv,
   ULONG* pcCols);
```

#### <a name="parameters"></a>Parâmetros

*PV*<br/>
no Um ponteiro para a classe derivada do `CRowsetImpl` do usuário.

*pcCols*<br/>
no Um ponteiro (saída) para o número de colunas retornado.

### <a name="return-value"></a>Valor retornado

Um ponteiro para uma estrutura de `ATLCOLUMNINFO` estática.

### <a name="remarks"></a>Comentários

Esse método é uma substituição avançada.

Esse método é chamado por várias classes de implementação base para recuperar informações de coluna para uma determinada solicitação de cliente. Normalmente, esse método seria chamado por `IColumnsInfoImpl`. Se você substituir esse método, deverá posicionar uma versão do método em sua classe derivada de `CRowsetImpl`. Como o método pode ser colocado em uma classe não modelos, você deve alterar *VP* para a classe derivada de `CRowsetImpl`apropriada.

O exemplo a seguir demonstra `GetColumnInfo` uso. Neste exemplo, `CMyRowset` é uma classe derivada de `CRowsetImpl`. Para substituir `GetColumnInfo` para todas as instâncias dessa classe, coloque o seguinte método na definição da classe `CMyRowset`:

[!code-cpp[NVC_OLEDB_Provider#1](../../data/oledb/codesnippet/cpp/crowsetimpl-getcolumninfo_1.h)]

## <a name="getcommandfromid"></a>CRowsetImpl::GetCommandFromID

Verifica se um ou ambos os parâmetros contêm valores de cadeia de caracteres e, nesse caso, copia os valores de cadeia de caracteres para os membros de dados [m_strCommandText](../../data/oledb/crowsetimpl-m-strcommandtext.md) e [m_strIndexText](../../data/oledb/crowsetimpl-m-strindextext.md).

### <a name="syntax"></a>Sintaxe

```cpp
HRESULT CRowsetBaseImpl::GetCommandFromID(DBID* pTableID,
   DBID* pIndexID);
```

#### <a name="parameters"></a>Parâmetros

*pTableID*<br/>
no Um ponteiro para a `DBID` que representa a ID da tabela.

*pIndexID*<br/>
no Um ponteiro para a `DBID` que representa a ID do índice.

### <a name="return-value"></a>Valor retornado

Um HRESULT padrão.

### <a name="remarks"></a>Comentários

Esse método é chamado por meio de um upcast estático por `CRowsetImpl` para popular os membros de dados [m_strCommandText](../../data/oledb/crowsetimpl-m-strcommandtext.md) e [m_strIndexText](../../data/oledb/crowsetimpl-m-strindextext.md). Por padrão, esse método verifica se um ou ambos os parâmetros contêm valores de cadeia de caracteres. Se eles contiverem valores de cadeia de caracteres, esse método copiará os valores de cadeia de caracteres para os membros de dados. Colocando um método com essa assinatura em sua classe derivada de `CRowsetImpl`, seu método será chamado em vez da implementação base.

## <a name="validatecommandid"></a>CRowsetImpl::ValidateCommandID

Verifica se um ou ambos os `DBID`s contêm valores de cadeia de caracteres e, nesse caso, os copia para seus membros de dados [m_strCommandText](../../data/oledb/crowsetimpl-m-strcommandtext.md) e [m_strIndexText](../../data/oledb/crowsetimpl-m-strindextext.md).

### <a name="syntax"></a>Sintaxe

```cpp
HRESULT CRowsetBaseImpl::ValidateCommandID(DBID* pTableID,
   DBID* pIndexID);
```

#### <a name="parameters"></a>Parâmetros

*pTableID*<br/>
no Um ponteiro para a `DBID` que representa a ID da tabela.

*pIndexID*<br/>
no Um ponteiro para a `DBID` que representa a ID do índice.

### <a name="return-value"></a>Valor retornado

Um HRESULT padrão.

### <a name="remarks"></a>Comentários

Esse método é chamado por meio de um upcast estático por `CRowsetImpl` para preencher seus membros de dados [m_strCommandText](../../data/oledb/crowsetimpl-m-strcommandtext.md) e [m_strIndexText](../../data/oledb/crowsetimpl-m-strindextext.md). Por padrão, esse método verifica se um ou ambos os `DBID`s contêm valores de cadeia de caracteres e, nesse caso, os copia para seus membros de dados. Colocando um método com essa assinatura em sua classe derivada de `CRowsetImpl`, seu método será chamado em vez da implementação base.

## <a name="rgrowdata"></a>CRowsetImpl:: m_rgRowData

Por padrão, um `CAtlArray` que templatizes no argumento de modelo de registro de usuário para `CRowsetImpl`.

### <a name="syntax"></a>Sintaxe

```cpp
ArrayType CRowsetBaseImpl::m_rgRowData;
```

### <a name="remarks"></a>Comentários

*ArrayType* é um parâmetro de modelo a `CRowsetImpl`.

## <a name="strcommandtext"></a>CRowsetImpl:: m_strCommandText

Contém o comando inicial do conjunto de linhas.

### <a name="syntax"></a>Sintaxe

```cpp
CComBSTR CRowsetBaseImpl::m_strCommandText;
```

## <a name="strindextext"></a>CRowsetImpl:: m_strIndexText

Contém o índice inicial do conjunto de linhas.

### <a name="syntax"></a>Sintaxe

```cpp
CComBSTR CRowsetBaseImpl::m_strIndexText;
```