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
ms.openlocfilehash: 35a80503597b7e59ec10618b9c8e18e0e69f018e
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87221504"
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

### <a name="parameters"></a>parâmetros

*T*<br/>
A classe do usuário que deriva de `CRowsetImpl` .

*Storage*<br/>
A classe de registro de usuário.

*CreatorClass*<br/>
A classe que contém propriedades para o conjunto de linhas; Normalmente, o comando.

*ArrayType*<br/>
A classe que atuará como armazenamento para os dados do conjunto de linhas. Esse parâmetro assume como padrão `CAtlArray` , mas pode ser qualquer classe que ofereça suporte à funcionalidade necessária.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** Atldb. h

## <a name="members"></a>Membros

### <a name="methods"></a>Métodos

|||
|-|-|
|[NameFromDBID](#namefromdbid)|Extrai uma cadeia de caracteres de um `DBID` e copia-o para o *BSTR* passado.|
|[SetCommandText](#setcommandtext)|Valida e armazena os `DBID` s nas duas cadeias de caracteres ([m_strCommandText](../../data/oledb/crowsetimpl-m-strcommandtext.md) e [m_strIndexText](../../data/oledb/crowsetimpl-m-strindextext.md)).|

### <a name="overridable-methods"></a>Métodos substituíveis

|||
|-|-|
|[GetColumnInfo](#getcolumninfo)|Recupera informações de coluna para uma solicitação de cliente específica.|
|[GetCommandFromID](#getcommandfromid)|Verifica se um ou ambos os parâmetros contêm valores de cadeia de caracteres e, nesse caso, copia os valores de cadeia de caracteres para os membros de dados [m_strCommandText](../../data/oledb/crowsetimpl-m-strcommandtext.md) e [m_strIndexText](../../data/oledb/crowsetimpl-m-strindextext.md).|
|[ValidateCommandID](#validatecommandid)|Verifica se um ou ambos os `DBID` s contêm valores de cadeia de caracteres e, nesse caso, os copia para seus membros de dados [m_strCommandText](../../data/oledb/crowsetimpl-m-strcommandtext.md) e [m_strIndexText](../../data/oledb/crowsetimpl-m-strindextext.md).|

### <a name="data-members"></a>Membros de dados

|||
|-|-|
|[m_rgRowData](#rgrowdata)|Por padrão, um `CAtlArray` templatizes no argumento de modelo de registro de usuário para `CRowsetImpl` . Outra classe de tipo de matriz pode ser usada alterando o `ArrayType` argumento de modelo para `CRowsetImpl` .|
|[m_strCommandText](#strcommandtext)|Contém o comando inicial do conjunto de linhas.|
|[m_strIndexText](#strindextext)|Contém o índice inicial do conjunto de linhas.|

## <a name="remarks"></a>Comentários

`CRowsetImpl`fornece substituições na forma de upcasts estáticos. Os métodos controlam a maneira como um determinado conjunto de linhas validará o texto do comando. Você pode criar sua própria `CRowsetImpl` classe de estilo tornando suas interfaces de implementação múltiplas herdadas. O único método para o qual você deve fornecer a implementação é `Execute` . Dependendo do tipo de conjunto de linhas que você está criando, os métodos criadores esperam assinaturas diferentes para o `Execute` . Por exemplo, se você estiver usando uma `CRowsetImpl` classe derivada para implementar um conjunto de linhas de esquema, o `Execute` método terá a seguinte assinatura:

`HRESULT Execute(LONG* pcRows, ULONG cRestrictions, const VARIANT* rgRestrictions)`

Se você estiver criando uma `CRowsetImpl` classe derivada para implementar um comando ou conjunto de linhas de sessão, o `Execute` método terá a seguinte assinatura:

`HRESULT Execute(LONG* pcRows, DBPARAMS* pParams)`

Para implementar qualquer um dos `CRowsetImpl` métodos derivados `Execute` , você deve preencher os buffers de dados internos ([m_rgRowData](../../data/oledb/crowsetimpl-m-rgrowdata.md)).

## <a name="crowsetimplnamefromdbid"></a><a name="namefromdbid"></a>CRowsetImpl::NameFromDBID

Extrai uma cadeia de caracteres de um `DBID` e copia-o para o *BSTR* passado.

### <a name="syntax"></a>Sintaxe

```cpp
HRESULT CRowsetBaseImpl::NameFromDBID(DBID* pDBID,
   CComBSTR& bstr,
   bool bIndex);
```

#### <a name="parameters"></a>parâmetros

*pDBID*<br/>
no Um ponteiro para o `DBID` do qual extrair uma cadeia de caracteres.

*BSTR*<br/>
no Uma referência de [CComBSTR](../../atl/reference/ccombstr-class.md) para fazer uma cópia da `DBID` cadeia de caracteres.

*bIndex*<br/>
[in] **`true`** Se for um índice `DBID` ; **`false`** se for uma tabela `DBID` .

### <a name="return-value"></a>Valor retornado

Um HRESULT padrão. Dependendo se o `DBID` é uma tabela ou um índice (indicado por *bIndex*), o método retornará DB_E_NOINDEX ou DB_E_NOTABLE.

### <a name="remarks"></a>Comentários

Esse método é chamado pelas `CRowsetImpl` implementações de [ValidateCommandID](../../data/oledb/crowsetimpl-validatecommandid.md) e [GetCommandFromID](../../data/oledb/crowsetimpl-getcommandfromid.md).

## <a name="crowsetimplsetcommandtext"></a><a name="setcommandtext"></a>CRowsetImpl:: SetCommandText

Valida e armazena os `DBID` s nas duas cadeias de caracteres ([m_strCommandText](../../data/oledb/crowsetimpl-m-strcommandtext.md) e [m_strIndexText](../../data/oledb/crowsetimpl-m-strindextext.md)).

### <a name="syntax"></a>Sintaxe

```cpp
HRESULT CRowsetBaseImpl::SetCommandText(DBID* pTableID,
   DBID* pIndexID);
```

#### <a name="parameters"></a>parâmetros

*pTableID*<br/>
no Um ponteiro para o `DBID` que representa a ID da tabela.

*pIndexID*<br/>
no Um ponteiro para o `DBID` que representa a ID do índice.

### <a name="return-value"></a>Valor retornado

Um HRESULT padrão.

### <a name="remarks"></a>Comentários

O `SetCommentText` método é chamado por `CreateRowset` , um método modelos estático de `IOpenRowsetImpl` .

Esse método delega seu trabalho chamando [ValidateCommandID](../../data/oledb/crowsetimpl-validatecommandid.md) e [GetCommandFromID](../../data/oledb/crowsetimpl-getcommandfromid.md) por meio de um ponteiro convertido.

## <a name="crowsetimplgetcolumninfo"></a><a name="getcolumninfo"></a>CRowsetImpl:: GetColumnInfo

Recupera informações de coluna para uma solicitação de cliente específica.

### <a name="syntax"></a>Sintaxe

```cpp
static ATLCOLUMNINFO* CRowsetBaseImpl::GetColumnInfo(T* pv,
   ULONG* pcCols);
```

#### <a name="parameters"></a>parâmetros

*PV*<br/>
no Um ponteiro para a `CRowsetImpl` classe derivada do usuário.

*pcCols*<br/>
no Um ponteiro (saída) para o número de colunas retornado.

### <a name="return-value"></a>Valor retornado

Um ponteiro para uma `ATLCOLUMNINFO` estrutura estática.

### <a name="remarks"></a>Comentários

Esse método é uma substituição avançada.

Esse método é chamado por várias classes de implementação base para recuperar informações de coluna para uma determinada solicitação de cliente. Normalmente, esse método seria chamado por `IColumnsInfoImpl` . Se você substituir esse método, deverá posicionar uma versão do método na `CRowsetImpl` classe derivada. Como o método pode ser colocado em uma classe não modelos, você deve alterar *VP* para a `CRowsetImpl` classe derivada apropriada.

O exemplo a seguir demonstra o `GetColumnInfo` uso. Neste exemplo, `CMyRowset` é uma `CRowsetImpl` classe derivada. Para substituir `GetColumnInfo` todas as instâncias dessa classe, coloque o seguinte método na `CMyRowset` definição de classe:

[!code-cpp[NVC_OLEDB_Provider#1](../../data/oledb/codesnippet/cpp/crowsetimpl-getcolumninfo_1.h)]

## <a name="crowsetimplgetcommandfromid"></a><a name="getcommandfromid"></a>CRowsetImpl::GetCommandFromID

Verifica se um ou ambos os parâmetros contêm valores de cadeia de caracteres e, nesse caso, copia os valores de cadeia de caracteres para os membros de dados [m_strCommandText](../../data/oledb/crowsetimpl-m-strcommandtext.md) e [m_strIndexText](../../data/oledb/crowsetimpl-m-strindextext.md).

### <a name="syntax"></a>Sintaxe

```cpp
HRESULT CRowsetBaseImpl::GetCommandFromID(DBID* pTableID,
   DBID* pIndexID);
```

#### <a name="parameters"></a>parâmetros

*pTableID*<br/>
no Um ponteiro para o `DBID` que representa a ID da tabela.

*pIndexID*<br/>
no Um ponteiro para o `DBID` que representa a ID do índice.

### <a name="return-value"></a>Valor retornado

Um HRESULT padrão.

### <a name="remarks"></a>Comentários

Esse método é chamado por meio de um upcast estático `CRowsetImpl` para preencher os membros de dados [m_strCommandText](../../data/oledb/crowsetimpl-m-strcommandtext.md) e [m_strIndexText](../../data/oledb/crowsetimpl-m-strindextext.md). Por padrão, esse método verifica se um ou ambos os parâmetros contêm valores de cadeia de caracteres. Se eles contiverem valores de cadeia de caracteres, esse método copiará os valores de cadeia de caracteres para os membros de dados. Ao colocar um método com essa assinatura na `CRowsetImpl` classe derivada, seu método será chamado em vez da implementação base.

## <a name="crowsetimplvalidatecommandid"></a><a name="validatecommandid"></a>CRowsetImpl::ValidateCommandID

Verifica se um ou ambos os `DBID` s contêm valores de cadeia de caracteres e, nesse caso, os copia para seus membros de dados [m_strCommandText](../../data/oledb/crowsetimpl-m-strcommandtext.md) e [m_strIndexText](../../data/oledb/crowsetimpl-m-strindextext.md).

### <a name="syntax"></a>Sintaxe

```cpp
HRESULT CRowsetBaseImpl::ValidateCommandID(DBID* pTableID,
   DBID* pIndexID);
```

#### <a name="parameters"></a>parâmetros

*pTableID*<br/>
no Um ponteiro para o `DBID` que representa a ID da tabela.

*pIndexID*<br/>
no Um ponteiro para o `DBID` que representa a ID do índice.

### <a name="return-value"></a>Valor retornado

Um HRESULT padrão.

### <a name="remarks"></a>Comentários

Esse método é chamado por meio de um upcast estático `CRowsetImpl` para preencher seus membros de dados [m_strCommandText](../../data/oledb/crowsetimpl-m-strcommandtext.md) e [m_strIndexText](../../data/oledb/crowsetimpl-m-strindextext.md). Por padrão, esse método verifica se um ou ambos `DBID` contêm valores de cadeia de caracteres e, nesse caso, os copia para seus membros de dados. Ao colocar um método com essa assinatura na `CRowsetImpl` classe derivada, seu método será chamado em vez da implementação base.

## <a name="crowsetimplm_rgrowdata"></a><a name="rgrowdata"></a>CRowsetImpl:: m_rgRowData

Por padrão, um `CAtlArray` templatizes no argumento de modelo de registro de usuário para `CRowsetImpl` .

### <a name="syntax"></a>Sintaxe

```cpp
ArrayType CRowsetBaseImpl::m_rgRowData;
```

### <a name="remarks"></a>Comentários

*ArrayType* é um parâmetro de modelo para `CRowsetImpl` .

## <a name="crowsetimplm_strcommandtext"></a><a name="strcommandtext"></a>CRowsetImpl:: m_strCommandText

Contém o comando inicial do conjunto de linhas.

### <a name="syntax"></a>Sintaxe

```cpp
CComBSTR CRowsetBaseImpl::m_strCommandText;
```

## <a name="crowsetimplm_strindextext"></a><a name="strindextext"></a>CRowsetImpl:: m_strIndexText

Contém o índice inicial do conjunto de linhas.

### <a name="syntax"></a>Sintaxe

```cpp
CComBSTR CRowsetBaseImpl::m_strIndexText;
```
