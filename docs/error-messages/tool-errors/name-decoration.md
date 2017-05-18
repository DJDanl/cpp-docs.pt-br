---
title: "Decoração de nome | Documentos do Microsoft"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
dev_langs:
- C++
helpviewer_keywords:
- name decoration [C++]
- names [C++], decorated
- decorated names, calling conventions
ms.assetid: 8327a27b-bb4f-49f2-8218-b851b9d2a463
caps.latest.revision: 9
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
ms.sourcegitcommit: 3168772cbb7e8127523bc2fc2da5cc9b4f59beb8
ms.openlocfilehash: d66aaf837d4db66aeb9fe254c5570de002f941e0
ms.contentlocale: pt-br
ms.lasthandoff: 02/25/2017

---
# <a name="name-decoration"></a>Decoração do nome
Decoração de nome geralmente se refere a convenções de nomenclatura do C++, mas pode ser aplicadas a um número de casos de C também. Por padrão, o C++ usa o nome da função, parâmetros e tipo de retorno para criar um nome de vinculador para a função. Considere a seguinte função:  
  
```  
void CALLTYPE test(void)  
```  
  
 A tabela a seguir mostra o nome do vinculador para várias convenções de chamada.  
  
|Convenção de chamada|arquivo de extern "C" ou. c|. cpp,. cxx ou /TP|  
|------------------------|---------------------------|------------------------|  
|Convenção de nomenclatura de C (`__cdecl`)|Test|? @ de teste@ZAXXZ|  
|Convenção de nomenclatura fastcall (`__fastcall`)|@test@0|? @ de teste@YIXXZ|  
|Convenção de nomenclatura padrão de chamada (`__stdcall`)|_test@0|? @ de teste@YGXXZ|  
|Convenção de nomenclatura Vectorcall (`__vectorcall`)|testar @@0|? @ de teste@YQXXZ|  
  
 Use extern "C" para chamar uma função C do C++. Extern "C" força o uso da convenção de nomenclatura de C para funções do C++ sem classe. Lembre-se de comutadores de compilador **/Tc** ou **/Tp**, que instrui o compilador a ignorar a extensão de nome de arquivo e compilar o arquivo como C ou C++, respectivamente. Essas opções podem causar nomes que não esperado.  
  
 Ter protótipos de função com parâmetros incompatíveis também pode causar esse erro. Decoração de nome incorpora o nome decorado de função final os parâmetros de uma função. Chamar uma função com os tipos de parâmetro que não corresponderem na declaração de função também pode causar LNK2001.  
  
 Atualmente, há um padrão de nomeação entre fornecedores de compilador ou até mesmo entre versões diferentes de um compilador de C++. Arquivos de objeto compilados com outros compiladores de vinculação, portanto, talvez não produza o mesmo esquema de nomenclatura e, portanto, faz com que externos não resolvidos.  
  
## <a name="see-also"></a>Consulte também  
 [Erro das ferramentas de vinculador LNK2001](../../error-messages/tool-errors/linker-tools-error-lnk2001.md)
