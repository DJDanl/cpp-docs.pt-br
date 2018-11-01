---
title: Noções básicas sobre a função auxiliar
ms.date: 11/04/2016
helpviewer_keywords:
- delayed loading of DLLs, helper function
- __delayLoadHelper2 function
- delayimp.lib
- __delayLoadHelper function
- delayhlp.cpp
- delayimp.h
- helper functions
ms.assetid: 6279c12c-d908-4967-b0b3-cabfc3e91d3d
ms.openlocfilehash: ee2a8b66eaf4a8ba29ba3de7e63407bea738d626
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50440138"
---
# <a name="understanding-the-helper-function"></a>Noções básicas sobre a função auxiliar

A função auxiliar para carregamento atrasado de suporte para o vinculador é o que realmente carrega a DLL em tempo de execução. Você pode modificar a função auxiliar para personalizar seu comportamento escrevendo sua própria função e vinculá-lo ao seu programa em vez de usar a função auxiliar fornecido no delayimp. Uma função auxiliar atende a todas as DLLs de atrasar carregada.

Você pode fornecer sua própria versão da função auxiliar para fazer processamento específico com base nos nomes da DLL ou importações.

A função auxiliar executa as seguintes ações:

- Verifica se o identificador armazenado na biblioteca para ver se ele já foi carregado

- Chamadas **LoadLibrary** para tentar o carregamento da DLL

- Chamadas **GetProcAddress** para tentar obter o endereço do procedimento

- Retorna para a importação de atraso de carga conversão para chamar o ponto de entrada carregadas com agora

A função auxiliar pode retornar a chamada para um gancho de notificação em seu programa depois de cada uma das seguintes ações:

- Quando a função auxiliar é iniciado

- Logo antes **LoadLibrary** é chamado na função auxiliar

- Logo antes **GetProcAddress** é chamado na função auxiliar

- Se a chamada para **LoadLibrary** na função auxiliar falhou

- Se a chamada para **GetProcAddress** na função auxiliar falhou

- Após o auxiliar de função é feita processamento

Cada um desses pontos de gancho pode retornar um valor que irá alterar o processamento normal de a rotina do auxiliar de alguma maneira, exceto o retorno para a conversão de carga de importação de atraso.

O código auxiliar padrão pode ser encontrado no Delayhlp.cpp e delayimp (vc\include) e é compilado no delayimp (em vc\lib). Você precisará incluir essa biblioteca em suas compilações, a menos que você escreva sua própria função auxiliar.

Os tópicos a seguir descrevem a função auxiliar:

- [Alterações feitas na função auxiliar de carregamento com atraso da DLL desde o Visual C++ 6.0](../../build/reference/changes-in-the-dll-delayed-loading-helper-function-since-visual-cpp-6-0.md)

- [Convenções de chamada, parâmetros e tipo de retorno](../../build/reference/calling-conventions-parameters-and-return-type.md)

- [Definições de estrutura e constante](../../build/reference/structure-and-constant-definitions.md)

- [Calculando valores necessários](../../build/reference/calculating-necessary-values.md)

- [Descarregando uma DLL carregada com atraso](../../build/reference/explicitly-unloading-a-delay-loaded-dll.md)

## <a name="see-also"></a>Consulte também

[Suporte do vinculador para DLLs carregadas com atraso](../../build/reference/linker-support-for-delay-loaded-dlls.md)