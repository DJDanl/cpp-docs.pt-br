---
title: Erro fatal C1852
ms.date: 11/04/2016
f1_keywords:
- C1852
helpviewer_keywords:
- C1852
ms.assetid: fa011004-b8d6-46f1-ba80-4785e4ce137f
ms.openlocfilehash: 895c2fc988c9566f9e50b1ac1a18eb4dc1c6661a
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62165730"
---
# <a name="fatal-error-c1852"></a>Erro fatal C1852

'filename' não é um arquivo de cabeçalho pré-compilado válido

O arquivo não é um cabeçalho pré-compilado.

### <a name="to-fix-by-checking-the-following-possible-causes"></a>Para corrigir verificando as possíveis causas a seguir

1. Arquivo inválido especificado com **/Yu** ou **#pragma hdrstop**.

1. O compilador pressupõe uma extensão de arquivo de. pch, se você não especifique o contrário.