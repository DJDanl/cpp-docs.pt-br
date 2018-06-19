---
title: Personalizando processamento de linha de comando C | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-language
ms.topic: language-reference
dev_langs:
- C++
helpviewer_keywords:
- _spawn functions
- command line, processing
- command-line processing
- startup code, customizing command-line processing
- environment, environment-processing routine
- _setargv function
- command line, processing arguments
- suppressing environment processing
- _exec function
ms.assetid: c20fa11d-b35b-4f3e-93b6-2cd5a1c3c993
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 824de86ec0930fb93bf5fa0a2a8ac15a4237e4fb
ms.sourcegitcommit: be2a7679c2bd80968204dee03d13ca961eaa31ff
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/03/2018
ms.locfileid: "32384392"
---
# <a name="customizing-c-command-line-processing"></a>Personalizando processamento de linha de comando C
Se o seu programa não utiliza argumentos de linha de comando, é possível economizar um pequeno espaço suprimindo o uso da rotina de biblioteca que executa o processamento de linha de comando. Essa rotina é chamada de **_setargv** (ou **_wsetargv** no ambiente de caractere largo), conforme descrito em [Expandir argumentos curinga](../c-language/expanding-wildcard-arguments.md). Para suprimir seu uso, defina uma rotina que não faça nada no arquivo que contém a função **main** e denomine-a **_setargv** (ou **_wsetargv** no ambiente de caractere largo). A chamada para **_setargv** ou **_wsetargv** é atendida por sua definição de **_setargv** ou de **_wsetargv** e a versão da biblioteca não é carregada.  
  
 Da mesma forma, se você nunca acessar a tabela de ambiente pelo argumento `envp`, poderá fornecer sua própria rotina vazia, que será usada em vez de **_setenvp** (ou de **_wsetenvp**), a rotina de processamento de ambiente.  
  
 Se seu programa faz chamadas para a família **_spawn** ou **_exec** das rotinas na biblioteca em tempo de execução de C, você não deve suprimir a rotina de processamento de ambiente, pois ela é usada para transmitir um ambiente do processo de geração para o novo processo.  
  
## <a name="see-also"></a>Consulte também  
 [Função main e execução do programa](../c-language/main-function-and-program-execution.md)