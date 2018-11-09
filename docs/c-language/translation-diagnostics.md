---
title: 'Translação: diagnóstico'
ms.date: 11/04/2016
ms.assetid: 3730ca7c-0147-452d-bd4a-6a1e97e9793e
ms.openlocfilehash: 4863b97dc1db7ff295b5f786ca97da2551d0fa62
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50664991"
---
# <a name="translation-diagnostics"></a>Translação: diagnóstico

**ANSI 2.1.1.3** Como um diagnóstico é identificado

O Microsoft C gera mensagens de erro no formato:

> *filename* **(** *line-number* **) :** *diagnostic* **C**<em>number</em> *message*

em que *filename* é o nome do arquivo de origem no qual o erro foi encontrado; *line-number* é o número da linha na qual o compilador detectou o erro; *diagnostic* é "erro" ou "aviso"; *number* é um número único de quatro dígitos (precedido por um **C**, conforme observado na sintaxe) que identifica o erro ou o aviso; *message* é uma mensagem explicativa.

## <a name="see-also"></a>Consulte também

[Comportamento definido pela implementação](../c-language/implementation-defined-behavior.md)