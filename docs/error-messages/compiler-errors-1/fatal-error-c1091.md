---
title: Erro fatal C1091 | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-csharp
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- C1091
dev_langs:
- C++
helpviewer_keywords:
- C1091
ms.assetid: 812d4201-9154-48b0-b9af-5959c082ca33
caps.latest.revision: 8
author: corob-msft
ms.author: corob
manager: ghogen
translation.priority.ht:
- de-de
- es-es
- fr-fr
- it-it
- ja-jp
- ko-kr
- ru-ru
- zh-cn
- zh-tw
translation.priority.mt:
- cs-cz
- pl-pl
- pt-br
- tr-tr
translationtype: Machine Translation
ms.sourcegitcommit: 3168772cbb7e8127523bc2fc2da5cc9b4f59beb8
ms.openlocfilehash: 223b1528e1806a2e3297ca6bc5c0632d362d06c5
ms.lasthandoff: 02/25/2017

---
# <a name="fatal-error-c1091"></a>Erro fatal C1091
limite do compilador: cadeia de caracteres excede 'comprimento' bytes de comprimento  
  
 Uma constante de cadeia de caracteres excedeu o limite atual no comprimento de cadeias de caracteres.  
  
 Você talvez queira dividir a cadeia de caracteres estática em duas (ou mais) variáveis e usar [strcpy_s](../../c-runtime-library/reference/strcpy-s-wcscpy-s-mbscpy-s.md) para unir o resultado como parte da declaração ou durante o tempo de execução.
