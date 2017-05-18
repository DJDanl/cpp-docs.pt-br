---
title: "Compilador aviso (nível 1) C4251 | Documentos do Microsoft"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C4251
dev_langs:
- C++
helpviewer_keywords:
- C4251
ms.assetid: a9992038-f0c2-4fc4-a9be-4509442cbc1e
caps.latest.revision: 16
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
ms.sourcegitcommit: 3f69f0c3176d2fbe19e11ce08c071691a72d858d
ms.openlocfilehash: b75c3e6c93c0963a692b210b158339ea5e9eacac
ms.contentlocale: pt-br
ms.lasthandoff: 02/25/2017

---
# <a name="compiler-warning-level-1-c4251"></a>Compilador C4251 de aviso (nível 1)
'identifier': classe 'type' deve ter a interface de dll a ser usado por clientes da classe 'type2'  
  
 Para minimizar a possibilidade de corrupção de dados ao exportar uma classe com [dllexport](../../cpp/dllexport-dllimport.md), certifique-se de que:  
  
-   Todos os seus dados estáticos é o acesso por meio das funções exportadas da DLL.  
  
-   Nenhum método embutido da sua classe pode modificar dados estáticos.  
  
-   Nenhum método embutido da sua classe usa funções de CRT ou outras funções de biblioteca usam dados estáticos (consulte [potenciais erros passando CRT objetos entre limites de DLL](../../c-runtime-library/potential-errors-passing-crt-objects-across-dll-boundaries.md) para obter mais informações).  
  
-   Nenhum método de sua classe (independentemente de inlining) podem usar tipos de onde a instanciação no EXE e DLL têm diferenças de dados estáticos.  
  
 Você pode evitar exportando classes definindo uma DLL que define uma classe com funções virtuais e funções que você pode chamar para criar e excluir objetos do tipo.  Você pode chamar funções virtuais apenas no tipo.  
  
 Para obter mais informações sobre como exportar modelos, consulte [http://support.microsoft.com/default.aspx?scid=KB; EN-US;&16895;8](http://support.microsoft.com/default.aspx?scid=KB;EN-US;168958).  
  
 C4251 pode ser ignorado se você estiver derivando de um tipo de biblioteca padrão C++, compilar uma versão de depuração (**/MTd**) e onde a mensagem de erro do compilador se refere ao _Container_base.  
  
```  
// C4251.cpp  
// compile with: /EHsc /MTd /W2 /c  
#include <vector>  
using namespace std;  
class Node;  
class __declspec(dllimport) VecWrapper : vector<Node *> {};   // C4251  
```
