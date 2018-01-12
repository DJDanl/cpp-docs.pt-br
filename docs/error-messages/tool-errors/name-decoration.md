---
title: "Decoração de nome | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
dev_langs: C++
helpviewer_keywords:
- name decoration [C++]
- names [C++], decorated
- decorated names, calling conventions
ms.assetid: 8327a27b-bb4f-49f2-8218-b851b9d2a463
caps.latest.revision: "9"
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: f780b91d7d58ecdfc9b2af4295c76253357f8e66
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="name-decoration"></a>Decoração do nome
Decoração do nome geralmente se refere a convenções de nomenclatura do C++, mas pode ser aplicadas a um número de casos de C também. Por padrão, o C++ usa o nome da função, parâmetros e tipo de retorno para criar um nome de vinculador para a função. Considere a seguinte função:  
  
```  
void CALLTYPE test(void)  
```  
  
 A tabela a seguir mostra o nome do vinculador para várias convenções de chamada.  
  
|Convenção de chamada|arquivo de extern "C" ou o. c|. cpp,. cxx ou /TP|  
|------------------------|---------------------------|------------------------|  
|Convenção de nomenclatura de C (`__cdecl`)|Test|? @ de teste@ZAXXZ|  
|Convenção de nomenclatura fastcall (`__fastcall`)|@test@0|? @ de teste@YIXXZ|  
|Convenção de nomenclatura padrão de chamada (`__stdcall`)|_test@0|? @ de teste@YGXXZ|  
|Convenção de nomenclatura Vectorcall (`__vectorcall`)|testar @@0|? @ de teste@YQXXZ|  
  
 Use extern "C" para chamar uma função de C do C++. Extern "C" força o uso da convenção de nomenclatura de C para funções de C++ não classe. Lembre-se de switches de compilador **/Tc** ou **/Tp**, que instrui o compilador a ignorar a extensão de nome de arquivo e compilar o arquivo como C ou C++, respectivamente. Essas opções podem causar nomes que você não espera.  
  
 Ter protótipos de função que tenha parâmetros incompatíveis também pode causar esse erro. Decoração do nome incorpora o nome da função decorados final os parâmetros de uma função. Chamando uma função com os tipos de parâmetro que não coincide com a declaração da função também pode causar LNK2001.  
  
 Atualmente, há um padrão de nomeação entre os fornecedores de compilador ou até mesmo entre versões diferentes de um compilador de C++. Vincular, portanto, os arquivos de objeto compilados com outros compiladores talvez não produza o mesmo esquema de nomenclatura e, portanto, faz com que itens externos não resolvidos.  
  
## <a name="see-also"></a>Consulte também  
 [Erro das ferramentas de vinculador LNK2001](../../error-messages/tool-errors/linker-tools-error-lnk2001.md)