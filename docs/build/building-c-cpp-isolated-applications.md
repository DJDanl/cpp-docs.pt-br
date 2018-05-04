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
ms.openlocfilehash: 69de94159ef792aedff35efe81e8bb663d571105
ms.sourcegitcommit: be2a7679c2bd80968204dee03d13ca961eaa31ff
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/03/2018
---
# <a name="building-cc-isolated-applications"></a>Compilando aplicativos isolados do C/C++
Um aplicativo isolado depende apenas assemblies lado a lado e associa a suas dependências usando um manifesto. Não é necessário para seu aplicativo deve ser totalmente isolado para executar corretamente no Windows. No entanto, investindo em tornar seu aplicativo totalmente isolado, você pode economizar tempo se você precisar manter seu aplicativo no futuro. Para obter mais informações sobre as vantagens de seu aplicativo totalmente isolado, consulte [aplicativos isolados](http://msdn.microsoft.com/library/aa375190).  
  
 Quando você criar seu aplicativo C/C++ nativo usando o Visual C++, por padrão, o Visual Studio, o sistema de projeto gera um arquivo de manifesto que descreve as dependências do seu aplicativo em bibliotecas do Visual C++. Se essas são as dependências somente tem seu aplicativo, em seguida, ele se torna um aplicativo isolado assim que ele é recriado com o Visual Studio. Se seu aplicativo estiver usando outras bibliotecas em tempo de execução, talvez você precise recriar essas bibliotecas como assemblies lado a lado seguindo as etapas descritas em [criando conjuntos de C/C++-lado a lado](../build/building-c-cpp-side-by-side-assemblies.md).  
  
## <a name="see-also"></a>Consulte também  
 [Conceitos de aplicativos isolados e Assemblies lado a lado](../build/concepts-of-isolated-applications-and-side-by-side-assemblies.md)   
 [Compilando aplicativos isolados do C/C++ e assemblies lado a lado](../build/building-c-cpp-isolated-applications-and-side-by-side-assemblies.md)