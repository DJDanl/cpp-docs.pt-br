---
title: Compilando assemblies lado a lado do C/C++
ms.date: 11/04/2016
helpviewer_keywords:
- side-by-side applications [C++]
ms.assetid: 7fa20b16-3737-4f76-a0b5-1dacea19a1e8
ms.openlocfilehash: 6e49ba72a397efb97437a2f7e6d721c782875c48
ms.sourcegitcommit: fcb48824f9ca24b1f8bd37d647a4d592de1cc925
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/15/2019
ms.locfileid: "69493334"
---
# <a name="building-cc-side-by-side-assemblies"></a>Compilando assemblies lado a lado do C/C++

Um [assembly lado a lado](/windows/win32/SbsCs/about-side-by-side-assemblies-) é uma coleção de recursos — um grupo de DLLs, classes do Windows, servidores com, bibliotecas de tipos ou interfaces — disponíveis para um aplicativo usar no tempo de execução. A principal vantagem de reempacotar DLLs em assemblies é que várias versões de assemblies podem ser usadas por aplicativos ao mesmo tempo e é possível atender a assemblies atualmente instalados no caso de uma versão de atualização.

Um C++ aplicativo pode usar uma ou várias DLLs em diferentes partes do aplicativo. Em tempo de execução, as DLLs são carregadas no processo principal e o código necessário é executado. O aplicativo depende do sistema operacional para localizar as DLLs solicitadas, entender quais outras DLLs dependentes precisam ser carregadas e, em seguida, carregá-las junto com a DLL solicitada. Em versões de sistemas operacionais Windows anteriores ao Windows XP, ao Windows Server 2003 e ao Windows Vista, o carregador do sistema operacional procura DLLs dependentes na pasta local do aplicativo ou em outra pasta especificada no caminho do sistema. No Windows XP, no Windows Server 2003 e no Windows Vista, o carregador do sistema operacional também pode pesquisar DLLs dependentes usando um arquivo de [manifesto](/windows/win32/sbscs/manifests) e Pesquisar por assemblies lado a lado que contenham essas DLLs.

Por padrão, quando uma DLL é criada com o Visual Studio, ela tem um [manifesto de aplicativo](/windows/win32/SbsCs/application-manifests) inserido como um recurso RT_MANIFEST com ID igual a 2. Assim como para um executável, este manifesto descreve as dependências dessa DLL em outros assemblies. Isso pressupõe que a DLL não faz parte de um assembly lado a lado e os aplicativos que dependem dessa DLL não usarão um manifesto de aplicativo para carregá-lo, mas, em vez disso, dependem do carregador do sistema operacional para encontrar essa DLL no caminho do sistema.

> [!NOTE]
> É importante para uma DLL que usa um manifesto de aplicativo para que o manifesto seja inserido como um recurso com ID igual a 2. Se a DLL for carregada dinamicamente em tempo de execução (por exemplo, usando a função [LoadLibrary](/windows/win32/api/libloaderapi/nf-libloaderapi-loadlibraryw) ), o carregador do sistema operacional carregará os assemblies dependentes especificados no manifesto da dll. Um manifesto de aplicativo externo para DLLs não é verificado durante `LoadLibrary` uma chamada. Se o manifesto não for inserido, o carregador poderá tentar carregar versões incorretas de assemblies ou falhar ao localizar os assemblies dependentes.

Uma ou várias DLLs relacionadas podem ser reempacotadas em um assembly lado a lado com um [manifesto de assembly](/windows/win32/SbsCs/assembly-manifests)correspondente, que descreve quais arquivos formam o assembly, bem como a dependência do assembly em outros assemblies lado a lado.

> [!NOTE]
> Se um assembly contiver uma DLL, é recomendável inserir o manifesto do assembly nessa DLL como um recurso com ID igual a 1 e dar ao assembly privado o mesmo nome que a DLL. Por exemplo, se o nome da dll for MyLibrary. dll, o valor do atributo name usado no \<elemento AssemblyIdentity > do manifesto também poderá ser MyLibrary. Em alguns casos, quando uma biblioteca tem uma extensão diferente de. dll (por exemplo, um projeto de controles ActiveX do MFC cria uma biblioteca. ocx), um manifesto de assembly externo pode ser criado. Nesse caso, o nome do assembly e seu manifesto devem ser diferentes do nome da DLL (por exemplo, MyAssembly, MyAssembly. manifest e MyLibrary. ocx). No entanto, ainda é recomendável renomear essas bibliotecas para ter a extensão. dll e inserir o manifesto como um recurso para reduzir o custo de manutenção futuro desse assembly. Para obter mais informações sobre como o sistema operacional pesquisa assemblies privados, consulte [sequência de pesquisa de assembly](/windows/win32/SbsCs/assembly-searching-sequence).

Essa alteração pode permitir a implantação de DLLs correspondentes como um [assembly privado](/windows/win32/Msi/private-assemblies) em uma pasta local do aplicativo ou como um [assembly compartilhado](/windows/win32/Msi/shared-assemblies) no cache do assembly WinSxS. Várias etapas devem ser seguidas para alcançar o comportamento correto do tempo de execução desse novo assembly; Elas são descritas em [diretrizes para criar assemblies lado a lado](/windows/win32/SbsCs/guidelines-for-creating-side-by-side-assemblies). Depois que um assembly é criado corretamente, ele pode ser implantado como um assembly compartilhado ou privado junto com um aplicativo que depende dele. Ao instalar assemblies lado a lado como um assembly compartilhado, você pode seguir as diretrizes descritas em [instalando assemblies do Win32 para compartilhamento lado a lado no Windows XP](/windows/win32/Msi/installing-win32-assemblies-for-side-by-side-sharing-on-windows-xp) ou usar [módulos](/windows/win32/msi/merge-modules)de mesclagem. Ao instalar assemblies lado a lado como um assembly privado, você pode simplesmente copiar a DLL correspondente, os recursos e o manifesto do assembly como parte do processo de instalação para a pasta local do aplicativo no computador de destino, garantindo que esse assembly possa ser encontrado pelo carregador em tempo de execução (consulte [sequência de pesquisa de assembly](/windows/win32/SbsCs/assembly-searching-sequence)). Outra maneira é usar [Windows Installer](/windows/win32/Msi/windows-installer-portal) e seguir as diretrizes descritas em instalando [assemblies do Win32 para o uso particular de um aplicativo no Windows XP](/windows/win32/Msi/installing-win32-assemblies-for-the-private-use-of-an-application-on-windows-xp).

## <a name="see-also"></a>Consulte também

[Compilando aplicativos isolados do C/C++](building-c-cpp-isolated-applications.md)<br/>
[Compilando aplicativos isolados do C/C++ e assemblies lado a lado](building-c-cpp-isolated-applications-and-side-by-side-assemblies.md)
