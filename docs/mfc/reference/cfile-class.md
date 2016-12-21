---
title: "Classe de CFile | Microsoft Docs"
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
  - "CFile"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe de CArchive, usando com CFile"
  - "Classe de CFile"
  - "arquivos [C++], para classes"
ms.assetid: b2eb5757-d499-4e67-b044-dd7d1abaa0f8
caps.latest.revision: 22
caps.handback.revision: 12
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe de CFile
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

A classe base para o arquivo de classe da Microsoft foundation classes.  
  
## Sintaxe  
  
```  
class CFile : public CObject  
```  
  
## Membros  
  
### Construtores public  
  
|Nome|Descrição|  
|----------|---------------|  
|[CFile::CFile](../Topic/CFile::CFile.md)|Constrói um objeto de `CFile` de um caminho ou um identificador de arquivo.|  
  
### Métodos públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[CFile::Abort](../Topic/CFile::Abort.md)|Fechar um arquivo que ignora todos os erros e avisos.|  
|[CFile::Close](../Topic/CFile::Close.md)|Fechar um arquivo e exclui o objeto.|  
|[CFile::Duplicate](../Topic/CFile::Duplicate.md)|Constrói um objeto duplicado baseado em este arquivo.|  
|[CFile::Flush](../Topic/CFile::Flush.md)|Libera os dados a serem gravados ainda.|  
|[CFile::GetFileName](../Topic/CFile::GetFileName.md)|Recupera o nome do arquivo selecionado.|  
|[CFile::GetFilePath](../Topic/CFile::GetFilePath.md)|Retorna o caminho do arquivo completo do arquivo selecionado.|  
|[CFile::GetFileTitle](../Topic/CFile::GetFileTitle.md)|Recupera o título do arquivo selecionado.|  
|[CFile::GetLength](../Topic/CFile::GetLength.md)|Recupera o comprimento.|  
|[CFile::GetPosition](../Topic/CFile::GetPosition.md)|Recupera o ponteiro do arquivo atual.|  
|[CFile::GetStatus](../Topic/CFile::GetStatus.md)|Recupera o status de arquivo aberto, ou a versão estático, recupera o status do arquivo especificado \(estático, função virtual\).|  
|[CFile::LockRange](../Topic/CFile::LockRange.md)|Bloquear um intervalo de bytes em um arquivo.|  
|[CFile::Open](../Topic/CFile::Open.md)|Abre um arquivo com segurança com uma opção de teste.|  
|[CFile::Read](../Topic/CFile::Read.md)|Lê dados \(Unbuffered\) de um arquivo na posição atual do arquivo.|  
|[CFile::Remove](../Topic/CFile::Remove.md)|Exclui o arquivo especificado \(função estática\).|  
|[CFile::Rename](../Topic/CFile::Rename.md)|Renomeia o arquivo especificado \(função estática\).|  
|[CFile::Seek](../Topic/CFile::Seek.md)|Posiciona o ponteiro do arquivo atual.|  
|[CFile::SeekToBegin](../Topic/CFile::SeekToBegin.md)|Posiciona o ponteiro do arquivo atual no início do arquivo.|  
|[CFile::SeekToEnd](../Topic/CFile::SeekToEnd.md)|Posiciona o ponteiro do arquivo atual no final do arquivo.|  
|[CFile::SetFilePath](../Topic/CFile::SetFilePath.md)|Defina o caminho do arquivo completo do arquivo selecionado.|  
|[CFile::SetLength](../Topic/CFile::SetLength.md)|Altera o tamanho do arquivo.|  
|[CFile::SetStatus](../Topic/CFile::SetStatus.md)|Define o status do arquivo especificado \(estático, função virtual\).|  
|[CFile::UnlockRange](../Topic/CFile::UnlockRange.md)|Desbloqueia um intervalo de bytes em um arquivo.|  
|[CFile::Write](../Topic/CFile::Write.md)|Grava dados \(Unbuffered\) em um arquivo para a posição atual do arquivo.|  
  
### Operadores públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[ALÇA de CFile::operator](../Topic/CFile::operator%20HANDLE.md)|Um identificador para um objeto de `CFile` .|  
  
### Membros públicos de dados  
  
|Nome|Descrição|  
|----------|---------------|  
|[CFile::hFileNull](../Topic/CFile::hFileNull.md)|Determina se o objeto de `CFile` tem um identificador válido.|  
|[CFile::m\_hFile](../Topic/CFile::m_hFile.md)|Geralmente contém o identificador de arquivo do sistema operacional.|  
  
### Membros de dados protegidos  
  
|Nome|Descrição|  
|----------|---------------|  
|[CFile::m\_pTM](../Topic/CFile::m_pTM.md)|Ponteiro para o objeto de `CAtlTransactionManager` .|  
  
## Comentários  
 Fornece serviços unbuffered diretamente, binários de arquivos entrada\/saída de disco, e oferece suporte indiretamente arquivos de texto e arquivos de memória por meio de suas classes derivadas.  Os trabalhos de`CFile` em conjunto com a classe de `CArchive` para oferecer suporte a serialização de classe de base de O objeto.  
  
 A relação hierárquica entre essa classe e suas classes derivadas permite que seu programa opera sobre todos os objetos do arquivo através da interface polimorfo de `CFile` .  Um arquivo de memória, por exemplo, se comporta como um arquivo em disco.  
  
 Use `CFile` e suas classes derivadas para o disco uso geral de E\/S.  Use `ofstream` ou outras classes de iostream Microsoft para o texto formatado enviado em um arquivo no disco.  
  
 Normalmente, um arquivo em disco é aberta automaticamente a compilação de `CFile` e fechado na destruição.  As funções de membro estático permitem que você interrogar o status de um arquivo sem abrir o arquivo.  
  
 Para obter mais informações sobre como usar `CFile`, consulte os artigos [Arquivos no MFC](../../mfc/files-in-mfc.md) e [Manipular de Arquivo](../../c-runtime-library/file-handling.md)*na referência da biblioteca em tempo de execução*.  
  
## Hierarquia de herança  
 [CObject](../Topic/CObject%20Class.md)  
  
 `CFile`  
  
## Requisitos  
 **Cabeçalho:** afx.h  
  
## Consulte também  
 [O MFC exemplos DRAWCLI](../../top/visual-cpp-samples.md)   
 [Classe de CObject](../Topic/CObject%20Class.md)   
 [Gráfico da hierarquia](../../mfc/hierarchy-chart.md)   
 [Classe de CStdioFile](../Topic/CStdioFile%20Class.md)   
 [Classe de CMemFile](../../mfc/reference/cmemfile-class.md)   
 [Como: eu faço Use a classe de CFile?](http://go.microsoft.com/fwlink/?LinkId=128046)