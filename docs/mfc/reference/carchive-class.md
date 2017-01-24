---
title: "Classe de CArchive | Microsoft Docs"
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
  - "CArchive"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe de CArchive"
  - "armazenamento de dados [C++], Classe de CArchive"
  - "E/S [MFC], arquivando objetos"
  - "serialização [C++], Classe de CArchive"
  - "armazenamento [C++], Classe de CArchive"
ms.assetid: 9e950d23-b874-456e-ae4b-fe00781a7699
caps.latest.revision: 21
caps.handback.revision: 11
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe de CArchive
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Permite que você salve uma rede complexa de objetos em um formulário binária \(geralmente armazenamento não\-volátil de disco\) que persistir após esses objetos são excluídos.  
  
## Sintaxe  
  
```  
class CArchive  
```  
  
## Membros  
  
### Construtores public  
  
|Nome|Descrição|  
|----------|---------------|  
|[CArchive::CArchive](../Topic/CArchive::CArchive.md)|Cria um objeto de `CArchive` .|  
  
### Métodos públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[CArchive::Abort](../Topic/CArchive::Abort.md)|Fechar um arquivo neutro sem lançar uma exceção.|  
|[CArchive::Close](../Topic/CArchive::Close.md)|Libera dados não\-escritos e disconexões de `CFile`.|  
|[CArchive::Flush](../Topic/CArchive::Flush.md)|Dados não\-escritos de resplendores de buffer do arquivamento.|  
|[CArchive::GetFile](../Topic/CArchive::GetFile.md)|Obtém o ponteiro do objeto de `CFile` para esse arquivo neutro.|  
|[CArchive::GetObjectSchema](../Topic/CArchive::GetObjectSchema.md)|Chamada de função de `Serialize` para determinar qual versão do objeto que desserializado\-lo.|  
|[CArchive::IsBufferEmpty](../Topic/CArchive::IsBufferEmpty.md)|Determina se o buffer foi esvaziado durante o windows que os soquetes recebem o processo.|  
|[CArchive::IsLoading](../Topic/CArchive::IsLoading.md)|Determina se o arquivo neutro é carregar.|  
|[CArchive::IsStoring](../Topic/CArchive::IsStoring.md)|Determina se o arquivo neutro estiver armazenando.|  
|[CArchive::MapObject](../Topic/CArchive::MapObject.md)|Coloca os objetos no mapa que não são serializados para o arquivo, mas que está disponível para os subobjects referenciem.|  
|[CArchive::Read](../Topic/CArchive::Read.md)|Ler bytes crua.|  
|[CArchive::ReadClass](../Topic/CArchive::ReadClass.md)|Ler uma referência da classe armazenadas anteriormente com `WriteClass`.|  
|[CArchive::ReadObject](../Topic/CArchive::ReadObject.md)|Chama a função de `Serialize` de um objeto para carregar.|  
|[CArchive::ReadString](../Topic/CArchive::ReadString.md)|Ler uma única linha de texto.|  
|[CArchive::SerializeClass](../Topic/CArchive::SerializeClass.md)|Leitura ou grava a referência da classe ao objeto de `CArchive` dependendo da direção de `CArchive`.|  
|[CArchive::SetLoadParams](../Topic/CArchive::SetLoadParams.md)|Defina o tamanho para que a matriz aumenta a carga.  Deve ser chamado antes que qualquer objeto é carregado ou antes que `MapObject` ou `ReadObject` serem chamados.|  
|[CArchive::SetObjectSchema](../Topic/CArchive::SetObjectSchema.md)|Defina o esquema de objeto armazenado no objeto do arquivamento.|  
|[CArchive::SetStoreParams](../Topic/CArchive::SetStoreParams.md)|Define o hash o tamanho e o tamanho do bloco de mapa usado para identificar objetos exclusivos durante o processo de serialização.|  
|[CArchive::Write](../Topic/CArchive::Write.md)|Grava bytes crua.|  
|[CArchive::WriteClass](../Topic/CArchive::WriteClass.md)|Grava uma referência a `CRuntimeClass` a `CArchive`.|  
|[CArchive::WriteObject](../Topic/CArchive::WriteObject.md)|Chama a função de `Serialize` de um objeto para armazenar.|  
|[CArchive::WriteString](../Topic/CArchive::WriteString.md)|Grava uma única linha de texto.|  
  
