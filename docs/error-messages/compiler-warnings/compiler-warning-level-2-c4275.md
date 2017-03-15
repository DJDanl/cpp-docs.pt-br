---
title: "Compilador aviso (nível 2) C4275 | Documentos do Microsoft"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C4275
dev_langs:
- C++
helpviewer_keywords:
- C4275
ms.assetid: 18de967a-0a44-4dbc-a2e8-fc4c067ba909
caps.latest.revision: 14
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
ms.openlocfilehash: 873a96d4595b75ff6b9567500723c32d7ba5bd2b
ms.lasthandoff: 02/25/2017

---
# <a name="compiler-warning-level-2-c4275"></a>Compilador C4275 de aviso (nível 2)
não – classkey 'Identificador de interface de DLL' usada como base para interface de DLL classkey 'Identificador'  
  
 Uma classe exportada foi derivada de uma classe que não foram exportada.  
  
 Para minimizar a possibilidade de corrupção de dados ao exportar uma classe com [dllexport](../../cpp/dllexport-dllimport.md), certifique-se de que:  
  
-   Todos os seus dados estáticos é acessado por meio das funções exportadas da DLL.  
  
-   Nenhum método embutido da sua classe pode modificar dados estáticos.  
  
-   Nenhum método embutido da sua classe usa funções de CRT ou outras funções de biblioteca usam dados estáticos.  
  
-   Nenhuma função de classe embutida usa funções de CRT ou outras funções de biblioteca, onde, por exemplo, acessar dados estáticos.  
  
-   Nenhum método de sua classe (independentemente de inlining) podem usar tipos de onde a instanciação no EXE e DLL têm diferenças de dados estáticos.  
  
 Você pode evitar exportando classes definindo uma DLL que define uma classe com funções virtuais e funções que você pode chamar para criar e excluir objetos do tipo.  Você pode chamar funções virtuais apenas no tipo.  
  
 Para obter mais informações sobre como exportar modelos, consulte [http://support.microsoft.com/default.aspx?scid=KB; EN-US;&16895;8](http://support.microsoft.com/default.aspx?scid=KB;EN-US;168958).  
  
 C4275 pode ser ignorado no Visual C++, se você estiver derivando de um tipo de biblioteca padrão C++, compilar uma versão de depuração (**/MTd**) e onde a mensagem de erro do compilador se refere ao _Container_base.  
  
```  
// C4275.cpp  
// compile with: /EHsc /MTd /W2 /c  
#include <vector>  
using namespace std;  
class Node;  
class __declspec(dllimport) VecWrapper : vector<Node *> {};   // C4275  
```
