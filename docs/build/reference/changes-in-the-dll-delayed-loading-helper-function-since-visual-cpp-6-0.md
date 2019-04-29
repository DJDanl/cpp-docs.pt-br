---
title: Alterações feitas na função auxiliar de carregamento com atraso da DLL desde o Visual C++ 6.0
ms.date: 11/04/2016
helpviewer_keywords:
- delayed loading of DLLs, what's changed
- PFromRva method
- __delayLoadHelper2 function
- helper functions, what's changed
ms.assetid: 99f0be69-105d-49ba-8dd5-3be7939c0c72
ms.openlocfilehash: cd6e842fd6d35e05f2d5a9f906713f0d85d3b80d
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62294623"
---
# <a name="changes-in-the-dll-delayed-loading-helper-function-since-visual-c-60"></a>Alterações feitas na função auxiliar de carregamento com atraso da DLL desde o Visual C++ 6.0

Se você tiver várias versões do Visual C++ em seu computador ou se você tiver definido sua própria função auxiliar, você pode ser afetado por alterações feitas para a DLL de carregamento com atraso da função auxiliar. Por exemplo:

- **delayloadhelper** agora é **__delayLoadHelper2**

- **__pfnDliNotifyHook** agora é **__pfnDliNotifyHook2**

- **__pfnDliFailureHook** agora é **__pfnDliFailureHook2**

- **__FUnloadDelayLoadedDLL** agora é **__FUnloadDelayLoadedDLL2**

> [!NOTE]
>  Se você estiver usando a função de auxiliar padrão, essas alterações não afetarão você. Não há nenhuma alteração em relação a como você invoca o vinculador.

## <a name="multiple-versions-of-visual-c"></a>Várias versões do Visual C++

Se você tiver várias versões do Visual C++ em seu computador, verifique se que o vinculador corresponde delayimp. Se houver uma incompatibilidade, você receberá um erro de vinculador a emissão de relatórios `___delayLoadHelper2@8` ou `___delayLoadHelper@8` como um símbolo externo não resolvido. O primeiro implica um vinculador novo com um delayimp antigo e o último implica um vinculador antigo com um novo delayimp.

Se você receber um erro de vinculador não resolvido, execute [/linkermember (DUMPBIN)](linkermember.md): 1 no delayimp que você espera que contenha a função auxiliar para ver qual função auxiliar é definida em vez disso. A função auxiliar também pode ser definida em um arquivo de objeto; Execute [dumpbin /symbols](symbols.md) e procure `delayLoadHelper(2)`.

Se você souber que tem o vinculador do Visual C++ 6.0, então:

- Executar (DUMPBIN) o arquivo. lib ou. obj do auxiliar de carregamento de atraso para determinar se ele define **__delayLoadHelper2**. Caso contrário, o link falhará.

- Definir **delayloadhelper** no atraso carregar o arquivo. lib ou. obj do auxiliar.

## <a name="user-defined-helper-function"></a>Função auxiliar definido pelo usuário

Se você definiu sua própria função auxiliar e estiver usando a versão atual do Visual C++, faça o seguinte:

- Renomeie a função auxiliar **__delayLoadHelper2**.

- Como os ponteiros no descritor de atraso (ImgDelayDescr em delayimp) foram alterados de endereços absolutos (VAs) para endereços relativos relacionados (RVAs) para funcionar como esperado em ambos os programas de 32 e 64 bits, você precisa converter esses back para ponteiros. Foi introduzida uma nova função: PFromRva, encontrado no delayhlp.cpp. Você pode usar essa função em cada um dos campos no descritor de convertê-los de volta para qualquer um dos ponteiros de 32 ou 64 bits. A função de auxiliar de carregamento de atraso padrão continua a ser um bom modelo a ser usado como um exemplo.

## <a name="load-all-imports-for-a-delay-loaded-dll"></a>Carregar todas as importações para uma DLL carregadas com atraso

O vinculador pode carregar todas as importações de uma DLL que você especificou para ser carregado de atraso. Ver [carregar todas as importações para uma DLL Delay-Loaded](loading-all-imports-for-a-delay-loaded-dll.md) para obter mais informações.

## <a name="see-also"></a>Consulte também

[Noções básicas sobre a função auxiliar](understanding-the-helper-function.md)
