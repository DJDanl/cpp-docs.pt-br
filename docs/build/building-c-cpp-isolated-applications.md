---
title: Compilando aplicativos isolados do C/C++
ms.date: 11/04/2016
helpviewer_keywords:
- isolated applications [C++]
ms.assetid: 8a2fe4fa-0489-433e-bfc6-495844d8d73a
ms.openlocfilehash: 6ff9ada45a1ddd7c0aa1da62f6dd7f6a7b7bf371
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50534921"
---
# <a name="building-cc-isolated-applications"></a>Compilando aplicativos isolados do C/C++

Um aplicativo isolado depende somente assemblies lado a lado e associa a suas dependências usando um manifesto. Não é necessário para seu aplicativo para ser totalmente isolados para executar corretamente no Windows; No entanto, ao investir em tornar seu aplicativo totalmente isolado, você pode economizar tempo se você precisar manter seu aplicativo no futuro. Para obter mais informações sobre as vantagens de fazer seu aplicativo totalmente isolado, consulte [aplicativos isolados](/windows/desktop/SbsCs/isolated-applications).

Quando você compila seu aplicativo C/C++ nativo usando o Visual C++, por padrão, o Visual Studio, o sistema de projeto gera um arquivo de manifesto que descreve as dependências do aplicativo em bibliotecas do Visual C++. Se essas são as dependências apenas seu aplicativo tiver, ele se tornará um aplicativo isolado, assim que ele é recriado com o Visual Studio. Se seu aplicativo estiver usando outras bibliotecas em tempo de execução, talvez seja necessário recriar essas bibliotecas como assemblies lado a lado seguindo as etapas descritas em [criando conjuntos de C/C++ lado a lado](../build/building-c-cpp-side-by-side-assemblies.md).

## <a name="see-also"></a>Consulte também

[Conceitos de aplicativos isolados e assemblies lado a lado](../build/concepts-of-isolated-applications-and-side-by-side-assemblies.md)<br/>
[Compilando aplicativos isolados do C/C++ e assemblies lado a lado](../build/building-c-cpp-isolated-applications-and-side-by-side-assemblies.md)