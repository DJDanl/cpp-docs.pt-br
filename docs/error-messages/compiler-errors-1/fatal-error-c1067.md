---
title: Erro fatal C1067
ms.date: 11/04/2016
f1_keywords:
- C1067
helpviewer_keywords:
- C1067
ms.assetid: e2c94be6-4573-4571-aac9-73d657fe9f96
ms.openlocfilehash: 3b016790220d409435ff7ea53c6f48899a9e8f1c
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80204341"
---
# <a name="fatal-error-c1067"></a>Erro fatal C1067

limite do compilador: o limite de 64K de tamanho de um registro de tipo foi excedido

Esse erro pode ocorrer se um símbolo tiver um nome decorado que exceda 247 caracteres.  Para resolver, encurte o nome do símbolo.

Quando o compilador gera informações de depuração, ele emite registros de tipo para definir tipos encontrados no código-fonte.  Por exemplo, os registros de tipo incluem estruturas simples e listas de argumentos de funções.  Alguns desses registros de tipo podem ser listas grandes.

Há um limite de 64K no tamanho de qualquer registro de tipo.  Se esse limite de 64K for excedido, esse erro ocorrerá.

C1067 também pode ocorrer se houver muitos símbolos com nomes longos ou se uma classe, struct ou União tiver muitos membros.
