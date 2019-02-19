---
title: Argumentos para main
ms.date: 11/04/2016
ms.assetid: 39824fef-05ad-461d-ae82-49447dda8060
ms.openlocfilehash: 918be9d281f1cb12c27c6c2f5dd834e4af137179
ms.sourcegitcommit: f4be868c0d1d78e550fba105d4d3c993743a1f4b
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/12/2019
ms.locfileid: "56150253"
---
# <a name="arguments-to-main"></a>Argumentos para main

**ANSI 2.1.2.2.1** A semântica dos argumentos para main

No Microsoft C, a função chamada na inicialização do programa é chamada **main**. Não há nenhum protótipo declarado para **main** e ele pode ser definido com zero, dois ou três parâmetros:

```
int main( void )
int main( int argc, char *argv[] )
int main( int argc, char *argv[], char *envp[] )
```

A terceira linha acima, em que **main** aceita três parâmetros, é uma extensão da Microsoft para o padrão ANSI C. O terceiro parâmetro, **envp**, é uma matriz dos ponteiros para variáveis de ambiente. A matriz **envp** é terminada por um ponteiro nulo. Consulte [A função main e a execução do programa](../c-language/main-function-and-program-execution.md) para obter mais informações sobre **main** e **envp**.

A variável **argc** nunca contém um valor negativo.

A matriz de cadeias de caracteres termina com **argv[argc]**, que contém um ponteiro nulo.

Todos os elementos da matriz **argv** são ponteiros para cadeias de caracteres.

Um programa invocado sem argumentos de linha de comando receberá um valor de um para **argc**, já que o nome do arquivo executável é colocado em **argv[0]**. (Em versões do MS-DOS anteriores a 3.0, o nome do arquivo executável não está disponível. A letra “C” é colocada em **argv[0]**.) As cadeias de caracteres apontadas por **argv[1]** a **argv[argc – 1]** representam parâmetros do programa.

Os parâmetros **argc** e **argv** são modificáveis e retêm seus últimos valores armazenados entre a inicialização do programa e o término do programa.

## <a name="see-also"></a>Consulte também

[Ambiente](../c-language/environment.md)
