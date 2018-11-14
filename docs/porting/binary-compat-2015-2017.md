---
title: Compatibilidade binária de C++ entre o Visual Studio 2015 e o Visual Studio 2017
ms.date: 09/24/2018
helpviewer_keywords:
- binary compatibility, Visual C++
ms.assetid: 591580f6-3181-4bbe-8ac3-f4fbaca949e6
ms.openlocfilehash: e526002bdca0eee122531f39c195aef3474cc61c
ms.sourcegitcommit: 1819bd2ff79fba7ec172504b9a34455c70c73f10
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 11/09/2018
ms.locfileid: "51329820"
---
# <a name="c-binary-compatibility-between-visual-studio-2015-and-visual-studio-2017"></a>Compatibilidade binária de C++ entre o Visual Studio 2015 e o Visual Studio 2017

Em versões anteriores do Visual Studio, não havia garantia de compatibilidade binária entre arquivo-objetos (OBJs), bibliotecas estáticas (LIBs), bibliotecas dinâmicas (DLLs) e executáveis (EXEs) compilados com versões diferentes do conjunto de ferramentas do computador e das bibliotecas de tempo de execução. Isso mudou no Visual Studio 2017. No Visual Studio 2015 e no Visual Studio 2017, o número principal do conjunto de ferramentas do C++ é 14 (v140 para Visual Studio 2015 e v141 para Visual Studio 2017). Isso reflete o fato de que tanto as bibliotecas de tempo de execução quanto os aplicativos compilados com uma das versões do compilador apresentam, em grande parte, compatibilidade binária. Por exemplo, isso significa que, se você tiver uma DLL no Visual Studio 2015, não será possível recompilá-la para consumi-la em um aplicativo criado com o Visual Studio 2017.

Há duas exceções a essa regra. Não há garantia de compatibilidade binária nesses casos:

1. Quando as bibliotecas estáticas ou os arquivos de objeto são compilados com a opção do compilador `/GL`.

2. Ao consumir bibliotecas criadas com um conjunto de ferramentas cuja versão é maior que o conjunto de ferramentas usado para compilar e vincular o aplicativo. Por exemplo, um programa compilado e vinculado com a versão do compilador 19.12 pode consumir bibliotecas compiladas com as versões de 19.0 até 19.12. Além disso, a compatibilidade binária só existe entre o Visual Studio 2015 e o Visual Studio 2017. Não há suporte para a vinculação de programas 19.x com bibliotecas produzidas pelo Visual Studio 2013 ou anterior.

## <a name="see-also"></a>Consulte também

[Histórico de alterações do Visual C++](../porting/visual-cpp-change-history-2003-2015.md)
