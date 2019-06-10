---
title: Compatibilidade binária de C++ entre o Visual Studio 2015 e o Visual Studio 2019
ms.date: 05/03/2019
helpviewer_keywords:
- binary compatibility, Visual C++
ms.assetid: 591580f6-3181-4bbe-8ac3-f4fbaca949e6
ms.openlocfilehash: 052874eb9273ee9a9ce1695ffdadedd9911673e1
ms.sourcegitcommit: 7d64c5f226f925642a25e07498567df8bebb00d4
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/08/2019
ms.locfileid: "65449040"
---
# <a name="c-binary-compatibility-between-visual-studio-2015-and-visual-studio-2019"></a>Compatibilidade binária de C++ entre o Visual Studio 2015 e o Visual Studio 2019

No Visual Studio 2013 e em versões anteriores, não havia garantia de compatibilidade binária entre arquivos-objetos (OBJs), bibliotecas estáticas (LIBs), bibliotecas dinâmicas (DLLs) e executáveis (EXEs) compilados com versões diferentes do conjunto de ferramentas do compilador e das bibliotecas de tempo de execução. 

No Visual Studio 2015 e posteriores, o número principal do conjunto de ferramentas do C++ é 14 (v140 para Visual Studio 2015, v141 para Visual Studio 2017 e v142 para Visual Studio 2019). Isso reflete o fato de que tanto as bibliotecas de tempo de execução quanto os aplicativos compilados com uma das versões do compilador apresentam compatibilidade binária. Isso significa que, se você tiver uma biblioteca de terceiros que foi criada com o Visual Studio 2015, você não precisará recompilá-la a fim de consumi-la de um aplicativo criado com o Visual Studio 2017 ou com o Visual Studio 2019.

A única exceção a essa regra é que as bibliotecas estáticas ou os arquivos-objeto são compilados com o comutador de compilador `/GL` que não apresenta compatibilidade binária. 

Quando você mistura binários criados com diferentes versões com suporte do conjunto de ferramentas do MSVC, redistribuível do Visual C++ no qual o aplicativo é executado não pode ser mais antigo do que qualquer uma das versões de conjunto de ferramentas usadas para criar seu aplicativo ou as bibliotecas que ele consome. 

## <a name="see-also"></a>Consulte também

[Histórico de alterações do Visual C++](../porting/visual-cpp-change-history-2003-2015.md)
