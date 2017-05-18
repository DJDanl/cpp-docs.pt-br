---
title: Nomes de ambiente | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-language
ms.tgt_pltfrm: 
ms.topic: article
dev_langs:
- C++
ms.assetid: 9af409a5-e724-465a-9a21-88d3586c2e92
caps.latest.revision: 7
author: mikeblome
ms.author: mblome
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
ms.translationtype: Human Translation
ms.sourcegitcommit: a937c9d083a7e4331af63323a19fb207142604a0
ms.openlocfilehash: e27637b911ebab5552974dd8fc6e7c9637c192a0
ms.contentlocale: pt-br
ms.lasthandoff: 02/25/2017

---
# <a name="environment-names"></a>Nomes de ambientes
**ANSI 4.10.4.4** O conjunto de nomes de ambiente e o método para alterar a lista de ambientes usada pela função [getenv](../c-runtime-library/reference/getenv-wgetenv.md)  
  
 O conjunto de nomes de ambientes é ilimitado.  
  
 Para alterar as variáveis de ambiente de um programa C, chame a função [_putenv](../c-runtime-library/reference/putenv-wputenv.md). Para alterar as variáveis de ambiente de linha de comando no Windows, use o comando SET (por exemplo, SET LIB = D:\ LIBS).  
  
 As variáveis de ambiente definidas dentro de um programa C só existirão enquanto sua cópia do host de shell de comando do sistema operacional estiver em execução (CMD.EXE ou COMMAND.COM). Por exemplo, a linha  
  
```  
system( SET LIB = D:\LIBS );  
```  
  
 executará uma cópia do shell de comando (CMD.EXE), definirá a variável de ambiente LIB e retornará ao programa C, saindo da cópia secundária de CMD.EXE. Sair dessa cópia de CMD.EXE remove a variável de ambiente temporária LIB.  
  
 Da mesma forma, as alterações feitas pela função `_putenv` durará apenas até o encerramento do programa.  
  
## <a name="see-also"></a>Consulte também  
 [Funções de biblioteca](../c-language/library-functions.md)   
 [_putenv, _wputenv](../c-runtime-library/reference/putenv-wputenv.md)   
 [getenv, _wgetenv](../c-runtime-library/reference/getenv-wgetenv.md)
