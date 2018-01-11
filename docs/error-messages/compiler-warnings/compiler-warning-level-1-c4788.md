---
title: "Compilador (nível 1) de aviso C4788 | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords: C4788
dev_langs: C++
helpviewer_keywords: C4788
ms.assetid: 47d75bda-f833-4bdd-93a0-a134df0cd303
caps.latest.revision: "9"
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: e6f876dada851f46b7708ef1b34da4bae6f96dc0
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="compiler-warning-level-1-c4788"></a>Compilador C4788 de aviso (nível 1)
'Identificador': identificador foi truncado para 'número' caracteres  
  
 O compilador limita o tamanho máximo permitido para um nome de função. Quando o compilador gera funclets código EH/SEH, constitui o nome funclet acrescentando o nome da função com algum texto, por exemplo "__catch," "\__unwind", ou outra cadeia de caracteres.  
  
 O nome de funclet resultante pode ser muito longo, e o compilador irá truncar e gerar C4788.  
  
 Para resolver este aviso, diminua o nome da função original. Se a função é um método ou função de modelo do C++, use um typedef para a parte do nome. Por exemplo:  
  
```  
C1<x, y, z<T>>::C2<a,b,c>::f  
```  
  
 pode ser substituído por:  
  
```  
typedef C1<x, y, z<T>>::C2<a,b,c> new_class ;  
new_class::f  
```  
  
 Este aviso ocorre apenas no [!INCLUDE[vcprx64](../../assembler/inline/includes/vcprx64_md.md)] compilador.