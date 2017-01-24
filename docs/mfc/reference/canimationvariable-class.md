---
title: "Classe de CAnimationVariable | Microsoft Docs"
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
  - "CAnimationVariable"
  - "afxanimationcontroller/CAnimationVariable"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe de CAnimationVariable"
ms.assetid: 506e697e-31a8-4033-a27e-292f4d7b42d9
caps.latest.revision: 17
caps.handback.revision: 6
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe de CAnimationVariable
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Representa uma variável de animação.  
  
## Sintaxe  
  
```  
class CAnimationVariable;  
```  
  
## Membros  
  
### Construtores public  
  
|Nome|Descrição|  
|----------|---------------|  
|[CAnimationVariable::CAnimationVariable](../Topic/CAnimationVariable::CAnimationVariable.md)|Constrói uma variável objeto de animação.|  
|[CAnimationVariable::~CAnimationVariable](../Topic/CAnimationVariable::~CAnimationVariable.md)|O destrutor.  Chamado quando um objeto de CAnimationVariable é destruído.|  
  
### Métodos públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[CAnimationVariable::AddTransition](../Topic/CAnimationVariable::AddTransition.md)|Adiciona uma transição.|  
|[CAnimationVariable::ApplyTransitions](../Topic/CAnimationVariable::ApplyTransitions.md)|Adiciona as transições de lista interna para o storyboard.|  
|[CAnimationVariable::ClearTransitions](../Topic/CAnimationVariable::ClearTransitions.md)|As transições de limpa.|  
|[CAnimationVariable::Create](../Topic/CAnimationVariable::Create.md)|Cria o objeto COM base da variável de animação.|  
|[CAnimationVariable::CreateTransitions](../Topic/CAnimationVariable::CreateTransitions.md)|Cria todas as transições a ser aplicadas a essa variável de animação.|  
|[CAnimationVariable::EnableIntegerValueChangedEvent](../Topic/CAnimationVariable::EnableIntegerValueChangedEvent.md)|Habilita ou desabilita o evento de IntegerValueChanged.|  
|[CAnimationVariable::EnableValueChangedEvent](../Topic/CAnimationVariable::EnableValueChangedEvent.md)|Habilita ou desabilita o evento de ValueChanged.|  
|[CAnimationVariable::GetDefaultValue](../Topic/CAnimationVariable::GetDefaultValue.md)|Retorna o valor padrão.|  
|[CAnimationVariable::GetParentAnimationObject](../Topic/CAnimationVariable::GetParentAnimationObject.md)|Retorna o objeto pai da animação.|  
|[CAnimationVariable::GetValue](../Topic/CAnimationVariable::GetValue.md)|Sobrecarregado.  Retorna o valor atual da variável de animação.|  
|[CAnimationVariable::GetVariable](../Topic/CAnimationVariable::GetVariable.md)|Retorna um ponteiro para o objeto COM de IUIAnimationVariable.|  
|[CAnimationVariable::SetDefaultValue](../Topic/CAnimationVariable::SetDefaultValue.md)|Defina o valor padrão e libera o objeto COM de IUIAnimationVariable.|  
  
### Métodos protegidos  
  
|Nome|Descrição|  
|----------|---------------|  
|[CAnimationVariable::SetParentAnimationObject](../Topic/CAnimationVariable::SetParentAnimationObject.md)|Define a relação entre uma variável de animação e um objeto de animação.|  
  
### Membros públicos de dados  
  
|Nome|Descrição|  
|----------|---------------|  
|[CAnimationVariable::m\_bAutodestroyTransitions](../Topic/CAnimationVariable::m_bAutodestroyTransitions.md)|Especifica se os objetos relacionados a transição devem ser excluídos.|  
  
### Membros de dados protegidos  
  
|Nome|Descrição|  
|----------|---------------|  
|[CAnimationVariable::m\_dblDefaultValue](../Topic/CAnimationVariable::m_dblDefaultValue.md)|Especifica o valor padrão, que é propagado para IUIAnimationVariable.|  
|[CAnimationVariable::m\_lstTransitions](../Topic/CAnimationVariable::m_lstTransitions.md)|Contém uma lista das transições que elas animam essa variável de animação.|  
|[CAnimationVariable::m\_pParentObject](../Topic/CAnimationVariable::m_pParentObject.md)|Um ponteiro para um objeto de animação que encapsula essa variável de animação.|  
|[CAnimationVariable::m\_variable](../Topic/CAnimationVariable::m_variable.md)|Armazena um ponteiro para o objeto COM de IUIAnimationVariable.  ANULE se o objeto COM ainda não foi criado, ou se a criação falhou.|  
  
## Comentários  
 a classe de CAnimationVariable encapsula o objeto COM de IUIAnimationVariable.  Também contém uma lista das transições a ser aplicadas à variável de animação em um storyboard.  Os objetos de CAnimationVariable são inseridos em objetos de animação, que podem representar em um aplicativo um valor animado, aponte\-o, tamanho, cor e retângulo.  
  
## Hierarquia de herança  
 [CAnimationVariable](../../mfc/reference/canimationvariable-class.md)  
  
## Requisitos  
 **Cabeçalho:** afxanimationcontroller.h  
  
## Consulte também  
 [Classes](../Topic/MFC%20Classes.md)