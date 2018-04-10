---
title: Compilador (nível 1) de aviso C4297 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.reviewer: ''
ms.suite: ''
ms.technology:
- cpp-tools
ms.tgt_pltfrm: ''
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
ms.workload:
- cplusplus
ms.openlocfilehash: 9253ae709109927e69940d5023b542dfb543c6de
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="compiler-warning-level-1-c4297"></a>Compilador C4297 de aviso (nível 1)
'function': função não deveria para lançar uma exceção, mas não  
  
 Uma declaração de função contém um (possivelmente implícita) `noexcept` especificador, vazio `throw` especificador de exceção, ou um [nothrow](../../cpp/nothrow-cpp.md) atributo e a definição contém um ou mais [throw ](../../cpp/try-throw-and-catch-statements-cpp.md) instruções. Para resolver C4297, não tente gerar exceções em funções que são declaradas `__declspec(nothrow)`, `noexcept(true)` ou `throw()`. Como alternativa, remova o `noexcept`, `throw()`, ou `__declspec(nothrow)` especificação.  
  
 Por padrão, o compilador gera implícita `noexcept(true)` especificadores de funções de desalocador e destruidores definido pelo usuário e funções de membro especial gerada pelo compilador. Isso segue o padrão C++ 11 ISO. Para evitar a geração de especificadores não exceção implícita e reverter o compilador para o comportamento não padrão do Visual Studio 2013, use o **/Zc:implicitNoexcept-** opção de compilador. Para obter mais informações, consulte [/ZC: implicitnoexcept (especificadores de exceção implícitos)](../../build/reference/zc-implicitnoexcept-implicit-exception-specifiers.md).  
  
 Para obter mais informações sobre as especificações de exceção, consulte [especificações de exceção (lançar)](../../cpp/exception-specifications-throw-cpp.md). Além disso, consulte [/EH (modelo de tratamento de exceção)](../../build/reference/eh-exception-handling-model.md) para obter informações sobre como modificar o comportamento em tempo de compilação de tratamento de exceção.  
  
 Esse aviso também é gerado para declspec ([dllexport](../../cpp/dllexport-dllimport.md)) funções marcado extern "C", mesmo se eles são funções C++.  
  
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