---
title: Incluindo nomes de arquivo entre colchetes | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-language
ms.tgt_pltfrm: 
ms.topic: article
dev_langs:
- C++
ms.assetid: 6a4e5411-c35e-48b8-90ef-b37ac324ed94
caps.latest.revision: 7
author: mikeblome
ms.author: mblome
manager: ghogen
ms.translationtype: HT
ms.sourcegitcommit: 16d1bf59dfd4b3ef5f037aed9c0f6febfdf1a2e8
ms.openlocfilehash: f118417a7ed2fdf8cad77775e144b81655c56916
ms.contentlocale: pt-br
ms.lasthandoff: 10/09/2017

---
# <a name="including-bracketed-filenames"></a>Incluindo nomes de arquivo entre colchetes
**ANSI 3.8.2** O método para localizar arquivos de origem incluíveis  
  
 Para as especificações de arquivo colocadas entre colchetes angulares, o pré-processador não pesquisa diretórios dos arquivos pai. Um arquivo "pai" é o arquivo que contém a diretiva [#include](../preprocessor/hash-include-directive-c-cpp.md). Em vez disso, ele começa procurando o arquivo nos diretórios especificados na linha de comando do compilador depois de /I. Se a opção /I não estiver presente ou falhar, o pré-processador usará a variável de ambiente INCLUDE para localizar os arquivos de inclusão entre colchetes angulares. A variável de ambiente INCLUDE pode conter vários caminhos separados por ponto e vírgula (**;**). Se mais de um diretório aparecer como parte da opção /I ou dentro da variável de ambiente INCLUDE, o pré-processador procurará por eles na ordem em que aparecem.  
  
## <a name="see-also"></a>Consulte também  
 [Diretivas de pré-processamento](../c-language/preprocessing-directives.md)
