---
title: "Classe de CFileFind | Microsoft Docs"
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
  - "CFileFind"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe de CFileFind"
  - "arquivos [C++], localizando"
  - "Internet arquivos [C++], localizando"
  - "arquivos locais"
  - "arquivos locais, procure"
  - "URLS [C++], procure"
ms.assetid: 9990068c-b023-4114-9580-a50182d15240
caps.latest.revision: 22
caps.handback.revision: 12
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe de CFileFind
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Executar pesquisas locais de arquivo e é a classe base para [CGopherFileFind](../../mfc/reference/cgopherfilefind-class.md) e [CFtpFileFind](../Topic/CFtpFileFind%20Class.md), que executam pesquisas de arquivo da Internet.  
  
## Sintaxe  
  
```  
class CFileFind : public CObject  
```  
  
## Membros  
  
### Construtores public  
  
|Nome|Descrição|  
|----------|---------------|  
|[CFileFind::CFileFind](../Topic/CFileFind::CFileFind.md)|Constrói um objeto de `CFileFind` .|  
  
### Métodos públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[CFileFind::Close](../Topic/CFileFind::Close.md)|Fecha a solicitação de pesquisa.|  
|[CFileFind::FindFile](../Topic/CFileFind::FindFile.md)|Procura um diretório por um nome de arquivo especificado.|  
|[CFileFind::FindNextFile](../Topic/CFileFind::FindNextFile.md)|Uma pesquisa continua do arquivo de uma chamada anterior a [FindFile](../Topic/CFileFind::FindFile.md).|  
|[CFileFind::GetCreationTime](../Topic/CFileFind::GetCreationTime.md)|Obtém o tempo que o arquivo foi criado.|  
|[CFileFind::GetFileName](../Topic/CFileFind::GetFileName.md)|Obtém o nome, incluindo a extensão, o arquivo encontrado|  
|[CFileFind::GetFilePath](../Topic/CFileFind::GetFilePath.md)|Obtém o caminho para o arquivo encontrado.|  
|[CFileFind::GetFileTitle](../Topic/CFileFind::GetFileTitle.md)|Obtém o título do arquivo encontrado.  o título não inclui a extensão.|  
|[CFileFind::GetFileURL](../Topic/CFileFind::GetFileURL.md)|Obtém o URL, incluindo o caminho do arquivo, o arquivo encontrado.|  
|[CFileFind::GetLastAccessTime](../Topic/CFileFind::GetLastAccessTime.md)|Obtém o tempo que o arquivo foi acessado pela última vez.|  
|[CFileFind::GetLastWriteTime](../Topic/CFileFind::GetLastWriteTime.md)|Obtém o tempo que o arquivo foi modificado pela última vez e salvo.|  
|[CFileFind::GetLength](../Topic/CFileFind::GetLength.md)|Obtém o tamanho do arquivo encontrado, em bytes.|  
|[CFileFind::GetRoot](../Topic/CFileFind::GetRoot.md)|Obtém o diretório raiz do arquivo encontrado.|  
|[CFileFind::IsArchived](../Topic/CFileFind::IsArchived.md)|Determina se o arquivo é encontrado as.|  
|[CFileFind::IsCompressed](../Topic/CFileFind::IsCompressed.md)|Determina se o arquivo encontrado será compactado.|  
|[CFileFind::IsDirectory](../Topic/CFileFind::IsDirectory.md)|Determina se o arquivo for encontrado um diretório.|  
|[CFileFind::IsDots](../Topic/CFileFind::IsDots.md)|Determina se o nome do arquivo localizado tem o nome “.” ou “. ”, indicando que é realmente um diretório.|  
|[CFileFind::IsHidden](../Topic/CFileFind::IsHidden.md)|Determina se o arquivo está oculto encontrado.|  
|[CFileFind::IsNormal](../Topic/CFileFind::IsNormal.md)|Determina se o arquivo localizado é normal \(ou seja não tem outros atributos\).|  
|[CFileFind::IsReadOnly](../Topic/CFileFind::IsReadOnly.md)|Determina se o arquivo encontrado é somente leitura.|  
|[CFileFind::IsSystem](../Topic/CFileFind::IsSystem.md)|Determina se o arquivo for encontrado um arquivo do sistema.|  
|[CFileFind::IsTemporary](../Topic/CFileFind::IsTemporary.md)|Determina se o arquivo temporário. é encontrado|  
|[CFileFind::MatchesMask](../Topic/CFileFind::MatchesMask.md)|Indica os atributos de arquivo desejado do arquivo a ser encontrado.|  
  
### Métodos protegidos  
  
|Nome|Descrição|  
|----------|---------------|  
|[CFileFind::CloseContext](../Topic/CFileFind::CloseContext.md)|Fecha o arquivo especificado pelo identificador atual de pesquisa.|  
  
### Membros de dados protegidos  
  
|Nome|Descrição|  
|----------|---------------|  
|[CFileFind::m\_pTM](../Topic/CFileFind::m_pTM.md)|Ponteiro para um objeto de `CAtlTransactionManager` .|  
  
## Comentários  
 `CFileFind` inclui funções de membro que começam uma pesquisa, encontra um arquivo, e retornam título, o nome, ou o caminho do arquivo.  Para pesquisas da Internet, a função de membro [GetFileURL](../Topic/CFileFind::GetFileURL.md) retorna o URL do arquivo.  
  
 `CFileFind` é a classe base para outras duas classes MFC criadas para procurar tipos de servidor específicos: especificamente `CGopherFileFind` funciona com os servidores de Gopher, e trabalhos de `CFtpFileFind` especificamente com servidores FTP.  Juntas, essas três classes fornecem um mecanismo direto para o cliente localizar arquivos, independentemente do protocolo do servidor, o tipo de arquivo, ou local, em um computador local ou em um servidor remoto.  
  
 O código a seguir enumerará todos os arquivos no diretório atual, a impressão o nome de cada arquivo:  
  
 [!code-cpp[NVC_MFCFiles#31](../../mfc/codesnippet/CPP/cfilefind-class_1.cpp)]  
  
 Para manter o exemplo simples, esse código usa a classe de biblioteca de `cout` C\+\+ padrão.  A linha de `cout` pode ser substituída por uma chamada a `CListBox::AddString`, por exemplo, em um programa com uma interface gráfica do usuário.  
  
 Para obter mais informações sobre como usar `CFileFind` e outras classes de WinInet, consulte o artigo [Internet que programa com WinInet](../../mfc/win32-internet-extensions-wininet.md).  
  
## Hierarquia de herança  
 [CObject](../Topic/CObject%20Class.md)  
  
 `CFileFind`  
  
## Requisitos  
 **Cabeçalho:** afx.h  
  
## Consulte também  
 [Classe de CObject](../Topic/CObject%20Class.md)   
 [Gráfico da hierarquia](../../mfc/hierarchy-chart.md)   
 [Classe de CFtpFileFind](../Topic/CFtpFileFind%20Class.md)   
 [Classe de CGopherFileFind](../../mfc/reference/cgopherfilefind-class.md)   
 [Classe de CInternetFile](../../mfc/reference/cinternetfile-class.md)   
 [Classe de CGopherFile](../../mfc/reference/cgopherfile-class.md)   
 [Classe de CHttpFile](../Topic/CHttpFile%20Class.md)