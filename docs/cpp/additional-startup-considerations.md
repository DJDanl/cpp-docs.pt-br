---
title: "Considera&#231;&#245;es de inicializa&#231;&#227;o adicionais | Microsoft Docs"
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
  - "inicializando antes de principal"
  - "inicialização de programa [C++]"
  - "código de inicialização"
ms.assetid: 0e942aa6-8342-447c-b068-8980ed7622bd
caps.latest.revision: 6
caps.handback.revision: 6
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Considera&#231;&#245;es de inicializa&#231;&#227;o adicionais
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Em C\+\+, a construção e destruição do objeto podem envolver a execução do código do usuário.  Portanto, é importante entender que inicializações acontecem antes da entrada em **main** e que destruidores são invocados depois da saída de **main**. \(Para obter informações detalhadas sobre a construção e destruição de objetos, consulte [Construtores](../cpp/constructors-cpp.md) e [Destruidores](../cpp/destructors-cpp.md).\)  
  
 As seguintes inicializações ocorrem antes da entrada em **main**:  
  
-   Inicialização padrão de dados estáticos em zero.  Todos os dados estáticos sem inicializadores explícitos são definidos como zero antes de executar qualquer outro código, inclusive a inicialização no tempo de execução.  Os membros de dados static ainda devem ser explicitamente definidos.  
  
-   Inicialização de objetos globais estáticos em uma unidade de conversão.  Isso pode ocorrer antes da entrada em **main** ou antes do primeiro uso de qualquer função ou objeto na unidade de conversão do objeto.  
  
 **Específico da Microsoft**  
  
 No Microsoft C\+\+, os objetos globais estáticos são inicializados antes da entrada em **main**.  
  
 **FIM de Específico da Microsoft**  
  
 Os objetos globais estáticos que são mutuamente interdependentes, mas em diferentes unidades de conversão, podem provocar comportamento incorreto.  
  
## Consulte também  
 [Início e término](../cpp/startup-and-termination-cpp.md)