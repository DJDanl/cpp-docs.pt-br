---
title: "Compilador (nível 1) de aviso C4503 | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C4503
dev_langs:
- C++
helpviewer_keywords:
- C4503
ms.assetid: 7c5a98ae-5b6d-41d8-b881-12d3ffd5e392
caps.latest.revision: 
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 8f8af13ffdcd71d760a180340a79a863cecb5e32
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="compiler-warning-level-1-c4503"></a>Compilador C4503 de aviso (nível 1)
'Identificador': decorado excedido, comprimento do nome nome foi truncado  
  
 O nome decorado era maior que o limite do compilador (4096) e foi truncado. Para evitar esse aviso e o truncamento, reduza o número de argumentos ou o comprimento do nome dos identificadores usados.  
  
 Uma situação em que esse aviso será emitido é quando o código contém modelos especializado em modelos repetidamente.  Por exemplo, um mapa de mapas (da biblioteca padrão C++).  Nessa situação, você pode tornar seu typedefs um tipo (por exemplo, struct) que contém o mapa.  
  
 No entanto, você pode, decidir não reestruture seu código.  É possível enviar um aplicativo que gera C4503, mas se você receber erros de tempo de link em um símbolo truncado, será mais difícil determinar o tipo do símbolo no erro.  Depuração também será mais difícil; o depurador também terão dificuldade mapeamento de nome de símbolo para o nome de tipo.  A exatidão do programa, no entanto, não é afetada pelo nome truncado.  
  
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