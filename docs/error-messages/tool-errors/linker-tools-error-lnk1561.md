---
title: Ferramentas de vinculador LNK1561 erro | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- LNK1561
dev_langs:
- C++
helpviewer_keywords:
- LNK1561
ms.assetid: cb0b709b-7c9c-4496-8a4e-9e1e4aefe447
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
ms.openlocfilehash: 405cfce0a89c9c39cffb1e85e19b95fda24f7452
ms.lasthandoff: 02/25/2017

---
# <a name="linker-tools-error-lnk1561"></a>Erro das Ferramentas de Vinculador LNK1561
pontos de entrada devem ser definidos  
  
 O vinculador não encontrou um ponto de entrada. Você pode ter pretendido vincular como uma DLL, nesse caso, você deve vincular com a [/DLL](../../build/reference/dll-build-a-dll.md) opção. Você pode ter esquecido também especificar o nome do ponto de entrada; Vincular com a [/ENTRY](../../build/reference/entry-entry-point-symbol.md) opção.  
  
 Caso contrário, você deve incluir um principal, WMA, WinMain ou função wMain em seu código.  
  
 Se você estiver usando [LIB](../../build/reference/lib-reference.md) e pretende criar um arquivo. dll, um motivo para esse erro é que você forneceu um arquivo. def. Nesse caso, remova o arquivo. def da compilação.  
  
 O exemplo a seguir gera LNK1561:  
  
```  
// LNK1561.cpp  
// LNK1561 expected  
int i;  
// add a main function to resolve this error  
```
