---
title: "CMyProviderSource (MyProviderDS.H) | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
f1_keywords: 
  - ""myproviderds.h""
  - "cmyprovidersource"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe CMyProviderSource em MyProviderDS.H"
  - "Provedores OLE DB, arquivos gerados por assistente"
ms.assetid: c143d48e-59c8-4f67-9141-3aab51859b92
caps.latest.revision: 10
caps.handback.revision: 10
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# CMyProviderSource (MyProviderDS.H)
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

As classes de provedor usam a herança múltipla.  O código a seguir mostra a cadeia de herança para o objeto de fonte de dados:  
  
```  
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
  
 Todos os componentes COM derivam de `CComObjectRootEx` e de `CComCoClass`.  `CComObjectRootEx` fornece qualquer implementação da interface de **IUnknown** .  Pode ter qualquer modelo de threading.  `CComCoClass` controla todo o suporte de erro necessário.  Se você quiser enviar nenhuma informação de erro mais sofisticadas para o cliente, você pode usar qualquer das APIs de erro em `CComCoClass`.  
  
 O objeto de fonte de dados também herda de vários “executar” classes.  Cada classe fornece a implementação de uma interface.  O objeto de fonte de dados implementa `IPersist`, `IDBProperties`, interfaces de **IDBInitialize**, e de **IDBCreateSession** .  Cada interface é necessária por OLE DB implementar o objeto de fonte de dados.  Você pode escolher para oferecer suporte ou não oferecer suporte à funcionalidade específica ou herdando não herdando de um destes “executar” classes.  Se você quiser oferecer suporte à interface de **IDBDataSourceAdmin** , você herda da classe **IDBDataSourceAdminImpl** para obter a funcionalidade necessária.  
  
## Mapa da  
 Sempre que o cliente chama `QueryInterface` para uma interface na fonte de dados, revise o seguinte do mapa COM:  
  
```  
BEGIN_COM_MAP(CMyProviderSource)  
   COM_INTERFACE_ENTRY(IDBCreateSession)  
   COM_INTERFACE_ENTRY(IDBInitialize)  
   COM_INTERFACE_ENTRY(IDBProperties)  
   COM_INTERFACE_ENTRY(IPersist)  
   COM_INTERFACE_ENTRY(IInternalConnection)  
END_COM_MAP()  
```  
  
 Macros de COM\_INTERFACE\_ENTRY são de ATL e indicam a implementação de `QueryInterface` em `CComObjectRootEx` para retornar as interfaces apropriadas.  
  
## Mapa de propriedade  
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
  
 As propriedades no OLE DB são agrupadas.  O objeto de fonte de dados tem dois grupos de propriedades: um para **DBPROPSET\_DATASOURCEINFO** definido e um para **DBPROPSET\_DBINIT** define.  **DBPROPSET\_DATASOURCEINFO** definido corresponde às propriedades sobre o provedor e sua fonte de dados.  **DBPROPSET\_DBINIT** definido corresponde às propriedades usadas na inicialização.  Os modelos do provedor OLE DB trata esses clusters com macros de PROPERTY\_SET.  Macros criam um pacote que contém uma matriz de propriedades.  Sempre que o cliente chama a interface de `IDBProperties` , o provedor usa o mapa da propriedade.  
  
 Você não precisa implementar cada propriedade na especificação.  Porém, você deve oferecer suporte às propriedades necessárias; consulte para o nível 0 especificações de conformidade para obter mais informações.  Se não desejar oferecer suporte a uma propriedade, você poderá removê\-lo do mapa.  Se você quiser oferecer suporte a uma propriedade, adicioná\-las no mapa usando uma macro de PROPERTY\_INFO\_ENTRY.  A macro corresponde à estrutura de **UPROPINFO** conforme mostrado no seguinte código:  
  
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
  
 Cada elemento na estrutura representa informações para controlar a propriedade.  Contém **DBPROPID** para determinar o GUID e o ID para a propriedade.  Também contém entradas para determinar o tipo e o valor da propriedade.  
  
 Se você quiser alterar o valor padrão da propriedade \(observe que um consumidor pode alterar o valor de uma propriedade gravável a qualquer momento\), você pode usar a macro de PROPERTY\_INFO\_ENTRY\_VALUE ou de PROPERTY\_INFO\_ENTRY\_EX.  Esses macros permitem que você especifique um valor de uma propriedade correspondente.  A macro de PROPERTY\_INFO\_ENTRY\_VALUE é uma notação de taquigrafia que permite alterar o valor.  As chamadas macro de PROPERTY\_INFO\_ENTRY\_VALUE a macro de PROPERTY\_INFO\_ENTRY\_EX.  Esta macro permite adicionar ou modificar todos os atributos na estrutura de **UPROPINFO** .  
  
 Se você quiser definir seu próprio conjunto de propriedades, você pode adicionar um fazendo uma combinação de BEGIN\_PROPSET\_MAP\/END\_PROPSET\_MAP adicional.  Você precisa definir o GUID do conjunto de propriedades e depois de definir suas próprias propriedades.  Se você tiver propriedades específicas de provedor, adicioná\-las a um novo conjunto de propriedades em vez de usar existente.  Isso evita problemas em versões posteriores do OLE DB.  
  
## Conjuntos de propriedades definidas pelo usuário  
 Visual C\+\+ .NET der suporte a conjuntos de propriedades definidas pelo usuário.  Você não tem que substituir **GetProperties** ou `GetPropertyInfo`.  Em vez disso, os modelos detectam qualquer conjunto de propriedades definido pelo usuário e o adiciona ao objeto apropriado.  
  
 Se você tiver um conjunto de propriedades definido pelo usuário que precisa estar disponível no momento da inicialização \(ou seja, antes que o consumidor chamar **IDBInitialize::Initialize**\), você pode especificar isso usando o sinalizador de **UPROPSET\_USERINIT** junto com a macro de BEGIN\_PROPERTY\_SET\_EX.  O conjunto de propriedades deve estar no objeto de fonte de dados para essa ao trabalho \(como a especificação OLE DB requer\).  Por exemplo:  
  
```  
BEGIN_PROPERTY_SET_EX(DBPROPSET_MYPROPSET, UPROPSET_USERINIT)  
   PROPERTY_INFO_ENTRY(DBPROP_MYPROP)  
END_PROPERTY_SET_EX(DBPROPSET_MYPROPSET)  
```  
  
## Consulte também  
 [Arquivos gerados pelo Assistente do Provedor](../../data/oledb/provider-wizard-generated-files.md)