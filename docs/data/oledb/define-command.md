---
title: DEFINE_COMMAND | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords: DEFINE_COMMAND
dev_langs: C++
helpviewer_keywords: DEFINE_COMMAND macro
ms.assetid: 9d724968-e242-413c-9a13-e7175fccf9b1
caps.latest.revision: "7"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
- data-storage
ms.openlocfilehash: cd2acfee6bb0f28acc774774e446e9efd4a5637b
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="definecommand"></a>DEFINE_COMMAND
Especifica o comando que será usado para criar o conjunto de linhas ao usar o [CCommand](../../data/oledb/ccommand-class.md) classe. Aceita somente os tipos de cadeia de caracteres correspondente ao tipo de aplicativo especificado (ANSI ou Unicode).  
  
> [!NOTE]
>  É recomendável que você use [DEFINE_COMMAND_EX](../../data/oledb/define-command-ex.md) em vez de `DEFINE_COMMAND`.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
  
DEFINE_COMMAND(  
x  
,   
szCommand  
 )  
  
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