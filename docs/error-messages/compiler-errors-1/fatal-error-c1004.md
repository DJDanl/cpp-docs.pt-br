---
title: Erro fatal C1004
ms.date: 11/04/2016
f1_keywords:
- C1004
helpviewer_keywords:
- C1004
ms.assetid: dbe034b0-6eb0-41b4-a50c-2fccf9e78ad4
ms.openlocfilehash: 82a1a3e410505be53d4356e46d5521aebb72763c
ms.sourcegitcommit: 16fa847794b60bf40c67d20f74751a67fccb602e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/03/2019
ms.locfileid: "74756962"
---
# <a name="fatal-error-c1004"></a>Erro fatal C1004

fim de arquivo inesperado encontrado

O compilador atingiu o final de um arquivo de origem sem resolver um constructo. O código pode estar faltando um dos seguintes elementos:

- Uma chave de fechamento

- Um parêntese de fechamento

- Um marcador de comentário de fechamento (*/)

- Um ponto e vírgula

Para resolver esse erro, verifique o seguinte:

- A unidade de disco padrão não tem espaço suficiente para arquivos temporários, o que exige aproximadamente duas vezes mais espaço que o arquivo de origem.

- Uma diretiva `#if` que é avaliada como false não tem uma diretiva de fechamento `#endif`.

- Um arquivo de origem não termina com um retorno de carro e alimentação de linha.

O exemplo a seguir gera C1004:

```cpp
// C1004.cpp
#if TEST
int main() {}
// C1004
```

Resolução possível:

```cpp
// C1004b.cpp
#if TEST
#endif

int main() {}
```
