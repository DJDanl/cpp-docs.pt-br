---
title: _amsg_exit | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-standard-libraries
ms.tgt_pltfrm: 
ms.topic: reference
apiname:
- _amsg_exit
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
- _amsg_exit
dev_langs:
- C++
helpviewer_keywords:
- _amsg_exit
ms.assetid: 146d4faf-d763-43a4-b264-12711196456b
caps.latest.revision: 
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 5b9029cbcfaa3853638a5b46e2c3ee1cb56622cb
ms.sourcegitcommit: 6002df0ac79bde5d5cab7bbeb9d8e0ef9920da4a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/14/2018
---
# <a name="amsgexit"></a>_amsg_exit
Emite uma mensagem de erro de tempo de execução especificada e, em seguida, sai do seu aplicativo com o código de erro 255.  
  
## <a name="syntax"></a>Sintaxe  
  
```cpp  
void _amsg_exit (  
   int rterrnum  
   )  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `rterrnum`  
 O número de identificação de uma mensagem de erro de tempo de execução definida pelo sistema.  
  
## <a name="remarks"></a>Comentários  
 Essa função emite a mensagem de erro de tempo de execução para **stderr** para aplicativos de console ou exibe a mensagem em uma caixa de mensagem para aplicativos do Windows. No modo de depuração, você pode optar por invocar o depurador antes de sair.  
  
## <a name="requirements"></a>Requisitos  
  
|Rotina|Cabeçalho necessário|  
|-------------|---------------------|  
|_amsg_exit|internal.h|