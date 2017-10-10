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
caps.latest.revision: 8
author: corob-msft
ms.author: corob
manager: ghogen
ms.translationtype: MT
ms.sourcegitcommit: 35b46e23aeb5f4dbfd2a0dd44b906389dd5bfc88
ms.openlocfilehash: 148e3e6035304eb155a478e5971defd9a0a55120
ms.contentlocale: pt-br
ms.lasthandoff: 10/09/2017

---
# <a name="fatal-error-c1081"></a>Erro fatal C1081
'symbol': nome de arquivo muito longo  
  
 O comprimento de um caminho de arquivo excede `_MAX_PATH` (definido por STDLIB.h como 260 caracteres). Encurte o nome do arquivo.  
  
 Se você chamar CL.exe com um nome de arquivo curto, o compilador talvez seja necessário gerar um nome de caminho completo. Por exemplo, `cl -c myfile.cpp` pode fazer com que o compilador gere:  
  
```  
D:\<very-long-directory-path>\myfile.cpp  
```
