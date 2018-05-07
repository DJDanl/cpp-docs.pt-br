---
title: DEFINE_COMMAND_EX | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-data
ms.topic: reference
f1_keywords:
- DEFINE_COMMAND_EX
dev_langs:
- C++
helpviewer_keywords:
- DEFINE_COMMAND_EX macro
ms.assetid: d3e2ef20-1455-46d2-8499-8ab84bbb90a4
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- data-storage
ms.openlocfilehash: b2a77fa0d6655edeee88df3c7c45e1936a766b40
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="definecommandex"></a>DEFINE_COMMAND_EX
Especifica o comando que será usado para criar o conjunto de linhas ao usar o [CCommand](../../data/oledb/ccommand-class.md) classe. Oferece suporte a aplicativos ANSI e Unicode.  
  
## <a name="syntax"></a>Sintaxe  
  
```cpp
DEFINE_COMMAND_EX(x, wszCommand)  
  
```  
  
#### <a name="parameters"></a>Parâmetros  
 *x*  
 [in] O nome da classe de registro (comando) de usuário.  
  
 `wszCommand`  
 [in] A cadeia de caracteres de comando que será usada para criar o conjunto de linhas ao usar [CCommand](../../data/oledb/ccommand-class.md).  
  
## <a name="remarks"></a>Comentários  
 A cadeia de caracteres de comando que você especificar será usada como o padrão se você não especificar o texto do comando no [ccommand:: Open](../../data/oledb/ccommand-open.md) método.  
  
 Esta macro aceita cadeias de caracteres Unicode, independentemente do tipo de aplicativo. Essa macro é preferencial em [DEFINE_COMMAND](../../data/oledb/define-command.md) porque ele oferece suporte a Unicode, bem como aplicativos ANSI.  
  
## <a name="example"></a>Exemplo  
 Consulte [BOOKMARK_ENTRY](../../data/oledb/bookmark-entry.md).  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atldbcli.h  
  
## <a name="see-also"></a>Consulte também  
 [Macros e funções globais para modelos de consumidor do OLE DB](../../data/oledb/macros-and-global-functions-for-ole-db-consumer-templates.md)