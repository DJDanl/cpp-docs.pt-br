---
title: "Construindo objetos de fluxo de saída | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-standard-libraries
ms.tgt_pltfrm: 
ms.topic: article
dev_langs: C++
helpviewer_keywords: output stream objects
ms.assetid: 93c8eab6-610c-4f48-b76d-1d960cac7641
caps.latest.revision: "9"
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 04cbb5ae7433dc31e99136c11c4022e60ad4808e
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="constructing-output-stream-objects"></a>Construindo objetos de fluxo de saída
Se você usar apenas os objetos `cout`, `cerr` ou `clog` predefinidos, não será necessário construir um fluxo de saída. É necessário usar construtores para:  
  
- [Construtores de fluxo de arquivo de saída](#vclrfoutputfilestreamconstructorsanchor1)  
  
- [Construtores de fluxo de cadeia de caracteres de saída](#vclrfoutputstringstreamconstructorsanchor2)  
  
##  <a name="vclrfoutputfilestreamconstructorsanchor1"></a> Construtores de fluxo de arquivo de saída  
 É possível construir um fluxo de arquivo de saída de duas maneiras:  
  
-   Usar o construtor padrão e, em seguida, chamar a função de membro `open`.  
  
 ```  
    ofstream myFile; // Static or on the stack  
    myFile.open("filename");

 
    ofstream* pmyFile = new ofstream; // On the heap  
    pmyFile->open("filename");
```  
  
-   Especificar um nome de arquivo e sinalizadores de modo na chamada do construtor.  
  
 ```  
    ofstream myFile("filename", ios_base::out);
```  
  
##  <a name="vclrfoutputstringstreamconstructorsanchor2"></a> Construtores de fluxo de cadeia de caracteres de saída  
 Para construir um fluxo de cadeia de caracteres de saída, é possível usar `ostringstream` da seguinte maneira:  
  
```  
    using namespace std;  
string sp;  
ostringstream myString;  
myString <<"this is a test" <<ends;  
sp = myString.str();
// Obtain string  
cout <<sp <endl;   
```  
  
 O “manipulador” `ends` adiciona o caractere nulo de terminação necessário à cadeia de caracteres.  
  
## <a name="see-also"></a>Consulte também  
 [Fluxos de saída](../standard-library/output-streams.md)

