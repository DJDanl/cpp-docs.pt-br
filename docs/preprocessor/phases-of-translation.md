---
title: "Fases de translação | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-tools
ms.tgt_pltfrm: 
ms.topic: article
dev_langs: C++
helpviewer_keywords:
- translation phases
- preprocessor, translation
- translation, compiler process
- preprocessor
- file translation [C++], compiler process
- files [C++], translation
ms.assetid: a7f7a8c9-e8ba-4321-9e50-ebfbbdcce9db
caps.latest.revision: "10"
author: corob-msft
ms.author: corob
manager: ghogen
ms.openlocfilehash: cfecdabea3a65815600c36b0ece1b14778305e15
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
---
# <a name="phases-of-translation"></a>Fases de translação
Os programas em C e C++ consistem em um ou mais arquivos de origem, cada um contendo parte do texto do programa. Um arquivo de origem, junto com seus arquivos de inclusão (arquivos que são incluídos a política de pré-processador `#include`) mas sem as seções de código removidas por políticas de compilação condicional, como `#if`, é chamado de uma "unidade de tradução".  
  
 Os arquivos de origem podem ser traduzidos em horas diferentes — de fato, é comum traduzir apenas os arquivos expirados. As unidades de tradução convertidas podem ser processadas em arquivos de objeto ou bibliotecas de código objeto separadas. Em seguida, essas unidades de tradução separadas e convertidas são vinculadas para formarem um programa executável ou uma biblioteca de vínculo dinâmico (DLL).  Para obter mais informações sobre os arquivos que podem ser usados como entrada para o vinculador, consulte [arquivos de entrada do LINK](../build/reference/link-input-files.md).  
  
 As unidades de tradução podem se comunicar usando:  
  
-   Chamadas a funções que têm vinculação externa.  
  
-   Chamadas a funções membro de classe que têm vinculação externa.  
  
-   Modificação direta de objetos que têm vinculação externa.  
  
-   Modificação direta de arquivos.  
  
-   Comunicação entre processos (apenas para aplicativos baseados em Microsoft Windows).  
  
 A lista a seguir descreve as fases nas quais o compilador traduz os arquivos:  
  
 *Mapeamento de caractere*  
 Os caracteres no arquivo de origem são mapeados para a representação de origem interna. As sequências de trígrafo são convertidas para representação interna de um único caractere nessa fase.  
  
 *União de linha*  
 Todas as linhas que terminam em uma barra invertida (**\\**) e seguido imediatamente por uma nova linha caractere associadas com a próxima linha no arquivo de origem cria linhas lógicas das linhas físicas. A menos que esteja vazio, um arquivo de origem deve terminar em um caractere de nova linha que não seja precedido por uma barra invertida.  
  
 *Geração de tokens*  
 O arquivo de origem é dividido em tokens de pré-processamento e em caracteres de espaço em branco. Cada um dos comentários do arquivo de origem são substituídos por um caractere de espaço. Os caracteres de nova linha são mantidos.  
  
 *Pré-processamento*  
 As políticas de pré-processamento são executadas e as macros são expandidas no arquivo de origem. A instrução `#include` invoca a tradução, começando pelas três etapas de tradução anteriores em qualquer texto incluído.  
  
 *Mapeamento de conjunto de caracteres*  
 Todos os membros do conjunto de caracteres e as sequências de escape da origem são convertidos em seus equivalentes no conjunto de caracteres de execução. Para Microsoft C e C++, os conjuntos de caracteres de origem e de execução são ASCII.  
  
 *Concatenação de cadeia de caracteres*  
 Todas as cadeia de caracteres e literais de cadeias de caracteres amplas adjacentes são concatenados. Por exemplo, `"String " "concatenation"` se torna `"String concatenation"`.  
  
 *Tradução*  
 Todos os tokens são analisados sintaticamente e semanticamente; esses tokens são convertidos em código objeto.  
  
 *Vinculação*  
 Todas as referências externas são resolvidas para criar um programa executável ou uma biblioteca de vínculo dinâmico.  
  
 O compilador emitirá avisos ou erros durante as fases de tradução nas quais ele encontrar erros de sintaxe.  
  
 O vinculador resolve todas as referências externas e cria um programa executável ou uma DLL combinando uma ou mais unidades de tradução processadas separadamente com bibliotecas padrão.  
  
## <a name="see-also"></a>Consulte também  
 [Pré-processador](../preprocessor/preprocessor.md)