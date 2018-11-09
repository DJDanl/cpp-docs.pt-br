---
title: Naked (C)
ms.date: 11/04/2016
helpviewer_keywords:
- naked keyword [C], storage-class attribute
- naked keyword [C]
- prolog code
- epilog code
ms.assetid: 23b1209b-93ba-46ad-a60f-2327c1933eaf
ms.openlocfilehash: c79502d1793df2a3340eed26c67cca5d2a8b0d9b
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50537226"
---
# <a name="naked-c"></a>Naked (C)

**Seção específica da Microsoft**

O atributo de classe de armazenamento naked é uma extensão específica da Microsoft na linguagem C. O compilador gera um código sem código de prólogo e de epílogo para funções declaradas com o atributo de classe de armazenamento naked. As funções naked são úteis quando você precisa escrever suas próprias sequências de código de prólogo/epílogo usando o código de assembler embutido. As funções naked são úteis para escrever drivers para dispositivo virtuais.

Para obter informações específicas sobre como usar o atributo naked, consulte [Funções naked](../c-language/naked-functions.md).

**Fim da seção específica da Microsoft**

## <a name="see-also"></a>Consulte também

[Atributos de classe de armazenamento estendido C](../c-language/c-extended-storage-class-attributes.md)