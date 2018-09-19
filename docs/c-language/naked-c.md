---
title: Naked | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-language
ms.topic: language-reference
dev_langs:
- C++
helpviewer_keywords:
- naked keyword [C], storage-class attribute
- naked keyword [C]
- prolog code
- epilog code
ms.assetid: 23b1209b-93ba-46ad-a60f-2327c1933eaf
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: dd6665bafb0041989e99a3a766204555f969d16c
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46062144"
---
# <a name="naked-c"></a>Naked (C)

**Seção específica da Microsoft**

O atributo de classe de armazenamento naked é uma extensão específica da Microsoft na linguagem C. O compilador gera um código sem código de prólogo e de epílogo para funções declaradas com o atributo de classe de armazenamento naked. As funções naked são úteis quando você precisa escrever suas próprias sequências de código de prólogo/epílogo usando o código de assembler embutido. As funções naked são úteis para escrever drivers para dispositivo virtuais.

Para obter informações específicas sobre como usar o atributo naked, consulte [Funções naked](../c-language/naked-functions.md).

**Fim da seção específica da Microsoft**

## <a name="see-also"></a>Consulte também

[Atributos de classe de armazenamento estendido C](../c-language/c-extended-storage-class-attributes.md)