---
title: DEFINE_COMMAND | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-data
ms.topic: reference
f1_keywords:
- DEFINE_COMMAND
dev_langs:
- C++
helpviewer_keywords:
- DEFINE_COMMAND macro
ms.assetid: 9d724968-e242-413c-9a13-e7175fccf9b1
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- data-storage
ms.openlocfilehash: 51f975b0477d29fbb35880c796f52612456c32c8
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="definecommand"></a>DEFINE_COMMAND
Especifica o comando que será usado para criar o conjunto de linhas ao usar o [CCommand](../../data/oledb/ccommand-class.md) classe. Aceita somente os tipos de cadeia de caracteres correspondente ao tipo de aplicativo especificado (ANSI ou Unicode).  
  
> [!NOTE]
>  É recomendável que você use [DEFINE_COMMAND_EX](../../data/oledb/define-command-ex.md) em vez de `DEFINE_COMMAND`.  
  
## <a name="syntax"></a>Sintaxe  
  
```cpp
DEFINE_COMMAND(x, szCommand)  
  
```  
  
#### <a name="parameters"></a>Parâmetros  
 *x*  
 [in] O nome da classe de registro (comando) de usuário.  
  
 `szCommand`  
 [in] A cadeia de caracteres de comando que será usada para criar o conjunto de linhas ao usar [CCommand](../../data/oledb/ccommand-class.md).  
  
## <a name="remarks"></a>Comentários  
 A cadeia de caracteres de comando que você especificar será usada como o padrão se você não especificar o texto do comando no [ccommand:: Open](../../data/oledb/ccommand-open.md) método.  
  
 Esta macro aceita cadeias de caracteres ANSI se você criar seu aplicativo como ANSI ou cadeias de caracteres Unicode, se você criar seu aplicativo como Unicode. É recomendável que você use [DEFINE_COMMAND_EX](../../data/oledb/define-command-ex.md) em vez de `DEFINE_COMMAND`, como o primeiro aceita cadeias de caracteres Unicode, independentemente do tipo de aplicativo ANSI ou Unicode.  
  
## <a name="example"></a>Exemplo  
 Consulte [BOOKMARK_ENTRY](../../data/oledb/bookmark-entry.md).  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atldbcli.h  
  
## <a name="see-also"></a>Consulte também  
 [Macros e funções globais para modelos de consumidor do OLE DB](../../data/oledb/macros-and-global-functions-for-ole-db-consumer-templates.md)