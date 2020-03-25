---
title: Erro das Ferramentas de Vinculador LNK1302
ms.date: 11/04/2016
f1_keywords:
- LNK1302
helpviewer_keywords:
- LNK1302
ms.assetid: aea3c753-c2c4-4249-bbc3-f2d4f0164b5e
ms.openlocfilehash: 8323fa234851ce3ba12083adb74d5ee0fba0ac69
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80194922"
---
# <a name="linker-tools-error-lnk1302"></a>Erro das Ferramentas de Vinculador LNK1302

dá suporte apenas à vinculação de Safe. netmodules; Não é possível vincular arquivo. netmodule

Um. netmodule (compilado com **/ln**) foi passado para o vinculador em uma tentativa de usuário de invocar a vinculação MSIL.  Um C++ módulo é válido para vinculação MSIL se ele for compilado com **/CLR: safe**.

Para corrigir esse erro, compile com **/CLR: safe** para habilitar a vinculação MSIL ou passe o arquivo **/CLR** ou **/CLR: Pure** . obj para o vinculador em vez do módulo.

Para obter mais informações, consulte

- [/LN (criar módulo de MSIL)](../../build/reference/ln-create-msil-module.md)

- [Arquivos .netmodule como entrada do vinculador](../../build/reference/netmodule-files-as-linker-input.md)
