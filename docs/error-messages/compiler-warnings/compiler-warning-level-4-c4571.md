---
title: "Compilador aviso (nível 4) C4571 | Documentos do Microsoft"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C4571
dev_langs:
- C++
helpviewer_keywords:
- C4571
ms.assetid: 07aa17bd-b15c-4266-824c-57cc445e8edd
caps.latest.revision: 12
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
ms.openlocfilehash: e75d66d16c593e480dc5b29ba22a311e626147ca
ms.lasthandoff: 02/25/2017

---
# <a name="compiler-warning-level-4-c4571"></a>Compilador C4571 de aviso (nível 4)
Informativo: semântica catch(...) mudou desde o Visual C++ 7.1; exceções estruturadas (SEH) não são mais capturadas  
  
 C4571 é gerado para cada bloco catch ao compilar com **/EHs**.  
  
 Ao compilar com **/EHs**, um bloco catch não vai capturar uma exceção estruturada (divisão por zero, um ponteiro nulo, por exemplo); um catch bloco será apenas catch geradas explicitamente, exceções do C++.  Para obter mais informações, consulte [Exception Handling](../../cpp/exception-handling-in-visual-cpp.md).  
  
 Esse aviso é desativada por padrão.  Ativar esse aviso em garantir que quando você compila com **/EHs** seus blocos catch (…) não tiver a intenção de capturar exceções estruturadas.  Consulte [compilador avisos que está desativado por padrão](../../preprocessor/compiler-warnings-that-are-off-by-default.md) para obter mais informações.  
  
 Você pode resolver C4571 de uma das maneiras a seguir,  
  
-   Compile com **/EHa** se você ainda deseja seus blocos catch para capturar exceções estruturadas.  
  
-   Não habilite C4571 se você não quiser que seus blocos catch para capturar exceções estruturadas, mas você ainda queira usar blocos catch.  Você ainda pode capturar exceções estruturadas, usando a palavras-chave de tratamento de exceção estruturada (**Try**, **EXCEPT**, e **Finally**).  Mas lembre-se, quando compilado **/EHs** destruidores só serão chamados quando uma exceção de C++ é lançada, não quando ocorre uma exceção SEH.  
  
-   Substitua o bloco catch com blocos catch para exceções específicas de C++ e, opcionalmente, adicionar tratamento em todo o tratamento de exceções C++ de exceção estruturada (**Try**, **EXCEPT**, e **Finally**).  Consulte [Structured Exception Handling (C/C++)](../../cpp/structured-exception-handling-c-cpp.md) para obter mais informações.  
  
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
