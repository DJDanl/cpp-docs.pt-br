---
title: Construindo objetos de fluxo de entrada | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-standard-libraries
ms.tgt_pltfrm: 
ms.topic: article
dev_langs: C++
helpviewer_keywords: input stream objects
ms.assetid: ab94866e-6ffe-4f15-b4db-0bd23e636075
caps.latest.revision: "8"
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: d284452e7b6c9983a751117ad6c2290b267c6994
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
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

