---
title: _CxxThrowException | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-standard-libraries
ms.tgt_pltfrm: 
ms.topic: article
apiname:
- _CxxThrowException
apilocation:
- msvcrt.dll
- msvcr80.dll
- msvcr90.dll
- msvcr100.dll
- msvcr100_clr0400.dll
- msvcr110.dll
- msvcr110_clr0400.dll
- msvcr120.dll
- msvcr120_clr0400.dll
- ucrtbase.dll
apitype: DLLExport
f1_keywords:
- CxxThrowException
- _CxxThrowException
dev_langs:
- C++
helpviewer_keywords:
- _CxxThrowException function
- CxxThrowException function
ms.assetid: 0b90bef5-b7d2-46e0-88e2-59e531e01a4d
caps.latest.revision: 8
author: corob-msft
ms.author: corob
manager: ghogen
ms.translationtype: MT
ms.sourcegitcommit: 35b46e23aeb5f4dbfd2a0dd44b906389dd5bfc88
ms.openlocfilehash: 5cfe894dc20e77bf34067c16fddd74432c522bda
ms.contentlocale: pt-br
ms.lasthandoff: 10/09/2017

---
# <a name="cxxthrowexception"></a>_CxxThrowException
Cria o registro de exceção e chama o ambiente de tempo de execução para iniciar o processamento da exceção.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
extern "C" void __stdcall _CxxThrowException(  
   void* pExceptionObject  
   _ThrowInfo* pThrowInfo  
);  
```  
  
#### <a name="parameters"></a>Parâmetros  
 [in] `pExceptionObject`  
 O objeto que gerou a exceção.  
  
 [in] `pThrowInfo`  
 As informações necessárias para processar a exceção.  
  
## <a name="remarks"></a>Comentários  
 Esse método é incluído em um arquivo somente de compilador que o compilador usa para processar exceções. Não chame o método diretamente do código.  
  
## <a name="requirements"></a>Requisitos  
 **Fonte:** Throw.cpp  
  
## <a name="see-also"></a>Consulte também  
 [Referência da Função Alfabética](../../c-runtime-library/reference/crt-alphabetical-function-reference.md)
