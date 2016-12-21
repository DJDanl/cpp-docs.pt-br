---
title: "Classe de CComVariant | Microsoft Docs"
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
  - "ATL.CComVariant"
  - "ATL::CComVariant"
  - "CComVariant"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe de CComVariant"
  - "Macro VARIANTE"
  - "Macro VARIANTE, ATL"
ms.assetid: 4d31149c-d005-44b5-a509-10f84afa2b61
caps.latest.revision: 26
caps.handback.revision: 10
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe de CComVariant
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Essa classe envolve o tipo de `VARIANT` , fornecendo um membro que indica o tipo de dados armazenados.  
  
## Sintaxe  
  
```  
  
class CComVariant : public tagVARIANT  
  
```  
  
## Membros  
  
### Construtores public  
  
|Nome|Descrição|  
|----------|---------------|  
|[CComVariant::CComVariant](../Topic/CComVariant::CComVariant.md)|o construtor.|  
|[CComVariant::~CComVariant](../Topic/CComVariant::~CComVariant.md)|O destrutor.|  
  
### Métodos públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[CComVariant::Attach](../Topic/CComVariant::Attach.md)|Anexa **VARIANT** ao objeto de `CComVariant` .|  
|[CComVariant::ChangeType](../Topic/CComVariant::ChangeType.md)|Converte o objeto de `CComVariant` em um novo tipo.|  
|[CComVariant::Clear](../Topic/CComVariant::Clear.md)|Limpa o objeto de `CComVariant` .|  
|[CComVariant::Copy](../Topic/CComVariant::Copy.md)|Copia **VARIANT** ao objeto de `CComVariant` .|  
|[CComVariant::CopyTo](../Topic/CComVariant::CopyTo.md)|Copia o conteúdo do objeto de `CComVariant` .|  
|[CComVariant::Detach](../Topic/CComVariant::Detach.md)|Dispara **VARIANT** do objeto subjacente de `CComVariant` .|  
|[CComVariant::GetSize](../Topic/CComVariant::GetSize.md)|Retorna o número de tamanho em bytes do conteúdo do objeto de `CComVariant` .|  
|[CComVariant::ReadFromStream](../Topic/CComVariant::ReadFromStream.md)|Carrega **VARIANT** de um fluxo.|  
|[CComVariant::SetByRef](../Topic/CComVariant::SetByRef.md)|Inicializa o objeto de `CComVariant` e define o membro de **vt** a **VT\_BYREF**.|  
|[CComVariant::WriteToStream](../Topic/CComVariant::WriteToStream.md)|Salva **VARIANT** subjacente em um fluxo.|  
  
### Operadores públicos  
  
|||  
|-|-|  
|[CComVariant::operator \<](../Topic/CComVariant::operator%20%3C.md)|Indica se o objeto de `CComVariant` é menor que **VARIANT**especificado.|  
|[CComVariant::operator \>](../Topic/CComVariant::operator%20%3E.md)|Indica se o objeto de `CComVariant` é maior do que **VARIANT**especificado.|  
|[operador\! \=](../Topic/CComVariant::operator%20!=.md)|Indica se o objeto de `CComVariant` não é igual **VARIANT**especificado.|  
|[operador \=](../Topic/CComVariant::operator%20=.md)|Atribui um valor ao objeto de `CComVariant` .|  
|[\=\= de operador](../Topic/CComVariant::operator%20==.md)|Indica se o objeto de `CComVariant` é igual **VARIANT**especificado.|  
  
## Comentários  
 `CComVariant` envolve o tipo de `VARIANT and VARIANTARG` , que consiste em uma união e um membro que indicam o tipo dos dados armazenados na união.  **VARIANT**o é normalmente usado na automação.  
  
 `CComVariant` deriva do tipo de **VARIANT** o que pode ser usado onde quer que **VARIANT** pode ser usado.  Você pode, por exemplo, usar a macro de **V\_VT** para extrair o tipo de `CComVariant` ou você pode acessar o membro de **vt** diretamente assim como faria com **VARIANT**.  
  
## Hierarquia de herança  
 `tagVARIANT`  
  
 `CComVariant`  
  
## Requisitos  
 **Cabeçalho:** atlcomcli.h  
  
## Consulte também  
 [Visão geral de classe](../../atl/atl-class-overview.md)