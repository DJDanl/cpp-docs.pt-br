---
title: Constantes de namespace de simultaneidade (AMP) | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.tgt_pltfrm: 
ms.topic: article
ms.assetid: 13a8e8cd-2eec-4e60-a91d-5d271072747b
caps.latest.revision: 9
author: mikeblome
ms.author: mblome
manager: ghogen
translationtype: Machine Translation
ms.sourcegitcommit: 22ba62ab8b3b4f9d14953dbab3edd8228ea85193
ms.openlocfilehash: 852408f309c00aa284ce710a3612d0654ed7b768
ms.lasthandoff: 02/25/2017

---
# <a name="concurrency-namespace-constants-amp"></a>Constantes de namespace de simultaneidade (AMP)
|||  
|-|-|  
|[Constante HLSL_MAX_NUM_BUFFERS](#hlsl_max_num_buffers)|[Constante MODULENAME_MAX_LENGTH](#modulename_max_length)|  
  
##  <a name="a-namehlslmaxnumbuffersa--hlslmaxnumbuffers-constant"></a><a name="hlsl_max_num_buffers"></a>Constante HLSL_MAX_NUM_BUFFERS  
 O número máximo de buffers permitido pelo DirectX.  
  
```  
static const UINT HLSL_MAX_NUM_BUFFERS = 64 + 128;  
```  
  
##  <a name="a-namemodulenamemaxlengtha--modulenamemaxlength-constant"></a><a name="modulename_max_length"></a>Constante MODULENAME_MAX_LENGTH  
 Armazena o comprimento máximo do nome do módulo. Esse valor deve ser o mesmo no compilador e no tempo de execução.  
  
```  
static const UINT MODULENAME_MAX_LENGTH = 1024;  
```  
  
## <a name="see-also"></a>Consulte também  
 [Namespace de simultaneidade (C++ AMP)](concurrency-namespace-cpp-amp.md)

