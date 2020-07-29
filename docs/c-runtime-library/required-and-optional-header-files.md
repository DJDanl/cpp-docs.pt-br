---
title: Arquivos de cabeçalho obrigatórios e opcionais
ms.date: 11/04/2016
f1_keywords:
- c.headers
helpviewer_keywords:
- include files, required in run time
- header files, required in run time
ms.assetid: f64d0bf5-e2c3-4b42-97d0-443b3d901d9f
ms.openlocfilehash: 8d1547ae7dd3b6adb33271e93e85022f04859886
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87211600"
---
# <a name="required-and-optional-header-files"></a>Arquivos de cabeçalho obrigatórios e opcionais

A descrição de cada rotina de tempo de execução inclui uma lista de arquivos de cabeçalho (.H) obrigatórios e opcionais para essa rotina. Os arquivos de cabeçalho obrigatórios precisam ser incluídos para se obter a declaração de função para a rotina ou uma definição usada por outra rotina chamada internamente. Os arquivos de cabeçalho opcionais geralmente são incluídos para tirar proveito de constantes predefinidas, definições de tipo ou macros embutidas. A tabela a seguir lista alguns exemplos de conteúdos de arquivo de cabeçalho opcionais:

|Definição|Exemplo|
|----------------|-------------|
|Definição da macro|Se uma rotina da biblioteca é implementada como macro, a definição da macro pode estar em um arquivo de cabeçalho diferente daquele da rotina original. Por exemplo, a macro `_toupper` é definida no arquivo de cabeçalho CTYPE. H, enquanto a função `toupper` é declarada em STDLIB. H.|
|Constante predefinida|Muitas rotinas de biblioteca consultam constantes que são definidas nos arquivos de cabeçalho. Por exemplo, a rotina `_open` usa constantes como `_O_CREAT`, que é definida no arquivo de cabeçalho FCNTL. H.|
|Definição do tipo|Algumas rotinas da biblioteca retornam uma estrutura ou adotam uma estrutura como argumento. Por exemplo, rotinas de entrada/saída de fluxo usam uma estrutura do tipo `FILE`, que é definido em STDIO. H.|

Os arquivos de cabeçalho de biblioteca de tempo de execução fornecem declarações de função no estilo recomendado pelo padrão C ANSI/ISO. O compilador executa uma verificação de tipo em qualquer referência de rotina que ocorra após a declaração de função associada. As declarações de função são especialmente importantes para rotinas que retornam um valor de algum tipo diferente de **`int`** , que é o padrão. As rotinas que não especificam o valor de retorno apropriado em sua declaração serão consideradas pelo compilador para retornar um **`int`** , o que pode causar resultados inesperados. Consulte [Verificação de tipo](../c-runtime-library/type-checking-crt.md) para obter mais informações.

## <a name="see-also"></a>Confira também

[Recursos da biblioteca CRT](../c-runtime-library/crt-library-features.md)
