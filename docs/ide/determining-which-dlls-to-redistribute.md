---
title: "Determinando quais DLLs devem ser redistribu&#237;das | Microsoft Docs"
ms.custom: ""
ms.date: "12/14/2016"
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
  - "implantação de aplicativos [C++], Redistribuição de DLLs"
  - "dependências [C++], implantação de aplicativos e"
  - "implantando aplicativos [C++], Redistribuição de DLLs"
  - "DLLs [C++], redistribuindo"
  - "redistribuindo DLLs"
ms.assetid: f7a2cb42-fb48-42ab-abd2-b35e2fd5601a
caps.latest.revision: 31
caps.handback.revision: 31
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Determinando quais DLLs devem ser redistribu&#237;das
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Quando você cria um aplicativo que usa as DLLs fornecidas pelo Visual Studio, os usuários do seu aplicativo também devem ter essas DLLs em seus computadores para a execução do aplicativo.  Como a maioria dos usuários provavelmente não tiver instalado o Visual Studio, você deve fornecer essas DLLs para eles.  Visual Studio torna essas DLLs disponíveis como bibliotecas redistribuíveis que você pode incluir no instalador de seu aplicativo.  
  
 As DLLs redistribuíveis estão incluídas na instalação do Visual Studio.  Por padrão, eles são instalados na pasta arquivos de programas \(x86\) \\Microsoft Visual Studio version\\VC\\Redist.  Para facilitar para incluí\-los com seu instalador, eles também estão disponíveis como autônomos pacotes redistribuíveis do Microsoft Download Center.  Esses são executáveis que instala os arquivos redistribuíveis no computador do usuário.  A versão do pacote redistribuível deve corresponder à versão do conjunto de ferramentas do Visual Studio usado para criar seu aplicativo.  Para localizar um pacote redistribuível correspondente, pesquise o [Microsoft Download Center](http://go.microsoft.com/fwlink/p/?LinkId=158431) para "Visual C\+\+ redistribuível pacotes".  
  
 Para determinar quais DLLs necessário redistribuir com seu aplicativo, colete uma lista de DLLs que seu aplicativo depende.  Uma maneira de coletar a lista é executar o Dependency Walker \(depends.exe\), conforme descrito em [Noções básicas sobre as dependências de um aplicativo do Visual C\+\+](../ide/understanding-the-dependencies-of-a-visual-cpp-application.md).  
  
 Quando você tem a lista de dependências, compará\-la à lista em qualquer arquivo Redist no diretório de instalação do Microsoft Visual Studio ou a "lista REDIST" de DLLs redistribuíveis mencionada na seção "Código distribuível" dos termos de licença de Software Microsoft para sua cópia do Visual Studio.  Visual Studio 2013, a lista está disponível online em [Código distribuível para o Microsoft Visual Studio e SDK do Microsoft Visual Studio 2013](http://go.microsoft.com/fwlink/p/?LinkId=313603).  Você não pode redistribuir todos os arquivos que estão incluídos no Visual Studio; Você só poderá redistribuir os arquivos que são especificados em Redist ou a online "lista REDIST." As versões de depuração de aplicativos e a depuração do Visual C\+\+ várias DLLs não são redistribuíveis.  Para obter mais informações, consulte [Escolhendo uma método de implantação](../ide/choosing-a-deployment-method.md).  
  
 A tabela a seguir descreve algumas das DLLs Visual C\+\+ que seu aplicativo pode depender.  
  
|Biblioteca do Visual C\+\+|Descrição|Aplica\-se a|  
|--------------------------------|---------------|------------------|  
|msvcr*versão*. dll|C Runtime Library \(CRT\) para código nativo.|Aplicativos que usam o [Recursos da biblioteca CRT](../c-runtime-library/crt-library-features.md).|  
|msvcp*versão*. dll|Biblioteca padrão C\+\+ para código nativo.|Aplicativos que usam o [biblioteca padrão C\+\+](../standard-library/cpp-standard-library-reference.md).|  
|MFC*versão*. dll|Microsoft Foundation Classes \(MFC\) de biblioteca.|Aplicativos que usam o [biblioteca MFC](../mfc/mfc-desktop-applications.md).|  
|MFC*versão*u.dll|Biblioteca MFC com suporte a Unicode.|Aplicativos que usam o [biblioteca MFC](../mfc/mfc-desktop-applications.md) e requer suporte a Unicode.|  
|mfcmifc80|Biblioteca de Interfaces gerenciadas do MFC.|Aplicativos que usam o [biblioteca MFC](../mfc/mfc-desktop-applications.md) com [Controles de Windows Forms](../Topic/Windows%20Forms%20Controls.md).|  
|mfcm*versão*. dll|Biblioteca gerenciada do MFC.|Aplicativos que usam o [biblioteca MFC](../mfc/mfc-desktop-applications.md) com [Controles de Windows Forms](../Topic/Windows%20Forms%20Controls.md).|  
|mfcm*versão*u.dll|Biblioteca gerenciada MFC com suporte a Unicode.|Aplicativos que usam o [biblioteca MFC](../mfc/mfc-desktop-applications.md) com [Controles de Windows Forms](../Topic/Windows%20Forms%20Controls.md) e requer suporte a Unicode.|  
  
> [!NOTE]
>  Você não precisa redistribuir o Active Template Library como uma DLL separada.  Sua funcionalidade foi movida para cabeçalhos e uma biblioteca estática.  
  
 Para obter mais informações sobre como redistribuir essas DLLs com seu aplicativo, consulte [Redistribuindo arquivos do Visual C\+\+](../Topic/Redistributing%20Visual%20C++%20Files.md).  Para obter exemplos, consulte [Exemplos de implantação](../ide/deployment-examples.md).  
  
 Normalmente, não é necessário redistribuir DLLs do sistema porque fazem parte do sistema operacional.  No entanto, pode haver exceções, por exemplo, quando o aplicativo será executado em várias versões dos sistemas operacionais da Microsoft.  Nesse caso, não deixe de ler os termos de licença correspondente.  Além disso, tente fazer o sistema DLLs atualizados por meio do Windows Update, os service packs ou usando pacotes redistribuíveis disponibilizados pela Microsoft.  Você poderá localizar pacotes disponíveis ao pesquisar o [Microsoft Support](http://support.microsoft.com/) site ou o [Microsoft Download Center](http://go.microsoft.com/fwlink/p/?LinkId=158431).  
  
## Consulte também  
 [Escolhendo uma método de implantação](../ide/choosing-a-deployment-method.md)   
 [Implantando aplicativos da área de trabalho](../Topic/Deploying%20Native%20Desktop%20Applications%20\(Visual%20C++\).md)