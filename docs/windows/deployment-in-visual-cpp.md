---
title: Implantação no Visual C++
ms.date: 05/11/2018
helpviewer_keywords:
- deploying applications [C++]
- application deployment [C++]
ms.assetid: d4b4ffc0-d2bd-4e4a-84a6-62f1c26f6a09
ms.openlocfilehash: 8dccf581cff88dc2e8c4a889bed8b47fc140eb7c
ms.sourcegitcommit: 72583d30170d6ef29ea5c6848dc00169f2c909aa
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/18/2019
ms.locfileid: "58786123"
---
# <a name="deployment-in-visual-c"></a>Implantação no Visual C++

A instalação do aplicativo em um computador diferente do computador de desenvolvimento é conhecida como *implantação*. Ao implantar um aplicativo do Visual C++ em outro computador, é necessário instalar o aplicativo e os arquivos de biblioteca dos quais ele depende. O Visual Studio possibilita três maneiras de implantação das bibliotecas do Visual C++, junto com o aplicativo: *implantação central*, *implantação local* e *vinculação estática*. A implantação central coloca os arquivos de biblioteca no diretório do Windows, no qual o serviço Windows Update pode atualizá-los automaticamente. A implantação local coloca os arquivos de biblioteca no mesmo diretório do aplicativo. É necessário reimplantar as bibliotecas implantadas localmente para atualizá-las. A vinculação estática associa o código de biblioteca ao aplicativo. É necessário recompilar e reimplantar o aplicativo para aproveitar as atualizações nas bibliotecas ao usar a vinculação estática.

No Visual Studio 2015, a biblioteca de Tempo de Execução do Microsoft C foi refatorada em componentes da biblioteca local específicos à uma versão e em uma nova biblioteca de Tempo de Execução do C Universal, que agora faz parte do Windows. Para obter detalhes sobre a implantação do CRT Universal, confira [Implantação do CRT Universal](universal-crt-deployment.md).

## <a name="central-deployment"></a>Implantação central

Na implantação central, os arquivos DLL da biblioteca são instalados no diretório Windows\System32, ou para arquivos de biblioteca de 32 bits em sistemas x64, no diretório Windows\SysWow64. A Microsoft atualiza automaticamente as bibliotecas que são implantadas centralmente. Para as bibliotecas do Visual C++ que são implantadas localmente ou vinculadas estaticamente, é necessário fornecer as atualizações.

Para implantar centralmente as bibliotecas do Visual C++, use uma destas duas fontes para a instalação dos arquivos:

- Arquivos de *pacote redistribuível*, executáveis de linha de comando autônomo que contêm todas as bibliotecas redistribuíveis do Visual C++ em formato compactado, ou

- *Módulos de mesclagem redistribuíveis* (arquivos .msm), que podem ser usados para implantar bibliotecas específicas e que são incluídos no arquivo do Windows Installer (.msi) do aplicativo.

Um arquivo de pacote redistribuível instala todas as bibliotecas do Visual C++ de uma arquitetura de sistema específica. Por exemplo, se o aplicativo é compilado para x64, você pode usar o pacote redistribuível vcredist_x64.exe para instalar todas as bibliotecas do Visual C++ usadas pelo aplicativo. Programe o instalador do aplicativo para executar o pacote redistribuível como um pré-requisito antes de instalar o aplicativo.

Um módulo de mesclagem permite a inclusão da lógica de configuração para uma biblioteca específica do Visual C++ em um arquivo de instalação de aplicativo do Windows Installer. Você pode incluir a quantidade de módulos de mesclagem necessária para seu aplicativo. Use módulos de mesclagem quando precisar minimizar o tamanho dos binários de implantação.

Como a implantação central com o uso de um pacote redistribuível ou de módulos de mesclagem permite que o Windows Update atualize as bibliotecas do Visual C++ automaticamente, recomendamos que você use as DLLs da biblioteca em seu aplicativo, no lugar das bibliotecas estáticas, e a implantação central, em vez da implantação local.

## <a name="local-deployment"></a>Implantação local

Na implantação local, os arquivos de biblioteca são instalados na pasta do aplicativo junto com o arquivo executável. Diferentes versões de bibliotecas redistribuíveis do Visual C++ podem ser instaladas na mesma pasta, pois o nome de arquivo de cada versão inclui seu número de versão. Por exemplo, a versão 12 da biblioteca de tempo de execução do C++ é msvcp120.dll e a versão 14 é msvcp140.dll.

Uma biblioteca pode ser distribuída em várias DLLs adicionais, conhecidas como *bibliotecas dot*. Por exemplo, algumas funcionalidades da biblioteca padrão liberadas no Visual Studio 2017 versão 15.6 foram adicionadas em msvcp140_1.dll, para preservar a compatibilidade com o ABI de msvcp140.dll. Caso você use o Visual Studio 2017 versão 15.6 (conjunto de ferramentas 14.13) ou um conjunto de ferramentas posterior do Visual Studio 2017, precisará implantar essas bibliotecas dot localmente, bem como a biblioteca principal. Essas bibliotecas dot separadas são então distribuídas para a próxima versão principal da biblioteca base, no momento em que a ABI é alterada.

Como a Microsoft não pode atualizar de forma automática as bibliotecas do Visual C++ implantadas localmente, não recomendamos a implantação local dessas bibliotecas. Se você decidir usar a implantação local de bibliotecas redistribuíveis, recomendamos implementar seu próprio método de atualização automática das bibliotecas localmente implantadas.

## <a name="static-linking"></a>Vinculação estática

Além das bibliotecas de vínculo dinâmico, o Visual Studio fornece a maioria de suas bibliotecas como bibliotecas estáticas. Você pode vincular estaticamente uma biblioteca estática ao aplicativo, ou seja, vincular o código de objeto de biblioteca diretamente ao aplicativo. Isso cria um único binário sem uma dependência de DLL, de modo que você não precise implantar os arquivos de biblioteca do Visual C++ separadamente. No entanto, não recomendamos o uso dessa abordagem, porque as bibliotecas de vínculo estático não podem ser atualizadas in-loco. Se você usar a vinculação estática e quiser atualizar uma biblioteca vinculada, precisará recompilar e reimplantar seu aplicativo.

## <a name="troubleshooting-deployment-issues"></a>Solução de problemas de implantação

A ordem de carregamento das bibliotecas do Visual C++ é dependente do sistema. Para diagnosticar problemas do carregador, use depends.exe ou where.exe. Para obter mais informações, confira [Ordem de pesquisa das bibliotecas de vínculo dinâmico (Windows)](/windows/desktop/Dlls/dynamic-link-library-search-order).

## <a name="see-also"></a>Consulte também

- [Implantando aplicativos da área de trabalho](deploying-native-desktop-applications-visual-cpp.md)
- [Implantação do Universal CRT](universal-crt-deployment.md)
