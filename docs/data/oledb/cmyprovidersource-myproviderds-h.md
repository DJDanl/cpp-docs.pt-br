---
title: CCustomSource (CustomDS.H) | Microsoft Docs
ms.custom: ''
ms.date: 10/22/2018
ms.technology:
- cpp-data
ms.topic: reference
f1_keywords:
- myproviderds.h
- cmyprovidersource
- customds.h
- ccustomsource
dev_langs:
- C++
helpviewer_keywords:
- OLE DB providers, wizard-generated files
- CMyProviderSource class in MyProviderDS.H
- CCustomSource class in CustomDS.H
ms.assetid: c143d48e-59c8-4f67-9141-3aab51859b92
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- data-storage
ms.openlocfilehash: bcabecde8f299e878ec6498dada503a894c406b4
ms.sourcegitcommit: a9dcbcc85b4c28eed280d8e451c494a00d8c4c25
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/25/2018
ms.locfileid: "50081125"
---
# <a name="ccustomsource-customdsh"></a>CCustomSource (CustomDS.h)

As classes de provedor usam herança múltipla. O código a seguir mostra a cadeia de herança para o objeto de fonte de dados:

```cpp
/////////////////////////////////////////////////////////////////////////
// CCustomSource
class ATL_NO_VTABLE CCustomSource :
   public CComObjectRootEx<CComSingleThreadModel>,
   public CComCoClass<CCustomSource, &CLSID_Custom>,
   public IDBCreateSessionImpl<CCustomSource, CCustomSession>,
   public IDBInitializeImpl<CCustomSource>,
   public IDBPropertiesImpl<CCustomSource>,
   public IPersistImpl<CCustomSource>,
   public IInternalConnectionImpl<CCustomSource>
```

Todos os componentes COM derivam `CComObjectRootEx` e `CComCoClass`. `CComObjectRootEx` fornece todas as a implementação para o `IUnknown` interface. Ele pode lidar com qualquer modelo de threading. `CComCoClass` lida com suporte para qualquer erro necessário. Se você quiser enviar informações de erro mais detalhadas para o cliente, você pode usar algumas das APIs de erro em `CComCoClass`.

O objeto de fonte de dados também herda de várias classes de 'Impl'. Cada classe fornece a implementação de uma interface. A fonte de dados objeto implementa a `IPersist`, `IDBProperties`, `IDBInitialize`, e `IDBCreateSession` interfaces. Cada interface é necessária pelo OLE DB para implementar o objeto de fonte de dados. Você pode escolher dar suporte ou não suporte à funcionalidade específica por herdar ou não herdar de uma dessas classes de 'Impl'. Se você quiser dar suporte a `IDBDataSourceAdmin` interface, você herda do `IDBDataSourceAdminImpl` classe para obter a funcionalidade necessária.

## <a name="com-map"></a>Mapa COM

Sempre que o cliente chama `QueryInterface` para uma interface na fonte de dados, ele percorre o mapa COM a seguir:

```cpp
BEGIN_COM_MAP(CCustomSource)
   COM_INTERFACE_ENTRY(IDBCreateSession)
   COM_INTERFACE_ENTRY(IDBInitialize)
   COM_INTERFACE_ENTRY(IDBProperties)
   COM_INTERFACE_ENTRY(IPersist)
   COM_INTERFACE_ENTRY(IInternalConnection)
END_COM_MAP()
```

As macros COM_INTERFACE_ENTRY são da ATL e informar a implementação de `QueryInterface` em `CComObjectRootEx` para retornar as interfaces apropriadas.

## <a name="property-map"></a>Mapa de propriedade

O mapa de propriedade especifica todas as propriedades designadas pelo provedor:

