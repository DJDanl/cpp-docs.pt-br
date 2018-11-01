---
title: Propriedade de modificador de acelerador (C++)
ms.date: 11/04/2016
helpviewer_keywords:
- Modifier property
ms.assetid: f05a9379-e037-4cfb-b6ef-d2c655bcfa7f
ms.openlocfilehash: f9dfcbde68d2b3d1ebdd1b94aa40339bbc0ff4e1
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50650653"
---
# <a name="accelerator-modifier-property-c"></a>Propriedade de modificador de acelerador (C++)

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

[Configurando propriedades do acelerador](../windows/setting-accelerator-properties.md)<br/>
[Editor de aceleradores](../windows/accelerator-editor.md)