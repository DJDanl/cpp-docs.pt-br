---
title: "Suporte do provedor para indicadores | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "indicadores, OLE DB"
  - "Classe IRowsetLocate"
  - "Classe IRowsetLocate, suporte do provedor para indicadores"
  - "modelos de provedor do OLE DB, indicadores"
  - "Provedores OLE DB, suporte a indicadores"
ms.assetid: 1b14ccff-4f76-462e-96ab-1aada815c377
caps.latest.revision: 7
caps.handback.revision: 7
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Suporte do provedor para indicadores
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

O exemplo neste tópico adiciona a interface de `IRowsetLocate` à classe de `CMyProviderRowset` .  Em quase todos os casos, você começa adicionando uma interface para um objeto COM existente.  Você pode então adicionar mais chama teste de modelos do consumidor.  O exemplo a seguir demonstra como:  
  
-   Adicionar uma interface para um provedor.  
  
-   Determinar dinamicamente as colunas retornar ao consumidor.  
  
-   Adicionar suporte do medidor.  
  
 A interface de `IRowsetLocate` herda da interface de `IRowset` .  Para adicionar a interface de `IRowsetLocate` , herde `CMyProviderRowset` de [IRowsetLocateImpl](../../data/oledb/irowsetlocateimpl-class.md).  
  
 Adicionar a interface de `IRowsetLocate` é um pouco diferente da maioria das interfaces.  Para fazer a linha de VTABLEs, os modelos do provedor OLE DB tem um parâmetro de modelo para controlar a interface derivada.  O código a seguir mostra a nova lista de herança:  
  
```  
////////////////////////////////////////////////////////////////////////  
// MyProviderRS.h  
  
// CMyProviderRowset  
class CMyProviderRowset : public CRowsetImpl< CMyProviderRowset,   
      CTextData, CMyProviderCommand, CAtlArray<CTextData>,   
      CSimpleRow,   
          IRowsetLocateImpl<CMyProviderRowset, IRowsetLocate> >  
```  
  
 Todos do quarto, o quinto, e o sexto os parâmetros são adicionados.  Este exemplo usa as opções para o quarto e o quinto parâmetros mas especifica `IRowsetLocateImpl` como o sexto parâmetro.  `IRowsetLocateImpl` é uma classe do modelo OLE DB que usa dois parâmetros do modelo: esses engancham acima da interface de `IRowsetLocate` à classe de `CMyProviderRowset` .  Para adicionar a maioria das interfaces, ignore esta etapa e passar a seguir.  Somente as interfaces de `IRowsetLocate` e de `IRowsetScroll` precisam ser tratadas dessa maneira.  
  
 É necessário depois de saber `CMyProviderRowset` para chamar `QueryInterface` para a interface de `IRowsetLocate` .  Adicionar a linha `COM_INTERFACE_ENTRY(IRowsetLocate)` ao mapa.  O mapa da interface para `CMyProviderRowset` deve aparecer como mostrado no seguinte código:  
  
```  
////////////////////////////////////////////////////////////////////////  
// MyProviderRS.h  
  
typedef CRowsetImpl< CMyProviderRowset, CTextData, CMyProviderCommand, CAtlArray<CTextData>, CSimpleRow, IRowsetLocateImpl<CMyProviderRowset, IRowsetLocate> > _RowsetBaseClass;  
  
BEGIN_COM_MAP(CMyProviderRowset)  
   COM_INTERFACE_ENTRY(IRowsetLocate)  
   COM_INTERFACE_ENTRY_CHAIN(_RowsetBaseClass)  
END_COM_MAP()  
```  
  
 Você também precisa conectar seu mapa na classe de `CRowsetImpl` .  Adicionar em macro de COM\_INTERFACE\_ENTRY\_CHAIN ao gancho no mapa de `CRowsetImpl` .  Além disso, crie um typedef chamado `RowsetBaseClass` que consiste em informações de herança.  Este typedef é arbitrário e pode ser ignorado.  
  
 Finalmente, controlar a chamada de **IColumnsInfo::GetColumnsInfo** .  Normalmente você usaria macros de PROVIDER\_COLUMN\_ENTRY para fazer isso.  No entanto, um consumidor pode querer usar medidores.  Você deve poder alterar as colunas que o provedor retornará se o consumidor solicita um medidor.  
  
 Para controlar a chamada de **IColumnsInfo::GetColumnsInfo** , exclua o mapa de **PROVIDER\_COLUMN** na classe de `CTextData` .  A macro de PROVIDER\_COLUMN\_MAP define uma função `GetColumnInfo`.  Você precisa definir sua própria função de `GetColumnInfo` .  A declaração de função deve ter esta aparência:  
  
```  
////////////////////////////////////////////////////////////////////////  
// MyProviderRS.H  
  
class CTextData  
{  
   ...  
     // NOTE: Be sure you removed the PROVIDER_COLUMN_MAP!  
   static ATLCOLUMNINFO* GetColumnInfo(CMyProviderRowset* pThis,   
        ULONG* pcCols);  
   static ATLCOLUMNINFO* GetColumnInfo(CMyProviderCommand* pThis,   
        ULONG* pcCols);  
...  
};  
```  
  
 Em seguida, implementar a função de `GetColumnInfo` no arquivo de MyProviderRS.cpp como segue:  
  
