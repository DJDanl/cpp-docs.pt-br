---
title: Compilador (nível 2) do aviso C4275 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C4275
dev_langs:
- C++
helpviewer_keywords:
- C4275
ms.assetid: 18de967a-0a44-4dbc-a2e8-fc4c067ba909
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: a5d2a3cd7c4b937f8bee1b8f8e37e0619cc224ba
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="compiler-warning-level-2-c4275"></a>Compilador C4275 de aviso (nível 2)
não - DLL-interface classkey 'Identificador' usado como base para classkey 'Identificador de interface de DLL'  
  
 Uma classe exportada foi derivada de uma classe que não foram exportada.  
  
 Para minimizar a possibilidade de corrupção de dados ao exportar uma classe com [dllexport](../../cpp/dllexport-dllimport.md), certifique-se de que:  
  
-   Todos os seus dados estáticos é acessado por meio de funções exportadas da DLL.  
  
-   Nenhum método embutido da sua classe pode modificar dados estáticos.  
  
-   Nenhum método embutido da sua classe usa funções de CRT ou outras funções de biblioteca usam dados estáticos.  
  
-   Nenhuma função de classe embutida usa funções de CRT ou outras funções de biblioteca, onde, por exemplo, acessar dados estáticos.  
  
-   Nenhum método de sua classe (independentemente de inlining) podem usar os tipos de onde a instanciação na DLL e EXE têm diferenças de dados estáticos.  
  
 Você pode evitar exportando classes definindo uma DLL que define uma classe com funções virtuais e funções que você pode chamar para instanciar e excluir objetos do tipo.  Em seguida, você pode chamar apenas funções virtuais no tipo.  
  
 Para obter mais informações sobre como exportar modelos, consulte [ http://support.microsoft.com/default.aspx?scid=KB; EN-US; 168958](http://support.microsoft.com/default.aspx?scid=KB;EN-US;168958).  
  
 C4275 pode ser ignorado em Visual C++ se você estiver derivando de um tipo de biblioteca padrão C++, Compilando uma versão de depuração (**/MTd**) e onde a mensagem de erro do compilador se refere à _Container_base.  
  
```  
// C4275.cpp  
// compile with: /EHsc /MTd /W2 /c  
#include <vector>  
using namespace std;  
class Node;  
class __declspec(dllimport) VecWrapper : vector<Node *> {};   // C4275  
```