---
title: "Classe de CSimpleStringT | Microsoft Docs"
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
  - "ATL.CSimpleStringT"
  - "ATL::CSimpleStringT"
  - "ATL::CSimpleStringT<BaseType>"
  - "ATL.CSimpleStringT<BaseType>"
  - "CSimpleStringT"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe de CSimpleStringT"
  - "classes compartilhadas, CSimpleStringT"
  - "cadeias de caracteres [C++], Classe de ATL"
ms.assetid: 15814fcb-5b8f-4425-a97e-3b61fc9b48d8
caps.latest.revision: 19
caps.handback.revision: 8
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe de CSimpleStringT
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Esta classe representa um objeto de `CSimpleStringT` .  
  
## Sintaxe  
  
```  
  
      template <typename   
      BaseType  
      >  
class CSimpleStringT  
```  
  
#### Parâmetros  
 `BaseType`  
 O tipo da classe de caractere de cadeia de caracteres.  Pode ser um dos seguintes:  
  
-   `char` \(para cadeias de caracteres ANSI\).  
  
-   `wchar_t` \(para cadeias de caracteres Unicode\).  
  
-   Para**TCHAR** \(ANSI e cadeias de caracteres Unicode\).  
  
## Membros  
  
### Typedefs público  
  
|Nome|Descrição|  
|----------|---------------|  
|[CSimpleStringT::PCXSTR](../Topic/CSimpleStringT::PCXSTR.md)|Um ponteiro para uma cadeia de caracteres constante.|  
|[CSimpleStringT::PXSTR](../Topic/CSimpleStringT::PXSTR.md)|Um ponteiro para uma cadeia de caracteres.|  
  
### Construtores public  
  
|Nome|Descrição|  
|----------|---------------|  
|[CSimpleStringT::CSimpleStringT](../Topic/CSimpleStringT::CSimpleStringT.md)|Constrói objetos de `CSimpleStringT` de várias maneiras.|  
|[CSimpleStringT::~CSimpleStringT](../Topic/CSimpleStringT::~CSimpleStringT.md)|Destruidor.|  
  
