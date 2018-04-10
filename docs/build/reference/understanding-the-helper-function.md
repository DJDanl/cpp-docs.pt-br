---
title: Noções básicas sobre a função auxiliar | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.reviewer: ''
ms.suite: ''
ms.technology:
- cpp-tools
ms.tgt_pltfrm: ''
ms.topic: article
dev_langs:
- C++
helpviewer_keywords:
- delayed loading of DLLs, helper function
- __delayLoadHelper2 function
- delayimp.lib
- __delayLoadHelper function
- delayhlp.cpp
- delayimp.h
- helper functions
ms.assetid: 6279c12c-d908-4967-b0b3-cabfc3e91d3d
caps.latest.revision: 8
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: c3a013cf584c37f84331a5ab5dfe74eaa213c851
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="understanding-the-helper-function"></a>Noções básicas sobre a função auxiliar
A função auxiliar para suporte de vinculador carregamento atrasado é o que realmente carrega a DLL em tempo de execução. Você pode modificar a função auxiliar para personalizar seu comportamento escrevendo sua própria função e vinculá-lo ao seu programa em vez de usar a função auxiliar fornecido em Delayimp.lib. Uma função auxiliar serve todas as DLLs de atraso carregado.  
  
 Você pode fornecer sua própria versão da função auxiliar, se você quiser fazer o processamento específico com base nos nomes da DLL ou importações.  
  
 A função auxiliar executa as seguintes ações:  
  
-   Verifica se o identificador armazenado na biblioteca para ver se ele já foi carregado  
  
-   Chamadas **LoadLibrary** a tentativa de carregamento de DLL  
  
-   Chamadas **GetProcAddress** para tentar obter o endereço do procedimento  
  
-   Retorna para a importação de atraso carga conversão para chamar o ponto de entrada carregado agora  
  
 A função auxiliar pode chamar de volta para um gancho de notificação em seu programa depois de cada uma das seguintes ações:  
  
-   Quando a função auxiliar é iniciado  
  
-   Antes **LoadLibrary** é chamado na função auxiliar  
  
-   Antes **GetProcAddress** é chamado na função auxiliar  
  
-   Se a chamada para **LoadLibrary** na função auxiliar falha  
  
-   Se a chamada para **GetProcAddress** na função auxiliar falha  
  
-   Após o auxiliar de função é feita processamento  
  
 Cada um desses pontos de gancho pode retornar um valor que irá alterar o processamento normal da rotina auxiliar de alguma maneira exceto o retorno para a conversão de carga de importação de atraso.  
  
 O código auxiliar padrão pode ser encontrado no Delayhlp.cpp e Delayimp.h (vc\include) e é compilado em Delayimp.lib (em vc\lib). Você precisará incluir essa biblioteca em suas compilações, a menos que você escrever sua própria função auxiliar.  
  
 Os tópicos a seguir descrevem a função auxiliar:  
  
-   [Alterações feitas na função auxiliar de carregamento com atraso da DLL desde o Visual C++ 6.0](../../build/reference/changes-in-the-dll-delayed-loading-helper-function-since-visual-cpp-6-0.md)  
  
-   [Convenções de chamada, parâmetros e tipo de retorno](../../build/reference/calling-conventions-parameters-and-return-type.md)  
  
-   [Definições de estrutura e constante](../../build/reference/structure-and-constant-definitions.md)  
  
-   [Calculando valores necessários](../../build/reference/calculating-necessary-values.md)  
  
-   [Descarregando uma DLL carregada com atraso](../../build/reference/explicitly-unloading-a-delay-loaded-dll.md)  
  
## <a name="see-also"></a>Consulte também  
 [Suporte do vinculador para DLLs carregadas com atraso](../../build/reference/linker-support-for-delay-loaded-dlls.md)