---
title: "Preven&#231;&#227;o de conflito da heap | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "reference"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "conflito da heap"
ms.assetid: 797129d7-5f8c-4b0e-8974-bb93217e9ab5
caps.latest.revision: 12
caps.handback.revision: 8
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Preven&#231;&#227;o de conflito da heap
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Os gerentes padrão de cadeia de caracteres fornecidos pelo MFC e o ATL são invólucros simples em uma pilha global.  Este heap global é totalmente thread\-safe, significando que vários segmentos podem atribuir e liberar memória de ela simultaneamente sem danificar o heap.  Para ajudar a fornecer segurança de segmentos, o heap precisa serializar o acesso a ele.  Geralmente isso é feito com uma seção crítica ou um mecanismo de bloqueio semelhante.  Sempre que dois segmentos tentarem simultaneamente acessar o heap, um segmento está bloqueado até que a solicitação de outro segmento seja concluída.  Para muitos aplicativos, essa situação ocorre e raramente o impacto de desempenho o mecanismo de bloqueio da heap é irrisória.  Em o entanto, para aplicativos que acessam freqüentemente o heap de vários segmento um conflito para o bloqueio de heap pode causar o aplicativo mais lento do que se fosse de segmentação única \(mesmo em vários computadores com cpus\).  
  
 Aplicativos que usam [CStringT](../atl-mfc-shared/reference/cstringt-class.md) são especialmente suscetíveis a conflito da heap como as operações em objetos de `CStringT` freqüentemente exigem a realocação de buffer de cadeia de caracteres.  
  
 Uma maneira de aliviar a heap de conflito entre segmentos é que cada segmento atribuir cadeias de caracteres de um particular, heap do com local.  Como as cadeias de caracteres atribuídas com distribuidor específico de um segmento são usadas somente em aquele segmento, o distribuidor não precisa ser thread\-safe.  
  
## Exemplo  
 O exemplo a seguir ilustra um procedimento de segmento que atribui seu próprio heap não\-thread\- seguro particular para usar para cadeias de caracteres em aquele segmento:  
  
 [!code-cpp[NVC_ATLMFC_Utilities#182](../atl-mfc-shared/codesnippet/CPP/avoidance-of-heap-contention_1.cpp)]  
  
## Comentários  
 Vários segmentos podem executar usando o mesmo procedimento de segmento mas já que cada segmento possui seu próprio heap não houver nenhum conflito entre segmentos.  Além de isso, o fato de que cada heap não é thread\-safe fornece um aumento mensurável no desempenho se apenas uma cópia do segmento está executando.  Este é o resultado da heap que não usa operações com barreira faces para proteger contra o acesso simultânea.  
  
 Para um procedimento mais complicado segmento, pode ser conveniente para armazenar um ponteiro ao gerenciador de cadeia de caracteres de segmento em um slot de \(TLS\) do armazenamento local de segmento.  Isso permite outras funções chamadas de procedimento pelo segmento para acessar o gerenciador de cadeia de caracteres de segmento.  
  
## Consulte também  
 [Gerenciamento de memória com CStringT](../atl-mfc-shared/memory-management-with-cstringt.md)