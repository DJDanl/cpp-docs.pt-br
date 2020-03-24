---
title: Erro do compilador C3728
ms.date: 11/04/2016
f1_keywords:
- C3728
helpviewer_keywords:
- C3728
ms.assetid: 6b510cb1-887f-4fcd-9a1f-3bb720417ed1
ms.openlocfilehash: 8aec3ae1ff629ef7fa000182cde29e306a471315
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80165867"
---
# <a name="compiler-error-c3728"></a>Erro do compilador C3728

' Event ': o evento não tem um método Raise

Os metadados criados com uma linguagem, como C#, que não permitem que um evento seja gerado de fora da classe na qual ele foi definido, foram incluídos com a diretiva [#using](../../preprocessor/hash-using-directive-cpp.md) e um programa Visual C++ que usa programação CLR tentou gerar o evento.

Para gerar um evento em um programa desenvolvido em um idioma como C#, a classe que contém o evento também precisa definir um método público que gera o evento.
