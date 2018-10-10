---
title: 'Translação: diagnóstico | Microsoft Docs'
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-language
ms.topic: language-reference
dev_langs:
- C++
ms.assetid: 3730ca7c-0147-452d-bd4a-6a1e97e9793e
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: d297cfd4f4dee49d3344ae2f159f85682f05ea2f
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46017580"
---
# <a name="translation-diagnostics"></a>Translação: diagnóstico

**ANSI 2.1.1.3** Como um diagnóstico é identificado

O Microsoft C gera mensagens de erro no formato:

> *filename* **(** *line-number* **) :** *diagnostic* **C**<em>number</em> *message*

em que *filename* é o nome do arquivo de origem no qual o erro foi encontrado; *line-number* é o número da linha na qual o compilador detectou o erro; *diagnostic* é "erro" ou "aviso"; *number* é um número único de quatro dígitos (precedido por um **C**, conforme observado na sintaxe) que identifica o erro ou o aviso; *message* é uma mensagem explicativa.

## <a name="see-also"></a>Consulte também

[Comportamento definido pela implementação](../c-language/implementation-defined-behavior.md)