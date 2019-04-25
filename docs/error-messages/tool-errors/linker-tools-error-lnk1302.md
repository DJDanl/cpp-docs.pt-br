---
title: Erro das Ferramentas de Vinculador LNK1302
ms.date: 11/04/2016
f1_keywords:
- LNK1302
helpviewer_keywords:
- LNK1302
ms.assetid: aea3c753-c2c4-4249-bbc3-f2d4f0164b5e
ms.openlocfilehash: c3b1117b31db4759b385943323a581da7a58f0c4
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62160439"
---
# <a name="linker-tools-error-lnk1302"></a>Erro das Ferramentas de Vinculador LNK1302

apenas suporta vínculo seguro. netmodules; não foi possível vincular o. netmodule de arquivo

Um. netmodule (compilado com **/LN**) foi passado para o vinculador em uma tentativa de usuário para invocar a vinculação MSIL.  Um módulo do C++ é válido para se ele for compilado com a vinculação de MSIL **/CLR: safe**.

Para corrigir esse erro, compilar com **/CLR: safe** para habilitar a vinculação MSIL ou passe o **/clr** ou **/clr: pure** arquivo. obj para o vinculador, em vez do módulo.

Para saber mais, veja

- [/LN (criar módulo de MSIL)](../../build/reference/ln-create-msil-module.md)

- [Arquivos .netmodule como entrada do vinculador](../../build/reference/netmodule-files-as-linker-input.md)