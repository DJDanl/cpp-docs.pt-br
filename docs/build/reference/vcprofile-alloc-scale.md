---
title: VCPROFILE_ALLOC_SCALE | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-tools
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords: VCPROFILE_ALLOC_SCALE
dev_langs: C++
helpviewer_keywords: VCPROFILE_ALLOC_SCALE environment variable
ms.assetid: 5cb5ce27-f9b8-489b-b46c-d6e9bcab2d34
caps.latest.revision: "4"
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: b7b441f41106544633bd691c409fa04c989146f0
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="vcprofileallocscale"></a>VCPROFILE_ALLOC_SCALE
Modificar a quantidade de memória alocada para armazenar os dados do perfil.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
VCPROFILE_ALLOC_SCALE=scale_value  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `scale_value`  
 O valor de escala para a quantidade de memória que você deseja para a execução de cenários de teste.  O padrão é 1.  
  
## <a name="remarks"></a>Comentários  
 Em casos raros, não haja memória suficiente dar suporte a coleta de dados de perfil durante a execução de cenários de teste.  Nesses casos, você pode aumentar a quantidade de memória com `VCPROFILE_ALLOC_SCALE`.  
  
 Se você receber uma mensagem de erro durante uma execução de teste que indica que você tenha memória suficiente, atribua um valor maior para `VCPROFILE_ALLOC_SCALE`, até que a execução do teste concluída sem erros de falta de memória.  
  
## <a name="example"></a>Exemplo  
  
```  
set VCPROFILE_ALLOC_SCALE=2  
```  
  
## <a name="see-also"></a>Consulte também  
 [Variáveis de ambiente para otimizações guiadas por perfil](../../build/reference/environment-variables-for-profile-guided-optimizations.md)