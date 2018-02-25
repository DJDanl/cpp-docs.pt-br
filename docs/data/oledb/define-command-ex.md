---
title: DEFINE_COMMAND_EX | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- DEFINE_COMMAND_EX
dev_langs:
- C++
helpviewer_keywords:
- DEFINE_COMMAND_EX macro
ms.assetid: d3e2ef20-1455-46d2-8499-8ab84bbb90a4
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
- data-storage
ms.openlocfilehash: e3fb4ce434f578ed79f3ed086adf73a6a49da870
ms.sourcegitcommit: d51ed21ab2b434535f5c1d553b22e432073e1478
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/23/2018
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