```cpp
BEGIN_PROPSET_MAP(CCustomSource)
   BEGIN_PROPERTY_SET(DBPROPSET_DATASOURCEINFO)
      PROPERTY_INFO_ENTRY(ACTIVESESSIONS)
      PROPERTY_INFO_ENTRY(ASYNCTXNABORT)
      PROPERTY_INFO_ENTRY(ASYNCTXNCOMMIT)
      PROPERTY_INFO_ENTRY(BYREFACCESSORS)
      PROPERTY_INFO_ENTRY_VALUE(CATALOGLOCATION, DBPROPVAL_CL_START)
      PROPERTY_INFO_ENTRY(CATALOGTERM)
      PROPERTY_INFO_ENTRY(CATALOGUSAGE)
      PROPERTY_INFO_ENTRY(COLUMNDEFINITION)
      PROPERTY_INFO_ENTRY(CONCATNULLBEHAVIOR)
      PROPERTY_INFO_ENTRY(DATASOURCENAME)
      PROPERTY_INFO_ENTRY(DATASOURCEREADONLY)
      PROPERTY_INFO_ENTRY(DBMSNAME)
      PROPERTY_INFO_ENTRY(DBMSVER)
      PROPERTY_INFO_ENTRY_VALUE(DSOTHREADMODEL, DBPROPVAL_RT_FREETHREAD)
      PROPERTY_INFO_ENTRY(GROUPBY)
      PROPERTY_INFO_ENTRY(HETEROGENEOUSTABLES)
      PROPERTY_INFO_ENTRY(IDENTIFIERCASE)
      PROPERTY_INFO_ENTRY(MAXINDEXSIZE)
      PROPERTY_INFO_ENTRY(MAXROWSIZE)
      PROPERTY_INFO_ENTRY(MAXROWSIZEINCLUDESBLOB)
      PROPERTY_INFO_ENTRY(MAXTABLESINSELECT)
      PROPERTY_INFO_ENTRY(MULTIPLEPARAMSETS)
      PROPERTY_INFO_ENTRY(MULTIPLERESULTS)
      PROPERTY_INFO_ENTRY(MULTIPLESTORAGEOBJECTS)
      PROPERTY_INFO_ENTRY(MULTITABLEUPDATE)
      PROPERTY_INFO_ENTRY(NULLCOLLATION)
      PROPERTY_INFO_ENTRY(OLEOBJECTS)
      PROPERTY_INFO_ENTRY(ORDERBYCOLUMNSINSELECT)
      PROPERTY_INFO_ENTRY(OUTPUTPARAMETERAVAILABILITY)
      PROPERTY_INFO_ENTRY(PERSISTENTIDTYPE)
      PROPERTY_INFO_ENTRY(PREPAREABORTBEHAVIOR)
      PROPERTY_INFO_ENTRY(PREPARECOMMITBEHAVIOR)
      PROPERTY_INFO_ENTRY(PROCEDURETERM)
      PROPERTY_INFO_ENTRY(PROVIDERNAME)
      PROPERTY_INFO_ENTRY(PROVIDEROLEDBVER)
      PROPERTY_INFO_ENTRY(PROVIDERVER)
      PROPERTY_INFO_ENTRY(QUOTEDIDENTIFIERCASE)
      PROPERTY_INFO_ENTRY(ROWSETCONVERSIONSONCOMMAND)
      PROPERTY_INFO_ENTRY(SCHEMATERM)
      PROPERTY_INFO_ENTRY(SCHEMAUSAGE)
      PROPERTY_INFO_ENTRY(STRUCTUREDSTORAGE)
      PROPERTY_INFO_ENTRY(SUBQUERIES)
      PROPERTY_INFO_ENTRY(TABLETERM)
      PROPERTY_INFO_ENTRY(USERNAME)
   END_PROPERTY_SET(DBPROPSET_DATASOURCEINFO)
   BEGIN_PROPERTY_SET(DBPROPSET_DBINIT)
      PROPERTY_INFO_ENTRY(AUTH_PASSWORD)
      PROPERTY_INFO_ENTRY(AUTH_PERSIST_SENSITIVE_AUTHINFO)
      PROPERTY_INFO_ENTRY(AUTH_USERID)
      PROPERTY_INFO_ENTRY(INIT_DATASOURCE)
      PROPERTY_INFO_ENTRY(INIT_HWND)
      PROPERTY_INFO_ENTRY(INIT_LCID)
      PROPERTY_INFO_ENTRY(INIT_LOCATION)
      PROPERTY_INFO_ENTRY(INIT_MODE)
      PROPERTY_INFO_ENTRY(INIT_PROMPT)
      PROPERTY_INFO_ENTRY(INIT_PROVIDERSTRING)
      PROPERTY_INFO_ENTRY(INIT_TIMEOUT)
   END_PROPERTY_SET(DBPROPSET_DBINIT)
   BEGIN_PROPERTY_SET(DBPROPSET_DATASOURCE)
      PROPERTY_INFO_ENTRY(CURRENTCATALOG)
   END_PROPERTY_SET(DBPROPSET_DATASOURCE)
   CHAIN_PROPERTY_SET(CCustomSession)
END_PROPSET_MAP()
```

