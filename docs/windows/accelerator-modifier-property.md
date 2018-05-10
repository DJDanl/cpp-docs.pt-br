---
title: Propriedade do modificador de acelerador | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- Modifier property
ms.assetid: f05a9379-e037-4cfb-b6ef-d2c655bcfa7f
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: d99d4656f2835f9adb60f310e429c4ccb97ac7b6
ms.sourcegitcommit: d55ac596ba8f908f5d91d228dc070dad31cb8360
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/08/2018
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