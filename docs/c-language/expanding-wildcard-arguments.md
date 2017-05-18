---
title: Expandindo argumentos de curinga | Microsoft Docs
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
helpviewer_keywords:
- asterisk wildcard
- question mark, wildcard
- expanding wildcard arguments
- wildcards, expanding
ms.assetid: 80a11c4b-0199-420e-a342-cf1d803be5bc
caps.latest.revision: 11
author: mikeblome
ms.author: mblome
manager: ghogen
translation.priority.ht:
- de-de
- es-es
- fr-fr
- it-it
- ja-jp
- ko-kr
- ru-ru
- zh-cn
- zh-tw
translation.priority.mt:
- cs-cz
- pl-pl
- pt-br
- tr-tr
ms.translationtype: Human Translation
ms.sourcegitcommit: a937c9d083a7e4331af63323a19fb207142604a0
ms.openlocfilehash: b8444a15e8f0fb9a8e4322f1bb2001b19d38eec1
ms.contentlocale: pt-br
ms.lasthandoff: 02/25/2017

---
# <a name="expanding-wildcard-arguments"></a>Expandindo argumentos de curinga
**Seção específica da Microsoft**  
  
 Ao executar um programa C, você pode usar qualquer um dos dois caracteres curinga — o ponto de interrogação (?) e o asterisco (*) — para especificar argumentos de nome de arquivo e caminho na linha de comando.  
  
 Por padrão, os curingas não são expandidos em argumentos de linha de comando. Você pode substituir o vetor de argumento normal `argv` carregando a rotina com uma versão que expande curingas por meio da vinculação com o arquivo setargv.obj ou wsetargv.obj. Se seu programa usa uma função `main`, faça um link com setargv.obj. Se seu programa usa uma função `wmain`, faça um link com wsetargv.obj. Ambos têm comportamento equivalente.  
  
 Para vinculá-lo a Setargv.obj ou a wsetargv.obj, use a opção **/link**. Por exemplo:  
  
 **cl example.c /link setargv.obj**  
  
 Os caracteres curinga são expandidos da mesma maneira que os comandos do sistema operacional. (Consulte o guia do usuário do sistema operacional se você não estiver familiarizado com os caracteres curinga.)  
  
 **Fim da seção específica da Microsoft**  
  
## <a name="see-also"></a>Consulte também  
 [Opções de link](../c-runtime-library/link-options.md)   
 [Função main e execução do programa](../c-language/main-function-and-program-execution.md)
