---
title: Erro fatal C1081 | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
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
translation.priority.ht:
- cs-cz
- de-de
- es-es
- fr-fr
- it-it
- ja-jp
- ko-kr
- pl-pl
- pt-br
- ru-ru
- tr-tr
- zh-cn
- zh-tw
translationtype: Machine Translation
ms.sourcegitcommit: 3168772cbb7e8127523bc2fc2da5cc9b4f59beb8
ms.openlocfilehash: 39c3a48e3fa01eb9bf2f357df73ef0bb466d1b10
ms.lasthandoff: 02/25/2017

---
# <a name="fatal-error-c1081"></a>Erro fatal C1081
'symbol': nome de arquivo muito longo  
  
 O comprimento de um caminho de arquivo excede `_MAX_PATH` (definido por stdlib. h como 260 caracteres). Diminua o nome do arquivo.  
  
 Se você chamar CL.exe com um nome de arquivo curto, o compilador talvez seja necessário gerar um nome de caminho completo. Por exemplo, `cl -c myfile.cpp` pode fazer com que o compilador gere:  
  
```  
D:\<very-long-directory-path>\myfile.cpp  
```
