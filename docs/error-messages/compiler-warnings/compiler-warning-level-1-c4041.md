---
title: Aviso do compilador (nível 1) C4041
ms.date: 11/04/2016
f1_keywords:
- C4041
helpviewer_keywords:
- C4041
ms.assetid: 107ee9fd-4b88-4f22-a18f-a20726831095
ms.openlocfilehash: 14ea6d9cae3b490107b656153bb68815026971e1
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80164229"
---
# <a name="compiler-warning-level-1-c4041"></a>Aviso do compilador (nível 1) C4041

limite do compilador: finalizando saída do navegador

As informações do navegador excederam o limite do compilador.

Esse aviso pode ser causado pela compilação com [/fr](../../build/reference/fr-fr-create-dot-sbr-file.md) (informações do navegador, incluindo variáveis locais).

### <a name="to-fix-by-using-the-following-possible-solutions"></a>Para corrigir usando as seguintes soluções possíveis

1. Compile com/fr (informações do navegador sem variáveis locais).

1. Desabilite a saída do navegador (compile sem/FR ou/fr).
