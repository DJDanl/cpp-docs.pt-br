---
title: "Escolhendo uma m&#233;todo de implanta&#231;&#227;o | Microsoft Docs"
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
  - "implantação de aplicativos [C++], métodos"
  - "implantando aplicativos [C++], métodos"
  - "DLLs [C++], redistribuindo"
  - "vinculação dinâmica [C++]"
  - "bibliotecas [C++], problemas de implantação de aplicativos"
  - "manifestos [C++]"
  - "redistribuindo DLLs"
  - "assemblies lado a lado [C++]"
  - "vinculação estática [C++]"
ms.assetid: fd8eb956-f4a0-4ffb-b401-328c73e66986
caps.latest.revision: 35
caps.handback.revision: 35
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Escolhendo uma m&#233;todo de implanta&#231;&#227;o
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

A menos que seu aplicativo do [!INCLUDE[vcprvc](../build/includes/vcprvc_md.md)] seja independente e possa ser implantado usando um comando de cópia, recomendamos que você use o Windows Installer para implantação.  O Windows Installer oferece suporte à instalação, ao reparo e à desinstalação, e também oferece suporte à atualização atômica dos arquivos de aplicativo, dependências e das entradas do Registro.  
  
> [!NOTE]
>  Embora a implantação do [ClickOnce](../Topic/ClickOnce%20Security%20and%20Deployment.md) para aplicativos nativos do [!INCLUDE[vcprvc](../build/includes/vcprvc_md.md)] seja possível no Visual Studio, ela requer etapas adicionais.  Para obter mais informações, consulte [ClickOnce Implantação para aplicativos do Visual C\+\+](../ide/clickonce-deployment-for-visual-cpp-applications.md).  
  
## As bibliotecas do Visual C\+\+ são DLLs compartilhadas  
 Como as bibliotecas do Visual C\+\+ são instaladas no diretório %windir%\\system32\\ pelo instalador do Visual Studio, quando você desenvolve um aplicativo do Visual C\+\+ que depende delas, ele será executado como esperado.  No entanto, para implantar o aplicativo em computadores que podem não ter o Visual Studio, recomendamos que você verifique se as bibliotecas foram instaladas nesses computadores junto com o aplicativo.  
  
## Redistribuindo bibliotecas do Visual C\+\+  
 Em suas implantações, você pode redistribuir qualquer versão de uma biblioteca do Visual C\+\+ que é licenciada para redistribuição.  Estas são três maneiras de implantá\-las:  
  
