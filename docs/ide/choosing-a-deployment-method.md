---
title: "Escolhendo um método de implantação | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-ide
ms.tgt_pltfrm: 
ms.topic: article
dev_langs:
- C++
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
caps.latest.revision: 
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 4e4336f200f736ea7656af11c7c7c43ca32f27f9
ms.sourcegitcommit: 185e11ab93af56ffc650fe42fb5ccdf1683e3847
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 01/29/2018
---
# <a name="choosing-a-deployment-method"></a>Escolhendo uma método de implantação
A menos que seu aplicativo do Visual C++ é independente e pode ser implantado por meio de um comando de cópia, recomendamos que você use o Windows Installer para implantação. O Windows Installer oferece suporte à instalação, ao reparo e à desinstalação, e também oferece suporte à atualização atômica dos arquivos de aplicativo, dependências e das entradas do Registro.  
  
> [!NOTE]
>  Embora [ClickOnce](/visualstudio/deployment/clickonce-security-and-deployment) implantação para aplicativos nativos do Visual C++ é possível no Visual Studio, ele requer etapas adicionais. Para obter mais informações, consulte [implantação de ClickOnce para aplicativos Visual C++](../ide/clickonce-deployment-for-visual-cpp-applications.md).  
  
## <a name="visual-c-libraries-are-shared-dlls"></a>As bibliotecas do Visual C++ são DLLs compartilhadas  
 Como as bibliotecas do Visual C++ são instaladas no diretório %windir%\system32\ pelo instalador do Visual Studio, quando você desenvolve um aplicativo do Visual C++ que depende delas, ele será executado como esperado. No entanto, para implantar o aplicativo em computadores que podem não ter o Visual Studio, recomendamos que você verifique se as bibliotecas foram instaladas nesses computadores junto com o aplicativo.  
  
## <a name="redistributing-visual-c-libraries"></a>Redistribuindo bibliotecas do Visual C++  
 Em suas implantações, você pode redistribuir qualquer versão de uma biblioteca do Visual C++ que é licenciada para redistribuição. Estas são três maneiras de implantá-las:  
  
-   Implantação Central usando os pacotes redistribuíveis, que instala as bibliotecas do Visual C++ como DLLs compartilhadas em %windir%\system32\\. (A instalação nessa pasta exige direitos de administrador.) Você pode criar um script ou um programa de instalação que execute o pacote redistribuível antes de instalar seu aplicativo no computador de destino. Os pacotes redistribuíveis estão disponíveis para as plataformas x86, x64 e ARM (VCRedist_x86.exe, VCRedist_x64.exe ou VCRedist_arm.exe). O Visual Studio inclui esses pacotes em % ProgramFiles (x86) %\Microsoft Visual Studio `version`\VC\Redist\\`locale ID`\\. Você também pode baixá-los no [Microsoft Download Center](http://go.microsoft.com/fwlink/p/?linkid=132793). (No Centro de Download, procure o "pacote redistribuível do Visual C++ *versão do Visual Studio e atualização*" que corresponde a seu aplicativo. Por exemplo, se você usou a atualização 4 do Visual Studio 2012 para compilar seu aplicativo, procure pela “atualização 4 do pacote redistribuível do Visual C++ 2012.) Para obter informações sobre como usar um pacote redistribuível, consulte [passo a passo: Implantando um Visual C++ aplicativo usando o pacote redistribuível do Visual C++](../ide/deploying-visual-cpp-application-by-using-the-vcpp-redistributable-package.md).  
  
-   Implantação Central usando módulos de mesclagem, cada um dos quais instala uma biblioteca específica do Visual C++ como uma DLL compartilhada em %windir%\system32\\. (A instalação nessa pasta exige direitos de administrador.) Os módulos de mesclagem se tornam parte do arquivo do instalador .msi de seu aplicativo. Módulos de mesclagem redistribuíveis do Visual C++ são incluídos no Visual Studio, em \Program arquivos (x86) \Common Files\Merge módulos\\. Para obter mais informações, consulte [redistribuição por usando Mesclar módulos](../ide/redistributing-components-by-using-merge-modules.md).  
  
-   Implantação local, no qual você copiar DLLs de C++ Visual específica de sua instalação do Visual Studio — normalmente em \Program Files (x86) \Microsoft Visual Studio `version`\VC\Redist\\`platform`\\`library`\—and a instalação em computadores de destino na mesma pasta que o executável do aplicativo. Você pode usar esse método de implantação para habilitar a instalação pelos usuários que não têm direitos de administrador ou para aplicativos que podem ser executados a partir de um compartilhamento de rede.  
  
 Se uma implantação usa módulos de mesclagem redistribuíveis e uma instalação é executada por um usuário que não tem direitos administrativos, as DLLs do Visual C++ não estão instaladas e o aplicativo não será executado. Além disso, instaladores de aplicativos compilados com módulos de mesclagem que permitem a instalação por usuário instalam as bibliotecas em um local compartilhado que afeta todos os usuários do sistema. Você pode usar a implantação local para instalar as DLLs do Visual C++ necessários no diretório do aplicativo de um usuário específico, sem afetar outros usuários ou tenha direitos de administrador. Como isso pode criar problemas de manutenção, não recomendamos a implantação local de DLLs redistribuíveis do Visual C++.  
  
 A implantação incorreta de bibliotecas do Visual C++ pode causar erros de tempo de execução durante a execução de um aplicativo que dependem delas. Quando o sistema operacional carrega o aplicativo, ele usa a ordem de pesquisa descrita em [LoadLibraryEx](http://go.microsoft.com/fwlink/p/?linkid=132792)  
  
## <a name="dynamic-linking-is-better-than-static-linking"></a>A vinculação dinâmica é melhor que a vinculação estática  
 É recomendável que você evite a vinculação estática quando você redistribuir bibliotecas do Visual C++. Embora a vinculação estática quase nunca melhora significativamente o desempenho do aplicativo, quase sempre torna a manutenção mais cara. Por exemplo, considere um aplicativo que seja vinculado estaticamente a uma biblioteca que é atualizado com aprimoramentos de segurança – o aplicativo não pode se beneficiar, a menos que seja recompilado e reimplantado. Em vez disso, recomendamos que você vincule dinamicamente seus aplicativos às bibliotecas de que eles dependem para que as bibliotecas possam ser atualizadas sempre que implantadas.  
  
## <a name="see-also"></a>Consulte também  
 [Implantando aplicativos de área de trabalho](../ide/deploying-native-desktop-applications-visual-cpp.md)   
 [Segurança e implantação do ClickOnce](/visualstudio/deployment/clickonce-security-and-deployment)   
 [Exemplos de implantação](../ide/deployment-examples.md)