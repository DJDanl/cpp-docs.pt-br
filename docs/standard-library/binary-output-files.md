---
title: "Arquivos de Sa&#237;da Bin&#225;rios | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "dados binários, arquivos de saída binários"
  - "arquivos [C++], arquivos de saída binários"
  - "E/S [C++], arquivos de saída binários"
ms.assetid: 180954af-8cd6-444b-9a76-2f630a3389d8
caps.latest.revision: 8
caps.handback.revision: 7
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Arquivos de Sa&#237;da Bin&#225;rios
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Os fluxos foi criado originalmente para o texto, portanto o modo de saída padrão é texto.  No modo de texto, o caractere de nova linha \(10\) hexadecimais expanda a uma retorno\- avanço de linha de carro \(somente 16 bits\).  A expansão pode causar problemas, como mostrado a seguir:  
  
```  
// binary_output_files.cpp  
// compile with: /EHsc  
#include <fstream>  
using namespace std;  
int iarray[2] = { 99, 10 };  
int main( )  
{  
    ofstream os( "test.dat" );  
    os.write( (char *) iarray, sizeof( iarray ) );  
}  
```  
  
 Você pode esperar esse programa a saída a sequência de bytes {99, 0, 10, 0}; em vez disso, ele produz {99, 0, 13, 10, 0}, que causa problemas para um programa espera que a entrada binária.  Se você precisar a saída binários for true, em que os caracteres são gravados não traduzido, você pode especificar a saída binários usando o argumento do modo do construtor de [ofstream](../Topic/ofstream.md) :  
  
```  
// binary_output_files2.cpp  
// compile with: /EHsc  
#include <fstream>  
using namespace std;  
int iarray[2] = { 99, 10 };  
  
int main()  
{  
   ofstream ofs ( "test.dat", ios_base::binary );  
  
   // Exactly 8 bytes written  
   ofs.write( (char*)&iarray[0], sizeof(int)*2 );   
}  
```  
  
## Consulte também  
 [Fluxos de Saída](../standard-library/output-streams.md)