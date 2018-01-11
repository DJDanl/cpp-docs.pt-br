---
title: 'Ccommand:: Create | Microsoft Docs'
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- CCommand.Create
- CCommand::Create
dev_langs: C++
helpviewer_keywords: Create method [C++]
ms.assetid: e4bede7a-68bd-491a-97f4-89b03d45cd24
caps.latest.revision: "9"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
- data-storage
ms.openlocfilehash: f4bbd236c2ec7ae6857ede1ac64f738ca8600774
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="ccommandcreate"></a>CCommand::Create
Chamadas [ccommand:: CreateCommand](../../data/oledb/ccommand-createcommand.md) para criar um comando para a sessão especificada, em seguida, chama [ICommandText:: SetCommandText](https://msdn.microsoft.com/en-us/library/ms709825.aspx) para especificar o texto do comando.  
  
## <a name="syntax"></a>Sintaxe  
  
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
  
#### <a name="parameters"></a>Parâmetros  
 `session`  
 [in] Uma sessão na qual criar o comando.  
  
 `wszCommand`  
 [in] Um ponteiro para o texto Unicode da cadeia de caracteres de comando.  
  
 `szCommand`  
 [in] Um ponteiro para o texto ANSI da cadeia de caracteres de comando.  
  
 `guidCommand`  
 [in] Um GUID que especifica a sintaxe e regras gerais para o provedor a ser usado na análise do texto de comando. Para obter uma descrição de dialetos, consulte [ICommandText::GetCommandText](https://msdn.microsoft.com/en-us/library/ms709825.aspx) no *referência do programador de DB OLE*.  
  
## <a name="return-value"></a>Valor de retorno  
 Um padrão `HRESULT`.  
  
## <a name="remarks"></a>Comentários  
 O primeiro formulário da **criar** usa uma cadeia de caracteres de comando Unicode. A segunda forma de **criar** usa uma cadeia de caracteres de comando ANSI (fornecida para compatibilidade com aplicativos existentes de ANSI).  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atldbcli.h  
  
## <a name="see-also"></a>Consulte também  
 [Classe CCommand](../../data/oledb/ccommand-class.md)