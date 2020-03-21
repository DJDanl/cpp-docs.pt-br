---
title: CCustomWindowsFile
ms.date: 10/22/2018
f1_keywords:
- cmyproviderwindowsfile
- ccustomwindowsfile
helpviewer_keywords:
- CMyProviderWindowsFile class
- OLE DB providers, wizard-generated files
- CCustomWindowsFile class
ms.assetid: 0e9e72ac-1e1e-445f-a7ac-690c20031f9d
ms.openlocfilehash: 103a1ce5568c6137994056e574ce8eec04511d8f
ms.sourcegitcommit: 8e285a766523e653aeeb34d412dc6f615ef7b17b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/21/2020
ms.locfileid: "80079742"
---
# <a name="ccustomwindowsfile"></a>CCustomWindowsFile

O assistente cria uma classe que tem uma linha de dados; Nesse caso, ele é chamado de `CCustomWindowsFile`. O código a seguir para `CCustomWindowsFile` é gerado pelo assistente e lista todos os arquivos em um diretório usando a estrutura de `WIN32_FIND_DATA`. `CCustomWindowsFile` herda da estrutura de `WIN32_FIND_DATA`:

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

`CCustomWindowsFile` é chamado de [classe de registro de usuário](../../data/oledb/user-record.md) porque também tem um mapa que descreve as colunas no conjunto de linhas do provedor. O mapa de colunas do provedor contém uma entrada para cada campo no conjunto de linhas usando as macros PROVIDER_COLUMN_ENTRY. As macros especificam o nome da coluna, o ordinal e o deslocamento para uma entrada de estrutura. As entradas de coluna do provedor no código acima contêm deslocamentos para a estrutura de `WIN32_FIND_DATA`. Quando o consumidor chama `IRowset::GetData`, os dados são transferidos em um buffer contíguo. Em vez de fazer com que você faça a aritmética do ponteiro, o mapa permite que você especifique um membro de dados.

A classe `CCustomRowset` também contém o método `Execute`. `Execute` é o que realmente lê os dados da fonte nativa. O código a seguir mostra o método de `Execute` gerado pelo assistente. A função usa as APIs de `FindFirstFile` e `FindNextFile` do Win32 para recuperar informações sobre os arquivos no diretório e colocá-los em instâncias da classe `CCustomWindowsFile`.

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

O diretório a ser pesquisado é mostrado por `m_strCommandText`; Isso contém o texto representado pela interface `ICommandText` no objeto Command. Se nenhum diretório for especificado, ele usará o diretório atual.

O método cria uma entrada para cada arquivo (correspondente a uma linha) e o coloca no membro de dados `m_rgRowData`. A classe `CRowsetImpl` define o membro de dados `m_rgRowData`. Os dados nessa matriz são mostrados na tabela inteira e são usados em todos os modelos.

## <a name="see-also"></a>Confira também

[Arquivos gerados pelo Assistente do Provedor](../../data/oledb/provider-wizard-generated-files.md)<br/>
