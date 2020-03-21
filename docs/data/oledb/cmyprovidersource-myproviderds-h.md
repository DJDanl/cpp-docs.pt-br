---
title: CCustomSource (CustomDS.H)
ms.date: 10/22/2018
f1_keywords:
- myproviderds.h
- cmyprovidersource
- customds.h
- ccustomsource
helpviewer_keywords:
- OLE DB providers, wizard-generated files
- CMyProviderSource class in MyProviderDS.H
- CCustomSource class in CustomDS.H
ms.assetid: c143d48e-59c8-4f67-9141-3aab51859b92
ms.openlocfilehash: 60324ae914c9490144a715e06323ee6d184ce201
ms.sourcegitcommit: 8e285a766523e653aeeb34d412dc6f615ef7b17b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/21/2020
ms.locfileid: "80079729"
---
# <a name="ccustomsource-customdsh"></a>CCustomSource (CustomDS. h)

As classes de provedor usam várias heranças. O código a seguir mostra a cadeia de herança para o objeto de fonte de dados:

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

Todos os componentes COM derivam de `CComObjectRootEx` e `CComCoClass`. `CComObjectRootEx` fornece toda a implementação para a interface `IUnknown`. Ele pode lidar com qualquer modelo de Threading. `CComCoClass` manipula qualquer suporte de erro necessário. Se você quiser enviar informações de erro mais avançadas para o cliente, poderá usar algumas das APIs de erro no `CComCoClass`.

O objeto de fonte de dados também é herdado de várias classes ' impl '. Cada classe fornece a implementação para uma interface. O objeto de fonte de dados implementa as interfaces `IPersist`, `IDBProperties`, `IDBInitialize`e `IDBCreateSession`. Cada interface é exigida pelo OLE DB para implementar o objeto de fonte de dados. Você pode optar por dar suporte ou não a uma funcionalidade específica, herdando ou não herdando de uma dessas classes ' impl '. Se você quiser dar suporte à interface `IDBDataSourceAdmin`, herdará da classe `IDBDataSourceAdminImpl` para obter a funcionalidade necessária.

## <a name="com-map"></a>Mapa COM

Sempre que o cliente chama `QueryInterface` para uma interface na fonte de dados, ele passa pelo seguinte mapa COM:

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

Todos os componentes COM derivam de `CComObjectRootEx` e `CComCoClass`. `CComObjectRootEx` fornece toda a implementação para a interface `IUnknown`. Ele pode lidar com qualquer modelo de Threading. `CComCoClass` manipula qualquer suporte de erro necessário. Se você quiser enviar informações de erro mais avançadas para o cliente, poderá usar algumas das APIs de erro no `CComCoClass`.

O objeto de fonte de dados também é herdado de várias classes ' impl '. Cada classe fornece a implementação para uma interface. O objeto de fonte de dados implementa as interfaces `IPersist`, `IDBProperties`, `IDBInitialize`e `IDBCreateSession`. Cada interface é exigida pelo OLE DB para implementar o objeto de fonte de dados. Você pode optar por dar suporte ou não a uma funcionalidade específica, herdando ou não herdando de uma dessas classes ' impl '. Se você quiser dar suporte à interface `IDBDataSourceAdmin`, herdará da classe `IDBDataSourceAdminImpl` para obter a funcionalidade necessária.

## <a name="com-map"></a>Mapa COM

Sempre que o cliente chama `QueryInterface` para uma interface na fonte de dados, ele passa pelo seguinte mapa COM:

```cpp
BEGIN_COM_MAP(CCustomSource)
   COM_INTERFACE_ENTRY(IDBCreateSession)
   COM_INTERFACE_ENTRY(IDBInitialize)
   COM_INTERFACE_ENTRY(IDBProperties)
   COM_INTERFACE_ENTRY(IPersist)
   COM_INTERFACE_ENTRY(IInternalConnection)
END_COM_MAP()
```

As macros COM_INTERFACE_ENTRY são da ATL e dizem a implementação de `QueryInterface` no `CComObjectRootEx` para retornar as interfaces apropriadas.