-   Implantação central usando pacotes redistribuíveis, que instalam bibliotecas do Visual C\+\+ como DLLs compartilhadas em %windir%\\system32\\. \(A instalação nessa pasta exige direitos de administrador.\) Você pode criar um script ou um programa de instalação que execute o pacote redistribuível antes de instalar seu aplicativo no computador de destino.  Os pacotes redistribuíveis estão disponíveis para as plataformas x86, x64 e ARM \(VCRedist\_x86.exe, VCRedist\_x64.exe ou VCRedist\_arm.exe\).  O Visual Studio inclui esses pacotes em %ProgramFiles\(x86\)%\\Microsoft Visual Studio `version`\\VC\\Redist\\`locale ID`\\.  Você também pode baixá\-los do [Centro de Download da Microsoft](http://go.microsoft.com/fwlink/?LinkId=132793). \(No Centro de Download, procure pelo pacote redistribuível do [!INCLUDE[vcprvc](../build/includes/vcprvc_md.md)] *Visual Studio version and update* que corresponde ao seu aplicativo.  Por exemplo, se você usou a atualização 4 do Visual Studio 2012 para compilar seu aplicativo, procure pela “atualização 4 do pacote redistribuível do Visual C\+\+ 2012.\) Para obter informações sobre como usar um pacote redistribuível, consulte [Instruções passo a passo: implantando um aplicativo do Visual C\+\+ usando o pacote redistribuível do Visual C\+\+](../Topic/Walkthrough:%20Deploying%20a%20Visual%20C++%20Application%20By%20Using%20the%20Visual%20C++%20Redistributable%20Package.md).  
  
-   Implantação central usando módulos de mesclagem, onde cada um instala uma biblioteca específica do Visual C\+\+ como DLL compartilhada em %windir%\\system32\\. \(A instalação nessa pasta exige direitos de administrador.\) Os módulos de mesclagem se tornam parte do arquivo do instalador .msi de seu aplicativo.  Os módulos de mesclagem redistribuíveis do Visual C\+\+ são incluídos no Visual Studio, em \\Program Files \(x86\)\\Common Files\\Merge Modules\\.  Para obter mais informações, consulte [Redistribuindo usando módulos de mesclagem](../ide/redistributing-components-by-using-merge-modules.md).  
  
-   Implantação local, em que você copia DLLs específicas do Visual C\+\+ de sua instalação do Visual Studio — normalmente em \\Program Files \(x86\)\\Microsoft Visual Studio `version`\\VC\\Redist\\`platform`\\`library`\\ — e as instala nos computadores de destino na mesma pasta do executável do aplicativo.  Você pode usar esse método de implantação para habilitar a instalação pelos usuários que não têm direitos de administrador ou para aplicativos que podem ser executados a partir de um compartilhamento de rede.  
  
 Se uma implantação usa módulos de mesclagem redistribuíveis e uma instalação é executada por um usuário que não tem direitos administrativos, as DLLs do [!INCLUDE[vcprvc](../build/includes/vcprvc_md.md)]não serão instaladas e o aplicativo não será executado.  Além disso, instaladores de aplicativos compilados com módulos de mesclagem que permitem a instalação por usuário instalam as bibliotecas em um local compartilhado que afeta todos os usuários do sistema.  Você pode usar a implantação local para instalar as DLLs necessárias do [!INCLUDE[vcprvc](../build/includes/vcprvc_md.md)] no diretório de um aplicativo de um usuário específico sem afetar outros usuários ou exigir direitos de administrador.  Como isso pode criar problemas da utilidade, não recomendamos a implantação local de DLLs redistribuíveis do [!INCLUDE[vcprvc](../build/includes/vcprvc_md.md)].  
  
 A implantação incorreta de bibliotecas do Visual C\+\+ pode causar erros de tempo de execução durante a execução de um aplicativo que dependem delas.  Quando o sistema operacional carrega o aplicativo, ele usa a ordem de pesquisa descrita em [LoadLibraryEx](http://go.microsoft.com/fwlink/?LinkId=132792)  
  
## A vinculação dinâmica é melhor que a vinculação estática  
 É recomendável evitar a vinculação estática ao redistribuir bibliotecas do [!INCLUDE[vcprvc](../build/includes/vcprvc_md.md)].  Embora a vinculação estática quase nunca melhora significativamente o desempenho do aplicativo, quase sempre torna a manutenção mais cara.  Por exemplo, considere um aplicativo que seja vinculado estaticamente a uma biblioteca que é atualizado com aprimoramentos de segurança – o aplicativo não pode se beneficiar, a menos que seja recompilado e reimplantado.  Em vez disso, recomendamos que você vincule dinamicamente seus aplicativos às bibliotecas de que eles dependem para que as bibliotecas possam ser atualizadas sempre que implantadas.  
  
## Consulte também  
 [Implantando aplicativos da área de trabalho](../Topic/Deploying%20Native%20Desktop%20Applications%20\(Visual%20C++\).md)   
 [Not in Build: Choosing a Deployment Strategy](http://msdn.microsoft.com/pt-br/ecd632d8-063c-4028-b785-81bba045107b)   
 [Windows Installer Deployment Overview](http://msdn.microsoft.com/pt-br/3ce4610a-b54f-404e-b650-42f4a55dfc3b)   
 [Segurança e implantação do ClickOnce](../Topic/ClickOnce%20Security%20and%20Deployment.md)   
 [Exemplos de implantação](../ide/deployment-examples.md)