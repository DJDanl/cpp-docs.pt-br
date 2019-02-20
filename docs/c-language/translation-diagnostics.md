---
title: 'Translação: diagnóstico'
ms.date: 11/04/2016
ms.assetid: 3730ca7c-0147-452d-bd4a-6a1e97e9793e
ms.openlocfilehash: a274b7c5f29b091b2bf29922abfa4d66d3447b47
ms.sourcegitcommit: f4be868c0d1d78e550fba105d4d3c993743a1f4b
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/12/2019
ms.locfileid: "56152593"
---
# <a name="translation-diagnostics"></a>Translação: diagnóstico

**ANSI 2.1.1.3** Como um diagnóstico é identificado

O Microsoft C gera mensagens de erro no formato:

> *filename* **(** *line-number* **) :** *diagnostic* **C**<em>number</em> *message*

em que *filename* é o nome do arquivo de origem no qual o erro foi encontrado; *line-number* é o número da linha na qual o compilador detectou o erro; *diagnostic* é "erro" ou "aviso"; *number* é um número único de quatro dígitos (precedido por um **C**, conforme observado na sintaxe) que identifica o erro ou o aviso; *message* é uma mensagem explicativa.

## <a name="see-also"></a>Consulte também

[Comportamento definido pela implementação](../c-language/implementation-defined-behavior.md)
