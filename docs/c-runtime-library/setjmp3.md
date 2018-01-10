---
title: _setjmp3 | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-standard-libraries
ms.tgt_pltfrm: 
ms.topic: article
apiname: _setjmp3
apilocation:
- msvcrt.dll
- msvcr90.dll
- msvcr110.dll
- msvcr80.dll
- msvcr110_clr0400.dll
- msvcr100.dll
- msvcr120.dll
apitype: DLLExport
f1_keywords:
- setjmp3
- _setjmp3
dev_langs: C++
helpviewer_keywords:
- _setjmp3 function
- setjmp3 function
ms.assetid: 6129c2f3-8bac-4fdb-a827-44e1eebba500
caps.latest.revision: "6"
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 72bc1e833ddaa72979e25274b7328d8987f62763
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="setjmp3"></a>_setjmp3
Função CRT interna. Uma nova implementação da função `setjmp`.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
int _setjmp3(  
   OUT jmp_buf env,  
   int count,  
   (optional parameters)  
);  
```  
  
#### <a name="parameters"></a>Parâmetros  
 [out] `env`  
 Endereço do buffer para armazenar informações de estado.  
  
 [in] `count`  
 O número de informações `DWORD` adicionais armazenadas no `optional parameters`.  
  
 [in] `optional parameters`  
 Dados adicionais enviados pelo `setjmp` intrínseco. O primeiro `DWORD` é um ponteiro de função usado para desenrolar dados extras e retornar para um estado de registro não volátil. O segundo `DWORD` é o nível de tentativa a ser restaurado. Todos os demais dados são salvos na matriz de dados genérica no `jmp_buf`.  
  
## <a name="return-value"></a>Valor retornado  
 Sempre retorna 0.  
  
## <a name="remarks"></a>Comentários  
 Não use essa função em um programa C++. É uma função intrínseca que não tem suporte para C++. Para obter mais informações sobre como usar o `setjmp`, consulte [Usando setjmp/longjmp](../cpp/using-setjmp-longjmp.md).  
  
## <a name="requirements"></a>Requisitos  
  
## <a name="see-also"></a>Consulte também  
 [Alphabetical Function Reference](../c-runtime-library/reference/crt-alphabetical-function-reference.md)  (Referência da função alfabética)  
 [setjmp](../c-runtime-library/reference/setjmp.md)