---
title: Classe CDBPropSet | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-data
ms.topic: reference
f1_keywords:
- CDBPropSet
- ATL.CDBPropSet
- ATL::CDBPropSet
- CDBPropSet::AddProperty
- CDBPropSet.AddProperty
- AddProperty
- ATL::CDBPropSet::AddProperty
- ATL.CDBPropSet.AddProperty
- CDBPropSet.CDBPropSet
- CDBPropSet::CDBPropSet
- ATL::CDBPropSet::CDBPropSet
- ATL.CDBPropSet.CDBPropSet
- CDBPropSet.operator=
- ATL::CDBPropSet::operator=
- ATL.CDBPropSet.operator=
- CDBPropSet::operator=
- ATL.CDBPropSet.SetGUID
- CDBPropSet.SetGUID
- ATL::CDBPropSet::SetGUID
- SetGUID
- CDBPropSet::SetGUID
dev_langs:
- C++
helpviewer_keywords:
- CDBPropSet class
- AddProperty method
- CDBPropSet class, constructor
- operator =, property sets
- = operator, with OLE DB templates
- operator=, property sets
- SetGUID method
- AddProperty method
ms.assetid: 54190149-c277-4679-b81a-ef484d4d1c00
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- data-storage
ms.openlocfilehash: c6d62b8d4b033d1b90c753d5de1752f0cb737f0d
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46114651"
---
# <a name="cdbpropset-class"></a>Classe CDBPropSet

Herda de `DBPROPSET` estruturar e adiciona um construtor que inicializa os campos de chave, bem como a `AddProperty` método de acesso.  
  
## <a name="syntax"></a>Sintaxe

```cpp
class CDBPropSet : public tagDBPROPSET  
```  

## <a name="requirements"></a>Requisitos  

**Cabeçalho:** atldbcli.h  

## <a name="members"></a>Membros  
  
### <a name="methods"></a>Métodos  
  
