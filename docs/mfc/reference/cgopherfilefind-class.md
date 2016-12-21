---
title: "Classe de CGopherFileFind | Microsoft Docs"
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
  - "CGopherFileFind"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe de CGopherFileFind"
  - "o arquivo procura [C++]"
ms.assetid: 8465a979-6323-496d-ab4b-e81383fb999d
caps.latest.revision: 21
caps.handback.revision: 11
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe de CGopherFileFind
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Os auxílios em O arquivo pesquisas de servidores de Gopher.  
  
> [!NOTE]
>  As classes `CGopherConnection`, `CGopherFile`, `CGopherFileFind`, `CGopherLocator` e seus membros foram substituídas porque não funcionam na plataforma Windows XP, mas continuarão a funcionar nas plataformas anteriores.  
  
## Sintaxe  
  
```  
class CGopherFileFind : public CFileFind  
```  
  
## Membros  
  
### Construtores public  
  
|Nome|Descrição|  
|----------|---------------|  
|[CGopherFileFind::CGopherFileFind](../Topic/CGopherFileFind::CGopherFileFind.md)|Constrói um objeto de `CGopherFileFind` .|  
  
### Métodos públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[CGopherFileFind::FindFile](../Topic/CGopherFileFind::FindFile.md)|Localiza um arquivo em um servidor de Gopher.|  
|[CGopherFileFind::FindNextFile](../Topic/CGopherFileFind::FindNextFile.md)|Uma pesquisa continua do arquivo de uma chamada anterior a [FindFile](../Topic/CGopherFileFind::FindFile.md).|  
|[CGopherFileFind::GetCreationTime](../Topic/CGopherFileFind::GetCreationTime.md)|Obtém o tempo que o arquivo especificado foi criado.|  
|[CGopherFileFind::GetLastAccessTime](../Topic/CGopherFileFind::GetLastAccessTime.md)|Obtém o tempo que o arquivo especificado foi acessado pela última vez.|  
|[CGopherFileFind::GetLastWriteTime](../Topic/CGopherFileFind::GetLastWriteTime.md)|Obtém o tempo que o arquivo especificado a última gravados.|  
|[CGopherFileFind::GetLength](../Topic/CGopherFileFind::GetLength.md)|Obtém o tamanho do arquivo encontrado, em bytes.|  
|[CGopherFileFind::GetLocator](../Topic/CGopherFileFind::GetLocator.md)|Obter um objeto de `CGopherLocator` .|  
|[CGopherFileFind::GetScreenName](../Topic/CGopherFileFind::GetScreenName.md)|Obtém o nome de uma tela de Gopher.|  
|[CGopherFileFind::IsDots](../Topic/CGopherFileFind::IsDots.md)|Testa marcadores de diretório atual e o diretório pai para percorrer os arquivos.|  
  
## Comentários  
 `CGopherFileFind` inclui funções de membro que começam uma pesquisa, encontra um arquivo, e retornam a URL de um arquivo.  
  
 Outras classes MFC criadas para a Internet e o arquivo local incluem [CFtpFileFind](../Topic/CFtpFileFind%20Class.md) pesquisados e [CFileFind](../../mfc/reference/cfilefind-class.md).  `CGopherFileFind`, juntamente com essas classes fornecem um mecanismo direto para que o usuário localizar arquivos específicos, independentemente do protocolo do servidor, o tipo de arquivo, ou local \(um computador local ou um servidor remoto.\) Observe que não há nenhuma classe MFC para procurar em servidores HTTP porque HTTP não oferece suporte direto a manipulação de arquivo necessária por pesquisas.  
  
> [!NOTE]
>  `CGopherFileFind` não suporta as seguintes funções de membro da classe base [CFileFind](../../mfc/reference/cfilefind-class.md):  
  
-   [GetRoot](../Topic/CFileFind::GetRoot.md)  
  
-   [GetFileName](../Topic/CFileFind::GetFileName.md)  
  
-   [GetFilePath](../Topic/CFileFind::GetFilePath.md)  
  
-   [GetFileTitle](../Topic/CFileFind::GetFileTitle.md)  
  
-   [GetFileURL](../Topic/CFileFind::GetFileURL.md)  
  
 Além de isso, quando usada com `CGopherFileFind`, a função de membro [IsDots](../Topic/CFileFind::IsDots.md) de `CFileFind` é sempre **Falso**.  
  
 Para obter mais informações sobre como usar `CGopherFileFind` e outras classes de WinInet, consulte o artigo [Internet que programa com WinInet](../../mfc/win32-internet-extensions-wininet.md).  
  
## Hierarquia de herança  
 [CObject](../Topic/CObject%20Class.md)  
  
 [CFileFind](../../mfc/reference/cfilefind-class.md)  
  
 `CGopherFileFind`  
  
## Requisitos  
 **Cabeçalho:** afxinet.h  
  
## Consulte também  
 [Classe de CFileFind](../../mfc/reference/cfilefind-class.md)   
 [Gráfico da hierarquia](../../mfc/hierarchy-chart.md)   
 [Classe de CFtpFileFind](../Topic/CFtpFileFind%20Class.md)   
 [Classe de CFileFind](../../mfc/reference/cfilefind-class.md)   
 [Classe de CInternetFile](../../mfc/reference/cinternetfile-class.md)   
 [Classe de CGopherFile](../../mfc/reference/cgopherfile-class.md)   
 [Classe de CHttpFile](../Topic/CHttpFile%20Class.md)