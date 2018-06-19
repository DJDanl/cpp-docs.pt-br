---
title: NMAKE Erro Fatal U1045 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- U1045
dev_langs:
- C++
helpviewer_keywords:
- U1045
ms.assetid: dc70d162-14b9-4107-9237-7514044d72e3
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 673b20dde7156025c6aa56c487433eebe9e77aa3
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33316368"
---
# <a name="nmake-fatal-error-u1045"></a>Erro fatal U1045 (NMAKE)
falha de geração: mensagem  
  
 Um programa ou comando chamado pelo NMAKE falhou pelo motivo específico. Quando NMAKE chama outro programa — por exemplo, o compilador ou vinculador — a chamada pode falhar ou um erro pode ser retornado pelo programa chamado. Essa mensagem é usada para relatar o erro.  
  
 Para corrigir esse problema, primeiro determine a causa do erro. Você pode usar os comandos relatados pelo NMAKE [/N](../../build/nmake-options.md) opção para verificar as configurações de ambiente e repetir as ações realizadas pelo NMAKE na linha de comando.