---
title: Armazenando cadeias de caracteres no provedor de banco de dados OLE
ms.date: 10/26/2018
helpviewer_keywords:
- user records, editing
ms.assetid: 36cb9635-067c-4cad-8f85-962f28026f6a
ms.openlocfilehash: 5dce7dac84ef69da17baac135a68bd78698c4456
ms.sourcegitcommit: c7f90df497e6261764893f9cc04b5d1f1bf0b64b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/05/2019
ms.locfileid: "59026403"
---
# <a name="storing-strings-in-the-ole-db-provider"></a>Armazenando cadeias de caracteres no provedor de banco de dados OLE

Na *personalizado*RS.h, o **Assistente da ATL OLE DB Provider** cria um registro de usuário padrão chamado `CWindowsFile`. Para lidar com duas cadeias de caracteres, modifique `CWindowsFile` conforme mostrado no código a seguir:

```cpp
////////////////////////////////////////////////////////////////////////
class CCustomWindowsFile:
   public WIN32_FIND_DATA
{
public:
DWORD dwBookmark;
static const int iSize = 256;    // Add this
TCHAR szCommand[iSize];          // Add this
TCHAR szText[iSize];             // Add this
TCHAR szCommand2[iSize];         // Add this
TCHAR szText2[iSize];            // Add this

BEGIN_PROVIDER_COLUMN_MAP(CCustomWindowsFile)
   PROVIDER_COLUMN_ENTRY("FileAttributes", 1, dwFileAttributes)
   PROVIDER_COLUMN_ENTRY("FileSizeHigh", 2, nFileSizeHigh)
   PROVIDER_COLUMN_ENTRY("FileSizeLow", 3, nFileSizeLow)
   PROVIDER_COLUMN_ENTRY_STR("FileName", 4, cFileName)
   PROVIDER_COLUMN_ENTRY_STR("AltFileName", 5, cAlternateFileName)

   PROVIDER_COLUMN_ENTRY_STR("Command", 6, szCommand)    // Add this
   PROVIDER_COLUMN_ENTRY_STR("Text", 7, szText)          // Add this
   PROVIDER_COLUMN_ENTRY_STR("Command2", 8, szCommand2)  // Add this
   PROVIDER_COLUMN_ENTRY_STR("Text2", 9, szText2)        // Add this
END_PROVIDER_COLUMN_MAP()

   bool operator==(const CCustomWindowsFile& am) // This is optional
   {
      return (lstrcmpi(cFileName, am.cFileName) == 0);
   }
};
```

Os membros de dados `szCommand` e `szText` representam as duas cadeias de caracteres, com `szCommand2` e `szText2` com colunas adicionais, se necessário. O membro de dados `dwBookmark` não é necessário para esse provedor somente leitura simple, mas é usado posteriormente para adicionar um `IRowsetLocate` interface, consulte [melhorando a simples leitura apenas provedor](../../data/oledb/enhancing-the-simple-read-only-provider.md). O `==` operador compara instâncias (implementar esse operador é opcional).

Quando isso for feito, você pode adicionar a funcionalidade do [lendo cadeias de caracteres no provedor de OLE DB](../../data/oledb/reading-strings-into-the-ole-db-provider.md).

## <a name="see-also"></a>Consulte também

[Implementando o provedor somente leitura simples](../../data/oledb/implementing-the-simple-read-only-provider.md)<br/>
