---
title: "Classe de CGopherFile | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "reference"
f1_keywords: 
  - "CGopherFile"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe de CGopherFile"
  - "arquivos de protocolo de Gopher"
  - "Internet, Gopher"
ms.assetid: 3ca9898f-8cdb-4495-bbde-46d40100feda
caps.latest.revision: 23
caps.handback.revision: 11
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe de CGopherFile
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Fornece a funcionalidade para localizar e ler arquivos em um servidor de Gopher.  
  
> [!NOTE]
>  As classes `CGopherConnection`, `CGopherFile`, `CGopherFileFind`, `CGopherLocator` e seus membros foram substituídas porque não funcionam na plataforma Windows XP, mas continuarão a funcionar nas plataformas anteriores.  
  
## Sintaxe  
  
```  
class CGopherFile : public CInternetFile  
```  
  
## Membros  
  
### Construtores protegidos  
  
|Nome|Descrição|  
|----------|---------------|  
|[CGopherFile::CGopherFile](../Topic/CGopherFile::CGopherFile.md)|Constrói um objeto de `CGopherFile` .|  
  
## Comentários  
 O serviço de Gopher não permite que os usuários redijam dados em um arquivo de Gopher como funções esse serviço principalmente como uma interface menu\- baseada em para localizar informações.  As funções de membro **Gravar**, `WriteString`, e `Flush` de `CGopherFile` não são implementadas para `CGopherFile`.  Chamando essas funções em `CGopherFile` objeto, retorna [CNotSupportedException](../../mfc/reference/cnotsupportedexception-class.md).  
  
 Para saber mais sobre como `CGopherFile` trabalhar com as outras classes MFC Internet, consulte o artigo [Internet que programa com WinInet](../../mfc/win32-internet-extensions-wininet.md).  
  
## Hierarquia de herança  
 [CObject](../Topic/CObject%20Class.md)  
  
 [CFile](../../mfc/reference/cfile-class.md)  
  
 [CStdioFile](../Topic/CStdioFile%20Class.md)  
  
 [CInternetFile](../../mfc/reference/cinternetfile-class.md)  
  
 `CGopherFile`  
  
## Requisitos  
 **Cabeçalho:** afxinet.h  
  
## Consulte também  
 [Classe de CInternetFile](../../mfc/reference/cinternetfile-class.md)   
 [Gráfico da hierarquia](../../mfc/hierarchy-chart.md)   
 [Classe de CInternetFile](../../mfc/reference/cinternetfile-class.md)   
 [Classe de CGopherLocator](../Topic/CGopherLocator%20Class.md)   
 [Classe de CGopherFileFind](../../mfc/reference/cgopherfilefind-class.md)   
 [Classe de CGopherConnection](../../mfc/reference/cgopherconnection-class.md)