---
title: Propriedade de modificador de acelerador | Microsoft Docs
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
ms.openlocfilehash: 0788536e776661b9a84a6cccc648a7db68389ae5
ms.sourcegitcommit: 37a10996022d738135999cbe71858379386bab3d
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/08/2018
ms.locfileid: "39644249"
---
# <a name="accelerator-modifier-property"></a>Propriedade do modificador de acelerador
A seguir estão as entradas legais para a propriedade de modificador na tabela de aceleradores.  
  
|Valor|Descrição|  
|-----------|-----------------|  
|**Nenhum**|Usuário pressiona apenas o **chave** valor. Isso é mais efetivamente usado com os valores de ASCII/ANSI 001 a 026, que é interpretado como ^ A-^ Z (CTRL-A por meio de CTRL-Z).|  
|**Alt**|O usuário deve pressionar o **Alt** chave antes do **chave** valor.|  
|**Ctrl**|O usuário deve pressionar o **Ctrl** chave antes do **chave** valor. Não é válido com o tipo de ASCII.|  
|**Shift**|O usuário deve pressionar o **Shift** chave antes do **chave** valor.|  
|**Ctrl + Alt**|O usuário deve pressionar o **Ctrl** chave e o **Alt** chave antes do **chave** valor. Não é válido com o tipo de ASCII.|  
|**Ctrl + Shift**|O usuário deve pressionar o **Ctrl** chave e o **Shift** chave antes do **chave** valor. Não é válido com o tipo de ASCII.|  
|**Alt + Shift**|O usuário deve pressionar o **Alt** chave e o **Shift** chave antes do **chave** valor. Não é válido com o tipo de ASCII.|  
|**Ctrl + Alt + Shift**|O usuário deve pressionar **Ctrl**, **Alt**, e **Shift** antes do **chave** valor. Não é válido com o tipo de ASCII.|  
  
## <a name="requirements"></a>Requisitos  
 Win32  
  
## <a name="see-also"></a>Consulte também  
 [Configurando propriedades do acelerador](../windows/setting-accelerator-properties.md)   
 [Editor de aceleradores](../windows/accelerator-editor.md)