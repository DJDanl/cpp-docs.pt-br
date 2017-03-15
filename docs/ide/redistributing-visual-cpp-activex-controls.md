---
title: "Redistribuindo controles ActiveX do Visual C++ | Microsoft Docs"
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
  - "controles [C++], distribuindo"
  - "controles [C++], redistribuindo"
ms.assetid: eefbb7e4-d28c-4c35-98bf-d9540cfaae83
caps.latest.revision: 18
caps.handback.revision: 18
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Redistribuindo controles ActiveX do Visual C++
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

O Visual C\+\+ 6,0 fornece controles ActiveX que você pode usar em aplicativos que você então redistribuir.  Esses controles não estão incluídos no Visual C\+\+.  Por acordes de licença para Visual C\+\+ 6,0, você pode redistribuir esses controles com aplicativos desenvolvidos em Visual C\+\+.  
  
> [!NOTE]
>  O Visual C\+\+ 6,0 não é mais suportado pela Microsoft.  
  
 Para obter uma lista dos controles redistribuíveis do Visual C\+\+ 6.0 ActiveX, consulte Common\\Redist\\Redist.txt no disco 1 do CD de produto do Visual C\+\+ 6.0.  
  
 Ao distribuir aplicativos, você deve instalar e registrar o .ocx para o controle ActiveX \(usando Regsvr32.exe\).  Além disso, você deve certificar\-se o computador de destino tem versões atuais dos seguintes arquivos do sistema \(um asterisco indica que o arquivo precisa ser registrado\):  
  
-   Asycfilt.dll  
  
-   Comcat.dll \*  
  
-   Oleaut32.dll \*  
  
-   Olepro32.dll \*  
  
-   Stdole2.tlb  
  
 Se essas dlls não estão disponíveis no sistema de destino, você precisa obtê\-los atualizados usando o mecanismo prescrito para atualizar o sistema operacional correspondente.  Você pode baixar os pacotes de serviço os mais recentes para sistemas operacionais do [http:\/\/windowsupdate.microsoft.com](http://windowsupdate.microsoft.com)Windows.  
  
 Se seu aplicativo usa um dos controles ActiveX que se conecta a um banco de dados, você deve ter Microsoft Data Access Components \(MDAC\) instalado no sistema de destino.  Para obter mais informações, consulte [Redistribuindo arquivos de suporte de banco de dados](../ide/redistributing-database-support-files.md).  
  
 Ao usar um controle ActiveX que se conecta a um banco de dados, você também precisará replicar o nome da fonte de dados no computador de destino.  Você pode fazer isso com papéis programaticamente como `ConfigDSN`.  
  
 Alguns controles ActiveX redistribuíveis tem dependências adicionais.  Para cada arquivo de .ocx no ósmio pasta \\ do sistema no CD de produto do Visual C\+\+ 6,0, há também um arquivo de .dep.  Para cada arquivo de .ocx que você deseja redistribuir, procure uma ou mais entradas de USOS no arquivo correspondente de .dep.  Se um arquivo é listado, você deve garantir que o arquivo está no computador de destino.  Alguns DLL que suportam diretamente uma necessidade de arquivo de .ocx de ser registrado.  \(Para que Regsvr32.exe foi bem\-sucedida, o computador de destino deve primeiramente conter todos as dlls que o controle carrega estaticamente.\) Além disso, se uma DLL que está listado como uma dependência também tem um arquivo de .dep no ósmio pasta \\ do sistema no CD do Visual C\+\+ 6,0, você também deve investigar que arquivo de .dep para entradas de USOS.  
  
## Consulte também  
 [Redistribuindo arquivos do Visual C\+\+](../Topic/Redistributing%20Visual%20C++%20Files.md)