```  
////////////////////////////////////////////////////////////////////  
// MyProviderRS.cpp  
  
template <class TInterface>  
ATLCOLUMNINFO* CommonGetColInfo(IUnknown* pPropsUnk, ULONG* pcCols)  
{  
   static ATLCOLUMNINFO _rgColumns[5];  
   ULONG ulCols = 0;  
  
   CComQIPtr<TInterface> spProps = pPropsUnk;  
  
   CDBPropIDSet set(DBPROPSET_ROWSET);  
   set.AddPropertyID(DBPROP_BOOKMARKS);  
   DBPROPSET* pPropSet = NULL;  
   ULONG ulPropSet = 0;  
   HRESULT hr;  
  
   if (spProps)  
      hr = spProps->GetProperties(1, &set, &ulPropSet, &pPropSet);  
  
   // Check the property flag for bookmarks, if it is set, set the   
// zero ordinal entry in the column map with the bookmark   
// information.  
  
   if (pPropSet)  
   {  
      CComVariant var = pPropSet->rgProperties[0].vValue;  
      CoTaskMemFree(pPropSet->rgProperties);  
      CoTaskMemFree(pPropSet);  
  
      if ((SUCCEEDED(hr) && (var.boolVal == VARIANT_TRUE)))  
      {  
         ADD_COLUMN_ENTRY_EX(ulCols, OLESTR("Bookmark"), 0,   
                     sizeof(DWORD), DBTYPE_BYTES,  
            0, 0, GUID_NULL, CAgentMan, dwBookmark,         
                        DBCOLUMNFLAGS_ISBOOKMARK)  
         ulCols++;  
      }  
  
   }  
  
   // Next set the other columns up.  
   ADD_COLUMN_ENTRY_EX(ulCols, OLESTR("Field1"), 1, 16, DBTYPE_STR,   
          0xFF, 0xFF, GUID_NULL, CTextData, szField1)  
   ulCols++;  
   ADD_COLUMN_ENTRY_EX(ulCols, OLESTR("Field2"), 2, 16, DBTYPE_STR,  
       0xFF, 0xFF, GUID_NULL, CTextData, szField2)  
   ulCols++;  
  
   if (pcCols != NULL)  
      *pcCols = ulCols;  
  
   return _rgColumns;  
}  
  
ATLCOLUMNINFO* CTextData::GetColumnInfo(CMyProviderCommand* pThis,   
     ULONG* pcCols)  
{  
   return CommonGetColInfo<ICommandProperties>(pThis->GetUnknown(),  
        pcCols);  
}  
  
ATLCOLUMNINFO* CAgentMan::GetColumnInfo(RUpdateRowset* pThis, ULONG* pcCols)  
{  
   return CommonGetColInfo<IRowsetInfo>(pThis->GetUnknown(), pcCols);  
}  
```  
  
 `GetColumnInfo` verificará primeiramente se uma propriedade chamada **DBPROP\_IRowsetLocate** está definida.  OLE DB tem as propriedades para cada uma das interfaces opcionais do objeto do conjunto de linhas.  Se o consumidor deseja usar uma dessas interfaces opcionais, define uma propriedade para retificar.  O provedor então poderá marcar esta propriedade e executar a ação especial com base nele.  
  
 Em sua implementação, você obtém a propriedade que usa o ponteiro para o objeto de comando.  O ponteiro de `pThis` representa a classe do conjunto de linhas ou do comando.  Como usar modelos a partir daqui, você deve transmitir este em como um ponteiro de `void` ou falham ao compilar o código.  
  
 Especifique uma matriz estático para conter informações da coluna.  Se o consumidor não quiser que a coluna do indicador, uma entrada na matriz será inútil.  Você pode atribuir dinamicamente essa matriz, mas você precisará verificar destrui\-la corretamente.  Este exemplo define e usar macros ADD\_COLUMN\_ENTRY e ADD\_COLUMN\_ENTRY\_EX para inserir informações na matriz.  Você pode adicionar macros para o arquivo de MyProviderRS.H conforme mostrado no seguinte código:  
  
