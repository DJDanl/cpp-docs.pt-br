---
title: "Classe de CCustomTransition | Microsoft Docs"
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
  - "afxanimationcontroller/CCustomTransition"
  - "CCustomTransition"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe de CCustomTransition"
ms.assetid: 5bd3f492-940f-4290-a38b-fa68eb8f8401
caps.latest.revision: 17
caps.handback.revision: 6
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe de CCustomTransition
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Implementa uma transição personalizada.  
  
## Sintaxe  
  
```  
class CCustomTransition : public CBaseTransition;  
```  
  
## Membros  
  
### Construtores public  
  
|Nome|Descrição|  
|----------|---------------|  
|[CCustomTransition::CCustomTransition](../Topic/CCustomTransition::CCustomTransition.md)|Constrói um objeto de transição personalizada.|  
  
### Métodos públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[CCustomTransition::Create](../Topic/CCustomTransition::Create.md)|Chama a biblioteca de transição para criar o objeto COM encapsulado de transição.  Overrides \( [CBaseTransition::Create](../Topic/CBaseTransition::Create.md).\)|  
|[CCustomTransition::SetInitialValue](../Topic/CCustomTransition::SetInitialValue.md)|Define um valor inicial, que é aplicado a uma variável de animação associado com essa transição.|  
|[CCustomTransition::SetInitialVelocity](../Topic/CCustomTransition::SetInitialVelocity.md)|Define uma velocidade inicial, que é aplicada a uma variável de animação associado com essa transição.|  
  
### Membros de dados protegidos  
  
|Nome|Descrição|  
|----------|---------------|  
|[CCustomTransition::m\_bInitialValueSpecified](../Topic/CCustomTransition::m_bInitialValueSpecified.md)|Especifica se o valor inicial foi especificado com SetInitialValue.|  
|[CCustomTransition::m\_bInitialVelocitySpecified](../Topic/CCustomTransition::m_bInitialVelocitySpecified.md)|Especifica se a velocidade inicial foi especificada com SetInitialVelocity.|  
|[CCustomTransition::m\_initialValue](../Topic/CCustomTransition::m_initialValue.md)|Armazena o valor inicial.|  
|[CCustomTransition::m\_initialVelocity](../Topic/CCustomTransition::m_initialVelocity.md)|Armazena a velocidade inicial.|  
|[CCustomTransition::m\_pInterpolator](../Topic/CCustomTransition::m_pInterpolator.md)|Armazena um ponteiro para um interpolador personalizado.|  
  
## Comentários  
 A classe de CCustomTransitions permite que os desenvolvedores secundários implementem transições personalizados.  Criou e usado como uma transição padrão, mas o construtor aceita como o parâmetro um ponteiro para um interpolador personalizado.  Execute as seguintes etapas para usar transições personalizados: 1.  Derive uma classe de CCustomInterpolator e implementar pelo menos o método de InterpolateValue.  2.  Certifique\-se de que o tempo de vida do objeto de interpolador deve ser maior que a duração da animação onde usou.  3.  Criar uma instância de \(usando o operador novo\) um objeto de CCustomTransition e passar um ponteiro para o interpolador personalizado no construtor.  4.  Chame CCustomTransition::SetInitialValue e CCustomTransition::SetInitialVelocity se esses parâmetros são necessários para a interpolação personalizado.  5.  Passar o ponteiro para a transição personalizada para o método de AddTransition do objeto de animação, cujo valor deve ser animado com o algoritmo personalizado.  6.  Quando o valor do objeto de animação deve alterar a animação API do windows chamará InterpolateValue \(e outros métodos relevantes\) em CCustomInterpolator.  
  
## Hierarquia de herança  
 [CObject](../Topic/CObject%20Class.md)  
  
 [CBaseTransition](../../mfc/reference/cbasetransition-class.md)  
  
 [CCustomTransition](../../mfc/reference/ccustomtransition-class.md)  
  
## Requisitos  
 **Cabeçalho:** afxanimationcontroller.h  
  
## Consulte também  
 [Classes](../Topic/MFC%20Classes.md)