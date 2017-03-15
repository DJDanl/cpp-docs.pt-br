---
title: "ClickOnce Implanta&#231;&#227;o para aplicativos do Visual C++ | Microsoft Docs"
ms.custom: ""
ms.date: "12/15/2016"
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
  - "Implantando aplicativos [C++], ClickOnce"
  - "implantação de aplicativo [C++], ClickOnce"
  - "Aplicativos de C++, a implantação do ClickOnce [C++]"
ms.assetid: 9988c546-0936-452c-932f-9c76daa42157
caps.latest.revision: 17
caps.handback.revision: 17
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# ClickOnce Implanta&#231;&#227;o para aplicativos do Visual C++
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

[!INCLUDE[vsprvs](../assembler/masm/includes/vsprvs_md.md)] fornece duas tecnologias diferentes para implantar aplicativos do Windows: implantação de ClickOnce ou [Windows Installer](http://msdn.microsoft.com/library/cc185688).  
  
## Implantação de ClickOnce em C\+\+  
 O ambiente de desenvolvimento de [!INCLUDE[vcprvc](../build/includes/vcprvc_md.md)] não oferece suporte direto à implantação de projetos de [!INCLUDE[vcprvc](../build/includes/vcprvc_md.md)] com [!INCLUDE[ndptecclick](../ide/includes/ndptecclick_md.md)], mas as ferramentas estão disponíveis para uso.  
  
> [!NOTE]
>  [!INCLUDE[vsprvs](../assembler/masm/includes/vsprvs_md.md)] suporta [!INCLUDE[ndptecclick](../ide/includes/ndptecclick_md.md)] em ambientes de desenvolvimento de [!INCLUDE[csprcs](../ide/includes/csprcs_md.md)] e [!INCLUDE[vbprvb](../Token/vbprvb_md.md)].  Se seu projeto do [!INCLUDE[vcprvc](../build/includes/vcprvc_md.md)] for uma dependência de um projeto do [!INCLUDE[csprcs](../ide/includes/csprcs_md.md)], você poderá publicar o aplicativo \(incluindo suas dependências\) usando a implantação de [!INCLUDE[ndptecclick](../ide/includes/ndptecclick_md.md)] do ambiente de desenvolvimento do [!INCLUDE[csprcs](../ide/includes/csprcs_md.md)].  
  
 Para implantar um aplicativo [!INCLUDE[vcprvc](../build/includes/vcprvc_md.md)] usando [!INCLUDE[ndptecclick](../ide/includes/ndptecclick_md.md)], você primeiro precisará criar [Manifesto de aplicativo ClickOnce](../Topic/ClickOnce%20Application%20Manifest.md) e [Manifesto de implantação do ClickOnce](../Topic/ClickOnce%20Deployment%20Manifest.md) usando [Mage.exe \(Ferramenta de Geração e Edição de Manifesto\)](../Topic/Mage.exe%20\(Manifest%20Generation%20and%20Editing%20Tool\).md) ou sua versão da interface gráfica do usuário \(para obter mais informações, consulte [MageUI.exe \(Ferramenta de Geração e Edição de Manifesto, cliente gráfico\)](../Topic/MageUI.exe%20\(Manifest%20Generation%20and%20Editing%20Tool,%20Graphical%20Client\).md)\).  
  
 Você usa primeiro o Mage.exe para compilar o manifesto do aplicativo; o arquivo resultante terá a extensão .manifest.  Em seguida, você usa o Mage.exe para compilar o manifesto de implantação; o arquivo resultante terá a extensão .application.  Em seguida, você assina os manifestos.  
  
 O manifesto do aplicativo deve especificar o processador de destino \(**x86**, **x64** ou **ARM**\).  Consulte [Implantando pré\-requisitos para aplicativos de 64 bits](../Topic/Deploying%20Prerequisites%20for%2064-bit%20Applications.md) para obter informações sobre essas opções.  
  
 Além disso, o nome do aplicativo e dos manifestos de implantação deve ser diferente do nome do aplicativo do C\+\+.  Isso evita o conflito entre o manifesto do aplicativo criado por Mage.exe e o manifesto externo, que faz parte de aplicativo do C\+\+.  
  
 A implantação precisará instalar todas as bibliotecas de [!INCLUDE[vcprvc](../build/includes/vcprvc_md.md)] de que seu aplicativo depende.  Para determinar as dependências para um aplicativo específico, você pode usar depends.exe ou o utilitário de DUMPBIN com a opção de \/DEPENDENTS.  Para obter mais informações sobre as dependências, consulte [Noções básicas sobre as dependências de um aplicativo do Visual C\+\+](../ide/understanding-the-dependencies-of-a-visual-cpp-application.md).  Talvez seja necessário executar o VCRedist.exe; esse utilitário instala bibliotecas de [!INCLUDE[vcprvc](../build/includes/vcprvc_md.md)] no computador de destino.  
  
 Talvez seja necessário criar um bootstrapper \(instalador de pré\-requisitos\) para seu aplicativo implantar os componentes de pré\-requisito; para obter informações sobre bootstrapper, consulte [Criando pacotes de bootstrapper](../Topic/Creating%20Bootstrapper%20Packages.md).  
  
 Para obter uma descrição mais detalhada da tecnologia, consulte [Segurança e implantação do ClickOnce](../Topic/ClickOnce%20Security%20and%20Deployment.md).  Para obter um exemplo detalhado da implantação de [!INCLUDE[ndptecclick](../ide/includes/ndptecclick_md.md)], consulte [Instruções passo a passo: implantando um aplicativo ClickOnce manualmente](../Topic/Walkthrough:%20Manually%20Deploying%20a%20ClickOnce%20Application.md).  
  
## Consulte também  
 [Mage.exe \(Ferramenta de Geração e Edição de Manifesto\)](../Topic/Mage.exe%20\(Manifest%20Generation%20and%20Editing%20Tool\).md)   
 [MageUI.exe \(Ferramenta de Geração e Edição de Manifesto, cliente gráfico\)](../Topic/MageUI.exe%20\(Manifest%20Generation%20and%20Editing%20Tool,%20Graphical%20Client\).md)   
 [Makecert.exe \(Ferramenta de Criação de Certificado\)](../Topic/Makecert.exe%20\(Certificate%20Creation%20Tool\).md)   
 [Implantando aplicativos da área de trabalho](../Topic/Deploying%20Native%20Desktop%20Applications%20\(Visual%20C++\).md)   
 [Implantando aplicativos, serviços e componentes](../Topic/Deploying%20Applications,%20Services,%20and%20Components.md)   
 [Windows Installer Deployment](http://msdn.microsoft.com/pt-br/121be21b-b916-43e2-8f10-8b080516d2a0)   
 [Segurança e implantação do ClickOnce](../Topic/ClickOnce%20Security%20and%20Deployment.md)   
 [Criando pacotes de bootstrapper](../Topic/Creating%20Bootstrapper%20Packages.md)   
 [Programação do .NET com o C \+ \+ \/ CLI \(Visual C\+\+\)](../dotnet/dotnet-programming-with-cpp-cli-visual-cpp.md)   
 [Nativo e interoperabilidade .NET](../Topic/Native%20and%20.NET%20Interoperability.md)