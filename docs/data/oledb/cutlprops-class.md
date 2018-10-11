---
title: Classe CUtlProps | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-data
ms.topic: reference
f1_keywords:
- CUtlProps
- CUtlProps::GetPropValue
- CUtlProps.GetPropValue
- GetPropValue
- CUtlProps::IsValidValue
- CUtlProps.IsValidValue
- IsValidValue
- CUtlProps
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
dev_langs:
- C++
helpviewer_keywords:
- CUtlProps class
- GetPropValue method
- IsValidValue method
- OnInterfaceRequested method
- OnPropertyChanged method
- SetPropValue method
ms.assetid: bb525178-765c-4e23-a110-c0fd70c05437
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- data-storage
ms.openlocfilehash: 87ef1c3f3867b7cd5890a29db3a8c45300ebdd58
ms.sourcegitcommit: 3a141cf07b5411d5f1fdf6cf67c4ce928cf389c3
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/11/2018
ms.locfileid: "49083392"
---
# <a name="cutlprops-class"></a>Classe CUtlProps

Implementa as propriedades para uma variedade de interfaces de propriedade do OLE DB (por exemplo, `IDBProperties`, `IDBProperties`, e `IRowsetInfo`).  
  
## <a name="syntax"></a>Sintaxe

```cpp
template < class T >  
class ATL_NO_VTABLE CUtlProps : public CUtlPropsBase  
```  
  
### <a name="parameters"></a>Parâmetros  

*T*<br/>
A classe que contém o `BEGIN_PROPSET_MAP`.  

## <a name="requirements"></a>Requisitos  

**Cabeçalho:** atldb.h  

## <a name="members"></a>Membros  
  
### <a name="methods"></a>Métodos  
  
