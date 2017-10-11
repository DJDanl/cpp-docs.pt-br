---
title: _except_handler3 | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-standard-libraries
ms.tgt_pltfrm: 
ms.topic: article
apiname:
- _except_handler3
apilocation:
- msvcrt.dll
- msvcr90.dll
- msvcr80.dll
- msvcr110_clr0400.dll
- msvcr120.dll
- msvcr100.dll
- msvcr110.dll
apitype: DLLExport
f1_keywords:
- _except_handler3
- except_handler3
dev_langs:
- C++
helpviewer_keywords:
- _except_handler3 function
- except_handler3 function
ms.assetid: b0c64898-0ae5-48b7-9724-80135a0813e2
caps.latest.revision: 7
author: corob-msft
ms.author: corob
manager: ghogen
ms.translationtype: HT
ms.sourcegitcommit: 16d1bf59dfd4b3ef5f037aed9c0f6febfdf1a2e8
ms.openlocfilehash: dbbde719028df2d7b535548f4343b88e2c90efbd
ms.contentlocale: pt-br
ms.lasthandoff: 10/09/2017

---
# <a name="excepthandler3"></a>_except_handler3
Função CRT interna. Usada por uma estrutura para encontrar o manipulador de exceção apropriado para processar a exceção atual.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
int _except_handler3(  
   PEXCEPTION_RECORD exception_record,  
   PEXCEPTION_REGISTRATION registration,  
   PCONTEXT context,  
   PEXCEPTION_REGISTRATION dispatcher  
);  
```  
  
#### <a name="parameters"></a>Parâmetros  
 [in] `exception_record`  
 Informações sobre a exceção específica.  
  
 [in] `registration`  
 O registro que indica qual tabela de escopo deve ser usada para encontrar o manipulador de exceção.  
  
 [in] `context`  
 Reservado.  
  
 [in] `dispatcher`  
 Reservado.  
  
## <a name="return-value"></a>Valor de retorno  
 Caso uma exceção deva ser desconsiderada, retorna `DISPOSITION_DISMISS`. Caso a exceção deva ser passada um nível acima para os manipuladores de exceção de encapsulamento, retorna `DISPOSITION_CONTINUE_SEARCH`.  
  
## <a name="remarks"></a>Comentários  
 Caso encontre um manipulador de exceção apropriado, o método passa a exceção para o manipulador. Nessa situação, esse método não retorna ao código que o chamou e o valor retornado é irrelevante.  
  
## <a name="see-also"></a>Consulte também  
 [Referência da Função Alfabética](../c-runtime-library/reference/crt-alphabetical-function-reference.md)
