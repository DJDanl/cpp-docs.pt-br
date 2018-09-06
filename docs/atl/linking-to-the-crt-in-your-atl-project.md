---
title: Vinculando ao CRT em seu projeto ATL | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-atl
ms.topic: conceptual
f1_keywords:
- DllMainCRTStartup
- wWinMainCRTStartup
- WinMainCRTStartup
dev_langs:
- C++
helpviewer_keywords:
- CRT, linking with ATL
- WinMainCRTStartup method
- DllMainCRTStartup method
- wWinMainCRTStartup method
- ATL, C Run-Time library (CRT)
ms.assetid: 650957ae-362c-4ecf-8b03-5d49138e8b5b
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 7d5548089f66a26f633e5692f1fe2199a8109904
ms.sourcegitcommit: 92dbc4b9bf82fda96da80846c9cfcdba524035af
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/05/2018
ms.locfileid: "43764569"
---
# <a name="linking-to-the-crt-in-your-atl-project"></a>Vinculando ao CRT em seu projeto ATL

O [bibliotecas de tempo de execução C](../c-runtime-library/crt-library-features.md) (CRT) fornece muitas funções úteis que podem facilitar a programação muito durante o desenvolvimento de ATL. Todos os projetos ATL vincular à biblioteca do CRT. Você pode ver as vantagens e desvantagens de vinculação de método na [vantagens e desvantagens do método usado para vincular ao CRT](../atl/benefits-and-tradeoffs-of-the-method-used-to-link-to-the-crt.md).

## <a name="effects-of-linking-to-the-crt-on-your-program-image"></a>Efeitos de vincular ao CRT em sua imagem de programa

Se você vincular estaticamente ao CRT, o código do CRT é colocado em sua imagem executável e não é necessário ter a DLL do CRT presentes em um sistema para executar sua imagem. Se você vincular dinamicamente ao CRT, as referências ao código na DLL do CRT são colocadas em sua imagem, mas não o próprio código. Para que sua imagem ser executado em um determinado sistema, a DLL do CRT deve estar presente no sistema. Até mesmo quando você vincula dinamicamente ao CRT, você pode achar que alguns códigos podem ser vinculados estaticamente (por exemplo, `DllMainCRTStartup`).

Quando você vincula sua imagem, você explicitamente ou implicitamente especificar um ponto de entrada que o sistema operacional irá chamar depois de carregar a imagem. Para uma DLL, o ponto de entrada padrão é `DllMainCRTStartup`. Para que um EXE, ele é `WinMainCRTStartup`. Você pode substituir o padrão com a opção de vinculador /ENTRY. A CRT fornece uma implementação para `DllMainCRTStartup`, `WinMainCRTStartup`, e `wWinMainCRTStartup` (o ponto de entrada Unicode para que um EXE). Esses pontos de entrada fornecidos pelo CRT chamar construtores em objetos globais e inicializar outras estruturas de dados que são usadas por algumas funções de CRT. Esse código de inicialização adiciona cerca de 25 mil à sua imagem se ele está vinculado estaticamente. Se ele está vinculado dinamicamente, a maioria do código é na DLL, para que o tamanho da imagem permaneça pequeno.

Para obter mais informações, consulte o tópico de vinculador [/ENTRY (símbolo de ponto de entrada)](../build/reference/entry-entry-point-symbol.md).

## <a name="optimization-options"></a>Opções de otimização

Usando a opção de vinculador/OPT:NOWIN98 pode reduzir ainda mais um controle ATL padrão por 10 mil, às custas de maior ao carregar o tempo em sistemas Windows 98. Para obter mais informações sobre opções de vinculação, consulte [/OPT (otimizações)](../build/reference/opt-optimizations.md).

## <a name="see-also"></a>Consulte também

[Programando com código de tempo de execução de C e ATL](../atl/programming-with-atl-and-c-run-time-code.md)   
[Comportamento de DLLs e da biblioteca em tempo de execução do Visual C++](../build/run-time-library-behavior.md)

