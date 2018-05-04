---
title: Compilando Assemblies de C/C++-lado a lado | Microsoft Docs
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
ms.openlocfilehash: a45062af5648c7b3565d959fd1d2dce13aeca4b3
ms.sourcegitcommit: be2a7679c2bd80968204dee03d13ca961eaa31ff
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/03/2018
---
# <a name="building-cc-side-by-side-assemblies"></a>Compilando assemblies lado a lado do C/C++
Um [assembly lado a lado](http://msdn.microsoft.com/library/windows/desktop/ff951640) é uma coleção de recursos — um grupo de DLLs, classes de windows, servidores COM, bibliotecas de tipo ou interfaces — disponível para um aplicativo para usar em tempo de execução. A principal vantagem de remontagem DLLs em assemblies é que várias versões de módulos (assemblies) podem ser usadas por aplicativos ao mesmo tempo e é possível assemblies de serviço instalado atualmente no caso de uma versão de atualização.  
  
 Um aplicativo Visual C++ pode usar uma ou várias DLLs em diferentes partes do aplicativo. Em tempo de execução, as DLLs são carregadas no processo principal e o código necessário é executado. O aplicativo depende do sistema operacional para localizar as DLLs solicitadas, entender o que tem outras DLLs dependentes ser carregado e, em seguida, carregá-los junto com a DLL solicitada. Em versões de sistemas operacionais Windows anteriores ao Windows XP, Windows Server 2003 e Windows Vista, o carregador do sistema operacional procura DLLs dependentes na pasta local do aplicativo ou em outra pasta especificada no caminho do sistema. No Windows XP, Windows Server 2003 e Windows Vista, o carregador do sistema operacional também pode procurar DLLs dependentes usando um [manifesto](http://msdn.microsoft.com/library/windows/desktop/aa375365) arquivo e pesquisa para assemblies lado a lado que contêm essas DLLs.  
  
 Por padrão, quando uma DLL é compilada com Visual Studio, ele tem um [o manifesto do aplicativo](http://msdn.microsoft.com/library/windows/desktop/aa374191) inserido como um recurso RT_MANIFEST com a ID igual a 2. Como um executável, esse manifesto descreve as dependências dessa DLL em outros assemblies. Isso pressupõe que a DLL não faz parte de um assembly lado a lado e aplicativos que dependem dessa DLL não pretende usar um manifesto de aplicativo para carregá-lo, mas em vez disso, contam com o carregador do sistema operacional para encontrar essa DLL no caminho do sistema.  
  
> [!NOTE]
>  É importante para uma DLL que usa um manifesto de aplicativo para que o manifesto inserido como um recurso com a ID igual a 2. Se a DLL é carregada dinamicamente em tempo de execução (por exemplo, usando o [LoadLibrary](http://msdn.microsoft.com/library/windows/desktop/ms684175) função), o carregador do sistema operacional carrega assemblies dependentes especificados no manifesto da DLL. Um manifesto de aplicativo externo para DLLs não é verificado durante um `LoadLibrary` chamar. Se o manifesto não é inserido, o carregador pode tentar carregar versões incorretas de assemblies ou não conseguir localizar para localizar assemblies de dependentes.  
  
 Um ou vários relacionados a DLLs podem ser empacotados novamente em um assembly lado a lado com um correspondente [manifesto do assembly](http://msdn.microsoft.com/library/windows/desktop/aa374219), que descreve os arquivos que formam o assembly, bem como a dependência do assembly no outro lado módulos (assemblies).  
  
> [!NOTE]
>  Se um assembly contém uma DLL, recomenda-se de inserir o manifesto do assembly para essa DLL como um recurso com a ID igual a 1 e oferecem o assembly particular o mesmo nome que a DLL. Por exemplo, se o nome da DLL for MyLibrary, o valor do atributo nome usado no \<assemblyIdentity > elemento do manifesto também pode ser mylibrary. Em alguns casos, quando uma biblioteca tem uma extensão diferente de. dll (por exemplo, um projeto de controles ActiveX MFC cria uma biblioteca. ocx) pode ser criado um manifesto de assembly externo. Nesse caso, o nome do assembly e manifesto deve ser diferente do nome da DLL (por exemplo, MyAssembly, MyAssembly.manifest e mylibrary.ocx). No entanto, ainda é recomendável renomear essas bibliotecas para que o extension.dll e inserir o manifesto como um recurso para reduzir o custo de manutenção futura deste assembly. Para obter mais informações sobre como o sistema operacional procura por assemblies privados, consulte [a sequência de pesquisa de Assembly](http://msdn.microsoft.com/library/windows/desktop/aa374224).  
  
 Essa alteração pode permitir a implantação de DLLs correspondentes como uma [assembly particular](http://msdn.microsoft.com/library/windows/desktop/aa370850) em uma pasta local do aplicativo ou como um [assembly compartilhado](http://msdn.microsoft.com/library/windows/desktop/aa371839) no cache de assembly WinSxS. Várias etapas precisam ser seguidas para alcançar o comportamento de tempo de execução corretos deste novo assembly; eles são descritos nos [diretrizes para criação lado a lado Assemblies](http://msdn.microsoft.com/library/windows/desktop/aa375155). Depois que um assembly foi criado corretamente pode implantado como um assembly de compartilhado ou privado junto com um aplicativo que depende dele. Ao instalar os assemblies lado a lado como um assembly compartilhado, você pode ou siga as diretrizes descritas em [instalar Assemblies de Win32 para compartilhamento de lado a lado no Windows XP](http://msdn.microsoft.com/library/windows/desktop/aa369532) ou use [Mesclar módulos](http://msdn.microsoft.com/library/windows/desktop/aa369820). Ao instalar os assemblies lado a lado como um assembly privado, você pode simplesmente copiar o manifesto DLL, recursos e o assembly correspondente como parte do processo de instalação para a pasta local do aplicativo no computador de destino, garantindo que esse assembly pode ser encontrado pelo carregador em tempo de execução (consulte [a sequência de pesquisa de Assembly](http://msdn.microsoft.com/library/windows/desktop/aa374224)). Outra maneira é usar [do Windows Installer](http://msdn.microsoft.com/library/windows/desktop/cc185688) e siga as diretrizes descritas em [instalar Assemblies do Win32 para o uso particular de um aplicativo no Windows XP](http://msdn.microsoft.com/library/windows/desktop/aa369534).  
  
## <a name="see-also"></a>Consulte também  
 [Exemplos de implantação](../ide/deployment-examples.md)   
 [Compilando aplicativos isolados C/C++](../build/building-c-cpp-isolated-applications.md)   
 [Compilando aplicativos isolados do C/C++ e assemblies lado a lado](../build/building-c-cpp-isolated-applications-and-side-by-side-assemblies.md)