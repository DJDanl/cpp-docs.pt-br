---
title: "Fun&#231;&#245;es (SafeInt) | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "language-reference"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Funções , SafeInt"
ms.assetid: fdc208e5-5d8a-41a9-8271-567fd438958d
caps.latest.revision: 13
caps.handback.revision: 13
author: "ghogen"
ms.author: "ghogen"
manager: "ghogen"
---
# Fun&#231;&#245;es (SafeInt)
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

A biblioteca de SafeInt fornece várias funções que você pode usar sem criar uma instância de [Classe SafeInt](../windows/safeint-class.md).  Se você quiser proteger uma única operação matemática de estouro de inteiro, você pode usar essas funções.  Se você quiser proteger várias operações matemáticas, você deve criar objetos de `SafeInt` .  É mais eficiente criar objetos de `SafeInt` do que para usar várias vezes essas funções.  
  
 Essas funções permitem comparar ou executar operações matemáticas em dois tipos diferentes de parâmetros sem ter que o primeiro o mesmo tipo.  
  
 Cada uma dessas funções tem dois tipos de modelo: `T` e `U`.  Cada um deless pode ser um booliano, um caractere, ou um tipo integral.  Os tipos integrais podem ser assinados ou não assinados e qualquer tamanho de 8 bits para 64 bits.  
  
## Nesta seção  
  
|Função|Descrição|  
|------------|---------------|  
|[SafeAdd](../windows/safeadd.md)|Soma dois números e protege\-os no estouro.|  
|[SafeCast](../windows/safecast.md)|Conversões um tipo de parâmetro para outro tipo.|  
|[SafeDivide](../windows/safedivide.md)|Divide dois números e proteger contra dividir por zero.|  
|[SafeEquals](../windows/safeequals.md), [SafeGreaterThan](../windows/safegreaterthan.md), [SafeGreaterThanEquals](../windows/safegreaterthanequals.md), [SafeLessThan](../windows/safelessthan.md), [SafeLessThanEquals](../windows/safelessthanequals.md), [SafeNotEquals](../Topic/SafeNotEquals.md)|Compara dois números.  Essas funções permitem comparar dois tipos diferentes de números sem alterar seus tipos.|  
|[SafeModulus](../windows/safemodulus.md)|Executa a operação do módulo em dois números.|  
|[SafeMultiply](../Topic/SafeMultiply.md)|Multiplica dois números e protege\-os no estouro.|  
|[SafeSubtract](../windows/safesubtract.md)|Subtrai dois números e protege\-os no estouro.|  
  
## Seções relacionadas  
  
|Seção|Descrição|  
|-----------|---------------|  
|[Classe SafeInt](../windows/safeint-class.md)|A classe `SafeInt`.|  
|[Classe SafeIntException](../windows/safeintexception-class.md)|O específico da classe de exceção na biblioteca de SafeInt.|