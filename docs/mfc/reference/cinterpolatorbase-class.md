---
title: "Classe de CInterpolatorBase | Microsoft Docs"
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
  - "afxanimationcontroller/CInterpolatorBase"
  - "CInterpolatorBase"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe de CInterpolatorBase"
ms.assetid: bbc3dce7-8398-47f9-b97e-e4fd2d737232
caps.latest.revision: 19
caps.handback.revision: 7
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe de CInterpolatorBase
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Implementa um retorno de chamada, que é chamado pela animação API quando tem que calcula um novo valor de uma variável de animação.  
  
## Sintaxe  
  
```  
class CInterpolatorBase : public CUIAnimationInterpolatorBase<CInterpolatorBase>;  
```  
  
## Membros  
  
### Construtores public  
  
|Nome|Descrição|  
|----------|---------------|  
|[CInterpolatorBase::CInterpolatorBase](../Topic/CInterpolatorBase::CInterpolatorBase.md)|Constrói o objeto de `CInterpolatorBase` .|  
  
### Métodos públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[CInterpolatorBase::CreateInstance](../Topic/CInterpolatorBase::CreateInstance.md)|Cria uma instância de `CInterpolatorBase` e armazena um ponteiro para o interpolador personalizado, que irá manipular eventos.|  
|[CInterpolatorBase::GetDependencies](../Topic/CInterpolatorBase::GetDependencies.md)|Obtém as dependências de interpolador.  Overrides \( `CUIAnimationInterpolatorBase::GetDependencies`.\)|  
|[CInterpolatorBase::GetDuration](../Topic/CInterpolatorBase::GetDuration.md)|Obtém a duração de interpolador.  Overrides \( `CUIAnimationInterpolatorBase::GetDuration`.\)|  
|[CInterpolatorBase::GetFinalValue](../Topic/CInterpolatorBase::GetFinalValue.md)|Obtém o valor final para que o interpolador resulta.  Overrides \( `CUIAnimationInterpolatorBase::GetFinalValue`.\)|  
|[CInterpolatorBase::InterpolateValue](../Topic/CInterpolatorBase::InterpolateValue.md)|Interpola o valor em um deslocamento determinado \(Substitui `CUIAnimationInterpolatorBase::InterpolateValue`\).|  
|[CInterpolatorBase::InterpolateVelocity](../Topic/CInterpolatorBase::InterpolateVelocity.md)|Interpola a velocidade em um deslocamento determinado \(Substitui `CUIAnimationInterpolatorBase::InterpolateVelocity`\).|  
|[CInterpolatorBase::SetCustomInterpolator](../Topic/CInterpolatorBase::SetCustomInterpolator.md)|Armazena um ponteiro para o interpolador personalizado, que irá manipular eventos.|  
|[CInterpolatorBase::SetDuration](../Topic/CInterpolatorBase::SetDuration.md)|Define a duração de interpolador \(substituições `CUIAnimationInterpolatorBase::SetDuration`.\)|  
|[CInterpolatorBase::SetInitialValueAndVelocity](../Topic/CInterpolatorBase::SetInitialValueAndVelocity.md)|Defina o valor inicial e a velocidade de interpolador.  Overrides \( `CUIAnimationInterpolatorBase::SetInitialValueAndVelocity`.\)|  
  
## Comentários  
 Esse manipulador é criado e passado para `IUIAnimationTransitionFactory::CreateTransition` quando um objeto de `CCustomTransition` está sendo criado como parte do processo de inicialização de animação \(iniciado por `CAnimationController::AnimateGroup`\).  Geralmente você não precisa usar diretamente de essa classe, ele distribui apenas todos os eventos a `CCustomInterpolator`\- a classe derivada, cujo ponteiro é passado para o construtor de `CCustomTransition`.  
  
## Hierarquia de herança  
 `CUIAnimationCallbackBase`  
  
 `CUIAnimationInterpolatorBase`  
  
 `CInterpolatorBase`  
  
## Requisitos  
 **Cabeçalho:** afxanimationcontroller.h  
  
## Consulte também  
 [Classes](../Topic/MFC%20Classes.md)