### Métodos públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[CSimpleStringT::Append](../Topic/CSimpleStringT::Append.md)|Acrescenta um objeto de `CSimpleStringT` a um objeto existente de `CSimpleStringT` .|  
|[CSimpleStringT::AppendChar](../Topic/CSimpleStringT::AppendChar.md)|Acrescenta um caractere a um objeto existente de `CSimpleStringT` .|  
|[CSimpleStringT::CopyChars](../Topic/CSimpleStringT::CopyChars.md)|Copia um caractere ou mais caracteres em outros cadeia de caracteres.|  
|[CSimpleStringT::CopyCharsOverlapped](../Topic/CSimpleStringT::CopyCharsOverlapped.md)|Copia um caractere ou mais caracteres para outra cadeia de caracteres em que os buffers sobrepostos.|  
|[CSimpleStringT::Empty](../Topic/CSimpleStringT::Empty.md)|Força uma cadeia de caracteres para ter um de comprimento zero.|  
|[CSimpleStringT::FreeExtra](../Topic/CSimpleStringT::FreeExtra.md)|Qualquer libera a memória adicional atribuída anteriormente pelo objeto de cadeia de caracteres.|  
|[CSimpleStringT::GetAllocLength](../Topic/CSimpleStringT::GetAllocLength.md)|Recupera atribuído o comprimento de um objeto de `CSimpleStringT` .|  
|[CSimpleStringT::GetAt](../Topic/CSimpleStringT::GetAt.md)|Retorna o caractere em uma posição determinada.|  
|[CSimpleStringT::GetBuffer](../Topic/CSimpleStringT::GetBuffer.md)|Retorna um ponteiro para caracteres em `CSimpleStringT`.|  
|[CSimpleStringT::GetBufferSetLength](../Topic/CSimpleStringT::GetBufferSetLength.md)|Retorna um ponteiro para caracteres em `CSimpleStringT`, truncando para o comprimento especificado.|  
|[CSimpleStringT::GetLength](../Topic/CSimpleStringT::GetLength.md)|Retorna o número de caracteres em um objeto de `CSimpleStringT` .|  
|[CSimpleStringT::GetManager](../Topic/CSimpleStringT::GetManager.md)|Recupera o gerenciador de memória do objeto de `CSimpleStringT` .|  
|[CSimpleStringT::GetString](../Topic/CSimpleStringT::GetString.md)|Retorna a cadeia de caracteres|  
|[CSimpleStringT::IsEmpty](../Topic/CSimpleStringT::IsEmpty.md)|Testa se um objeto de `CSimpleStringT` não contém nenhum caractere.|  
|[CSimpleStringT::LockBuffer](../Topic/CSimpleStringT::LockBuffer.md)|Contagem de referência desativa e protege a cadeia de caracteres em buffer.|  
|[CSimpleStringT::Preallocate](../Topic/CSimpleStringT::Preallocate.md)|Atribui uma quantidade de memória específica para o buffer de caracteres.|  
|[CSimpleStringT::ReleaseBuffer](../Topic/CSimpleStringT::ReleaseBuffer.md)|O controle de versões do buffer retornado por `GetBuffer`.|  
|[CSimpleStringT::ReleaseBufferSetLength](../Topic/CSimpleStringT::ReleaseBufferSetLength.md)|O controle de versões do buffer retornado por `GetBuffer`.|  
|[CSimpleStringT::SetAt](../Topic/CSimpleStringT::SetAt.md)|Define um caractere em uma posição determinada.|  
|[CSimpleStringT::SetManager](../Topic/CSimpleStringT::SetManager.md)|Define o gerenciador de memória de um objeto de `CSimpleStringT` .|  
|[CSimpleStringT::SetString](../Topic/CSimpleStringT::SetString.md)|Defina a cadeia de caracteres de um objeto de `CSimpleStringT` .|  
|[CSimpleStringT::StringLength](../Topic/CSimpleStringT::StringLength.md)|Retorna o número de caracteres na cadeia de caracteres especificada.|  
|[CSimpleStringT::Truncate](../Topic/CSimpleStringT::Truncate.md)|Trunca a cadeia de caracteres em um comprimento especificado.|  
|[CSimpleStringT::UnlockBuffer](../Topic/CSimpleStringT::UnlockBuffer.md)|Permite que a contagem de referência e libera a cadeia de caracteres em buffer.|  
  
### Operadores públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[CSimpleStringT::operator PCXSTR](../Topic/CSimpleStringT::operator%20PCXSTR.md)|Acessa diretamente os caracteres armazenados em um objeto de `CSimpleStringT` como se AC \- estilize a cadeia de caracteres.|  
|[CSimpleStringT::operator](../Topic/CSimpleStringT::operator.md)|Retorna o caractere em uma posição determinada — substituição do operador para `GetAt`.|  
|[CSimpleStringT::operator \+\=](../Topic/CSimpleStringT::operator%20+=.md)|Concatena uma nova cadeia de caracteres ao final de uma cadeia de caracteres existente.|  
|[CSimpleStringT::operator \=](../Topic/CSimpleStringT::operator%20=.md)|Atribuir um novo valor a um objeto de `CSimpleStringT` .|  
  
## Comentários  
 `CSimpleStringT` é a classe base para as várias classes de cadeia de caracteres suportadas pelo Visual C\+\+.  Fornece suporte mínimo para o gerenciamento de memória do objeto de cadeia de caracteres e de tratamento básico de buffer.  Para os objetos mais avançados de cadeia de caracteres, consulte [classe de CStringT](../../atl-mfc-shared/reference/cstringt-class.md).  
  
## Requisitos  
 **Cabeçalho:** atlsimpstr.h  
  
## Consulte também  
 [Gráfico da hierarquia](../../mfc/hierarchy-chart.md)   
 [ATL\/MFC compartilhasse classes](../../atl-mfc-shared/atl-mfc-shared-classes.md)