---
title: "Compilador aviso (nível 4) C4207 | Documentos do Microsoft"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C4207
dev_langs:
- C++
helpviewer_keywords:
- C4207
ms.assetid: f4e09e3e-ac87-4489-8e3f-c8f76b82e721
caps.latest.revision: 7
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
ms.openlocfilehash: 4c415ea29879527dfeedd20db22b13610095a73b
ms.lasthandoff: 02/25/2017

---
# <a name="compiler-warning-level-4-c4207"></a>Compilador C4207 de aviso (nível 4)
extensão não padrão usada : forma de inicializador estendido  
  
 Com as extensões da Microsoft (/Ze), você pode inicializar uma matriz sem tamanho de `char` usando uma cadeia de caracteres entre chaves.  
  
## <a name="example"></a>Exemplo  
  
```  
// C4207.c  
// compile with: /W4  
char c[] = { 'a', 'b', "cdefg" }; // C4207  
  
int main()  
{  
}  
```  
  
 Inicializações são inválidas em compatibilidade com ANSI ([/Za](../../build/reference/za-ze-disable-language-extensions.md)).
