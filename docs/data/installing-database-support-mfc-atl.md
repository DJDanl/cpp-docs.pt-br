---
title: "Instalando o suporte a banco de dados (MFC/ATL) | Microsoft Docs"
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
  - "ATL [C++], suporte a banco de dados"
  - "acesso a dados [C++], instalando suporte do banco de dados"
  - "bancos de dados [C++], instalando suporte do banco de dados"
  - "instalando suporte do banco de dados"
ms.assetid: 3820ba96-4fb8-4405-83dd-bb3bc5998667
caps.latest.revision: 10
caps.handback.revision: 10
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Instalando o suporte a banco de dados (MFC/ATL)
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Quando você executa a instalação do Visual C\+\+ .NET, os seguintes componentes de banco de dados são instalados automaticamente:  
  
-   Todos os componentes de ATL OLE DB necessários.  Para obter mais informações, consulte [Instalando suporte do banco de dados ATL](../data/installing-atl-database-support.md).  
  
-   Um conjunto de drivers ODBC com gerenciador de driver ODBC e programa de administrador ODBC.  Para obter mais informações, consulte "Drivers ODBC instalados" e "Componentes ODBC SDK instalados" em [Instalando o suporte ao banco de dados MFC](../data/installing-mfc-database-support.md).  
  
-   Componentes necessários do SDK de DAO.  Inclui arquivos de Ajuda, que não estão integrados com esta documentação.  No entanto, se você trabalha com o DAO, precisa instalar uma versão do Jet compatível com o sistema operacional.  Para obter mais informações, consulte "Componentes ODBC SDK instalados" em [Instalando o suporte ao banco de dados MFC](../data/installing-mfc-database-support.md).  
  
 Como parte da instalação de linha de base, o programa de instalação também instala o Microsoft Data Access Components \(MDAC\), que são necessários para dar suporte ao acesso a dados de programação no Visual C\+\+ .NET.  
  
 Visual C\+\+ .NET instala o SDK do MDAC 2.7.  Você deve verificar o site de Acesso a Dados Universal da Microsoft na Web em [http:\/\/go.microsoft.com\/fwlink\/?LinkId\=121548](http://go.microsoft.com/fwlink/?LinkId=121548) para atualizações e notícias sobre o SDK do MDAC.  
  
 Se você estiver redistribuindo aplicativos de acesso de dados, também deve ter o programa de redistribuição MDAC 2.7.  O SDK do MDAC 2.7 foi projetado para uso com o programa de redistribuição MDAC 2.7 \(Mdac\_typ.exe\) incluído no diretório MDAC no CD\-ROM de pré\-requisitos do Visual Studio .NET.  Você também pode baixar Mdac\_typ.exe do link de download MDAC 2.7 SDK listado anteriormente.  Para obter mais informações sobre como redistribuir componentes, consulte [Redistribuindo controles](../Topic/Redistributing%20Controls.md).  
  
## Consulte também  
 [Acesso a dados](../Topic/Data%20Access%20in%20Visual%20C++.md)