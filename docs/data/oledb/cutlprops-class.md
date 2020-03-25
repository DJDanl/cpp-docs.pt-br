---
title: Classe CUtlProps
ms.date: 11/04/2016
f1_keywords:
- CUtlProps
- CUtlProps::GetPropValue
- CUtlProps.GetPropValue
- GetPropValue
- CUtlProps::IsValidValue
- CUtlProps.IsValidValue
- IsValidValue
- OnPropertyChanged
- CUtlProps.OnPropertyChanged
- CUtlProps::OnPropertyChanged
- SetPropValue
- ATL::CUtlProps<T>::SetPropValue
- ATL.CUtlProps<T>.SetPropValue
- ATL.CUtlProps.SetPropValue
- CUtlProps::SetPropValue
- CUtlProps<T>::SetPropValue
- CUtlProps.SetPropValue
- CUtlProps<T>.SetPropValue
- ATL::CUtlProps::SetPropValue
helpviewer_keywords:
- CUtlProps class
- GetPropValue method
- IsValidValue method
- OnInterfaceRequested method
- OnPropertyChanged method
- SetPropValue method
ms.assetid: bb525178-765c-4e23-a110-c0fd70c05437
ms.openlocfilehash: 3498ec1250d9443007acb3b12ec25983a71587d0
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80211101"
---
# <a name="cutlprops-class"></a>Classe CUtlProps

Implementa propriedades para uma variedade de OLE DB interfaces de propriedade (por exemplo, `IDBProperties`, `IDBProperties`e `IRowsetInfo`).

## <a name="syntax"></a>Sintaxe

```cpp
template < class T >
class ATL_NO_VTABLE CUtlProps : public CUtlPropsBase
```

### <a name="parameters"></a>parâmetros

*T*<br/>
A classe que contém a `BEGIN_PROPSET_MAP`.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** Atldb. h

## <a name="members"></a>Membros

### <a name="methods"></a>Métodos

