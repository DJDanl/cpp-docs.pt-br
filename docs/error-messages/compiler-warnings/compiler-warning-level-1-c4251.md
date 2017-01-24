---
title: "Aviso do compilador (n&#237;vel 1) C4251 | Microsoft Docs"
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
  - "C4251"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "C4251"
ms.assetid: a9992038-f0c2-4fc4-a9be-4509442cbc1e
caps.latest.revision: 16
caps.handback.revision: 16
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Aviso do compilador (n&#237;vel 1) C4251
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

“identificador”: necessidades do tipo das classes de” ter a DLL\- interface a ser usada pelos clientes do tipo das classes \- 2 "  
  
 Para minimizar a possibilidade de corrupção de dados ao exportar uma classe com [\_\_declspec \(dllexport\)](../../cpp/dllexport-dllimport.md), certifique\-se de que:  
  
-   Todos os seus dados estáticos são acesso às funções que são exportadas da DLL.  
  
-   Nenhum método será embutida da sua classe pode alterar dados estáticos.  
  
-   Nenhum método será embutida da classe usar funções de CRT ou outros dados estáticos usam funções de biblioteca \(consulte [Erros em potencial passando por objetos CRT em limites de DLL](../../c-runtime-library/potential-errors-passing-crt-objects-across-dll-boundaries.md) para obter mais informações\).  
  
-   Nenhum método da classe \(independentemente de inlining\) pode usar os tipos onde a instanciação em EXE e a DLL possuem diferenças de dados estáticos.  
  
 Você pode evitar exportar classes definindo uma DLL que define uma classe usada com funções virtuais, e funções que você pode chamar para criar uma instância e excluir objetos do tipo.  Você pode então apenas chamar funções virtuais no tipo.  
  
 Para obter mais informações sobre como exportar modelos, consulte [http:\/\/support.microsoft.com\/default.aspx?scid\=KB;EN\-US;168958](http://support.microsoft.com/default.aspx?scid=KB;EN-US;168958).  
  
 C4251 pode ser ignorado se você estiver derivando de um tipo na biblioteca padrão C\+\+, criando uma versão de depuração \(**\/MTd**\) e onde a mensagem de erro do compilador refere\-se ao \_Container\_base.  
  
```  
// C4251.cpp  
// compile with: /EHsc /MTd /W2 /c  
#include <vector>  
using namespace std;  
class Node;  
class __declspec(dllimport) VecWrapper : vector<Node *> {};   // C4251  
```