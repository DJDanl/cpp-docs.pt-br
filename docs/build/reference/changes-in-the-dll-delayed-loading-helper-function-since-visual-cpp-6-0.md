---
title: "Alterações na DLL atrasada função auxiliar de carregamento desde o Visual C++ 6.0 | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-tools
ms.tgt_pltfrm: 
ms.topic: article
dev_langs: C++
helpviewer_keywords:
- delayed loading of DLLs, what's changed
- PFromRva method
- __delayLoadHelper2 function
- helper functions, what's changed
ms.assetid: 99f0be69-105d-49ba-8dd5-3be7939c0c72
caps.latest.revision: "6"
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: b3123a722e0e95119a4b04f5c060bd947b987cdf
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="changes-in-the-dll-delayed-loading-helper-function-since-visual-c-60"></a>Alterações feitas na função auxiliar de carregamento com atraso da DLL desde o Visual C++ 6.0
Se você tiver várias versões do Visual C++ em seu computador ou se você tiver definido sua própria função auxiliar, você pode ser afetado por alterações feitas para a DLL de carregamento atrasado função auxiliar. Por exemplo:  
  
-   **delayloadhelper** agora é **delayloadhelper2**  
  
-   **__pfnDliNotifyHook** agora é **__pfnDliNotifyHook2**  
  
-   **__pfnDliFailureHook** agora é **__pfnDliFailureHook2**  
  
-   **__FUnloadDelayLoadedDLL** agora é **__FUnloadDelayLoadedDLL2**  
  
> [!NOTE]
>  Se você estiver usando a função auxiliar padrão, essas alterações não afetarão você. Não existem alterações sobre como você invoca o vinculador.  
  
## <a name="multiple-versions-of-visual-c"></a>Várias versões do Visual C++  
 Se você tiver várias versões do Visual C++ em seu computador, verifique se que o vinculador corresponde delayimp.lib. Se houver uma incompatibilidade, você receberá um erro de vinculador reporting o `___delayLoadHelper2@8` ou `___delayLoadHelper@8` como um símbolo externo não resolvido. No primeiro caso, um novo vinculador com um delayimp.lib antigo e o último implica um vinculador antigo com um novo delayimp.lib.  
  
 Se você receber um erro de vinculador não resolvidos, execute [/linkermember dumpbin](../../build/reference/linkermember.md): 1 no delayimp.lib que você espera que contenha a função auxiliar para ver qual função auxiliar é definida em vez disso. A função auxiliar também pode ser definida em um arquivo de objeto. executar [dumpbin /symbols](../../build/reference/symbols.md) e procure `delayLoadHelper(2)`.  
  
 Se você souber que tem o vinculador do Visual C++ 6.0, então:  
  
-   Executar dumpbin o arquivo. lib ou. obj do auxiliar de carregamento de atraso para determinar se ele define **delayloadhelper2**. Caso contrário, o link falhará.  
  
-   Definir **delayloadhelper** no atraso carregar o arquivo. lib ou. obj do auxiliar.  
  
## <a name="user-defined-helper-function"></a>Função auxiliar definidos pelo usuário  
 Se definido sua própria função auxiliar e estiver usando a versão atual do Visual C++, faça o seguinte:  
  
-   Renomeie a função auxiliar **delayloadhelper2**.  
  
-   Como os ponteiros no descritor de atraso (ImgDelayDescr em delayimp.h) foram alterados de endereços absolutos (VAs) para endereços relativos (RVAs) para funcionar como esperado em ambos os programas de 32 bits e de 64 bits, você precisa converter esses back ponteiros. Uma nova função foi introduzida: PFromRva, encontrado em delayhlp.cpp. Você pode usar essa função em cada um dos campos no descritor de convertê-las para qualquer um dos ponteiros de 32 ou 64 bits. A função de auxiliar de carregamento de atraso padrão continua a ter um bom modelo a ser usado como um exemplo.  
  
## <a name="load-all-imports-for-a-delay-loaded-dll"></a>Carregar todas as importações para uma DLL carregada com atraso  
 O vinculador pode carregar todas as importações de uma DLL que você especificou para ser carregado de atraso. Consulte [carregar todas as importações para uma DLL Delay-Loaded](../../build/reference/loading-all-imports-for-a-delay-loaded-dll.md) para obter mais informações.  
  
## <a name="see-also"></a>Consulte também  
 [Noções básicas sobre a função auxiliar](understanding-the-helper-function.md)