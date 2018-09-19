---
title: Classe IDBSchemaRowsetImpl | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-data
ms.topic: reference
f1_keywords:
- IDBSchemaRowsetImpl
- CheckRestrictions
- IDBSchemaRowsetImpl::CheckRestrictions
- IDBSchemaRowsetImpl.CheckRestrictions
- IDBSchemaRowsetImpl::CreateSchemaRowset
- ATL::IDBSchemaRowsetImpl::CreateSchemaRowset
- CreateSchemaRowset
- IDBSchemaRowsetImpl.CreateSchemaRowset
- ATL.IDBSchemaRowsetImpl.CreateSchemaRowset
- IDBSchemaRowsetImpl::SetRestrictions
- SetRestrictions
- IDBSchemaRowsetImpl.SetRestrictions
- ATL::IDBSchemaRowsetImpl::GetRowset
- ATL.IDBSchemaRowsetImpl.GetRowset
- IDBSchemaRowsetImpl<SessionClass>::GetRowset
- IDBSchemaRowsetImpl.GetRowset
- IDBSchemaRowsetImpl::GetRowset
- ATL::IDBSchemaRowsetImpl<SessionClass>::GetRowset
- GetRowset
- ATL::IDBSchemaRowsetImpl::GetSchemas
- GetSchemas
- IDBSchemaRowsetImpl<SessionClass>::GetSchemas
- ATL.IDBSchemaRowsetImpl.GetSchemas
- ATL::IDBSchemaRowsetImpl<SessionClass>::GetSchemas
- IDBSchemaRowsetImpl.GetSchemas
- IDBSchemaRowsetImpl::GetSchemas
dev_langs:
- C++
helpviewer_keywords:
- IDBSchemaRowsetImpl class
- CheckRestrictions method
- CreateSchemaRowset method
- SetRestrictions method
- GetRowset method
- GetSchemas method
ms.assetid: bd7bf0d7-a1c6-4afa-88e3-cfdbdf560703
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- data-storage
ms.openlocfilehash: 3d998654b92e2e75836bb9dad9e3d7fc17bfa0bd
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46103094"
---
# <a name="idbschemarowsetimpl-class"></a>Classe IDBSchemaRowsetImpl

Fornece implementação para conjuntos de linhas de esquema.  
  
## <a name="syntax"></a>Sintaxe

```cpp
template <class SessionClass>  
class ATL_NO_VTABLE IDBSchemaRowsetImpl : public IDBSchemaRowset  
```  
  
### <a name="parameters"></a>Parâmetros  

*SessionClass*<br/>
A classe pelo qual `IDBSchemaRowsetImpl` é herdada. Normalmente, essa classe será classe da sessão do usuário. 

## <a name="requirements"></a>Requisitos  

**Cabeçalho:** atldb.h  
  
## <a name="members"></a>Membros  
  
### <a name="methods"></a>Métodos  
  
