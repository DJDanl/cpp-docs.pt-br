---
title: "Classe de CMFCFilterChunkValueImpl | Microsoft Docs"
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
  - "CMFCFilterChunkValueImpl"
  - "afxwin/CMFCFilterChunkValueImpl"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe de CMFCFilterChunkValueImpl"
ms.assetid: 3c833f23-5b88-4d08-9e09-ca6a8aec88bf
caps.latest.revision: 25
caps.handback.revision: 12
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe de CMFCFilterChunkValueImpl
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Esta é uma classe que simplifica a parte e a lógica de pares de valor de propriedade.  
  
## Sintaxe  
  
```  
class CMFCFilterChunkValueImpl : public ATL::IFilterChunkValue;  
```  
  
## Membros  
  
### Construtores public  
  
|Nome|Descrição|  
|----------|---------------|  
|[CMFCFilterChunkValueImpl::~CMFCFilterChunkValueImpl](../Topic/CMFCFilterChunkValueImpl::~CMFCFilterChunkValueImpl.md)|Destructs o objeto.|  
|[CMFCFilterChunkValueImpl::CMFCFilterChunkValueImpl](../Topic/CMFCFilterChunkValueImpl::CMFCFilterChunkValueImpl.md)|Constrói o objeto.|  
  
### Métodos públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[CMFCFilterChunkValueImpl::Clear](../Topic/CMFCFilterChunkValueImpl::Clear.md)|Limpa o ChunkValue.|  
|[CMFCFilterChunkValueImpl::CopyChunk](../Topic/CMFCFilterChunkValueImpl::CopyChunk.md)|Copia esta parte a estrutura que descreve as características de uma parte.|  
|[CMFCFilterChunkValueImpl::CopyFrom](../Topic/CMFCFilterChunkValueImpl::CopyFrom.md)|Inicializa o valor da parte de outro valor.|  
|[CMFCFilterChunkValueImpl::GetChunkGUID](../Topic/CMFCFilterChunkValueImpl::GetChunkGUID.md)|Recupera a parte GUID.|  
|[CMFCFilterChunkValueImpl::GetChunkPID](../Topic/CMFCFilterChunkValueImpl::GetChunkPID.md)|Recupera a parte PID \(ID da propriedade\).|  
|[CMFCFilterChunkValueImpl::GetChunkType](../Topic/CMFCFilterChunkValueImpl::GetChunkType.md)|Obtém o tipo da parte.|  
|[CMFCFilterChunkValueImpl::GetString](../Topic/CMFCFilterChunkValueImpl::GetString.md)|O recupera o valor da cadeia de caracteres.|  
|[CMFCFilterChunkValueImpl::GetValue](../Topic/CMFCFilterChunkValueImpl::GetValue.md)|Recupera o valor como um propvariant atribuído.|  
|[CMFCFilterChunkValueImpl::GetValueNoAlloc](../Topic/CMFCFilterChunkValueImpl::GetValueNoAlloc.md)|\(Não retorna valor atribuído de valor interno\).|  
|[CMFCFilterChunkValueImpl::IsValid](../Topic/CMFCFilterChunkValueImpl::IsValid.md)|Verifica se esse valor de propriedade é válido ou não.|  
|[CMFCFilterChunkValueImpl::SetBoolValue](../Topic/CMFCFilterChunkValueImpl::SetBoolValue.md)|Sobrecarregado.  Defina a propriedade pela chave para um valor booleano.|  
|[CMFCFilterChunkValueImpl::SetDwordValue](../Topic/CMFCFilterChunkValueImpl::SetDwordValue.md)|Defina a propriedade pela chave para um dword.|  
|[CMFCFilterChunkValueImpl::SetFileTimeValue](../Topic/CMFCFilterChunkValueImpl::SetFileTimeValue.md)|Defina a propriedade pela chave para um filetime.|  
|[CMFCFilterChunkValueImpl::SetInt64Value](../Topic/CMFCFilterChunkValueImpl::SetInt64Value.md)|Defina a propriedade pela chave para um int64.|  
|[CMFCFilterChunkValueImpl::SetIntValue](../Topic/CMFCFilterChunkValueImpl::SetIntValue.md)|Defina a propriedade pela chave para um int.|  
|[CMFCFilterChunkValueImpl::SetLongValue](../Topic/CMFCFilterChunkValueImpl::SetLongValue.md)|Defina a propriedade pela chave para um LONGO.|  
|[CMFCFilterChunkValueImpl::SetSystemTimeValue](../Topic/CMFCFilterChunkValueImpl::SetSystemTimeValue.md)|Defina a propriedade pela chave para um SystemTime.|  
|[CMFCFilterChunkValueImpl::SetTextValue](../Topic/CMFCFilterChunkValueImpl::SetTextValue.md)|Defina a propriedade como a chave para uma cadeia de caracteres Unicode.|  
  
### Métodos protegidos  
  
|Nome|Descrição|  
|----------|---------------|  
|[CMFCFilterChunkValueImpl::SetChunk](../Topic/CMFCFilterChunkValueImpl::SetChunk.md)|Uma função auxiliar que define as propriedades comuns da parte.|  
  
## Comentários  
 Para usar, você simplesmente cria uma classe de CMFCFilterChunkValueImpl do tipo correto  
  
 Exemplo:  
  
 Parte de CMFCFilterChunkValueImpl;  
  
 momento \= chunk.SetBoolValue PKEY\_IsAttachment, true \(;\)  
  
 ou  
  
 momento \= chunk.SetFileTimeValue \(PKEY\_ItemDate, ftLastModified\);  
  
## Hierarquia de herança  
 `ATL::IFilterChunkValue`  
  
 [CMFCFilterChunkValueImpl](../../mfc/reference/cmfcfilterchunkvalueimpl-class.md)  
  
## Requisitos  
 **Cabeçalho:** afxwin.h  
  
## Consulte também  
 [Classes](../Topic/MFC%20Classes.md)