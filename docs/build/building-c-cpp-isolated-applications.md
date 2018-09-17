---
title: Compilando aplicativos isolados C/C++ | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-tools
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- isolated applications [C++]
ms.assetid: 8a2fe4fa-0489-433e-bfc6-495844d8d73a
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 78d14f812700afa4ea0ad66b527a0e3888862f4d
ms.sourcegitcommit: 92f2fff4ce77387b57a4546de1bd4bd464fb51b6
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/17/2018
ms.locfileid: "45716892"
---
# <a name="building-cc-isolated-applications"></a>Compilando aplicativos isolados do C/C++

Um aplicativo isolado depende somente assemblies lado a lado e associa a suas dependências usando um manifesto. Não é necessário para seu aplicativo para ser totalmente isolados para executar corretamente no Windows; No entanto, ao investir em tornar seu aplicativo totalmente isolado, você pode economizar tempo se você precisar manter seu aplicativo no futuro. Para obter mais informações sobre as vantagens de fazer seu aplicativo totalmente isolado, consulte [aplicativos isolados](/windows/desktop/SbsCs/isolated-applications).

Quando você compila seu aplicativo C/C++ nativo usando o Visual C++, por padrão, o Visual Studio, o sistema de projeto gera um arquivo de manifesto que descreve as dependências do aplicativo em bibliotecas do Visual C++. Se essas são as dependências apenas seu aplicativo tiver, ele se tornará um aplicativo isolado, assim que ele é recriado com o Visual Studio. Se seu aplicativo estiver usando outras bibliotecas em tempo de execução, talvez seja necessário recriar essas bibliotecas como assemblies lado a lado seguindo as etapas descritas em [criando conjuntos de C/C++ lado a lado](../build/building-c-cpp-side-by-side-assemblies.md).

## <a name="see-also"></a>Consulte também

[Conceitos de aplicativos isolados e assemblies lado a lado](../build/concepts-of-isolated-applications-and-side-by-side-assemblies.md)<br/>
[Compilando aplicativos isolados do C/C++ e assemblies lado a lado](../build/building-c-cpp-isolated-applications-and-side-by-side-assemblies.md)