## <a name="property-map"></a>Mapa de propriedades

O mapa de propriedade especifica todas as propriedades atribuídas pelo provedor:

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

As propriedades no OLE DB são agrupadas. O objeto de fonte de dados tem dois grupos de propriedades: um para o conjunto de DBPROPSET_DATASOURCEINFO e outro para o conjunto de DBPROPSET_DBINIT. O conjunto de DBPROPSET_DATASOURCEINFO corresponde a propriedades sobre o provedor e sua fonte de dados. O conjunto de DBPROPSET_DBINIT corresponde às propriedades usadas na inicialização. Os modelos de provedor de OLE DB lidam com esses conjuntos com as macros PROPERTY_SET. As macros criam um bloco que contém uma matriz de propriedades. Sempre que o cliente chama a interface `IDBProperties`, o provedor usa o mapa de propriedade.

Você não precisa implementar todas as propriedades na especificação. No entanto, você deve dar suporte às propriedades necessárias; consulte a especificação conformidade de nível 0 para obter mais informações. Se você não quiser dar suporte a uma propriedade, poderá removê-la do mapa. Se você quiser dar suporte a uma propriedade, adicione-a ao mapa usando uma macro PROPERTY_INFO_ENTRY. A macro corresponde à estrutura de `UPROPINFO`, conforme mostrado no código a seguir:

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

Cada elemento na estrutura representa informações para manipular a propriedade. Ele contém um `DBPROPID` para determinar o GUID e a ID da propriedade. Ele também contém entradas para determinar o tipo e o valor da propriedade.

Se você quiser alterar o valor padrão de uma propriedade (Observe que um consumidor pode alterar o valor de uma propriedade gravável a qualquer momento), você pode usar a macro PROPERTY_INFO_ENTRY_VALUE ou PROPERTY_INFO_ENTRY_EX. Essas macros permitem que você especifique um valor para uma propriedade correspondente. A macro PROPERTY_INFO_ENTRY_VALUE é uma notação abreviada que permite que você altere o valor. A macro PROPERTY_INFO_ENTRY_VALUE chama a macro PROPERTY_INFO_ENTRY_EX. Essa macro permite adicionar ou alterar todos os atributos na estrutura de `UPROPINFO`.

Se você quiser definir seu próprio conjunto de propriedades, poderá adicionar um fazendo uma combinação adicional de BEGIN_PROPSET_MAP/END_PROPSET_MAP. Defina um GUID para o conjunto de propriedades e defina suas próprias propriedades. Se você tiver propriedades específicas do provedor, adicione-as a um novo conjunto de propriedades em vez de usar uma existente. Isso evita problemas em versões posteriores do OLE DB.

## <a name="user-defined-property-sets"></a>Conjuntos de propriedades definidas pelo usuário

O C++ Visual oferece suporte a conjuntos de propriedades definidas pelo usuário. Você não precisa substituir `GetProperties` ou `GetPropertyInfo`. Em vez disso, os modelos detectam qualquer conjunto de propriedades definidas pelo usuário e o adicionam ao objeto apropriado.

Se você tiver um conjunto de propriedades definido pelo usuário que precisa estar disponível no momento da inicialização (ou seja, antes de o consumidor chamar `IDBInitialize::Initialize`), você pode especificar isso usando o sinalizador UPROPSET_USERINIT junto com a macro BEGIN_PROPERTY_SET_EX. O conjunto de propriedades deve estar no objeto de fonte de dados para que isso funcione (conforme a especificação de OLE DB requer). Por exemplo:

```cpp
BEGIN_PROPERTY_SET_EX(DBPROPSET_MYPROPSET, UPROPSET_USERINIT)
   PROPERTY_INFO_ENTRY(DBPROP_MYPROP)
END_PROPERTY_SET_EX(DBPROPSET_MYPROPSET)
```

## <a name="see-also"></a>Confira também

[Arquivos gerados pelo Assistente do Provedor](../../data/oledb/provider-wizard-generated-files.md)<br/>
