---
title: Escolhendo uma método de implantação
ms.date: 03/14/2019
helpviewer_keywords:
- redistributing DLLs
- manifests [C++]
- DLLs [C++], redistributing
- side-by-side assemblies [C++]
- dynamic linking [C++]
- application deployment [C++], methods
- deploying applications [C++], methods
- static linking [C++]
- libraries [C++], application deployment issues
ms.assetid: fd8eb956-f4a0-4ffb-b401-328c73e66986
ms.openlocfilehash: 5ca1f33a809bc81b7dcc090231e507ba66775205
ms.sourcegitcommit: 72583d30170d6ef29ea5c6848dc00169f2c909aa
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/18/2019
ms.locfileid: "58786164"
---
# <a name="choosing-a-deployment-method"></a>Escolhendo uma método de implantação

A menos que seu aplicativo do Visual C++ seja autossuficiente e possa ser implantado usando um comando de cópia, recomendamos que você use o Windows Installer para a implantação. O Windows Installer oferece suporte à instalação, ao reparo e à desinstalação, e também oferece suporte à atualização atômica dos arquivos de aplicativo, dependências e das entradas do Registro.

> [!NOTE]
>  Embora a implantação do [ClickOnce](/visualstudio/deployment/clickonce-security-and-deployment) para aplicativos nativos do Visual C++ seja possível no Visual Studio, ela exige etapas extras. Para obter mais informações, confira [Implantação do ClickOnce para aplicativos do Visual C++](clickonce-deployment-for-visual-cpp-applications.md).

## <a name="visual-c-libraries-are-shared-dlls"></a>As bibliotecas do Visual C++ são DLLs compartilhadas

Como as bibliotecas do Visual C++ são instaladas no diretório %windir%\system32\ pelo instalador do Visual Studio, quando você desenvolve um aplicativo do Visual C++ que depende delas, ele será executado como esperado. No entanto, para implantar o aplicativo em computadores que podem não ter o Visual Studio, recomendamos que você verifique se as bibliotecas foram instaladas nesses computadores junto com o aplicativo.

## <a name="redistributing-visual-c-libraries"></a>Redistribuindo bibliotecas do Visual C++

Em suas implantações, você pode redistribuir qualquer versão de uma biblioteca do Visual C++ que é licenciada para redistribuição. Estas são três maneiras de implantá-las:

- Implantação central usando pacotes redistribuíveis, que instalam bibliotecas do Visual C++ como DLLs compartilhadas em %windir%\system32\\. (A instalação nessa pasta exige direitos de administrador.) Você pode criar um script ou um programa de instalação que execute o pacote redistribuível antes de instalar seu aplicativo no computador de destino. Os pacotes redistribuíveis estão disponíveis para as plataformas x86, x64 e ARM (VCRedist_x86.exe, VCRedist_x64.exe ou VCRedist_arm.exe). O Visual Studio inclui esses pacotes em %ProgramFiles(x86)%\Microsoft Visual Studio `version`\VC\Redist\\`locale ID`\\. Baixe-os também no [Centro de Download da Microsoft](https://www.microsoft.com/download). (Use a caixa de pesquisa no Centro de Download para pesquisar o "Pacote Redistribuível do Visual C++ *versão do Visual Studio e atualização*" que corresponde ao seu aplicativo. Por exemplo, se você usou o Visual Studio 2015 atualização 3 para compilar o aplicativo, pesquise "Pacote Redistribuível do Visual C++ 2015 atualização 3".) Para obter informações sobre como usar um pacote redistribuível, confira [Passo a passo: Implantação de um aplicativo em Visual C++ usando o Pacote Redistribuível do Visual C++](deploying-visual-cpp-application-by-using-the-vcpp-redistributable-package.md).

- Implantação central usando módulos de mesclagem, em que cada um instala uma biblioteca específica do Visual C++ como uma DLL compartilhada em %windir%\system32\\. (A instalação nessa pasta exige direitos de administrador.) Os módulos de mesclagem se tornam parte do arquivo do instalador .msi de seu aplicativo. Os módulos de mesclagem redistribuíveis do Visual C++ são incluídos no Visual Studio, em \Arquivos de Programas (x86)\Common Files\Merge Modules\\. Para obter mais informações, confira [Redistribuindo componentes usando módulos de mesclagem](redistributing-components-by-using-merge-modules.md).

- Implantação local, em que você copia DLLs específicas do Visual C++ da instalação do Visual Studio – normalmente em \Arquivos de Programas (x86)\Microsoft Visual Studio `version`\VC\Redist\\`platform`\\`library`\ – e as instala nos computadores de destino na mesma pasta do executável do aplicativo. Você pode usar esse método de implantação para habilitar a instalação pelos usuários que não têm direitos de administrador ou para aplicativos que podem ser executados a partir de um compartilhamento de rede.

Se uma implantação usar módulos de mesclagem redistribuíveis e uma instalação for executada por um usuário que não tem direitos administrativos, as DLLs do Visual C++ não serão instaladas e o aplicativo não será executado. Além disso, instaladores de aplicativos compilados com módulos de mesclagem que permitem a instalação por usuário instalam as bibliotecas em um local compartilhado que afeta todos os usuários do sistema. Use a implantação local para instalar as DLLs necessárias do Visual C++ no diretório do aplicativo de um usuário específico sem afetar outros usuários nem exigir direitos de administrador. Como isso pode criar problemas de capacidade de serviço, não recomendamos a implantação local de DLLs redistribuíveis do Visual C++.

A implantação incorreta de bibliotecas do Visual C++ pode causar erros de tempo de execução durante a execução de um aplicativo que dependem delas. Quando o sistema operacional carrega o aplicativo, ele usa a ordem de pesquisa descrita em [LoadLibraryEx](/windows/desktop/api/libloaderapi/nf-libloaderapi-loadlibraryexw).

## <a name="dynamic-linking-is-better-than-static-linking"></a>A vinculação dinâmica é melhor que a vinculação estática

Recomendamos que você evite usar a vinculação estática ao redistribuir bibliotecas do Visual C++. Embora a vinculação estática quase nunca melhora significativamente o desempenho do aplicativo, quase sempre torna a manutenção mais cara. Por exemplo, considere um aplicativo que seja vinculado estaticamente a uma biblioteca que é atualizado com aprimoramentos de segurança – o aplicativo não pode se beneficiar, a menos que seja recompilado e reimplantado. Em vez disso, recomendamos que você vincule dinamicamente seus aplicativos às bibliotecas de que eles dependem para que as bibliotecas possam ser atualizadas sempre que implantadas.

## <a name="see-also"></a>Consulte também

[Implantando aplicativos da área de trabalho](deploying-native-desktop-applications-visual-cpp.md)<br>
[Segurança e implantação do ClickOnce](/visualstudio/deployment/clickonce-security-and-deployment)<br>
[Exemplos de implantação](deployment-examples.md)
