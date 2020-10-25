---
title: Implantação do CRT Universal
description: Saiba como, quando e onde implantar a biblioteca CRT universal para seu aplicativo.
ms.date: 10/23/2020
helpviewer_keywords:
- deploying the CRT [C++]
- application CRT deployment [C++]
ms.openlocfilehash: 50ab23f3b0276b058685e9c9ef6634caf5a96186
ms.sourcegitcommit: bf54b407169900bb668c85a67b31dbc0f069fe65
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2020
ms.locfileid: "92497205"
---
# <a name="universal-crt-deployment"></a>Implantação do CRT Universal

Do Visual Studio .NET ao Visual Studio 2013, cada versão principal das ferramentas e do compilador C++ incluía uma nova versão autônoma da biblioteca CRT (Runtime do Microsoft C). Essas versões autônomas do CRT eram independentes e, até certo ponto, incompatíveis entre si. Por exemplo, a biblioteca CRT usada pelo Visual Studio 2012 era a versão 11, chamada msvcr110.dll, e o CRT usado pelo Visual Studio 2013 era a versão 12, chamada msvcr120.dll. A partir do Visual Studio 2015, não é mais o caso. O Visual Studio 2015 e todas as versões posteriores do Visual Studio usam um CRT Universal.

O CRT (UCRT) universal é um componente do sistema operacional Microsoft Windows. Ele é incluído como parte do sistema operacional no Windows 10 e no Windows Server 2016 ou posterior. O UCRT está disponível usando Windows Update em sistemas operacionais mais antigos que ainda estão no suporte estendido. Há suporte para a implantação local do CRT universal, com algumas restrições.

## <a name="central-deployment"></a>Implantação central

O método preferencial para instalar centralmente o CRT Universal é usar o Microsoft Windows Update. O CRT Universal é que uma atualização Recomendada para todos sistemas operacionais Microsoft Windows compatíveis e, assim, por padrão, a maioria dos computadores instala-o como parte do processo de atualização normal. A versão inicial do CRT universal era [KB2999226](https://support.microsoft.com/kb/2999226). Uma atualização posterior com várias correções de bugs foi feita em [KB3118401](https://support.microsoft.com/kb/3118401), e houve atualizações adicionais com correções de bugs e novos recursos. Para obter atualizações mais recentes, pesquise Runtime do C Universal ou CRT Universal em [support.microsoft.com](https://support.microsoft.com).

Nem todos os computadores Microsoft Windows instalam atualizações regularmente pelo uso do Windows Update, e alguns podem não instalar todas as atualizações Recomendadas. Para dar suporte ao uso de aplicativos criados usando o Visual Studio 2015 e os conjuntos de ferramentas do C++ posteriores nessas máquinas, há arquivos redistribuíveis do CRT universal disponíveis para distribuição offline. Esses arquivos redistribuíveis podem ser baixados de um dos links de KB acima. O universal CRT redistribuível requer que o computador tenha sido atualizado para a service pack atual. Assim, por exemplo, os pacotes redistribuíveis do Windows 7 serão instalados apenas no Windows 7 SP1, não no Windows 7 RTM.

Como o CRT universal é uma dependência fundamental das bibliotecas C++, o Visual C++ redistribuível (VCRedist) instala a versão inicial do CRT universal (versão 10.0.10240) em computadores que ainda não têm um instalado. Esta versão é suficiente para atender às dependências da biblioteca C++. Se seu aplicativo depende de uma versão mais recente do CRT universal, você deve usar Windows Update para colocar seu computador totalmente atualizado ou instalar essa versão explicitamente. É melhor instalar o tempo de execução C universal via Windows Update ou uma MSU antes de instalar o VCRedist, para evitar possíveis reinicializações necessárias.

Nem todos os sistemas operacionais estão qualificados para o tempo de execução universal C mais recente via Windows Update. No Windows 10, a versão implantada centralmente corresponde à versão do sistema operacional. Para atualizar o tempo de execução universal C, você deve atualizar o sistema operacional. Para o Windows Vista por meio do Windows 8.1, o tempo de execução universal C mais recente disponível atualmente é baseado na versão incluída na atualização de aniversário do Windows 10, com correções adicionais (versão 10.0.14393).

## <a name="local-deployment"></a>Implantação local

Há suporte para a implantação local do CRT Universal, mas isso não é recomendado por motivos de desempenho e de segurança. As DLLs para implantação local são incluídas como parte do SDK do Windows no subdiretório Windows Kits\\10\\Redist\\ucrt\\DLLs, pela arquitetura do computador. As DLLs necessárias incluem ucrtbase.dll e um conjunto de DLLs do encaminhador de APISet denominado api-ms-win-\*.dll. O conjunto de DLLs necessário em cada sistema operacional varia. É altamente recomendável que você inclua todas as DLLs ao implantar localmente.

Há duas restrições na implantação local a serem consideradas:

- No Windows 10, o CRT Universal no diretório do sistema sempre é usado, mesmo se um aplicativo inclui uma cópia local do aplicativo do CRT Universal. É verdade mesmo quando a cópia local é mais recente, porque o CRT universal é um componente principal do sistema operacional no Windows 10.

- Nas versões do Windows anteriores ao Windows 8, o CRT universal não pode ser empacotado localmente com um plug-in, se estiver localizado em um diretório diferente do diretório do executável do aplicativo principal. As DLLs do encaminhador de APISet não podem resolver a ucrtbase.dll com êxito nesse caso. Algumas soluções alternativas recomendadas incluem:

  - Vincular o CRT Universal estaticamente;
  - Implantar o CRT Universal centralmente; ou
  - Colocar os arquivos do CRT Universal no mesmo diretório do aplicativo.

## <a name="deployment-on-microsoft-windows-xp"></a>Implantação no Microsoft Windows XP

O Visual Studio 2015 e o Visual Studio 2017 continuam dando suporte ao desenvolvimento de software para uso no Microsoft Windows XP. Para dar suporte a esse desenvolvimento, uma versão do CRT universal funciona no Microsoft Windows XP. O sistema operacional Microsoft Windows XP deixou de ter o suporte base ou estendido. Portanto, a implantação central do CRT Universal no Microsoft Windows XP é diferente de outros sistemas operacionais.

Quando o Visual C++ redistribuível é instalado no Windows XP, ele instala diretamente o CRT universal e todas as suas dependências no diretório do sistema. Ele não é instalado nem depende de nenhum Windows Update. Os módulos de mesclagem dos Pacotes Redistribuíveis, os arquivos Microsoft_VC*version*_CRT_\*.msm, fazem o mesmo.

A implantação local do CRT Universal no Windows XP é a mesma usada nos sistemas operacionais compatíveis.

## <a name="see-also"></a>Confira também

- [Implantação no Visual C++](deployment-in-visual-cpp.md)
