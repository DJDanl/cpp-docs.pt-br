---
title: Compilador aviso (nível 2) C4653
ms.date: 11/04/2016
f1_keywords:
- C4653
helpviewer_keywords:
- C4653
ms.assetid: 90ec3317-3d39-4b4c-bcd1-97e7c799e1b6
ms.openlocfilehash: 664b1b3ec732c323d0074310902890cdd6eca9a6
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62402405"
---
# <a name="compiler-warning-level-2-c4653"></a>Compilador aviso (nível 2) C4653

opção de compilador 'option' inconsistente com cabeçalho pré-compilado; opção de linha de comando atual ignorada

Uma opção especificada com os cabeçalhos pré-compilados de uso ([/Yu](../../build/reference/yu-use-precompiled-header-file.md)) opção estava inconsistente com as opções especificadas quando o cabeçalho pré-compilado foi criado. Esta compilação usou a opção especificada quando o cabeçalho pré-compilado foi criado.

Esse aviso pode ocorrer quando um valor diferente para a opção de estruturas de pacote ([/Zp](../../build/reference/zp-struct-member-alignment.md)) foi especificado durante a compilação de cabeçalho pré-compilado.