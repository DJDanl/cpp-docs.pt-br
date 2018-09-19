---
title: Renomeando com um nome que existe | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-language
ms.topic: language-reference
dev_langs:
- C++
ms.assetid: fc2a8f29-f757-4ce0-8d7f-7f8cff7f49ab
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 10b9a9c4e42356a087c8cb6c10a470ba68acd4ba
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46067748"
---
# <a name="renaming-with-a-name-that-exists"></a>Renomear com um nome que existe

**ANSI 4.9.4.2** O efeito se um arquivo com o novo nome existir antes de uma chamada à função de **rename**

Se você tentar renomear um arquivo usando um nome que existe, a função **rename** falhará e retornará um código de erro.

## <a name="see-also"></a>Consulte também

[Funções de biblioteca](../c-language/library-functions.md)