```  
////////////////////////////////////////////////////////////////////////  
// MyProviderRS.h  
  
#define ADD_COLUMN_ENTRY(ulCols, name, ordinal, colSize, type, precision, scale, guid, dataClass, member) \  
   _rgColumns[ulCols].pwszName = (LPOLESTR)name; \  
   _rgColumns[ulCols].pTypeInfo = (ITypeInfo*)NULL; \  
   _rgColumns[ulCols].iOrdinal = (ULONG)ordinal; \  
   _rgColumns[ulCols].dwFlags = 0; \  
   _rgColumns[ulCols].ulColumnSize = (ULONG)colSize; \  
   _rgColumns[ulCols].wType = (DBTYPE)type; \  
   _rgColumns[ulCols].bPrecision = (BYTE)precision; \  
   _rgColumns[ulCols].bScale = (BYTE)scale; \  
   _rgColumns[ulCols].cbOffset = offsetof(dataClass, member);  
  
#define ADD_COLUMN_ENTRY_EX(ulCols, name, ordinal, colSize, type, precision, scale, guid, dataClass, member, flags) \  
   _rgColumns[ulCols].pwszName = (LPOLESTR)name; \  
   _rgColumns[ulCols].pTypeInfo = (ITypeInfo*)NULL; \  
   _rgColumns[ulCols].iOrdinal = (ULONG)ordinal; \  
   _rgColumns[ulCols].dwFlags = flags; \  
   _rgColumns[ulCols].ulColumnSize = (ULONG)colSize; \  
   _rgColumns[ulCols].wType = (DBTYPE)type; \  
   _rgColumns[ulCols].bPrecision = (BYTE)precision; \  
   _rgColumns[ulCols].bScale = (BYTE)scale; \  
   _rgColumns[ulCols].cbOffset = offsetof(dataClass, member); \  
   memset(&(_rgColumns[ulCols].columnid), 0, sizeof(DBID)); \  
   _rgColumns[ulCols].columnid.uName.pwszName = (LPOLESTR)name;  
```  
  
 Para testar o código no consumidor, você precisa fazer nenhuma alteração ao manipulador de `OnRun` .  A primeira alteração para a função é que você adicionar o código para adicionar uma propriedade ao conjunto de propriedades.  Os conjuntos de códigos a propriedade da **DBPROP\_IRowsetLocate** retificar assim, informando ao provedor que você deseja que a coluna do indicador.  O código do manipulador de `OnRun` deve aparecer como segue:  
  
```  
//////////////////////////////////////////////////////////////////////  
// TestProv Consumer Application in TestProvDlg.cpp  
  
void CTestProvDlg::OnRun()   
{  
   CCommand<CAccessor<CProvider> > table;  
   CDataSource source;  
   CSession   session;  
  
   if (source.Open("MyProvider.MyProvider.1", NULL, NULL, NULL,   
          NULL) != S_OK)  
      return;  
  
   if (session.Open(source) != S_OK)  
      return;  
  
   CDBPropSet propset(DBPROPSET_ROWSET);  
   propset.AddProperty(DBPROP_IRowsetLocate, true);  
   if (table.Open(session, _T("c:\\public\\testprf2\\myData.txt"),   
          &propset) != S_OK)  
      return;  
  
   CBookmark<4> tempBookmark;  
   ULONG ulCount=0;  
   while (table.MoveNext() == S_OK)  
   {  
  
      DBCOMPARE compare;  
      if (ulCount == 2)  
         tempBookmark = table.bookmark;  
      HRESULT hr = table.Compare(table.dwBookmark, table.dwBookmark,  
                 &compare);  
      if (FAILED(hr))  
         ATLTRACE(_T("Compare failed: 0x%X\n"), hr);  
      else  
         _ASSERTE(compare == DBCOMPARE_EQ);  
  
      m_ctlString1.AddString(table.szField1);  
      m_ctlString2.AddString(table.szField2);  
      ulCount++;  
   }  
  
   table.MoveToBookmark(tempBookmark);  
   m_ctlString1.AddString(table.szField1);  
   m_ctlString2.AddString(table.szField2);  
}  
```  
  
 O loop while contém o código para chamar o método de `Compare` na interface de `IRowsetLocate` .  O código que você tenha sempre deve passar por que você está comparando exatamente os mesmos indicadores.  Além disso, o armazenamento de um indicador em uma variável temporário de forma que você possa usá\-lo depois do término do loop while para chamar a função de `MoveToBookmark` em modelos do consumidor.  As chamadas de função de `MoveToBookmark` o método de `GetRowsAt` em `IRowsetLocate`.  
  
 Você também precisa atualizar o registro de usuário no consumidor.  Adicione uma entrada na classe para tratar um indicador e uma entrada em **COLUMN\_MAP**:  
  
```  
///////////////////////////////////////////////////////////////////////  
// TestProvDlg.cpp  
  
class CProvider  
{  
// Attributes  
public:  
   CBookmark<4>    bookmark;  // Add this line  
   char   szCommand[16];  
   char   szText[256];  
  
   // Binding Maps  
BEGIN_ACCESSOR_MAP(CProvider, 1)  
   BEGIN_ACCESSOR(0, true)   // auto accessor  
      BOOKMARK_ENTRY(bookmark)  // Add this line  
      COLUMN_ENTRY(1, szField1)  
      COLUMN_ENTRY(2, szField2)  
   END_ACCESSOR()  
END_ACCESSOR_MAP()  
};  
```  
  
 Quando você atualizou o código, você deve poder criar e executar o provedor com a interface de `IRowsetLocate` .  
  
## Consulte também  
 [Técnicas de provedor avançadas](../Topic/Advanced%20Provider%20Techniques.md)