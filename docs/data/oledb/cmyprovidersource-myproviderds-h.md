---
title: CMyProviderSource (myproviderds. H) | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- myproviderds.h
- cmyprovidersource
dev_langs:
- C++
helpviewer_keywords:
- OLE DB providers, wizard-generated files
- CMyProviderSource class in MyProviderDS.H
ms.assetid: c143d48e-59c8-4f67-9141-3aab51859b92
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
- data-storage
ms.openlocfilehash: 0bdb766abd034868fe12fc0913fbdd99287b9e4f
ms.sourcegitcommit: d51ed21ab2b434535f5c1d553b22e432073e1478
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/23/2018
---
# <a name="cmyprovidersource-myproviderdsh"></a>CMyProviderSource (MyProviderDS.H)
As classes de provedor usam várias heranças. O código a seguir mostra a cadeia de herança para o objeto de fonte de dados:  
  
```cpp
/////////////////////////////////////////////////////////////////////////  
// CMyProviderSource  
class ATL_NO_VTABLE CMyProviderSource :   
   public CComObjectRootEx<CComSingleThreadModel>,  
   public CComCoClass<CMyProviderSource, &CLSID_MyProvider>,  
   public IDBCreateSessionImpl<CMyProviderSource, CMyProviderSession>,  
   public IDBInitializeImpl<CMyProviderSource>,  
   public IDBPropertiesImpl<CMyProviderSource>,  
   public IPersistImpl<CMyProviderSource>,  
   public IInternalConnectionImpl<CMyProviderSource>  
```  
  
 Todos os componentes COM derivam `CComObjectRootEx` e `CComCoClass`. `CComObjectRootEx` fornece a implementação para o **IUnknown** interface. Ele pode lidar com qualquer modelo de threading. `CComCoClass` trata qualquer suporte erro necessário. Se você deseja enviar as informações de erro para o cliente, você pode usar algumas das APIs de erro em `CComCoClass`.  
  
 O objeto de fonte de dados também herda de várias classes de 'Impl'. Cada classe fornece a implementação de uma interface. A fonte de dados objeto implementa a `IPersist`, `IDBProperties`, **IDBInitialize**, e **IDBCreateSession** interfaces. Cada interface é necessária pelo OLE DB para implementar o objeto de fonte de dados. Você pode escolher dar suporte ou não suporte à funcionalidade específica por herança ou não herdar de uma dessas classes de 'Impl'. Se você deseja dar suporte a **IDBDataSourceAdmin** interface, você herda o **IDBDataSourceAdminImpl** classe para obter a funcionalidade necessária.  
  
## <a name="com-map"></a>Mapa COM  
 Sempre que o cliente chama `QueryInterface` para uma interface na fonte de dados, ele passa pelas seguinte mapa COM:  
  
```  
BEGIN_COM_MAP(CMyProviderSource)  
   COM_INTERFACE_ENTRY(IDBCreateSession)  
   COM_INTERFACE_ENTRY(IDBInitialize)  
   COM_INTERFACE_ENTRY(IDBProperties)  
   COM_INTERFACE_ENTRY(IPersist)  
   COM_INTERFACE_ENTRY(IInternalConnection)  
END_COM_MAP()  
```  
  
 As macros COM_INTERFACE_ENTRY são de ATL e informar a implementação de `QueryInterface` na `CComObjectRootEx` para retornar as interfaces apropriadas.  
  
## <a name="property-map"></a>Mapa de propriedade  
 O mapa de propriedade especifica todas as propriedades designadas pelo provedor:  
  
```  
BEGIN_PROPSET_MAP(CMyProviderSource)  
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
   CHAIN_PROPERTY_SET(CMyProviderSession)  
END_PROPSET_MAP()  
```  
  
 Propriedades no OLE DB são agrupadas. O objeto de fonte de dados tem dois grupos de propriedades: uma para o **DBPROPSET_DATASOURCEINFO** conjunto e outro para o **DBPROPSET_DBINIT** definido. O **DBPROPSET_DATASOURCEINFO** conjunto corresponde às propriedades sobre o provedor e fonte de dados. O **DBPROPSET_DBINIT** conjunto corresponde a propriedades usadas na inicialização. Os modelos OLE DB Provider lidar com esses conjuntos com as macros PROPERTY_SET. As macros crie um bloco que contém uma matriz de propriedades. Sempre que o cliente chama o `IDBProperties` interface, o provedor usa o mapa de propriedade.  
  
 Você não precisa implementar todas as propriedades na especificação. No entanto, você deve dar suporte as propriedades necessárias; Consulte a especificação de conformidade de nível 0 para obter mais informações. Se você não deseja dar suporte a uma propriedade, você pode removê-lo do mapa. Se você deseja dar suporte a uma propriedade, adicione-o para o mapa usando uma macro PROPERTY_INFO_ENTRY. A macro corresponde do **UPROPINFO** estrutura conforme mostrado no código a seguir:  
  
```  
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
  
 Cada elemento na estrutura representa informações para lidar com a propriedade. Ele contém um **DBPROPID** para determinar o GUID e a ID da propriedade. Ele também contém entradas para determinar o tipo e o valor da propriedade.  
  
 Se você quiser alterar o valor padrão de uma propriedade (Observe que um consumidor pode alterar o valor de uma propriedade gravável a qualquer momento), você pode usar o PROPERTY_INFO_ENTRY_VALUE ou PROPERTY_INFO_ENTRY_EX macro. Essas macros permitem que você especifique um valor para uma propriedade correspondente. A macro PROPERTY_INFO_ENTRY_VALUE é uma notação abreviada que permite que você altere o valor. A macro PROPERTY_INFO_ENTRY_VALUE chama a macro PROPERTY_INFO_ENTRY_EX. Esta macro permite que você adicionar ou alterar todos os atributos no **UPROPINFO** estrutura.  
  
 Se você quiser definir seu próprio conjunto de propriedades, você pode adicionar uma fazendo uma combinação de BEGIN_PROPSET_MAP/END_PROPSET_MAP adicional. Você precisa definir um GUID para o conjunto de propriedades e, em seguida, definir suas próprias propriedades. Se você tiver propriedades específicas do provedor, você deve adicioná-los para uma nova propriedade definida em vez de usar um existente. Isso evita problemas em versões posteriores do OLE DB.  
  
## <a name="user-defined-property-sets"></a>Conjuntos de propriedades definidas pelo usuário  
 Visual C++ dá suporte a conjuntos de propriedades definidas pelo usuário. Você não tem que substituir **GetProperties** ou `GetPropertyInfo`. Em vez disso, os modelos de detectam qualquer conjunto de propriedades definidas pelo usuário e adicioná-lo para o objeto apropriado.  
  
 Se você tiver um conjunto de propriedades definidas pelo usuário que precisa estar disponível no momento da inicialização (ou seja, antes do consumidor chama **IDBInitialize:: Initialize**), você pode especificar isso usando o **UPROPSET_USERINIT** sinalizador em conjunto com a macro BEGIN_PROPERTY_SET_EX. O conjunto de propriedades deve ser no objeto de fonte de dados para este trabalho (como requer a especificação OLE DB). Por exemplo:  
  
```  
BEGIN_PROPERTY_SET_EX(DBPROPSET_MYPROPSET, UPROPSET_USERINIT)  
   PROPERTY_INFO_ENTRY(DBPROP_MYPROP)  
END_PROPERTY_SET_EX(DBPROPSET_MYPROPSET)  
```  
  
## <a name="see-also"></a>Consulte também  
 [Arquivos gerados pelo Assistente do Provedor](../../data/oledb/provider-wizard-generated-files.md)