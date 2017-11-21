---
title: "Fluxos de Entrada/Saída | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-standard-libraries
ms.tgt_pltfrm: 
ms.topic: article
dev_langs: C++
helpviewer_keywords:
- I/O [C++], stream
- stream I/O
ms.assetid: 21a97566-91a7-42d6-b2f8-a4c16bc926f1
caps.latest.revision: "11"
author: corob-msft
ms.author: corob
manager: ghogen
ms.openlocfilehash: f8c9a570dc883839bd4b51cb99fd43f4f605402f
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
---
# <a name="inputoutput-streams"></a>Fluxos de Entrada/Saída
`basic_iostream`, que é definido no arquivo de cabeçalho \<istream>, é o modelo de classe para objetos que manipulam fluxos de E/S baseados em caracteres de entrada e de saída.  
  
 Há dois typedefs que definem especializações específicas do caractere de `basic_iostream` e que podem ajudar a facilitar a leitura do código: `iostream` (não deve ser confundido com o arquivo de cabeçalho \<iostream>) é um fluxo de E/S baseado em `basic_iostream<char>`; `wiostream` é um fluxo de E/S baseado em `basic_iostream<wchar_t>`.  
  
 Para obter mais informações, consulte [Classe basic_iostream](../standard-library/basic-iostream-class.md), [iostream](../standard-library/basic-iostream-class.md) e [wiostream](../standard-library/basic-iostream-class.md).  
  
 Derivado de `basic_iostream`, há o modelo de classe `basic_fstream`, que é usado para transmitir dados de caractere para arquivos e de arquivos.  
  
 Também há typedefs que fornecem especializações específicas do caractere de `basic_fstream`. Eles são `fstream`, que é um fluxo de E/S de arquivo baseado em `char`, e `wfstream`, que é um fluxo de E/S de arquivo baseado em `wchar_t`. Para obter mais informações, consulte [Classe basic_fstream](../standard-library/basic-fstream-class.md), [fstream](../standard-library/basic-fstream-class.md) e [wfstream](../standard-library/basic-fstream-class.md). Usar esses typedefs requer a inclusão do arquivo de cabeçalho \<fstream>.  
  
> [!NOTE]
>  Quando um objeto `basic_fstream` é usado para realizar E/S de arquivo, embora o buffer subjacente contenha posições designadas separadamente para leitura e gravação, as posições atuais de entrada e saída são vinculadas e, portanto, ler alguns dados move a posição de saída.  
  
 O modelo de classe `basic_stringstream` e sua especialização comum, `stringstream`, geralmente são usados para trabalhar com objetos de fluxo de E/S para inserir e extrair dados de caractere. Para obter mais informações, consulte a [Classe basic_stringstream](../standard-library/basic-stringstream-class.md).  
  
## <a name="see-also"></a>Consulte também  
 [stringstream](../standard-library/basic-stringstream-class.md)   
 [Classe basic_stringstream](../standard-library/basic-stringstream-class.md)   
 [\<sstream>](../standard-library/sstream.md)   
 [Programação de iostream](../standard-library/iostream-programming.md)   
 [Biblioteca padrão C++](../standard-library/cpp-standard-library-reference.md)



