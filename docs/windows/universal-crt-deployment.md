---
title: Implantação do CRT Universal
ms.date: 05/11/2018
helpviewer_keywords:
- deploying the CRT [C++]
- application CRT deployment [C++]
ms.openlocfilehash: 7952d2ec6e8f502b0edf776811a492c67f495cce
ms.sourcegitcommit: 283cb64fd7958a6b7fbf0cd8534de99ac8d408eb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/28/2019
ms.locfileid: "64857238"
---
# <a name="universal-crt-deployment"></a>Implantação do CRT Universal

Do Visual Studio .NET ao Visual Studio 2013, cada versão principal das ferramentas e do compilador C++ incluía uma nova versão autônoma da biblioteca CRT (Tempo de Execução do Microsoft C). Essas versões autônomas do CRT eram independentes e, até certo ponto, incompatíveis entre si. Por exemplo, a biblioteca CRT usada pelo Visual Studio 2012 era a versão 11, chamada msvcr110.dll, e o CRT usado pelo Visual Studio 2013 era a versão 12, chamada msvcr120.dll. Do Visual Studio 2015 em diante, isso deixou de acontecer. O Visual Studio 2015 e todas as versões posteriores do Visual Studio usam um CRT Universal.

O CRT Universal é um componente do sistema operacional Microsoft Windows. Ele é incluído como parte do sistema operacional no Windows 10 e está disponível para sistemas operacionais mais antigos, Windows Vista por meio do Windows 8.1, usando o Windows Update. Além disso, há suporte para a implantação local do CRT Universal, com algumas restrições.

## <a name="central-deployment"></a>Implantação central

O método preferencial para instalar centralmente o CRT Universal é usar o Microsoft Windows Update. O CRT Universal é que uma atualização Recomendada para todos sistemas operacionais Microsoft Windows compatíveis e, assim, por padrão, a maioria dos computadores instala-o como parte do processo de atualização normal. A versão inicial do CRT Universal era [KB2999226](https://support.microsoft.com/kb/2999226); uma atualização seguinte com várias correções de bug foi feita em [KB3118401](https://support.microsoft.com/kb/3118401), e houve atualizações adicionais com novas funcionalidades e outras correções de bug. Para obter atualizações mais recentes, pesquise Tempo de Execução do C Universal ou CRT Universal em [support.microsoft.com](https://support.microsoft.com).

Nem todos os computadores Microsoft Windows instalam atualizações regularmente pelo uso do Windows Update, e alguns podem não instalar todas as atualizações Recomendadas. Para dar suporte ao uso de aplicativos compilados usando o Visual Studio 2015 e conjuntos de ferramentas C++ posteriores nesses computadores, há pacotes redistribuíveis do CRT Universal disponíveis para distribuição offline. Esses pacotes redistribuíveis podem ser baixados em um dos links da KB acima. Observe que os pacotes redistribuíveis do CRT Universal exigem que o computador tenha sido atualizado para o service pack atual. Assim, por exemplo, os pacotes redistribuíveis do Windows 7 serão instalados apenas no Windows 7 SP1, não no Windows 7 RTM.

Como o CRT Universal é uma dependência fundamental do C++ bibliotecas, o Visual C++ (VCRedist) redistribuível instala a versão inicial do CRT Universal (versão 10.0.10240) em computadores que não têm uma versão já instalada. Esta versão é suficiente para atender a C++ dependências de biblioteca. Se seu aplicativo depender de uma versão mais recente do CRT Universal, você deve usar o Windows Update para trazer o seu computador totalmente atualizada ou instalá-la explicitamente. É recomendável ter o tempo de execução C Universal já instalado via Windows Update ou por meio do MSU antes de instalar o VCRedist, para evitar o potencial de várias reinicializações necessárias.

Nem todos os sistemas operacionais são elegíveis para o mais recente Universal C Runtime por meio do Windows Update. No Windows 10, a versão implantada centralmente corresponde à versão do sistema operacional. Para atualizar o tempo de execução C Universal Além disso, você deve atualizar o sistema operacional. Para o Windows Vista por meio do Windows 8.1, o mais recente disponível Universal C Runtime no momento, com base na versão incluída na atualização de aniversário do Windows 10, com correções adicionais (versão 10.0.14393).

## <a name="local-deployment"></a>Implantação local

Há suporte para a implantação local do CRT Universal, mas isso não é recomendado por motivos de desempenho e de segurança.  As DLLs para implantação local são incluídas como parte do SDK do Windows no subdiretório Windows Kits\\10\\Redist\\ucrt\\DLLs, pela arquitetura do computador. As DLLs necessárias incluem ucrtbase.dll e um conjunto de DLLs do encaminhador de APISet denominado api-ms-win-\*.dll. O conjunto de DLLs necessário em cada sistema operacional varia. Portanto, é altamente recomendável incluir todas as DLLs ao usar a implantação local.

Há duas restrições na implantação local a serem consideradas:

- No Windows 10, o CRT Universal no diretório do sistema sempre é usado, mesmo se um aplicativo inclui uma cópia local do aplicativo do CRT Universal. Isso se aplica mesmo se a cópia local do CRT Universal é mais recente. Isso ocorre porque o CRT Universal é um componente principal do sistema operacional no Windows 10.

- Em versões do Windows anteriores ao Windows 8, o CRT Universal não pode ser empacotado localmente com um plug-in localizado em um diretório diferente do diretório que contém o executável principal do aplicativo. As DLLs do encaminhador de APISet não podem resolver a ucrtbase.dll com êxito nesse caso. Algumas soluções alternativas recomendadas incluem:

  - Vincular o CRT Universal estaticamente;
  - Implantar o CRT Universal centralmente; ou
  - Colocar os arquivos do CRT Universal no mesmo diretório do aplicativo.

## <a name="deployment-on-microsoft-windows-xp"></a>Implantação no Microsoft Windows XP

O Visual Studio 2015 e o Visual Studio 2017 continuam dando suporte ao desenvolvimento de software para uso no Microsoft Windows XP. Para dar suporte a esse recurso, uma versão do CRT Universal funciona no Microsoft Windows XP. O sistema operacional Microsoft Windows XP deixou de ter o suporte base ou estendido. Portanto, a implantação central do CRT Universal no Microsoft Windows XP é diferente de outros sistemas operacionais.

Quando o pacote redistribuível do Visual C++ é instalado no Windows XP, ele instala diretamente o CRT Universal e todas as suas dependências no diretório do sistema, sem instalar nenhum Windows Update nem depender de um. Os módulos de mesclagem dos Pacotes Redistribuíveis, os arquivos Microsoft_VC*version*_CRT_\*.msm, fazem o mesmo.

A implantação local do CRT Universal no Windows XP é a mesma usada nos sistemas operacionais compatíveis.

## <a name="see-also"></a>Consulte também

- [Implantação no Visual C++](deployment-in-visual-cpp.md)
