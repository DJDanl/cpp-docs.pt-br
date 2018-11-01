---
title: Erro fatal C1004
ms.date: 11/04/2016
f1_keywords:
- C1004
helpviewer_keywords:
- C1004
ms.assetid: dbe034b0-6eb0-41b4-a50c-2fccf9e78ad4
ms.openlocfilehash: 13fb8963b33569facf62ccedfe9ce8b7bbbbfdc3
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50428113"
---
# <a name="fatal-error-c1004"></a>Erro fatal C1004

fim de arquivo inesperado encontrado

O compilador atingiu o final de um arquivo de origem sem resolver uma construção. O código pode estar faltando um dos seguintes elementos:

- Uma chave de fechamento

- Um parêntese de fechamento

- Marcador de comentário de um fechamento (* /)

- Um ponto e vírgula

Para resolver esse erro, verifique o seguinte:

- A unidade de disco padrão não tem espaço suficiente para arquivos temporários que requerem praticamente duas vezes mais espaço do arquivo de origem.

- Uma `#if` diretiva que seja avaliada como false carece um fechamento `#endif` diretiva.

- Um arquivo de origem não termina com um retorno de carro e alimentação de linha.

O exemplo a seguir gera C1004:

```
// C1004.cpp
#if TEST
int main() {}
// C1004
```

Solução possível:

```
// C1004b.cpp
#if TEST
#endif

int main() {}
```