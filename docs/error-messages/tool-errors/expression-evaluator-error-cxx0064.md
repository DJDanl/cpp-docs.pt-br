---
title: "CXX0064 de erro do avaliador de expressão | Microsoft Docs"
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
caps.latest.revision: 
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 2edeb05e39c6d2e70cb2c9dde562a89e85921301
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
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