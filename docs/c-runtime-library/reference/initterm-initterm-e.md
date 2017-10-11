---
title: _initterm, _initterm_e | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-standard-libraries
ms.tgt_pltfrm: 
ms.topic: article
apiname:
- _initterm_e
- _initterm
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
- api-ms-win-crt-runtime-l1-1-0.dll
apitype: DLLExport
f1_keywords:
- _initterm_e
- initterm
- _initterm
- initterm_e
dev_langs:
- C++
helpviewer_keywords:
- initterm function
- initterm_e function
- _initterm function
- _initterm_e function
ms.assetid: 85131efe-c747-429a-8897-bcdedb000172
caps.latest.revision: 7
author: corob-msft
ms.author: corob
manager: ghogen
ms.translationtype: MT
ms.sourcegitcommit: 35b46e23aeb5f4dbfd2a0dd44b906389dd5bfc88
ms.openlocfilehash: 377f8e19268a643b0237da66ba14a82fc7b6685b
ms.contentlocale: pt-br
ms.lasthandoff: 10/09/2017

---
# <a name="initterm-initterme"></a>_initterm, _initterm_e
Métodos internos que percorrem uma tabela de ponteiros de função e os inicializam.  
  
 O primeiro ponteiro é o local de início da tabela e o segundo ponteiro é o local de término.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
void __cdecl _initterm(  
   PVFV *,  
   PVFV *  
);  
  
int __cdecl _initterm_e(  
   PVFV *,  
   PVFV *  
);  
```  
  
## <a name="return-value"></a>Valor de retorno  
 Um código de erro diferente de zero se uma inicialização falhar e gerar um erro; 0 se nenhum erro ocorrer.  
  
## <a name="remarks"></a>Comentários  
 Esses métodos são chamados internamente apenas durante a inicialização de um programa C++. Não chame esses métodos em um programa.  
  
 Quando percorrem uma tabela de entradas de função, os métodos ignoram entradas `NULL` e continuam.  
  
## <a name="see-also"></a>Consulte também  
 [Referência da Função Alfabética](../../c-runtime-library/reference/crt-alphabetical-function-reference.md)
