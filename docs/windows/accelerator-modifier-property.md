---
title: Propriedade do modificador de acelerador | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
dev_langs:
- C++
helpviewer_keywords:
- Modifier property
ms.assetid: f05a9379-e037-4cfb-b6ef-d2c655bcfa7f
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 63d6a4b526fc1f2aeb2a942e682a8c7cc6f9b58c
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="accelerator-modifier-property"></a>Propriedade do modificador de acelerador
As seguintes entradas legais para a propriedade de modificador na tabela de teclas aceleradoras são.  
  
|Valor|Descrição|  
|-----------|-----------------|  
|**Nenhum**|Usuário pressiona apenas o valor de chave. Isso é efetivamente usado com os valores de ASCII/ANSI 001 a 026, que é interpretado como ^ A-^ Z (CTRL-A por meio de CTRL-Z).|  
|**ALT**|Usuário deve pressionar a tecla ALT antes do valor de chave.|  
|**CTRL**|Usuário deve pressionar a tecla CTRL antes do valor de chave. Não é válido com o tipo de ASCII.|  
|**SHIFT**|Usuário deve pressionar a tecla SHIFT antes do valor de chave.|  
|**Ctrl + Alt**|Usuário deve pressionar a tecla CTRL e a tecla ALT antes do valor de chave. Não é válido com o tipo de ASCII.|  
|**Ctrl + Shift**|Usuário deve pressionar a tecla CTRL e SHIFT antes do valor de chave. Não é válido com o tipo de ASCII.|  
|**Alt + Shift**|Usuário deve pressionar a tecla ALT e a tecla SHIFT antes do valor de chave. Não é válido com o tipo de ASCII.|  
|**Ctrl + Alt + Shift**|Usuário deve pressionar SHIFT, ALT e CTRL antes do valor de chave. Não é válido com o tipo de ASCII.|  
  
## <a name="requirements"></a>Requisitos  
 Win32  
  
## <a name="see-also"></a>Consulte também  
 [Definindo propriedades de acelerador](../windows/setting-accelerator-properties.md)   
 [Editor de aceleradores](../windows/accelerator-editor.md)