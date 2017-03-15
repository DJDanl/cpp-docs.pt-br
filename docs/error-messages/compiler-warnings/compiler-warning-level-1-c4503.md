---
title: "Compilador aviso (nível 1) C4503 | Documentos do Microsoft"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C4503
dev_langs:
- C++
helpviewer_keywords:
- C4503
ms.assetid: 7c5a98ae-5b6d-41d8-b881-12d3ffd5e392
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
ms.sourcegitcommit: 3f69f0c3176d2fbe19e11ce08c071691a72d858d
ms.openlocfilehash: f999fcb73860bfd2fabb3484e78f313a32240dee
ms.lasthandoff: 02/25/2017

---
# <a name="compiler-warning-level-1-c4503"></a>Compilador C4503 de aviso (nível 1)
'identifier': decorados excedido, comprimento do nome nome foi truncado.  
  
 O nome decorado era maior que o limite do compilador (4096) e foi truncado. Para evitar esse aviso e o truncamento, reduza o número de argumentos ou o comprimento do nome dos identificadores usados.  
  
 Uma situação em que o aviso será emitido é quando seu código contém modelos especializados em modelos repetidamente.  Por exemplo, um mapa de mapas (da biblioteca padrão C++).  Nessa situação, você pode fazer suas definições de tipo um tipo (por exemplo, struct) que contém o mapa.  
  
 Você pode, no entanto, decidir não reestruturar seu código.  É possível enviar um aplicativo que gera C4503, mas se você obtiver erros de tempo de link em um símbolo truncado, será mais difícil determinar o tipo do símbolo no erro.  Depuração também será mais difícil; o depurador também terá dificuldade mapeamento de nome do símbolo para o tipo de nome.  A correção do programa, no entanto, não é afetada pelo nome truncado.  
  
 O exemplo a seguir gera C4503:  
  
```  
// C4503.cpp  
// compile with: /W1 /EHsc /c  
// C4503 expected  
#include <string>  
#include <map>  
  
class Field{};  
  
typedef std::map<std::string, Field> Screen;  
typedef std::map<std::string, Screen> WebApp;  
typedef std::map<std::string, WebApp> WebAppTest;  
typedef std::map<std::string, WebAppTest> Hello;  
Hello MyWAT;  
```  
  
 O exemplo a seguir mostra uma maneira de reescrever o código para resolver C4503:  
  
```  
// C4503b.cpp  
// compile with: /W1 /EHsc /c  
#include <string>  
#include <map>  
  
class Field{};  
struct Screen2 {  
   std::map<std::string, Field> Element;  
};  
  
struct WebApp2 {  
   std::map<std::string, Screen2> Element;  
};  
  
struct WebAppTest2 {  
   std::map<std::string, WebApp2> Element;  
};  
  
struct Hello2 {  
   std::map<std::string, WebAppTest2> Element;  
};  
  
Hello2 MyWAT2;  
```
