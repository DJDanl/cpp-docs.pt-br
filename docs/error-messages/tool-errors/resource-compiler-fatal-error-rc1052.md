---
title: Erro fatal RC1052 (compilador de recurso)
ms.date: 11/04/2016
f1_keywords:
- RC1052
helpviewer_keywords:
- RC1052
ms.assetid: 59803673-492b-44fa-80fa-df93b8aaf9fb
ms.openlocfilehash: ad0fe23b20870610c5979d6ad85fce55b4e506d3
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80182547"
---
# <a name="resource-compiler-fatal-error-rc1052"></a>Erro fatal RC1052 (compilador de recurso)

limite do compilador: blocos #if ou #ifdef muito aninhados

O programa excedeu os níveis de aninhamento máximos permitidos para as diretivas `#if` e `#ifdef`.

Esse erro pode ser causado pela inclusão dos arquivos que usam essas diretivas de pré-processador.

Para corrigir esse problema, reduza o número das diretivas `#if` e `#ifdef` aninhadas no seu arquivo de recurso. Se o problema for causado por arquivos de cabeçalho incluídos no seu arquivo de recursos, reduza o número de diretivas `#if` e `#ifdef` aninhadas nos arquivos de cabeçalho. Se isso não for possível, considere criar e incluir um novo arquivo de cabeçalho no arquivo de recursos, executando o pré-processador nos arquivos de cabeçalho incluídos existentes. Para obter mais informações, consulte a opção de compilador [/p (pré-processar para um arquivo)](../../build/reference/p-preprocess-to-a-file.md) .