### Operadores públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[CArchive::operator \<\<](../Topic/CArchive::operator%20%3C%3C.md)|Objetos e tipos primitivos dos armazenamentos para o arquivamento.|  
|[CArchive::operator \>\>](../Topic/CArchive::operator%20%3E%3E.md)|Objetos e tipos primitivos carrega do arquivamento.|  
  
### Membros públicos de dados  
  
|Nome|Descrição|  
|----------|---------------|  
|[CArchive::m\_pDocument](../Topic/CArchive::m_pDocument.md)||  
  
## Comentários  
 `CArchive` não tem uma classe base.  
  
 Mais tarde você pode carregar os objetos de armazenamento persistente, os reconstituindo na memória.  Este processo de fazer dados persistentes é chamado “serialização.”  
  
 Você pode pensar um objeto do arquivamento como um tipo de fluxo binário.  Como um fluxo de arquivos entrada\/saída, um arquivo neutro é associado a um arquivo e permite a escrita e leitura de dados armazenados em buffer para o armazenamento.  As seqüências de processos de um fluxo de arquivos entrada\/saída de caracteres ASCII, mas um arquivo neutro processam dados binários de objeto em um formato eficiente, nonredundant.  
  
 Você deve criar um objeto de [CFile](../../mfc/reference/cfile-class.md) antes que você possa criar um objeto de `CArchive` .  Além de isso, você deve garantir que o status de carga\/armazenamento do arquivamento seja compatível com o modo de abertura do arquivo.  Você está limitado a um arquivo neutro ativo por arquivo.  
  
 Quando você constrói um objeto de `CArchive` , você anexa a um objeto da classe `CFile` \(ou uma classe derivada\) que representa um arquivo aberto.  Você também especifica se o arquivo neutro será usado carregar ou armazenando.  Um objeto de `CArchive` pode processar não apenas tipos primitivos mas também objetos de [CObject](../Topic/CObject%20Class.md)\- classes derivadas criadas para a serialização.  Uma classe serializável usualmente possui uma função de membro de `Serialize` , e usa geralmente macros de [DECLARE\_SERIAL](../Topic/DECLARE_SERIAL.md) e de [IMPLEMENT\_SERIAL](../Topic/IMPLEMENT_SERIAL.md) , como descritos na classe `CObject`.  
  
 Os operadores sobrecarregados de extração \(**\>\>**\) e insert \(**\<\<**\) são as interfaces de programação convenientes do arquivamento que oferecem suporte a tipos primitivos e `CObject`\- classes derivadas.  
  
 Programação de suporte de`CArchive` também com os soquetes do windows MFC classes [CSocket](../../mfc/reference/csocket-class.md) e [CSocketFile](../Topic/CSocketFile%20Class.md).  O oferece suporte a função de membro de [IsBufferEmpty](../Topic/CArchive::IsBufferEmpty.md) que uso.  
  
 Para obter mais informações sobre `CArchive`, consulte os artigos [serialização](../Topic/Serialization%20in%20MFC.md) e [Soquetes do windows: usando os soquetes com arquivos mortos](../../mfc/windows-sockets-using-sockets-with-archives.md).  
  
## Hierarquia de herança  
 `CArchive`  
  
## Requisitos  
 **Cabeçalho:** afx.h  
  
## Consulte também  
 [Gráfico da hierarquia](../../mfc/hierarchy-chart.md)   
 [Classe de CFile](../../mfc/reference/cfile-class.md)   
 [Classe de CObject](../Topic/CObject%20Class.md)   
 [Classe de CSocket](../../mfc/reference/csocket-class.md)   
 [Classe de CSocketFile](../Topic/CSocketFile%20Class.md)