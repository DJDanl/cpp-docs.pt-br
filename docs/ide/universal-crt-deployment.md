---
title: Implantação do Universal CRT | Microsoft Docs
ms.custom: ''
ms.date: 05/11/2018
ms.technology:
- cpp-ide
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- deploying the CRT [C++]
- application CRT deployment [C++]
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 20006118d4bf27c379b78b84dc8807a4fd6c5e6c
ms.sourcegitcommit: 19a108b4b30e93a9ad5394844c798490cb3e2945
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/17/2018
---
# <a name="universal-crt-deployment"></a>Implantação do Universal CRT

Do Visual Studio .NET por meio do Visual Studio 2013, cada versão principal do compilador C++ e ferramentas inclui uma versão autônoma novo da biblioteca do Microsoft C Runtime (CRT). Essas versões autônomas do CRT eram independentes de e para vários graus, incompatíveis entre si. Por exemplo, a biblioteca CRT usada pelo Visual Studio 2012 foi msvcr110.dll de nomeada 11, versão e CRT usado pelo Visual Studio 2013 foi msvcr120.dll nomeado 12, de versão. A partir do Visual Studio 2015, isso não é mais o caso. Visual Studio 2015 e versões posteriores do Visual Studio usam um Universal CRT.

O Universal CRT é um componente do sistema operacional Microsoft Windows. Ele é incluído como parte do sistema operacional no Windows 10 e está disponível para sistemas operacionais mais antigos, o Windows Vista por meio do Windows 8.1, usando o Windows Update. Além disso, a implantação local do CRT Universal tem suporte, com algumas restrições.

## <a name="central-deployment"></a>Implantação central

É o método preferencial para instalar centralmente o Universal CRT usar o Microsoft Windows Update. O Universal CRT é que uma atualização recomendado para todos com suporte a sistemas operacionais Microsoft Windows, por que padrão, a maioria das máquinas instalação-lo como parte do processo de atualização regular. A versão inicial do Universal CRT foi [KB2999226](https://support.microsoft.com/en-us/kb/2999226); uma atualização subsequente com várias correções de bugs foram feita em [KB3118401](https://support.microsoft.com/en-us/kb/3118401), e foram atualizações adicionais com novos recursos e correções de bugs adicionais. Para obter atualizações mais recentes, procure [support.microsoft.com](https://support.microsoft.com) para o tempo de execução C Universal ou Universal CRT.

Nem todos os computadores com Microsoft Windows instalam atualizações regularmente pelo uso do Windows Update, e alguns não podem instalar todas as atualizações recomendadas. Para dar suporte ao uso de aplicativos criado usando o Visual Studio 2015 e conjuntos de ferramentas posteriores C++ nessas máquinas, há redistribuíveis do CRT Universal disponíveis para distribuição offline. Esses redistribuíveis podem ser baixados em um dos links acima KB. Observe que o Universal CRT redistribuíveis requerem que a máquina foi atualizada para o service pack atual. Assim, por exemplo, os pacotes redistribuíveis do Windows 7 serão instalado somente no Windows 7 SP1, não o Windows 7 RTM.

Como o Universal CRT é uma dependência fundamental das bibliotecas do C++, Visual C++ redistribuível (VCRedist) instala a versão base do CRT Universal em computadores que não têm uma versão já instalada, suficiente para atender a biblioteca C++ dependências. Se seu aplicativo depende de uma versão mais recente do CRT Universal, instale explicitamente que a versão mais recente. É melhor para instalá-lo antes de instalar o VCRedist, para evitar várias possíveis necessária reinicializa.

## <a name="local-deployment"></a>Implantação local

Implantação local do CRT Universal é aceito, mas não recomendada por motivos de segurança e de desempenho.  As DLLs de implantação local são incluídas como parte do SDK do Windows no Windows Kits\\10\\Redist\\ucrt\\subdiretório DLLs, pela arquitetura do computador. As DLLs necessárias incluem ucrtbase.dll e um conjunto de encaminhador APISet DLLs denominados api-ms-win -\*. dll. O conjunto de DLLs necessárias em cada sistema operacional varia, portanto, é altamente recomendável que você incluir todas as DLLs quando você implanta localmente.

Há duas restrições na implantação local a serem consideradas:

- No Windows 10, o Universal CRT no diretório do sistema sempre é usado, mesmo se um aplicativo inclui uma cópia local do aplicativo do CRT Universal. Isso é verdadeiro mesmo se a cópia local do CRT Universal é mais recente. Isso ocorre porque o Universal CRT é um componente do sistema operacional principal no Windows 10.

- Em versões do Windows anteriores ao Windows 8, o Universal CRT não podem ser compactado localmente com um plug-in que está localizado em um diretório diferente do diretório que contém o executável principal de seu aplicativo. O encaminhador de APISet DLLs são não é possível resolver o ucrtbase.dll com êxito nesse caso. Algumas soluções alternativas recomendadas incluem:

  - O Universal CRT, a vinculação estática
  - Implantar centralmente o Universal CRT, ou
  - Coloque os arquivos do CRT Universal no mesmo diretório que o aplicativo.

## <a name="deployment-on-microsoft-windows-xp"></a>Implantação no Microsoft Windows XP

O Visual Studio 2015 e o Visual Studio de 2017 continuam a oferecer suporte ao desenvolvimento de software para uso no Microsoft Windows XP. Para dar suporte a isso, uma versão do CRT Universal funciona no Microsoft Windows XP. O sistema operacional Microsoft Windows XP não está mais em suporte estendido ou base, por implantação central do CRT Universal no Microsoft Windows XP é diferente de outros sistemas operacionais.

Quando o Visual C++ redistributable é instalado no Windows XP, ele diretamente instala o Universal CRT e todas as suas dependências no diretório do sistema, sem instalar ou dependendo qualquer atualização do Windows. Os módulos de mesclagem redistribuíveis, o Microsoft_VC*versão*_CRT_\*arquivos. msm, faça o mesmo.

Implantação local do CRT Universal no Windows XP é o mesmo em sistemas operacionais com suporte.

## <a name="see-also"></a>Consulte também

- [Implantação no Visual C++](deployment-in-visual-cpp.md)
