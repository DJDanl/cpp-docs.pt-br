---
title: C3166 de erro do compilador | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C3166
dev_langs:
- C++
helpviewer_keywords:
- C3166
ms.assetid: ec3e330d-c15d-4158-8268-09101486c566
caps.latest.revision: 11
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
ms.sourcegitcommit: c243063a9770542f137d5950e8a269f771960f74
ms.openlocfilehash: 13ff799b21825c24ae98cfd416e7e2021b6bd2bb
ms.lasthandoff: 02/25/2017

---
# <a name="compiler-error-c3166"></a>C3166 de erro do compilador
'ponteiro': não é possível declarar um ponteiro para um ponteiro de GC interiores como um membro de 'type'  
  
O compilador encontrado uma declaração de ponteiro inválido (um `__nogc` ponteiro para um `__gc` ponteiro.). 
  
C3166 só está acessível usando a opção de compilador obsoleto **/CLR: oldSyntax**.  

