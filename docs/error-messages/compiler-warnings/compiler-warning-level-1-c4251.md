---
title: Compilador (nível 1) de aviso C4251 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C4251
dev_langs:
- C++
helpviewer_keywords:
- C4251
ms.assetid: a9992038-f0c2-4fc4-a9be-4509442cbc1e
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 366d66a38685e75e47d8921f9ebd525b334ced7e
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="compiler-warning-level-1-c4251"></a>Compilador C4251 de aviso (nível 1)
'Identificador': classe 'type' precisa ter dll-interface a ser usada por clientes da classe 'type2'  
  
 Para minimizar a possibilidade de corrupção de dados ao exportar uma classe com [dllexport](../../cpp/dllexport-dllimport.md), certifique-se de que:  
  
-   Todos os seus dados estáticos é acesso por meio de funções exportadas da DLL.  
  
-   Nenhum método embutido da sua classe pode modificar dados estáticos.  
  
-   Nenhum método embutido da sua classe usa funções de CRT ou outras funções de biblioteca usam dados estáticos (consulte [possíveis erros passando CRT objetos entre limites de DLL](../../c-runtime-library/potential-errors-passing-crt-objects-across-dll-boundaries.md) para obter mais informações).  
  
-   Nenhum método de sua classe (independentemente de inlining) podem usar os tipos de onde a instanciação na DLL e EXE têm diferenças de dados estáticos.  
  
 Você pode evitar exportando classes definindo uma DLL que define uma classe com funções virtuais e funções que você pode chamar para instanciar e excluir objetos do tipo.  Em seguida, você pode chamar apenas funções virtuais no tipo.  
  
 Para obter mais informações sobre como exportar modelos, consulte [ http://support.microsoft.com/default.aspx?scid=KB; EN-US; 168958](http://support.microsoft.com/default.aspx?scid=KB;EN-US;168958).  
  
 C4251 pode ser ignorada se você estiver derivando de um tipo de biblioteca padrão C++, Compilando uma versão de depuração (**/MTd**) e onde a mensagem de erro do compilador se refere à _Container_base.  
  
```  
// C4251.cpp  
// compile with: /EHsc /MTd /W2 /c  
#include <vector>  
using namespace std;  
class Node;  
class __declspec(dllimport) VecWrapper : vector<Node *> {};   // C4251  
```