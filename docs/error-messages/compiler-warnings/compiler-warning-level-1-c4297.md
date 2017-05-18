---
title: "Compilador aviso (nível 1) C4297 | Documentos do Microsoft"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C4297
dev_langs:
- C++
helpviewer_keywords:
- C4297
ms.assetid: ba92fcdc-9f70-4f60-abe6-281f9582ca59
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
ms.translationtype: Machine Translation
ms.sourcegitcommit: 3168772cbb7e8127523bc2fc2da5cc9b4f59beb8
ms.openlocfilehash: c21453d185fed2c33e7cb054e77e1698fadf491b
ms.contentlocale: pt-br
ms.lasthandoff: 02/25/2017

---
# <a name="compiler-warning-level-1-c4297"></a>Compilador C4297 de aviso (nível 1)
'function': função não deve para lançar uma exceção, mas não  
  
 Uma declaração de função contém um (possivelmente implícito) `noexcept` especificador, vazio `throw` especificador de exceção, ou um [__declspec(nothrow)](../../cpp/nothrow-cpp.md) atributo e a definição contém um ou mais [lançar](../../cpp/try-throw-and-catch-statements-cpp.md) instruções. Para resolver C4297, não tente lançar exceções em funções que são declaradas `__declspec(nothrow)`, `noexcept(true)` ou `throw()`. Como alternativa, remova o `noexcept`, `throw()`, ou `__declspec(nothrow)` especificação.  
  
 Por padrão, o compilador gera implícita `noexcept(true)` especificadores para destruidores definidos pelo usuário e funções deallocator e funções de membro especial gerado pelo compilador. Isso está de acordo com o ISO C++&11; padrão. Para evitar a geração de noexcept implícita especificadores e reverter o compilador o comportamento não padrão do Visual Studio 2013, use o **/Zc:implicitNoexcept-** opção de compilador. Para obter mais informações, consulte [/Zc:implicitNoexcept (especificadores de exceção implícita)](../../build/reference/zc-implicitnoexcept-implicit-exception-specifiers.md).  
  
 Para obter mais informações sobre especificações de exceção, consulte [especificações de exceção (acionar)](../../cpp/exception-specifications-throw-cpp.md). Consulte também [/EH (modelo de tratamento de exceção)](../../build/reference/eh-exception-handling-model.md) para obter informações sobre como modificar o comportamento em tempo de compilação de manipulação de exceção.  
  
 Esse aviso também é gerado para declspec ([dllexport](../../cpp/dllexport-dllimport.md)) funções marcadas extern "C", mesmo que eles estejam funções C++.  
  
 O exemplo a seguir gera C4297:  
  
```  
// C4297.cpp  
// compile with: /W1 /LD  
void __declspec(nothrow) f1()   // declared nothrow  
// try the following line instead  
// void f1()  
{  
   throw 1;   // C4297  
}  
```
