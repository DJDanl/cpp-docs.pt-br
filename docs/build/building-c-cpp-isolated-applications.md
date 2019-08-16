---
title: Compilando aplicativos isolados do C/C++
ms.date: 05/06/2019
helpviewer_keywords:
- isolated applications [C++]
ms.assetid: 8a2fe4fa-0489-433e-bfc6-495844d8d73a
ms.openlocfilehash: fbb553e3514ac3c32ee1e1f276dcb3e43d3a192e
ms.sourcegitcommit: fcb48824f9ca24b1f8bd37d647a4d592de1cc925
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/15/2019
ms.locfileid: "69493338"
---
# <a name="building-cc-isolated-applications"></a>Compilando aplicativos isolados do C/C++

Um aplicativo isolado depende apenas de assemblies lado a lado e é associado a suas dependências usando um manifesto. Não é necessário que seu aplicativo esteja totalmente isolado para ser executado corretamente no Windows; no entanto, ao investir em tornar seu aplicativo totalmente isolado, você poderá economizar tempo se precisar atender seu aplicativo no futuro. Para obter mais informações sobre as vantagens de tornar seu aplicativo totalmente isolado, consulte [aplicativos isolados](/windows/win32/SbsCs/isolated-applications).

Quando você cria seu C/C++ aplicativo nativo usando o Visual Studio, por padrão, o sistema de projeto do Visual Studio gera um arquivo de manifesto que descreve as dependências do seu aplicativo nas bibliotecas do Visual Studio. Se essas são as únicas dependências de seu aplicativo, ele se torna um aplicativo isolado assim que é recriado com o Visual Studio. Se seu aplicativo estiver usando outras bibliotecas em tempo de execução, talvez seja necessário recriar essas bibliotecas como assemblies lado a lado seguindo as etapas descritas na [criação de assembliesC++ C/lado](building-c-cpp-side-by-side-assemblies.md)a lado.

## <a name="see-also"></a>Consulte também

[Conceitos de aplicativos isolados e assemblies lado a lado](concepts-of-isolated-applications-and-side-by-side-assemblies.md)<br/>
[Compilando aplicativos isolados do C/C++ e assemblies lado a lado](building-c-cpp-isolated-applications-and-side-by-side-assemblies.md)
