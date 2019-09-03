---
title: Fases de translação
ms.date: 08/29/2019
helpviewer_keywords:
- translation phases
- preprocessor, translation
- translation, compiler process
- preprocessor
- file translation [C++], compiler process
- files [C++], translation
ms.assetid: a7f7a8c9-e8ba-4321-9e50-ebfbbdcce9db
ms.openlocfilehash: d072c9aec48d815ba85f8a12576baa6447703f8c
ms.sourcegitcommit: 6e1c1822e7bcf3d2ef23eb8fac6465f88743facf
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/03/2019
ms.locfileid: "70218297"
---
# <a name="phases-of-translation"></a>Fases de translação

Os programas em C e C++ consistem em um ou mais arquivos de origem, cada um contendo parte do texto do programa. Um arquivo de origem, junto com seus *arquivos de inclusão*, arquivos que são incluídos `#include` usando a diretiva de pré-processador, mas sem incluir seções de código removidas por diretivas de `#if`compilação condicional, como, é chamado de  *unidade de tradução*.

Os arquivos de origem podem ser traduzidos em momentos diferentes. Na verdade, é comum traduzir somente arquivos desatualizados. As unidades de tradução convertidas podem ser processadas em arquivos de objeto ou bibliotecas de código objeto separadas. Em seguida, essas unidades de tradução separadas e convertidas são vinculadas para formarem um programa executável ou uma biblioteca de vínculo dinâmico (DLL). Para obter mais informações sobre os arquivos que podem ser usados como entrada para o vinculador, consulte [vincular arquivos de entrada](../build/reference/link-input-files.md).

As unidades de tradução podem se comunicar usando:

- Chamadas a funções que têm vinculação externa.

- Chamadas a funções membro de classe que têm vinculação externa.

- Modificação direta de objetos que têm vinculação externa.

- Modificação direta de arquivos.

- Comunicação entre processos (apenas para aplicativos baseados em Microsoft Windows).

A lista a seguir descreve as fases nas quais o compilador traduz os arquivos:

*Mapeamento de caracteres*\
Os caracteres no arquivo de origem são mapeados para a representação de origem interna. As sequências de trígrafo são convertidas para representação interna de um único caractere nessa fase.

*Da União de linha*\
Todas as linhas que terminam em uma **\\** barra invertida () imediatamente seguidas por um caractere de nova linha são unidas com a Next line no arquivo de origem, formando linhas lógicas das linhas físicas. A menos que esteja vazio, um arquivo de origem deve terminar em um caractere de nova linha que não seja precedido por uma barra invertida.

*Tokens*\
O arquivo de origem é dividido em tokens de pré-processamento e em caracteres de espaço em branco. Cada um dos comentários do arquivo de origem são substituídos por um caractere de espaço. Os caracteres de nova linha são mantidos.

*Pré-processamento*\
As políticas de pré-processamento são executadas e as macros são expandidas no arquivo de origem. A instrução `#include` invoca a tradução, começando pelas três etapas de tradução anteriores em qualquer texto incluído.

*Mapeamento de conjunto de caracteres*\
Todos os membros do conjunto de caracteres e as sequências de escape da origem são convertidos em seus equivalentes no conjunto de caracteres de execução. Para Microsoft C e C++, os conjuntos de caracteres de origem e de execução são ASCII.

*Concatenação de cadeia de caracteres*\
Todas as cadeia de caracteres e literais de cadeias de caracteres amplas adjacentes são concatenados. Por exemplo, `"String " "concatenation"` se torna `"String concatenation"`.

*Transferência*\
Todos os tokens são analisados sintaticamente e semanticamente; esses tokens são convertidos em código objeto.

*Claro*\
Todas as referências externas são resolvidas para criar um programa executável ou uma biblioteca de vínculo dinâmico.

O compilador emitirá avisos ou erros durante as fases de tradução nas quais ele encontrar erros de sintaxe.

O vinculador resolve todas as referências externas e cria um programa executável ou uma DLL combinando uma ou mais unidades de tradução processadas separadamente com bibliotecas padrão.

## <a name="see-also"></a>Consulte também

[Pré-processador](../preprocessor/preprocessor.md)
