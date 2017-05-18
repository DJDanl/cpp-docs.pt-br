---
title: "Compilador aviso (nível 1) C4788 | Documentos do Microsoft"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C4788
dev_langs:
- C++
helpviewer_keywords:
- C4788
ms.assetid: 47d75bda-f833-4bdd-93a0-a134df0cd303
caps.latest.revision: 9
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
ms.translationtype: Machine Translation
ms.sourcegitcommit: 3168772cbb7e8127523bc2fc2da5cc9b4f59beb8
ms.openlocfilehash: ae06ee08751afaff627d4baab59c6cab8f4ae883
ms.contentlocale: pt-br
ms.lasthandoff: 02/25/2017

---
# <a name="compiler-warning-level-1-c4788"></a>Compilador C4788 de aviso (nível 1)
'identifier': identificador foi truncado para caracteres 'number'  
  
 O compilador limita o tamanho máximo permitido para um nome de função. Quando o compilador gera funclets para código EH/SEH, formar o nome funclet acrescentando o nome da função com algum texto, por exemplo "__catch," "\__unwind", ou outra cadeia de caracteres.  
  
 O nome funclet resultante pode ser muito longo, e o compilador irá truncar e gerar C4788.  
  
 Para resolver esse aviso, encurte o nome da função original. Se a função é uma função de modelo C++ ou método, use um typedef para a parte do nome. Por exemplo:  
  
```  
C1<x, y, z<T>>::C2<a,b,c>::f  
```  
  
 pode ser substituído por:  
  
```  
typedef C1<x, y, z<T>>::C2<a,b,c> new_class ;  
new_class::f  
```  
  
 Esse aviso ocorre apenas no [!INCLUDE[vcprx64](../../assembler/inline/includes/vcprx64_md.md)] compilador.
