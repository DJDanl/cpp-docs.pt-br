---
title: "Classe SRWLock | Microsoft Docs"
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
  - "corewrappers/Microsoft::WRL::Wrappers::SRWLock"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe SRWLock"
ms.assetid: 4fa250e3-5f29-4b06-ac24-61b6c04ade93
caps.latest.revision: 5
caps.handback.revision: 5
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe SRWLock
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Representa um slim bloqueio de leitor\/gravador.  
  
## Sintaxe  
  
```  
class SRWLock;  
```  
  
## Comentários  
 Slim um bloqueio de leitor\/gravador é usado para sincronizar o acesso pelos threads a um objeto ou recurso.  Para obter mais informações, consulte [Funções de sincronização](http://msdn.microsoft.com/pt-br/9b6359c2-0113-49b6-83d0-316ad95aba1b) na Biblioteca MSDN.  
  
## Membros  
  
### Typedefs Públicas  
  
|||  
|-|-|  
|**SyncLockExclusive**|Sinônimo para um objeto de SRWLock que é adquirido em modo exclusivo.|  
|**SyncLockShared**|Sinônimo para um objeto de SRWLock que é adquirido no modo compartilhado.|  
  
### Construtores Públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[Construtor SRWLock::SRWLock](../windows/srwlock-srwlock-constructor.md)|Inicializa uma nova instância da classe de SRWLock.|  
|[Destruidor SRWLock::~SRWLock](../windows/srwlock-tilde-srwlock-destructor.md)|Deinitializes uma instância da classe de SRWLock.|  
  
### Métodos Públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[Método SRWLock::LockExclusive](../windows/srwlock-lockexclusive-method.md)|Adquire um objeto de SRWLock no modo exclusivo.|  
|[Método SRWLock::LockShared](../windows/srwlock-lockshared-method.md)|Adquire um objeto de SRWLock no modo compartilhado.|  
|[Método SRWLock::TryLockExclusive](../windows/srwlock-trylockexclusive-method.md)|Tentativas de adquirir um objeto de SRWLock no modo exclusivo para o atual ou o objeto especificado de SRWLock.|  
|[Método SRWLock::TryLockShared](../windows/srwlock-trylockshared-method.md)|Tentativas de adquirir um objeto de SRWLock no modo compartilhado para o atual ou o objeto especificado de SRWLock.|  
  
### Membro de dados protegido  
  
|Nome|Descrição|  
|----------|---------------|  
|[Membro de dados SRWLock::SRWLock\_](../windows/srwlock-srwlock-data-member.md)|Contém a variável subjacente de bloqueio para o objeto atual de SRWLock.|  
  
## Hierarquia de Herança  
 `SRWLock`  
  
## Requisitos  
 **Cabeçalho:** corewrappers.h  
  
 **Namespace:** Microsoft::WRL::Wrappers  
  
## Consulte também  
 [Namespace Microsoft::WRL::Wrappers](../Topic/Microsoft::WRL::Wrappers%20Namespace.md)