---
title: Erro do compilador C3173 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C3173
dev_langs:
- C++
helpviewer_keywords:
- C3173
ms.assetid: edf79e10-e8cf-4f76-8d33-ab9d05e974e9
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 21a02ae1fcf4aff9636445979a81ef0a02ab5cb1
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46053018"
---
# <a name="compiler-error-c3173"></a>Erro do compilador C3173

incompatibilidade de versão em mesclagem de idl

Esse erro ocorre quando um arquivo de objeto contém idl incorporado que foi gerado com uma versão anterior do compilador. O compilador codifica um número de versão para garantir que o mesmo compilador usado para gerar o conteúdo idl incorporado em arquivos. obj, também é o mesmo compilador usado para mesclar o idl incorporado.

Atualize sua instalação do Visual C++ para que todas as ferramentas são da versão mais recente.