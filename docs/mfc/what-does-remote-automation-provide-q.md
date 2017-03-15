---
title: "O que a automa&#231;&#227;o remota fornece? | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Automação remota, DCOM"
ms.assetid: 269ad218-e164-40ef-9b87-25fcc8ba21de
caps.latest.revision: 10
caps.handback.revision: 6
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# O que a automa&#231;&#227;o remota fornece?
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

A automação remoto permite que os programas têm permissão para invocar implementações de `IDispatch` em um computador de outro.  O também oferece suporte a outras interfaces necessárias à automação, especificamente **IEnumVARIANT** para suporte da coleção.  O não fornece a capacidade de distribuir nenhuma outra interface COM \(exceto **IUnknown**, naturalmente\) e, como a automação normal, contém o marshaling suporte apenas para os tipos de dados suportados pela automação.  
  
 Esse conjunto de recursos permite que um programa acesse os métodos e as propriedades, inclusive aquelas que as coleções de retorno ou para promover objetos de automação, um objeto que é executado em um nó de rede acessível.  Se a máquina cliente também está executando o software apropriado, é possível que o servidor chamar a volta ao cliente, novamente usando recursos de automação \(isso funciona para clientes de 32 bits e de 64 bits, e é conceitualmente semelhante a eventos, embora não usa o mesmo mecanismo\).  
  
 Para que um aplicativo é operável como um servidor remoto de automação, deve ser implementado como um executável \(isto é, como “um servidor local” em vez de como “um servidor inproc”\).  
  
## Consulte também  
 [Onde entra a automação remota?](../mfc/where-does-remote-automation-fit-in-q.md)   
 [Histórico de DCOM](../mfc/history-of-dcom.md)