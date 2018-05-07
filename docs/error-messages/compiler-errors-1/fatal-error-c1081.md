---
title: Erro fatal C1081 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C1081
dev_langs:
- C++
helpviewer_keywords:
- C1081
ms.assetid: e58adf17-cbe1-4955-a5c7-80622bbba249
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 4b5ea18ff3f2714d9621d4372cf541be2f9b225a
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="fatal-error-c1081"></a>Erro fatal C1081
'symbol': nome de arquivo muito longo  
  
 O comprimento de um caminho de arquivo excede `_MAX_PATH` (definido por STDLIB.h como 260 caracteres). Encurte o nome do arquivo.  
  
 Se você chamar CL.exe com um nome de arquivo curto, o compilador talvez seja necessário gerar um nome de caminho completo. Por exemplo, `cl -c myfile.cpp` pode fazer com que o compilador gere:  
  
```  
D:\<very-long-directory-path>\myfile.cpp  
```