---
title: RC2144 de erro do compilador de recurso | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- RC2144
dev_langs:
- C++
helpviewer_keywords:
- RC2144
ms.assetid: 1b3ff39a-92cd-4a04-b1a3-b1fa6a805813
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 62f9eb2b25919a2336c36a459ef41eece447a490
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46080487"
---
# <a name="resource-compiler-error-rc2144"></a>Erro RC2144 (compilador de recurso)

ID DE IDIOMA PRIMÁRIO não é um número

A ID DE IDIOMA PRIMÁRIO deve ser uma ID de idioma hexadecimal. Ver [cadeias de caracteres de país/região e idioma](../../c-runtime-library/locale-names-languages-and-country-region-strings.md) na *referência de biblioteca de tempo de execução* para obter uma lista de IDs de idioma válido.

Esse erro também pode ocorrer se os recursos forem adicionados e excluídos do arquivo .RC usando uma ferramenta. Para corrigir esse problema, abra o arquivo .RC em um editor de texto e limpe quaisquer recursos não usados manualmente.