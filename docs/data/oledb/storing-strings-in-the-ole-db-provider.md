---
title: Armazenando cadeias de caracteres no provedor de banco de dados OLE
ms.date: 05/09/2019
helpviewer_keywords:
- user records, editing
ms.assetid: 36cb9635-067c-4cad-8f85-962f28026f6a
ms.openlocfilehash: 1d6d2b73495d5ca6e275b13ed3c430f8169179d4
ms.sourcegitcommit: 8e285a766523e653aeeb34d412dc6f615ef7b17b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/21/2020
ms.locfileid: "80079104"
---
# <a name="storing-strings-in-the-ole-db-provider"></a>Armazenando cadeias de caracteres no provedor de banco de dados OLE

> [!NOTE]
> O assistente de Provedor OLE DB da ATL não está disponível no Visual Studio 2019 e posteriores.

Em *Custom*RS.h, o **Assistente de Provedor OLE DB da ATL** cria um registro de usuário padrão chamado `CWindowsFile`. Para lidar com duas cadeias de caracteres, modifique `CWindowsFile` conforme mostrado no seguinte código:

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

Os membros de dados `szCommand` e `szText` representam as duas cadeias de caracteres, com `szCommand2` e `szText2` com colunas adicionais, se necessário. O membro de dados `dwBookmark` não é necessário para esse provedor simples somente leitura, mas é usado posteriormente para adicionar uma interface `IRowsetLocate`. Confira [Aprimoramento do provedor simples somente leitura](../../data/oledb/enhancing-the-simple-read-only-provider.md). O operador `==` compara instâncias (a implementação desse operador é opcional).

Quando isso for feito, você poderá adicionar a funcionalidade de [ler cadeias de caracteres no provedor OLE DB](../../data/oledb/reading-strings-into-the-ole-db-provider.md).

## <a name="see-also"></a>Confira também

[Implementando o provedor somente leitura simples](../../data/oledb/implementing-the-simple-read-only-provider.md)<br/>
