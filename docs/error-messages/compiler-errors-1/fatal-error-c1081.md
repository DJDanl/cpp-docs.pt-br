---
title: Erro fatal C1081 | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C1081
dev_langs:
- C++
helpviewer_keywords:
- C1081
ms.assetid: e58adf17-cbe1-4955-a5c7-80622bbba249
caps.latest.revision: 
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 8bac4aaf0d4aebcbc34f74b6ccb91170fd4224e4
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="fatal-error-c1081"></a>Erro fatal C1081
'symbol': nome de arquivo muito longo  
  
 O comprimento de um caminho de arquivo excede `_MAX_PATH` (definido por STDLIB.h como 260 caracteres). Encurte o nome do arquivo.  
  
 Se você chamar CL.exe com um nome de arquivo curto, o compilador talvez seja necessário gerar um nome de caminho completo. Por exemplo, `cl -c myfile.cpp` pode fazer com que o compilador gere:  
  
```  
D:\<very-long-directory-path>\myfile.cpp  
```