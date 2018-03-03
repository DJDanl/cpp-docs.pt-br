---
title: Conceitos de aplicativos isolados e Assemblies lado a lado | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: article
dev_langs:
- C++
helpviewer_keywords:
- side-by-side assemblies [C++]
- isolated assemblies [C++]
ms.assetid: 945a885f-cb3e-4c8a-a0b9-2c2e3e02cc50
caps.latest.revision: 
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 9166f62c51344cc9c620da34d9c6fcee4665f400
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="concepts-of-isolated-applications-and-side-by-side-assemblies"></a>Conceitos de aplicativos isolados e assemblies lado a lado
Um aplicativo é considerado um [aplicativo isolado](http://msdn.microsoft.com/library/aa375190) se todos os seus componentes [assemblies lado a lado](http://msdn.microsoft.com/library/ff951640). Um assembly lado a lado é uma coleção de recursos – um grupo de DLLs, classes windows, servidores COM, bibliotecas de tipos ou interfaces – que são implantados juntos e disponibilizados para um aplicativo usar no tempo de execução. Normalmente, um assembly lado a lado é um para várias DLLs.  
  
## <a name="shared-or-private"></a>Compartilhado ou particular  
 Um assembly lado a lado pode ser compartilhado ou particular. [Assemblies lado a lado compartilhados](https://msdn.microsoft.com/en-us/library/aa375996.aspx) podem ser usados por vários aplicativos que especifique, em seus manifestos, uma dependência no assembly. Várias versões de um assembly lado a lado podem ser compartilhadas por aplicativos diferentes que são executados ao mesmo tempo. Um [assembly particular](http://msdn.microsoft.com/library/ff951638) é um assembly que é implantado junto com um aplicativo para o uso exclusivo do aplicativo. Os assemblies particulares são instalados na pasta que contém o arquivo executável do aplicativo ou uma de suas subpastas.  
  
## <a name="manifests-and-search-order"></a>Manifestos e ordem de pesquisa  
 Aplicativos isolados e assemblies lado a lado são descritos por [manifestos](http://msdn.microsoft.com/library/aa375365). Um manifesto é um documento XML que pode ser um arquivo externo ou pode ser inserido em um aplicativo ou em um assembly como um recurso. O arquivo de manifesto de um aplicativo isolado é usado para gerenciar os nomes e as versões dos assemblies lado a lado compartilhados aos quais o aplicativo deve se associar no tempo de execução. O manifesto de um assembly lado a lado especifica nomes, versões, recursos e os assemblies dependentes de assemblies lado a lado. Para um assembly lado a lado compartilhado, seu manifesto é instalado na pasta %WINDIR%\WinSxS\Manifests\. No caso de um assembly particular, recomendamos que você inclua seu manifesto na DLL como um recurso que tenha uma ID igual a 1. Você também pode dar ao assembly particular o mesmo nome da DLL. Para obter mais informações, consulte [sobre Assemblies privados](http://msdn.microsoft.com/library/ff951638).  
  
 No momento da execução, o Windows usa as informações do assembly do manifesto do aplicativo para procurar e carregar o assembly lado a lado correspondente. Se um aplicativo isolado especificar uma dependência do assembly, o sistema operacional procura pelo assembly primeiro entre os assemblies compartilhados em cache de assembly nativo na pasta %WINDIR%\WinSxS\. Se o assembly necessário não for localizado, o sistema operacional procurará um assembly particular em uma pasta da estrutura de diretórios do aplicativo. Para obter mais informações, consulte [a sequência de pesquisa de Assembly](http://msdn.microsoft.com/library/aa374224).  
  
## <a name="changing-dependencies"></a>Alterando dependências  
 Você pode alterar as dependências de assembly lado a lado após a implantação de um aplicativo modificando o [arquivos de configuração do publicador](http://msdn.microsoft.com/library/aa375682) e [arquivos de configuração de aplicativo](http://msdn.microsoft.com/library/aa374182). Um arquivo de configuração do editor, também conhecido como um arquivo de política do editor, é um arquivo XML que redireciona globalmente aplicativos e assemblies do uso de uma versão de um assembly lado a lado para o uso de outra versão do mesmo assembly. Por exemplo, você poderia alterar uma dependência quando uma correção de bug ou de segurança é implantada para um assembly lado a lado e você deseja redirecionar todos os aplicativos para usar a versão corrigida. Um arquivo de configuração do aplicativo é um arquivo XML que redireciona um aplicativo específico do uso de uma versão de um assembly lado a lado para o uso de outra versão do mesmo assembly. Você pode usar um arquivo de configuração do aplicativo para redirecionar um aplicativo específico para usar uma versão de um assembly lado a lado que seja diferente daquela definida no arquivo de configuração do editor. Para obter mais informações, consulte [Configuração](http://msdn.microsoft.com/library/aa375123).  
  
## <a name="visual-c-libraries"></a>Bibliotecas do Visual C++  
 No Visual Studio 2005 e no Visual Studio 2008, as bibliotecas redistribuíveis como ATL, MFC, CRT, C++ padrão, OpenMP e MSDIA foram implantadas como assemblies lado a lado compartilhados no cache de assembly nativo. Na versão atual, as bibliotecas redistribuíveis usam a implantação central. Por padrão, todos os aplicativos que são compilados usando o Visual C++ são compilados com o manifesto inserido no final binário, e o manifesto descreve as dependências do binário nas bibliotecas do Visual C++. Para entender a geração de manifesto para aplicativos Visual C++, consulte [Noções básicas sobre geração de manifesto para programas do C/C++](../build/understanding-manifest-generation-for-c-cpp-programs.md). Um manifesto não é necessário para aplicativos que são vinculados estaticamente às bibliotecas que eles usam, ou que usam a implantação local. Para obter mais informações sobre a implantação, consulte [implantação no Visual C++](../ide/deployment-in-visual-cpp.md).  
  
## <a name="see-also"></a>Consulte também  
 [Compilando aplicativos isolados do C/C++ e assemblies lado a lado](../build/building-c-cpp-isolated-applications-and-side-by-side-assemblies.md)