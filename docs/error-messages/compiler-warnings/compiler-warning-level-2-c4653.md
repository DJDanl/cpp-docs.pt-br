---
title: Compilador aviso (nível 2) C4653 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C4653
dev_langs:
- C++
helpviewer_keywords:
- C4653
ms.assetid: 90ec3317-3d39-4b4c-bcd1-97e7c799e1b6
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 376da24d4619eacc3e6b3defe8fdfc582800a898
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46045972"
---
# <a name="compiler-warning-level-2-c4653"></a>Compilador aviso (nível 2) C4653

opção de compilador 'option' inconsistente com cabeçalho pré-compilado; opção de linha de comando atual ignorada

Uma opção especificada com os cabeçalhos pré-compilados de uso ([/Yu](../../build/reference/yu-use-precompiled-header-file.md)) opção estava inconsistente com as opções especificadas quando o cabeçalho pré-compilado foi criado. Esta compilação usou a opção especificada quando o cabeçalho pré-compilado foi criado.

Esse aviso pode ocorrer quando um valor diferente para a opção de estruturas de pacote ([/Zp](../../build/reference/zp-struct-member-alignment.md)) foi especificado durante a compilação de cabeçalho pré-compilado.