---
title: "CCommand::Create | Microsoft Docs"
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
  - "CCommand.Create"
  - "CCommand::Create"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Método Create [C++]"
ms.assetid: e4bede7a-68bd-491a-97f4-89b03d45cd24
caps.latest.revision: 9
caps.handback.revision: 9
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# CCommand::Create
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Chama [CCommand::CreateCommand](../Topic/CCommand::CreateCommand.md) para criar um comando para a sessão especificada, em seguida chama [ICommandText::SetCommandText](https://msdn.microsoft.com/en-us/library/ms709825.aspx) para especificar o texto do comando.  
  
## Sintaxe  
  
```  
  
      HRESULT CCommandBase::Create(  
   const CSession& session,   
   LPCWSTR wszCommand,   
   REFGUID guidCommand = DBGUID_DEFAULT  
) throw ( );  
HRESULT CCommandBase::Create(  
   const CSession& session,   
   LPCSTR szCommand,   
   REFGUID guidCommand = DBGUID_DEFAULT  
) throw ( );  
```  
  
#### Parâmetros  
 `session`  
 \[in\] da sessão no qual criar o comando.  
  
 `wszCommand`  
 \[in\] ao ponteiro de texto Unicode de cadeia de caracteres de comando.  
  
 `szCommand`  
 \[in\] ao ponteiro de texto ANSI de cadeia de caracteres de comando.  
  
 `guidCommand`  
 \[in\] GUID que especifica a sintaxe e as regras gerais para que o provedor usa em analisar o texto do comando.  Para obter uma descrição dos dialetos, consulte [ICommandText::GetCommandText](https://msdn.microsoft.com/en-us/library/ms709825.aspx)*na referência do programador de OLE DB*.  
  
## Valor de retorno  
 `HRESULT`padrão.  
  
## Comentários  
 O primeiro formulário de **Criar** usa uma cadeia de caracteres de comando Unicode.  O segundo formulário de **Criar** usa uma cadeia de caracteres de comando ANSI \(fornecida para compatibilidade com versões anteriores com os aplicativos existentes de ANSI\).  
  
## Requisitos  
 **Header:** atldbcli.h  
  
## Consulte também  
 [Classe CCommand](../../data/oledb/ccommand-class.md)