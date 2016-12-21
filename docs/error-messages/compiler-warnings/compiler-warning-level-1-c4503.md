---
title: "Aviso do compilador (n&#237;vel 1) C4503 | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "error-reference"
f1_keywords: 
  - "C4503"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "C4503"
ms.assetid: 7c5a98ae-5b6d-41d8-b881-12d3ffd5e392
caps.latest.revision: 8
caps.handback.revision: 8
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Aviso do compilador (n&#237;vel 1) C4503
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

“identificador”: o comprimento decorado excedido, o nome do nome foi truncado  
  
 O nome decorado era maior que o limite do compilador \(4096\), e foi truncado.  Para evitar esse aviso e o truncamento, reduza o número de argumentos ou comprimento do nome dos identificadores usados.  
  
 Uma situação em que esse aviso será emitido quando o código é contém os modelos especializados em modelos repetidamente.  Por exemplo, um mapa dos mapas de biblioteca padrão \(C\+\+\).  Nessa situação, você pode fazer a seus typedefs um tipo \(struct, por exemplo\) que contém o mapa.  
  
 Você pode, no entanto, decidir não reestruturar seu código.  É possível enviar um aplicativo que gerencia C4503, mas se você obtiver erros de tempo de link em um símbolo truncado, será mais difícil determinar o tipo do símbolo em erro.  A depuração também será mais difícil; o depurador também terá difìcil mapear o nome do símbolo para digite o nome.  A exatidão do programa, porém, não é afetada pelo nome truncado.  
  
 O seguinte exemplo gera C4503:  
  
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
  
 O exemplo a seguir mostra uma maneira da recriação de seu código para resolver C4503:  
  
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