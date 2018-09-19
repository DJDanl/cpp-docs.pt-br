---
title: CMyProviderWindowsFile | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-data
ms.topic: reference
f1_keywords:
- cmyproviderwindowsfile
dev_langs:
- C++
helpviewer_keywords:
- CMyProviderWindowsFile class
- OLE DB providers, wizard-generated files
ms.assetid: 0e9e72ac-1e1e-445f-a7ac-690c20031f9d
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- data-storage
ms.openlocfilehash: 6f3badc08da7bd11e65c244c42c91ad37a584ca5
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46087260"
---
# <a name="cmyproviderwindowsfile"></a>CMyProviderWindowsFile

O assistente cria uma classe para conter uma linha de dados. Nesse caso, ele é chamado `CMyProviderWindowsFile`. O código a seguir para `CMyProviderWindowsFile` é gerado pelo assistente e lista todos os arquivos em um diretório usando o `WIN32_FIND_DATA` estrutura. `CMyProviderWindowsFile` herda o `WIN32_FIND_DATA` estrutura:  
  
```cpp
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
  
`CMyProviderWindowsFile` é chamado de [classe de registro de usuário](../../data/oledb/user-record.md) porque ele também contém um mapa que descreve as colunas no conjunto de linhas do provedor. O mapa de coluna do provedor contém uma entrada para cada campo no conjunto de linhas usando as macros PROVIDER_COLUMN_ENTRY. As macros especificam nome de coluna ordinal e deslocamento para uma entrada de estrutura. As entradas de coluna do provedor no código acima contém deslocamentos no `WIN32_FIND_DATA` estrutura. Quando o consumidor chama `IRowset::GetData`, os dados são transferidos em um buffer contíguo. Em vez de fazer a fazer aritmética de ponteiro, o mapa permite que você especifique um membro de dados.  
  
O `CMyProviderRowset` classe também contém o `Execute` método. `Execute` é o que realmente lê os dados da fonte de nativo. O código a seguir mostra o Assistente gerou `Execute` método. A função usa o Win32 `FindFirstFile` e `FindNextFile` APIs para recuperar informações sobre os arquivos no diretório e colocá-los em instâncias do `CMyProviderWindowsFile` classe.  
  
```cpp
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
  
O diretório a ser pesquisado é representado por `m_strCommandText`; isso contém o texto representado pelo `ICommandText` interface no objeto de comando. Se nenhum diretório for especificado, ele usa o diretório atual.  
  
O método cria uma entrada para cada arquivo (correspondente a uma linha) e o coloca no `m_rgRowData` membro de dados. O `CRowsetImpl` classe define o `m_rgRowData` membro de dados. Os dados nessa matriz representa a tabela inteira e são usados em todo os modelos.  
  
## <a name="see-also"></a>Consulte também  

[Arquivos gerados pelo Assistente do Provedor](../../data/oledb/provider-wizard-generated-files.md)