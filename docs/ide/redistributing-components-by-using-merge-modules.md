---
title: "Redistribuindo componentes usando m&#243;dulos de mesclagem | Microsoft Docs"
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
  - "mesclar módulos, usando"
  - "redistribuindo aplicativos, usando mesclar módulos"
ms.assetid: 93b84211-bf9b-4a78-9f22-474ac2ef7840
caps.latest.revision: 21
caps.handback.revision: 21
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Redistribuindo componentes usando m&#243;dulos de mesclagem
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

O [!INCLUDE[vsprvs](../assembler/masm/includes/vsprvs_md.md)] inclui [módulos de mesclagem](http://msdn.microsoft.com/library/aa367434) para cada componente do [!INCLUDE[vcprvc](../build/includes/vcprvc_md.md)] que é licenciado para ser redistribuído com um aplicativo.  Quando um módulo de mesclagem é compilado em um arquivo de instalação do Windows Installer, ele permite a implantação de DLLs específicas para computadores que tenham uma plataforma específica.  No arquivo de instalação, especifique que os módulos de mesclagem são pré\-requisitos para seu aplicativo.  Quando o [!INCLUDE[vsprvs](../assembler/masm/includes/vsprvs_md.md)] é instalado, os módulos de mesclagem são instalados em \\Program Files\\Common Files\\Merge Modules\\. \(Somente as versões de não depuração das DLLs do [!INCLUDE[vcprvc](../build/includes/vcprvc_md.md)] podem ser redistribuídas.\) Para obter mais informações e um link para uma lista de módulos de mesclagem licenciados para redistribuição, consulte [Redistribuindo arquivos do Visual C\+\+](../Topic/Redistributing%20Visual%20C++%20Files.md).  
  
 Você pode usar os módulos de mesclagem para habilitar a instalação de DLLs redistribuíveis do [!INCLUDE[vcprvc](../build/includes/vcprvc_md.md)] na pasta %SYSTEMROOT%\\system32\\. \(O próprio [!INCLUDE[vsprvs](../assembler/masm/includes/vsprvs_md.md)] usa essa técnica.\) No entanto, a instalação nessa pasta falhará a menos que o usuário instalador tenha direitos de administrador.  
  
 É recomendável não usar módulos de mesclagem, exceto quando você não precisa reparar o aplicativo e não depende de mais de uma versão das DLLs.  Os módulos de mesclagem para versões diferentes da mesma DLL não podem ser incluídos em um instalador, e os módulos de mesclagem dificultam o reparo de DLLs independentemente de seu aplicativo.  Em vez disso, recomendamos que você instale o pacote redistribuível do [!INCLUDE[vcprvc](../build/includes/vcprvc_md.md)].  
  
## Consulte também  
 [Redistribuindo arquivos do Visual C\+\+](../Topic/Redistributing%20Visual%20C++%20Files.md)