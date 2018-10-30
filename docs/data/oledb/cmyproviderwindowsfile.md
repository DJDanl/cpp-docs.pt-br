---
title: CCustomWindowsFile | Microsoft Docs
ms.custom: ''
ms.date: 10/22/2018
ms.technology:
- cpp-data
ms.topic: reference
f1_keywords:
- cmyproviderwindowsfile
- ccustomwindowsfile
dev_langs:
- C++
helpviewer_keywords:
- CMyProviderWindowsFile class
- OLE DB providers, wizard-generated files
- CCustomWindowsFile class
ms.assetid: 0e9e72ac-1e1e-445f-a7ac-690c20031f9d
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- data-storage
ms.openlocfilehash: bbbde895c7c83264d0ad77bf50bfc14428cdb99f
ms.sourcegitcommit: 840033ddcfab51543072604ccd5656fc6d4a5d3a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/29/2018
ms.locfileid: "50216260"
---
# <a name="ccustomwindowsfile"></a>CCustomWindowsFile

O assistente cria uma classe que tem uma linha de dados. Nesse caso, ele é chamado `CCustomWindowsFile`. O código a seguir para `CCustomWindowsFile` é gerado pelo assistente e lista todos os arquivos em um diretório usando o `WIN32_FIND_DATA` estrutura. `CCustomWindowsFile` herda o `WIN32_FIND_DATA` estrutura:

```cpp
/////////////////////////////////////////////////////////////////////
// CustomRS.H

class CCustomWindowsFile: 
   public WIN32_FIND_DATA
{
public:
BEGIN_PROVIDER_COLUMN_MAP(CCustomWindowsFile)
   PROVIDER_COLUMN_ENTRY("FileAttributes", 1, dwFileAttributes)
   PROVIDER_COLUMN_ENTRY("FileSizeHigh", 2, nFileSizeHigh)
   PROVIDER_COLUMN_ENTRY("FileSizeLow", 3, nFileSizeLow)
   PROVIDER_COLUMN_ENTRY_STR("FileName", 4, cFileName)
   PROVIDER_COLUMN_ENTRY_STR("AltFileName", 5, cAlternateFileName)
END_PROVIDER_COLUMN_MAP()
};
```

`CCustomWindowsFile` é chamado de [classe de registro de usuário](../../data/oledb/user-record.md) porque ele também tem um mapa que descreve as colunas no conjunto de linhas do provedor. O mapa de coluna do provedor contém uma entrada para cada campo no conjunto de linhas usando as macros PROVIDER_COLUMN_ENTRY. As macros especificam nome de coluna ordinal e deslocamento para uma entrada de estrutura. As entradas de coluna do provedor no código acima contém deslocamentos no `WIN32_FIND_DATA` estrutura. Quando o consumidor chama `IRowset::GetData`, os dados são transferidos em um buffer contíguo. Em vez de fazer a fazer aritmética de ponteiro, o mapa permite que você especifique um membro de dados.

O `CCustomRowset` classe também contém o `Execute` método. `Execute` é o que realmente lê os dados da fonte de nativo. O código a seguir mostra o Assistente gerou `Execute` método. A função usa o Win32 `FindFirstFile` e `FindNextFile` APIs para recuperar informações sobre os arquivos no diretório e colocá-los em instâncias do `CCustomWindowsFile` classe.

```cpp
/////////////////////////////////////////////////////////////////////
// CustomRS.H

HRESULT Execute(DBPARAMS * pParams, LONG* pcRowsAffected)
{
   USES_CONVERSION;
   BOOL bFound = FALSE;
   HANDLE hFile;
   LPTSTR  szDir = (m_strCommandText == _T("")) ? _T("*.*") :
       OLE2T(m_strCommandText);
   CCustomWindowsFile wf;
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

O diretório a ser pesquisado é mostrado pelas `m_strCommandText`; isso contém o texto representado pelo `ICommandText` interface no objeto de comando. Se nenhum diretório for especificado, ele usa o diretório atual.

O método cria uma entrada para cada arquivo (correspondente a uma linha) e o coloca no `m_rgRowData` membro de dados. O `CRowsetImpl` classe define o `m_rgRowData` membro de dados. Os dados nessa matriz são mostrados na tabela inteira e são usados em todo os modelos.

## <a name="see-also"></a>Consulte também

[Arquivos gerados pelo Assistente do Provedor](../../data/oledb/provider-wizard-generated-files.md)<br/>
