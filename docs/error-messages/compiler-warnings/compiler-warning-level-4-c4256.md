---
title: "Compilador aviso (nível 4) C4256 | Documentos do Microsoft"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C4256
dev_langs:
- C++
helpviewer_keywords:
- C4256
ms.assetid: a755a32e-895a-4837-a2b5-4ea06b736798
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
ms.openlocfilehash: 21f924cae78f7400de0b141ee20a4422feb003b7
ms.lasthandoff: 02/25/2017

---
# <a name="compiler-warning-level-4-c4256"></a>Compilador C4256 de aviso (nível 4)
'function': construtor de classe com bases virtuais tem '...'; chamadas podem não ser compatíveis com versões anteriores do Visual C++  
  
 Possível incompatibilidade.  
  
 Considere o exemplo de código a seguir. Se a definição do construtor S2::S2 (int i,...) foi compilado usando uma versão do compilador do Visual C++ antes da versão 7, mas o exemplo a seguir é compilado usando a versão atual, a chamada para o construtor para S3 não funcionará corretamente devido a uma alteração de convenção de chamada de casos especiais. Se ambos foram compiladas usando o Visual C++ 6.0, a chamada não funcionaria muito bem, a menos que não há parâmetros foram passados para o botão de reticências.  
  
 Para corrigir esse aviso  
  
1.  Não use o botão de reticências em um construtor.  
  
2.  Certifique-se de que todos os componentes em seu projeto são compilados com a versão atual (incluindo todas as bibliotecas que podem definir ou fazer referência a essa classe) então desativar o aviso usando o [aviso](../../preprocessor/warning.md) pragma.  
  
 O exemplo a seguir gera C4256:  
  
```  
// C4256.cpp  
// compile with: /W4  
// #pragma warning(disable : 4256)  
struct S1  
{  
};  
  
struct S2: virtual public S1  
{  
   S2( int i, ... )    // C4256  
   {  
      i = 0;  
   }  
   /*  
   // try the following line instead  
   S2( int i)  
   {  
      i = 0;  
   }  
   */  
};  
  
void func1()  
{  
   S2 S3( 2, 1, 2 );   // C4256  
   // try the following line instead  
   // S2 S3( 2 );  
}  
  
int main()  
{  
}  
```
