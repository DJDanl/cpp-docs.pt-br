---
title: Erro das Ferramentas de Vinculador LNK1302
ms.date: 11/04/2016
f1_keywords:
- LNK1302
helpviewer_keywords:
- LNK1302
ms.assetid: aea3c753-c2c4-4249-bbc3-f2d4f0164b5e
ms.openlocfilehash: c3b1117b31db4759b385943323a581da7a58f0c4
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50491072"
---
# <a name="linker-tools-error-lnk1302"></a>Erro das Ferramentas de Vinculador LNK1302

apenas suporta vínculo seguro. netmodules; não foi possível vincular o. netmodule de arquivo

Um. netmodule (compilado com **/LN**) foi passado para o vinculador em uma tentativa de usuário para invocar a vinculação MSIL.  Um módulo do C++ é válido para se ele for compilado com a vinculação de MSIL **/CLR: safe**.

Para corrigir esse erro, compilar com **/CLR: safe** para habilitar a vinculação MSIL ou passe o **/clr** ou **/clr: pure** arquivo. obj para o vinculador, em vez do módulo.

Para saber mais, veja

- [/LN (criar módulo de MSIL)](../../build/reference/ln-create-msil-module.md)

- [Arquivos .netmodule como entrada do vinculador](../../build/reference/netmodule-files-as-linker-input.md)