---
title: "Instalando suporte do banco de dados MFC | Microsoft Docs"
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
  - "DAO [C++], instalando componentes"
  - "bancos de dados [C++], instalando suporte do banco de dados"
  - "bancos de dados [C++], MFC"
  - "instalando DAO"
  - "instalando ODBC"
  - "Componentes ODBC [C++], instalando"
  - "Drivers ODBC [C++], instalando"
ms.assetid: a6c2fc84-9e0e-4f39-a464-0bcbc415b946
caps.latest.revision: 11
caps.handback.revision: 11
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Instalando suporte do banco de dados MFC
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

##  <a name="_core_odbc_drivers_installed"></a> Drivers ODBC instalados  
 A instalação instala os seguintes drivers ODBC:  
  
-   Driver do Microsoft Access  
  
-   Driver do dBASE da Microsoft  
  
-   Driver do Microsoft Excel  
  
-   Driver do Microsoft VFP FoxPro  
  
-   Driver do Microsoft Visual FoxPro  
  
-   O Microsoft ODBC para o driver Oracle  
  
-   Driver de paradox da Microsoft  
  
-   Driver do texto da Microsoft  
  
-   Driver do Microsoft SQL Server  
  
 Para obter informações sobre como obter e drivers adicionais para obter uma lista de drivers ODBC incluídos nesta versão do Visual C\+\+, consulte [Lista de driver ODBC](../data/odbc/odbc-driver-list.md).  
  
##  <a name="_core_odbc_sdk_components_installed"></a> Componentes ODBC instalados SDK  
 Visual C\+\+ inclui muitos componentes chaves de ODBC, incluindo os arquivos de cabeçalho, as bibliotecas, as dlls, e as ferramentas necessárias.  Esses incluem o aplicativo do painel de controle do administrador de ODBC, que você usa para configurar as fontes de dados ODBC, e o gerenciador de driver ODBC.  Também são incluídos os drivers ODBC para muitos DBMSs popular, conforme listado em [Drivers ODBC instalados](#_core_odbc_drivers_installed).  
  
 SDK de ODBC oferece informações adicionais e as ferramentas para escrever e testar drivers ODBC.  Observe que a partir do Visual C\+\+ .NET, ODBC SDK é mais incluído na mídia de instalação do Visual C\+\+ .NET e está disponível como parte de [!INCLUDE[winsdkshort](../atl/reference/includes/winsdkshort_md.md)] instalado com os pré\-requisitos do Visual Studio .NET.  
  
##  <a name="_core_dao_sdk_components_installed"></a> Componentes de DAO SDK instalado  
  
> [!NOTE]
>  A Microsoft recomenda usar OLE DB ou ODBC para novos projetos.  DAO deve ser usado apenas em manter os aplicativos existentes.  
  
 Os seguintes componentes do SDK DAO são instalados por padrão:  
  
-   Microsoft Jet 4,0 \(SP3\)  
  
-   O Microsoft Jet \(3.x MDB\)  
  
-   O Microsoft Jet \(1.x, 2.x\)  
  
-   Todos os formatos de base de dados listados em [Que bases de dados posso acessar com DAO e ODBC?](../data/what-data-sources-can-i-access-with-dao-and-odbc-q.md)  
  
 No Visual C\+\+ .NET, DAO o SDK é instalado com os pré\-requisitos do Visual Studio .NET.  Execução \\ Jet \\ Jetsetup.exe.  
  
> [!NOTE]
>  A Microsoft recomenda que você use Jet 4,0 Service Pack 3 \(versão 2927,04\) ou posterior.  Jet 4,0 Service Pack 3 fornecido com o Windows 2000 e Windows ME.  Usar esta versão do Jet reduz o número de versões do Jet que devem ser testadas com seu aplicativo.  Windows XP pode enviar com outra versão do Jet.  Consulte a observação “em redistribuir componentes de DAO” em [Redistribuindo controles](../Topic/Redistributing%20Controls.md).  
  
 Se você quiser instalar outros componentes do, DAO como as classes de DAO SDK C\+\+, arquivos de exemplo, a versão ou da ajuda do windows do arquivo de ajuda de DAO, DAO instalar o SDK do Visual C\+\+ 6.0 CD\-ROM.  
  
 Para atualizações do e notícias sobre o OLE DB, consulte o site de acesso a dados universal em [http:\/\/go.microsoft.com\/fwlink\/?LinkId\=121548](http://go.microsoft.com/fwlink/?LinkId=121548).  
  
## Consulte também  
 [Programação de acesso a dados \(MFC\/ATL\)](../data/data-access-programming-mfc-atl.md)