---
title: Armazenamento de cadeias de caracteres no provedor OLE DB | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
dev_langs:
- C++
helpviewer_keywords:
- user records, editing
ms.assetid: 36cb9635-067c-4cad-8f85-962f28026f6a
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
- data-storage
ms.openlocfilehash: 523193d7fa5f18d3d0956d39ca68cdc5d34131b0
ms.sourcegitcommit: 6002df0ac79bde5d5cab7bbeb9d8e0ef9920da4a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/14/2018
---
# <a name="storing-strings-in-the-ole-db-provider"></a>Armazenando cadeias de caracteres no provedor de banco de dados OLE
Em myproviderrs. H, o OLE DB Provider assistente ATL cria um registro de usuário padrão chamado `CWindowsFile`. Para lidar com as duas cadeias de caracteres, modifique `CWindowsFile` ou adicionar seu próprios registro de usuário, conforme mostrado no código a seguir:  
  
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
  
 Os membros de dados `szCommand` e `szText` representar as duas cadeias de caracteres com `szCommand2` e `szText2` fornecendo colunas adicionais, se necessário. O membro de dados `dwBookmark` não é necessária para este provedor somente leitura simples, mas é usado posteriormente para adicionar um `IRowsetLocate` interface, consulte [melhorando a leitura apenas provedor simples](../../data/oledb/enhancing-the-simple-read-only-provider.md). O `==` operador compara instâncias (implementar esse operador é opcional).  
  
 Quando isso for feito, o provedor deve estar pronto para compilar e executar. Para testar o provedor, você precisa de um consumidor com funcionalidade de correspondência. [Implementando um consumidor simples](../../data/oledb/implementing-a-simple-consumer.md) mostra como criar esse um consumidor de teste. Execute o consumidor de teste com o provedor. Verifique se que o consumidor de teste recupera as cadeias de caracteres corretas do provedor quando você clica o **executar** no botão o **testar consumidor** caixa de diálogo.  
  
 Quando o provedor foi testada com sucesso, você talvez queira aperfeiçoar sua funcionalidade implementando interfaces adicionais. Um exemplo é mostrado em [melhorando o provedor somente leitura simples](../../data/oledb/enhancing-the-simple-read-only-provider.md).  
  
## <a name="see-also"></a>Consulte também  
 [Implementando o provedor somente leitura simples](../../data/oledb/implementing-the-simple-read-only-provider.md)