---
title: NMAKE Erro Fatal U1095 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- U1095
dev_langs:
- C++
helpviewer_keywords:
- U1095
ms.assetid: a392582b-06db-4568-9c13-450293a4fbda
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 964ec1d029e56a5d9d78659ad919c71a4e44506d
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46039875"
---
# <a name="nmake-fatal-error-u1095"></a>Erro fatal U1095 (NMAKE)

linha de comando expandida 'commandline' muito longo

Após a expansão de macro, a linha de comando fornecida excedeu o limite no tamanho das linhas de comando para o sistema operacional.

MS-DOS permite até 128 caracteres em uma linha de comando.

Se o comando é um programa que pode aceitar a entrada de linha de comando de um arquivo, altere o comando e fornecer a entrada de um arquivo no disco ou um arquivo embutido. Por exemplo, o LINK e LIB aceitam entrada de um arquivo de resposta.