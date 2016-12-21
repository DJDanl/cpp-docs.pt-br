---
title: "Vincula&#231;&#227;o autom&#225;tica da vers&#227;o da biblioteca MFC | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
f1_keywords: 
  - "defaultlib"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "links automáticos [C++]"
  - "defaultlib em MFC"
  - "vinculando [C++]"
  - "vinculando [C++], automático da versão da biblioteca MFC"
  - "vinculando [C++], de MFC"
  - "Bibliotecas MFC, vinculando a"
  - "Bibliotecas MFC, versões"
ms.assetid: 02af4a20-2034-4fce-b200-c2202c3c8311
caps.latest.revision: 11
caps.handback.revision: 7
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Vincula&#231;&#227;o autom&#225;tica da vers&#227;o da biblioteca MFC
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Em versões de MFC antes da versão 3,0 \(a versão 2,0 do Visual C\+\+\), você precisava especificar manualmente a versão correta de biblioteca MFC na lista de entrada de bibliotecas do vinculador.  MFC com a versão 3,0 e posteriores, não é mais necessário especificar manualmente a versão da biblioteca MFC.  Em vez disso, os arquivos de cabeçalho MFC determinar automaticamente a versão correta da biblioteca MFC, com base nos valores definidos com `#define`, como **\_DEBUG** ou **\_UNICODE**.  Os arquivos de cabeçalho MFC adicionam as políticas de **\/defaultlib** que instruem o vinculador o link em uma versão específica de biblioteca MFC.  
  
 Por exemplo, o seguinte fragmento de código do arquivo de cabeçalho de AFX.H instrui o vinculador para vincular na versão de NAFXCWD.LIB ou de NAFXCW.LIB MFC, dependendo se você está usando a versão de depuração MFC:  
  
 `#ifndef _UNICODE`  
  
 `#ifdef _DEBUG`  
  
 `#pragma comment(lib, "nafxcwd.lib")`  
  
 `#else`  
  
 `#pragma comment(lib, "nafxcw.lib")`  
  
 `#endif`  
  
 `#else`  
  
 `#ifdef _DEBUG`  
  
 `#pragma comment(lib, "uafxcwd.lib")`  
  
 `#else`  
  
 `#pragma comment(lib, "uafxcw.lib")`  
  
 `#endif`  
  
 `#endif`  
  
 Os arquivos de cabeçalho MFC também são vinculados em todas as bibliotecas necessários, inclusive bibliotecas MFC, bibliotecas do Win32, bibliotecas OLE, bibliotecas criadas com OLE DB exemplos, bibliotecas ODBC, e assim por diante.  As bibliotecas do Win32 incluem Kernel32.Lib, User32.Lib, e GDI32.Lib.  
  
## Consulte também  
 [Versões de biblioteca MFC](../mfc/mfc-library-versions.md)