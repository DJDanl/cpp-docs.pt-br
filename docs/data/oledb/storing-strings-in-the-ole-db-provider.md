---
title: Armazenando cadeias de caracteres no provedor de banco de dados OLE
ms.date: 10/26/2018
helpviewer_keywords:
- user records, editing
ms.assetid: 36cb9635-067c-4cad-8f85-962f28026f6a
ms.openlocfilehash: b1bc7ca74ce114f9d901fc5771a376df973f54a8
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50652329"
---
# <a name="storing-strings-in-the-ole-db-provider"></a>Armazenando cadeias de caracteres no provedor de banco de dados OLE

Em myproviderrs. H, o **ATL OLE DB Provider Wizard** cria um registro de usuário padrão chamado `CWindowsFile`. Para lidar com duas cadeias de caracteres, modifique `CWindowsFile` ou adicionar seu próprio registro de usuário, conforme mostrado no código a seguir:

```cpp
////////////////////////////////////////////////////////////////////////
class CAgentMan: 
   public WIN32_FIND_DATA
   DWORD dwBookmark;              // Add this
   TCHAR szCommand[256];          // Add this
   TCHAR szText[256];             // Add this
   TCHAR szCommand2[256];         // Add this
   TCHAR szText2[256];            // Add this
  
{
public:
BEGIN_PROVIDER_COLUMN_MAP()
   PROVIDER_COLUMN_ENTRY_STR(OLESTR("Command"), 1, 256, GUID_NULL, CAgentMan, szCommand)
   PROVIDER_COLUMN_ENTRY_STR(OLESTR("Text"), 2, 256, GUID_NULL, CAgentMan, szText) 
   PROVIDER_COLUMN_ENTRY_STR(OLESTR("Command2"), 3, 256, GUID_NULL, CAgentMan, szCommand2)
   PROVIDER_COLUMN_ENTRY_STR(OLESTR("Text2"),4, 256, GUID_NULL, CAgentMan, szText2)
END_PROVIDER_COLUMN_MAP()
   bool operator==(const CAgentMan& am) // This is optional 
   {
      return (lstrcmpi(cFileName, wf.cFileName) == 0);
   }
};
```

Os membros de dados `szCommand` e `szText` representam as duas cadeias de caracteres, com `szCommand2` e `szText2` com colunas adicionais, se necessário. O membro de dados `dwBookmark` não é necessário para esse provedor somente leitura simple, mas é usado posteriormente para adicionar um `IRowsetLocate` interface, consulte [melhorando a simples leitura apenas provedor](../../data/oledb/enhancing-the-simple-read-only-provider.md). O `==` operador compara instâncias (implementar esse operador é opcional).

Quando isso for feito, o provedor deve estar pronto para compilar e executar. Para testar o provedor, você precisa de um consumidor com a funcionalidade correspondente. [Implementando um consumidor simples](../../data/oledb/implementing-a-simple-consumer.md) mostra como criar tal um consumidor de teste. Execute o consumidor de teste com o provedor. Verifique se que o consumidor de teste recupera as cadeias de caracteres apropriadas do provedor quando você clica o **executar** botão na **testar consumidor** caixa de diálogo.

Quando você testou com êxito seu provedor, você talvez queira aprimorar sua funcionalidade ao implementar interfaces adicionais. Um exemplo é mostrado na [melhorando o provedor somente leitura simples](../../data/oledb/enhancing-the-simple-read-only-provider.md).

## <a name="see-also"></a>Consulte também

[Implementando o provedor somente leitura simples](../../data/oledb/implementing-the-simple-read-only-provider.md)<br/>
