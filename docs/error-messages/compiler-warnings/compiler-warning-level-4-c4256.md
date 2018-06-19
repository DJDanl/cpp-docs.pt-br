---
title: Compilador (nível 4) de aviso C4256 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C4256
dev_langs:
- C++
helpviewer_keywords:
- C4256
ms.assetid: a755a32e-895a-4837-a2b5-4ea06b736798
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: ed1a40f0da75460c4306f69da0f26eb0888bef66
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33297216"
---
# <a name="compiler-warning-level-4-c4256"></a>Compilador C4256 de aviso (nível 4)
'function': construtor de classe com bases virtual possui '...'; chamadas podem não ser compatíveis com versões anteriores do Visual C++  
  
 Possível incompatibilidade.  
  
 Considere o exemplo de código a seguir. Se a definição do construtor S2::S2 (int i,...) foi compilado, usando uma versão do compilador Visual C++ antes da versão 7, mas o exemplo a seguir é compilado usando a versão atual, a chamada para o construtor para S3 não funcionará corretamente porque alteração de convenção de chamada de uma caso especial. Se ambos foram compiladas usando o Visual C++ 6.0, a chamada não funcionaria bem à direita, a menos que não há parâmetros foram passados para o botão de reticências.  
  
 Para corrigir este aviso  
  
1.  Não use o botão de reticências em um construtor.  
  
2.  Certifique-se de que todos os componentes em seu projeto são criados com a versão atual (incluindo todas as bibliotecas que podem definir ou fazer referência a essa classe) e desativar o aviso usando o [aviso](../../preprocessor/warning.md) pragma.  
  
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