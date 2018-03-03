---
title: "Compilador (nível 4) de aviso C4571 | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C4571
dev_langs:
- C++
helpviewer_keywords:
- C4571
ms.assetid: 07aa17bd-b15c-4266-824c-57cc445e8edd
caps.latest.revision: 
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: cab2068b6117f092dcc098591bb620156b2c0cf6
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="compiler-warning-level-4-c4571"></a>Compilador C4571 de aviso (nível 4)
Informativo: semântica catch(...) alterada desde o Visual C++ 7.1; exceções estruturadas (SEH) não são mais capturadas  
  
 C4571 é gerado para cada bloco catch(...) ao compilar com **/EHs**.  
  
 Ao compilar com **/EHs**, um bloco de catch(...) não irá capturar uma exceção estruturada (divisão por zero, um ponteiro nulo, por exemplo); um catch(...) bloco será apenas catch gerada explicitamente, as exceções do C++.  Para saber mais, veja [Tratamento de exceção](../../cpp/exception-handling-in-visual-cpp.md).  
  
 Esse aviso é desativada por padrão.  Ativar este aviso para garantir que, quando você compilar com **/EHs** seus blocos catch (...) não pretende capturar exceções estruturadas.  Consulte [compilador avisos que está desativado por padrão](../../preprocessor/compiler-warnings-that-are-off-by-default.md) para obter mais informações.  
  
 Você pode resolver C4571 em uma das seguintes maneiras  
  
-   Compilar com **/EHa** se você ainda deseja seus blocos catch(...) para capturar exceções estruturadas.  
  
-   Não habilite C4571 se você não quiser que seus blocos catch(...) para capturar exceções estruturadas, mas você ainda queira usar catch(...) blocos.  Você ainda pode capturar usando o palavras-chave de tratamento de exceções estruturado de exceções estruturadas (**Try**, **EXCEPT**, e **Finally**).  Mas lembre-se, quando compilado **/EHs** destruidores só serão chamados quando uma exceção de C++ é gerada, não quando ocorre uma exceção SEH.  
  
-   Substituir catch(...) bloco com blocos catch para exceções específicas do C++ e, opcionalmente, adicione manipulação em torno de tratamento de exceções de C++ de exceção estruturada (**Try**, **EXCEPT**, e **_ _finally**).  Consulte [manipulação de exceções estruturado (C/C++)](../../cpp/structured-exception-handling-c-cpp.md) para obter mais informações.  
  
 Consulte [/EH (modelo de tratamento de exceção)](../../build/reference/eh-exception-handling-model.md) para obter mais informações.  
  
## <a name="example"></a>Exemplo  
 O exemplo a seguir gera C4571.  
  
```  
// C4571.cpp  
// compile with: /EHs /W4 /c  
#pragma warning(default : 4571)  
int main() {  
   try {  
      int i = 0, j = 1;  
      j /= i;   // this will throw a SE (divide by zero)  
   }  
   catch(...) {}   // C4571 warning  
}  
```