---
title: Personalizando processamento de linha de comando C++ | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-language
ms.tgt_pltfrm: 
ms.topic: language-reference
f1_keywords:
- _setenvp
- _setargv
dev_langs:
- C++
helpviewer_keywords:
- command line [C++], processing
- command-line processing
- startup code, customizing command-line processing
- environment, environment-processing routine
- _setargv function
- command line [C++], processing arguments
- suppressing environment processing
- _setenvp function
ms.assetid: aae01cbb-892b-48b8-8e1f-34f22421f263
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 396f2a314c185f39593c92745346f988d666980f
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="customizing-c-command-line-processing"></a>Personalizando processamento de linha de comando C++
## <a name="microsoft-specific"></a>Específico da Microsoft  
 Se o seu programa não utiliza argumentos de linha de comando, é possível economizar um pequeno espaço suprimindo o uso da rotina de biblioteca que executa o processamento de linha de comando. Esta rotina é chamada **setargv** e é descrito na [expansão de curinga](../cpp/wildcard-expansion.md). Para suprimir o seu uso, definir uma rotina que não faz nada no arquivo que contém o **principal** de função e nomeie-o **setargv**. A chamada para **setargv** , em seguida, é atendido pela sua definição de **setargv**, e a versão da biblioteca não está carregada.  
  
 Da mesma forma, se você nunca acessa a tabela de ambiente por meio de `envp` argumento, você pode fornecer sua própria rotina vazia a ser usado no lugar de **setenvp**, a rotina de processamento de ambiente. Assim como ocorre com o **setargv** função **setenvp** deve ser declarado como **extern "C"**.  
  
 Seu programa pode fazer chamadas para o **geração** ou `exec` família de rotinas na biblioteca de tempo de execução do C. Se esse for o caso, você não deve suprimir a rotina de processamento de ambiente, pois essa rotina é usada para passar um ambiente do processo pai para o processo filho.  
  
**Fim da seção específica da Microsoft**  
  
## <a name="see-also"></a>Consulte também  
 [main: inicialização do programa](../cpp/main-program-startup.md)