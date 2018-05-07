---
title: 'Ccommand:: Create | Microsoft Docs'
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-data
ms.topic: reference
f1_keywords:
- CCommand.Create
- CCommand::Create
dev_langs:
- C++
helpviewer_keywords:
- Create method [C++]
ms.assetid: e4bede7a-68bd-491a-97f4-89b03d45cd24
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- data-storage
ms.openlocfilehash: f85cfd9ed9938d76c28449fae01a87d3bb81a293
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="ccommandcreate"></a>CCommand::Create
Chamadas [ccommand:: CreateCommand](../../data/oledb/ccommand-createcommand.md) para criar um comando para a sessão especificada, em seguida, chama [ICommandText:: SetCommandText](https://msdn.microsoft.com/en-us/library/ms709825.aspx) para especificar o texto do comando.  
  
## <a name="syntax"></a>Sintaxe  
  
```cpp
HRESULT CCommandBase::Create(const CSession& session,   
   LPCWSTR wszCommand,   
   REFGUID guidCommand = DBGUID_DEFAULT) throw ();  


HRESULT CCommandBase::Create(const CSession& session,   
   LPCSTR szCommand,   
   REFGUID guidCommand = DBGUID_DEFAULT) throw ();  
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