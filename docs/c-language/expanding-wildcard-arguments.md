---
title: Expandindo argumentos de curinga | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-language
ms.tgt_pltfrm: 
ms.topic: article
dev_langs: C++
helpviewer_keywords:
- asterisk wildcard
- question mark, wildcard
- expanding wildcard arguments
- wildcards, expanding
ms.assetid: 80a11c4b-0199-420e-a342-cf1d803be5bc
caps.latest.revision: "11"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.openlocfilehash: b0c1deca52e74241b56c3c152e66a74d652b4829
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
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