|||  
|-|-|  
|[AddProperty](#addproperty)|Adiciona uma propriedade ao conjunto de propriedades.|  
|[CDBPropSet](#cdbpropset)|Construtor.|  
|[SetGUID](#setguid)|Define o `guidPropertySet` campo do `DBPROPSET` estrutura.|  
  
### <a name="operators"></a>Operadores  
  
|||  
|-|-|  
|[operador =](#op_equal)|Atribui o conteúdo de uma propriedade definida para outro.|  
  
## <a name="remarks"></a>Comentários  

Uso de consumidores e provedores OLE DB `DBPROPSET` passar matrizes de estruturas de `DBPROP` estruturas. Cada `DBPROP` estrutura representa uma única propriedade que pode ser definida.  

## <a name="addproperty"></a> Cdbpropset:: AddProperty

Adiciona uma propriedade ao conjunto de propriedades.  
  
### <a name="syntax"></a>Sintaxe  
  
```cpp
bool AddProperty(DWORD dwPropertyID,   
   constVARIANT& var,   
   DBPROPOPTIONS propoptions = DBPROPOPTIONS_REQUIRED) throw();bool AddProperty(DWORD dwPropertyID,  
   LPCSTR szValue,  DBPROPOPTIONS propoptions = DBPROPOPTIONS_REQUIRED) throw();bool AddProperty(DWORD dwPropertyID,  
   LPCWSTR szValue,DBPROPOPTIONS propoptions = DBPROPOPTIONS_REQUIRED) throw();bool AddProperty(DWORD dwPropertyID,  
   bool bValue,  DBPROPOPTIONS propoptions = DBPROPOPTIONS_REQUIRED) throw();bool AddProperty(DWORD dwPropertyID,  
   BYTE bValue,  DBPROPOPTIONS propoptions = DBPROPOPTIONS_REQUIRED);bool AddProperty(DWORD dwPropertyID,  
   short nValue,  DBPROPOPTIONS propoptions = DBPROPOPTIONS_REQUIRED);bool AddProperty(DWORD dwPropertyID,  
   long nValue,  DBPROPOPTIONS propoptions = DBPROPOPTIONS_REQUIRED);bool AddProperty(DWORD dwPropertyID,  
   float fltValue,  DBPROPOPTIONS propoptions = DBPROPOPTIONS_REQUIRED);bool AddProperty(DWORD dwPropertyID,  
   double dblValue,  DBPROPOPTIONS propoptions = DBPROPOPTIONS_REQUIRED) throw();bool AddProperty(DWORD dwPropertyID,  
   CY cyValue,  DBPROPOPTIONS propoptions = DBPROPOPTIONS_REQUIRED) throw();  
```  
  
#### <a name="parameters"></a>Parâmetros  

*dwPropertyID*<br/>
[in] A ID da propriedade a ser adicionado. Usado para inicializar o `dwPropertyID` do `DBPROP` adicionada ao conjunto de propriedades de estrutura.  
  
*var*<br/>
[in] Uma variante usada para inicializar o valor da propriedade para o `DBPROP` adicionada ao conjunto de propriedades de estrutura.  
  
*szValue*<br/>
[in] Uma cadeia de caracteres usada para inicializar o valor da propriedade para o `DBPROP` adicionada ao conjunto de propriedades de estrutura.  
  
*bValue*<br/>
[in] Um `BYTE` ou um valor booliano usado para inicializar o valor da propriedade para o `DBPROP` adicionada ao conjunto de propriedades de estrutura.  
  
*Nvalor*<br/>
[in] Um valor inteiro usado para inicializar o valor da propriedade para o `DBPROP` adicionada ao conjunto de propriedades de estrutura.  
  
*fltValue*<br/>
[in] Um valor de ponto flutuante usado para inicializar o valor da propriedade para o `DBPROP` adicionada ao conjunto de propriedades de estrutura.  
  
*dblValue*<br/>
[in] Um valor de ponto flutuante de precisão dupla usado para inicializar o valor da propriedade para o `DBPROP` adicionada ao conjunto de propriedades de estrutura.  
  
*cyValue*<br/>
[in] Um valor de moeda CY usado para inicializar o valor da propriedade para o `DBPROP` adicionada ao conjunto de propriedades de estrutura.  
  
### <a name="return-value"></a>Valor de retorno  

**True** se a propriedade foi adicionada com êxito. Caso contrário, **falsos**. 

## <a name="cdbpropset"></a> Cdbpropset:: Cdbpropset

O construtor. Inicializa o `rgProperties`, `cProperties`, e `guidPropertySet` campos dos [DBPROPSET](/previous-versions/windows/desktop/ms714367\(v=vs.85\)) estrutura.  
  
### <a name="syntax"></a>Sintaxe  
  
```cpp
CDBPropSet(const GUID& guid);  

CDBPropSet(const CDBPropSet& propset);  

CDBPropSet();  
```  
  
#### <a name="parameters"></a>Parâmetros  

*guid*<br/>
[in] Um GUID usado para inicializar o `guidPropertySet` campo.  
  
*propset*<br/>
[in] Outro `CDBPropSet` objeto para a construção da cópia.  

## <a name="setguid"></a> Cdbpropset:: Setguid

Define o `guidPropertySet` campo o `DBPROPSET` estrutura.  
  
### <a name="syntax"></a>Sintaxe  
  
```cpp
void SetGUID(const GUID& guid) throw();  
```  
  
#### <a name="parameters"></a>Parâmetros  

*guid*<br/>
[in] Um GUID usado para definir a `guidPropertySet` campo do [DBPROPSET](/previous-versions/windows/desktop/ms714367\(v=vs.85\)) estrutura.  
  
### <a name="remarks"></a>Comentários  

Este campo pode ser definido [construtor](../../data/oledb/cdbpropset-cdbpropset.md) também.  

## <a name="op_equal"></a> Cdbpropset:: Operator =

Atribui o conteúdo de uma propriedade definida como outro conjunto de propriedades.  
  
### <a name="syntax"></a>Sintaxe  
  
```cpp
CDBPropSet& operator =(CDBPropSet& propset) throw();  
```  
  
## <a name="see-also"></a>Consulte também  

[Modelos de consumidor do OLE DB](../../data/oledb/ole-db-consumer-templates-cpp.md)<br/>
[Referência de modelos de consumidor do OLE DB](../../data/oledb/ole-db-consumer-templates-reference.md)<br/>
[Classe CDBPropIDSet](../../data/oledb/cdbpropidset-class.md)<br/>
[Estrutura DBPROPSET](/previous-versions/windows/desktop/ms714367\(v=vs.85\))   
[Estrutura DBPROP](/previous-versions/windows/desktop/ms717970\(v=vs.85\))