---
title: "Desenvolvendo a fun&#231;&#227;o auxiliar pr&#243;pria | Microsoft Docs"
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
  - "funções auxiliares"
ms.assetid: a845429d-68b1-4e14-aa88-f3f5343bd490
caps.latest.revision: 7
caps.handback.revision: 7
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Desenvolvendo a fun&#231;&#227;o auxiliar pr&#243;pria
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Você pode desejar fornecer sua própria versão da rotina para fazer o processamento específico com base em nomes de DLL ou importações. Há duas maneiras de fazer isso: codificação de sua preferência, possivelmente com base no código fornecido, ou simplesmente conectar a versão fornecida usando os ganchos de notificação detalhados anteriormente.  
  
 Código de seu próprio  
 Isso é bastante simple, pois basicamente você pode usar o código fornecido como uma diretriz para a nova. Obviamente, devem seguir as convenções de chamada e se ele retorna para os conversões gerados pelo vinculador, ele deve retornar um ponteiro de função apropriada. Uma vez no seu código, você pode fazer quase tudo o que você deseja para atender a chamada ou tirar proveito da chamada.  
  
 Usar o processamento de gancho de notificação de início  
 Provavelmente será mais fácil simplesmente fornecer um ponteiro para uma função de gancho de notificação fornecido pelo usuário que recebe os mesmos valores que o auxiliar padrão em dliStartProcessing a notificação. Nesse ponto, a função de gancho pode essencialmente se tornar a nova função de auxiliar, como um retorno bem\-sucedido para o auxiliar padrão ignorará todos os processamento no auxiliar padrão.  
  
## Consulte também  
 [Suporte de vinculador para DLLs carregadas com atraso](../../build/reference/linker-support-for-delay-loaded-dlls.md)