|||  
|-|-|  
|[CheckRestrictions](#checkrestrictions)|Verifica a validade de restrições em relação a um conjunto de linhas de esquema.|  
|[CreateSchemaRowset](#createschemarowset)|Implementa uma função de criador do objeto COM para o objeto especificado pelo parâmetro de modelo.|  
|[SetRestrictions](#setrestrictions)|Especifica quais restrições você oferece suporte em um conjunto de linhas de esquema específico.|  
  
### <a name="interface-methods"></a>Métodos de interface  
  
|||  
|-|-|  
|[GetRowset](#getrowset)|Retorna um conjunto de linhas de esquema.|  
|[GetSchemas](#getschemas)|Retorna uma lista de conjuntos de linhas de esquema acessível pelos [idbschemarowsetimpl:: Getrowset](../../data/oledb/idbschemarowsetimpl-getrowset.md).|  
  
## <a name="remarks"></a>Comentários  

Essa classe implementa a [IDBSchemaRowset](/previous-versions/windows/desktop/ms713686\(v=vs.85\)) interface e a função de criador de modelos [CreateSchemaRowset](../../data/oledb/idbschemarowsetimpl-createschemarowset.md).  
  
OLE DB usa conjuntos de linhas de esquema para retornar dados sobre os dados em um provedor. Esses dados são geralmente chamados de "metadados". Por padrão, um provedor sempre deve suportar `DBSCHEMA_TABLES`, `DBSCHEMA_COLUMNS`, e `DBSCHEMA_PROVIDER_TYPES`, conforme descrito em [IDBSchemaRowset](/previous-versions/windows/desktop/ms713686\(v=vs.85\)) no *referência do programador DB OLE*. Conjuntos de linhas de esquema são designados em um mapa de esquema. Para obter informações sobre as entradas de mapa de esquema, consulte [SCHEMA_ENTRY](../../data/oledb/schema-entry.md).  
  
O OLE DB Provider Wizard, no Assistente de objeto ATL, gera automaticamente o código para os conjuntos de linhas de esquema em seu projeto. (Por padrão, o assistente dá suporte os conjuntos de linhas de esquema obrigatório mencionados anteriormente.) Quando você cria um consumidor usando o Assistente de objeto ATL, o assistente usa conjuntos de linhas de esquema para associar os dados corretos para um provedor. Se você não implementar seus conjuntos de linhas de esquema para fornecer os metadados corretos, o assistente não associará os dados corretos.  
  
Para obter informações sobre como dar suporte a conjuntos de linhas de esquema no seu provedor, consulte [que dão suporte a conjuntos de linhas de esquema](../../data/oledb/supporting-schema-rowsets.md).  
  
Para obter mais informações sobre conjuntos de linhas de esquema, consulte [Schema Rowsets](/previous-versions/windows/desktop/ms712921\(v=vs.85\)) na *referência do programador DB OLE*.  

## <a name="checkrestrictions"></a> Idbschemarowsetimpl:: Checkrestrictions

Verifica a validade de restrições em relação a um conjunto de linhas de esquema.  
  
### <a name="syntax"></a>Sintaxe  
  
```cpp
HRESULT CheckRestrictions(REFGUID rguidSchema,  
   ULONG cRestrictions,  const VARIANT rgRestrictions[]);  
```  
  
#### <a name="parameters"></a>Parâmetros  

*rguidSchema*<br/>
[in] Uma referência para o GUID do conjunto de linhas do esquema solicitado (por exemplo, `DBSCHEMA_TABLES`).  
  
*cRestrictions*<br/>
[in] O número de restrições que o consumidor passado para o conjunto de linhas de esquema.  
  
*rgRestrictions*<br/>
[in] Uma matriz de comprimento *cRestrictions* de valores de restrição a ser definido. Para obter mais informações, consulte a descrição do *rgRestrictions* parâmetro na [SetRestrictions](../../data/oledb/idbschemarowsetimpl-setrestrictions.md).  
  
### <a name="remarks"></a>Comentários  

Use `CheckRestrictions` para verificar a validade de restrições em relação a um conjunto de linhas de esquema. Ele verifica as restrições para `DBSCHEMA_TABLES`, `DBSCHEMA_COLUMNS`, e `DBSCHEMA_PROVIDER_TYPES` conjuntos de linhas de esquema. Chamá-lo para determinar se um consumidor de chamada para `IDBSchemaRowset::GetRowset` está correto. Se você quiser dar suporte a conjuntos de linhas de esquema diferente daqueles listados acima, você deve criar sua própria função para realizar essa tarefa.  
  
`CheckRestrictions` Determina se o consumidor está chamando [GetRowset](../../data/oledb/idbschemarowsetimpl-getrowset.md) com a restrição correta e o tipo de restrição correto (por exemplo, um VT_BSTR para uma cadeia de caracteres) que o provedor oferece suporte. Ele também determina se o número correto de restrições têm suporte. Por padrão, `CheckRestrictions` pedirá que o provedor, por meio de [SetRestrictions](../../data/oledb/idbschemarowsetimpl-setrestrictions.md) chamar, quais restrições dá suporte a em um determinado conjunto de linhas. Ele então compara as restrições do consumidor contra aqueles suportados pelo provedor e tiver êxito ou falhar.  
  
Para obter mais informações sobre conjuntos de linhas de esquema, consulte [IDBSchemaRowset](/previous-versions/windows/desktop/ms713686\(v=vs.85\)) na *referência do programador DB OLE* no SDK do Windows.  

## <a name="createschemarowset"></a> Idbschemarowsetimpl:: Createschemarowset

Implementa uma função de criador do objeto COM para o objeto especificado pelo parâmetro de modelo.  
  
### <a name="syntax"></a>Sintaxe  
  
```cpp
template template <class SchemaRowsetClass>  
HRESULT CreateSchemaRowset(IUnknown *pUnkOuter,  
   ULONG cRestrictions,  
   const VARIANT rgRestrictions[],  
   REFIID riid,  
   ULONG cPropertySets,  
   DBPROPSET rgPropertySets[],  
   IUnknown** ppRowset,  
   SchemaRowsetClass*& pSchemaRowset);  
```  
  
#### <a name="parameters"></a>Parâmetros  

*pUnkOuter*<br/>
[in] Um outer [IUnknown](/windows/desktop/api/unknwn/nn-unknwn-iunknown) ao agregar, caso contrário, NULL.  
  
*cRestrictions*<br/>
[in] A contagem de restrições aplicadas ao conjunto de linhas de esquema.  
  
*rgRestrictions*<br/>
[in] Uma matriz de `cRestrictions` **VARIANT**s a ser aplicado ao conjunto de linhas.  
  
*riid*<br/>
[in] A interface [QueryInterface](../../atl/queryinterface.md) para a saída `IUnknown`.  
  
*cPropertySets*<br/>
[in] Define o número de propriedade para definir.  
  
*rgPropertySets*<br/>
[in] Uma matriz de [DBPROPSET](/previous-versions/windows/desktop/ms714367\(v=vs.85\)) estruturas que especificam as propriedades que está sendo definidas.  
  
*ppRowset*<br/>
[out] A saída `IUnknown` solicitado pelo *riid*. Isso `IUnknown` é uma interface no objeto de conjunto de linhas de esquema.  
  
*pSchemaRowset*<br/>
[out] Um ponteiro para uma instância da classe de conjunto de linhas de esquema. Normalmente, esse parâmetro não for usado, mas ele pode ser usado se for preciso executar mais trabalho no conjunto de linhas de esquema antes de entregá-lo a um objeto COM. O tempo de vida dos *pSchemaRowset* estiver associado ao *ppRowset*.  
  
### <a name="return-value"></a>Valor de retorno  

Um valor padrão de HRESULT.  
  
### <a name="remarks"></a>Comentários  

Essa função implementa um criador de genérico para todos os tipos de conjuntos de linhas de esquema. Normalmente, o usuário não chama essa função. Ele é chamado pela implementação do mapa de esquema. 

## <a name="setrestrictions"></a> Idbschemarowsetimpl:: Setrestrictions

Especifica quais restrições você oferece suporte em um conjunto de linhas de esquema específico.  
  
### <a name="syntax"></a>Sintaxe  
  
```cpp
void SetRestrictions(ULONG cRestrictions,  
   GUID* /* rguidSchema */,  
   ULONG* rgRestrictions);  
```  
  
#### <a name="parameters"></a>Parâmetros  

*cRestrictions*<br/>
[in] O número de restrições na *rgRestrictions* matriz e o número de GUIDs na *rguidSchema* matriz.  
  
*rguidSchema*<br/>
[in] Uma matriz de GUIDs de conjuntos de linhas de esquema para o qual buscar restrições. Cada elemento da matriz contém o GUID do conjunto de linhas de um esquema (por exemplo, `DBSCHEMA_TABLES`).  
  
*rgRestrictions*<br/>
[in] Uma matriz de comprimento *cRestrictions* de valores de restrição a ser definido. Cada elemento corresponde às restrições no conjunto de linhas de esquema identificado pelo GUID. Se um conjunto de linhas de esquema não é suportado pelo provedor, o elemento é definido como zero. Caso contrário, o **ULONG** valor contém uma máscara de bits que representa as restrições com suporte nesse conjunto de linhas de esquema. Para obter mais informações nos quais restrições correspondem a um conjunto de linhas de esquema específico, consulte a tabela de GUIDs do conjunto de linhas de esquema no [IDBSchemaRowset](/previous-versions/windows/desktop/ms713686\(v=vs.85\)) na *referência do programador DB OLE* no Windows SDK.  
  
### <a name="remarks"></a>Comentários  

O `IDBSchemaRowset` chamadas do objeto `SetRestrictions` para determinar quais restrições você oferece suporte em um conjunto de linhas de esquema específico (ele é chamado pelo [GetSchemas](../../data/oledb/idbschemarowsetimpl-getschemas.md) por meio de um ponteiro upcasted). As restrições permitem que os consumidores buscar somente as linhas correspondentes (por exemplo, localizar todas as colunas na tabela "MyTable"). As restrições são opcionais e, no caso em que nenhum têm suporte (o padrão), todos os dados são sempre retornadas.  
  
A implementação padrão desse método define a *rgRestrictions* elementos como 0 da matriz. Substitua o padrão em sua classe de sessão para definir restrições que não seja o padrão.  
  
Para obter informações sobre como implementar o suporte ao conjunto de linhas de esquema, consulte [que dão suporte a conjuntos de linhas de esquema](../../data/oledb/supporting-schema-rowsets.md).  
  
Para obter um exemplo de um provedor que dá suporte a conjuntos de linhas de esquema, consulte o [UpdatePV](https://github.com/Microsoft/VCSamples/tree/master/VC2010Samples/ATL/OLEDB/Provider/UPDATEPV) exemplo.  
  
Para obter mais informações sobre conjuntos de linhas de esquema, consulte [IDBSchemaRowset](/previous-versions/windows/desktop/ms713686\(v=vs.85\)) na *referência do programador DB OLE* no SDK do Windows. 
  
## <a name="getrowset"></a> Idbschemarowsetimpl:: Getrowset

Retorna um conjunto de linhas de esquema.  
  
### <a name="syntax"></a>Sintaxe  
  
```cpp
STDMETHOD (GetRowset)(IUnknown *pUnkOuter,  
   REFGUID rguidSchema,  
   ULONG cRestrictions,  
   const VARIANT rgRestrictions[],  
   REFIID riid,  
   ULONG cPropertySets,  
   DBPROPSET rgPropertySets[],  
   IUnknown **ppRowset);  
```  
  
#### <a name="parameters"></a>Parâmetros  

*pUnkOuter*<br/>
[in] Um outer `IUnknown` durante a agregação; caso contrário, NULL.  
  
*rguidSchema*<br/>
[in] Uma referência para o GUID do conjunto de linhas do esquema solicitado (por exemplo, `DBSCHEMA_TABLES`).  
  
*cRestrictions*<br/>
[in] Uma contagem de restrições a serem aplicadas ao conjunto de linhas.  
  
*rgRestrictions*<br/>
[in] Uma matriz de `cRestrictions` **VARIANT**s que representam as restrições.  
  
*riid*<br/>
[in] O IID para solicitar do conjunto de linhas de esquema recém-criado.  
  
*cPropertySets*<br/>
[in] Define o número de propriedade para definir.  
  
*rgPropertySets*<br/>
[entrada/saída] Uma matriz de [DBPROPSET](/previous-versions/windows/desktop/ms714367\(v=vs.85\)) estruturas para definir no conjunto de linhas de esquema recém-criado.  
  
*ppRowset*<br/>
[out] Um ponteiro para a interface solicitada no conjunto de linhas de esquema recém-criado.  
  
### <a name="remarks"></a>Comentários  

Esse método requer que o usuário tenha um esquema do mapa na classe de sessão. Usando as informações de mapa de esquema, `GetRowset` cria um objeto de determinado conjunto de linhas se o *rguidSchema* parâmetro é igual a uma das entradas de mapa GUIDs. Ver [SCHEMA_ENTRY](../../data/oledb/schema-entry.md) para obter uma descrição da entrada do mapa.  
  
Ver [IDBSchemaRowset:: Getrowset](/previous-versions/windows/desktop/ms722634\(v=vs.85\)) no Windows SDK.  

## <a name="getschemas"></a> Idbschemarowsetimpl:: Getschemas

Retorna uma lista de conjuntos de linhas de esquema acessível pelos [idbschemarowsetimpl:: Getrowset](../../data/oledb/idbschemarowsetimpl-getrowset.md).  
  
### <a name="syntax"></a>Sintaxe  
  
```cpp
STDMETHOD (GetSchema s )(ULONG * pcSchemas,  
   GUID ** prgSchemas,  
   ULONG** prgRest);  
```  
  
#### <a name="parameters"></a>Parâmetros  

*pcSchemas*<br/>
[out] Um ponteiro para um **ULONG** que é preenchido com o número de esquemas.  
  
*prgSchemas*<br/>
[out] Um ponteiro para uma matriz de GUIDs que é preenchido com um ponteiro para uma matriz de GUIDs do conjunto de linhas de esquema.  
  
*prgRest*<br/>
[out] Um ponteiro para uma matriz de **ULONG**s que deve ser preenchido com a matriz de restrição.  
  
### <a name="remarks"></a>Comentários  

Esse método retorna uma matriz de todos os conjuntos de linhas do esquema suportados pelo provedor. Ver [IDBSchemaRowset::GetSchemas](/previous-versions/windows/desktop/ms719605\(v=vs.85\)) no Windows SDK.  
  
A implementação dessa função exige que o usuário tenha um esquema do mapa na classe de sessão. Usando as informações de mapa de esquema, ele responde com a matriz de GUIDs para os esquemas no mapa. Isso representa os esquemas com suporte pelo provedor.  

## <a name="see-also"></a>Consulte também  

[Classes typedef e classes de conjunto de linhas de esquema](../../data/oledb/schema-rowset-classes-and-typedef-classes.md)<br/>
[Dando suporte a conjuntos de linhas do esquema](../../data/oledb/supporting-schema-rowsets.md)<br/>
[SCHEMA_ENTRY](../../data/oledb/schema-entry.md)<br/>
[UpdatePV](https://github.com/Microsoft/VCSamples)