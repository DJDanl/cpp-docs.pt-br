---
title: Erro fatal C1900 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C1900
dev_langs:
- C++
helpviewer_keywords:
- C1900
ms.assetid: 3aaa583b-4c1a-45de-aa34-527d806f2cb5
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: b2211b4243ddf44194959a263fd90ec1a615ea0a
ms.sourcegitcommit: 9a0905c03a73c904014ec9fd3d6e59e4fa7813cd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/29/2018
ms.locfileid: "43220275"
---
# <a name="fatal-error-c1900"></a>Erro fatal C1900

> Incompatibilidade de linguagem intermediária entre '*tool1*'version'*Número1*'e'*tool2*'version'*Número2*'

As ferramentas executadas em vários passos do compilador não correspondem. *Número1* e *Número2* consulte as datas nos arquivos. Por exemplo, na etapa 1, o front-end do compilador é executado (c1.dll) e na etapa 2, o back-end do compilador é executado (c2.dll). As datas nos arquivos devem ser correspondentes.

Para corrigir esse problema, certifique-se de que todas as atualizações foram aplicadas ao Visual Studio. Se o problema persistir, use **programas e recursos** no painel de controle do Windows para reparar ou reinstalar o Visual Studio.