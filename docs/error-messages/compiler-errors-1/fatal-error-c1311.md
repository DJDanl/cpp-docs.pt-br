---
title: Erro fatal C1311
ms.date: 11/04/2016
f1_keywords:
- C1311
helpviewer_keywords:
- C1311
ms.assetid: 6590a06c-ce9d-4f17-8f62-c809343143b8
ms.openlocfilehash: e57e4e0899a5f9d81e87a203b1b699cef0884f0d
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80203262"
---
# <a name="fatal-error-c1311"></a>Erro fatal C1311

O formato COFF não pode inicializar ' var ' estaticamente com o número de byte (s) de um endereço

Um endereço cujo valor não é conhecido em tempo de compilação não pode ser atribuído estaticamente a uma variável cujo tipo tem armazenamento de menos de quatro bytes.

Esse erro pode ocorrer em código que, de outra C++forma, é válido.

O exemplo a seguir mostra uma condição que pode causar C1311.

```
char c = (char)"Hello, world";   // C1311
char *d = (char*)"Hello, world";   // OK
```
