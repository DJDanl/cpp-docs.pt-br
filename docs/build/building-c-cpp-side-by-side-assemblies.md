---
title: Criação de Assemblies de C/C++ Side-by-side | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-tools
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- side-by-side applications [C++]
ms.assetid: 7fa20b16-3737-4f76-a0b5-1dacea19a1e8
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 51435d0613a7f68ca906058e4ff72f1ad34e6c54
ms.sourcegitcommit: 92f2fff4ce77387b57a4546de1bd4bd464fb51b6
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/17/2018
ms.locfileid: "45701578"
---
# <a name="building-cc-side-by-side-assemblies"></a>Compilando assemblies lado a lado do C/C++

Um [assembly lado a lado](/windows/desktop/SbsCs/about-side-by-side-assemblies-) é uma coleção de recursos — um grupo de DLLs, classes do windows, servidores COM, bibliotecas de tipos ou interfaces – disponível para um aplicativo para usar em tempo de execução. A principal vantagem do reempacotamento DLLs assemblies é que várias versões de assemblies podem ser usadas por aplicativos ao mesmo tempo e é possível aos assemblies do serviço instalado atualmente no caso de uma versão de atualização.

Um aplicativo Visual C++ pode usar uma ou várias DLLs em diferentes partes do aplicativo. Em tempo de execução, as DLLs são carregadas no processo principal e o código necessário é executado. O aplicativo depende do sistema operacional para localizar as DLLs solicitadas, entender o que outras DLLs dependentes tem que ser carregado e, em seguida, carregá-los junto com a DLL solicitada. Em versões de sistemas operacionais Windows anteriores ao Windows XP, Windows Server 2003 e Windows Vista, o carregador do sistema operacional procura as DLLs dependentes na pasta local do aplicativo ou outra pasta especificada no caminho do sistema. No Windows XP, Windows Server 2003 e Windows Vista, o carregador do sistema operacional também pode procurar DLLs dependentes usando um [manifesto](https://msdn.microsoft.com/library/windows/desktop/aa375365) arquivo e procure por assemblies lado a lado que contêm essas DLLs.

Por padrão, quando uma DLL é compilada com o Visual Studio, ele tem um [manifesto do aplicativo](/windows/desktop/SbsCs/application-manifests) incorporado como um recurso RT_MANIFEST com ID igual a 2. Assim como um executável, esse manifesto descreve as dependências dessa DLL em outros assemblies. Isso pressupõe que a DLL não faz parte de um assembly lado a lado e aplicativos que dependem dessa DLL não pretende usar um manifesto de aplicativo para carregá-lo, mas em vez disso, contar o carregador do sistema operacional para encontrar essa DLL no caminho do sistema.

> [!NOTE]
>  É importante para uma DLL que usa um manifesto de aplicativo para ter o manifesto inserido como um recurso com ID igual a 2. Se a DLL é carregada dinamicamente em tempo de execução (por exemplo, usando o [LoadLibrary](https://msdn.microsoft.com/library/windows/desktop/ms684175) função), o carregador do sistema operacional carrega assemblies dependentes especificados no manifesto da DLL. Um manifesto de aplicativo externo para DLLs não é verificado durante um `LoadLibrary` chamar. Se o manifesto não for inserido, o carregador pode tentar carregar versões incorretas de assemblies ou não conseguir localizar para localizar assemblies de dependentes.

Um ou vários relacionados a DLLs podem ser reempacotadas em um assembly lado a lado com um correspondente [manifesto do assembly](/windows/desktop/SbsCs/assembly-manifests), que descreve quais arquivos formam o assembly, bem como a dependência do assembly no outra lado a lado assemblies.

> [!NOTE]
>  Se um assembly contém uma DLL, é recomendável inserir o manifesto do assembly nessa DLL como um recurso com ID igual a 1 e, em seguida, dar o assembly particular o mesmo nome que a DLL. Por exemplo, se o nome da DLL for MyLibrary, o valor do nome do atributo usado no \<assemblyIdentity > elemento do manifesto também pode ser mylibrary. Em alguns casos, quando uma biblioteca tem uma extensão diferente de. dll (por exemplo, um projeto de controles ActiveX do MFC cria uma biblioteca. ocx) pode ser criado um manifesto do assembly externo. Nesse caso, o nome do assembly e manifesto deve ser diferente do nome da DLL (por exemplo, MyAssembly, MyAssembly.manifest e mylibrary.ocx). No entanto ele ainda é recomendável renomear essas bibliotecas para que o extension.dll e inserir o manifesto como um recurso para reduzir o custo de manutenção futura desse assembly. Para obter mais informações sobre como o sistema operacional procura assemblies particulares, consulte [sequência de pesquisa de Assembly](/windows/desktop/SbsCs/assembly-searching-sequence).

Essa alteração pode permitir que a implantação de DLLs correspondentes como uma [assembly particular](/windows/desktop/Msi/private-assemblies) em uma pasta local do aplicativo ou como um [compartilhado assembly](/windows/desktop/Msi/shared-assemblies) no cache de assembly WinSxS. Várias etapas que devem ser seguidas para alcançar o comportamento de tempo de execução correta desse novo assembly; elas são descritas [diretrizes para criar Assemblies de lado a lado](/windows/desktop/SbsCs/guidelines-for-creating-side-by-side-assemblies). Depois que um assembly foi criado corretamente, ele pode implantado como um assembly de compartilhado ou particular junto com um aplicativo que depende dele. Ao instalar os assemblies lado a lado como um assembly compartilhado, você pode ambos seguem as diretrizes descritas em [instalando Assemblies do Win32 para compartilhamento de lado a lado no Windows XP](/windows/desktop/Msi/installing-win32-assemblies-for-side-by-side-sharing-on-windows-xp) ou use [Mesclar módulos](https://msdn.microsoft.com/library/windows/desktop/aa369820). Ao instalar os assemblies lado a lado como um assembly privado, você pode apenas copiar o manifesto do assembly, DLL e recursos correspondente como parte do processo de instalação para a pasta local do aplicativo no computador de destino, garantindo que esse assembly pode ser encontrado pelo carregador de em tempo de execução (consulte [sequência de pesquisa de Assembly](/windows/desktop/SbsCs/assembly-searching-sequence)). Outra maneira é usar [Windows Installer](/windows/desktop/Msi/windows-installer-portal) e siga as diretrizes descritas [instalando Assemblies do Win32 para uso privado de um aplicativo no Windows XP](/windows/desktop/Msi/installing-win32-assemblies-for-the-private-use-of-an-application-on-windows-xp).

## <a name="see-also"></a>Consulte também

[Exemplos de implantação](../ide/deployment-examples.md)<br/>
[Compilando aplicativos isolados do C/C++](../build/building-c-cpp-isolated-applications.md)<br/>
[Compilando aplicativos isolados do C/C++ e assemblies lado a lado](../build/building-c-cpp-isolated-applications-and-side-by-side-assemblies.md)