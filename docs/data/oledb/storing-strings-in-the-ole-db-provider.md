---
title: "Armazenando cadeias de caracteres no provedor de banco de dados OLE | Microsoft Docs"
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
  - "registros de usuário, edição"
ms.assetid: 36cb9635-067c-4cad-8f85-962f28026f6a
caps.latest.revision: 7
caps.handback.revision: 7
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Armazenando cadeias de caracteres no provedor de banco de dados OLE
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Em MyProviderRS.h, o assistente do provedor OLE DB de ATL cria um registro de usuário padrão chamado `CWindowsFile`.  Para tratar as duas cadeias de caracteres, para alterar `CWindowsFile` ou adicionar seu próprio registro de usuário conforme mostrado no seguinte código:  
  
```  
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
  
 Os membros de dados `szCommand` e `szText` representam as duas cadeias de caracteres, com `szCommand2` e `szText2` que fornecem colunas adicionais se necessário.  O membro de dados `dwBookmark` não é necessário para esse provedor somente leitura simples mas é usado posteriormente para adicionar uma interface de `IRowsetLocate` ; consulte [Aprimorando o provedor somente leitura simples](../../data/oledb/enhancing-the-simple-read-only-provider.md).  O operador de `==` compara instâncias \(implementar esse operador é opcional\).  
  
 Quando isso for feito, o provedor deve estar pronto para compilar e executar.  Para testar o provedor, é necessário um consumidor com funcionalidade correspondente.  [Implementando um consumidor simples](../../data/oledb/implementing-a-simple-consumer.md) mostra como criar um consumidor de teste.  Execute o consumidor de teste com o provedor.  Verifique se o consumidor de teste recupera as cadeias de caracteres adequadas do provedor quando você clica no botão de **Executar** na caixa de diálogo de **Test Consumer** .  
  
 Quando você testar com êxito o provedor, talvez você queira aumentar sua funcionalidade implementando interfaces adicionais.  Um exemplo é mostrado em [Aprimorando o provedor somente leitura simples](../../data/oledb/enhancing-the-simple-read-only-provider.md).  
  
## Consulte também  
 [Implementando o provedor somente leitura simples](../../data/oledb/implementing-the-simple-read-only-provider.md)