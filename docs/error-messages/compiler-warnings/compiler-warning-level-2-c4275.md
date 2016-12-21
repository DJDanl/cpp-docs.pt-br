---
title: "Aviso do compilador (n&#237;vel 2) C4275 | Microsoft Docs"
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
  - "C4275"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "C4275"
ms.assetid: 18de967a-0a44-4dbc-a2e8-fc4c067ba909
caps.latest.revision: 14
caps.handback.revision: 14
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Aviso do compilador (n&#237;vel 2) C4275
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

não classkey” – “identificador de DLL\- interface usado como base para o classkey “identificador da” DLL\- interface  
  
 Uma classe exportada foi derivada de uma classe que não foi exportada.  
  
 Para minimizar a possibilidade de corrupção de dados ao exportar uma classe com [\_\_declspec \(dllexport\)](../../cpp/dllexport-dllimport.md), certifique\-se de que:  
  
-   Todos os seus dados estáticos são acessados com as funções que são exportadas da DLL.  
  
-   Nenhum método será embutida da sua classe pode alterar dados estáticos.  
  
-   Nenhum método será embutida da classe usar funções de CRT ou outras funções da biblioteca usam dados estáticos.  
  
-   Nenhuma função da classe será embutida usar funções de CRT, ou outras funções da biblioteca, onde, por exemplo, você acessa dados estáticos.  
  
-   Nenhum método da classe \(independentemente de inlining\) pode usar os tipos onde a instanciação em EXE e a DLL possuem diferenças de dados estáticos.  
  
 Você pode evitar exportar classes definindo uma DLL que define uma classe usada com funções virtuais, e funções que você pode chamar para criar uma instância e excluir objetos do tipo.  Você pode então apenas chamar funções virtuais no tipo.  
  
 Para obter mais informações sobre como exportar modelos, consulte [http:\/\/support.microsoft.com\/default.aspx?scid\=KB;EN\-US;168958](http://support.microsoft.com/default.aspx?scid=KB;EN-US;168958).  
  
 C4275 pode ser ignorado no Visual C\+\+ se você estiver derivando de um tipo na biblioteca padrão C\+\+, criando uma versão de depuração \(**\/MTd**\) e onde a mensagem de erro do compilador refere\-se ao \_Container\_base.  
  
```  
// C4275.cpp  
// compile with: /EHsc /MTd /W2 /c  
#include <vector>  
using namespace std;  
class Node;  
class __declspec(dllimport) VecWrapper : vector<Node *> {};   // C4275  
```