|||
|-|-|
|[GetPropValue](#getpropvalue)|Obtém uma propriedade de um conjunto de propriedades.|
|[Isvalidavalue](#isvalidvalue)|Usado para validar um valor antes de definir uma propriedade.|
|[OnInterfaceRequested](#oninterfacerequested)|Lida com solicitações para uma interface opcional quando um consumidor chama um método em uma interface de criação de objeto.|
|[OnPropertyChanged](#onpropertychanged)|Chamado depois de definir uma propriedade para manipular as propriedades encadeadas.|
|[SetPropValue](#setpropvalue)|Define uma propriedade em um conjunto de propriedades.|

## <a name="remarks"></a>Comentários

A maior parte dessa classe é um detalhe de implementação.

`CUtlProps` contém dois membros para definir propriedades internamente: [GetPropValue](../../data/oledb/cutlprops-getpropvalue.md) e [SetPropValue](../../data/oledb/cutlprops-setpropvalue.md).

Para obter mais informações sobre as macros usadas em um mapa de conjunto de propriedades, consulte [BEGIN_PROPSET_MAP](../../data/oledb/begin-propset-map.md) e [END_PROPSET_MAP](../../data/oledb/end-propset-map.md).

## <a name="cutlpropsgetpropvalue"></a><a name="getpropvalue"></a>CUtlProps:: GetPropValue

Obtém uma propriedade de um conjunto de propriedades.

### <a name="syntax"></a>Sintaxe

```cpp
OUT_OF_LINE HRESULT GetPropValue(const GUID* pguidPropSet,
   DBPROPID dwPropId,
   VARIANT* pvValue);
```

#### <a name="parameters"></a>parâmetros

*pguidPropSet*<br/>
no O GUID para o propset.

*dwPropId*<br/>
no O índice de propriedade.

*pvValue*<br/>
fora Um ponteiro para uma variante que contém o novo valor da propriedade.

### <a name="return-value"></a>Valor retornado

`Failure` em caso de falha e S_OK se tiver êxito.

## <a name="cutlpropsisvalidvalue"></a><a name="isvalidvalue"></a>CUtlProps:: isvalidavalue

Usado para validar um valor antes de definir uma propriedade.

### <a name="syntax"></a>Sintaxe

```cpp
virtual HRESULT CUtlPropsBase::IsValidValue(ULONG /* iCurSet */,
   DBPROP* pDBProp);
```

#### <a name="parameters"></a>parâmetros

*iCurSet*<br/>
O índice na matriz de conjunto de propriedades; zero se houver apenas um conjunto de propriedades.

*pDBProp*<br/>
A ID da propriedade e o novo valor em uma estrutura [DBPROP](/previous-versions/windows/desktop/ms717970(v=vs.85)) .

### <a name="return-value"></a>Valor retornado

Um HRESULT padrão. O valor de retorno padrão é S_OK.

### <a name="remarks"></a>Comentários

Se você tiver alguma rotina de validação que deseja executar em um valor que você está prestes a usar para definir uma propriedade, você deve substituir essa função. Por exemplo, você pode validar DBPROP_AUTH_PASSWORD em relação a uma tabela de senha para determinar um valor válido.

## <a name="cutlpropsoninterfacerequested"></a><a name="oninterfacerequested"></a>CUtlProps::OnInterfaceRequested

Lida com solicitações para uma interface opcional quando um consumidor chama um método em uma das interfaces de criação de objeto.

### <a name="syntax"></a>Sintaxe

```cpp
virtual HRESULT CUtlPropsBase::OnInterfaceRequested(REFIID riid);
```

#### <a name="parameters"></a>parâmetros

*riid*<br/>
no O IID para a interface solicitada. Para obter mais detalhes, consulte a descrição do parâmetro *riid* de `ICommand::Execute` na *referência do programador de OLE DB* (no SDK do *MDAC*).

### <a name="remarks"></a>Comentários

o `OnInterfaceRequested` lida com solicitações de consumidor para uma interface opcional quando um consumidor chama um método em uma das interfaces de criação de objeto (como `IDBCreateSession`, `IDBCreateCommand`, `IOpenRowset`ou `ICommand`). Ele define a propriedade de OLE DB correspondente para a interface solicitada. Por exemplo, se o consumidor solicitar `IID_IRowsetLocate`, `OnInterfaceRequested` definirá a interface `DBPROP_IRowsetLocate`. Fazer isso mantém o estado correto durante a criação do conjunto de linhas.

Esse método é chamado quando o consumidor chama `IOpenRowset::OpenRowset` ou `ICommand::Execute`.

Se um consumidor abrir um objeto e solicitar uma interface opcional, o provedor deverá definir a propriedade associada a essa interface como VARIANT_TRUE. Para permitir o processamento específico de propriedade, `OnInterfaceRequested` é chamado antes de o método de `Execute` do provedor ser chamado. Por padrão, o `OnInterfaceRequested` manipula as seguintes interfaces:

- `IRowsetLocate`

- `IRowsetChange`

- `IRowsetUpdate`

- `IConnectionPointContainer`

- `IRowsetScroll`

Se você quiser lidar com outras interfaces, substitua essa função em sua fonte de dados, sessão, comando ou classe de conjunto de linhas para processar funções. Sua substituição deve passar pelas interfaces de propriedades set/get normais para garantir que a configuração de propriedades também defina todas as propriedades encadeadas (consulte [OnPropertyChanged](../../data/oledb/cutlprops-onpropertychanged.md)).

## <a name="cutlpropsonpropertychanged"></a><a name="onpropertychanged"></a>CUtlProps:: OnPropertyChanged

Chamado depois de definir uma propriedade para manipular as propriedades encadeadas.

### <a name="syntax"></a>Sintaxe

```cpp
virtual HRESULT OnPropertyChanged(ULONG /* iCurSet */,
   DBPROP* pDBProp);
```

#### <a name="parameters"></a>parâmetros

*iCurSet*<br/>
O índice na matriz de conjunto de propriedades; zero se houver apenas um conjunto de propriedades.

*pDBProp*<br/>
A ID da propriedade e o novo valor em uma estrutura [DBPROP](/previous-versions/windows/desktop/ms717970(v=vs.85)) .

### <a name="return-value"></a>Valor retornado

Um HRESULT padrão. O valor de retorno padrão é S_OK.

### <a name="remarks"></a>Comentários

Se você quiser manipular propriedades encadeadas, como indicadores ou atualizações cujos valores são dependentes de outro valor de propriedade, você deve substituir essa função.

### <a name="example"></a>Exemplo

Nessa função, o usuário Obtém a ID da Propriedade do parâmetro `DBPROP*`. Agora, é possível comparar a ID com uma propriedade para cadeia. Quando a propriedade é encontrada, `SetProperties` é chamado com a propriedade que agora será definida em conjunto com a outra propriedade. Nesse caso, se uma Obtém a propriedade `DBPROP_IRowsetLocate`, `DBPROP_LITERALBOOKMARKS`ou `DBPROP_ORDEREDBOOKMARKS`, uma pode definir a propriedade `DBPROP_BOOKMARKS`.

[!code-cpp[NVC_OLEDB_Provider#2](../../data/oledb/codesnippet/cpp/cutlprops-onpropertychanged_1.h)]

## <a name="cutlpropssetpropvalue"></a><a name="setpropvalue"></a>CUtlProps:: SetPropValue

Define uma propriedade em um conjunto de propriedades.

### <a name="syntax"></a>Sintaxe

```cpp
HRESULT SetPropValue(const GUID* pguidPropSet,
   DBPROPID dwPropId,
   VARIANT* pvValue);
```

#### <a name="parameters"></a>parâmetros

*pguidPropSet*<br/>
no O GUID para o propset.

*dwPropId*<br/>
no O índice de propriedade.

*pvValue*<br/>
no Um ponteiro para uma variante que contém o novo valor da propriedade.

### <a name="return-value"></a>Valor retornado

`Failure` em caso de falha e S_OK se tiver êxito.

## <a name="see-also"></a>Confira também

[Modelos de Provedor OLE DB](../../data/oledb/ole-db-provider-templates-cpp.md)<br/>
[Arquitetura de modelo do provedor do OLE DB](../../data/oledb/ole-db-provider-template-architecture.md)