As propriedades no OLE DB são agrupadas. O objeto de fonte de dados tem dois grupos de propriedades: uma para o DBPROPSET_DATASOURCEINFO definido e um para o DBPROPSET_DBINIT definido. O conjunto DBPROPSET_DATASOURCEINFO corresponde às propriedades sobre o provedor e sua fonte de dados. O conjunto DBPROPSET_DBINIT corresponde a propriedades usadas na inicialização. O OLE DB modelos de provedor lidar com esses conjuntos com as macros PROPERTY_SET. As macros de criar um bloco que contém uma matriz de propriedades. Sempre que o cliente chama o `IDBProperties` interface, o provedor usa o mapa de propriedade.

Você não precisa implementar todas as propriedades na especificação. No entanto, você deve dar suporte as propriedades necessárias; Consulte a especificação de conformidade de nível 0 para obter mais informações. Se você não quiser dar suporte a uma propriedade, remova-a do mapa. Se você quiser dar suporte a uma propriedade, adicioná-lo para o mapa usando uma macro PROPERTY_INFO_ENTRY. A macro corresponde à `UPROPINFO` estrutura conforme mostrado no código a seguir:

```cpp
struct UPROPINFO
{
   DBPROPID    dwPropId;
   ULONG       ulIDS;
   VARTYPE     VarType;
   DBPROPFLAGS dwFlags;
   union
   {
      DWORD dwVal;
      LPOLESTR szVal;
   };
   DBPROPOPTIONS dwOption;
};
```

Cada elemento na estrutura representa informações para lidar com a propriedade. Ele contém um `DBPROPID` para determinar o GUID e a ID da propriedade. Ele também contém entradas para determinar o tipo e o valor da propriedade.

Se você quiser alterar o valor padrão de uma propriedade (Observe que um consumidor pode alterar o valor de uma propriedade gravável a qualquer momento), você pode usar a macro PROPERTY_INFO_ENTRY_VALUE ou PROPERTY_INFO_ENTRY_EX. Essas macros permitem que você especifique um valor para uma propriedade correspondente. A macro PROPERTY_INFO_ENTRY_VALUE é uma notação abreviada que permite que você altere o valor. A macro PROPERTY_INFO_ENTRY_VALUE chama a macro PROPERTY_INFO_ENTRY_EX. Essa macro permite que você adicionar ou alterar todos os atributos de `UPROPINFO` estrutura.

Se você quiser definir seu próprio conjunto de propriedade, você poderá adicionar um fazendo uma combinação de BEGIN_PROPSET_MAP/END_PROPSET_MAP adicional. Você precisa definir um GUID para o conjunto de propriedades e, em seguida, definir suas próprias propriedades. Se você tiver propriedades específicas do provedor, você deve adicioná-los para uma nova propriedade definida em vez de usar um existente. Isso evita problemas em versões posteriores do OLE DB.

## <a name="user-defined-property-sets"></a>Conjuntos de propriedades definidas pelo usuário

Visual C++ dá suporte a conjuntos de propriedades definidas pelo usuário. Você não precisa substituir `GetProperties` ou `GetPropertyInfo`. Em vez disso, os modelos de detectam qualquer conjunto de propriedades definidas pelo usuário e adicioná-lo ao objeto apropriado.

Se você tiver um conjunto de propriedades definidas pelo usuário que precisa estar disponível no momento da inicialização (ou seja, antes do consumidor chama `IDBInitialize::Initialize`), você pode especificar isso usando o sinalizador UPROPSET_USERINIT em conjunto com a macro BEGIN_PROPERTY_SET_EX. A propriedade definida deve ser no objeto de fonte de dados para este trabalho (como requer a especificação OLE DB). Por exemplo:

```cpp
BEGIN_PROPERTY_SET_EX(DBPROPSET_MYPROPSET, UPROPSET_USERINIT)
   PROPERTY_INFO_ENTRY(DBPROP_MYPROP)
END_PROPERTY_SET_EX(DBPROPSET_MYPROPSET)
```

## <a name="see-also"></a>Consulte também

[Arquivos gerados pelo Assistente do Provedor](../../data/oledb/provider-wizard-generated-files.md)