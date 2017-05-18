---
title: "Arquivos de saída binários | Microsoft Docs"
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
- I/O [C++], binary output files
- files [C++], binary output files
- binary data, binary output files
ms.assetid: 180954af-8cd6-444b-9a76-2f630a3389d8
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
ms.sourcegitcommit: 66798adc96121837b4ac2dd238b9887d3c5b7eef
ms.openlocfilehash: 8968a47f9d957aa0873b5db78909a6b4ad66ea75
ms.contentlocale: pt-br
ms.lasthandoff: 04/29/2017

---
# <a name="binary-output-files"></a>Arquivos de Saída Binários
Os fluxos foram criados originalmente para texto, portanto, o modo de saída padrão é texto. No modo de texto, o caractere de nova linha (10 hexadecimal) se expande para um carro retorno-alimentação de linha (somente 16 bits). A expansão pode causar problemas, como é mostrado aqui:  
  
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
  
 Você pode esperar que este programa produza a sequência de bytes { 99, 0, 10, 0 }, mas ele produz { 99, 0, 13, 10, 0 }, o que causa problemas para um programa que espera uma entrada binária. Se você precisar de uma saída binária verdadeira, na qual os caracteres são escritos sem conversão, especifique a saída binária usando o argumento openmode do construtor [ofstream](../standard-library/basic-ofstream-class.md#basic_ofstream):  
  
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
  
## <a name="see-also"></a>Consulte também  
 [Fluxos de saída](../standard-library/output-streams.md)


