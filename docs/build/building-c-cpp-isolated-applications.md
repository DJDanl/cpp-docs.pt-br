---
title: Compilando aplicativos isolados do C/C++
ms.date: 05/06/2019
helpviewer_keywords:
- isolated applications [C++]
ms.assetid: 8a2fe4fa-0489-433e-bfc6-495844d8d73a
ms.openlocfilehash: 42192ad9388a8e69b70947c20c6fa7ee428a2bb9
ms.sourcegitcommit: da32511dd5baebe27451c0458a95f345144bd439
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/07/2019
ms.locfileid: "65220964"
---
# <a name="building-cc-isolated-applications"></a>Compilando aplicativos isolados do C/C++

Um aplicativo isolado depende somente assemblies lado a lado e associa a suas dependências usando um manifesto. Não é necessário para seu aplicativo para ser totalmente isolados para executar corretamente no Windows; No entanto, ao investir em tornar seu aplicativo totalmente isolado, você pode economizar tempo se você precisar manter seu aplicativo no futuro. Para obter mais informações sobre as vantagens de fazer seu aplicativo totalmente isolado, consulte [aplicativos isolados](/windows/desktop/SbsCs/isolated-applications).

Quando você compila seu nativo C /C++ aplicativo usando o Visual Studio, por padrão, o sistema de projeto do Visual Studio gera um arquivo de manifesto que descreve as dependências do aplicativo em bibliotecas do Visual Studio. Se essas são as dependências apenas seu aplicativo tiver, ele se tornará um aplicativo isolado, assim que ele é recriado com o Visual Studio. Se seu aplicativo estiver usando outras bibliotecas em tempo de execução, talvez seja necessário recriar essas bibliotecas como assemblies lado a lado seguindo as etapas descritas em [criando conjuntos de C/C++ lado a lado](building-c-cpp-side-by-side-assemblies.md).

## <a name="see-also"></a>Consulte também

[Conceitos de aplicativos isolados e assemblies lado a lado](concepts-of-isolated-applications-and-side-by-side-assemblies.md)<br/>
[Compilando aplicativos isolados do C/C++ e assemblies lado a lado](building-c-cpp-isolated-applications-and-side-by-side-assemblies.md)
