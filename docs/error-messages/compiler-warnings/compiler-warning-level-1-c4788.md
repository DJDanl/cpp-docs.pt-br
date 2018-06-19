---
title: Compilador (nível 1) de aviso C4788 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C4788
dev_langs:
- C++
helpviewer_keywords:
- C4788
ms.assetid: 47d75bda-f833-4bdd-93a0-a134df0cd303
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 19a43fb9d79c63637b2bff9a27661a9f848ef6dc
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33284193"
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