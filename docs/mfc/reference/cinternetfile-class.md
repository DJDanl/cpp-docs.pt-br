---
title: "Classe de CInternetFile | Microsoft Docs"
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
  - "CInternetFile"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe de CInternetFile"
  - "Arquivos de Internet"
  - "Arquivos de Internet, Classe de CInternetFile"
ms.assetid: 96935681-ee71-4a8d-9783-5abc7b3e6f10
caps.latest.revision: 23
caps.handback.revision: 12
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe de CInternetFile
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Permite acesso aos arquivos em sistemas remoto usando protocolos da Internet.  
  
## Sintaxe  
  
```  
  
class CInternetFile : public CStdioFile  
  
```  
  
## Membros  
  
### Construtores protegidos  
  
|Nome|Descrição|  
|----------|---------------|  
|[CInternetFile::CInternetFile](../Topic/CInternetFile::CInternetFile.md)|Constrói um objeto de `CInternetFile` .|  
  
### Métodos públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[CInternetFile::Abort](../Topic/CInternetFile::Abort.md)|Fecha o arquivo, ignorando todos os erros e avisos.|  
|[CInternetFile::Close](../Topic/CInternetFile::Close.md)|Fecha `CInternetFile` e libera os recursos.|  
|[CInternetFile::Flush](../Topic/CInternetFile::Flush.md)|Libera o conteúdo do buffer de gravação e certifique\-se que os dados na memória são gravados no computador de destino.|  
|[CInternetFile::GetLength](../Topic/CInternetFile::GetLength.md)|Retorna o tamanho do arquivo.|  
|[CInternetFile::Read](../Topic/CInternetFile::Read.md)|Ler o número de bytes especificados.|  
|[CInternetFile::ReadString](../Topic/CInternetFile::ReadString.md)|Ler um fluxo de caracteres.|  
|[CInternetFile::Seek](../Topic/CInternetFile::Seek.md)|Reposiciona o ponteiro em um arquivo aberto.|  
|[CInternetFile::SetReadBufferSize](../Topic/CInternetFile::SetReadBufferSize.md)|Defina o tamanho do buffer onde os dados serão lidas.|  
|[CInternetFile::SetWriteBufferSize](../Topic/CInternetFile::SetWriteBufferSize.md)|Defina o tamanho do buffer onde os dados serão gravados.|  
|[CInternetFile::Write](../Topic/CInternetFile::Write.md)|Grava o número de bytes especificados.|  
|[CInternetFile::WriteString](../Topic/CInternetFile::WriteString.md)|Grava uma cadeia de caracteres NULL\- finalizada a um arquivo.|  
  
### Operadores públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[CInternetFile::operator HINTERNET](../Topic/CInternetFile::operator%20HINTERNET.md)|Um operador de conversão para uma alça da Internet.|  
  
### Membros de dados protegidos  
  
|Nome|Descrição|  
|----------|---------------|  
|[CInternetFile::m\_hFile](../Topic/CInternetFile::m_hFile.md)|Um identificador para um arquivo.|  
  
## Comentários  
 Fornece uma classe base para [CHttpFile](../Topic/CHttpFile%20Class.md) e o arquivo de [CGopherFile](../../mfc/reference/cgopherfile-class.md) classe.  Você nunca cria um objeto de `CInternetFile` diretamente.  Em vez de isso, crie um objeto de uma de suas classes derivadas chamando [CGopherConnection::OpenFile](../Topic/CGopherConnection::OpenFile.md) ou [CHttpConnection::OpenRequest](../Topic/CHttpConnection::OpenRequest.md).  Você também pode criar um objeto de `CInternetFile` chamando [CFtpConnection::OpenFile](../Topic/CFtpConnection::OpenFile.md).  
  
 As funções de membro **Abrir**, `LockRange`, `UnlockRange`, e `Duplicate` de `CInternetFile` não são implementadas para `CInternetFile`.  Se você chamar essas funções em `CInternetFile` objeto, você [CNotSupportedException](../../mfc/reference/cnotsupportedexception-class.md)obterão.  
  
 Para saber mais sobre como `CInternetFile` trabalhar com as outras classes MFC Internet, consulte o artigo [Internet que programa com WinInet](../../mfc/win32-internet-extensions-wininet.md).  
  
## Hierarquia de herança  
 [CObject](../Topic/CObject%20Class.md)  
  
 [CFile](../../mfc/reference/cfile-class.md)  
  
 [CStdioFile](../Topic/CStdioFile%20Class.md)  
  
 `CInternetFile`  
  
## Requisitos  
 **Cabeçalho:** afxinet.h  
  
## Consulte também  
 [Classe de CStdioFile](../Topic/CStdioFile%20Class.md)   
 [Gráfico da hierarquia](../../mfc/hierarchy-chart.md)   
 [Classe de CInternetConnection](../Topic/CInternetConnection%20Class.md)