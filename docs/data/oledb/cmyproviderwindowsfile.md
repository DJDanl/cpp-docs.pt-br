---
title: "CMyProviderWindowsFile | Microsoft Docs"
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
  - "cmyproviderwindowsfile"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe CMyProviderWindowsFile"
  - "Provedores OLE DB, arquivos gerados por assistente"
ms.assetid: 0e9e72ac-1e1e-445f-a7ac-690c20031f9d
caps.latest.revision: 6
caps.handback.revision: 6
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# CMyProviderWindowsFile
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

O assistente cria uma classe para conter uma linha de dados; nesse caso, é chamado `CMyProviderWindowsFile`.  O código a seguir para `CMyProviderWindowsFile` assistente é gerado e lista todos os arquivos em um diretório usando a estrutura de **WIN32\_FIND\_DATA** .  `CMyProviderWindowsFile` herda da estrutura de **WIN32\_FIND\_DATA** :  
  
```  
/////////////////////////////////////////////////////////////////////  
// MyProviderRS.H  
  
class CMyProviderWindowsFile:   
   public WIN32_FIND_DATA  
{  
public:  
BEGIN_PROVIDER_COLUMN_MAP(CMyProviderWindowsFile)  
   PROVIDER_COLUMN_ENTRY("FileAttributes", 1, dwFileAttributes)  
   PROVIDER_COLUMN_ENTRY("FileSizeHigh", 2, nFileSizeHigh)  
   PROVIDER_COLUMN_ENTRY("FileSizeLow", 3, nFileSizeLow)  
   PROVIDER_COLUMN_ENTRY_STR("FileName", 4, cFileName)  
   PROVIDER_COLUMN_ENTRY_STR("AltFileName", 5, cAlternateFileName)  
END_PROVIDER_COLUMN_MAP()  
};  
```  
  
 `CMyProviderWindowsFile` é chamado [classe de registro do usuário](../../data/oledb/user-record.md) como também contém um mapa que descreve as colunas no conjunto de linhas do provedor.  O mapa da coluna do provedor contém uma entrada para cada campo no conjunto de linhas usando as macros de PROVIDER\_COLUMN\_ENTRY.  Macros especificam o nome da coluna, o ordinal, e o deslocamento a uma entrada de estrutura.  As entradas da coluna do provedor no código anterior contêm deslocamentos na estrutura de **WIN32\_FIND\_DATA** .  Quando o consumidor chama **IRowset::GetData**, os dados são transferidos em um buffer contíguas.  Em vez de fazer o execute aritmética do ponteiro, o mapa permite que você especifique um membro de dados.  
  
 A classe de `CMyProviderRowset` também contém o método de `Execute` .  `Execute` é o fato que lê os dados na origem nativo.  O código a seguir mostra o método script MDX de `Execute` .  A função usa **FindFirstFile** APIs do Win32 e `FindNextFile` para recuperar informações sobre os arquivos no diretório e para inseri\-los nas instâncias de classe de `CMyProviderWindowsFile` .  
  
```  
/////////////////////////////////////////////////////////////////////  
// MyProviderRS.H  
  
HRESULT Execute(DBPARAMS * pParams, LONG* pcRowsAffected)  
{  
   USES_CONVERSION;  
   BOOL bFound = FALSE;  
   HANDLE hFile;  
   LPTSTR  szDir = (m_strCommandText == _T("")) ? _T("*.*") :  
       OLE2T(m_strCommandText);  
   CMyProviderWindowsFile wf;  
   hFile = FindFirstFile(szDir, &wf);  
   if (hFile == INVALID_HANDLE_VALUE)  
      return DB_E_ERRORSINCOMMAND;  
   LONG cFiles = 1;  
   BOOL bMoreFiles = TRUE;  
   while (bMoreFiles)  
   {  
      if (!m_rgRowData.Add(wf))  
         return E_OUTOFMEMORY;  
      bMoreFiles = FindNextFile(hFile, &wf);  
      cFiles++;  
   }  
   FindClose(hFile);  
   if (pcRowsAffected != NULL)  
      *pcRowsAffected = cFiles;  
   return S_OK;  
}  
```  
  
 O diretório a ser pesquisada é representado por `m_strCommandText`; ele contém o texto representado pela interface de `ICommandText` no objeto de comando.  Se nenhum diretório é especificado, usa o diretório atual.  
  
 O método cria uma entrada para cada arquivo \(que correspondem a uma linha\) e locais ele no membro de dados de **m\_rgRowData** .  A classe de `CRowsetImpl` define o membro de dados de **m\_rgRowData** .  Os dados nesta matriz representam a tabela inteira e são usados durante todos os modelos.  
  
## Consulte também  
 [Arquivos gerados pelo Assistente do Provedor](../../data/oledb/provider-wizard-generated-files.md)