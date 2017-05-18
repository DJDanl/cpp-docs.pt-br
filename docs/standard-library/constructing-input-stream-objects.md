---
title: Construindo objetos de fluxo de entrada | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-standard-libraries
ms.tgt_pltfrm: 
ms.topic: article
dev_langs:
- C++
helpviewer_keywords:
- input stream objects
ms.assetid: ab94866e-6ffe-4f15-b4db-0bd23e636075
caps.latest.revision: 8
author: corob-msft
ms.author: corob
manager: ghogen
translation.priority.ht:
- cs-cz
- de-de
- es-es
- fr-fr
- it-it
- ja-jp
- ko-kr
- pl-pl
- pt-br
- ru-ru
- tr-tr
- zh-cn
- zh-tw
ms.translationtype: Machine Translation
ms.sourcegitcommit: 3168772cbb7e8127523bc2fc2da5cc9b4f59beb8
ms.openlocfilehash: 7e8c664bd6632f480ba53b9dedea914bbc8e4dd7
ms.contentlocale: pt-br
ms.lasthandoff: 02/25/2017

---
# <a name="constructing-input-stream-objects"></a>Construindo objetos de fluxo de entrada
Se você usar somente o objeto `cin`, não será necessário construir um fluxo de entrada. Será necessário construir um fluxo de entrada se você usar:  
  
- [Construtores de fluxo de arquivo de entrada](#vclrfinputfilestreamconstructorsanchor8)  
  
- [Construtores de fluxo de cadeia de caracteres de entrada](#vclrfinputstringstreamconstructorsanchor9)  
  
##  <a name="vclrfinputfilestreamconstructorsanchor8"></a> Construtores de fluxo de arquivo de entrada  
 Há duas maneiras de criar um fluxo de arquivo de entrada:  
  
-   Use o construtor de argumento `void` e, em seguida, chame a função de membro `open`:  
  
 ```  
    ifstream myFile; // On the stack  
    myFile.open("filename");

 
    ifstream* pmyFile = new ifstream; // On the heap  
    pmyFile->open("filename");
```  
  
-   Especifique um nome de arquivo e sinalizadores de modo na invocação do construtor, abrindo o arquivo durante o processo de construção:  
  
 ```  
    ifstream myFile("filename");
```  
  
##  <a name="vclrfinputstringstreamconstructorsanchor9"></a> Construtores de fluxo de cadeia de caracteres de entrada  
 Construtores de fluxo de cadeia de caracteres de entrada exigem o endereço do armazenamento pré-alocado e pré-inicializado:  
  
```  
string s("123.45");

double amt;  
istringstream myString(s);

//istringstream myString("123.45") also works  
myString>> amt; // amt contains 123.45  
```  
  
## <a name="see-also"></a>Consulte também  
 [Fluxos de entrada](../standard-library/input-streams.md)


