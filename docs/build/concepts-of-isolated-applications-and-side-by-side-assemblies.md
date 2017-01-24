---
title: "Conceitos de aplicativos isolados e assemblies lado a lado | Microsoft Docs"
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
  - "assemblies lado a lado [C++]"
  - "assemblies isolados [C++]"
ms.assetid: 945a885f-cb3e-4c8a-a0b9-2c2e3e02cc50
caps.latest.revision: 21
caps.handback.revision: 21
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Conceitos de aplicativos isolados e assemblies lado a lado
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Um aplicativo é considerado uma [aplicativo isolado](http://msdn.microsoft.com/library/aa375190) se todos os seus componentes são [assemblies lado a lado](_win32_side_by_side_assemblies). Um assembly lado a lado é uma coleção de recursos — um grupo de DLLs, classes windows, servidores COM, bibliotecas de tipos ou interfaces – que são implantados juntos e disponibilizados para um aplicativo para usar em tempo de execução. Normalmente, um assembly lado a lado é um para várias DLLs.  
  
## Compartilhado ou particular  
 Um assembly lado a lado pode ser compartilhado ou particular.[Assemblies lado a lado compartilhados](https://msdn.microsoft.com/en-us/library/aa375996.aspx) podem ser usados por vários aplicativos que especifique, em seus manifestos, uma dependência do assembly. Várias versões de um assembly lado a lado podem ser compartilhadas por diferentes aplicativos que estão em execução ao mesmo tempo. Um [assembly particular](_win32_private_assemblies) é um assembly que foi implantado com um aplicativo para uso exclusivo desse aplicativo. Assemblies particulares são instalados na pasta que contém o arquivo executável do aplicativo ou uma de suas subpastas.  
  
## Manifestos e ordem de pesquisa  
 Aplicativos isolados e assemblies lado a lado são descritos por [manifestos](http://msdn.microsoft.com/library/aa375365). Um manifesto é um documento XML que pode ser um arquivo externo ou pode ser inserido em um aplicativo ou um assembly como um recurso. O arquivo de manifesto de um aplicativo isolado é usado para gerenciar os nomes e as versões de assemblies lado a lado compartilhados aos quais o aplicativo deve se associar no tempo de execução. O manifesto de um assembly lado a lado Especifica nomes, versões, recursos e assemblies dependentes de assemblies lado a lado. Para um assembly lado a lado compartilhado, seu manifesto é instalado na pasta %Windir%\\winsxs\\manifests\\.. No caso de um assembly particular, recomendamos que você inclua seu manifesto na DLL como um recurso que tem uma ID igual a 1. Você também pode adicionar o assembly particular o mesmo nome da DLL. Para obter mais informações, consulte [Assemblies particulares](_win32_private_assemblies).  
  
 Em tempo de execução, o Windows usa informações de assembly do manifesto do aplicativo para procurar e carregar o assembly lado a lado correspondente. Se um aplicativo isolado especificar uma dependência do assembly, o sistema operacional primeiro procura o assembly entre os assemblies compartilhados no cache de assembly nativo na pasta %Windir%\\winsxs\\.. Se o assembly necessário não for encontrado, o sistema operacional, em seguida, procura por um assembly particular em uma pasta da estrutura de diretório do aplicativo. Para obter mais informações, consulte [a sequência de pesquisa de Assembly](http://msdn.microsoft.com/library/aa374224).  
  
## Alterando dependências  
 Você pode alterar as dependências do assembly lado a lado após a implantação de um aplicativo modificando o [arquivos de configuração do publicador](http://msdn.microsoft.com/library/aa375682) e [arquivos de configuração do aplicativo](http://msdn.microsoft.com/library/aa374182). Um arquivo de configuração do publicador, também conhecido como um arquivo de política de editor, é um arquivo XML que redireciona globalmente aplicativos e assemblies do uso de uma versão de um assembly lado a lado usando outra versão do mesmo assembly. Por exemplo, você pode alterar uma dependência quando uma correção de bug ou correção de segurança é implantada para um assembly lado a lado e você deseja redirecionar todos os aplicativos para usar a versão corrigida. Um arquivo de configuração do aplicativo é um arquivo XML que redireciona um aplicativo específico que usa uma versão de um assembly lado a lado usando outra versão do mesmo assembly. Você pode usar um arquivo de configuração do aplicativo para redirecionar um aplicativo específico para usar uma versão de um assembly lado a lado que é diferente daquele que é definido no arquivo de configuração do publicador. Para obter mais informações, consulte [configuração](http://msdn.microsoft.com/library/aa375123).  
  
## Bibliotecas do Visual C\+\+  
 No Visual Studio 2005 e Visual Studio 2008, as bibliotecas redistribuíveis como ATL, MFC, CRT, C\+\+ padrão, OpenMP e MSDIA foram implantadas como assemblies lado a lado compartilhados no cache de assembly nativo. Na versão atual, as bibliotecas redistribuíveis usam a implantação central. Por padrão, todos os aplicativos que são criados usando o Visual C\+\+ são criados com o manifesto inserido no final binário e o manifesto descreve as dependências do binário nas bibliotecas do Visual C\+\+. Para entender a geração de manifesto para aplicativos do Visual C\+\+, consulte [Noções básicas sobre geração de manifesto para programas do C\/C\+\+](../Topic/Understanding%20Manifest%20Generation%20for%20C-C++%20Programs.md). Um manifesto não é necessário para aplicativos que são vinculados estaticamente às bibliotecas que eles usam, ou que usam a implantação local. Para obter mais informações sobre a implantação, consulte [Implantação no Visual C\+\+](../ide/deployment-in-visual-cpp.md).  
  
## Consulte também  
 [Compilando aplicativos isolados do C\/C\+\+ e assemblies lado a lado](../build/building-c-cpp-isolated-applications-and-side-by-side-assemblies.md)