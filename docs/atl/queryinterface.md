---
title: "QueryInterface | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
f1_keywords: 
  - "QueryInterface"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "interfaces, disponibilidade"
  - "interfaces, ponteiros"
  - "Método de QueryInterface"
ms.assetid: 62fce95e-aafa-4187-b50b-e6611b74c3b3
caps.latest.revision: 10
caps.handback.revision: 5
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# QueryInterface
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Embora haja mecanismos por que um objeto pode expressar a funcionalidade ele fornece estaticamente \(antes que é instanciada\), o mecanismo de COM o fundamento é usar o método de **IUnknown** chamado [QueryInterface](http://msdn.microsoft.com/library/windows/desktop/ms682521).  
  
 Cada interface é derivada de **IUnknown**, para que cada interface tem uma implementação de `QueryInterface`.  Independentemente da implementação, esse método consulta a um objeto usando o IID de interface para que o chamador deseja um ponteiro.  Se o oferece suporte a interface, `QueryInterface` do objeto recupera um ponteiro para a interface, o também chamar `AddRef`.  Caso contrário, retornará o código de erro de **E\_NOINTERFACE** .  
  
 Observe que você deve obedecer regras de [Contagem de referência](../atl/reference-counting.md) em cada vez.  Se você chamar **Versão** em um ponteiro de interface para diminuir a contagem de referência como zero, você não deve usar esse ponteiro novamente.  Ocasionalmente você pode precisar obter uma referência fraca a um objeto \(ou seja, você pode desejar obter um ponteiro para uma de suas interfaces sem incrementar contagem de referência\), mas não é aceitável fazer isso chamando `QueryInterface` seguido por **Versão**.  O ponteiro obtido em tal forma não é válido e não deve ser usado.  Isso torna mais imediatamente aparente quando [\_ATL\_DEBUG\_INTERFACES](../Topic/_ATL_DEBUG_INTERFACES.md) é definido, então defina isso macro é uma maneira útil para localizar erros de contagem de referência.  
  
## Consulte também  
 [Introdução ao COM](../atl/introduction-to-com.md)   
 [QueryInterface: Navigating in an Object](http://msdn.microsoft.com/library/windows/desktop/ms687230)