|||  
|-|-|  
|[GetPropValue](#getpropvalue)|Obtém uma propriedade de um conjunto de propriedades.|  
|[IsValidValue](#isvalidvalue)|Usado para validar um valor antes de definir uma propriedade.|  
|[OnInterfaceRequested](#oninterfacerequested)|Trata solicitações para uma interface opcional quando um consumidor chama um método em uma interface de criação de objeto.|  
|[OnPropertyChanged](#onpropertychanged)|Chamado depois de definir uma propriedade para lidar com propriedades encadeadas.|  
|[SetPropValue](#setpropvalue)|Define uma propriedade em um conjunto de propriedades.|  
  
## <a name="remarks"></a>Comentários  

A maioria dessa classe é um detalhe de implementação.  
  
`CUtlProps` contém dois membros para definir as propriedades internamente: [GetPropValue](../../data/oledb/cutlprops-getpropvalue.md) e [SetPropValue](../../data/oledb/cutlprops-setpropvalue.md).  
  
Para obter mais informações sobre as macros usadas em um mapa de conjunto de propriedade, consulte [BEGIN_PROPSET_MAP](../../data/oledb/begin-propset-map.md) e [END_PROPSET_MAP](../../data/oledb/end-propset-map.md).  
  
## <a name="getpropvalue"></a> Cutlprops:: Getpropvalue

Obtém uma propriedade de um conjunto de propriedades.  
  
### <a name="syntax"></a>Sintaxe  
  
```cpp
OUT_OF_LINE HRESULT GetPropValue(const GUID* pguidPropSet,  
   DBPROPID dwPropId,  
   VARIANT* pvValue);  
```  
  
#### <a name="parameters"></a>Parâmetros  

*pguidPropSet*<br/>
[in] O GUID para o conjunto de propriedades.  
  
*dwPropId*<br/>
[in] O índice da propriedade.  
  
*pvValue*<br/>
[out] Um ponteiro para uma variante que contém o novo valor da propriedade.  
  
### <a name="return-value"></a>Valor de retorno  

`Failure` em falha e S_OK se for bem-sucedido.

## <a name="isvalidvalue"></a> Cutlprops:: Isvalidvalue

Usado para validar um valor antes de definir uma propriedade.  
  
### <a name="syntax"></a>Sintaxe  
  
```cpp
virtual HRESULT CUtlPropsBase::IsValidValue(ULONG /* iCurSet */,  
   DBPROP* pDBProp);  
```  
  
#### <a name="parameters"></a>Parâmetros  

*iCurSet*<br/>
O índice na matriz de conjunto de propriedades; zero se houver apenas uma propriedade de conjunto.  
  
*pDBProp*<br/>
A ID de propriedade e o novo valor em uma [DBPROP](/previous-versions/windows/desktop/ms717970) estrutura.  
  
### <a name="return-value"></a>Valor de retorno  

Um HRESULT padrão. O valor de retorno padrão é S_OK.  
  
### <a name="remarks"></a>Comentários  

Se você tiver quaisquer rotinas de validação que você deseja executar em um valor que você está prestes a usar para definir uma propriedade, você deve substituir essa função. Por exemplo, você pode validar DBPROP_AUTH_PASSWORD em uma tabela de senha para determinar um valor válido. 

## <a name="oninterfacerequested"></a> Cutlprops:: Oninterfacerequested

Trata solicitações para uma interface opcional quando um consumidor chama um método em um objeto interfaces de criação.  
  
### <a name="syntax"></a>Sintaxe  
  
```cpp
virtual HRESULT CUtlPropsBase::OnInterfaceRequested(REFIID riid);  
```  
  
#### <a name="parameters"></a>Parâmetros  

*riid*<br/>
[in] O IID da interface solicitada. Para obter mais detalhes, consulte a descrição da *riid* parâmetro do `ICommand::Execute` no *referência do programador DB OLE* (no *SDK do MDAC*).  
  
### <a name="remarks"></a>Comentários  

`OnInterfaceRequested` trata solicitações de consumidor para uma interface opcional quando um consumidor chama um método em um objeto interfaces de criação (como `IDBCreateSession`, `IDBCreateCommand`, `IOpenRowset`, ou `ICommand`). Ele define a propriedade OLE DB correspondente para a interface solicitada. Por exemplo, se o consumidor solicita `IID_IRowsetLocate`, `OnInterfaceRequested` define o `DBPROP_IRowsetLocate` interface. Isso mantém o estado correto durante a criação do conjunto de linhas.  
  
Esse método é chamado quando o consumidor chama `IOpenRowset::OpenRowset` ou `ICommand::Execute`.  
  
Se um consumidor abre um objeto e solicita uma interface opcional, o provedor deve definir a propriedade associada a essa interface como VARIANT_TRUE. Para permitir o processamento de específico da propriedade `OnInterfaceRequested` é chamado antes do provedor `Execute` método é chamado. Por padrão, `OnInterfaceRequested` lida com as seguintes interfaces:  
  
- `IRowsetLocate`  
  
- `IRowsetChange`  
  
- `IRowsetUpdate`  
  
- `IConnectionPointContainer`  
  
- `IRowsetScroll`  
  
Se você quiser lidar com outras interfaces, substituem essa função em sua classe de origem, sessão, comando ou conjunto de linhas de dados para funções do processo. Sua substituição deve percorrer as interfaces de propriedades de definir/obter normal para garantir que também definindo propriedades define quaisquer propriedades encadeadas (consulte [OnPropertyChanged](../../data/oledb/cutlprops-onpropertychanged.md)).  

## <a name="onpropertychanged"></a> Cutlprops:: OnPropertyChanged

Chamado depois de definir uma propriedade para lidar com propriedades encadeadas.  
  
### <a name="syntax"></a>Sintaxe  
  
```cpp
virtual HRESULT OnPropertyChanged(ULONG /* iCurSet */,  
   DBPROP* pDBProp);  
```  
  
#### <a name="parameters"></a>Parâmetros  

*iCurSet*<br/>
O índice na matriz de conjunto de propriedades; zero se houver apenas uma propriedade de conjunto.  
  
*pDBProp*<br/>
A ID de propriedade e o novo valor em uma [DBPROP](/previous-versions/windows/desktop/ms717970) estrutura.  
  
### <a name="return-value"></a>Valor de retorno  

Um HRESULT padrão. O valor de retorno padrão é S_OK.  
  
### <a name="remarks"></a>Comentários  

Se você deseja manipular propriedades encadeadas, como indicadores ou atualizações cujos valores são dependentes de outro valor de propriedade, você deve substituir essa função.  
  
### <a name="example"></a>Exemplo  

Nessa função, o usuário obtém a ID de propriedade do `DBPROP*` parâmetro. Agora, é possível comparar a ID em relação a uma propriedade de cadeia. Quando a propriedade for encontrada, `SetProperties` é chamado com a propriedade que agora será definida em conjunto com a outra propriedade. Nesse caso, se um obtém os `DBPROP_IRowsetLocate`, `DBPROP_LITERALBOOKMARKS`, ou `DBPROP_ORDEREDBOOKMARKS` propriedade, é possível definir o `DBPROP_BOOKMARKS` propriedade.  
  
[!code-cpp[NVC_OLEDB_Provider#2](../../data/oledb/codesnippet/cpp/cutlprops-onpropertychanged_1.h)]  
  
## <a name="setpropvalue"></a> Cutlprops:: Setpropvalue

Define uma propriedade em um conjunto de propriedades.  
  
### <a name="syntax"></a>Sintaxe  
  
```cpp
HRESULT SetPropValue(const GUID* pguidPropSet,  
   DBPROPID dwPropId,  
   VARIANT* pvValue);  
```  
  
#### <a name="parameters"></a>Parâmetros  

*pguidPropSet*<br/>
[in] O GUID para o conjunto de propriedades.  
  
*dwPropId*<br/>
[in] O índice da propriedade.  
  
*pvValue*<br/>
[in] Um ponteiro para uma variante que contém o novo valor da propriedade.  
  
### <a name="return-value"></a>Valor de retorno  

`Failure` em falha e S_OK se for bem-sucedido. 

## <a name="see-also"></a>Consulte também  

[Modelos de provedor do OLE DB](../../data/oledb/ole-db-provider-templates-cpp.md)<br/>
[Arquitetura de modelo do provedor do OLE DB](../../data/oledb/ole-db-provider-template-architecture.md)