---
title: "CXX0064 de erro do avaliador de expressão | Documentos do Microsoft"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- CXX0064
dev_langs:
- C++
helpviewer_keywords:
- CAN0064
- CXX0064
ms.assetid: aa509e71-0616-41ca-a94e-6c376b041e57
caps.latest.revision: 6
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
ms.translationtype: Machine Translation
ms.sourcegitcommit: 3168772cbb7e8127523bc2fc2da5cc9b4f59beb8
ms.openlocfilehash: b5dbada9bbb62d5d7825784b9b55a4cd88e224c6
ms.contentlocale: pt-br
ms.lasthandoff: 02/25/2017

---
# <a name="expression-evaluator-error-cxx0064"></a>Erro CXX0064 (avaliador de expressão)
não é possível definir ponto de interrupção em função membro virtual associada  
  
 Um ponto de interrupção foi definido em uma função de membro virtual por meio de um ponteiro para um objeto, como:  
  
```  
pClass->vfunc( int );  
```  
  
 Um ponto de interrupção pode ser definido em uma função virtual inserindo a classe, como:  
  
```  
Class::vfunc( int );  
```  
  
 Esse erro é idêntico ao CAN0064.
