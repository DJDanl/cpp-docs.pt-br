---
title: "Criando conjuntos de C-C++ lado a lado | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "aplicativos lado a lado [C++]"
ms.assetid: 7fa20b16-3737-4f76-a0b5-1dacea19a1e8
caps.latest.revision: 18
caps.handback.revision: 18
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Compilando assemblies lado a lado do C/C++
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Um [assembly lado a lado](http://msdn.microsoft.com/pt-br/501bbffe-5927-4656-8eee-1f6ecfafef5e) é uma coleção de recursos — um grupo de DLLs, classes windows, servidores COM, bibliotecas de tipos ou interfaces – disponível para um aplicativo para usar em tempo de execução. A principal vantagem de remontagem DLLs em assemblies é que várias versões de assemblies podem ser usadas por aplicativos ao mesmo tempo e é possível composições de serviço instalado atualmente no caso de uma versão de atualização.  
  
 Um aplicativo Visual C\+\+ pode usar uma ou várias DLLs em diferentes partes do aplicativo. Em tempo de execução, as DLLs são carregadas no processo principal e o código necessário é executado. O aplicativo se baseia no sistema operacional para localizar as DLLs solicitadas, entender o que tem outras DLLs dependentes ser carregado e, em seguida, carregá\-los junto com a DLL solicitada. Em versões de sistemas operacionais Windows anteriores ao Windows XP, Windows Server 2003 e Windows Vista, o carregador do sistema operacional procura DLLs dependentes na pasta local do aplicativo ou outra pasta especificada no caminho do sistema. No Windows XP, Windows Server 2003 e Windows Vista, o carregador do sistema operacional também pode pesquisar por DLLs dependentes usando um [manifesto](http://msdn.microsoft.com/library/aa375365) arquivo e procure os assemblies lado a lado que contêm essas DLLs.  
  
 Por padrão, quando uma DLL é compilada com o Visual Studio, ele tem um [manifesto do aplicativo](http://msdn.microsoft.com/library/aa374191) incorporado como um recurso RT\_MANIFEST com ID igual a 2. Assim como um executável, esse manifesto descreve as dependências dessa DLL em outros assemblies. Isso pressupõe que a DLL não é parte de um assembly lado a lado e aplicativos que dependem dessa DLL não pretende usar um manifesto de aplicativo para carregá\-lo, mas em vez disso, confiar no carregador do sistema operacional para localizar essa DLL no caminho do sistema.  
  
> [!NOTE]
>  É importante para uma DLL que usa um manifesto de aplicativo com o manifesto incorporado como um recurso com ID igual a 2. Se a DLL é carregada dinamicamente em tempo de execução \(por exemplo, usando o [LoadLibrary](http://msdn.microsoft.com/library/windows/desktop/ms684175) função\), o carregador do sistema operacional carrega assemblies dependentes especificados no manifesto do DLL. Um manifesto de aplicativo externo para DLLs não é verificado durante um `LoadLibrary` chamar. Se o manifesto não for inserido, o carregador pode tentar carregar versões incorretas de assemblies ou Falha ao localizar para localizar conjuntos de módulos dependentes.  
  
 Um ou vários relacionados a DLLs podem ser reempacotadas em um assembly lado a lado com um correspondente [manifesto do assembly](http://msdn.microsoft.com/library/aa374219), que descreve os arquivos que formam o assembly, bem como a dependência do assembly em outros assemblies lado a lado.  
  
> [!NOTE]
>  Se um assembly contém uma DLL, é recomendável para incorporar o manifesto do assembly essa DLL como um recurso com ID igual a 1 e dar ao assembly particular o mesmo nome que a DLL. Por exemplo, se o nome da DLL for MyLibrary, o valor do atributo nome usado no elemento \< assemblyIdentity \> do manifesto também pode ser mylibrary. Em alguns casos, quando uma biblioteca tem uma extensão diferente de. dll \(por exemplo, um projeto de controles ActiveX MFC cria uma biblioteca. ocx\) pode ser criado um manifesto de assembly externo. Nesse caso, o nome do assembly e manifesto deve ser diferente do nome da DLL \(por exemplo, MyAssembly, MyAssembly.manifest e mylibrary.ocx\). No entanto, ainda é recomendável renomear essas bibliotecas para que o extension.dll e o manifesto incorporado como um recurso para reduzir o custo de manutenção futura desse assembly. Para obter mais informações sobre como o sistema operacional procura assemblies particulares, consulte [a sequência de pesquisa de Assembly](http://msdn.microsoft.com/library/aa374224).  
  
 Essa alteração pode permitir a implantação de DLLs correspondentes como uma [assembly particular](http://msdn.microsoft.com/pt-br/4c6dac5f-fdd3-4125-b54a-74941ee6b3b4) em uma pasta local do aplicativo ou como um [compartilhado assembly](http://msdn.microsoft.com/pt-br/d408b0a9-8dc5-4cd0-93b3-429de7d12b17) no cache de assembly WinSxS. Várias etapas precisam ser seguidas para alcançar o comportamento de tempo de execução correta desse novo assembly; eles estão descritos em [diretrizes para criar Assemblies de lado a lado](http://msdn.microsoft.com/pt-br/e10fe92c-bce8-420e-a84c-2748e929eb1b). Depois de um assembly é criado corretamente pode implantado como um assembly de compartilhado ou particular junto com um aplicativo que depende dele. Ao instalar assemblies lado a lado como um assembly compartilhado, você pode a seguir as diretrizes descritas em [instalar Assemblies de Win32 para compartilhamento de lado a lado no Windows XP](http://msdn.microsoft.com/library/aa369532) ou use [módulos de mesclagem](http://msdn.microsoft.com/library/aa369820). Ao instalar assemblies lado a lado como um assembly particular, você pode apenas copiar o manifesto DLL, recursos e o assembly correspondente como parte do processo de instalação para a pasta local do aplicativo no computador de destino, garantindo que esse assembly pode ser encontrado pelo carregador de em tempo de execução \(consulte [a sequência de pesquisa de Assembly](http://msdn.microsoft.com/library/aa374224)\). Outra maneira é usar [do Windows Installer](http://msdn.microsoft.com/library/cc185688) e siga as diretrizes descritas em [instalar Assemblies de Win32 para o uso particular de um aplicativo no Windows XP](http://msdn.microsoft.com/library/aa369534).  
  
## Consulte também  
 [Exemplos de implantação](../ide/deployment-examples.md)   
 [Compilando aplicativos isolados do C\/C\+\+](../build/building-c-cpp-isolated-applications.md)   
 [Compilando aplicativos isolados do C\/C\+\+ e assemblies lado a lado](../build/building-c-cpp-isolated-applications-and-side-by-side-assemblies.md)