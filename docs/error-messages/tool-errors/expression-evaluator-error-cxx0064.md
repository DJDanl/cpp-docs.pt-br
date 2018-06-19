---
title: CXX0064 de erro do avaliador de expressão | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- CXX0064
dev_langs:
- C++
helpviewer_keywords:
- CAN0064
- CXX0064
ms.assetid: aa509e71-0616-41ca-a94e-6c376b041e57
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 7964eac628fa89695d1757cff8b7b329fd7fe713
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33302130"
---
# <a name="expression-evaluator-error-cxx0064"></a>Erro CXX0064 (avaliador de expressão)
não é possível definir o ponto de interrupção na função de membro virtual associada  
  
 Um ponto de interrupção foi definido em uma função de membro virtual por meio de um ponteiro para um objeto, como:  
  
```  
pClass->vfunc( int );  
```  
  
 Um ponto de interrupção pode ser definido em uma função virtual inserindo a classe, como:  
  
```  
Class::vfunc( int );  
```  
  
 Esse erro é idêntico ao CAN0064.