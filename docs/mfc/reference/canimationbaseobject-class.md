---
title: "Classe de CAnimationBaseObject | Microsoft Docs"
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
  - "afxanimationcontroller/CAnimationBaseObject"
  - "CAnimationBaseObject"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe de CAnimationBaseObject"
ms.assetid: 76b25917-940e-4eba-940f-31d270702603
caps.latest.revision: 17
caps.handback.revision: 6
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe de CAnimationBaseObject
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

A classe base para todos os objetos de animação.  
  
## Sintaxe  
  
```  
class CAnimationBaseObject : public CObject;  
```  
  
## Membros  
  
### Construtores public  
  
|Nome|Descrição|  
|----------|---------------|  
|[CAnimationBaseObject::CAnimationBaseObject](../Topic/CAnimationBaseObject::CAnimationBaseObject.md)|Sobrecarregado.  Constrói um objeto de animação.|  
|[CAnimationBaseObject::~CAnimationBaseObject](../Topic/CAnimationBaseObject::~CAnimationBaseObject.md)|O destrutor.  Chamado quando um objeto de animação é destruído.|  
  
### Métodos públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[CAnimationBaseObject::ApplyTransitions](../Topic/CAnimationBaseObject::ApplyTransitions.md)|Adiciona transições para o storyboard a variável encapsulado de animação.|  
|[CAnimationBaseObject::ClearTransitions](../Topic/CAnimationBaseObject::ClearTransitions.md)|Remove todas as transições relacionadas.|  
|[CAnimationBaseObject::ContainsVariable](../Topic/CAnimationBaseObject::ContainsVariable.md)|Determina se um objeto de animação contém uma variável específico de animação.|  
|[CAnimationBaseObject::CreateTransitions](../Topic/CAnimationBaseObject::CreateTransitions.md)|Criar transições associadas com um objeto de animação.|  
|[CAnimationBaseObject::DetachFromController](../Topic/CAnimationBaseObject::DetachFromController.md)|Dispara um objeto de animação do controlador pai da animação.|  
|[CAnimationBaseObject::EnableIntegerValueChangedEvent](../Topic/CAnimationBaseObject::EnableIntegerValueChangedEvent.md)|Configura o manipulador de eventos modificado de valor inteiro.|  
|[CAnimationBaseObject::EnableValueChangedEvent](../Topic/CAnimationBaseObject::EnableValueChangedEvent.md)|Configura o manipulador de eventos valor modificado.|  
|[CAnimationBaseObject::GetAutodestroyTransitions](../Topic/CAnimationBaseObject::GetAutodestroyTransitions.md)|Informa se a transição está relacionada destruída automaticamente.|  
|[CAnimationBaseObject::GetGroupID](../Topic/CAnimationBaseObject::GetGroupID.md)|Retorna a identificação do grupo atual|  
|[CAnimationBaseObject::GetObjectID](../Topic/CAnimationBaseObject::GetObjectID.md)|Retorna a identificação de objeto atual|  
|[CAnimationBaseObject::GetUserData](../Topic/CAnimationBaseObject::GetUserData.md)|Retorna dados definidos pelo usuário.|  
|[CAnimationBaseObject::SetAutodestroyTransitions](../Topic/CAnimationBaseObject::SetAutodestroyTransitions.md)|Define um sinalizador que também pedidos ocorrem automaticamente.|  
|[CAnimationBaseObject::SetID](../Topic/CAnimationBaseObject::SetID.md)|Define novos identificações.|  
|[CAnimationBaseObject::SetUserData](../Topic/CAnimationBaseObject::SetUserData.md)|Define dados definidos pelo usuário.|  
  
### Métodos protegidos  
  
|Nome|Descrição|  
|----------|---------------|  
|[CAnimationBaseObject::GetAnimationVariableList](../Topic/CAnimationBaseObject::GetAnimationVariableList.md)|Coleta ponteiros para variáveis contidos de animação.|  
|[CAnimationBaseObject::SetParentAnimationObjects](../Topic/CAnimationBaseObject::SetParentAnimationObjects.md)|Estabelece a relação entre as variáveis de animação, contidos em um objeto de animação, e o seu recipiente.|  
  
### Membros de dados protegidos  
  
|Nome|Descrição|  
|----------|---------------|  
|[CAnimationBaseObject::m\_bAutodestroyTransitions](../Topic/CAnimationBaseObject::m_bAutodestroyTransitions.md)|Especifica se as transições relacionados devem ser automaticamente destruídas.|  
|[CAnimationBaseObject::m\_dwUserData](../Topic/CAnimationBaseObject::m_dwUserData.md)|Armazena dados definidos pelo usuário.|  
|[CAnimationBaseObject::m\_nGroupID](../Topic/CAnimationBaseObject::m_nGroupID.md)|Especifica a identificação do grupo de objeto de animação.|  
|[CAnimationBaseObject::m\_nObjectID](../Topic/CAnimationBaseObject::m_nObjectID.md)|Specifes a identificação de objeto do objeto de animação.|  
|[CAnimationBaseObject::m\_pParentController](../Topic/CAnimationBaseObject::m_pParentController.md)|Um ponteiro para o controlador pai da animação.|  
  
## Comentários  
 Essa classe implementa métodos básicos para todos os objetos de animação.  Um objeto de animação pode representar um valor, aponte, tamanho dos controles, ou retângulo cor em um aplicativo, bem como qualquer entidade personalizado.  Os objetos de animação são armazenados em grupos de animação CAnimationGroup \(consulte\).  Cada grupo pode ser animado separada e pode ser tratado como um analogue do storyboard.  Um objeto de animação encapsula um ou mais variáveis de animação \(consulte\) CAnimationVariable, dependendo de sua representação lógica.  Por exemplo, CAnimationRect contém quatro variáveis de animação \- uma variável para cada lado do retângulo.  Cada classe de objeto de animação expõe o método sobrecarregado de AddTransition, que deve ser usado para aplicar as transições a variáveis encapsulados de animação.  Um objeto de animação pode ser identificado por ID de objeto \(opcionalmente\) e pela identificação do grupo  Uma identificação de grupo é necessário para colocar um objeto de animação para o grupo correto, mas se uma identificação de grupo não é especificado, um objeto é colocado no grupo padrão com ID 0.  Se você chamar SetID com GroupID diferente, um objeto de animação será movida para outro grupo \(um novo grupo é criado se necessário\).  
  
## Hierarquia de herança  
 [CObject](../Topic/CObject%20Class.md)  
  
 [CAnimationBaseObject](../../mfc/reference/canimationbaseobject-class.md)  
  
## Requisitos  
 **Cabeçalho:** afxanimationcontroller.h  
  
## Consulte também  
 [Classes](../Topic/MFC%20Classes.md)