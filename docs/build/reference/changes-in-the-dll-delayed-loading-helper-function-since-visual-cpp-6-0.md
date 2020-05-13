---
title: Alterações feitas na função auxiliar de carregamento com atraso da DLL desde o Visual C++ 6.0
ms.date: 11/04/2016
helpviewer_keywords:
- delayed loading of DLLs, what's changed
- PFromRva method
- __delayLoadHelper2 function
- helper functions, what's changed
ms.assetid: 99f0be69-105d-49ba-8dd5-3be7939c0c72
ms.openlocfilehash: 536729e27c89d068957ea451355957e4a35348ee
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81320604"
---
# <a name="changes-in-the-dll-delayed-loading-helper-function-since-visual-c-60"></a>Alterações feitas na função auxiliar de carregamento com atraso da DLL desde o Visual C++ 6.0

Se você tiver várias versões do Visual C++ no computador ou se você definiu sua própria função de ajudante, você pode ser afetado por alterações feitas na função de ajudante de carregamento atrasado da DLL. Por exemplo:

- **__delayLoadHelper** agora está **__delayLoadHelper2**

- **__pfnDliNotifyHook** agora é **__pfnDliNotifyHook2**

- **__pfnDliFailureHook** agora está **__pfnDliFailureHook2**

- **__FUnloadDelayLoadedDLL** agora está **__FUnloadDelayLoadedDLL2**

> [!NOTE]
> Se você estiver usando a função de ajudante padrão, essas alterações não afetarão você. Não há mudanças em relação à forma como você invoca o linker.

## <a name="multiple-versions-of-visual-c"></a>Múltiplas versões do Visual C++

Se você tiver várias versões do Visual C++ no seu computador, certifique-se de que o linker corresponda ao delayimp.lib. Se houver uma incompatibilidade, você receberá um relatório `___delayLoadHelper2@8` `___delayLoadHelper@8` de erro do linker ou como um símbolo externo não resolvido. O primeiro implica um novo linker com um velho delayimp.lib, e o segundo implica um antigo linker com um novo delayimp.lib.

Se você tiver um erro de linker não resolvido, execute [dumpbin /linkermember](linkermember.md):1 no delayimp.lib que você espera conter a função de ajudante para ver qual função auxiliar é definida em vez disso. A função auxiliar também pode ser definida em um arquivo de objeto; executar [dumpbin /símbolos](symbols.md) `delayLoadHelper(2)`e procurar .

Se você sabe que tem o linker Visual C++ 6.0, então:

- Executar dumpbin no arquivo .lib ou .obj do helper de carga de atraso para determinar se ele define **__delayLoadHelper2**. Se não, o link falhará.

- Defina **__delayLoadHelper** no arquivo .lib ou .obj do helper de carga de atraso.

## <a name="user-defined-helper-function"></a>Função de ajudante definida pelo usuário

Se você definiu sua própria função de ajudante e está usando a versão atual do Visual C++, faça o seguinte:

- Renomeie a função auxiliar para **__delayLoadHelper2**.

- Uma vez que os ponteiros do descritor de atraso (ImgDelayDescr in delayimp.h) foram alterados de endereços absolutos (VAs) para endereços relativos (RVAs) para funcionar como esperado em programas de 32 e 64 bits, você precisa convertê-los de volta em ponteiros. Uma nova função foi introduzida: PFromRva, encontrada em delayhlp.cpp. Você pode usar esta função em cada um dos campos do descritor para convertê-los de volta para ponteiros de 32 ou 64 bits. A função de ajudante de carga de atraso padrão continua a ser um bom modelo para usar como exemplo.

## <a name="load-all-imports-for-a-delay-loaded-dll"></a>Carregar todas as importações para uma dll carregada com atraso

O linker pode carregar todas as importações de uma DLL que você especificou para ser carregado por atraso. Consulte [Loading All Imports for a Delay-Loaded DLL](loading-all-imports-for-a-delay-loaded-dll.md) para obter mais informações.

## <a name="see-also"></a>Confira também

[Noções básicas sobre a função auxiliar](understanding-the-helper-function.md)
