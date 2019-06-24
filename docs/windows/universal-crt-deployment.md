---
title: Implantação do CRT Universal
ms.date: 05/11/2018
helpviewer_keywords:
- deploying the CRT [C++]
- application CRT deployment [C++]
ms.openlocfilehash: 1f6e685cca65c4b31ac2e6147341c4b5a3fe8228
ms.sourcegitcommit: 6cf0c67acce633b07ff31b56cebd5de3218fd733
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 06/24/2019
ms.locfileid: "67344452"
---
# <a name="universal-crt-deployment"></a>Implantação do CRT Universal

Do Visual Studio .NET ao Visual Studio 2013, cada versão principal das ferramentas e do compilador C++ incluía uma nova versão autônoma da biblioteca CRT (Tempo de Execução do Microsoft C). Essas versões autônomas do CRT eram independentes e, até certo ponto, incompatíveis entre si. Por exemplo, a biblioteca CRT usada pelo Visual Studio 2012 era a versão 11, chamada msvcr110.dll, e o CRT usado pelo Visual Studio 2013 era a versão 12, chamada msvcr120.dll. A partir do Visual Studio 2015, ele não é mais o caso. O Visual Studio 2015 e todas as versões posteriores do Visual Studio usam um CRT Universal.

O CRT Universal é um componente do sistema operacional Microsoft Windows incluído como parte do sistema operacional no Windows 10. Ele está disponível para sistemas operacionais mais antigos, o Windows Vista por meio do Windows 8.1, usando o Windows Update. Implantação local do CRT Universal tem suporte, com algumas restrições.

## <a name="central-deployment"></a>Implantação central

O método preferencial para instalar centralmente o CRT Universal é usar o Microsoft Windows Update. O CRT Universal é que uma atualização Recomendada para todos sistemas operacionais Microsoft Windows compatíveis e, assim, por padrão, a maioria dos computadores instala-o como parte do processo de atualização normal. A versão inicial do CRT Universal estava [KB2999226](https://support.microsoft.com/kb/2999226). Uma atualização posterior com várias correções de bug foi feita na [KB3118401](https://support.microsoft.com/kb/3118401), e houve atualizações adicionais com ainda mais correções de bugs e novos recursos. Para obter atualizações mais recentes, pesquise Tempo de Execução do C Universal ou CRT Universal em [support.microsoft.com](https://support.microsoft.com).

Nem todos os computadores Microsoft Windows instalam atualizações regularmente pelo uso do Windows Update, e alguns podem não instalar todas as atualizações Recomendadas. Para dar suporte ao uso de aplicativos criados usando o Visual Studio 2015 e posteriores C++ conjuntos de ferramentas nessas máquinas, há arquivos redistribuíveis do CRT Universal disponíveis para distribuição offline. Esses arquivos redistribuíveis podem ser baixados em um dos links acima KB. Pacotes redistribuíveis do CRT Universal requer que a máquina foi atualizada para o service pack atual. Assim, por exemplo, os pacotes redistribuíveis do Windows 7 serão instalados apenas no Windows 7 SP1, não no Windows 7 RTM.

Como o CRT Universal é uma dependência fundamental do C++ bibliotecas, o Visual C++ (VCRedist) redistribuível instala a versão inicial do CRT Universal (versão 10.0.10240) em computadores que ainda não tem um instalado. Esta versão é suficiente para atender a C++ dependências de biblioteca. Se seu aplicativo depender de uma versão mais recente do CRT Universal, você deve usar o Windows Update para trazer o seu computador totalmente atualizada ou instalá-la explicitamente. É melhor instalar o tempo de execução C universais por meio do Windows Update ou um MSU antes de instalar o VCRedist, para evitar várias possíveis necessária é reinicializado.

Nem todos os sistemas operacionais são elegíveis para o mais recente Universal C Runtime por meio do Windows Update. No Windows 10, a versão implantada centralmente corresponde à versão do sistema operacional. Para atualizar o tempo de execução C Universal Além disso, você deve atualizar o sistema operacional. Para o Windows Vista por meio do Windows 8.1, o mais recente disponível Universal C Runtime no momento, com base na versão incluída na atualização de aniversário do Windows 10, com correções adicionais (versão 10.0.14393).

## <a name="local-deployment"></a>Implantação local

Há suporte para a implantação local do CRT Universal, mas isso não é recomendado por motivos de desempenho e de segurança. As DLLs para implantação local são incluídas como parte do SDK do Windows no subdiretório Windows Kits\\10\\Redist\\ucrt\\DLLs, pela arquitetura do computador. As DLLs necessárias incluem ucrtbase.dll e um conjunto de DLLs do encaminhador de APISet denominado api-ms-win-\*.dll. O conjunto de DLLs necessário em cada sistema operacional varia. É altamente recomendável que você inclua todas as DLLs ao implantar localmente.

Há duas restrições na implantação local a serem consideradas:

- No Windows 10, o CRT Universal no diretório do sistema sempre é usado, mesmo se um aplicativo inclui uma cópia local do aplicativo do CRT Universal. Ele é verdadeiro mesmo quando a cópia local é mais recente, como o CRT Universal é um componente do sistema operacional principal no Windows 10.

- Em versões do Windows anteriores ao Windows 8, o CRT Universal não pode ser empacotado localmente com um plug-in, se ele está localizado em um diretório que não seja o diretório do aplicativo principal do executável. As DLLs do encaminhador de APISet não podem resolver a ucrtbase.dll com êxito nesse caso. Algumas soluções alternativas recomendadas incluem:

  - Vincular o CRT Universal estaticamente;
  - Implantar o CRT Universal centralmente; ou
  - Colocar os arquivos do CRT Universal no mesmo diretório do aplicativo.

## <a name="deployment-on-microsoft-windows-xp"></a>Implantação no Microsoft Windows XP

O Visual Studio 2015 e o Visual Studio 2017 continuam dando suporte ao desenvolvimento de software para uso no Microsoft Windows XP. Para dar suporte a esse trabalho de desenvolvimento, uma versão do CRT Universal funcionam no Microsoft Windows XP. O sistema operacional Microsoft Windows XP deixou de ter o suporte base ou estendido. Portanto, a implantação central do CRT Universal no Microsoft Windows XP é diferente de outros sistemas operacionais.

Quando o Visual C++ redistribuível está instalado no Windows XP, ele instala diretamente o CRT Universal e todas as suas dependências no diretório do sistema. Ele não instalar ou depender de qualquer atualização do Windows. Os módulos de mesclagem dos Pacotes Redistribuíveis, os arquivos Microsoft_VC*version*_CRT_\*.msm, fazem o mesmo.

A implantação local do CRT Universal no Windows XP é a mesma usada nos sistemas operacionais compatíveis.

## <a name="see-also"></a>Consulte também

- [Implantação no Visual C++](deployment-in-visual-cpp.md)
