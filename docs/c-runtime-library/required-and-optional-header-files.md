---
title: "Arquivos de cabeçalho obrigatórios e opcionais | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-standard-libraries
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords: c.headers
dev_langs: C++
helpviewer_keywords:
- include files, required in run time
- header files, required in run time
ms.assetid: f64d0bf5-e2c3-4b42-97d0-443b3d901d9f
caps.latest.revision: "7"
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 9dde09f2125b595ffb3d79a69b4755353a0116bb
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="required-and-optional-header-files"></a>Arquivos de cabeçalho obrigatórios e opcionais
A descrição de cada rotina de tempo de execução inclui uma lista de arquivos de cabeçalho (.H) obrigatórios e opcionais para essa rotina. Os arquivos de cabeçalho obrigatórios precisam ser incluídos para se obter a declaração de função para a rotina ou uma definição usada por outra rotina chamada internamente. Os arquivos de cabeçalho opcionais geralmente são incluídos para tirar proveito de constantes predefinidas, definições de tipo ou macros embutidas. A tabela a seguir lista alguns exemplos de conteúdos de arquivo de cabeçalho opcionais:  
  
|Definição|Exemplo|  
|----------------|-------------|  
|Definição da macro|Se uma rotina da biblioteca é implementada como macro, a definição da macro pode estar em um arquivo de cabeçalho diferente daquele da rotina original. Por exemplo, a macro `_toupper` é definida no arquivo de cabeçalho CTYPE. H, enquanto a função `toupper` é declarada em STDLIB. H.|  
|Constante predefinida|Muitas rotinas de biblioteca consultam constantes que são definidas nos arquivos de cabeçalho. Por exemplo, a rotina `_open` usa constantes como `_O_CREAT`, que é definida no arquivo de cabeçalho FCNTL. H.|  
|Definição do tipo|Algumas rotinas da biblioteca retornam uma estrutura ou adotam uma estrutura como argumento. Por exemplo, rotinas de entrada/saída de fluxo usam uma estrutura do tipo `FILE`, que é definido em STDIO. H.|  
  
 Os arquivos de cabeçalho de biblioteca de tempo de execução fornecem declarações de função no estilo recomendado pelo padrão C ANSI/ISO. O compilador executa uma verificação de tipo em qualquer referência de rotina que ocorra após a declaração de função associada. Declarações de função são especialmente importantes para rotinas que retornam um valor de tipo diferente de `int`, que é o padrão. O compilador considera que as rotinas que não especificam o valor de retorno apropriado na declaração retornam `int`, o que pode causar resultados inesperados. Consulte [Verificação de tipo](../c-runtime-library/type-checking-crt.md) para obter mais informações.  
  
## <a name="see-also"></a>Consulte também  
 [Recursos da biblioteca CRT](../c-runtime-library/crt-library-features.md)